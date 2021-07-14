#ifndef __BlockingQueue__
#define __BlockingQueue__
#include <iostream>
#include <mutex>
#include <queue>
#include <condition_variable>
#include "ClosedQueueException.h"



//sacado de clase 
template <class T>
class BlockingQueue{
    private:
        bool is_closed;
        std::mutex m;
        std::queue<T> queue;
        std::condition_variable cv;

    public:

        BlockingQueue() : is_closed(false){}
        BlockingQueue(BlockingQueue&& other) : is_closed(other.is_closed),m(), queue(std::move(other.queue)) , cv(){}
        void push(T t){
            std::unique_lock<std::mutex> lk(m);
            queue.push(t);
            std::cout<<"NOTIFICANDO\n";
            cv.notify_all();
        }
        T pop(){
            std::unique_lock<std::mutex> lk(m);
            while(queue.empty()){
                if (is_closed)
                    throw ClosedQueueException();
                std::cout<<"ESPERANDO\n"; 
                cv.wait(lk);
                std::cout<<"TERMINOLA ESPERA\n";
            }
            T t = queue.front();
            queue.pop();
            return t;
        }
        void close(){
            std::unique_lock<std::mutex> lk(m);
            is_closed = true;
            cv.notify_all();

        }
        ~BlockingQueue(){}
};


#endif