#include <iostream>
#include "../include/window.h"
#include <SDL2/SDL.h>

SDL_Texture* load(const char *image, SDL_Renderer *renderer)
{
    SDL_Surface *surface = SDL_LoadBMP(image);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    return texture;
}
