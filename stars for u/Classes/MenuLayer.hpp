//
//  MenuLayer.hpp
//  MyCppGame
//
//  Created by zwj on 16/6/13.
//
//

#ifndef MenuLayer_hpp
#define MenuLayer_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "GameSceneManager.hpp"
#include "randomStars.hpp"
USING_NS_CC;

class MenuLayer:public Layer
{
public:
    
    virtual  bool init();
    static  MenuLayer* create();
    
    //星星
    randomStars* stars=new randomStars(this);

    //场景管理器
    GameSceneManager* gsm;
    
    //触摸方法
    virtual bool onTouchBegan(Touch* touch,Event* event);

    
    //pointer直向一颗星星
    Sprite* pointer;
    void pointToStar();

};

#endif /* MenuLayer_hpp */
