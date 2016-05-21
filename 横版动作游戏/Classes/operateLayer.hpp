//
//  operateLayer.hpp
//  practice
//
//  Created by zwj on 16/5/21.
//
//

#ifndef operateLayer_hpp
#define operateLayer_hpp

#include <stdio.h>
#include <cocos2d.h>
#include <ui/CocosGUI.h>
using namespace cocos2d::ui;
USING_NS_CC;

class operateLayer:public Layer
{
public:
    virtual bool init();
    CREATE_FUNC(operateLayer);
    void callBack(Ref *pSender,TouchEventType type);

};
#endif /* operateLayer_hpp */
