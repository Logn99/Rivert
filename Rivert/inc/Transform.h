#pragma once

#include"Rivert.h"
#include"Vector2D.h"
#include"Component.h"

class Transform:public Component{

public:

    Transform(GameObject* parent){
        type = Rivert::TRANSFORM;
        m_parent = parent;
        m_position = Vector2D(0,0);
    }
    void init(){}
    void update() {}
    void clean() {}

    void setPosition(float x, float y){
        m_position.setX(x);
        m_position.setY(y);
    }

    void setPosition(Vector2D v){
        m_position.setX(v.getX());
        m_position.setY(v.getY());
    }

    float getPositionX(){
        return m_position.getX();
    }
    
    float getPositionY(){
        return m_position.getY();
    }

    private:
    
    Vector2D m_position;

};