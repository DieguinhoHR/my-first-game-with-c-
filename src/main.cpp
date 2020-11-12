#include <iostream>
#include "../headers/Game.h"
#include <SDL2/SDL.h>

int main(int argc, char* args[]) 
{    
    SDL_Init(SDL_INIT_EVERYTHING);

    Game *game = new Game();
    game->execGame();
   
    return 0;
}