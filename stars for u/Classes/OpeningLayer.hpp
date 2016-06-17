//
//  OpeningLayer.hpp
//  MyCppGame
//
//  Created by zwj on 16/6/16.
//
//

#ifndef OpeningLayer_hpp
#define OpeningLayer_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "GameSceneManager.hpp"
#include "randomStars.hpp"


USING_NS_CC;

class OpeningLayer:public Layer
{

public:
    
    virtual bool init();
    static OpeningLayer* create();
    
    GameSceneManager* gsm;

    //回调
    void goBookMenuCallBack(Ref* pSender);
    void goSettingCallBack(Ref* pSender);
    
    //星星
    randomStars* star=new randomStars(this,10,6,0);
    


};


#endif /* OpeningLayer_hpp */
