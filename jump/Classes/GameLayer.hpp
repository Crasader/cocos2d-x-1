//
//  GameLayer.hpp
//  jump
//
//  Created by zwj on 16/6/11.
//
//

#ifndef GameLayer_hpp
#define GameLayer_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "SpriteManager.hpp"
#include "GameSceneManager.hpp"
#include "Barrier.hpp"
#include "GDData.hpp"
#include "JumpCube.hpp"

USING_NS_CC;

class GameLayer:public Layer
{


public:
    GameSceneManager* gsm;
    Director* director;
    Size visibleSize;
    Point origin;
    
    SpriteManager* sh;
    //PauseCode* pc;
    
    GDData* gdData;
    
    bool isUpdateAll=true;
    int indexGK;
    JumpCube *jc;
    std::string *ids;
    Barrier* tb;
    Barrier* zh;
    std::vector<Barrier*>::iterator iter;
    std::map<std::string, Sprite*> spMap;
    int timeCountCollision=0;
     std::vector<Barrier*> barrierVector;
    
    int timeCount=0;

    bool isTouch=false;
    virtual bool init();
    
    bool  myOnTouchBegan(Touch* touch,Event *event);
    void myOnTouchMoved(Touch* touch,Event *event);
    void myOnTouchEnded(Touch* touch,Event *event);
    void myOnTouchCancelled(Touch* touch,Event *event);
    
    void updateAll(float dt);
    void deleteBarrier();
    void collisiontDetection();
    void intiObjectOrSprite();
    void refleshJumpCube();
    void updateBarrier();
    CREATE_FUNC(GameLayer);

};
#endif /* GameLayer_hpp */
