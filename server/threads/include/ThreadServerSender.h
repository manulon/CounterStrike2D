#ifndef _THREAD_SERVER_SENDER_
#define _THREAD_SERVER_SENDER_

#include "Thread.h"
#include "Socket.h"
#include "BlockingQueue.h"
#include "CommunicationProtocol.h"
#include "ProtocolConstants.h"
#include "ServerMessage.h"

class ThreadServerSender : public Thread {
private:
    Socket &skt;
    BlockingQueue<ServerMessage*> *queue;
    // int id;
    bool isRunning;
public:
    ThreadServerSender(Socket &skt, BlockingQueue<ServerMessage*> *queue);
    ~ThreadServerSender(){}
    virtual void run() override;
    bool isDead();
};



#endif

