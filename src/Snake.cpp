#include "../includes.h"
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
}

void Snake::update(uint32_t delta_time, Food &food, bool &running, SDL_Renderer* renderer)
{
    this->accumulator += delta_time;
    // atualiza velocidade do jogo
    if (this->accumulator > (90 - (this->tail_length / 2))) { 
        this->accumulator = 0;

        this->tail[this->tail_end % this->tail_max] = this->position;

        this->tail_start++;
        this->tail_end++;         

        this->position.x += this->velocity.x;
        this->position.y += this->velocity.y;
        // verifica se bater nas bordas, finaliza o jogo
        if (this->position.x < 0 || this->position.y < 0 || this->position.x >= 50 || this->position.y >= 50) {
            this->emitSoundWav("./sounds/game-over.wav");
            running = false;
        }
        // movimenta a fruta na tela
        if (this->position.x == food.x && this->position.y == food.y) {
            this->tail_length += 1;
            this->tail_start -= 1;
            this->emitSoundWav("./sounds/eat-fruit.wav");
            food.move();        
        }

        for (int i = 0; i < this->tail_length; i++) {
            Dimension& tail_pos = this->tail[(this->tail_start + i) % this->tail_max];
            if (tail_pos.x == this->position.x && tail_pos.y == this->position.y) {
                this->tail_length = 0;
                this->tail_start = this->tail_end;

                if (tail_pos.x > 0) {           
                    running = false;
                }
            }
        }
    }
}

bool Snake::isPositionValid(Snake &snake, Food &food)
{
    if (this->tail_length > 0) {
       return true;
    }
    return false;
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
