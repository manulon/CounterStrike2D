#ifndef _SDL_SURFACE_H_
#define _SDL_SURFACE_H_

class SDL_Surface;

class SdlSurface {
    private:
        SDL_Surface* surface;
        SdlSurface(const SdlSurface &other) = delete;
        SdlSurface& operator=(const SdlSurface &other) = delete;
        void destroySurface();
    
    public:
        SdlSurface(const char *pathImg);
        SdlSurface(SdlSurface &&other);
        ~SdlSurface();
        SdlSurface& operator=(SdlSurface &&other);
        SDL_Surface* getSurface() const;
};

#endif // _SDL_SURFACE_H_
