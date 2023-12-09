#pragma once

#include "SDL2/SDL.h"

namespace Rivert{

Uint32 getTicks();

void delay(int time);

enum rivert {
    SPRITE_RENDERER = 0,
    TRANSFORM = 0
};

}