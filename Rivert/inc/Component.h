#pragma once

class GameObject;

class Component{
public:
    virtual void init() {}
    virtual void update() {}
    virtual void clean() {}
    virtual int getType() {
        return type;
    }
protected:
    GameObject* m_parent;
    int type;
};

