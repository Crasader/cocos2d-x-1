//
//  LevelLayer.cpp
//  jump
//
//  Created by zwj on 16/6/9.
//
//

#include "LevelLayer.hpp"

bool LevelLayer::init()
{

    if (!Layer::init())
    {
        return false;
    }
    
    sh=new SpriteManager(this);
    
    
    


    
    return  true;
}




LevelLayer* LevelLayer::create()
{

    LevelLayer* layer=new LevelLayer();
    if (layer&&layer->init())
    {
        layer->autorelease();
        return layer;
    }
    
    CC_SAFE_DELETE(layer);
    
    return nullptr;


}