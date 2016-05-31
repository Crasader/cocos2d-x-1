//
//  AboutLayer.cpp
//  fruitAndbird
//
//  Created by zwj on 16/5/27.
//
//

#include "AboutLayer.hpp"

bool aboutLayer::init()
{
    if (!Layer::init())
    {
        return false;
    }
    Size visibleSize=Director::getInstance()->getVisibleSize();
    Point origin=Director::getInstance()->getVisibleOrigin();
    
    Sprite *backGround=Sprite::create("morning.png");
    backGround->setAnchorPoint(Point(0,0));
    backGround->setPosition(Point(origin.x,origin.y+visibleSize.height-backGround->getContentSize().height));
    this->addChild(backGround,0);
    
    Sprite* floor=Sprite::create("floor.png");
    floor->setAnchorPoint(Point(0,0));
    floor->setPosition(Point(origin.x,origin.y));
    this->addChild(floor);
    floor->runAction(
                     RepeatForever::create(
                                           Sequence::create(
                                                            MoveTo::create(0.5, Point(-120,0)),
                                                            MoveTo::create(0, Point(0,0)), NULL)));
    Sprite* about=Sprite::create("aboutP.png");
    about->setPosition(visibleSize.width/2,visibleSize.height/2);
    this->addChild(about);
    
    MenuItemImage* menuItem=MenuItemImage::create("menu.png", "menu_off.png", CC_CALLBACK_1(aboutLayer::menuCallBack, this));
    menuItem->setPosition(80,50);
    Menu* menu=Menu::create(menuItem, NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu,10);
    


    return true;
}
void aboutLayer::menuCallBack(cocos2d::Ref *pSender)
{
    sceneManager->goToMainScene();

}
