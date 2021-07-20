#ifndef _GAME_ENDED_EXCEPTION_H_
#define _GAME_ENDED_EXCEPTION_H_

#include "Exception.h"

class GameEndedException : public Exception {
    public:
        GameEndedException() noexcept;
        virtual ~GameEndedException() noexcept;
};

#endif 
