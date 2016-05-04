#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "iostream"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iterator>
#include <functional>
USING_NS_CC;

class HelloWorld : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    Sprite *bird;
    Sprite *barContainer;
    int offset;
    PhysicsWorld *world;
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    virtual bool onTouchBegan(Touch *t,Event *e);
    bool ContactBegin(PhysicsContact &contact);
  int score=0;
    int bodyNumber=1;
    void scoreFunc(float dt);
    void addBird();
    void initWorld();
    void addGround();
    void addBar(float dt);
    void addBarContainer();
    void stopGame();
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
