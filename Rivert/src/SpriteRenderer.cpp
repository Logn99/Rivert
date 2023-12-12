#include"SpriteRenderer.h"
#include"GameObject.h"
#include <iostream>
#include"Transform.h"

SpriteRenderer::SpriteRenderer(GameObject* parent,std::string id,int width, int height){
    m_spriteId = id;
    m_spriteWidth = width;
    m_spriteHeight = height;
    m_parent = parent;
    type = Rivert::SPRITE_RENDERER;

    
    
}


void SpriteRenderer::setSprite(std::string id,int width, int height){
    m_spriteId = id;
    m_spriteWidth = width;
    m_spriteHeight = height;
    }

void SpriteRenderer::init(){

}

void SpriteRenderer::clean(){

}

void SpriteRenderer::update(){ 
    
        Transform* t = (Transform*)m_parent->getComponent(Rivert::TRANSFORM);
        

        TextureManager::getInstance()->addDraw(m_spriteId,t->getPositionX(),t->getPositionY(),m_spriteWidth,m_spriteHeight,Window::getInstance()->getRenderer());
}


