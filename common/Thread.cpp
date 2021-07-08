#include "Thread.h"

Thread::Thread() {}
void Thread :: spawn() {
    thread = std::thread(&Thread::run, this);
}

void Thread::join() {
    this->thread.join();
}

Thread::~Thread() {}
