#include"ECS.h"


void ECS::init(){
    // Create all systems
    // Rendersystem
    renderSystem = new RenderSystem();
    renderSystem->setRenderer(Window::getInstance()->getRenderer());
    createCamera();
    renderSystem->setCamera(getEntity(0));
    // Scriptsystem
    
    animationSystem = new AnimationSystem();
    scriptSystem = new ScriptSystem(); 
    
    // Collisionsystem

    // etc.
}

void ECS::update(){
    scriptSystem->update();
    animationSystem->update();
}

void ECS::draw(){
    renderSystem->Update();
}

void ECS::createEntity(std::string name){
    if(m_stringMap.count(name)!= 0){
        std::cout << "Try to add entity but name already exists" << std::endl;
        return;
    }
    
    int id = getNewId();
    m_entities[id] = new Entity(id,name,this);
    m_entities[id]->init();
   

    m_stringMap[name] = id;
}

void ECS::createCamera(){
    createEntity("Camera");
    int id = getId("camera");
    addTransform(id);
}

void ECS::addEntity(Entity* entity){
    m_entities[entity->m_entityId] = entity;
}

Entity* ECS::getEntity(int entityId){
    return m_entities[entityId];
}

Entity* ECS::getEntity(std::string name){
    return m_entities[m_stringMap[name]];
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

void ECS::addAnimator(int entityId, Animator* animator){
    
    m_entities[entityId]->m_components.push_back(animator);
    
    animationSystem->registerComponent(animator,m_entities[entityId]->getComponent<SpriteRenderer>());
}



void ECS::addScript(int entityId,ScriptObject* script){
    script->setEntity(m_entities[entityId]);
    script->init();
    scriptSystem->registerComponent(script);
}




