#include "SdlWindow.h"
#include "SdlInit.h"
#include "SdlException.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_video.h>
#include <SDL2/SDL_render.h>
#include <iostream>


SdlWindow::SdlWindow(int width, int height) : width(width), 
                                              height(height),
                                              window(nullptr), 
                                              renderer(nullptr) {
    SdlInit(SDL_INIT_VIDEO);
    int errCode = SDL_CreateWindowAndRenderer(width, height, 
                                              SDL_RENDERER_ACCELERATED,
                                              &window, &renderer);
    if (errCode < 0) {
        throw SdlException("SdlWindow no pudo crear la ventana y renderizarla. SDL_Error:");
    }
}

SdlWindow::~SdlWindow() {
    if (window != nullptr) {
        SDL_DestroyWindow(window);
    }

    if (renderer != nullptr) {
        SDL_DestroyRenderer(renderer);
    }
}

void SdlWindow::fill(std::uint8_t r, std::uint8_t g, std::uint8_t b,
                     std::uint8_t alpha) {
    int errCode = SDL_SetRenderDrawColor(renderer, r, g, b, alpha);
    if (errCode < 0){
        throw SdlException("SdlWindow no pudo renderizar el color para dibujar. SDL_Error:");
    }

    errCode = SDL_RenderClear(renderer);
    if (errCode < 0) {
        throw SdlException("SdlWindow no limpiar el renderizado. SDL_Error:");
    }
}

void SdlWindow::fill() {
    fill(0x33,0x33,0x33,0xFF);
}

void SdlWindow::render() {
    SDL_RenderPresent(renderer);
}


SDL_Renderer* SdlWindow::getRenderer() const {
    return renderer;
}
