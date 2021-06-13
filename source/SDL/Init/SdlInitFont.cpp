#include "SdlInitFont.h"
#include "SdlFontException.h"
#include <SDL2/SDL_ttf.h>

SdlInitFont::SdlInitFont() {
	createInit();
}

void SdlInitFont::createInit(){
	int errCode = TTF_Init();
    if(errCode == -1) {
	    throw SdlFontException("No pudo inicializar biblioteca TFF. SDL_Error:");
	}
}

SdlInitFont::SdlInitFont(SdlInitFont &&other) {
    createInit();
    other.destroyInit();
}

void SdlInitFont::destroyInit() {
    TTF_Quit();
}

SdlInitFont::~SdlInitFont() {
	destroyInit();
}

SdlInitFont& SdlInitFont::operator=(SdlInitFont &&other) {
	if (this == &other) return *this;
	destroyInit();
    createInit();
    other.destroyInit();
    return *this;	
}

