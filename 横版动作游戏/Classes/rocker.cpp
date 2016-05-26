//
//  rocker.cpp
//  practice
//
//  Created by zwj on 16/5/21.
//
//

#include "rocker.hpp"
#define PI 3.1415926

rocker *rocker::createRocker(const char *rockerImage, const char *rockerBgImage, cocos2d::Point positon)
{

    rocker *layer=rocker::create();
    
    if (layer) {
        layer->rockerInit(rockerImage,rockerBgImage,positon);
        return layer;
    }
    CC_SAFE_DELETE(layer);
    return nullptr;



}

void rocker::rockerInit(const char *image, const char *bgImage, cocos2d::Point position)
{

    auto rockerBg=Sprite::create(bgImage);
    rockerBg->setPosition(position);
    rockerBg->setVisible(false);
    this->addChild(rockerBg,0,tag_rockerBG);
    
    

    
    auto rocker=Sprite::create(image);
    rocker->setPosition(position);
    rocker->setVisible(false);
    this->addChild(rocker,0,tag_rocker);
    
    rockerBGPostion=position;
    rockerBGR=rockerBg->getContentSize().width/2;
    rockDirection=-1;
    isCanMove=false;
    
    
}

void rocker::startRocker(bool _isStopother)
{

    auto rocker= (Sprite *)this->getChildByTag(tag_rocker);
    rocker->setVisible(true);
    
    auto rockerBg=(Sprite *)this->getChildByTag(tag_rockerBG);
    rockerBg->setVisible(true);
    
    
    auto touchlistener=EventListenerTouchOneByOne::create();
    touchlistener->setSwallowTouches(true);
    touchlistener->onTouchBegan=CC_CALLBACK_2(rocker::onTouchBegan, this);
    touchlistener->onTouchMoved=CC_CALLBACK_2(rocker::onTouchMoved, this);
    touchlistener->onTouchEnded=CC_CALLBACK_2(rocker::onTouchEnded, this);
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchlistener, this);
}


void rocker::stopRocker()
{
    
    auto rocker= (Sprite *)this->getChildByTag(tag_rocker);
    rocker->setVisible(false);
    
    auto rockerBg=(Sprite *)this->getChildByTag(tag_rockerBG);
    rockerBg->setVisible(false);
    
    Director::getInstance()->getEventDispatcher()->removeEventListenersForTarget(this);


}

bool rocker::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event)
{

    
    Point point=touch->getLocation();
    auto rocker=(Sprite *)this->getChildByTag(tag_rocker);
    
    if (rocker->getBoundingBox().containsPoint(point)) {
        isCanMove=true;
        log("begin");
    }
    

    return true;
}

float  rocker::getRad(cocos2d::Point position1, cocos2d::Point pos2)
{


    float px1=position1.x;
    float py1=position1.y;
    float px2=pos2.x;
    float py2=pos2.y;

    float x=px2-px1;
    float y=py2-py1;
    float xie=sqrtf(powf(x, 2)+powf(y, 2));
    float cosAngle=x/xie;
    float rad=acosf(cosAngle);
    if (py2<py1) {
        rad=-rad;
    }

    return rad;

}

Point rocker::getAnglePosition(float r,float angle)
{


    return Point(r*cos(angle), r*sin(angle));
}
void rocker::onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *event)
{
    if (!isCanMove) {
        return;
    }
    Point point=touch->getLocationInView();
    auto rocker=(Sprite* )this->getChildByTag(tag_rocker);
    
    rockDirection=rocker_right;
    
    float angle=getRad(rockerBGPostion, point);
    if (sqrt(pow(rockerBGPostion.x-point.x, 2)+pow(rockerBGPostion.y-point.y, 2))>rockerBGR) {
        rocker->setPosition(ccpAdd(getAnglePosition(rockerBGR, angle), rockerBGPostion));
    }
    else
    {
            rocker->setPosition(point);
        }
    if (angle>=-PI/4 && angle<PI/4) {
        rockDirection=rocker_left;
        rockerRun=false;
    }
    else if(angle>=PI/4&&angle<3*PI/4)
    { rockDirection=rocker_up;
        }
    else if(angle>=3*PI/4&&angle<PI)
    { rockDirection=rocker_right;
        }
    else if(angle>=-3*PI/4&&angle<-PI/4)
    { rockDirection=rocker_down;
        }
}


void rocker::onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *event)
{
    

    if (!isCanMove) {
        return;
    }

    auto rocker= (Sprite *)this->getChildByTag(tag_rocker);
    rocker->stopAllActions();
    rocker->runAction(MoveTo::create(0.08, rockerBGPostion));
    isCanMove=false;
    auto rockerBg=(Sprite *)this->getChildByTag(tag_rockerBG);
    rockDirection=rocker_stay;

    
    

}


