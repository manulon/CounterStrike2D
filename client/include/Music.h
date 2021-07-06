#ifndef _MUSIC_H_
#define _MUSIC_H_

#include "SdlMusic.h"
#include <string>

class Music {
    private:
        SdlMusic sdlMusic;

        Music(const Music &other) = delete;
        Music& operator=(const Music &other) = delete;
    
    public:
        Music(const std::string &musicPath);
        Music(Music &&other);
        ~Music();
        Music& operator=(Music &&other);
        void playMusic(int loops) const;
};

#endif // _MUSIC_H_
