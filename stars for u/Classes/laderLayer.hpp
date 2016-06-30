//
//  laderLayer.hpp
//  MyCppGame
//
//  Created by zwj on 16/6/30.
//
//

#ifndef laderLayer_hpp
#define laderLayer_hpp

#include <stdio.h>
#include <cocos2d.h>
#include "GameSceneManager.hpp"
#include "Box2D/Box2D.h"


USING_NS_CC;

class laderLayer:public Layer
{
public:
    virtual bool init();
    static laderLayer* create();
    GameSceneManager* gsm;
    int k=0;
    Sprite* star;
    
    void starFunc(float dt);
    virtual bool onTouchBegan(Touch* touch, Event *event);
    
    void initPhysic();
    b2World* world;
    virtual void onExit();
    
    void update(float dt);
    
    void goBackCallBack(Ref* pSender);

};

#endif /* laderLayer_hpp */
