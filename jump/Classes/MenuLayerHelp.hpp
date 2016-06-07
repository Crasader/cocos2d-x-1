//
//  MenuLayerHelp.hpp
//  jump
//
//  Created by zwj on 16/6/6.
//
//

#ifndef MenuLayerHelp_hpp
#define MenuLayerHelp_hpp

#include <stdio.h>
#include <cocos2d.h>
#include "extensions/cocos-ext.h"
#include "Constant.h"
#include "SpriteManager.hpp"

USING_NS_CC;
using namespace extension;

class MenuLayerHelp
{

public:
    MenuLayerHelp(Layer* layerIn);
    void initCreateSprite();
    bool JudgeSp(Sprite* sp);
public:
    Layer* layer;
    SpriteManager* sh;


};

#endif /* MenuLayerHelp_hpp */
