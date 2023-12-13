#include"Tilemap.h"
#include"SpriteRenderer.h"



TileMap::TileMap(int cellWidth,int cellHeight,int layer){
    m_cellWidth = cellWidth;
    m_cellHeight = cellHeight;
    m_layer = layer;
}

void TileMap::loadMap(std::string filePath){ 
    char data;
    int cnt = 0;
    std::string tmp;

    std::ifstream file (filePath);
    if(file.is_open()){
        while ( file.good() ) {
            if(cnt == 0){
                std::getline(file,tmp);
                cnt++;
                std::cout<<tmp<< std::endl;
                m_mapHeight = std::stoi(tmp);
            }else if(cnt == 1){
                std::getline(file,tmp);
                m_mapWidth = std::stoi(tmp);
                cnt++;
            }else{
                data = file.get();
                if(data !='\n'){
                        m_map.push_back((int(data) - 48));
                    }
                }
            }
        }

}



void TileMap::update(){
    drawMap();
    
}

void TileMap::drawMap(){
                      
    int x_pos = 0;
    int y_pos = 0;
    int currentFrame = 0;

    for(std::vector<int*>::size_type i = 0; i!= m_map.size()-1;i++){
        
        if(currentFrame < m_mapWidth){
            drawTile(x_pos,y_pos,m_map[i]);
            x_pos += m_cellWidth;
            currentFrame++;    
        }else{
            currentFrame = 1; 
            x_pos = 0;
            y_pos += m_cellHeight;
            drawTile(x_pos,y_pos,m_map[i]);
            x_pos += m_cellWidth;
        }    
    }
}


void TileMap::drawTile(int xPos, int yPos, int type){
    if(type == 0){
        return;
    }else if(type == 1){
   TextureManager::getInstance()->addDraw("tileset",xPos,yPos,m_cellWidth,m_cellHeight,Window::getInstance()->getRenderer(),m_layer,1,3,SDL_FLIP_NONE);    
    }else if(type == 2){
   TextureManager::getInstance()->addDraw("tileset",xPos,yPos,m_cellWidth,m_cellHeight,Window::getInstance()->getRenderer(),m_layer,3,3,SDL_FLIP_NONE);    
    }else if(type == 3){
   TextureManager::getInstance()->addDraw("tileset",xPos,yPos,m_cellWidth,m_cellHeight,Window::getInstance()->getRenderer(),m_layer,7,1,SDL_FLIP_NONE);    
    }
}

