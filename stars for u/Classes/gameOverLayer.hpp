//
//  gameOverLayer.hpp
//  MyCppGame
//
//  Created by zwj on 16/7/6.
//
//

#ifndef gameOverLayer_hpp
#define gameOverLayer_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "GameSceneManager.hpp"

USING_NS_CC;


class gameOverLayer:public Layer
{
public:
    
    virtual bool init();
    CREATE_FUNC(gameOverLayer);

    GameSceneManager* gsm;
    
    //字幕
    std::string labelString;
       std::string labelStr;
    int strIndex=0;
    Label* stringLabel;
    //获取的星座图标vector
    Vector<Sprite* > conllenVecetor;
    
    //label打字效果回调
    void labelUpdate(float dt);
    
    //ok回调
    void okCallBack();
    int index=0;
    void labelOverCallback();
    void labelOverCallback2();
    
    //
   Size size;
};
#endif /* gameOverLayer_hpp */
