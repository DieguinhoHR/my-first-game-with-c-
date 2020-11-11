#include <SDL2/SDL.h>
#include <cstdlib>
#include <iostream>

#include "../headers/Food.h"

using namespace std;

void Food::move()
{        
    this->x = rand() % (600 / 18);
    this->y = rand() % (600 / 18);
}

void Food::draw(SDL_Renderer* renderer)
{
    SDL_Rect r{ 16 * this->x, 16 * this->y, 16, 16 };
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_RenderFillRect(renderer, &r);
}