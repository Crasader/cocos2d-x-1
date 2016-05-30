//
//  HelpLayer.hpp
//  fruitAndbird
//
//  Created by zwj on 16/5/27.
//
//

#ifndef HelpLayer_hpp
#define HelpLayer_hpp

#include <stdio.h>
#include <cocos2d.h>
#include "GameSceneManager.hpp"
USING_NS_CC;

class helpLayer:public Layer
{

public:
    Sprite* sp[4];
    int index=0;
    Point beganPoint=Point(0,0);
    Point endPoint=Point(0,0);
    bool moveFlag=false;
    CREATE_FUNC(helpLayer);
    GameSceneManager *sceneManager;

    
public:
    virtual bool init();
    void menuCallBack(Ref* pSender);
    bool onTouchBegan(Touch *touch,Event *event);
    void onTouchEnded(Touch *touch,Event *event);
    void setmoveFlag();

};
#endif /* HelpLayer_hpp */
