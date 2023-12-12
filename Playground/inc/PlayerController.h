#include<Behaviour.h>
#include<InputHandler.h>
#include<Transform.h>
class PlayerController : public Behaviour{

public:

    PlayerController(GameObject* parent):Behaviour(parent){}
    void init();
    void update();

private:
    Transform* m_position;
    int x;


};