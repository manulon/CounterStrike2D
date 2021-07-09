#include "Camera.h"



Camera::Camera(TileMap& map):
map(map),x(0),y(0){}

Camera::Camera(Camera &&other) : 
map(other.map), x(other.x), y(other.y) {}

Camera::~Camera(){}

void Camera::render(float x, float y, const Area &dest, std::list<Entity*> &serverObjects){
    float xOffset = map.getxOffset();
    float yOffset = map.getyOffset();
    map.render(-(x + xOffset)*PPM,-(y + yOffset)*PPM,dest);
    map.updateAndRenderObjects(-(x + xOffset)*PPM,-(y + yOffset)*PPM,serverObjects);
}
