#ifndef _RENDERIZABLE_FACTORY_H_
#define _RENDERIZABLE_FACTORY_H_
#include "DynamicObject.h"
#include "Window.h"
#include <memory>
#include <map>
class RenderizableFactory {
    private:
        Window &window;
        bool isPresent(short id, std::map<short,DynamicObject*> &objects);
        bool isSoldier(short id);
        bool isAk47(short id);
    public:
        RenderizableFactory(Window &window);
        ~RenderizableFactory(){}
        void createRenderizable(short id, std::map<short,DynamicObject*> &objects);

};



#endif