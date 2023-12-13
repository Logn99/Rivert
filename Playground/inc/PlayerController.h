#include<Behaviour.h>
#include<InputHandler.h>
#include<Transform.h>
#include"SpriteRenderer.h"

class PlayerController : public Behaviour{

public:

    PlayerController(GameObject* parent):Behaviour(parent){}
    void init();
    void update();

private:
    Transform* m_position;
    SpriteRenderer* m_spriteRenderer;
    int x;
    int y;
    int speed;


};