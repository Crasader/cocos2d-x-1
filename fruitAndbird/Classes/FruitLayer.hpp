//
//  FruitLayer.hpp
//  fruitAndbird
//
//  Created by zwj on 16/5/27.
//
//

#ifndef FruitLayer_hpp
#define FruitLayer_hpp

#include <stdio.h>
#include "GameSceneManager.hpp"
USING_NS_CC;

class fruitLayer:public Layer
{
    public:
    
    CREATE_FUNC(fruitLayer);
    GameSceneManager *sceneManager;
    
};
#endif /* FruitLayer_hpp */
