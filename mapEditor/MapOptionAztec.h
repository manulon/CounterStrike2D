#ifndef _MAP_OPTION_AZTEC_H
#define _MAP_OPTION_AZTEC_H

#include "MenuOption.h"

class MapOptionAztec : public MenuOption{
    private:
        MapOptionAztec(const MapOptionAztec &other) = delete;
        MapOptionAztec& operator=(const MapOptionAztec &other) = delete;
        MapOptionAztec& operator=(MapOptionAztec &&other) = delete;

    Window& window;

    public:
        MapOptionAztec(Window& window);
        ~MapOptionAztec();

        virtual const char* getPathToImage() override;
        virtual void render() override;
        virtual bool clicked(std::vector<MenuOption*>& options) override;
};

#endif