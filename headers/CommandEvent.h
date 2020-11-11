#ifndef COMMAND_EVENT_H
#define COMMAND_EVENT_H

#include <SDL2/SDL.h>
#include "../headers/Dimension.h"
#include "../headers/Snake.h"

class CommandEvent
{
    public:    
        void snakeMove(bool &running, Snake &snake);
};

#endif
