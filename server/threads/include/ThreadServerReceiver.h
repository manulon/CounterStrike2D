#ifndef _THREAD_SERVER_RECEIVER_
#define _THREAD_SERVER_RECEIVER_
#include "Thread.h"
#include "Socket.h"
#include "NonBlockingQueue.h"
#include "BlockingQueue.h"
#include "ServerMessage.h"
#include "CommunicationProtocol.h"
#include "ProtocolConstants.h"
#include <map>
#include "ServerEvent.h"

class ThreadServerReceiver : public Thread {
private:
    Socket &skt;
    NonBlockingQueue<std::shared_ptr<ServerEvent>> &queue;
    bool isRunning;
    short clientID;
public:
    ThreadServerReceiver(Socket &skt, 
                         NonBlockingQueue<std::shared_ptr<ServerEvent>> &queue,
                         short clientID);
    ~ThreadServerReceiver(){}
    virtual void run() override;
    bool isDead();
};



#endif

