#ifndef _WINDOW_H_
#define _WINDOW_H_

#include "SdlInit.h"
#include "SdlWindow.h"
#include "SdlRenderer.h"
#include <cstdint>

class Window {
	private:
		SdlInit sdlInit;
		SdlWindow sdlWindow;
		SdlRenderer sdlRenderer;

		Window(const Window &other) = delete;
		Window& operator=(const Window &other) = delete;
		void fill(std::uint8_t red, std::uint8_t green, 
				  std::uint8_t blue, std::uint8_t alpha);
		void fill();

	public:
		Window(const char *title, int width, 
			   int height, uint32_t windowFlags);
		Window(const char *title, int width, int height, 
               uint32_t windowFlags, uint32_t rendererFlags);
		Window(const char *title, int x, 
			   int y, int width, int height, 
               uint32_t windowFlags, uint32_t rendererFlags);
		Window(Window &&other);
		~Window();
		Window& operator=(Window &&other);
		void render();
		SdlRenderer& getRenderer();
};

#endif // _WINDOW_H_
