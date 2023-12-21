#include"Rivert.h"

#include<iostream>
#include<vector>
// Temporary
class TileMap : public ScriptObject{
public:
    TileMap(ECS* ecs,std::string textureId){ 
        m_ecs =ecs;
        m_textureId = textureId;
    }

    void init(){
        createTileMap();
    }

    void update(){
        
    }

    void createTileMap(){
        for(int i = 0; i < 24; i++){
            
            m_ecs->createEntity(i+5);
            m_ecs->addTransform(i+5);
            m_ecs->addSpriteRenderer(i+5,m_textureId,1);

            Transform* t = m_ecs->getEntity(i+5)->getComponent<Transform>();
            t->position.setX(i*16);
            t->position.setY(16*13);

            SpriteRenderer* sP = m_ecs->getEntity(i+5)->getComponent<SpriteRenderer>();
            sP->srcRect.x = 48;
            sP->srcRect.y = 16;
            sP->srcRect.h = 16;
            sP->srcRect.w = 16;
        } 

        for(int i = 0; i < 24; i++){
            
            m_ecs->createEntity(i+5+24);
            m_ecs->addTransform(i+5+24);
            m_ecs->addSpriteRenderer(i+5+24,m_textureId,1);

            Transform* t = m_ecs->getEntity(i+5+24)->getComponent<Transform>();
            t->position.setX(i*16);
            t->position.setY(16*14);

            SpriteRenderer* sP = m_ecs->getEntity(i+5+24)->getComponent<SpriteRenderer>();
            sP->srcRect.x = 48;
            sP->srcRect.y = 48;
            sP->srcRect.h = 16;
            sP->srcRect.w = 16;
        }   

    }

private:
    std::vector<SpriteRenderer*> tileMap;
    
    std::string m_textureId;
    ECS* m_ecs;
};