//
//  HomeMenuLayer.hpp
//  lostRoutes
//
//  Created by zwj on 16/5/6.
//
//

#ifndef HomeMenuLayer_hpp
#define HomeMenuLayer_hpp

#include "SystemHeader.hpp"
#include <stdio.h>
#include "SettingLayer.hpp"
#include "Game.hpp"


typedef enum {
    MenuItemStart,
    MentuItemSetting,
    MentuItemHelp

} ActionType;

class HomeMenuLayer:public Layer
{
public:
   static Scene *createScene();
    virtual bool init();
    virtual void onEnterTansitionDidFinish();
    
    void menuItemCallBack(Ref *pSender);
    
    CREATE_FUNC(HomeMenuLayer);
    


};

#endif /* HomeMenuLayer_hpp */
