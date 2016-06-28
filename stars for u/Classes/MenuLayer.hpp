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
#include <string>
USING_NS_CC;

class MenuLayer:public Layer
{
public:
    MenuLayer(int starNum, int ShineStarNum,int collNum);
    Size size;
    virtual  bool init();
    static  MenuLayer* create(int starNum,int shinStarNum,int collNum);
    
    
    //亲密值
    int Relation;
 
    
    //成长值
    int growth;
   
    
    //星星传入参数
    int starNum=0;
    int shineStarNum=0;
    //星座号,0为没有
    int collensation=0;
    bool conllGeted=false;
    
    //星星 ,传入 层，星星数量，闪烁数量
    randomStars* stars;
    

    //场景管理器
    GameSceneManager* gsm;
    
    //触摸方法
    virtual bool onTouchBegan(Touch* touch,Event* event);

    //指示线条
    DrawNode* line;
    int lineNum;
    
    //pointer直向一颗星星
    Sprite* pointer;
    void pointToStar();
    
    //提示线的出现
    bool lineShow=false;
    
   
    //时间到，显示数量
    void timeOver();
    int score=0;
    
    //talingBox
    Sprite* talkingBox;
    Label* talkingLabel;
    std::string talkingString;
    std::string talkingStr;
    void talkingBoxFunc(float dt);
    int index=0;
    
    //第1关提示
    void info(int starNum);
    
    //写入plist获取的星座
    void writToPlist();
    
    //定时器
    void timerFunc(float dt);
    //沙滩背景，以显示月亮落下海平面的效果
    Sprite* backGround2;
};

#endif /* MenuLayer_hpp */
