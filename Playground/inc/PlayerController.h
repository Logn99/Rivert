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
            

            idleAnimation = new Animation();
            idleAnimation->animationId = "idle";
            idleAnimation->frameTime = 100;
            idleAnimation->maxFrame = 3;
            idleAnimation->row = 0;
            idleAnimation->spriteHeight = 33;
            idleAnimation->spriteWidth = 33;

            runAnimation = new Animation();
            runAnimation->animationId = "run";
            runAnimation->frameTime = 100;
            runAnimation->maxFrame = 5;
            runAnimation->row = 1;
            runAnimation->spriteHeight= 33;
            runAnimation->spriteWidth = 33;

            animator = m_entity->getComponent<Animator>();
            animator->animations[runAnimation->animationId] = runAnimation;
            animator->animations[idleAnimation->animationId] = idleAnimation;
            animator->currentAnimation = idleAnimation->animationId;


        }

        void update(){
            animator->currentAnimation = idleAnimation->animationId;
            vel->setX(0);
            vel->setY(0);
            if(InputHandler::getInstance()->isKeyDown(SDL_SCANCODE_D)){
                vel->setX(1);
                spriteRenderer->flip = SDL_FLIP_NONE;
                animator->currentAnimation = runAnimation->animationId;
            }
            if(InputHandler::getInstance()->isKeyDown(SDL_SCANCODE_A)){
                vel->setX(-1);
                spriteRenderer->flip = SDL_FLIP_HORIZONTAL;
                animator->currentAnimation = runAnimation->animationId;
            }
            if(InputHandler::getInstance()->isKeyDown(SDL_SCANCODE_W)){
                vel->setY(-1);
                animator->currentAnimation = runAnimation->animationId;
            }
            if(InputHandler::getInstance()->isKeyDown(SDL_SCANCODE_S)){
               vel->setY(1);
               animator->currentAnimation = runAnimation->animationId;
            }
            transform->position =transform->position + *vel*2;
        }

private:    
    Transform* transform;
    SpriteRenderer* spriteRenderer;
    Animator* animator;
    Animation* runAnimation;
    Animation* idleAnimation;
    Vector2D* vel;
    ECS* m_ecs;
};