//
//  GameSceneManager.cpp
//  jump
//
//  Created by zwj on 16/6/6.
//
//

#include "GameSceneManager.hpp"
#include "MenuLayer.hpp"

void GameSceneManager::createScene()
{

    auto scene=Scene::create();
    auto layer=MenuLayer::create();
    scene->addChild(layer);
    
    


}