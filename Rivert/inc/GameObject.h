#pragma once

#include<SDL2/SDL.h>
#include<string>
#include<vector>
#include"Component.h"
#include"Rivert.h"
#include"Transform.h"


class GameObject{
public:
    GameObject(std::string tag);
    ~GameObject(){}
    void init();
    void draw();
    void update();
    void clean();

    std::string getTag(){
        return m_tag;
    }
    void addComponent(Component* component);

    Component* getComponent(int type);
    

private:
    std::vector<Component*> m_components;
    std::string m_tag;
};

