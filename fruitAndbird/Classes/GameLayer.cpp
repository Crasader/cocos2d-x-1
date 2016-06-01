//
//  GameLayer.cpp
//  fruitAndbird
//
//  Created by zwj on 16/5/27.
//
//

#include "GameLayer.hpp"
#include <time.h>

bool gameLayer::init()
{

    if (!Layer::init())
    {
        return false;
    }

    Size visibleSize=Director::getInstance()->getVisibleSize();
    Point origin=Director::getInstance()->getVisibleOrigin();
    
    int i =random();
    
    if (i%2==0)
    {
        backGround=Sprite::create("morning.png");
    }
    if (i%2==1)
    {
        backGround=Sprite::create("night.png");
    }
    backGround->setAnchorPoint(Point(0,0));
    backGround->setPosition(Point(origin.x,origin.y+visibleSize.height-backGround->getContentSize().height));
    this->addChild(backGround,0);
    
    Sprite* floor=Sprite::create("floor.png");
    floor->setAnchorPoint(Point(0,0));
    floor->setPosition(origin.x,origin.y);
    this->addChild(floor);
    floor->runAction(RepeatForever::create(Sequence::create(MoveTo::create(0.5, Point(-120,0)),MoveTo::create(0, Point(0,0)), NULL)));
    
    effecNode=NodeGrid::create();
    this->addChild(effecNode,11);
    Sprite* title=Sprite::create("title.png");
    title->setPosition(270,800);
    effecNode->addChild(title,12);
    Director::getInstance()->setDepthTest(false);
    effecNode->runAction(RepeatForever::create(Ripple3D::create(2.0f, Size(64,48), Point(270,800), 360, 2, 10)));
    
    
    
    MenuItemImage* birdItem=MenuItemImage::create("Bird.png", "Bird_off.png", CC_CALLBACK_1(gameLayer::menuCallBack0, this));
    birdItem->setPosition(Point(visibleSize.width/2,visibleSize.height/2));
    MenuItemImage* fruitItem=MenuItemImage::create("Fruit.png", "Fruit_off.png", CC_CALLBACK_1(gameLayer::menuCallBack1, this));
    fruitItem->setPosition(Point(visibleSize.width/2,visibleSize.height/2-100));
    
    MenuItemImage* menuItem=MenuItemImage::create("menu.png", "menu_off.png", CC_CALLBACK_1(gameLayer::menuCallBack2, this));
    menuItem->setPosition(Point(80,50));
    
    Menu* menu=Menu::create(birdItem,fruitItem,menuItem, NULL);
    menu->setPosition(0,0);
    this->addChild(menu,10);
    
    return true;
}

int gameLayer::random()
{
    srand((unsigned)time(NULL));
    int number=rand()%6;
    return number;
}

void gameLayer::initTitle()
{
    Sprite* title=Sprite::create("title.png");
    title->setPosition(270,800);
    this->addChild(title,12);
    this->removeChild(effecNode);
    
}
void gameLayer::menuCallBack0(cocos2d::Ref *pSender)
{
    sceneManager->goToFlappyScene(0);


}
void gameLayer::menuCallBack1(cocos2d::Ref *pSender)
{
    sceneManager->goToSquishyScene(0);
}
void gameLayer::menuCallBack2(cocos2d::Ref *pSender)
{
    sceneManager->goToMainScene();
    
}