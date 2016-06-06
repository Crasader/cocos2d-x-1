//
//  SpriteManager.hpp
//  jump
//
//  Created by zwj on 16/6/6.
//
//

#ifndef SpriteManager_hpp
#define SpriteManager_hpp

#include <stdio.h>
#include <cocos2d.h>
#include "extensions/cocos-ext.h"
#include "Barrier.hpp"
USING_NS_CC;
using namespace extension;


class SpriteManager
{
public:
    SpriteBatchNode* batchNode;
    Layer *layer;
    EventListenerTouchOneByOne* listenerTouch;
    Sprite * allSp[24];
    Scale9Sprite* allSs[1];
    Barrier* tb[5];
    bool isTouchBegin=false;
    bool isTouchMove=false;
    
public:
    SpriteManager(Layer* layerIn);
    void SpPause();
    void AaddEventListenerSprite(Sprite* sp);
    bool Judge(Sprite* sp,Point location);
	static Sprite* createSprite(std::string* id, Rect recta, SpriteBatchNode* batchNode, float anchorX, float anchorY, float locationX, float locationY, float width, float height, int ZOrder);
  Sprite* createStaticSprite(std::string* id, std::string pic, float anchorX, float anchorY, float locationX, float locationY, float width, float height);
    bool myOnTouchBegan(Touch* touch,Event* event);
    void myOnTouchMoved(Touch * touch,Event* event);
    void myOnTouchEnded(Touch* touch,Event* event);
    void myOnTouchCanclled(Touch* touch,Event* event);
    void backgroundRoll();
	Scale9Sprite* createScale9Sprite(std::string pic, Rect recta1, Rect recta2,float anchorX, float anchorY, float locationX, float locationY, float width, float height, int ZOrder);
    void createSiJiao();
    void createGround();
    void win();


};

#endif /* SpriteManager_hpp */
