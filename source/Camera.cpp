#include "Camera.h"
#include <iostream>

Camera:: Camera(const Image& img):
img(img),x(0),y(0),scrollingOffset(0),
backgroundWidth(img.getWidth()),backgroundHeight(img.getHeight()){}

Camera:: ~Camera(){}

void Camera::move(int direction){
    if (direction == LEFT) {
        x += 3;
    }else if (direction == RIGHT) {
        x -= 3;
    }else if (direction == UP) {
        y += 3;
    }else if (direction == DOWN) {
        y -= 3;
    }

    --scrollingOffset;
    if( scrollingOffset < backgroundWidth )
        scrollingOffset = 0;
}

void Camera::render(const Area &dest){
    img.render(x,y,dest);
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
