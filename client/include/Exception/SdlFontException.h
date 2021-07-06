#ifndef _SDL_FONT_EXCEPTION_H_
#define _SDL_FONT_EXCEPTION_H_

#include "Exception.h"

class SdlFontException : public Exception {
    public:
        SdlFontException(const char *description) noexcept;
        virtual ~SdlFontException() noexcept;
};

#endif // _SDL_FONT_EXCEPTION_H_
