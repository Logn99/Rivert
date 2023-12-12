#include "Game.h"
#include "InputHandler.h"
#include "TextureManager.h"
#include "Rivert.h"
#include "Transform.h"
#include "PlayerController.h"


Game::Game(){

}

void Game::init(){
    m_bRunning = Window::getInstance()->init("Test Window", 100, 100, 1280, 720, false);

    TextureManager::getInstance()->load("build/assets/rect.png", "rect", Window::getInstance()->getRenderer());
    TextureManager::getInstance()->load("build/assets/player-idle-1.png", "player", Window::getInstance()->getRenderer());
    // Tmp
    //sprite = new SpriteRenderer("rect", 225,225);
    
    

    gameObject = new GameObject("Player");
    
    gameObject->addComponent(new SpriteRenderer(gameObject,"player",32,32));
    
    gameObject->addComponent(new PlayerController(gameObject));

    gameObject->init();
    

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
   
    gameObject->update();


    
}

void Game::draw(){
    Window::getInstance()->clearWindow();
    TextureManager::getInstance()->update();
  
    Window::getInstance()->presentWindow();

}

void Game::clean(){
    Window::getInstance()->clean();
}   

 