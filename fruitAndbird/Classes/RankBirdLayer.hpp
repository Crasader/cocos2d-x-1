//
//  RankBirdLayer.hpp
//  fruitAndbird
//
//  Created by zwj on 16/5/27.
//
//

#ifndef RankBirdLayer_hpp
#define RankBirdLayer_hpp

#include <stdio.h>
#include "GameSceneManager.hpp"
USING_NS_CC;

class rankBirdLayer:public Layer
{
    public:
    
    CREATE_FUNC(rankBirdLayer);
    GameSceneManager *sceneManager;
    
};
#endif /* RankBirdLayer_hpp */
