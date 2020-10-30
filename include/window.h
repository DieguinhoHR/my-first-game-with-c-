#ifndef WINDOW_H
#define WINDOW_H
#include <SDL2/SDL.h>

SDL_Window* createWindow(SDL_Window *window);
void destroyWindow(SDL_Window *window, SDL_Renderer* renderer, SDL_Texture *snake);

#endif