#include <iostream>
#include <SDL2/SDL.h>
#include "../include/window.h"
#include "../include/image.h"
#include "./structs/snake.cpp"
#include "events/command_event.cpp"

using namespace std;

int main(int argc, char* args[]) 
{
    bool running = true;
    SDL_Window *window;
    Snake snake = {};
    Food food = {};
    food.move();

    uint32_t current_time = 0, previous_time, delta_time;

    window = createWindow(window);
    // Criar o renderizador para desenhar coisas na janela
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_Texture *snakeImage = load("images/snake.bmp", renderer);    

    while (running) {
        previous_time = current_time;
        current_time = SDL_GetTicks();
        delta_time = current_time - previous_time;

        snake = snakeMove(running, snake);
      
        snake.update(delta_time, food);

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        snake.draw(renderer);
        food.draw(renderer);

        SDL_RenderPresent(renderer);
        // Limpa o fundo da tela
        SDL_RenderClear(renderer);      
    } 
    destroyWindow(window, renderer, snakeImage);

    return 0;
}