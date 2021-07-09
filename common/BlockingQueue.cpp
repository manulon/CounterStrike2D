#include "BlockingQueue.h"
#include "ClosedQueueException.h"
#include <exception>

template <class T>
void BlockingQueue<T>::push(T t){
    std::unique_lock<std::mutex> lk(m);
    queue.push(t);
    cv.notify_all();
}

template <class T>
T BlockingQueue<T>::pop(){
    std::unique_lock<std::mutex> lk(m);
    while(queue.empty()){
        if (is_closed)
            throw ClosedQueueException(); 
        cv.wait(lk);
    }
    T t = queue.front();
    queue.pop();
    return t;
}

template <class T>
void BlockingQueue<T>::close(){
    std::unique_lock<std::mutex> lk(m);
    is_closed = true;
    cv.notify_all();

}