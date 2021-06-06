#ifndef _SDL_WINDOW_H_
#define _SDL_WINDOW_H_

class SDL_Window;
class SDL_Renderer;
#include <cstdint>

class SdlWindow {
    private:
        int width;
        int height;
        SDL_Window *window;
        SDL_Renderer *renderer;
    
    public:
        SdlWindow(int width, int height);
        ~SdlWindow();
        void fill();
        void fill(std::uint8_t r, std::uint8_t g, std::uint8_t b,
                  std::uint8_t alpha);
        void render();
        SDL_Renderer* getRenderer() const;
};

#endif // _SDL_WINDOW_H_
