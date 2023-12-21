#include"AnimationSystem.h"


void AnimationSystem::update(){

    for (size_t i = 0; i < m_components.size(); ++i) {
        // Get Animator
        Animator* animator = m_components[i].first;

        
        SpriteRenderer* spriteRenderer  = m_components[i].second;
        if(animator->animations.size() == 0){
            continue;
        }
        Animation* anim = animator->animations[animator->currentAnimation];

        anim->currentTime = SDL_GetTicks();

        if(anim->currentTime -anim->lastTime > anim->frameTime){
            
            anim->frame++;
            if(anim->frame > anim->maxFrame){
                
                anim->frame = 0;
            }
            anim->lastTime = anim->currentTime;
        }
        

        spriteRenderer->srcRect.x = anim->spriteWidth * anim->frame;
        spriteRenderer->srcRect.y = anim->spriteHeight * anim->row;
        spriteRenderer->srcRect.w = anim->spriteWidth;
        spriteRenderer->srcRect.h = anim->spriteHeight;
        
    }
}

void AnimationSystem::registerComponent(Animator* animator,SpriteRenderer* spriteRenderer){
    m_components.push_back(std::make_pair(animator,spriteRenderer));
}