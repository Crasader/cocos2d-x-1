
//
//  gameLayer.cpp
//  practice
//
//  Created by zwj on 16/5/20.
//
//

#include "gameLayer.hpp"
#include "mapLayer.hpp"
#include "operateLayer.hpp"
#include "rocker.hpp"
#include "baseRole.hpp"
#include "propertyMananger.hpp"

bool gameLayer::init()
{

    auto roleMap=FileUtils::getInstance()->getValueMapFromFile("hero.plist");
    propertyManager *pManager=propertyManager::create();
    pManager->setArmtureName(roleMap["armtureName"].asString());
    pManager->setDataName(roleMap["dataName"].asString());
    pManager->setHP(roleMap["HP"].asInt());
    pManager->setID(roleMap["ID"].asInt());
    pManager->setATK(roleMap["ATK"].asInt());
    pManager->setLOCKLIMIT(roleMap["lockLimit"].asInt());
    pManager->setATKLIMIT(roleMap["ATKLimit"].asInt());
    pManager->setPlayerName(roleMap["PlayerName"].asString());
    pManager->setHitRect(RectFromString(roleMap["HitRect"].asString()));
    pManager->setHitPoint(pManager->getHitRect().origin);
    pManager->setGetRect(RectFromString(roleMap["gethitRect"].asString()));
    pManager->setGetPoint(pManager->getGetRect().origin);
    
    pManager->retain();
    
    
    
    auto hero=baseRole::creatWithProperty(pManager);
    hero->setPosition(200,400);
    hero->type=static_cast<ROLE_TYPE>(roleMap["Type"].asInt());
    this->addChild(hero,100);
    
    mapLayer *mapLayer=mapLayer::create();
    
    mapLayer->setBackGround("background.jpg");
    //this->addChild(mapLayer);
    
    operateLayer *operateLayer=operateLayer::create();
    //this->addChild(operateLayer);
    
    
    
    auto rocker0=rocker::createRocker("CloseNormal.png", "background.jpg", Point(200,200));
    rocker0->startRocker(true);
    this->addChild(rocker0);
    
    
    
    
    
    
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("niugaoqing0.plist");
    auto sprite=Sprite::createWithSpriteFrameName("niugaoqing_default_1.png");
    sprite->setPosition(Point(200,200));
    
    
    Animation *animation=Animation ::create();
    for (int i=1; i<=8; i++) {
        __String *frameName=__String::createWithFormat("niugaoqing_default_%d.png",i);
        SpriteFrame* cache=SpriteFrameCache::getInstance()->getSpriteFrameByName(frameName->getCString());
        animation->addSpriteFrame(cache);
        }

    
    //animation->setRestoreOriginalFrame(true);
    animation->setDelayPerUnit(0.15);
    Animate *animate=Animate::create(animation);
    sprite->runAction(RepeatForever::create( animate));
   
    this->addChild(sprite);
    
    return true;
}