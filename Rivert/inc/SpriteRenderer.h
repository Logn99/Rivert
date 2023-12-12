#pragma once

#include<string>
#include<SDL2/SDL.h>
#include<TextureManager.h>
#include<Window.h>
#include"Rivert.h"
#include"Component.h"


class SpriteRenderer: public Component{

public: 
    SpriteRenderer(GameObject* parent,std::string id,int width, int height);

    void setSprite(std::string id,int width, int height);

    void update();

    void init();

    void clean();
    
    void flipHorizontal(bool h_flip){
        if(h_flip){
            flip = SDL_FLIP_HORIZONTAL;
        }else{
            flip = SDL_FLIP_NONE;
        }
    }

private:

    std::string m_spriteId;
    int m_spriteWidth;
    int m_spriteHeight;
    SDL_RendererFlip flip;

};