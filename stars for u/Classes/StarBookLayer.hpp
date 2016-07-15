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
    //age按钮的回调
    void label0Callback(Ref* pSender);
    void label10Callback(Ref* pSender);
      void label15Callback(Ref* pSender);
      void label20Callback(Ref* pSender);
    void label25Callback(Ref* pSender);
    
    
    //商店回调
    void shopCallBack(Ref* pSender);

    //开始游戏回调
    void startGame();
    //书签的menu
    Menu* menu;
   // Sprite* diary;
    Label* labelText;
    
    //获得的星座
    void setGetedConsent(int i);
    void getAllgetedConsetn();
    int getedCon[30]={0};
    //所有的星座在book上的精灵
    Vector<Sprite*> conllenVecetor;

    
    //按钮显示优先级
    int markIndex=50;
    
    //日记打字效果回调
    void  textOut(float dt);
    int textIndex=0;
    std::string dirayString="";
    std::string  textStr;
    std::string age0String;
    std::string age10String;
    std::string age15String;
    std::string age20String;
    std::string age25String;
    
    //触摸
    bool onTouchBegan(Touch* touch,Event *event);
    int touchArr[12];
    void useCallBack(Ref* pSender);
    void okCallBack(Ref* pSender);
    int  showCon;
    Sprite* conllentSpriteShow;
     std::string etextString;
    Label*etextLabel;
 
};

#endif /* StarBookLayer_hpp */
