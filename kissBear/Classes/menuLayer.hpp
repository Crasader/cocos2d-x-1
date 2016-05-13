//
//  menuLayer.hpp
//  kissBear
//
//  Created by zwj on 16/5/10.
//
//

#ifndef menuLayer_hpp
#define menuLayer_hpp

#include <stdio.h>
#include <cocos2d.h>
#include "HelloWorldScene.h"
USING_NS_CC;
class menuLayer:public Layer
{
public:
   static Scene *createScene();
    virtual bool init();
    CREATE_FUNC(menuLayer);
    void go();
    
};



#endif /* menuLayer_hpp */
