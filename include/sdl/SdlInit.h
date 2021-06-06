#ifndef _SDL_INIT_H_
#define _SDL_INIT_H_

#include <cstdint>

class SdlInit {    
    public:
        SdlInit(std::uint32_t flags);
        ~SdlInit();
};

#endif // _SDL_INIT_H_
