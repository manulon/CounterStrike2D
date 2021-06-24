#include "Camera.h"
#include <iostream>

Camera:: Camera(TileMap& map):
map(map),x(0),y(0){}

Camera::Camera(Camera &&other) : 
map(other.map), x(other.x), y(other.y) {}

Camera:: ~Camera(){}

void Camera::render(int x, int y, const Area &dest){
    //img.render(-x,-y,dest);
    map.render(-x,-y,dest);
}
