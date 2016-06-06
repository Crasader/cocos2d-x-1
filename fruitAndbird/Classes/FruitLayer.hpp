//
//  FruitLayer.hpp
//  fruitAndbird
//
//  Created by zwj on 16/5/27.
//
//

#ifndef FruitLayer_hpp
#define FruitLayer_hpp

#include <stdio.h>
#include "GameSceneManager.hpp"
#include "ui/CocosGUI.h"
#include "extensions/cocos-ext.h"

using namespace std;
USING_NS_CC;
using namespace cocos2d::extension;
using namespace ui;


class fruitLayer:public Layer
{
    public:
    
public:
    int count;
    int boss;
    bool stopFlag;
    bool bossFlag;
    bool gameFlag;
    bool readyFlag;
    bool overFlag;
    bool actionFlag;
    int height1;
    int height2;
    NodeGrid* effectNode;
    Sprite* bossSprite;
    //—™Ãı
    Slider* slider;
    LabelAtlas* pLabelAtlas;
    Sprite* overRank;
    MenuItemImage* relayItem;
    MenuItemImage* menuItem;
    Sprite* pauseBack;
    //…˘√˜‘›Õ£∞¥≈•æ´¡È
    Sprite* pause;
    //
    Sprite* ready;
    //…˘√˜±≥æ∞æ´¡È
    Sprite* background;
    //…˘√˜µÿ√Êæ´¡È
    Sprite* floor;
    //…˘√˜÷˘◊”æ´¡È
    Sprite* columnUnder1;
    Sprite* columnOn1;
    Sprite* columnUnder2;
    Sprite* columnOn2;
    //≥°æ∞π‹¿Ì÷∏’Î
    GameSceneManager* sceneManager;
    //¥Ê¥¢ÀÆπ˚∂‘œÛ
    vector<Sprite*>* fruit;
    
    
public:
    virtual bool init();
    //ø™ º”Œœ∑
    void startGame();
    //…˙≥…ÀÊª˙ ˝∑Ω∑®
    int random();
    //≥ı ºªØ÷˘◊”
    void initColumn1();
    void initColumn2();
    //”Œœ∑Ω· ¯
    void gameOver();
    //”Œœ∑ ß∞‹
    void replay();
    void check();
    void moveObject();
    //≤•∑≈“Ù–ß
    void wingSound();
    void eatSound();
    //∏¸∏ƒ±Í÷æŒª
    void setFlag();
    //∂® ±ªÿµ˜∑Ω∑®
    void update_fruit(float delta);
    void update_boss(float delta);
    void update_column(float delta);
    void menuCallback0(Ref* pSender);
    void menuCallback1(Ref* pSender);
    void menuCallback2(Ref* pSender);
    void menuCallback3(Ref* pSender);
    void menuCallback4(Ref* pSender);
    //∏¥—°øÚªÿµ˜∑Ω∑®
    void selectedEvent0(Ref* pSender,CheckBox::EventType type);
    void selectedEvent1(Ref* pSender,CheckBox::EventType type);
    //ø™ ºµ•µ„¥•øÿ ¬º˛µƒ¥¶¿Ì∑Ω∑®
    bool onTouchBegan(Touch* touch, Event* event);
    bool onTouchPause(Ref* pSender);
    CREATE_FUNC(fruitLayer);
    
};
#endif /* FruitLayer_hpp */
