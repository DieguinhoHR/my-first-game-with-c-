#ifndef FOOD_H
#define FOOD_H

#include <SDL2/SDL.h>

class Food
{
    public:
        int x, y;
        void move();
        void draw(SDL_Renderer* renderer);
};

#endif
