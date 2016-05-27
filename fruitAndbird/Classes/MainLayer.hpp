//
//  MainLayer.hpp
//  fruitAndbird
//
//  Created by zwj on 16/5/27.
//
//

#ifndef MainLayer_hpp
#define MainLayer_hpp

#include <stdio.h>
#include <cocos2d.h>
#include "GameSceneManager.hpp"
USING_NS_CC;
class MainLayer:public Layer
{

public:
    virtual bool init();
    CREATE_FUNC(MainLayer);
    
    GameSceneManager *sceneManager;

};
#endif /* MainLayer_hpp */
