#include<string>
#include<vector>
#include<iostream>
#include<fstream>
#include "GameObject.h"
#include"Transform.h"
#include"Vector2D.h"
#include"SpriteRenderer.h"


class Tile:GameObject{
public:
    Tile(std::string tag,Vector2D pos):GameObject(tag){
        this->addComponent(new SpriteRenderer(this,"tilemap",32,32,1));
        static_cast<Transform*>(this->getComponent(Rivert::TRANSFORM))->setPosition(pos);
    };
    
    void init();
    void update(); 
    void clean();
private:
    
};

class TileMap{
public:

    TileMap(int cellWidth,int cellHeight,int layer);


    void loadMap(std::string filePath);

    void cleanMap();
    void update();
    void drawMap();
    void drawTile(int xPos, int yPos, int type);
private:
    std::vector<int> m_map;
    int m_mapHeight;
    int m_mapWidth;
    int m_cellHeight;
    int m_cellWidth;
    int m_layer;
    
};