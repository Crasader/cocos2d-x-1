//
//  menuLayer.cpp
//  kissBear
//
//  Created by zwj on 16/5/10.
//
//

#include "menuLayer.hpp"

Scene *menuLayer::createScene()
{
    auto scene=Scene::create();
    auto layer=menuLayer::create();
    scene->addChild(layer);
    return scene;

    }

bool menuLayer::init(){
    if (!Layer::init()) {
        return false;
    }
    
    auto size=Director::getInstance()->getVisibleSize();
    auto bg=Sprite::create("bg1.png");
     CC_ASSERT(bg);
    bg->setPosition(size.width/2,size.height/2);
  
    addChild(bg);
    
    auto wc=Sprite::create("wo.png");
    wc->setPosition(size.width/2,size.height/2);
    addChild(wc);
    
    auto bear=Sprite::create("b.png");
    bear->setPosition(80,60);
    wc->addChild(bear);
    
    
    auto kiss=Sprite::create("m.png");
    kiss->setPosition(340,820);
    kiss->setRotation(20);
    addChild(kiss);
    
    auto menuLabel=Label::createWithTTF("Go", "Marker Felt.ttf", 50);
    auto startMenu=MenuItemLabel::create(menuLabel, CC_CALLBACK_0(menuLayer::go, this) );
    auto mu=Menu::create(startMenu, NULL);
    mu->setPosition(300,820);
    addChild(mu);


    return true;
}

void menuLayer::go()
{
    auto scene=HelloWorld::createScene();
    auto res=TransitionMoveInB::create(0.5, scene);
    
    Director::getInstance()->pushScene(res);


}