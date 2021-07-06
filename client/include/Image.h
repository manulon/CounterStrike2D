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
        const char* path;

        Image(const Image &other) = delete;
        //Image& operator=(const Image &other) = delete;
        //Image& operator=(Image &&other) = delete;
    
    public:
        Image();
        Image(const char *pathImg);
        Image(const char *pathImg, Window &window);

        Image(Image &&other);
        Image& operator=(Image &&other);
        Image& operator=(const Image &other);
        ~Image();
        void render(int x, int y,const Area &dest) const;
        void render(const Area &dest) const;
        void render(const Area &src, const Area &dest) const;
        void render(const Area &src, const Area &dest, float angle, const SDL_RendererFlip &flipType) const;
        const SdlTexture* getTexture() const;
        int getWidth() const;
        int getHeight() const;
        const char* getPath() const;
};

#endif // _IMAGE_H_
