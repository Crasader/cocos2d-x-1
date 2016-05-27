//
//  GameLayer.hpp
//  fruitAndbird
//
//  Created by zwj on 16/5/27.
//
//

#ifndef GameLayer_hpp
#define GameLayer_hpp

#include <stdio.h>
#include "GameSceneManager.hpp"
USING_NS_CC;

class gameLayer:public Layer
{
    
    public:
    CREATE_FUNC(gameLayer);
    GameSceneManager *sceneManager;
    
};
#endif /* GameLayer_hpp */
