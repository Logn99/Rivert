#include "Game.h"
#include "InputHandler.h"
#include "TextureManager.h"
#include "Rivert.h"
#include "Transform.h"
Game::Game(){

}

void Game::init(){
    m_bRunning = Window::getInstance()->init("Test Window", 100, 100, 640, 480, false);

    TextureManager::getInstance()->load("/home/michael/ownCloud - Michael Zimmerli (ost.ch)@drive.switch.ch/05_Development/CPP_Projects/Rivert_Engine/Playground/assets/rect.png", "rect", Window::getInstance()->getRenderer());
    // Tmp
    //sprite = new SpriteRenderer("rect", 225,225);
    
    gameObject = new GameObject();
   
    gameObject->addComponent(new SpriteRenderer(gameObject,"rect",225,225));
    Transform* t = (Transform*)gameObject->getComponent(Rivert::TRANSFORM);
    

    std::cout << t->m_position.getX() << std::endl;
    std::cout << t->m_position.getY() << std::endl;
    
    
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
   if(InputHandler::getInstance()->isKeyDown(SDL_SCANCODE_W)){
    std::cout << "W" << std::endl;
   }
}

void Game::draw(){
    Window::getInstance()->clearWindow();
    gameObject->update();
  
    Window::getInstance()->presentWindow();

}

void Game::clean(){
    Window::getInstance()->clean();
}   

 