#ifndef _SDL_EXCEPTION_H_
#define _SDL_EXCEPTION_H_

#include "Exception.h"

class SdlException : public Exception {
    public:
        SdlException(const char *description) noexcept;
        virtual ~SdlException() noexcept;
};

#endif // _SDL_EXCEPTION_H_
