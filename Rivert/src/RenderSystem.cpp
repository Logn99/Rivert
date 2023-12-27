#include"RenderSystem.h"
#include"Window.h"

#include<iostream>

RenderSystem::RenderSystem(){
   
}

void RenderSystem::Update(){
    for (size_t i = 0; i < m_components.size(); ++i) {
        
        // get components for calculation
        SpriteRenderer* spriteRenderer  = m_components[i].first;
        Transform* transform  = m_components[i].second;
        Transform* cameraTransform = m_camera->getComponent<Transform>();
        // calculate the destination redering
        SDL_Rect destRect;
        
        destRect.x = (transform->position.getX()-cameraTransform->position.getX())*m_globalScale;
        destRect.y = (transform->position.getY()-cameraTransform->position.getY())*m_globalScale;
        destRect.w = spriteRenderer->srcRect.w *m_globalScale* transform->scale.getX();
        destRect.h = spriteRenderer->srcRect.h *m_globalScale* transform->scale.getY();

        //std::cout << destRect.x << std::endl;
        // render copy
        SDL_RenderCopyEx(Window::getInstance()->getRenderer(), 
                         TextureManager::getInstance()->m_textureMap[spriteRenderer->textureId], 
                         &spriteRenderer->srcRect,
                         &destRect, 
                         0, // Rot
                         0, // Rot
                         spriteRenderer->flip);
    }
}

void RenderSystem::registerComponent(SpriteRenderer* spriteRenderer, Transform* transform){
    m_components.push_back(std::make_pair(spriteRenderer,transform));

    std::sort(m_components.begin(), m_components.end(), [this](const auto& a, const auto& b) {
            return compareByLayer(a, b);
    });
}

void RenderSystem::removeComponent(int entityId){

}



