#ifndef SDL_MIX_EXCEPTION_H_
#define SDL_MIX_EXCEPTION_H_

#include "Exception.h"

class SdlMixException : public Exception {
    public:
        SdlMixException(const char *description) noexcept;
        virtual ~SdlMixException() noexcept;
};

#endif // SDL_MIX_EXCEPTION_H_
