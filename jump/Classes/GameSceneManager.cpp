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
#include "MusicLayer.hpp"
#include "LevelLayer.hpp"
#include "GameLayer.hpp"
#include "FlyLayer.hpp"

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
void GameSceneManager::goMenuLayer()
{

    auto scene=Scene::create();
    auto layer=MenuLayer::create();
    scene->addChild(layer);
    layer->gsm=this;
    Director::getInstance()->replaceScene(scene);
}

void GameSceneManager::goMusicLayer()
{
    auto scene=Scene::create();
    auto layer=MusicLayer::create();
    scene->addChild(layer);
    layer->tsm=this;
    Director::getInstance()->replaceScene(scene);

}

void GameSceneManager::goLevelLayer()
{
    auto scene=Scene::create();
    LevelLayer* layer=LevelLayer::create();
    scene->addChild(layer);
    layer->gsm=this;
    Director::getInstance()->replaceScene(scene);



}

void GameSceneManager::goGameLayer(int index)
{
    auto scene=Scene::create();
    GameLayer* layer=GameLayer::create();
    scene->addChild(layer);
    layer->gsm=this;
    layer->indexGK = index;
    Director::getInstance()->replaceScene(scene);
    
    
    
}
void GameSceneManager::goFlayLayer()
{
    auto scene=Scene::create();
    FlyLayer* layer=FlyLayer::create();
    scene->addChild(layer);
    layer->gsm=this;
    Director::getInstance()->replaceScene(scene);


}