#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

USING_NS_CC;





class HelloWorld : public cocos2d::Layer
{
    
private:
    int score=0;
    int level=1;
    float interval=2;
    bool time;
    int bearPointCount;
    int i=0;
    int j[100]={0,0,0,0,0,0,0,0,0,0,0,0};
    int n=0;
    cocos2d::Point deletedPoint;
    cocos2d::Point bearP[9]={
                bearP[0]=cocos2d::Point(100,200),
            bearP[1]=cocos2d::Point(300,200),
            bearP[2]=cocos2d::Point(500,200),
            bearP[3]=cocos2d::Point(100,400),
            bearP[4]=cocos2d::Point(300,400),
            bearP[5]=cocos2d::Point(500,400),
            bearP[6]=cocos2d::Point(100,600),
            bearP[7]=cocos2d::Point(300,600),
            bearP[8]=cocos2d::Point(500,600),
            };
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  
    
     // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
    Sprite *bear;
    Sprite *kiss;
    Sprite *wo;
    EventListenerTouchOneByOne *listener;
public:
   //virtual void update(float dt);
    void bearShow(float dt);
    void setBearPosition();
    void restartGame();
 
    
    
    
};

#endif // __HELLOWORLD_SCENE_H__
