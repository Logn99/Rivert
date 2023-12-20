#pragma once

#include"Component.h"

class ScriptSystem{

public:
    ScriptSystem(){}

    void update();

    void registerComponent(ScriptObject* script);

    void removeComponent(int entityId);

    private:
    std::vector<ScriptObject*> m_scripts;

    


};