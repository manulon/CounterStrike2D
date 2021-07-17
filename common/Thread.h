#ifndef _THREAD_H_
#define _THREAD_H_
#include <iostream>
#include <thread>
#include <utility>

class Thread{
    private:
        std::thread thread;
        
    public:
        Thread();
        Thread(Thread &&other);
        virtual ~Thread();
        Thread& operator=(Thread &&other);
        void spawn();
        void join();
        virtual void run() = 0;
};

#endif // _THREAD_H_
