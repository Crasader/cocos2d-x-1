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
   size=Director::getInstance()->getVisibleSize();
    
    //背景
    Sprite* backGround=Sprite::create("bg.png");
    backGround->setPosition(size.width/2,size.height/2);
    backGround->setScale(1.2);
    this->addChild(backGround,0);
    

    //布置星星
    stars->randomPosition();
    
    //MAN
    Sprite* man=Sprite::create("man2.png");
    man->setPosition(100,100);
    man->setScale(0.8f);
    this->addChild(man);
    
 
    
    //boy
    Sprite* boy=Sprite::create("boy-hand.png");
    boy->setPosition(200,100);
    boy->setScale(0.8f);
    this->addChild(boy);
    
    //hand
    pointer=Sprite::create("hand.png");
    pointer->setAnchorPoint(Point(0,0.5));
    pointer->setScale(1.5);
    pointer->setPosition(215,95);
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
    //始终指向0号星星
        iter=stars->starsVector.begin();
        if ((*iter)->getBoundingBox().containsPoint(touchPoint))
        {
           
           //若点在星星上，则移除此星星
            //移除特效
            auto act1=MoveTo::create(1.0f, Point(size.width/2,size.height/2));
            auto act2=ScaleTo::create(1.0f, 3.0f);
            
            //爆炸效果
            auto act3=ParticleExplosion::create();
            act3->setPosition(Point::ZERO);
            act3->setLife(1.0f);
            act3->setScale(0.2f);
       
            (*iter)->addChild(act3);
            
            //EASESINEOUT:正弦加速
            (*iter)->runAction(Sequence::create(EaseSineOut::create(Spawn::create(act1,act2, NULL)),RemoveSelf::create(), NULL));
            
            
            
      
            
            //iter仍然指向0号元素
            iter=stars->starsVector.erase(iter);
            pointer->setRotation(0);
            pointToStar();
        }
    
   // }
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