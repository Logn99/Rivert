#pragma once

#include<vector>

#include "SDL2/SDL.h"

class InputHandler{

public:

    static InputHandler* getInstance(){
        if(s_pInstance == 0){
            s_pInstance = new InputHandler();
        }
        return s_pInstance;
    }

    void operator=(const InputHandler &) = delete;

    void update();
    void clean();
    bool getQuitEvent(){return quitEvent;}

private:

    InputHandler(){
        quitEvent = false;
         
    }
    ~InputHandler() {}

    bool quitEvent;

    static InputHandler* s_pInstance;
};

