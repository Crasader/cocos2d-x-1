//
//  operateLayer.cpp
//  practice
//
//  Created by zwj on 16/5/21.
//
//

#include "operateLayer.hpp"

bool operateLayer::init()
{

    Button *button =Button::create();
    button->loadTextures("CloseNormal.png", "CloseSelected.png");
    button->setPosition(Point(200,600));
    
    button->addTouchEventListener(this,toucheventselector(operateLayer::callBack));
    
    this->addChild(button);
    

    return  true;
}


void operateLayer::callBack(cocos2d::Ref *pSender, TouchEventType type)
{


    if (type == TouchEventType::TOUCH_EVENT_ENDED) {
        
        log("touched");
    }

}