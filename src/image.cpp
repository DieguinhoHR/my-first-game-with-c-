#include <iostream>
#include "../headers/Window.h"
#include <SDL2/SDL.h>

SDL_Texture* load(const char *path, SDL_Renderer *renderer)
{
    SDL_Surface *surface = SDL_LoadBMP(path); // retorna um surface
    if (!surface) {
        std::cout << "Erro carregando " << path << std::endl;
        return nullptr;
    }
    return SDL_CreateTextureFromSurface(renderer, surface);
}
