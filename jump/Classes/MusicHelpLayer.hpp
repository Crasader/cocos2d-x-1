//
//  MusicHelpLayer.hpp
//  jump
//
//  Created by zwj on 16/6/9.
//
//

#ifndef MusicHelpLayer_hpp
#define MusicHelpLayer_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "SpriteManager.hpp"
#include "simpleAudioEngine.h"

USING_NS_CC;
using namespace CocosDenshion;

class MusicHelpLayer
{

public:
    MusicHelpLayer(Layer* layerIn);
    SpriteManager* sh;
    Layer* layer;
    void initCreateSprite();
    bool JudgeSp(Sprite* sp);
    


};


#endif /* MusicHelpLayer_hpp */
