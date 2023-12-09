#include "Game.h"
#include "InputHandler.h"


Game::Game(){

}

void Game::init(){

    m_bRunning = Window::getInstance()->init("Test Window", 100, 100, 640, 480, false);
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

}

void Game::draw(){

}

void Game::clean(){
    Window::getInstance()->clean();
}   

 