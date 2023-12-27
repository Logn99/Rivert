
#include "Game.h"

Game::Game(){

}

void Game::init(){
    m_bRunning = Window::getInstance()->init("Test Window", 100, 100, 1150, 720, false);
    TextureManager::getInstance()->load("build/assets/rect.png", "rect", Window::getInstance()->getRenderer());
    TextureManager::getInstance()->load("build/assets/player-idle-1.png", "player", Window::getInstance()->getRenderer());
    TextureManager::getInstance()->load("build/assets/back.png", "background", Window::getInstance()->getRenderer());
    TextureManager::getInstance()->load("build/assets/tileset.png", "tileset", Window::getInstance()->getRenderer());
    TextureManager::getInstance()->load("build/assets/player.png", "player_sheet", Window::getInstance()->getRenderer());
    
    // Tmp --------------------------------------------------------------------------------
    
    ecs = new ECS();
    ecs->init();
    ecs->createEntity("Player");
    int entityId = ecs->getId("Player");
    ecs->addTransform(entityId);
    ecs->addSpriteRenderer(entityId,"player_sheet",2);
    ecs->addAnimator(entityId,new Animator());
    ecs->addScript(entityId,new PlayerController(ecs));

    ecs->createEntity("Background");
    entityId = ecs->getId("Background");
    ecs->addTransform(entityId);
    ecs->addSpriteRenderer(entityId,"background",0);

    //ecs->createEntity("Tilemap");
    //ecs->addTransform(3);
    //ecs->addScript(3,new TileMap(ecs,"tileset"));
    
}  

void Game::start(){
    Uint32 frameStart,frameTime;
    while(m_bRunning){
        frameStart = Rivert::getTicks();
        handleEvents();
        update();
        draw();
        frameTime = Rivert::getTicks()-frameStart;
        if(frameTime < DELAY_TIME){
           Rivert::delay(DELAY_TIME-frameTime);
        }
    }

    clean();
}

void Game::handleEvents(){
    InputHandler::getInstance()->update();
    if(InputHandler::getInstance()->getQuitEvent()){
        m_bRunning = false;
    }
}

void Game::update(){
    //Game Update Loop
    ecs->update();
}

void Game::draw(){
    Window::getInstance()->clearWindow();
    //Update Renderer
    ecs->draw();
    Window::getInstance()->presentWindow();
}

void Game::clean(){
    Window::getInstance()->clean();
}   

 