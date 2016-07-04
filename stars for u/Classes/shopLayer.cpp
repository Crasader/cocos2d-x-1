//
//  shopLayer.cpp
//  MyCppGame
//
//  Created by zwj on 16/7/4.
//
//

#include "shopLayer.hpp"
#include "StarBookLayer.hpp"

//extern bool shopOn;


bool shopLayer::init()
{

    if (!Layer::init())
    {
        return false;
        
    }
    auto size=Director::getInstance()->getVisibleSize();
    //大背景，透明
    auto bg2=Sprite::create("bg2.png");
    bg2->setPosition(size.width/2,size.height/2);
    this->addChild(bg2);
    bg2->setOpacity(100);
    
    //商店背景
    auto bg=Sprite::create("shop.png");
    //this->setContentSize(bg->getContentSize());
    bg->setPosition(size.width/2,size.height/2);
    bg->setTag(100);
    bg->setScale(1.5);
    this->addChild(bg);
    
   //触摸监听，注册级别最高
    auto dispatcher=Director::getInstance()->getEventDispatcher();
     lisetener=EventListenerTouchOneByOne::create();
    lisetener->onTouchBegan=CC_CALLBACK_2(shopLayer::onTouchBegan, this);
   // dispatcher->addEventListenerWithSceneGraphPriority(lisetener, this);
    dispatcher->addEventListenerWithFixedPriority(lisetener, -128);
    lisetener->setSwallowTouches(true);
    
    this->setScale(0);
    
    
  
    


    return true;
}

//触摸回调
bool shopLayer::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event)
{
    auto touchPoint=touch->getLocation();
    
    if (!(this->getChildByTag(100)->getBoundingBox().containsPoint(touchPoint)))
    {
       // shopOn=false;
        this->removeFromParentAndCleanup(true);
    }
    

    return true;
}



void shopLayer::onExit()
{
    Layer::onExit();
    
    //必须手动注销
    Director::getInstance()->getEventDispatcher()->removeEventListener(lisetener);
    
    
    log("onnnnnexit");

}