#ifndef _THREAD_SERVER_SENDER_
#define _THREAD_SERVER_SENDER_

#include "Thread.h"
#include "Socket.h"
#include "BlockingQueue.h"
#include "CommunicationProtocol.h"
#include "ProtocolConstants.h"

class ThreadServerSender : public Thread {
private:
    Socket &skt;
    std::shared_ptr<BlockingQueue<std::string>> &queue;
    int id;
    bool isRunning;
public:
    ThreadServerSender(Socket &skt, std::shared_ptr<BlockingQueue<std::string>> &queue, int id);
    ~ThreadServerSender();
    virtual void run() override;
};



#endif

