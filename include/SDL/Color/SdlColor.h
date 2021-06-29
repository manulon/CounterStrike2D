#ifndef _SDL_COLOR_H_
#define _SDL_COLOR_H_

#include "SDL2/SDL.h"
#include <cstdint>

class SdlColor {
    private:
        SdlColor(const SdlColor &other) = delete;
        SdlColor& operator=(const SdlColor &other) = delete;

        SDL_Color textColor;

    public:
        SdlColor(int r, int g, int b);
        ~SdlColor();
        
        SDL_Color& getColor();
};

#endif // _SDL_INIT_H_