#ifndef __NON_BLOCKING_QUEUE_
#define __NON_BLOCKING_QUEUE_
#include <iostream>
#include <mutex>
#include <queue>

template <class T>
class NonBlockingQueue {
    private:
        std::mutex m;
        std::queue<T> queue;

    public:

        NonBlockingQueue(){}
        NonBlockingQueue(NonBlockingQueue &&other) : m(other.m), queue(other.queue) {}
        void push(T t){
            std::unique_lock<std::mutex> lk(m);
            queue.push(t);
        }

        T pop(){
            std::unique_lock<std::mutex> lk(m);
            if (queue.empty()){
                return nullptr;
            }
            T t = queue.front();
            queue.pop();
            return t;
        }

        ~NonBlockingQueue(){}
};


#endif