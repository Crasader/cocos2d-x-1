//
//  HelpLayer.hpp
//  fruitAndbird
//
//  Created by zwj on 16/5/27.
//
//

#ifndef HelpLayer_hpp
#define HelpLayer_hpp

#include <stdio.h>
#include <cocos2d.h>
#include "GameSceneManager.hpp"
USING_NS_CC;

class helpLayer:public Layer
{

    public:
    CREATE_FUNC(helpLayer);
    GameSceneManager *sceneManager;

};
#endif /* HelpLayer_hpp */
