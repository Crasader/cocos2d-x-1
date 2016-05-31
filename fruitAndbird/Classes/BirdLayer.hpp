//
//  BirdLayer.hpp
//  fruitAndbird
//
//  Created by zwj on 16/5/27.
//
//

#ifndef BirdLayer_hpp
#define BirdLayer_hpp

#include <stdio.h>
#include "GameSceneManager.hpp"
#include "ui/CocosGUI.h"
#include "extensions/cocos-ext.h"

using namespace std;
using namespace ui;
USING_NS_CC;
using namespace cocos2d::extension;

class birdLayer:public Layer
{
public:
    
    virtual bool init();
    void initBird();
    void startGame();
    void gameOver();
    void birdRun();
    void wingSound();
    void pointSound();
    void hitSound();
    void dieSound();
    void update_column(float dt);
    void update_bird(float dt);
    void moveObject();
    void initColumn1();
    void initColumn2();
    int random();
    void menuCallBack0(Ref* pSender);
     void menuCallBack1(Ref* pSender);
     void menuCallBack2(Ref* pSender);
     void menuCallBack3(Ref* pSender);
     void menuCallBack4(Ref* pSender);
    
    void selectedEvent0(Ref * pSender, CheckBox::EventType type);
     void selectedEvent1(Ref * pSender, CheckBox::EventType type);
    bool onTouchBegan0(Touch * touch,Event *event);
    bool onTouchPause(Touch *touch,Event *event);
    void setRunFlag1();
    void setRunFlag2();
    CREATE_FUNC(birdLayer);
  
public:
    int columnNumber;
    bool stopFlag;
    bool runFlag=false;
    int count=0;
    bool columnFlag1;
    bool columnFlag2;
    bool gameFlag;
    bool readyFlag;
    bool overFlag;
    NodeGrid* effecNode;
    LabelAtlas* pLabelAtlas;
    Sprite* overRank;
    MenuItemImage* replayItem;
    MenuItemImage* menuItem;
    Sprite* pause;
    Sprite* backGround;
    Sprite* floor;
    Scale9Sprite* columnUnder1;
    Scale9Sprite* columnOn1;
    Scale9Sprite* columnUnder2;
    Scale9Sprite* columnOn2;
    Sprite* bird;
    Sprite* ready;
    Sprite* pauseBack;
    Animate* animAc;
    
    
    
    GameSceneManager *sceneManager;
};
#endif /* BirdLayer_hpp */
