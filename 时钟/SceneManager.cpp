//
//  SceneManager.cpp
//  practice
//
//  Created by zwj on 16/5/19.
//
//

#include "SceneManager.hpp"
#include "loadLayer.hpp"
#include "openLayer.hpp"
#include "clockLayer.hpp"

void SceneManager::createLoadScene()
{

    loadScene=Scene::create();
    auto layer=loadLayer::create();
    layer->tsm=this;

    loadScene->addChild(layer);
    
    Director::getInstance()->runWithScene(loadScene);

    
}


void SceneManager::goOpenScene()
{
    openScene=Scene::create();
    auto layer=openLayer::create();
    
    layer->tsm=this;

    openScene->addChild(layer);
    
    Director::getInstance()->replaceScene(openScene);
    
}

void SceneManager::goClockScecne()
{
    clockScene=Scene::create();
    auto layer=clockLayer::create();
    layer->tsm=this;
    clockScene->addChild(layer);
    
    Director::getInstance()->replaceScene(clockScene);




}