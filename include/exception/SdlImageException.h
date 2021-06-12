#ifndef _SDL_IMAGE_EXCEPTION_H_
#define _SDL_IMAGE_EXCEPTION_H_

#include "Exception.h"

class SdlImageException : public Exception {
    public:
        SdlImageException(const char *description) noexcept;
        virtual ~SdlImageException() noexcept;
};

#endif // _SDL_IMAGE_EXCEPTION_H_