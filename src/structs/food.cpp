#include <SDL2/SDL.h>
#include <cstdlib>

struct Food {
    int x, y;

    void move()
    {
        x = rand() % (800 / 16);
        y = rand() % (800 / 16);
    }

    void draw(SDL_Renderer* renderer)
    {
        SDL_Rect r{ 16 * x, 16 * y, 16, 16 };
        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
        SDL_RenderFillRect(renderer, &r);
    }
};