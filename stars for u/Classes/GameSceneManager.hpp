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
    
    //starNum ：星星数量， ShinestarNum闪闪数量，collNUm：星座号
    void goMenuLayer(int starNum,int shinStarNum,int collNum);
    
    void goBookLayer();
    void goSettingLayer();
    void goinfoLayer(int starNum,int shinStarNum,int collNum);
    void goLadderLayer(int windNum, int cloudNum);
    
  

};

#endif /* GameSceneManager_hpp */
