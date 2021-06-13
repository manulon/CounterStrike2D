/*
 * Created by Federico Manuel Gomez Peter
 * Date: 17/05/18.
 */

#ifndef __ANIMATION_H__
#define __ANIMATION_H__

#include <SDL2/SDL.h>

#include "SdlException.h"
#include "Image.h"
#include "SdlTexture.h"

#define FRAME_RATE 1000000.0f/25.0f

class Area;

class Animation {
   public:
    Animation(const Image *img, int vframes, int hframes);
    ~Animation();
    void update(float dt);
    void render(const Area& dst, const SDL_RendererFlip &flipType, int angle);
    void clear() const ;

   private:
    void advanceFrame();
    /** SDL texture of the raw image. */
    const Image *image;
    /** Current animation frame. */
    int currentVerticalFrame;
    int currentHorizontalFrame;
    /** Total number of frames in the sprite. */
    int verticalFrames;
    int horizontalFrames;
    /** Size of the sprite (height and width). */
    int size;
    /** Time elapsed since last update. */
    float elapsed;
};

#endif  //__ANIMATION_H__