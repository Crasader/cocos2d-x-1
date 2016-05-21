//
//  clockLayer.cpp
//  practice
//
//  Created by zwj on 16/5/19.
//
//

#include "clockLayer.hpp"

bool clockLayer::init()
{

    Size winSize=Director::getInstance()->getWinSize();
    MenuItemLabel *menuItem=MenuItemLabel::create(Label::create("back", "", 30), CC_CALLBACK_1(clockLayer::gotoMenu, this));
    
    menuItem->setPosition(winSize.width*0.8,winSize.height*0.8);
    auto mu=Menu::create(menuItem, NULL);
    mu->setPosition(0,0);
    this->addChild(mu);
 
    background=Sprite::create("background.jpg");
   // background->setScale(0.5);
    background->setPosition(winSize.width/2,winSize.height/2);
    this->addChild(background);
    
    hour=Sprite::create("shi.png");
    //hour->setScale(0.5);
    hour->setPosition(winSize.width/2,winSize.height/2);
    this->addChild(hour);
    
    minute=Sprite::create("fen.png");
    //minute->setScale(0.5);
    minute->setPosition(winSize.width/2,winSize.height/2);
    this->addChild(minute);
    
    second=Sprite::create("miao.png");
    //second->setScale(0.5);
    second->setPosition(winSize.width/2,winSize.height/2);
    this->addChild(second);
    
    //获取当前时间
    struct timeval noewTimal;
    gettimeofday(&noewTimal, NULL);
    struct tm*tm;
    time_t time_sec;
    time_sec=noewTimal.tv_sec;
    tm=localtime(&time_sec);
    
    second->setRotation(tm->tm_sec*6);
    minute->setRotation(tm->tm_min*6);
  
    if (tm->tm_hour>12) {
        hour->setRotation((tm->tm_hour-12)*5*6+tm->tm_min*6/72 );
        
    }else
    {hour->setRotation((tm->tm_hour)*5*6+tm->tm_min*6/72 );}
    
    schedule(schedule_selector(clockLayer::timeUpdate), 0.30f);

    return true;
}


void clockLayer::timeUpdate(float dt)
{
    second->setRotation(second->getRotation()+6);
   
    i++;
    if (i==60) {
        minute->setRotation(minute->getRotation()+6);
        i=0;
    }
    



}
void clockLayer::gotoMenu(cocos2d::Ref *pSender)
{
    tsm->createLoadScene();
    
}