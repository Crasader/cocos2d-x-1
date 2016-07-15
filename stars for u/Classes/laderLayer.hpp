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
    
    Sprite* bg;
    //提子数量
    int ladderNum=0;
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
   std::vector<b2Body*> bodyToDelete;
    
    laderLayer(int windNum, int cloudNum);
    
    void win();
    void fail();
    
    int ladderIndex=100;
    int cloudIndex=200;
    bool ladderStatus=false;
   
    
    void ladderUpdate(float dt);
    bool touchBool=false;
    
    int reBuildNum=0;
    
    //cloud
    void cloudPlace();
    int lx=0;
    int ly=0;
    Vector<Sprite*> cloudVector;
    void randomColoud();
    
    
    

};

#endif /* laderLayer_hpp */
