//
//  StarBookLayer.hpp
//  MyCppGame
//
//  Created by zwj on 16/6/16.
//
//

#ifndef StarBookLayer_hpp
#define StarBookLayer_hpp

#include <stdio.h>
#include "GameSceneManager.hpp"
#include "cocos2d.h"

USING_NS_CC;

class StarBookLayer:public Layer
{

public:
    virtual bool init();
    static StarBookLayer* create();
    
    GameSceneManager* gsm;
    Size size;

    
    //bookMark选关
    void BookMark(int i);
    
    //进度
    int age=0;
    
    //bookSprite
    Sprite* bookSprite;
    
    
   //回调
    void label0Callback(Ref* pSender);
    //书签的menu
    Menu* menu;
     
};

#endif /* StarBookLayer_hpp */
