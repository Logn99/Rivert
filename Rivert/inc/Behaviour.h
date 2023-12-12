#include"Component.h"
#include"Rivert.h"
#include"GameObject.h"
class Behaviour: public Component{

public:

    Behaviour(GameObject* parent){
        m_parent = parent;
    }
    virtual void init() {}
    virtual void update() {}


protected:
    GameObject* m_parent;
    int type = Rivert::BEHAVIOUR;
};