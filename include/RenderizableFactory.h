#ifndef _RENDERIZABLE_FACTORY_H_
#define _RENDERIZABLE_FACTORY_H_
#include "DynamicObject.h"
#include "Window.h"
#include <memory>
class RenderizableFactory {
    private:
        Window &window;
    public:
        RenderizableFactory(Window &window);
        ~RenderizableFactory(){}
        DynamicObject* createRenderizable(short id);
        
};



#endif