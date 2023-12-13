#include "TextureManager.h"
#include <iostream>
#include <algorithm>
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

void TextureManager::addDraw(std::string id, 
                             int x, 
                             int y, 
                             int width, 
                             int height, 
                             SDL_Renderer* pRenderer, 
                             int layer, 
                             int row,
                             int column,
                             SDL_RendererFlip flip)
    {
    m_drawQueue.push(Drawable(id,x,y,width,height,pRenderer,layer,row,column,flip));  
}
    
void TextureManager::update(){
    draw();
}

void TextureManager::draw(){
 
    std::vector<Drawable> drawableVector;

    while (!m_drawQueue.empty()) {
        // Move the front element from the queue to the vector
        drawableVector.push_back(std::move(m_drawQueue.front()));
        // Remove the element from the queue
        m_drawQueue.pop();
    }

    std::sort(drawableVector.begin(), drawableVector.end(),
              [](const Drawable& a, const Drawable& b) {
                  return a.m_layer < b.m_layer;
              });

    for (const Drawable& d : drawableVector) {
        int scale = 3;
        SDL_Rect srcRect;
        SDL_Rect destRect;

        
        srcRect.x =  d.m_width * d.m_column ;
        srcRect.y =  d.m_height * d.m_row ;
        destRect.x = d.m_x*scale;
        destRect.y = d.m_y*scale;
        srcRect.w  = d.m_width;
        srcRect.h  = d.m_height;
        destRect.w = d.m_width*scale;
        destRect.h = d.m_height*scale;
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