#include "Window.h"
#include <utility>
#include "SDL2/SDL.h"

Window::Window(const char *title, int width, 
			   int height, uint32_t windowFlags, 
			   uint32_t type) 
	: sdlWindow(title, width, height, windowFlags, type), 
	  sdlRenderer(sdlWindow) { 
	clear();
}

Window::Window(const char *title, int width, int height, 
               uint32_t windowFlags, uint32_t rendererFlags, 
               uint32_t type) 
	: sdlWindow(title, width, height, windowFlags, type), 
	  sdlRenderer(sdlWindow, rendererFlags) { }

Window::Window(const char *title, int x, 
			   int y, int width, int height, 
               uint32_t windowFlags, uint32_t rendererFlags, 
               uint32_t type) 
	: sdlWindow(title, x, y, width, height, windowFlags, type), 
	  sdlRenderer(sdlWindow, rendererFlags) { }

Window::Window(Window &&other) 
	: sdlWindow(std::move(other.sdlWindow)),
	  sdlRenderer(std::move(other.sdlRenderer)) { }

Window::~Window() { }

Window& Window::operator=(Window &&other) {
	if (this == &other) return *this;
	sdlWindow = std::move(other.sdlWindow);
	sdlRenderer = std::move(other.sdlRenderer);
	return *this;
}

void Window::clear(uint8_t red, uint8_t green, 
		  		  uint8_t blue, uint8_t alpha) {
	sdlRenderer.setRendererDrawColor(red, green, blue, alpha);
	sdlRenderer.renderClear();
}

void Window::clear() {
	clear(0x33,0x33,0x33,SDL_ALPHA_OPAQUE);
}

void Window::render() {
	sdlRenderer.renderPresent();
}

SdlRenderer& Window::getRenderer() { 
	return sdlRenderer;
}
