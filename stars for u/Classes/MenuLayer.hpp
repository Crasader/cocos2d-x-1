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
    MenuLayer(int starNum, int ShineStarNum);
    Size size;
    virtual  bool init();
    static  MenuLayer* create(int starNum,int shinStarNum);
    
    //星星传入参数
    int starNum=0;
    int shineStarNum=0;
    
    //星星 ,传入 层，星星数量，闪烁数量
    randomStars* stars;

    //场景管理器
    GameSceneManager* gsm;
    
    //触摸方法
    virtual bool onTouchBegan(Touch* touch,Event* event);

    //指示线条
    DrawNode* line;
    
    //pointer直向一颗星星
    Sprite* pointer;
    void pointToStar();
    
    //提示线的出现
    int lineCount=1;
    bool lineShow=false;

};

#endif /* MenuLayer_hpp */
