#ifndef _SDL_INIT_AUDIO_H_
#define _SDL_INIT_AUDIO_H_

#include <cstdint>

class SdlInitAudio {
    private:
        int frequency;
        uint16_t format;
        int channels; 
        int chunksize;
        
	    SdlInitAudio(const SdlInitAudio &other) = delete;
	    SdlInitAudio& operator=(const SdlInitAudio &other) = delete;
        void createInit(int frequency, uint16_t format, int channels, int chunksize);
	    void destroyInit();

    public:
        SdlInitAudio(int frequency, uint16_t format, int channels, int chunksize);
        SdlInitAudio(SdlInitAudio &&other);
        ~SdlInitAudio();
        SdlInitAudio& operator=(SdlInitAudio &&other);
};

#endif // _SDL_INIT_AUDIO_H_
