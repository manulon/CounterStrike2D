#ifndef _TEXT_H_
#define _TEXT_H_

#include "SdlFont.h"
#include "SdlTexture.h"
#include "Window.h"

class SdlRenderer;
class Area;

class Text {
	private:
		SdlFont sdlFont;
		SdlTexture sdlTexture;
		SdlRenderer &sdlRenderer;
		int posX;
		int posY;
		int width;
		int height;
		const char* asd;
		
		
		Text(const Text &other) = delete;
		Text& operator=(const Text &other) = delete;
		Text& operator=(Text &&other) = delete;

	public:
		Text(const char *fontPath, int ptsize,
		     const char *textToRender, 
		     SDL_Color color, 
		     Window &window);
		Text(Text &&other);
		~Text();
		void render(const Area &dest);
		bool mouseInText(int x, int y);
		void changeColor(int r, int g, int b);
		const char* getTextToRender();
};

#endif // _TEXT_H_
