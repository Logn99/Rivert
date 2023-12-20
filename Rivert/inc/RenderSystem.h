#pragma once
#include<vector>
#include<utility>
#include<SDL2/SDL.h>

#include"TextureManager.h"
#include"Component.h"
#include<algorithm>

class RenderSystem{

public:
    RenderSystem();

    void Update();

    void registerComponent(SpriteRenderer* spriteRenderer, Transform* transform);

    void removeComponent(int entityId);

    void setRenderer(SDL_Renderer* pRenderer){
        m_pRenderer = pRenderer;
    }

    
bool compareByLayer(const std::pair<SpriteRenderer*,Transform*>& a, const std::pair<SpriteRenderer*,Transform*>& b) {
        return a.first->layer < b.first->layer;
    }

    private:
    std::vector<std::pair<SpriteRenderer*,Transform*> > m_components;
    

    SDL_Renderer* m_pRenderer;
    int m_globalScale = 3;
    


};