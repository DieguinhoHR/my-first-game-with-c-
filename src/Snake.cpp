#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

#include "../headers/Food.h"
#include "../headers/Snake.h"
#include "../headers/Dimension.h"

#include <cstdlib>

void Snake::emitSoundWav(const char* file)
{                
    SDL_AudioSpec want, have;
    SDL_memset(&want, 0, sizeof(want));
    want.freq = 44100; // mais usado pra jogo
    want.format = AUDIO_S16SYS; // formato de audio
    want.channels = 1; // 1 mono ou 2 stereo
    want.samples = 8192;
    auto audio = SDL_OpenAudioDevice(nullptr, false, &want, &have, 0);

    Uint8 *buf; // armazena trecho de áudio
    Uint32 len;

    SDL_LoadWAV(file, &have, &buf, &len);
    SDL_QueueAudio(audio, buf, len);
    SDL_FreeWAV(buf);
    SDL_PauseAudioDevice(audio, false);

    // if (isDelay) {
    //     while (SDL_GetQueuedAudioSize(audio) > 0) {
    //         SDL_Delay(100);
    //     }
    // }
}

void Snake::update(uint32_t delta_time, Food &food, bool &running, Snake* snake)
{
    snake->accumulator += delta_time;
    // atualiza velocidade do jogo
    if (snake->accumulator > (90 - (snake->tail_length / 2))) { 
        snake->accumulator = 0;

        snake->tail[snake->tail_end % snake->tail_max] = snake->position;

        snake->tail_start++;
        snake->tail_end++;         

        snake->position.x += snake->velocity.x;
        snake->position.y += snake->velocity.y;
        // verifica se bater nas bordas, finaliza o jogo
        if (snake->position.x < 0 || snake->position.y < 0 || snake->position.x >= 37 || snake->position.y >= 37) {
            snake->emitSoundWav("./sounds/game-over.wav");
            running = false;
        }
        // movimenta a fruta na tela
        if (snake->position.x == food.x && snake->position.y == food.y) {
            snake->tail_length += 1;
            snake->tail_start -= 1;
            snake->emitSoundWav("./sounds/eat-fruit.wav");
            food.move();
        }

        for (int i = 0; i < snake->tail_length; i++) {
            Dimension& tail_pos = snake->tail[(snake->tail_start + i) % snake->tail_max];
            if (tail_pos.x == snake->position.x && tail_pos.y == snake->position.y) {
                snake->tail_length = 0;
                snake->tail_start = snake->tail_end;

                if (tail_pos.x > 0) {           
                    running = false;
                }
            }
        }
    }
}

void Snake::draw(SDL_Renderer* renderer, Snake* snake)
{
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    for (int i = 0; i < this->tail_length; ++i) {
        Dimension &tail_pos = this->tail[(this->tail_start + i) % this->tail_max];

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_Rect r{ 16 * tail_pos.x, 16 * tail_pos.y, 16, 16 };        
        SDL_RenderFillRect(renderer, &r);
    }
    SDL_Rect r{ 16 * this->position.x, 16 * this->position.y, 16, 16 };        
    SDL_RenderFillRect(renderer, &r);
}
