#pragma once

#include<map>

#include"ScriptSystem.h"
#include"RenderSystem.h"
#include"Entity.h"
#include"Component.h"


class ECS{
public:

void init();

void update();

void draw();

// Entity
void createEntity(int entityId);
void addEntity(Entity* entity);

Entity* getEntity(int entityId);

void deleteEntity();

// Components

void addTransform(int entityId);

void addSpriteRenderer(int entityId, std::string textureId,int layer);
// Systems
void addScript(int entityId,ScriptObject* script);


private:

   std::map<int,Entity*> m_entities;

   RenderSystem* renderSystem; 
   ScriptSystem* scriptSystem;
};