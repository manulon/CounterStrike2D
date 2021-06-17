#include "Camera.h"
#include <iostream>

Camera:: Camera(const Image& img):
img(img),x(0),y(0){}

Camera:: ~Camera(){}

void Camera::render(int x, int y, const Area &dest){
    img.render(-x,-y,dest);
}
