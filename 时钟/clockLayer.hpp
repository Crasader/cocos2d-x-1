//
//  clockLayer.hpp
//  practice
//
//  Created by zwj on 16/5/19.
//
//

#ifndef clockLayer_hpp
#define clockLayer_hpp

#include <stdio.h>
#include <cocos2d.h>
#include "SceneManager.hpp"

USING_NS_CC;

class clockLayer:public Layer
{

public:
    
    CREATE_FUNC(clockLayer);
    virtual bool init();

    void gotoMenu(Ref *pSender);
    
    void timeUpdate(float dt);
    int i=0;
    Sprite *hour;
    Sprite *minute;
    Sprite *second;
    Sprite *background;
    
    
    SceneManager *tsm;

};


#endif /* clockLayer_hpp */
