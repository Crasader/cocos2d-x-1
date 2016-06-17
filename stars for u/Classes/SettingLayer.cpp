//
//  SettingLayer.cpp
//  MyCppGame
//
//  Created by zwj on 16/6/16.
//
//

#include "SettingLayer.hpp"


//create()方法
SettingLayer* SettingLayer::create()
{
    SettingLayer* layer=new SettingLayer();
    if (layer&&layer->init())
    {
        layer->autorelease();
        return layer;
    }

    CC_SAFE_DELETE(layer);
    return  nullptr;
}

bool SettingLayer::init()
{
    if (!Layer::init())
    {
        return false;
    }
    
    
    




    return  true;
}