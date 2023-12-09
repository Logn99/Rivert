#include"Window.h"


Window* Window::s_pInstance = 0;

bool Window::init(const char* title, int xpos, int ypos, int width,int height, bool fullscreen){
    
    int flags = 0;
    if(fullscreen){
        flags = SDL_WINDOW_FULLSCREEN;
    }
// attempt to initialize SDL
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0){
        m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if(m_pWindow != 0){
            m_pRenderer = SDL_CreateRenderer(m_pWindow, -1,
                                             0);
            if(m_pRenderer != 0){
                SDL_SetRenderDrawColor(m_pRenderer, 255,255,255,255);
            }
            else{
                return false;
              
            }
        }
        else{
            return false;
            
        }
    }
    else{
        return false; // SDL init fail
        
    }
    return true; // everything inited successfully,
}


void Window::clean(){
    SDL_DestroyWindow(m_pWindow);
    SDL_DestroyRenderer(m_pRenderer);
    SDL_Quit();
}
