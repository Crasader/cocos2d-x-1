//
//  SettingLayer.hpp
//  MyCppGame
//
//  Created by zwj on 16/6/16.
//
//

#ifndef SettingLayer_hpp
#define SettingLayer_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "GameSceneManager.hpp"

class SettingLayer:public Layer
{
public:

    virtual bool init();
    static SettingLayer* create();
    
    GameSceneManager* gsm;


    
    
};

#endif /* SettingLayer_hpp */
