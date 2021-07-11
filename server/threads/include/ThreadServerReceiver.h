#ifndef _THREAD_SERVER_RECEIVER_
#define _THREAD_SERVER_RECEIVER_
#include "Thread.h"
#include "Socket.h"
#include "NonBlockingQueue.h"
#include "ClientEvent.h"
#include "CommunicationProtocol.h"
#include "ProtocolConstants.h"

class ThreadServerReceiver : public Thread {
private:
    Socket &skt;
    NonBlockingQueue<std::unique_ptr<ClientEvent>> &queue;
    bool isRunning;
public:
    ThreadServerReceiver(Socket &skt, NonBlockingQueue<std::unique_ptr<ClientEvent>> &queue);
    ~ThreadServerReceiver();
    virtual void run() override;
};



#endif

