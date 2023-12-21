#pragma once

#include<iostream>
#include<vector>
#include"Rivert.h"
#include"PlayerController.h"
#include"TileMap.h"
// Tmp
class Game
{
public:

    Game();
  
    void init();
    void start();
    void handleEvents();
    void update();
    void draw();
    void clean();
    bool running(){return m_bRunning;}

private:

    const int FPS = 60;
    const int DELAY_TIME = 1000.0f / FPS;

    bool m_bRunning;

    ECS* ecs;
};
typedef Game TheGame;


