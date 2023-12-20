#pragma once
#include"Rivert.h"

#include<iostream>
class PlayerController : public ScriptObject{
    public:
        PlayerController(ECS* ecs){ m_ecs =ecs; }

        void init(){
            
            transform = m_entity->getComponent<Transform>();
            spriteRenderer = m_entity->getComponent<SpriteRenderer>();
            vel = new Vector2D();
        }

        void update(){
            if(InputHandler::getInstance()->isKeyDown(SDL_SCANCODE_D)){
                vel->setX(1);
            }else{
                vel->setX(0);
            }
            if(InputHandler::getInstance()->isKeyDown(SDL_SCANCODE_A)){
                transform->scale.setX(1);
            }
            if(InputHandler::getInstance()->isKeyDown(SDL_SCANCODE_W)){
                transform->scale.setY(5);
            }
            if(InputHandler::getInstance()->isKeyDown(SDL_SCANCODE_S)){
                transform->scale.setY(1);
            }

            transform->position =transform->position + *vel;
        }

private:    
    Transform* transform;
    SpriteRenderer* spriteRenderer;
    Vector2D* vel;
    ECS* m_ecs;
};