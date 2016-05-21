//
//  SceneManger.cpp
//  practice
//
//  Created by zwj on 16/5/20.
//
//

#include "SceneManger.hpp"
#include "menuLayer.hpp"
#include "gameLayer.hpp"
void SceneManager::createScene()
{
    startScene=Scene::create();
    auto layer=menuLayer::create();
    startScene->addChild(layer);
    
    layer->tsm=this;
    
    Director::getInstance()->runWithScene(startScene);

}

void SceneManager::toGameScene()
{

    gameScene=Scene::create();
    auto layer=gameLayer::create();
    gameScene->addChild(layer);
    layer->tsm=this;
    
    Director::getInstance()->replaceScene(gameScene);


}