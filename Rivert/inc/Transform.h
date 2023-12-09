#pragma once

#include"Rivert.h"
#include"Vector2D.h"
#include"Component.h"

class Transform:public Component{

public:

    Transform(GameObject* parent){
        m_position = Vector2D();
        m_parent = parent;
    }
    void init() {}
    void update() {}
    void clean() {}

    void setPosition(float x, float y){
        m_position.m_x = x;
        m_position.m_y = y;
    }
    Vector2D m_position;


    private:
    int type = Rivert::TRANSFORM;

};