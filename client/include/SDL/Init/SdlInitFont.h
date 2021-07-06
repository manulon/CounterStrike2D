#ifndef _SDL_INIT_FONT_H_
#define _SDL_INIT_FONT_H_

class SdlInitFont {
    private:
        SdlInitFont(const SdlInitFont &other) = delete;
        SdlInitFont& operator=(const SdlInitFont &other) = delete;
        void createInit();
        void destroyInit();

    public:
        SdlInitFont();
        SdlInitFont(SdlInitFont &&other);
        ~SdlInitFont();
        SdlInitFont& operator=(SdlInitFont &&other);
};

#endif // _SDL_INIT_FONT_H_
