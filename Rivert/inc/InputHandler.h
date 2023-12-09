#pragma once

#include<vector>
#include "SDL2/SDL.h"
#include"Vector2D.h"


enum mouse_buttons
{
    LEFT = 0,
    MIDDLE = 1,
    RIGHT = 2
};

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

    //Mouse
    bool getMouseButtonState(int buttonNumber) const;
    Vector2D* getMousePosition() const;

    //Keyboard
    bool isKeyDown(SDL_Scancode key) const;

private:

    InputHandler();
    ~InputHandler() {}

void onKeyDown();
    void onKeyUp();

    void onMouseMove(SDL_Event& event);
    void onMouseButtonDown(SDL_Event& event);
    void onMouseButtonUp(SDL_Event& event);

    // Mouse
    std::vector<bool> m_mouseButtonStates;
    Vector2D* m_mousePosition;


    // Keyboard
    const Uint8* m_keystates;



    bool quitEvent;

    static InputHandler* s_pInstance;
};

