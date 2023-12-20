#include"ECS.h"

void ECS::init(){
    // Create all systems
    // Rendersystem
    renderSystem = new RenderSystem();
    renderSystem->setRenderer(Window::getInstance()->getRenderer());
    // Scriptsystem
    scriptSystem = new ScriptSystem(); 
    // Animationsystem

    // Collisionsystem

    // etc.
}

void ECS::update(){
    scriptSystem->update();
}

void ECS::draw(){
    renderSystem->Update();
}

void ECS::createEntity(int entityId){
    m_entities[entityId] = new Entity(entityId);
}

void ECS::addEntity(Entity* entity){
    m_entities[entity->m_entityId] = entity;
}

Entity* ECS::getEntity(int entityId){
    return m_entities[entityId];
}

// Components

void ECS::addTransform(int entityId){
    m_entities[entityId]->m_components.push_back(new Transform());
    m_entities[entityId]->getComponent<Transform>()->entityId = entityId;
}

void ECS::addSpriteRenderer(int entityId, std::string textureId,int layer){
    m_entities[entityId]->m_components.push_back(new SpriteRenderer());
    m_entities[entityId]->getComponent<SpriteRenderer>()->entityId = entityId;
    m_entities[entityId]->getComponent<SpriteRenderer>()->textureId = textureId;
    m_entities[entityId]->getComponent<SpriteRenderer>()->layer = layer;
    int w,h;
    SDL_QueryTexture(TextureManager::getInstance()->m_textureMap[textureId],NULL,NULL,&w,&h);
    m_entities[entityId]->getComponent<SpriteRenderer>()->srcRect.h = h;
    m_entities[entityId]->getComponent<SpriteRenderer>()->srcRect.w = w;
    renderSystem->registerComponent(m_entities[entityId]->getComponent<SpriteRenderer>(),
                                    m_entities[entityId]->getComponent<Transform>());
}



void ECS::addScript(int entityId,ScriptObject* script){
    script->setEntity(m_entities[entityId]);
    script->init();
    scriptSystem->registerComponent(script);
}




