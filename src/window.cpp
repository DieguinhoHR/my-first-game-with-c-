#include <iostream>
#include "../include/window.h"
#include <SDL2/SDL.h>

SDL_Window* createWindow(SDL_Window *window)
{
    const static auto WIDTH = 800;
    const static auto HEIGHT = 800;

    if (window == NULL) {
        std::cout << "Não pode criar a janela: " << SDL_GetError();
        return nullptr;
    }

    return SDL_CreateWindow("Snake game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
}


void destroyWindow(SDL_Window *window, SDL_Renderer* renderer, SDL_Texture *snake) 
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyTexture(snake);
    SDL_Quit();
}

