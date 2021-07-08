#ifndef _CLOSED_QUEUE_EXCEPTION__
#define _CLOSED_QUEUE_EXCEPTION__
#include <exception>
class ClosedQueueException : public std::exception{
    public:
    const char *what(){
        return "Queue is closed";
    }

};

#endif