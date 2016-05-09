//
//  BaseLayer.cpp
//  lostRoutes
//
//  Created by zwj on 16/5/6.
//
//

#include "BaseLayer.hpp"


Scene *BaseLayer::createScene(){

    auto scene=Scene::create();
    auto layer=BaseLayer::create();
    scene->addChild(layer);
    return scene;
}

bool BaseLayer::init()
{
    if(!Layer::init())
    {
        return false;
}
    auto visibleSize=Director::getInstance()->getVisibleSize();
    auto origin=Director::getInstance()->getVisibleOrigin();
    
    auto bg=TMXTiledMap::create("map/red_bg.tmx");
    addChild(bg);
    
    
    //眼睛
  
    auto glassesSprite= Sprite::createWithSpriteFrameName("setting.glasses.png");
    glassesSprite->setPosition(Point(visibleSize.width-glassesSprite->getContentSize().width/2,160));
    addChild(glassesSprite);
    
    //手套
    auto handSprite=Sprite::createWithSpriteFrameName("setting.hand.png");
    handSprite->setPosition(Point(handSprite->getContentSize().width/2,60));
    addChild(handSprite);
    
    //ok
    auto okNormal=Sprite::createWithSpriteFrameName("setting.button.ok.png");
    auto okSelected=Sprite::createWithSpriteFrameName("setting.button.ok-on.png");
    auto okMenuItem=MenuItemSprite::create(okNormal, okSelected, CC_CALLBACK_1(BaseLayer::menuBackCallback, this));
    auto mu=Menu::create(okMenuItem, NULL);
    okMenuItem->setPosition(visibleSize.width/2-mu->getContentSize().width/2,60);
    addChild(mu);
    
    return true;
    
}

void BaseLayer::menuBackCallback(cocos2d::Ref *pSender)
{
    Director::getInstance()->popScene();
    if (UserDefault::getInstance()->getBoolForKey(SOUND_KEY)) {
        SimpleAudioEngine::getInstance()->playEffect(sound_1);
    }


}
void BaseLayer::onEnterTransitionDidFinish()
{

    Layer::onEnterTransitionDidFinish();
    if (UserDefault::getInstance()->getBoolForKey(MUSIC_KEY)) {
        SimpleAudioEngine::getInstance()->playBackgroundMusic(bg_music_1,true);
    }
    
}