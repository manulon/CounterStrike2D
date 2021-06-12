#ifndef _STENCIL_H_
#define _STENCIL_H_

#include "SdlTexture.h"
class SdlRenderer;
class Window;
class Area;

class Stencil {
    private:
        SdlTexture sdlTexture;
        SdlRenderer &sdlRenderer;
        int width;
        int height;

        Stencil(const Stencil &other) = delete;
        Stencil& operator=(const Stencil &other) = delete;
        Stencil& operator=(Stencil &&other) = delete;
        void clear();
        void drawStencil(int Xc, int Yc, int viewR, float viewAngle);
        void drawCircle(int Xc, int Yc, int r);
        
        // Trabaja con maximo 180 grados de vision 
        // TODO Aumentar la capacidad a mas de 180 grados.
        void drawViewAngle(int viewAngle);
        void convertTexture();
    
    public:
        Stencil(int width, int height, int viewR, int viewAngle, uint8_t alpha, Window &window);
        Stencil(Stencil &&other);
        ~Stencil();
        void render(const Area &dest, const double angle) const;
};

#endif // _STENCIL_H_
