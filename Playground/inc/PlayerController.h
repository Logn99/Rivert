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

            int cameraId = m_ecs->getId("camera");
            cameraTransform = m_ecs->getEntity(cameraId)->getComponent<Transform>();
        }

        void update(){
            animator->currentAnimation = idleAnimation->animationId;
            vel->setX(0);
            vel->setY(2);
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
            cameraTransform->position.setX(cameraTransform->position.getX() + vel->getX()*2);
            if(transform->position.getY()> 208-32){
                transform->position.setY(208-32);
            }
        }

private:    
    // Components
    Transform* transform;
    Transform* cameraTransform;
    SpriteRenderer* spriteRenderer;
    Animator* animator;

    // Animations
    Animation* runAnimation;
    Animation* idleAnimation;

    // ECS
    ECS* m_ecs;

    // Script Variables
    Vector2D* vel;

    // 208
    
};