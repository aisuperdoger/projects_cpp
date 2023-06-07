#ifndef LOCKER_H
#define LOCKER_H

#include <pthread.h>
#include <semaphore.h>
#include <iostream>
using namespace std;

class locker{
public:
    locker(){
        if(pthread_mutex_init(&m_mutex, NULL) != 0){
            throw std::exception();
        }
    }
    ~locker(){
        pthread_mutex_destroy(&m_mutex);
    }
    bool lock(){
        return pthread_mutex_lock(&m_mutex) == 0;
    }
    bool unlock(){
        return pthread_mutex_unlock(&m_mutex) == 0;
    }
    pthread_mutex_t* getLock(){
        return &m_mutex;
    }
public:
    pthread_mutex_t m_mutex;
};

class cond {
public:
    cond(){
        if (pthread_cond_init(&m_cond, NULL) != 0) {
            throw std::exception();
        }
    }
    ~cond() {
        pthread_cond_destroy(&m_cond);
    }

    bool wait(pthread_mutex_t *m_mutex) {
        int ret = 0;
        ret = pthread_cond_wait(&m_cond, m_mutex);
        return ret == 0;
    }
    bool timewait(pthread_mutex_t *m_mutex, struct timespec t) {
        int ret = 0;
        ret = pthread_cond_timedwait(&m_cond, m_mutex, &t);
        return ret == 0;
    }
    bool signal() {
        return pthread_cond_signal(&m_cond) == 0;
    }
    bool broadcast() {
        return pthread_cond_broadcast(&m_cond) == 0;
    }

private:
    pthread_cond_t m_cond;
};

class sem{
public:
    sem(){
        if(sem_init(&m_sem, 0 ,0) != 0){
            throw std::exception();
        }
    }
    void init(int num){
        if(sem_init(&m_sem, 0, num) != 0){
            throw std::exception();
        }
    }
    ~sem(){
        sem_destroy(&m_sem);
    }
    bool wait(){
        return sem_wait(&m_sem) == 0; // 阻塞当前线程直到信号量sem的值大于0，解除阻塞后将sem的值减一。函数执行成功返回0
    }
    bool timewait(struct timespec timeout){
        int ret = 0;    
        ret = sem_timedwait(&m_sem, &timeout);
        return ret == 0;
    }
    bool post(){
        return sem_post(&m_sem) == 0; // 信号量加一。当有线程阻塞在这个信号量上时，调用这个函数会使其中的一个线程不在阻塞.函数执行成功返回0，
    }
private:
    sem_t m_sem;
};

#endif