#include "Thread.h"

Thread::Thread() {}

Thread::Thread(Thread &&other) : thread {std::move(other.thread)} { }

Thread::~Thread() {}

Thread& Thread::operator=(Thread &&other) {
    if (this == &other) return *this;
    thread = std::move(other.thread);
    return *this;
}

void Thread :: spawn() {
    thread = std::thread(&Thread::run, this);
}

void Thread::join() {
    this->thread.join();
}
