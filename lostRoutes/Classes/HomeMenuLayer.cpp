//
//  HomeMenuLayer.cpp
//  lostRoutes
//
//  Created by zwj on 16/5/6.
//
//

#include "HomeMenuLayer.hpp"

Scene* HomeMenuLayer::createScene()
{
    auto scene=Scene::create();
    auto layer=HomeMenuLayer::create();
    scene->addChild(layer);
    return scene;
}

bool HomeMenuLayer::init()
{
    if(!Layer::init())
{
    return false;
}
    auto visibleSize=Director::getInstance()->getVisibleSize();
    auto bg=TMXTiledMap::create("map/red_bg.tmx");
    addChild(bg);
    
    // zhuangshi
    auto top=Sprite::createWithSpriteFrameName("home-top.png");
    top->setPosition(Point(visibleSize.width/2,(visibleSize.height)-(top->getContentSize().height/2)));
    addChild(top);
    
    auto end=Sprite::createWithSpriteFrameName("home-end.png");
    end->setPosition(visibleSize.width/2,end->getContentSize().height/2);
    addChild(end);
    
    
    //kaishi
    auto startSpriteNormal=Sprite::createWithSpriteFrameName("home.button.start.png");
    auto startSpriteSelected=Sprite::createWithSpriteFrameName("home.button.start-on.png");
    auto startMenuItem=MenuItemSprite::create(startSpriteNormal, startSpriteSelected, CC_CALLBACK_1(HomeMenuLayer::menuItemCallBack, this) );
    startMenuItem->setTag(ActionType::MenuItemStart);
    
    //shezhi
    auto settingSpriteNormal=Sprite::createWithSpriteFrameName("home.button.setting.png");
    auto settingSpriteSelected=Sprite::createWithSpriteFrameName("home.button.setting-on.png");
    auto settingMenuItem=MenuItemSprite::create(settingSpriteNormal, settingSpriteSelected, CC_CALLBACK_1(HomeMenuLayer::menuItemCallBack, this ));
    settingMenuItem->setTag(ActionType::MentuItemSetting);
    
    
    auto mu=Menu::create(startMenuItem,settingMenuItem, NULL);
    mu->setPosition(visibleSize.width/2,visibleSize.height/2);
    mu->alignItemsVerticallyWithPadding(12); //自定间隙排列
    addChild(mu);
    

    return true;
}
void HomeMenuLayer::onEnterTansitionDidFinish()
{Layer::onEnterTransitionDidFinish();
    if(UserDefault::getInstance()->getBoolForKey(MUSIC_KEY))
    {
        SimpleAudioEngine::getInstance()->playBackgroundMusic(bg_music_1,true);
    
    
    };
}

void HomeMenuLayer::menuItemCallBack(cocos2d::Ref *pSender)
{
    if (UserDefault::getInstance()->getBoolForKey(SOUND_KEY)) {
        SimpleAudioEngine::getInstance()->playEffect(sound_1);
    }
    Scene *ts=nullptr;
    
    auto menuItem=(MenuItem* ) pSender;
    
    switch (menuItem->getTag()) {
        case ActionType::MenuItemStart  :
            Director::getInstance()->pushScene(Game::createScene());
            break;
        case ActionType::MentuItemSetting :
            ts=TransitionFlipX::create(0.5, SettingLayer::createScene());
            break;
        default:
            break;
  }
    if (ts) {
        Director::getInstance()->pushScene(ts);

        
    }
    




}