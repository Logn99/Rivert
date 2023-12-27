#pragma once

#include<map>

#include"ScriptSystem.h"
#include"RenderSystem.h"
#include"AnimationSystem.h"
#include"Entity.h"
#include"Component.h"


class ECS{
public:

void init();

void update();

void draw();

// Entity
void createEntity(std::string name);
void createCamera();
void addEntity(Entity* entity);

Entity* getEntity(int entityId);

void deleteEntity();

// Components

void addTransform(int entityId);

void addSpriteRenderer(int entityId, std::string textureId,int layer);
// Systems
void addScript(int entityId,ScriptObject* script);

void addAnimator(int entityId, Animator* animator);

int getId(std::string name){
   return m_stringMap[name];
}
Entity* getEntity(std::string name);

int getNewId(){
   int currentCount = m_entitieCount;
   m_entitieCount++;
   return currentCount;
}

private:

   std::map<int,Entity*> m_entities;
   std::map<std::string,int> m_stringMap;

   RenderSystem* renderSystem; 
   ScriptSystem* scriptSystem;
   AnimationSystem* animationSystem;

   int m_entitieCount = 0;
};