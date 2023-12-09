#include "Rivert.h"



Uint32 Rivert::getTicks(){
    return SDL_GetTicks();
}

void Rivert::delay(int time){
    SDL_Delay(time);
}