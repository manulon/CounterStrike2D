#ifndef _MAP_OPTION_INFERNO_H
#define _MAP_OPTION_INFERNO_H

#include "MenuOption.h"

class MapOptionInferno : public MenuOption{
    private:
        MapOptionInferno(const MapOptionInferno &other) = delete;
        MapOptionInferno& operator=(const MapOptionInferno &other) = delete;
        MapOptionInferno& operator=(MapOptionInferno &&other) = delete;

    Window& window;
    std::string path;

    public:
        MapOptionInferno(Window& Window);
        ~MapOptionInferno();

        virtual bool mouseInButton(int x, int y);
        virtual const char* getPathToImage() override;
        virtual void render() override;
        virtual bool clicked(std::vector<MenuOption*>& options) override;
        virtual const char* getMapName() override;

        virtual void setPair(std::pair<int,int>& pair) override;
};

#endif