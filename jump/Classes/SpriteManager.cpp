//
//  SpriteManager.cpp
//  jump
//
//  Created by zwj on 16/6/6.
//
//

#include "SpriteManager.hpp"
#include "Constant.h"

SpriteManager::SpriteManager(Layer* layerIn)
{

    this->layer=layerIn;
    
    batchNode=SpriteBatchNode::create("GJ_GameSheet1.png",800);  //800个子节点上限
    batchNode->setAnchorPoint(Point(0,0));
    batchNode->setPosition(Point(0,0));
    
    listenerTouch=EventListenerTouchOneByOne::create();
    listenerTouch->setSwallowTouches(true);
    listenerTouch->onTouchBegan=CC_CALLBACK_2(SpriteManager::myOnTouchBegan, this);
    listenerTouch->onTouchMoved=CC_CALLBACK_2(SpriteManager::myOnTouchMoved, this);
    listenerTouch->onTouchEnded=CC_CALLBACK_2(SpriteManager::myOnTouchEnded, this);
    listenerTouch->onTouchCancelled=CC_CALLBACK_2(SpriteManager::myOnTouchCanclled, this);
    
    layer->addChild(batchNode,BatchNodeZOrder);


}

void SpriteManager::SpPause()
{
    Rect recta(776,28,801-776,53-28);
    allSp[0]=createSprite(NULL, recta, batchNode, 1.0f, 1.0f, 960, 540, 60, 60, PauseBGZOrder-1);
    AaddEventListenerSprite(allSp[0]);

}

void SpriteManager::AaddEventListenerSprite(cocos2d::Sprite *sp)
{

    Director* director=Director::getInstance();
    director->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listenerTouch->clone(), sp);
    listenerTouch->retain();

}
bool SpriteManager::Judge(cocos2d::Sprite *sp, Point location)
{}

Sprite*  SpriteManager::createSprite(std::string *id, cocos2d::Rect recta, cocos2d::SpriteBatchNode *batchNode, float anchorX, float anchorY, float locationX, float locationY, float width, float height, int ZOrder)
{
    Sprite* sp=Sprite::createWithTexture(batchNode->getTexture(),recta);
    Size size=sp->getContentSize();
    float  scaleX=width/size.width;
    float scaleY=height/size.height;
    sp->setScale(scaleX, scaleY);
    sp->setAnchorPoint(Point(anchorX,anchorY));
    sp->setPosition(Point(locationX,locationY));
    sp->setUserData(id);
    batchNode->addChild(sp,ZOrder);
    return  sp;
    
}