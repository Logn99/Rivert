#pragma once

#include<SDL2/SDL.h>
#include<string>
#include<vector>
#include"Component.h"
#include"Rivert.h"



class GameObject{
public:
    GameObject();
    ~GameObject(){}
    void init();
    void draw();
    void update();
    void clean();

    void addComponent(Component* component);

    Component* getComponent(int type);
    

private:
    std::vector<Component*> m_components;
};

