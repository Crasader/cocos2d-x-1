//
//  menuLayer.hpp
//  practice
//
//  Created by zwj on 16/5/20.
//
//

#ifndef menuLayer_hpp
#define menuLayer_hpp

#include <stdio.h>
#include <cocos2d.h>
#include "SceneManger.hpp"
#include "ui/CocosGUI.h"
#include "cocostudio/CocoStudio.h"
using namespace cocos2d::ui;
using namespace cocostudio;

USING_NS_CC;

class menuLayer:public Layer
{
public:
 
    CREATE_FUNC(menuLayer);
    virtual bool init();
    void gotoGameLayer();

    SceneManager *tsm;

};

#endif /* menuLayer_hpp */
