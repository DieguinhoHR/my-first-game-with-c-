#include "../includes.h"

#include "../headers/Window.h"
#include "../headers/CommandEvent.h"
#include "../headers/Food.h"

#include "../headers/Snake.h"
#include "../headers/Game.h"

using namespace std;

void Game::execGame()
{
    CommandEvent *commandEvent = new CommandEvent(); 
    Snake *snake = new Snake(); 
    Food *food = new Food();
    Window *windowObject = new Window();

    bool running = true;
    SDL_Window *window;

    uint32_t current_time = 0, previous_time, delta_time;

    window = windowObject->createWindow(window);
    //Criar o renderizador para desenhar coisas na janela
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    food->move();
    snake->emitSoundWav("./sounds/music_game.wav");  
  
    while (running) {
        previous_time = current_time;
        current_time = SDL_GetTicks();
        // delta_time foi feito pra calcular a velocidade do jogo
        delta_time = current_time - previous_time;

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
        SDL_RenderClear(renderer);


        commandEvent->snakeMove(running, *snake);
        snake->update(delta_time, *food, running, renderer);
        
        snake->draw(renderer, snake);
        food->draw(renderer);

        SDL_RenderPresent(renderer);
    } 
    windowObject->destroyWindow(window, renderer);
};