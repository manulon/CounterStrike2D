#include "Window.h"
#include <utility>
#include "SDL2/SDL.h"

Window::Window(const char *title, int width, 
			   int height, uint32_t windowFlags) 
	: sdlInit(SDL_INIT_VIDEO), 
	  sdlWindow(title, width, height, windowFlags), 
	  sdlRenderer(sdlWindow) { }

Window::Window(const char *title, int width, int height, 
               uint32_t windowFlags, uint32_t rendererFlags) 
	: sdlInit(SDL_INIT_VIDEO), 
	  sdlWindow(title, width, height, windowFlags), 
	  sdlRenderer(sdlWindow, rendererFlags) { }

Window::Window(const char *title, int x, 
			   int y, int width, int height, 
               uint32_t windowFlags, uint32_t rendererFlags) 
	: sdlInit(SDL_INIT_VIDEO),
	  sdlWindow(title, x, y, width, height, windowFlags), 
	  sdlRenderer(sdlWindow, rendererFlags) { }

Window::Window(Window &&other) 
	: sdlInit(std::move(other.sdlInit)),
	  sdlWindow(std::move(other.sdlWindow)),
	  sdlRenderer(std::move(other.sdlRenderer)) { }

Window::~Window() { }

Window& Window::operator=(Window &&other) {
	if (this == &other) return *this;
	sdlInit = std::move(other.sdlInit);
	sdlWindow = std::move(other.sdlWindow);
	sdlRenderer = std::move(other.sdlRenderer);
	return *this;
}

void Window::fill(std::uint8_t red, std::uint8_t green, 
		  		  std::uint8_t blue, std::uint8_t alpha) {
	sdlRenderer.setRendererDrawColor(red, green, blue, alpha);
	sdlRenderer.renderClear();
}

void Window::fill() {
	fill(0x33,0x33,0x33,0xFF);
}

void Window::render() {
	sdlRenderer.renderPresent();
}

SdlRenderer& Window::getRenderer() { 
	return sdlRenderer;
}
