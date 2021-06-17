#ifndef _IMAGE_H_
#define _IMAGE_H_

#include "SdlTexture.h"
class SdlRenderer;
class Window;
class Area;

class Image {
    private:
        SdlTexture sdlTexture;
        SdlRenderer &sdlRenderer;

        Image(const Image &other) = delete;
        Image& operator=(const Image &other) = delete;
        Image& operator=(Image &&other) = delete;
    
    public:
        Image(const char *pathImg);
        Image(const char *pathImg, Window &window);

        Image(Image &&other);
        ~Image();
        /*manu*/void render(int x, int y,const Area &dest) const;
        void render(const Area &dest) const;
        void render(const Area &src, const Area &dest) const;
        void render(const Area &src, const Area &dest, float angle, const SDL_RendererFlip &flipType) const;
        const SdlTexture* getTexture() const;
        int getWidth() const;
        int getHeight() const;
};

#endif // _IMAGE_H_
