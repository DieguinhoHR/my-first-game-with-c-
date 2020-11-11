#ifndef SNAKE_H
#define SNAKE_H
#include <SDL2/SDL.h>

#include "../headers/Dimension.h"
#include "../headers/Food.h"

class Snake {
    public:
        Dimension position;
        Dimension acc;
        Dimension velocity;
        Dimension tail[255];
        int tail_max = 255;        
        int tail_start;
        int tail_end;
        int tail_length = 20;
        uint32_t accumulator;

        void emitSoundWav(const char* file);
        void update(uint32_t delta_time, Food &food, bool &running, Snake* snake);
        void draw(SDL_Renderer* renderer, Snake *snake);
};

#endif