//
//  loadLayer.hpp
//  practice
//
//  Created by zwj on 16/5/19.
//
//

#ifndef loadLayer_hpp
#define loadLayer_hpp

#include <stdio.h>
#include <cocos2d.h>
#include "SceneManager.hpp"
USING_NS_CC;


class loadLayer:public Layer
{
public:
    CREATE_FUNC(loadLayer);
    virtual bool init();

    void onScheduleOnce(float dt);
    
    
    SceneManager *tsm;

};

#endif /* loadLayer_hpp */
