#include <SDL2/SDL.h>
#include "food.cpp"
#include <cstdlib>

// Things to do:
//   * Make food not spawn in snake
//   * Keep track of score
//   * Walls? Multiple foods?
//   * difficulty curve
//   * Display for start game

struct Dimension {
	int x, y;
};

Dimension operator+ (const Dimension& a, const Dimension& b) {
	return Dimension{ a.x + b.x, a.y + b.y };
}

void operator+= (Dimension& a, const Dimension& b) {
	a.x += b.x;
	a.y += b.y;
}

const int tail_max = 255;

struct Snake {
    Dimension position;
    Dimension velocity;
    Dimension acc;

    Dimension tail[tail_max];
    int tail_start, tail_end;
    int tail_length = 20;

    uint32_t accumulator;

    void update(uint32_t delta_time, struct Food &food)
    {
        accumulator += delta_time;
        if (accumulator > (100 - (tail_length / 2))) { // atualiza velocidade do jogo
            accumulator = 0;

            tail[tail_end % tail_max] = position;

            tail_start++;
			tail_end++;

            position.x += velocity.x;
            position.y += velocity.y;
            // se sair da tela, volta novamente
            if (position.x < 0) position.x = 49;
            if (position.y < 0) position.y = 49;
            if (position.x >= 50) position.x = 0;
            if (position.y >= 50) position.y = 0;

            if (position.x == food.x && position.y == food.y) {
                tail_length += 1;
                tail_start -= 1;
                food.move();
            }

            for (int i = 0; i < tail_length; i++) {
				Dimension& tail_pos = tail[(tail_start + i) % tail_max];
				if (tail_pos.x == position.x && tail_pos.y == position.y) {
					tail_length = 0;
					tail_start = tail_end;
				}
			}
        }
    }

    void draw(SDL_Renderer* renderer)
    {
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

        for (int i = 0; i < tail_length; i++) {
            Dimension &tail_pos = tail[(tail_start + i) % tail_max];
            //_reactLoad(tail_pos, renderer);
            SDL_Rect r{ 16 * tail_pos.x, 16 * tail_pos.y, 16, 16 };        
             SDL_RenderFillRect(renderer, &r);
        }
        _reactLoad(position, renderer);
    }

    void _reactLoad(Dimension position, SDL_Renderer* renderer)
    {
        SDL_Rect r{ 16 * position.x, 16 * position.y, 16, 16 };        
        SDL_RenderFillRect(renderer, &r);
    }
};
