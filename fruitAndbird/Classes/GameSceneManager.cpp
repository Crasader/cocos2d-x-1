//
//  GameSceneManager.cpp
//  fruitAndbird
//
//  Created by zwj on 16/5/27.
//
//
//带有总场景控制类的场景创建方法
#include "GameSceneManager.hpp"
#include "MainLayer.hpp"
#include "BirdLayer.hpp"
#include "FruitLayer.hpp"
#include "GameLayer.hpp"
#include "SetLayer.hpp"
#include "RankBirdLayer.hpp"
#include "RankFruitLayer.hpp"
#include "HelpLayer.hpp"
#include "AboutLayer.hpp"


void GameSceneManager::createMainScene()
{
    mainScene=Scene::create();
    MainLayer *layer=MainLayer::create();
    layer->sceneManager=this;
    mainScene->addChild(layer);
}
//切换到main场景
void GameSceneManager::goToMainScene()
{
    Director::getInstance()->setDepthTest(true);
    mainScene=Scene::create();
    MainLayer *layer=MainLayer::create();
    mainScene->addChild(layer);
    layer->sceneManager=this;//MainLayer中的GameSceneManager 的指针指向此类
    auto ss=TransitionFade::create(1, mainScene);
    Director::getInstance()->replaceScene(mainScene);

}
//切换到bird场景
void GameSceneManager::goToFlappyScene(int i)
{
    Director::getInstance()->setDepthTest(true);
    birdScene=Scene::create();
    birdLayer *layer=birdLayer::create();
    birdScene->addChild(layer);
    layer->sceneManager=this;
    if (i==0) {
        auto ss=TransitionFadeTR::create(1, birdScene);
        Director::getInstance()->replaceScene(ss);
    }
    if (i==1) {
        auto ss=TransitionFade::create(1, birdScene);
        Director::getInstance()->replaceScene(ss);
    }
    
}
//切换到水果场景
void GameSceneManager::goToSquishyScene(int i)
{
    Director::getInstance()->setDepthTest(true);
    fruitScene=Scene::create();
    fruitLayer *layer=fruitLayer::create();
    fruitScene->addChild(layer);
    layer->sceneManager=this;
    if (i==0) {
        auto ss=TransitionFadeTR::create(1, fruitScene);
        Director::getInstance()->replaceScene(ss);
    }
    if (i==1) {
        auto ss=TransitionFade::create(1, fruitScene);
        Director::getInstance()->replaceScene(ss);
    }


}

//切换到game场景
void GameSceneManager::goToGameScene()
{
    Director::getInstance()->setDepthTest(true);
    gameScene=Scene::create();
    gameLayer *layer=gameLayer::create();
    gameScene->addChild(layer);
    layer->sceneManager=this;
    auto ss=TransitionPageTurn::create(1, gameScene, false);
    Director::getInstance()->replaceScene(gameScene);
}
//切换到set场景
void GameSceneManager::goToSetScene()
{
    musicScene=Scene::create();
    setLayer *layer=setLayer::create();
    layer->sceneManager=this;
    musicScene->addChild(layer);
    auto ss=TransitionPageTurn::create(1, musicScene, false);
    Director::getInstance()->replaceScene(ss);
}
//切换到birdRank场景
void GameSceneManager::goToRankBirdScene()
{
    rankScene=Scene::create();
    rankBirdLayer *layer=rankBirdLayer::create();
    rankScene->addChild(layer);
    layer->sceneManager=this;
    auto ss=TransitionPageTurn::create(1, rankScene, false);
    Director::getInstance()->replaceScene(ss);

}

//切换到fruitRank场景
void GameSceneManager::goToRankFruitScene()
{
    rankScene=Scene::create();
    ranFruitLayer *layer=ranFruitLayer::create();
    rankScene->addChild(layer);
    layer->sceneManager=this;
    auto ss=TransitionPageTurn::create(1, rankScene, false);
    Director::getInstance()->replaceScene(ss);
    
}

void GameSceneManager::goToAboutScene()
{
    aboutScene=Scene::create();
    aboutLayer *layer=aboutLayer::create();
    aboutScene->addChild(layer);
    layer->sceneManager=this;
    auto ss=TransitionPageTurn::create(1, aboutScene, false);
    Director::getInstance()->replaceScene(ss);

}

void GameSceneManager::goToHelpScene()
{
    helpScene=Scene::create();
    helpLayer *layer=helpLayer::create();
    helpScene->addChild(layer);
    layer->sceneManager=this;
    auto ss=TransitionPageTurn::create(1, helpScene, false);
    Director::getInstance()->replaceScene(ss);
}

