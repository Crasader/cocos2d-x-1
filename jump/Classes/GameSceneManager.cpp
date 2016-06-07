//
//  GameSceneManager.cpp
//  jump
//
//  Created by zwj on 16/6/6.
//
//

#include "GameSceneManager.hpp"
#include "MenuLayer.hpp"
#include "ChoiceCubeLayer.hpp"

void GameSceneManager::createScene()
{

    auto scene=Scene::create();
    auto layer=MenuLayer::create();
    scene->addChild(layer);
    Director::getInstance()->runWithScene(scene);
    
}

void GameSceneManager::goChoiceCubeLayer()
{

    auto scene=Scene::create();
    auto layer=ChoiceCubeLayer::create();
    scene->addChild(layer);
    layer->gsm=this;
    Director::getInstance()->replaceScene(scene);

}