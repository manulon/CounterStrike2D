#ifndef CAMERA_H 
#define CAMERA_H 

#include "Image.h"
#include "Directions.h"
#include "TileMap.h"

//Hacerla movible pero no copiable.
class Camera{
    public:

        Camera(TileMap& map);
        Camera(Camera &&other);
        ~Camera();
        void render(int x, int y, const Area &dest);
 

    private:
        Camera(const Camera &other) = delete;
        Camera& operator=(const Camera &other) = delete;
        Camera& operator=(Camera &&other) = delete;

        TileMap& map;
        int x;
        int y;
};


#endif