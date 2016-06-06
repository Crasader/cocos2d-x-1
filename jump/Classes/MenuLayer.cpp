//
//  MenuLayer.cpp
//  jump
//
//  Created by zwj on 16/6/6.
//
//

#include "MenuLayer.hpp"
#include "Constant.h"

bool MenuLayer::init()
{
    if (!Layer::init())
    {
        return false;
    }
    this->setTag(INDEX_MENULAYER);
    visibleSize=Director::getInstance()->getVisibleSize();
    origin=Director::getInstance()->getVisibleOrigin();
    

    


    return true;
}