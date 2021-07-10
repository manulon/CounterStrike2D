#ifndef _THREAD_SERVER_RECEIVER_
#define _THREAD_SERVER_RECEIVER_
#include "Thread.h"
#include "Socket.h"
#include "NonBlockingQueue.h"
class ThreadServerReceiver : public Thread {
private:
    Socket &skt;
    NonBlockingQueue<std::string> &queue;
public:
    ThreadServerReceiver(Socket &skt, NonBlockingQueue<> &queue);
    ~ThreadServerReceiver();
    virtual void run() override;
};



#endif

