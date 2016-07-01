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
    static laderLayer* create(int windNum, int cloudNum);
    GameSceneManager* gsm;
    //提子数量
    int k=0;
    Sprite* star;
    
    //风力 负表示朝左边，正表示朝右
    int wind=0;
    int cloud=0;
    //触摸
    virtual bool onTouchBegan(Touch* touch, Event *event);
    virtual void onTouchMoved(Touch* touch, Event* event);
    virtual void onTouchEnded(Touch* touch, Event* event);
    //box2d
    void initPhysic();
    b2World* world;
    
    //析构
    virtual void onExit();
    
    void update(float dt);
    
    void goBackCallBack(Ref* pSender);
    
    //bodyVector
    std::vector<b2Body*> bodyVector;
    
    laderLayer(int windNum, int cloudNum);
    
    

    

};

#endif /* laderLayer_hpp */
