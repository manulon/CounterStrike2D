#ifndef _BULLETT_H_
#define _BULLETT_H_
#include "Image.h"
#include "DynamicObject.h"
#include <string>
class Bullett : public DynamicObject{
    const Image image; 
        int x, y;
        int width, height;
        Bullett(const Bullett &other) = delete;
        Bullett& operator=(const Bullett &other) = delete;
        Bullett& operator=(Bullett &&other) = delete;
    public:
        Bullett(std::string imgPath,Window &window);
        Bullett(Bullett &&other);
        virtual void render(int x, int y) override;
        // void setPos(int xx, int yy);
        ~Bullett();
};



#endif