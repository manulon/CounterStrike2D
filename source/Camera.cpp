#include "Camera.h"
#include <iostream>

Camera:: Camera(const Image& img):
img(img),x(0),y(0){}

Camera::Camera(Camera &&other) : 
img(std::move(other.img)), x(other.x), y(other.y) {}

Camera:: ~Camera(){}

void Camera::render(int x, int y, const Area &dest){
    img.render(-x,-y,dest);
}
