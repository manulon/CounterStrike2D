#ifndef __NON_BLOCKING_QUEUE_
#define __NON_BLOCKING_QUEUE_
#include <iostream>
#include <mutex>
#include <queue>
#include <condition_variable>



//sacado de clase 
template <class T>
class NonBlockingQueue{
    private:
        std::mutex m;
        std::queue<T> queue;

    public:

        NonBlockingQueue(){}
        void push(T t);
        T pop();
        ~NonBlockingQueue(){}
};


#endif