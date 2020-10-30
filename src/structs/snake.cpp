#include <SDL2/SDL.h>
#include "food.cpp"

struct Snake {
    int x, y;
    int vx, vy;
    uint32_t accumulator;

    void update(uint32_t delta_time, Food &food)
    {
        accumulator += delta_time;
        if (accumulator > 100) { // update every 100 ms
            accumulator = 0;

            x += vx;
            y += vy;

            if (x == food.x && y == food.y) {
                food.move();
            }
        }
    }

    void draw(SDL_Renderer* renderer)
    {
   		SDL_Rect r{ 16 * x, 16 * y, 16, 16 };
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderFillRect(renderer, &r);
    }
};
