//
//  gameLayer.hpp
//  practice
//
//  Created by zwj on 16/5/20.
//
//

#ifndef gameLayer_hpp
#define gameLayer_hpp

#include <stdio.h>
#include <cocos2d.h>
#include "SceneManger.hpp"
#include "baseRole.hpp"
#include "rocker.hpp"
USING_NS_CC;

class gameLayer:public Layer
{
public:
   // CREATE_FUNC(gameLayer);
    static gameLayer* create();
    virtual bool init();
    SceneManager *tsm;
    baseRole *hero;
    rocker *rocker0;

    void update(float dt);
    
};

#endif /* gameLayer_hpp */
