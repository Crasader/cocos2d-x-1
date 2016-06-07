//
//  ChoiceCubeHelp.hpp
//  jump
//
//  Created by zwj on 16/6/7.
//
//

#ifndef ChoiceCubeHelp_hpp
#define ChoiceCubeHelp_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "SpriteManager.hpp"
#include "ParticlSystemHelp.hpp"

USING_NS_CC;

class ChoiceCubeHelp
{
    
public:
    ChoiceCubeHelp(Layer* layerIn);
    void initCreateSprite();
    bool JudgeSp(Sprite* sp);
    void saveData();
    void getData();
public:
    Layer* layer;
    SpriteManager* sh;
    int p1 = 779;
    int p2 = 110;
    int p3 = 30;
    int p4 = 30;
    int p11;
    int p12;
    int p13;
    int p14;
    
};

#endif /* ChoiceCubeHelp_hpp */
