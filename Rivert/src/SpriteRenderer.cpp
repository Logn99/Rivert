#include"SpriteRenderer.h"
#include"GameObject.h"
#include <iostream>
#include"Transform.h"

SpriteRenderer::SpriteRenderer(GameObject* parent,std::string id,int width, int height){
    m_spriteId = id;
    m_spriteWidth = width;
    m_spriteHeight = height;
    m_parent = parent;

    
    
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
     
        TextureManager::getInstance()->draw(m_spriteId,t->m_position.getX(),t->m_position.getY(),m_spriteWidth,m_spriteHeight,Window::getInstance()->getRenderer());
}


