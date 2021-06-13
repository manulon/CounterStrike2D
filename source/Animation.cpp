/*
 * Created by Federico Manuel Gomez Peter
 * Date: 17/05/18.
 */
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>

#include "Area.h"
#include "Animation.h"
#include "SdlTexture.h"

Animation::Animation(const Image *image, int vframes, int hframes) : 
image(image), currentVerticalFrame(0),currentHorizontalFrame(0),
verticalFrames(vframes),horizontalFrames(hframes),size(32),
elapsed(0.0f) {}

Animation::~Animation() {}

void Animation::update(float dt) {
    this->elapsed += dt;
    /* checks if the frame should be updated based on the time elapsed since the last update */
    while (this->elapsed > FRAME_RATE) {
        this->advanceFrame();
        this->elapsed -= FRAME_RATE;
    }
}

void Animation::render(const Area &dst, const SDL_RendererFlip &flipType,int angle) {
    Area src(size * currentHorizontalFrame, size * currentVerticalFrame, size, size);
    this->image->render(src,dst,angle,flipType);
}

void Animation::advanceFrame() {
    currentVerticalFrame ++;

    if (currentVerticalFrame == verticalFrames){
        currentHorizontalFrame ++;
        currentVerticalFrame = 0;
    }

    if(currentHorizontalFrame == horizontalFrames-1){
        currentHorizontalFrame = 0;
    }
}
/*
void Animation::advanceFrame() {
    currentHorizontalFrame ++;

    if (currentHorizontalFrame == horizontalFrames-1){
        currentVerticalFrame ++;
        currentHorizontalFrame = 0;
    }

    if(currentVerticalFrame == verticalFrames){
        currentVerticalFrame = 0;
    }
}*/

void Animation:: clear() const {
    this->image->clear();    
}
