#pragma once
#include<map>

#include"Component.h"
class AnimationSystem{

public:
    AnimationSystem(){}

    void update();

    void registerComponent(Animator* animator,SpriteRenderer* spriteRenderer);


    private:
    std::vector<std::pair<Animator*,SpriteRenderer*> > m_components;
    
   
    



};