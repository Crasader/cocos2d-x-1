//
//  GameSceneManager.cpp
//  MyCppGame
//
//  Created by zwj on 16/6/13.
//
//

#include "GameSceneManager.hpp"
#include "MenuLayer.hpp"
#include "OpeningLayer.hpp"
#include "StarBookLayer.hpp"
#include "SettingLayer.hpp"
void GameSceneManager::createOpeningLayer()
{

    auto scene=Scene::create();
    auto layer=OpeningLayer::create();
    scene->addChild(layer);
    Director::getInstance()->runWithScene(scene);

}
//menu
void GameSceneManager::goMenuLayer()
{

    auto scene=Scene::create();
    auto layer=MenuLayer::create();
    scene->addChild(layer);
    layer->gsm=this;
    
    //过渡效果
    auto act=TransitionFade::create(0.5f, scene);
    Director::getInstance()->replaceScene(act);
}

//book
void GameSceneManager::goBookLayer()
{
    
    auto scene=Scene::create();
    auto layer=StarBookLayer::create();
    scene->addChild(layer);
    layer->gsm=this;
    
    //过渡效果
    auto act=TransitionFade::create(0.5f, scene);
    Director::getInstance()->replaceScene(act);
}


//setting
void GameSceneManager::goSettingLayer()
{
    auto scene=Scene::create();
    auto layer=SettingLayer::create();
    scene->addChild(layer);
    layer->gsm=this;
    auto act=TransitionFade::create(0.5f, scene);
    Director::getInstance()->replaceScene(act);
}