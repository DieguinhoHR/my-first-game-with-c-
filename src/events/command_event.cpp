#include <SDL2/SDL.h>

Snake snakeMove(bool &running, Snake &snake)
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
                    snake.vy = -1;
                    snake.vx = 0;
                break;
                case SDLK_DOWN:
                    snake.vy = 1;
                    snake.vx = 0;
                break;
                case SDLK_RIGHT:
                    snake.vy = 0;
                    snake.vx = 1;
                break;   
                case SDLK_LEFT:
                    snake.vy = 0;
                    snake.vx = -1;
                break;   
            }
        }
    }
    return snake;
}