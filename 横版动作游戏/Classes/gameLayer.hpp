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
USING_NS_CC;

class gameLayer:public Layer
{
public:
    CREATE_FUNC(gameLayer);
    virtual bool init();
    SceneManager *tsm;

};

#endif /* gameLayer_hpp */
