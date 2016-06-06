//
//  MenuLayer.hpp
//  jump
//
//  Created by zwj on 16/6/6.
//
//

#ifndef MenuLayer_hpp
#define MenuLayer_hpp

#include <stdio.h>
#include <cocos2d.h>
#include "GameSceneManager.hpp"
#include "SpriteManager.hpp"
#include "MenuLayerHelp.hpp"
USING_NS_CC;

class MenuLayer:public Layer
{


public:
    GameSceneManager* gsm;
    Size visibleSize;
    Point origin;
    Director* dircotor;
    SpriteManager* sh;
    MenuLayerHelp* mlh;
    virtual bool init();
    
    CREATE_FUNC(MenuLayer);

};

#endif /* MenuLayer_hpp */
