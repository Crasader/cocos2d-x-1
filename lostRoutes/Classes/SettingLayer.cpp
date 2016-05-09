//
//  SettingLayer.cpp
//  lostRoutes
//
//  Created by zwj on 16/5/6.
//
//

#include "SettingLayer.hpp"


Scene* SettingLayer::creatScene(){

    auto scene=Scene::create();
    auto layer=SettingLayer::create();
    scene->addChild(layer);
    return scene;



}


bool SettingLayer::init()
{
    if(!BaseLayer::init())
    {
        return false;
    }

    auto visibleSize=Director::getInstance()->getVisibleSize();
    auto origin=Director::getInstance()->getVisibleOrigin();
    
    
    //yinxiao
    auto soundOnSprite=Sprite::createWithSpriteFrameName("setting.check-on.png");
    

    
    


    return true;
}