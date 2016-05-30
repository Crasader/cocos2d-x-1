//
//  SetLayer.cpp
//  fruitAndbird
//
//  Created by zwj on 16/5/27.
//
//

#include "SetLayer.hpp"
#include "MainLayer.hpp"
#include "SimpleAudioEngine.h"

bool setLayer::init()
{
    if (!Layer::init())
    {
        return  false;
    }

    Size visibleSize=Director::getInstance()->getVisibleSize();
    Point oringin=Director::getInstance()->getVisibleOrigin();
    
    Sprite *backGround=Sprite::create("morning.png");
    backGround->setAnchorPoint(Point(0,0));
    backGround->setPosition(Point(oringin.x,oringin.y+visibleSize.height-backGround->getContentSize().height));
    this->addChild(backGround);
    
    Sprite* floor1=Sprite::create("floor.png");
    floor1->setAnchorPoint(Point(0,0));
    floor1->setPosition(Point(oringin.x,oringin.y));
    this->addChild(floor1);
    floor1->runAction(RepeatForever::create(Sequence::create(MoveTo::create(0.5, Point(-120,0)),MoveTo::create(0, Point(0,0)), NULL)));
    
    Sprite *pauseBack=Sprite::create("setBack.png");
    pauseBack->setPosition(Point(270,500));
    this->addChild(pauseBack,10);
    
    Sprite* music=Sprite::create("music.png");
    pauseBack->addChild(music,1);
    music->setPosition(Point(100,220));
    
    
    //checkbox的使用---------
    
    CheckBox* checkMusic=CheckBox::create("sound_on.png", "sound_off.png", "sound_off.png", "sound_stop.png", "sound_stop.png");
    pauseBack->addChild(checkMusic,1);
    checkMusic->setPosition(Point(320,220));
    checkMusic->setSelectedState(!MainLayer::musicFlag);
    checkMusic->addEventListener(CC_CALLBACK_2(setLayer::selectedEvent0, this));
    
    
    
    Sprite* sound=Sprite::create("sound.png");
    pauseBack->addChild(sound);
    sound->setPosition(Point(100,140));
    CheckBox *checkSound=CheckBox::create("sound_on.png", "sound_off.png", "sound_off.png", "sound_stop.png", "sound_stop.png");
    pauseBack->addChild(checkSound);
    checkSound->setPosition(Point(320,140));
    checkSound->setSelectedState(!MainLayer::soundFlag);
    checkSound->addEventListener(CC_CALLBACK_2(setLayer::selectedEvent1, this));
    
    MenuItemImage *menuItem=MenuItemImage::create("menu.png", "menu_off.png", CC_CALLBACK_1(setLayer::menuCallBack, this));
    menuItem->setPosition(Point(200,60));
    Menu *menu=Menu::create(menuItem, NULL);
    menu->setPosition(Point::ZERO);
    pauseBack->addChild(menu,1);
    
    
    //3dtitle
    NodeGrid *effectNode=NodeGrid::create();
    this->addChild(effectNode,11);
    Sprite* title=Sprite::create("title.png");
    title->setPosition(Point(270,800));
    effectNode->addChild(title,1);
    Director::getInstance()->setDepthTest(false);
    effectNode->runAction(RepeatForever::create(Ripple3D::create(2.0f, Size(64,48), Point(270,800), 360, 2, 10)));
    
    return  true;
}

void setLayer::menuCallBack(cocos2d::Ref *pSender)
{
    sceneManager->goToMainScene();
}
void setLayer::selectedEvent0(cocos2d::Ref *pSender, CheckBox::EventType type)
{
    switch (type) {
        case cocos2d::ui::CheckBox::EventType::SELECTED:
            CocosDenshion::SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
            MainLayer::musicFlag=false;
            break;
        case  cocos2d::ui::CheckBox::EventType::UNSELECTED:
            CocosDenshion::SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
            MainLayer::musicFlag=true;
            break;
        default:
            break;
    }


}
void setLayer::selectedEvent1(cocos2d::Ref *pSender, CheckBox::EventType type)
{

    switch (type) {
        case cocos2d::ui::CheckBox::EventType::SELECTED:
            MainLayer::soundFlag=false;
            break;
            case cocos2d::ui::CheckBox::EventType::UNSELECTED:
            MainLayer::soundFlag=true;
            break;
        default:
            break;
    }

}