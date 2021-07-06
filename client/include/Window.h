#ifndef _WINDOW_H_
#define _WINDOW_H_

#include "SdlWindow.h"
#include "SdlRenderer.h"
#include <cstdint>

class Window {
	private:
		SdlWindow sdlWindow;
		SdlRenderer sdlRenderer;
		int height;
		int width;

		Window(const Window &other) = delete;
		Window& operator=(const Window &other) = delete;
		void clear(uint8_t red, uint8_t green, 
				  uint8_t blue, uint8_t alpha);

	public:
		Window(const char *title, int width, 
			   int height, uint32_t windowFlags, uint32_t type);
		Window(const char *title, int width, int height, 
               uint32_t windowFlags, uint32_t rendererFlags, uint32_t type);
		Window(const char *title, int x, 
			   int y, int width, int height, 
               uint32_t windowFlags, uint32_t rendererFlags, uint32_t type);
		Window(Window &&other);
		~Window();
		Window& operator=(Window &&other);
		void clear();
		void render();
		int getHeight();
		int getWidth();
		void changeWindow();
		SdlRenderer& getRenderer();
};

#endif // _WINDOW_H_
