//
//  MusicLayer.cpp
//  jump
//
//  Created by zwj on 16/6/9.
//
//

#include "MusicLayer.hpp"
#include "Constant.h"


bool MusicLayer::init()
{

    if (!Layer::init())
    {
        return  false;
    }
    this->setTag(INDEX_MUSICLAYER );
    sh=new SpriteManager(this);
    
    mh=new MusicHelpLayer(this);

    mh->initCreateSprite();
    

    return true;
}



 MusicLayer* MusicLayer::create()
{
    MusicLayer* layer=new MusicLayer();
    
    if (layer&&layer->init())
    {
        layer->autorelease();
        return layer;
    }
    CC_SAFE_DELETE(layer);
    return nullptr;
    }