#pragma once

#include<vector>
#include<string>
#include<Vector2D.h>
#include<SDL2/SDL.h>

#include"Entity.h"


struct Component{
    virtual ~Component() = default;  // Add a virtual destructor
};

struct Transform : Component{
    int      entityId;
    Vector2D position;
    Vector2D scale = Vector2D(1,1);
};

struct SpriteRenderer :Component{
    int              entityId;
    std::string      textureId = "rect";
    SDL_Rect         srcRect{0,0,225,255};
    SDL_RendererFlip flip = SDL_FLIP_NONE;
    int              layer = 0;
};





class ScriptObject{
public:
    ScriptObject(){}

    void setEntity(Entity* entity){
            m_entity = entity;
        }
    virtual void init(){}
    virtual void update(){}
protected:
    Entity* m_entity;
};

struct Script: Component{
    ScriptObject script;
};



	
