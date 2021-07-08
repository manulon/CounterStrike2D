#ifndef __TP3__THREAD_H_
#define __TP3__THREAD_H_
#include <iostream>
#include <thread>
#include <utility>



class Thread{
private:
    std::thread thread;
public:
    Thread();
    virtual ~Thread();
    void spawn();
    void join();
    virtual void run() = 0;
};

#endif
