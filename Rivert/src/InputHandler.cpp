#include"InputHandler.h"


InputHandler* InputHandler::s_pInstance = 0;

void InputHandler::update() {
    SDL_Event event;
   
    while (SDL_PollEvent(&event)) {

        switch (event.type) {
            case SDL_QUIT:
               
                quitEvent = true;
                break;
            default:
                break;
        }
    }
}