#ifndef __BlockingQueue__
#define __BlockingQueue__
#include <iostream>
#include <mutex>
#include <queue>
#include <condition_variable>



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
        void push(T t);
        T pop();
        void close();
        ~BlockingQueue(){}
};


#endif