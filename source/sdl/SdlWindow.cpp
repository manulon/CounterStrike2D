#include "SdlWindow.h"
#include "SdlException.h"
#include <SDL2/SDL.h>

SdlWindow::SdlWindow(const char *title, int width, 
                     int height, uint32_t flags)
    : SdlWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
                width, height, flags) { }

SdlWindow::SdlWindow(const char *title, int x, int y, 
                     int width, int height, uint32_t flags) : window(nullptr) {
    window =  SDL_CreateWindow(title, x, y, width, height, flags);
    if (window == nullptr) {
        throw SdlException("SdlWindow no pudo crear la ventana. SDL_Error:");
    }
}

SdlWindow::SdlWindow(SdlWindow &&other) : window(other.window) {
    other.window = nullptr;
}

SdlWindow::~SdlWindow() {
    destroyWindow();
}

SdlWindow& SdlWindow::operator=(SdlWindow &&other) {
    if (this == &other) return *this;
    destroyWindow();
    window = other.window;
    other.window = nullptr;
    return *this;
}

void SdlWindow::destroyWindow() {
    if (window != nullptr) {
        SDL_DestroyWindow(window);
    }
}

SDL_Window* SdlWindow::getWindow() const {
    return window;
}
