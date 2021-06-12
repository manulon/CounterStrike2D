#ifndef _SDL_SURFACE_H_
#define _SDL_SURFACE_H_

class SDL_Surface;
#include <cstdint>

struct Color {
    uint8_t red;
    uint8_t green;
    uint8_t blue;
};

class SdlSurface {
    private:
        SDL_Surface *surface;
        SdlSurface(const SdlSurface &other) = delete;
        SdlSurface& operator=(const SdlSurface &other) = delete;
        void destroySurface();
    
    public:
        SdlSurface(const char *pathImg);
        SdlSurface(int width, int height);
        SdlSurface(SdlSurface &&other);
        ~SdlSurface();
        SdlSurface& operator=(SdlSurface &&other);
        void setColorKey(Color key);
        SDL_Surface* getSurface() const;
};

#endif // _SDL_SURFACE_H_
