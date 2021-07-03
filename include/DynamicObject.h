#ifndef _RENDERIZABLE_OBJECT_H_
#define _RENDERIZABLE_OBJECT_H_
#include "Area.h"

class DynamicObject{
    protected: 
        int x, y; //posicion en pixeles
        int width, height;
        Area getDest(int otherX, int otherY);
    private:

    public:
        DynamicObject(int width, int height);
        ~DynamicObject(){}
        virtual void setPos(int xx,int yy);
        virtual void render(int x, int y) = 0;
};



#endif