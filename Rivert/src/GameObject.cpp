
#include"GameObject.h"
#include"SpriteRenderer.h"
#include"Transform.h"
#include<iostream>

GameObject::GameObject(){
    this->addComponent(new Transform(this));
}

void GameObject::init(){
    for(std::vector<Component*>::size_type i = 0; i!= m_components.size();i++){
        m_components[i]->init();
    }
}
void GameObject::draw(){
    
}
void GameObject::update(){

    for(std::vector<Component*>::size_type i = 0; i!= m_components.size();i++){
                m_components[i]->update();
            }
}

void GameObject::clean(){

}
void GameObject::addComponent(Component* component){
        
    m_components.push_back(component);
    
}


Component* GameObject::getComponent(int type){
    if(m_components.size() != 0){
        for(std::vector<Component*>::size_type i = 0; i!= m_components.size();i++){
            if(m_components[i]->getType() == type){
                return m_components[i];
            }
        }
    }
    std::cout << type << std::endl;
    
}