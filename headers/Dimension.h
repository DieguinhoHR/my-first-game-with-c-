#ifndef DIMENSION_H
#define DIMENSION_H
#include <SDL2/SDL.h>

class Dimension 
{
	public:
		int x, y;			
};

Dimension operator+ (const Dimension& a, const Dimension& b);
void operator+= (Dimension& a, const Dimension& b);	

#endif

