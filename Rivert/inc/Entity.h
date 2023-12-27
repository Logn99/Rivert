#pragma once
#include<vector>
#include<string>
#include<iostream>
#include<type_traits>

class ECS;
class Component;

class Entity {
    public:

    Entity(int entityId,std::string name,ECS* ecs){
        m_entityId = entityId;
        m_name = name;
    }

    void init(){

    }

    template<typename T>
    T* getComponent(){
        for (std::vector<Component*>::size_type i = 0; i < m_components.size(); i++) {
            // Use dynamic_cast to check if the current component is of type SpriteRenderer
            T* componentOfTypeT = dynamic_cast<T*>(m_components[i]);
            
            if (componentOfTypeT) {
                // If the cast is successful, return the component
                return componentOfTypeT;
            }
        }
        return nullptr;
    }

    int m_entityId;
    std::string m_name;
    ECS* m_ecs;
    std::vector<Component*> m_components;

};