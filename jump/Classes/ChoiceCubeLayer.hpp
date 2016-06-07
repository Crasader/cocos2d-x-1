//
//  ChoiceCubeLayer.hpp
//  jump
//
//  Created by zwj on 16/6/7.
//
//

#ifndef ChoiceCubeLayer_hpp
#define ChoiceCubeLayer_hpp

#include <stdio.h>
#include <cocos2d.h>
#include "GameSceneManager.hpp"
#include "SpriteManager.hpp"
#include "ChoiceCubeHelp.hpp"

class ChoiceCubeLayer:public Layer
{


public:
    GameSceneManager* gsm;
    Size visibleSize;
    Point origin;
    Director* director;
    ChoiceCubeHelp* cclh;
    virtual bool init();
    CREATE_FUNC(ChoiceCubeLayer);
    SpriteManager* sh;
    



};

#endif /* ChoiceCubeLayer_hpp */
