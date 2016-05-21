//
//  openLayer.cpp
//  practice
//
//  Created by zwj on 16/5/19.
//
//

#include "openLayer.hpp"
bool openLayer::init()
{
    Size winSize=Director::getInstance()->getWinSize();
    
    Label *label=Label::create("时钟", "Courier", 48);
    label->setPosition(winSize.width/2,winSize.height*3/4);
    addChild(label);
    
    auto menuItem=MenuItemLabel::create(Label::create("go", "", 30), CC_CALLBACK_1(openLayer::goToClock, this) );
    menuItem->setTag(101);
    menuItem->setPosition(winSize.width/2,winSize.height/2);
    auto mu=Menu::create(menuItem, NULL);
    mu->setPosition(0,0);
    addChild(mu);

    return true;
}
void openLayer::goToClock(cocos2d::Ref *pSender)
{
    
    tsm->goClockScecne();
    


}