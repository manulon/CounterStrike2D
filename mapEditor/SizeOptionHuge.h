#ifndef _SIZE_OPTION_HUGE_
#define _SIZE_OPTION_HUGE_

#include "MenuOption.h"
#include <vector>

class SizeOptionHuge : public MenuOption{
    private:
        SizeOptionHuge(const SizeOptionHuge &other) = delete;
        SizeOptionHuge& operator=(const SizeOptionHuge &other) = delete;
        SizeOptionHuge& operator=(SizeOptionHuge &&other) = delete;

    Window& window;

    public:
        SizeOptionHuge(Window &window);
        ~SizeOptionHuge();

        virtual bool mouseInButton(int x, int y);
        virtual bool clicked(std::vector<MenuOption*>& options) override;
        virtual void render() override;
        virtual const char* getPathToImage() override;
        virtual const char* getMapName() override;
        void setPair(std::pair<int,int>& pair);
};

#endif