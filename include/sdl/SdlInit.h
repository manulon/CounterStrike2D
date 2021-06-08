#ifndef _SDL_INIT_H_
#define _SDL_INIT_H_

#include <cstdint>

class SdlInit {
    private:
        SdlInit(const SdlInit &other) = delete;
        SdlInit& operator=(const SdlInit &other) = delete;
        void destroyInit();

    public:
        SdlInit(std::uint32_t flags);
        SdlInit(SdlInit &&other);
        ~SdlInit();
        SdlInit& operator=(SdlInit &&other);
};

#endif // _SDL_INIT_H_
