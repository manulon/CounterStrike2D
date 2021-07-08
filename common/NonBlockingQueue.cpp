#include "NonBlockingQueue.h"
#include <exception>

template <class T>
void NonBlockingQueue<T>::push(T t){
    std::unique_lock<std::mutex> lk(m);
    queue.push(t);
}

template <class T>
T NonBlockingQueue<T>::pop(){
    std::unique_lock<std::mutex> lk(m);
    if (queue.empty()){
        return NULL;
    }
    T t = queue.front();
    queue.pop();
    return t;
}

