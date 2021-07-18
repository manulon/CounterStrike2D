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
    std::shared_ptr<BlockingQueue<std::shared_ptr<ServerMessage>>> queue;
    // int id;
    bool isRunning;
public:
    ThreadServerSender(Socket &skt, std::shared_ptr<BlockingQueue<std::shared_ptr<ServerMessage>>> queue);
    ~ThreadServerSender(){}
    virtual void run() override;
    bool isDead();
    void stop();
};



#endif

