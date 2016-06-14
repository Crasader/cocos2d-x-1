//
//  MenuLayer.cpp
//  MyCppGame
//
//  Created by zwj on 16/6/13.
//
//

#include "MenuLayer.hpp"
#include "randomStars.hpp"
#include <math.h>

//create()方法
MenuLayer* MenuLayer::create()
{

    MenuLayer* layer=new MenuLayer();
    
    if (layer&&layer->init())
    {
        layer->autorelease();
        return layer;
    }
    CC_SAFE_DELETE(layer);
    return nullptr;
}

//init()方法

bool MenuLayer::init()
{
    if (!Layer::init())
    {
        return false;
    }
    auto size=Director::getInstance()->getVisibleSize();
   


//布置星星类
        stars->randomPosition();
    
    
    
    //pointer
    pointer=Sprite::create("pointer.png");
    pointer->setAnchorPoint(Point(0,0.5));
    pointer->setPosition(480,100);
    this->addChild(pointer);
    pointToStar();

    //开启触摸
    setTouchEnabled(true);
    setSwallowsTouches(true);
    setTouchMode(kCCTouchesOneByOne);


    
    return true;
}
//触摸监控
bool MenuLayer::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event)
{
    
    //触摸点位置
    auto touchPoint=touch->getLocation();
    //vector指针
    std::vector<Sprite*>::iterator iter;
    
    if (stars->starsVector.empty())
    {
        return false;
    }
    
    //判断触摸点是否在星星上
    for (iter=stars->starsVector.begin(); iter!=stars->starsVector.end(); )
    {
        //测试指向0号星星
        if ((*iter)->getBoundingBox().containsPoint(touchPoint)&& (*iter)==stars->starsVector.at(0))
        {
           
           //若点在星星上，则移除此星星
            (*iter)->removeFromParent();
            iter=stars->starsVector.erase(iter);
            pointer->setRotation(0);
            pointToStar();
        }
        else
        {
        iter++;
        }
    }
    return false;
}

void MenuLayer::pointToStar()
{
    
    if (stars->starsVector.empty())
    {
        return ;
    }
    
    //星星的坐标
     //测试指向0号星星
    auto starToPoint= stars->starsVector.at(0)->getPosition();
    log("x=%lf,y=%lf\n",starToPoint.x,starToPoint.y);
    //正切
    
    log("pointerX=%lf,pointerY=%lf\n",pointer->getPosition().x,pointer->getPosition().y);
    double tanAngle=(starToPoint.y-pointer->getPosition().y)/(starToPoint.x-pointer->getPosition().x);
    log("tanAngle=%lf\n",tanAngle);
    //反正切
    double Angle=atan(tanAngle)*180/3.141592653;
    log("angle=%lf\n",Angle);
   
        //正数顺时针旋转节点，负数逆时针旋转节点。
    if (Angle<=0)
    {
        
         pointer->setRotation(-(180-fabs(Angle)));
    }
    if (Angle>=0)
    {
         pointer->setRotation(-Angle);
    }
   

    
   
}