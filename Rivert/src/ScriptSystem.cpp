#include"ScriptSystem.h"


void ScriptSystem::update(){
    for (size_t i = 0; i < m_scripts.size(); ++i) {

        m_scripts[i]->update();
    }
}

void ScriptSystem::registerComponent(ScriptObject* script){
    m_scripts.push_back(script);
}

void ScriptSystem::removeComponent(int entityId){
    
}