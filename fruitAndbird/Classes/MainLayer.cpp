//
//  MainLayer.cpp
//  fruitAndbird
//
//  Created by zwj on 16/5/27.
//
//

#include "MainLayer.hpp"
#include "SimpleAudioEngine.h"
#include <time.h>

bool MainLayer::musicFlag=true;
bool MainLayer::soundFlag=true;
bool MainLayer::init()
{
    if (!Layer::init()) {
        return  false;
    }
    Size visibleSize=Director::getInstance()->getVisibleSize();
    Point origin=Director::getInstance()->getVisibleOrigin();
    
    
    int i=random();
    if (i%2==0) {
        backGround=Sprite::create("morning.png");
        
    }
    else
    {
        backGround=Sprite::create("night.png");
    
    }
    backGround->setAnchorPoint(Point(0,0));
    backGround->setPosition(Point(origin.x,origin.y+visibleSize.height-backGround->getContentSize().height));
    this->addChild(backGround,0);
    
    if (musicFlag)
    {
        CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("playscene.mp3",true);
    }
    Sprite *floor=Sprite::create("floor.png");
    floor->setAnchorPoint(Point(0,0));
    floor->setPosition(origin.x,origin.y);
    this->addChild(floor);
    
    floor->runAction(RepeatForever::create(Sequence::create(MoveTo::create(0.5, Point(-120,0)),MoveTo::create(0, Point(0,0)), NULL)));
    
    MenuItemImage *gameItem=MenuItemImage::create("start.png", "start_off.png", CC_CALLBACK_1(MainLayer::menuCallBack0, this));
    gameItem->setPosition(Point(150,600));
    
    MenuItemImage *rankItem=MenuItemImage::create("rank.png", "rank_off.png", CC_CALLBACK_1(MainLayer::menuCallBack1, this));
    rankItem->setPosition(Point(390,600));
    
    MenuItemImage *setItem=MenuItemImage::create("set.png", "set_off.png", CC_CALLBACK_1(MainLayer::menuCallBack2, this));
    setItem->setPosition(Point(150,450));
    
    MenuItemImage *helpItem=MenuItemImage::create("help.png", "help_off.png", CC_CALLBACK_1(MainLayer::menuCallBack3, this));
    helpItem->setPosition(Point(390,450));
    
    MenuItemImage *aboutItem=MenuItemImage::create("about.png", "about_off.png", CC_CALLBACK_1(MainLayer::menuCallBack4, this));
    aboutItem->setPosition(Point(150,300));
    
    MenuItemImage *exitItem=MenuItemImage::create("exit.png", "exit_off.png", CC_CALLBACK_1(MainLayer::menuCallBack5, this));
    exitItem->setPosition(Point(390,300));
    
    Menu* menu=Menu::create(gameItem,rankItem,setItem,helpItem,aboutItem,exitItem, NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu);
    
    
    //实现3d水波效果
    effectNode=NodeGrid::create();
    this->addChild(effectNode,10);
    Sprite *title=Sprite::create("title.png");
    title->setPosition(270,800);
    effectNode->addChild(title,12);
    Director::getInstance()->setDepthTest(false);
    effectNode->runAction(RepeatForever::create(Ripple3D::create(2.0f, Size(32,24), Point(270,800), 360, 2, 5)));
    
    
    
    
    return  true;
}
int MainLayer::random()
{
    srand((unsigned)time(NULL));//种子,后面可以直接调用rand()产生随机数
    int number=rand()%4;
    return  number;
}
void MainLayer::initTitle()
{
    Sprite *title=Sprite::create("title.png");
    title->setPosition(270,800);
    this->addChild(title);
    this->removeChild(effectNode);
}
void MainLayer::menuCallBack0(cocos2d::Ref *pSender)
{
    initTitle();
    sceneManager->goToGameScene();

}
void MainLayer::menuCallBack1(cocos2d::Ref *pSender)
{
    initTitle();
    sceneManager->goToRankBirdScene();
}
void MainLayer::menuCallBack2(cocos2d::Ref *pSender)
{
    initTitle();
    sceneManager->goToSetScene();
}
void MainLayer::menuCallBack3(cocos2d::Ref *pSender)
{

    initTitle();
    sceneManager->goToHelpScene();
}
void MainLayer::menuCallBack4(cocos2d::Ref *pSender)
{
    initTitle();
    sceneManager->goToAboutScene();
}
void MainLayer::menuCallBack5(cocos2d::Ref *pSender)
{
    Director::getInstance()->end();
}
