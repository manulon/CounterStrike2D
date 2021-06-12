#ifndef _SDL_INIT_H_
#define _SDL_INIT_H_

#include <cstdint>

class SdlInit {
    private:
        uint32_t flags;

        SdlInit(const SdlInit &other) = delete;
        SdlInit& operator=(const SdlInit &other) = delete;
        void createInit(uint32_t flags);
        void destroyInit();

    public:
        SdlInit(std::uint32_t flags);
        SdlInit(SdlInit &&other);
        ~SdlInit();
        SdlInit& operator=(SdlInit &&other);
};

#endif // _SDL_INIT_H_
