//
//  GameSceneManager.cpp
//  MyCppGame
//
//  Created by zwj on 16/6/13.
//
//

#include "GameSceneManager.hpp"
#include "MenuLayer.hpp"
void GameSceneManager::createMenuLayer()
{

    auto scene=Scene::create();
    auto layer=MenuLayer::create();
    scene->addChild(layer);
    Director::getInstance()->runWithScene(scene);

}