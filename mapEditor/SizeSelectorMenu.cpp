#include "SizeSelectorMenu.h"

SizeSelectorMenu::SizeSelectorMenu():
color(0,0,0),selectedWidth(0),selectedHeight(0),
pair(selectedWidth,selectedHeight),mousePositionX(0),mousePositionY(0){}

void SizeSelectorMenu::setSizeOptions(Window& window){
    sizeOptions.push_back(new SizeOptionSmall(window));
    sizeOptions.push_back(new SizeOptionBig(window));
    sizeOptions.push_back(new SizeOptionHuge(window));
}

bool SizeSelectorMenu::handleEvents(){
    SDL_Event event;

    while (SDL_PollEvent(&event)){
        switch (event.type) {
            case SDL_MOUSEMOTION:
                return mouseMotionHandler(event);

            case SDL_MOUSEBUTTONDOWN:
                return mouseMotionDown(event);

            case SDL_MOUSEBUTTONUP:
                return mouseMotionUp(event);

            case SDL_QUIT:
                return false;
            }
    }
    return true;
}

bool SizeSelectorMenu::mouseMotionUp(SDL_Event& event){
    return true;
}

bool SizeSelectorMenu::mouseMotionDown(SDL_Event& event){
    for(auto& option: sizeOptions){
        if (option->mouseInButton(mousePositionX,mousePositionY)){
            option->setPair(pair);
            return false;
        }
    }
    return true;
}

std::pair<int,int>& SizeSelectorMenu::getPair(){
    return pair;
}

bool SizeSelectorMenu::mouseMotionHandler(SDL_Event& event){
    mousePositionX = event.motion.x;
    mousePositionY = event.motion.y;
    return true;
}

void SizeSelectorMenu::run(){
    Window window("Menu editor",725,100,
                  SDL_WINDOW_RESIZABLE,(SDL_INIT_VIDEO | SDL_INIT_AUDIO));

    Text title("assets/gfx/fonts/liberationsans.ttf", 40,"Seleccione un tamano de mapa",
               color.getColor(),window);
    Area titleRenderArea(180,0,400,45);
    setSizeOptions(window);

    bool keepRunning(true);
    while (keepRunning){
        window.clear();
        title.render(titleRenderArea);
        for (auto& option: sizeOptions){
            option->render();
        }
        keepRunning = handleEvents();
        window.render();
    }
    window.changeWindow();
}

SizeSelectorMenu::~SizeSelectorMenu(){
    for (auto& option: sizeOptions){
        delete option;
    }
}
