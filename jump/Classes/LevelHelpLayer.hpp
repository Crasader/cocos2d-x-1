//
//  LevelHelpLayer.hpp
//  jump
//
//  Created by zwj on 16/6/9.
//
//

#ifndef LevelHelpLayer_hpp
#define LevelHelpLayer_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "SpriteManager.hpp"
USING_NS_CC;


class LevelHelpLayer
{

public:
    LevelHelpLayer(Layer* layerIn);
    SpriteManager* sh;
    void initCreateSp();
    bool JudgeSp(Sprite* sp);
    void changeLevel(int  levelNum, int direction);
    void moveEffect(int dirction);
    
    Layer* layer;
    



};

#endif /* LevelHelpLayer_hpp */
