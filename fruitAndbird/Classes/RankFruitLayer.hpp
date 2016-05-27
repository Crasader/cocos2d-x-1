//
//  RankFruitLayer.hpp
//  fruitAndbird
//
//  Created by zwj on 16/5/27.
//
//

#ifndef RankFruitLayer_hpp
#define RankFruitLayer_hpp

#include <stdio.h>
#include "GameSceneManager.hpp"
USING_NS_CC;

class ranFruitLayer:public Layer
{
    
    public:
    CREATE_FUNC(ranFruitLayer);
    GameSceneManager *sceneManager;
    
};
#endif /* RankFruitLayer_hpp */
