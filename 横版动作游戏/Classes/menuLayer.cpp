
//
//  menuLayer.cpp
//  practice
//
//  Created by zwj on 16/5/20.
//
//

#include "menuLayer.hpp"
bool menuLayer::init()
{
    
    auto goMenu=MenuItemFont::create("go", CC_CALLBACK_0(menuLayer::gotoGameLayer, this));
    goMenu->setPosition(200,200);
    auto menu=Menu::create(goMenu, NULL);
    menu->setPosition(0,0);
    this->addChild(menu);
    
    

    return true;
}
void menuLayer::gotoGameLayer()
{

    tsm->toGameScene();

}