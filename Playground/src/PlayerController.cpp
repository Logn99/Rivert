#include"PlayerController.h"
#include<iostream>
#include<Rivert.h>
void PlayerController::init(){
    
    m_position = static_cast<Transform*>(m_parent->getComponent(Rivert::TRANSFORM));
    m_position->setPosition(10.0f,10.0f);
    x = 10;
}

void PlayerController::update(){
    if(InputHandler::getInstance()->isKeyDown(SDL_SCANCODE_A)){
        x--;
   }

   if(InputHandler::getInstance()->isKeyDown(SDL_SCANCODE_D)){
        x++;
   }

   m_position->setPosition(x,10);
}