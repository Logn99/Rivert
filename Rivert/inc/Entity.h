#pragma once
#include<vector>
#include<string>
#include<iostream>
#include<type_traits>
//#include"Component.h"
class Component;

class Entity {
    public:

    Entity(int entityId){
        m_entityId = entityId;
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
    std::vector<Component*> m_components;
};