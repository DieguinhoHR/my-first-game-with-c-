#include <SDL2/SDL.h>
#include <cstdlib>

#include "../headers/Dimension.h"

Dimension operator+ (const Dimension& a, const Dimension& b) 
{
	return Dimension{ a.x + b.x, a.y + b.y };
}

void operator+= (Dimension& a, const Dimension& b) 
{
	a.x += b.x;
	a.y += b.y;
}
