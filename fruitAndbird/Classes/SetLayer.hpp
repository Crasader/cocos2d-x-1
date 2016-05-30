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
#include "cocos2d.h"
#include "ui/CocosGUI.h"

USING_NS_CC;
using namespace ui;

class setLayer:public Layer
{
    
public:
    CREATE_FUNC(setLayer);
    GameSceneManager *sceneManager;
public:
    virtual bool init();
    void menuCallBack(Ref* pSender);
    void selectedEvent0(Ref *pSender, CheckBox::EventType type);
    void selectedEvent1(Ref *pSender,CheckBox::EventType type);
    
};
#endif /* SetLayer_hpp */
