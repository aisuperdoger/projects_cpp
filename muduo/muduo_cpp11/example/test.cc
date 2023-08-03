#include <iostream>
#include <vector>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <functional>
#include <future>


class ThreadPool {
public:
    ThreadPool(size_t numThreads) : stop(false) {
        for (size_t i = 0; i < numThreads; ++i) {
            workers.emplace_back([this] {
                while (true) {
                    std::function<void()> task;
                    {
                        std::unique_lock<std::mutex> lock(queueMutex);
                        condition.wait(lock, [this] { return stop || !tasks.empty(); }); // this不能换成tasks
                        if (stop && tasks.empty()) {
                            return;
                        }
                        task = std::move(tasks.front());
                        tasks.pop();
                    }
                    task();
                }
            });
        }
    }

    template<typename F, typename... Args>
    auto enqueue(F&& f, Args&&... args) -> std::future<typename std::result_of<F(Args...)>::type> {
        using return_type = typename std::result_of<F(Args...)>::type;

        auto task = std::make_shared<std::packaged_task<return_type()>>(std::bind(std::forward<F>(f), std::forward<Args>(args)...));

        std::future<return_type> result = task->get_future(); // 返回一个futur对象，result通过result.get()获取线程函数的返回值 如果线程函数没有执行完就会阻塞在result.get()
        {
            std::unique_lock<std::mutex> lock(queueMutex);
            if (stop) {
                throw std::runtime_error("enqueue on stopped ThreadPool");
            }
            tasks.emplace([task]() { (*task)(); }); // Lambda函数是一种可调用对象 Lambda函数的语法为[捕获列表](参数列表) { 函数体 }。
        }
        condition.notify_one();
        return result;
    }

    ~ThreadPool() {
        {
            std::unique_lock<std::mutex> lock(queueMutex);
            stop = true;
        }
        condition.notify_all();
        for (std::thread& worker : workers) {
            worker.join();
        }
    }

private:
    std::vector<std::thread> workers;
    std::queue<std::function<void()>> tasks;
    std::mutex queueMutex;
    std::condition_variable condition;
    bool stop;
};

// 示例任务函数
int  printHello(int num) {
    std::cout << "Hello from thread " << std::this_thread::get_id() << "! Num: " << num << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    return num;
}

int main() {
    ThreadPool pool(4);

    std::vector<std::future<int>> results; 

    // 提交任务到线程池
    std::cout << "Enqueuing tasks..." << std::endl;
    for (int i = 0; i < 8; ++i) {
        results.push_back(pool.enqueue(printHello, i));
    }

    for (int i = 0; i < 8; ++i) {
        int num = results[i].get(); // 获取线程函数的返回值
        std::cout<< "获取到线程函数的返回值：" << num << std::endl;    // 获取线程函数的返回值  
    }

    // 等待任务完成
    std::this_thread::sleep_for(std::chrono::seconds(5));

    return 0;
}
