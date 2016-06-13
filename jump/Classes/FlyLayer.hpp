//
//  FlyLayer.hpp
//  jump
//
//  Created by zwj on 16/6/11.
//
//

#ifndef FlyLayer_hpp
#define FlyLayer_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "GameSceneManager.hpp"
#include "SpriteManager.hpp"
#include "Barrier.hpp"
USING_NS_CC;

class FlyLayer:public Layer
{
public:
    GameSceneManager* gsm;
    SpriteManager* sh;
    bool isTouch;

    int timeCount;
    
    std::vector<Barrier*> barrierVector;
    CREATE_FUNC(FlyLayer);
};

#endif /* FlyLayer_hpp */
