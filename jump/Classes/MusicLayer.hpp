//
//  MusicLayer.hpp
//  jump
//
//  Created by zwj on 16/6/9.
//
//

#ifndef MusicLayer_hpp
#define MusicLayer_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "SpriteManager.hpp"
#include "simpleAudioEngine.h"
#include "MusicHelpLayer.hpp"
#include "GameSceneManager.hpp"
USING_NS_CC;
using namespace CocosDenshion;


class MusicLayer:public Layer
{

public:
    GameSceneManager* tsm;
    SpriteManager* sh;
    MusicHelpLayer* mh;
    virtual bool init();
   // CREATE_FUNC(MusicLayer);
    static MusicLayer* create();


    
};



#endif /* MusicLayer_hpp */
