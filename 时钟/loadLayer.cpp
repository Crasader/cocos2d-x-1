//
//  loadLayer.cpp
//  practice
//
//  Created by zwj on 16/5/19.
//
//

#include "loadLayer.hpp"
bool loadLayer::init()
{
    Label *label=Label::create("加载中","Courier",32);
    label->setPosition(200,400);
    addChild(label);
    scheduleOnce(schedule_selector(loadLayer::onScheduleOnce), 2.0);


    return true;
}

void loadLayer::onScheduleOnce(float dt)
{

    tsm->goOpenScene();



}