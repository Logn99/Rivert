#include "TextureManager.h"
#include <iostream>
TextureManager* TextureManager::s_pInstance = 0;


bool TextureManager::load(std::string fileName, std::string id, SDL_Renderer* pRenderer){
    SDL_Surface* pTempSurface = IMG_Load(fileName.c_str());
    
    
    if(pTempSurface == 0){
        
        return false;
    }

    SDL_Texture* pTexture = SDL_CreateTextureFromSurface(pRenderer,pTempSurface);
    SDL_FreeSurface(pTempSurface);

    if(pTexture != 0){
        m_textureMap[id] = pTexture;
        return true;

    }

    return false;
}

void TextureManager::addDraw(std::string id, int x, int y, int width, int height, SDL_Renderer* pRenderer, SDL_RendererFlip flip){
    m_drawQueue.push(Drawable(id,x,y,width,height,pRenderer,flip));
    
}
    
void TextureManager::update(){
    draw();
}

void TextureManager::draw(){
    
    for (; !m_drawQueue.empty(); m_drawQueue.pop()){
        Drawable d = (Drawable)m_drawQueue.front();
    
    SDL_Rect srcRect;
    SDL_Rect destRect;

    srcRect.x = 0;
    srcRect.y = 0;
    destRect.x = d.m_x;
    destRect.y = d.m_y;
    srcRect.w = destRect.w = d.m_width*5;
    srcRect.h = destRect.h = d.m_height*5;
    
    SDL_RenderCopyEx(d.m_pRenderer, m_textureMap[d.m_id], &srcRect,
                     &destRect, 0, 0, d.m_flip);
    }   
}

void TextureManager::drawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* pRenderer, SDL_RendererFlip flip){
    SDL_Rect srcRect;
    SDL_Rect destRect;
    srcRect.x = width * currentFrame;
    srcRect.y = height * (currentRow - 1);
    srcRect.w = destRect.w = width;
    srcRect.h = destRect.h = height;
    destRect.x = x;
    destRect.y = y;
    SDL_RenderCopyEx(pRenderer, m_textureMap[id], &srcRect,
                     &destRect, 0, 0, flip);
}