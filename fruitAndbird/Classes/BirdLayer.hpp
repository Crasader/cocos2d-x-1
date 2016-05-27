//
//  BirdLayer.hpp
//  fruitAndbird
//
//  Created by zwj on 16/5/27.
//
//

#ifndef BirdLayer_hpp
#define BirdLayer_hpp

#include <stdio.h>
#include "GameSceneManager.hpp"
USING_NS_CC;

class birdLayer:public Layer
{
public:
    
    CREATE_FUNC(birdLayer);
    GameSceneManager *sceneManager;
    
};
#endif /* BirdLayer_hpp */
