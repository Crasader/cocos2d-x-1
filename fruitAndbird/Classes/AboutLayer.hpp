//
//  AboutLayer.hpp
//  fruitAndbird
//
//  Created by zwj on 16/5/27.
//
//

#ifndef AboutLayer_hpp
#define AboutLayer_hpp

#include <stdio.h>
#include "GameSceneManager.hpp"
USING_NS_CC;

class aboutLayer:public Layer
{
public:
    
    CREATE_FUNC(aboutLayer);
    GameSceneManager *sceneManager;
    
public:
    virtual bool init();
    void menuCallBack(Ref* pSender);
    
    
};
#endif /* AboutLayer_hpp */
