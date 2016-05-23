
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
#include "roleController.hpp"
#include "baseFSM.hpp"


gameLayer* gameLayer::create()
{
    gameLayer *layer=new gameLayer();
    if (layer&&layer->init()) {
        layer->autorelease();
        return layer;
    }
    CC_SAFE_DELETE(layer);
    return nullptr;
}

bool gameLayer::init()
{
//player
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
    pManager->setSPEED(roleMap["speed"].asInt());
    
    pManager->retain();
    hero=baseRole::creatWithProperty(pManager);
    hero->setPosition(200,400);
    hero->type=static_cast<ROLE_TYPE>(roleMap["Type"].asInt());
    this->addChild(hero,100);
    roleController::getInstance()->heroVec.push_back(hero);
    
 //laowang
    auto mounsterMap=FileUtils::getInstance()->getValueMapFromFile("laowang.plist");
    propertyManager *nManager=propertyManager::create();
    nManager->setArmtureName(mounsterMap["armtureName"].asString());
    nManager->setDataName(mounsterMap["dataName"].asString());
    nManager->setHP(mounsterMap["HP"].asInt());
    nManager->setID(mounsterMap["ID"].asInt());
    nManager->setATK(mounsterMap["ATK"].asInt());
    nManager->setLOCKLIMIT(mounsterMap["lockLimit"].asInt());
    nManager->setATKLIMIT(mounsterMap["ATKLimit"].asInt());
    nManager->setPlayerName(mounsterMap["PlayerName"].asString());
    nManager->setHitRect(RectFromString(mounsterMap["HitRect"].asString()));
    nManager->setHitPoint(nManager->getHitRect().origin);
    nManager->setGetRect(RectFromString(mounsterMap["gethitRect"].asString()));
    nManager->setGetPoint(nManager->getGetRect().origin);
    
    nManager->retain();
    auto laowang=baseRole::creatWithProperty(nManager);
    laowang->setPosition(600,400);
    laowang->type=static_cast<ROLE_TYPE>(mounsterMap["Type"].asInt());
    laowang->setRotationSkewY(-180);
    this->addChild(laowang,100);

  
    roleController::getInstance()->monsterVec.push_back(laowang);
    
    baseFSM *basehero=baseFSM::createFSM(hero);
    basehero->retain();
    hero->setbaseFsm(basehero);
    
    baseFSM *basewang=baseFSM::createFSM(laowang);
    basewang->retain();
    laowang->setbaseFsm(basewang);
    
    
    
    
    //
    mapLayer *mapLayer=mapLayer::create();
    
    mapLayer->setBackGround("background.jpg");
    //this->addChild(mapLayer);
    
    operateLayer *operateLayer=operateLayer::create();
    //this->addChild(operateLayer);
    
    
    
    rocker0=rocker::createRocker("CloseNormal.png", "background.jpg", Point(200,200));
    rocker0->startRocker(true);
    this->addChild(rocker0);
    
    
    Director::getInstance()->getScheduler()->schedule(schedule_selector(gameLayer::update), this, (float)1/60, false);
    
    
       
    return true;
}
void gameLayer::update(float dt)
{
    hero->getbaseFsm()->switchMoveStat(rocker0->rockDirection);


}