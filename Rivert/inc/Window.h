#pragma once

#include<SDL2/SDL.h>

class Window{

public:
    static Window* getInstance()
    {
        if(s_pInstance == 0)
        {
            s_pInstance = new Window();
            return s_pInstance;
        }
        return s_pInstance;
    }

    void operator=(const Window &) = delete;

    bool init(const char* title, int xpos, int ypos, int width,int height, bool fullscreen);

    void clearWindow(){ SDL_RenderClear(m_pRenderer); }

    void presentWindow(){ SDL_RenderPresent(m_pRenderer); }

    void clean();

    SDL_Renderer* getRenderer() const {return m_pRenderer; }

private:

    //Constructor
    Window(){}

    // SDL
    SDL_Window* m_pWindow;
    SDL_Renderer* m_pRenderer;

   
    static Window* s_pInstance;


};

