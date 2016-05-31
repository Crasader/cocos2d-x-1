//
//  GameLayer.hpp
//  fruitAndbird
//
//  Created by zwj on 16/5/27.
//
//

#ifndef GameLayer_hpp
#define GameLayer_hpp

#include <stdio.h>
#include "GameSceneManager.hpp"
USING_NS_CC;

class gameLayer:public Layer
{
    
public:
    virtual bool init();
    int random();
    CREATE_FUNC(gameLayer);
    void menuCallBack0(Ref* pSender);
    void menuCallBack1(Ref* pSender);
    void menuCallBack2(Ref* pSender);
    void initTitle();
    
    
public:
    Sprite* backGround;
    GameSceneManager *sceneManager;
    NodeGrid* effecNode;
};
#endif /* GameLayer_hpp */
