//
//  LevelLayer.cpp
//  jump
//
//  Created by zwj on 16/6/9.
//
//

#include "LevelLayer.hpp"
#include "Constant.h"

bool LevelLayer::init()
{

    if (!Layer::init())
    {
        return false;
    }
    
    this->setTag(INDEX_LEVELLAYER);
    sh=new SpriteManager(this);
    llh=new LevelHelpLayer(this);
    llh->initCreateSp();
    indexLevel=1;


    
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