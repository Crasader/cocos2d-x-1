//
//  ChoiceCubeLayer.cpp
//  jump
//
//  Created by zwj on 16/6/7.
//
//

#include "ChoiceCubeLayer.hpp"

bool ChoiceCubeLayer::init()
{
    if (!Layer::init())
    {
        return false;
    }
    this->setTag(INDEX_CHOICECUBELAYER);
    visibleSize=Director::getInstance()->getVisibleSize();
    origin=Director::getInstance()->getVisibleOrigin();
    
    
    sh=new SpriteManager(this);
    cclh=new ChoiceCubeHelp(this);
    cclh->initCreateSprite();

    return true;
}