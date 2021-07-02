#ifndef _MAP_OPTION_DUST_H
#define _MAP_OPTION_DUST_H

#include "MenuOption.h"

class MapOptionDust : public MenuOption{
    private:
        MapOptionDust(const MapOptionDust &other) = delete;
        MapOptionDust& operator=(const MapOptionDust &other) = delete;
        MapOptionDust& operator=(MapOptionDust &&other) = delete;

    Window& window;

    public:
        MapOptionDust(Window& window);
        ~MapOptionDust();

        virtual const char* getPathToImage() override;
        virtual void render() override;
        virtual bool clicked(std::vector<MenuOption*>& options) override;
        virtual const char* getMapName() override;
};

#endif