#ifndef _MAP_OPTION_INFERNO_H
#define _MAP_OPTION_INFERNO_H

#include "MenuOption.h"

class MapOptionInferno : public MenuOption{
    private:
        MapOptionInferno(const MapOptionInferno &other) = delete;
        MapOptionInferno& operator=(const MapOptionInferno &other) = delete;
        MapOptionInferno& operator=(MapOptionInferno &&other) = delete;

    Window& window;

    public:
        MapOptionInferno(Window& Window);
        ~MapOptionInferno();

        virtual const char* getPathToImage() override;
        virtual void render() override;
        virtual bool clicked(std::vector<MenuOption*>& options) override;
        virtual const char* getMapName() override;
};

#endif