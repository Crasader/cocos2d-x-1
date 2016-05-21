//
//  openLayer.hpp
//  practice
//
//  Created by zwj on 16/5/19.
//
//

#ifndef openLayer_hpp
#define openLayer_hpp

#include <stdio.h>
#include <cocos2d.h>
#include "SceneManager.hpp"
USING_NS_CC;

class openLayer:public Layer
{

public:
    CREATE_FUNC(openLayer);
    virtual bool init();
    void goToClock(Ref *pSender);

    SceneManager *tsm;

};
#endif /* openLayer_hpp */
