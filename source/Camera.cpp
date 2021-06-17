#include "Camera.h"
#include <iostream>

Camera:: Camera(const Image& img):
img(img),x(0),y(0),scrollingOffset(0),
backgroundWidth(img.getWidth()),backgroundHeight(img.getHeight()){}

Camera:: ~Camera(){}

void Camera::move(){
    --scrollingOffset;
    if( scrollingOffset < backgroundWidth )
        scrollingOffset = 0;
}

void Camera::render(int x, int y, const Area &dest){
    img.render(-x,-y,dest);
}

int Camera::getScrollingOffset(){
    return scrollingOffset;
}

int Camera:: getBackgroundWidth(){
    return backgroundWidth;
}

int Camera:: getBackgroundHeight(){
    return backgroundHeight;
}
