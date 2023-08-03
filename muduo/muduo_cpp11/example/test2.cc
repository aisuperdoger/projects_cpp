#include <iostream>
#include <vector>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <functional>
#include <future>


class ThreadPool{
public:
    ThreadPool(size_t numThreads):stop(false){
        for(int i=0;i<numThreads;++i){
            workers.emplace_back(
                [this]{
                    while(true){
                        std::function<void()> task;
                        {
                            std::unique_lock<std::mutex> lock(queueMutex);
                            condition.wait(lock, [this]{return !tasks.empty() || stop;});
                            task = std::move(tasks.front());
                        }
                        task();
                    }
                }
            );
        }
    }

    template<typename F,typename... Args>
    auto enqueue(F &&f, Args&&... args) -> std::future<typename std::result_of<F(Args...)>::type>{
        using result_type = typename std::result_of<F(Args...)>::type;

        auto task = std::make_shared<std::packaged_task<result_type>>(std::bind(std::forward<F>(f), std::forward<Args>(args)...));

        std::future<result_type> result = task->get_future();
        {
            std::unique_lock<std::mutex> lock(queueMutex);
            tasks.emplace([task]{*task();})
        }
        condtion.notify_one();
        return result;

    }


private:
    std::vector<std::thread> workers;
    std::queue<std::function<void()>> tasks;
    std::mutex queueMutex;
    std::condition_variable condition;
    bool stop;
};