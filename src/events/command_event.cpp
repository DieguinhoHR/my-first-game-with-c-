#include <SDL2/SDL.h>

Snake snakeMove(bool &running, Snake snake)
{
    // process entries
    SDL_Event event;

    while(SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            running = false;
        } else if (event.type == SDL_KEYDOWN) {
            switch (event.key.keysym.sym) {
                case SDLK_ESCAPE:
                    running = false;
                break;
                case SDLK_UP:
                    if (snake.velocity.y != 1) {
                        snake.velocity.y = -1;
                        snake.velocity.x = 0;
                    }
                break;
                case SDLK_DOWN:
                    if (snake.velocity.y != -1) {
                        snake.velocity.y = 1;
                        snake.velocity.x = 0;
                    }
                break;
                case SDLK_RIGHT:
                    if (snake.velocity.x != -1) {
                        snake.velocity.y = 0;
                        snake.velocity.x = 1;
                    }
                break;   
                case SDLK_LEFT:
                    if (snake.velocity.x != 1) {
                        snake.velocity.y = 0;
                        snake.velocity.x = -1;
                    }
                break;   
            }
        }
    }
    return snake;
}