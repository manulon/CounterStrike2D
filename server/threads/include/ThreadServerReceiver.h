#ifndef _THREAD_SERVER_RECEIVER_
#define _THREAD_SERVER_RECEIVER_
#include "Thread.h"
#include "Socket.h"
#include "NonBlockingQueue.h"
#include "../common/Event.h"
#include "CommunicationProtocol.h"
#include "ProtocolConstants.h"

class ThreadServerReceiver : public Thread {
private:
    Socket &skt;
    NonBlockingQueue<std::shared_ptr<Event>> &queue;
    bool isRunning;
public:
    ThreadServerReceiver(Socket &skt, NonBlockingQueue<std::shared_ptr<Event>> &queue);
    ~ThreadServerReceiver(){}
    virtual void run() override;
    bool isDead();
};



#endif

