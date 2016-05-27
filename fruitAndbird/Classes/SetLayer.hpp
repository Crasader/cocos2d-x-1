//
//  SetLayer.hpp
//  fruitAndbird
//
//  Created by zwj on 16/5/27.
//
//

#ifndef SetLayer_hpp
#define SetLayer_hpp

#include <stdio.h>
#include "GameSceneManager.hpp"
USING_NS_CC;

class setLayer:public Layer
{
    
    public:
    CREATE_FUNC(setLayer);
    GameSceneManager *sceneManager;
    
};
#endif /* SetLayer_hpp */
