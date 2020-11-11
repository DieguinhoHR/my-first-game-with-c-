#ifndef WINDOW_H
#define WINDOW_H
#include <SDL2/SDL.h>

class Window
{
    public:
        SDL_Window* createWindow(SDL_Window *window);
        void destroyWindow(SDL_Window *window, SDL_Renderer* renderer);
};

#endif