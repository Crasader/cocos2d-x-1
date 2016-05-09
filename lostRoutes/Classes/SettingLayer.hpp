//
//  SettingLayer.hpp
//  lostRoutes
//
//  Created by zwj on 16/5/6.
//
//

#ifndef SettingLayer_hpp
#define SettingLayer_hpp
#include "BaseLayer.hpp"
#include "SystemHeader.hpp"
#include "cocos2d.h"

#include <stdio.h>


class SettingLayer:public BaseLayer
{


public:
    virtual bool init();
    
    static Scene *creatScene();
    
    CREATE_FUNC(SettingLayer);
    

};



#endif /* SettingLayer_hpp */
