//
//  GameSceneManager.hpp
//  MyCppGame
//
//  Created by zwj on 16/6/13.
//
//

#ifndef GameSceneManager_hpp
#define GameSceneManager_hpp

#include <stdio.h>
#include "cocos2d.h"

USING_NS_CC;
class GameSceneManager
{
public:
    
    static void createOpeningLayer();
    void goMenuLayer();
    void goBookLayer();
    void goSettingLayer();

};

#endif /* GameSceneManager_hpp */
