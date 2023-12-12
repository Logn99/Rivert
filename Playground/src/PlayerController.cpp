#include"PlayerController.h"
#include<iostream>
#include<Rivert.h>
void PlayerController::init(){
    
    m_position = static_cast<Transform*>(m_parent->getComponent(Rivert::TRANSFORM));
    m_position->setPosition(10.0f,10.0f);

    m_spriteRenderer = static_cast<SpriteRenderer*>(m_parent->getComponent(Rivert::SPRITE_RENDERER));
    x = 10;
    y = 10;
    speed = 5;
}

void PlayerController::update(){
    if(InputHandler::getInstance()->isKeyDown(SDL_SCANCODE_A)){
        m_spriteRenderer->flipHorizontal(true);
        x -= speed;
   }

   if(InputHandler::getInstance()->isKeyDown(SDL_SCANCODE_D)){
         m_spriteRenderer->flipHorizontal(false);
        x += speed;
   }
    if(InputHandler::getInstance()->isKeyDown(SDL_SCANCODE_W)){
        y -= speed;
   }

   if(InputHandler::getInstance()->isKeyDown(SDL_SCANCODE_S)){
        y += speed;
   }
   m_position->setPosition(x,y);
}