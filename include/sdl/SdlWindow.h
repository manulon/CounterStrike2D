#ifndef _SDL_WINDOW_H_
#define _SDL_WINDOW_H_

#include "SdlInit.h"
#include <cstdint>
class SDL_Window;

class SdlWindow {
    private:
        SdlInit sdlInit;
        SDL_Window *window;

        SdlWindow(const SdlWindow &other) = delete;
        SdlWindow& operator=(const SdlWindow &other) = delete;
        void destroyWindow();
    
    public:
        SdlWindow(const char *title, int width, 
                  int height, uint32_t flags, uint32_t type);
        SdlWindow(const char *title, int x, int y, 
                  int width, int height, uint32_t flags, uint32_t type);
        SdlWindow(SdlWindow &&other);
        ~SdlWindow();
        SdlWindow& operator=(SdlWindow &&other);
        SDL_Window* getWindow() const;
};

#endif // _SDL_WINDOW_H_
