//
//  MainLayer.hpp
//  fruitAndbird
//
//  Created by zwj on 16/5/27.
//
//

#ifndef MainLayer_hpp
#define MainLayer_hpp

#include <stdio.h>
#include <cocos2d.h>
#include "GameSceneManager.hpp"
USING_NS_CC;
class MainLayer:public Layer
{

public:
    virtual bool init();
    int random();
    void initSound();
    void menuCallBack0(Ref *pSender);
    void menuCallBack1(Ref *pSender);
    void menuCallBack2(Ref *pSender);
    void menuCallBack3(Ref *pSender);
    void menuCallBack4(Ref *pSender);
    void menuCallBack5(Ref *pSender);
    void initTitle();
    CREATE_FUNC(MainLayer);
    
public:
    Sprite *backGround;
    NodeGrid *effectNode;
    static bool musicFlag;
    static bool soundFlag;
    GameSceneManager *sceneManager;

};
#endif /* MainLayer_hpp */
