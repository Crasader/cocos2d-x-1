//
//  SpriteManager.cpp
//  jump
//
//  Created by zwj on 16/6/6.
//
//

#include "SpriteManager.hpp"
#include "Constant.h"
#include "ChoiceCubeLayer.hpp"
#include "MenuLayer.hpp"
#include "MusicManager.hpp"
#include "MusicLayer.hpp"

//初始化
SpriteManager::SpriteManager(Layer* layerIn)
{

    layer=layerIn;
    
    
    //SpriteBatchNode加载一张大图，包含多个节点
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


//各个精灵可调用的触摸方法
void SpriteManager::AaddEventListenerSprite(cocos2d::Sprite *sp)
{

    Director* director=Director::getInstance();
    director->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listenerTouch->clone(), sp);
    listenerTouch->retain();

}

//各个精灵的触摸事件
bool SpriteManager::Judge(cocos2d::Sprite *sp, Point location)
{
    Size size=sp->getContentSize();
    Rect rect(0,0,size.width,size.height);

    if (rect.containsPoint(location))
    {
        
        if(layer->getTag() == INDEX_MENULAYER && ((MenuLayer*)(layer))->mlh->JudgeSp(sp))
        {
            return true;
        }
        else if(layer->getTag() == INDEX_CHOICECUBELAYER && ((ChoiceCubeLayer*)(layer))->cclh->JudgeSp(sp))
        {
            return true;
        }
        else if(layer->getTag() == INDEX_MUSICLAYER && ((MusicLayer*)(layer))->mh->JudgeSp(sp))
        {
            return true;
        }
    }
    return false;
}


//精灵创建方法，调用batchNode载入的图片直接裁切
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

bool SpriteManager::myOnTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event)
{
    isTouchBegin=true;
    
    Sprite* targetSp=static_cast<Sprite*>(event->getCurrentTarget());
    Point location=targetSp->convertToNodeSpace(touch->getLocation());
    return Judge(targetSp, location);


}
void SpriteManager::myOnTouchMoved(cocos2d::Touch *touch, cocos2d::Event *event)
{
    isTouchBegin=false;
    isTouchMove=true;

}
void SpriteManager::myOnTouchEnded(cocos2d::Touch *touch, cocos2d::Event *event)
{
    isTouchMove=false;
    Sprite* targetSp=static_cast<Sprite*>(event->getCurrentTarget());
    Point location=targetSp->convertToNodeSpace(touch->getLocation());
    Judge(targetSp, location);
}
void SpriteManager::myOnTouchCanclled(cocos2d::Touch *touch, cocos2d::Event *event)
{

    myOnTouchEnded(touch, event);
}

//pic创建
Sprite* SpriteManager::createStaticSprite(std::string *id, std::string pic, float anchorX, float anchorY, float locationX, float locationY, float width, float height)
{
    Sprite* sp=Sprite::create(pic);
    Size size=sp->getContentSize();
    float scaleX=width/size.width;
    float scaleY=height/size.height;
    sp->setScale(scaleX, scaleY);
    sp->setAnchorPoint(Point(anchorX,anchorY));
    sp->setPosition(Point(locationX,locationY));
    sp->setUserData(id);
    return sp;
}


//
void SpriteManager::backgroundRoll()
{
// new std::string(); ??????
    Sprite* bg=createStaticSprite(new std::string("bg"), "game_bg_01_001-hd.png", 0, 0, 0, 0, WIDTH, HEIGHT);

    //判断哪个场景/////////////////////////
    if (layer->getTag()==INDEX_GRAMLAYER)
    {
        
    }
    
    
    
    
    

}
//创建缩放的精灵
Scale9Sprite* SpriteManager::createScale9Sprite(std::string pic, cocos2d::Rect recta1, cocos2d::Rect recta2, float anchorX, float anchorY, float locationX, float locationY, float width, float height, int ZOrder)
{
    auto ss=Scale9Sprite::create(pic, recta1, recta2);
    ss->setAnchorPoint(Point(anchorX,anchorY));
    ss->setContentSize(Size(width,height));
    ss->setPosition(Point(locationX,locationY));
    layer->addChild(ss,ZOrder);
    return ss;
}

//屏幕四边
void SpriteManager::createSiJiao()
{
    createSprite(NULL, Rect(825,386,897-825,457-386), batchNode, 0, 0, 0, 0, 120, 120, GroundZOrder-1);
    Sprite* sp=createSprite(NULL, Rect(825,386,897-825,457-386), batchNode, 0, 0, WIDTH-120, 0, 120, 120, GroundZOrder+1);
    sp->setFlippedX(true);
    
    sp = createSprite(NULL, Rect(825,386,897-825,457-386), batchNode, 0.0f, 0.0f, 0, HEIGHT-120, 120, 120, GroundZOrder+1);
    sp->setFlippedY(true);
    
   
    sp = createSprite(NULL, Rect(825,386,897-825,457-386), batchNode, 0.0f, 0.0f, WIDTH-120, HEIGHT-120, 120, 120, GroundZOrder+1);
    sp->setFlippedX(true);
    sp->setFlippedY(true);
    
    
    
}


//to bt filled
void SpriteManager::createGround()
{



}


//胜利
void SpriteManager::win()
{
    batchNode->removeChild(allSp[0], true);
    Director::getInstance()->pause();
    
    createSprite(NULL, Rect(419,652,619-419,708-652), batchNode, 0.5, 0.5, WIDTH/2, HEIGHT/2, 500, 200, PauseBGZOrder+1);
    
    allSp[23] = createSprite(NULL, Rect(871,154,910-871,186-154), batchNode, 0.5f, 0.5f, 45, 540-37, 63, 55, GoBackZOrder);
    allSp[23]->setRotation(-90);
    AaddEventListenerSprite(allSp[23]);

}