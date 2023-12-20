#pragma once

#include<string>
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<map>
#include<queue>

#include"Window.h"
#include"Vector2D.h"
class Drawable{
public:

    Drawable(std::string id, 
             int x, 
             int y, 
             int width, 
             int height, 
             int objectWidth,
             int objectHeight,
             SDL_Renderer* pRenderer, 
             int layer,
             int row,
             int column,
             SDL_RendererFlip flip = SDL_FLIP_NONE){
        m_id = id;
        m_x = x;
        m_y = y;
        m_spriteWidth = width;
        m_spriteHeight = height;
        m_pRenderer = pRenderer;
        m_layer = layer;
        m_row = row;
        m_column = column;
        m_flip = flip;
        m_objectWidth = objectWidth;
        m_objectHeight = objectHeight;


    }


    std::string m_id;
    int m_x;
    int m_y;
    int m_spriteWidth;
    int m_spriteHeight;
    int m_layer;
    int m_row;
    int m_column;
    int m_objectWidth;
    int m_objectHeight;
    SDL_Renderer* m_pRenderer;
    SDL_RendererFlip m_flip;

};
class TextureManager{

public:

    static TextureManager* getInstance()
    {
        if(s_pInstance == 0)
        {
            s_pInstance = new TextureManager();
            return s_pInstance;
        }
        return s_pInstance;
    }


    bool load(std::string fileName, std::string id, SDL_Renderer* pRenderer);

    void debugDraw();

    void addDraw(std::string id, 
                 int x, int y, int width, int height, int objectWidth, int objectHeight,
                 SDL_Renderer* pRenderer,
                 int layer,int row,int column, 
                 SDL_RendererFlip flip = SDL_FLIP_NONE);
    
    void addDebugDraw(SDL_Rect rect);

    void update();
    
    SDL_Texture* getTexture(std::string id){
        return m_textureMap[id];
    }

    std::map<std::string, SDL_Texture*> m_textureMap;
    

private:
    TextureManager() {scale = 3;}

    std::queue<Drawable> m_drawQueue;
    std::queue<SDL_Rect> m_debugQueue;

    int scale;
    void draw();

    void drawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

    static TextureManager* s_pInstance;

};




