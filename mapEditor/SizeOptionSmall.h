#ifndef _SIZE_OPTION_SMALL_
#define _SIZE_OPTION_SMALL_

#include "MenuOption.h"
#include <vector>

class SizeOptionSmall : public MenuOption{
    private:
        SizeOptionSmall(const SizeOptionSmall &other) = delete;
        SizeOptionSmall& operator=(const SizeOptionSmall &other) = delete;
        SizeOptionSmall& operator=(SizeOptionSmall &&other) = delete;

    Window& window;

    public:
        SizeOptionSmall(Window &window);
        ~SizeOptionSmall();
        
        virtual bool mouseInButton(int x, int y);
        virtual bool clicked(std::vector<MenuOption*>& options) override;
        virtual void render() override;
        virtual const char* getPathToImage() override;
        virtual const char* getMapName() override;
        void setPair(std::pair<int,int>& pair);
};

#endif