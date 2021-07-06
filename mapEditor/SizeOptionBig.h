#ifndef _SIZE_OPTION_BIG_
#define _SIZE_OPTION_BIG_

#include "MenuOption.h"
#include <vector>

class SizeOptionBig : public MenuOption{
    private:
        SizeOptionBig(const SizeOptionBig &other) = delete;
        SizeOptionBig& operator=(const SizeOptionBig &other) = delete;
        SizeOptionBig& operator=(SizeOptionBig &&other) = delete;

    Window& window;

    public:
        SizeOptionBig(Window &window);
        ~SizeOptionBig();

        virtual bool mouseInButton(int x, int y);
        virtual bool clicked(std::vector<MenuOption*>& options) override;
        virtual void render() override;
        virtual const char* getPathToImage() override;
        virtual const char* getMapName() override;
        void setPair(std::pair<int,int>& pair);
};

#endif