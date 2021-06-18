#ifndef CAMERA_H 
#define CAMERA_H 

#include "Image.h"
#include "Directions.h"

//Hacerla movible pero no copiable.
class Camera{
    public:

        Camera(const Image& img);
        Camera(Camera &&other);
        ~Camera();
        void render(int x, int y, const Area &dest);
 

    private:
        Camera(const Camera &other) = delete;
        Camera& operator=(const Camera &other) = delete;
        Camera& operator=(Camera &&other) = delete;

        const Image& img;
        int x;
        int y;
};


#endif