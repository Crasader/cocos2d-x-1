//
//  HelpLayer.cpp
//  fruitAndbird
//
//  Created by zwj on 16/5/27.
//
//

#include "HelpLayer.hpp"

bool helpLayer::init()
{
    if (!Layer::init()) {
        return false;
    }

    Size visibleSize=Director::getInstance()->getVisibleSize();
    Point origin=Director::getInstance()->getVisibleOrigin();
    
    Sprite* backGround=Sprite::create("morning.png");
    backGround->setAnchorPoint(Point(0,0));
    backGround->setPosition(Point(origin.x,origin.y+visibleSize.height-backGround->getContentSize().height));
    this->addChild(backGround,0);
    
    Sprite* floor=Sprite::create("floor.png");
    floor->setAnchorPoint(Point(0,0));
    floor->setPosition(origin.x,origin.y);
    this->addChild(floor);
    floor->runAction(RepeatForever::create(Sequence::create(MoveTo::create(0.5, Point(-120,0)),MoveTo::create(0, Point(0,0)), NULL)));
    
    Sprite*back=Sprite::create("helpBack.png");
    back->setPosition(Point(visibleSize.width/2,visibleSize.height/2-5));
    this->addChild(back,0);
    
    for (int i=0; i<4; i++)
    {
        sp[i]=Sprite::create(StringUtils::format("help%d.png",i));
        sp[i]->setPosition(180+i*360,320);
        if (i!=0) {
            sp[i]->runAction(FadeOut::create(0));
        }
    
    }
    
    MenuItemImage* menuItem=MenuItemImage::create("menu.png", "menu_off.png", CC_CALLBACK_1(helpLayer::menuCallBack, this));
    
    menuItem->setPosition(Point(270,50));
    Menu *menu=Menu::create(menuItem, NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu);
    
    Point pp[4];
    pp[0]=Point(0,0);
    pp[1]=Point(360,0);
    pp[2]=Point(360,640);
    pp[3]=Point(0,640);
    Color4F green(0,1,0,0);
    Color4F red(1,0,0,0);
    
    //裁切图像
    DrawNode* shape=DrawNode::create();
    shape->drawPolygon(pp, 4, green, 1, red);
    
    ClippingNode* clipper=ClippingNode::create();
    clipper->setStencil(shape);  //裁剪模版
    for (int i=0; i<4; i++) {
        
        clipper->addChild(sp[i],0);
        
    }
    clipper->setPosition(Point(90,160));
    this->addChild(clipper,0);
    
    
    EventListenerTouchOneByOne *listener= EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true);
    listener->onTouchBegan=CC_CALLBACK_2(helpLayer::onTouchBegan, this);
    listener->onTouchEnded=CC_CALLBACK_2(helpLayer::onTouchEnded, this);
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, clipper);
    
    
    
    
    return  true;
}
void helpLayer::menuCallBack(cocos2d::Ref *pSender)
{
    sceneManager->goToMainScene();
}

void helpLayer::setmoveFlag()
{
    moveFlag=false;
    if(beganPoint.x-endPoint.x>=30)
    {
        if(index+1>3)
        {
            sp[0]->setPosition(Point(540,320));
        }else
        {
            sp[index+1]->setPosition(Point(540,320));
        }
    }
    
    if(endPoint.x-beganPoint.x>=30)
    {
        if(index-1<0)
        {
            sp[3]->setPosition(Point(-180,320));
        }else
        {
            sp[index-1]->setPosition(Point(-180,320));
        }
    }
    
    
}

bool helpLayer::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event)
{
    if (moveFlag) {
        return  false;
    }
    auto target=static_cast<Sprite*>(event->getCurrentTarget());
    auto location=target->convertToNodeSpace(touch->getLocation());
    beganPoint=location;
    
    return true;
}
void helpLayer::onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *event)
{
    do {
        
        if (moveFlag) {
            break;
        }
        
        auto target=static_cast<Sprite*>(event->getCurrentTarget());
        auto location=target->convertToNodeSpace(touch->getLocation());
        endPoint=location;
        if (beganPoint.x-endPoint.x>=30)
        {
            index++;
            if (index>3)
            {
                index=0;
                sp[0]->setPosition(Point(540,320));
                sp[0]->runAction(FadeOut::create(0));
            }
            sp[index]->setPosition(Point(540,320));
            moveFlag=true;
            for (int i=0; i<3; i++)
            {
            
                if (i==index)
                {
                    sp[i]->runAction(Spawn::create(MoveBy::create(1, Point(-360,0)),FadeIn::create(1), NULL));
    
                }
                if (i==index-1)
                {
                    sp[i]->runAction(Spawn::create(MoveBy::create(1, Point(-360,0)),FadeOut::create(1), NULL));
                }
//                if (i==index+1)
//                {
//                    sp[i]->runAction(Spawn::create(MoveBy::create(1, Point(-360,0)),FadeOut::create(1), NULL));
//                }
                
            }
            
            
        
        sp[3]->runAction(Sequence::create(Spawn::create(MoveBy::create(1,Point(-360,0)), FadeIn::create(1), NULL),CallFunc::create(CC_CALLBACK_0(helpLayer::setmoveFlag, this)), NULL));
    }
        else if(endPoint.x-beganPoint.x>=30)
        {
            index--;
            if(index<0)
            {
                index = 3;
                sp[3]->setPosition(Point(-180,320));
            }
            sp[index]->setPosition(Point(-180,320));
            moveFlag=true;
            for(int i=3;i>0;i--)
            {
                if(i == index)
                {
                    sp[i]->runAction(
                                     Spawn::create(
                                                   MoveBy::create(1,Point(360,0)),
                                                   FadeIn::create(1),
                                                   NULL
                                                   ));
                }
                if(i == index + 1)
                {
                    sp[i]->runAction(
                                     Spawn::create(
                                                   MoveBy::create(1,Point(360,0)),
                                                   FadeOut::create(1),
                                                   NULL
                                                   ));
                }
                if(i == index - 1)
                {
                    sp[i]->runAction(
                                     Spawn::create(
                                                   MoveBy::create(1,Point(360,0)),
                                                   FadeOut::create(1),
                                                   NULL
                                                   ));
                }
            }
            sp[0]->runAction(
                             Sequence::create(
                                              Spawn::create(MoveBy::create(1,Point(360,0)), FadeIn::create(1),NULL),
                                              CallFunc::create(CC_CALLBACK_0(helpLayer::setmoveFlag, this)),
                                              NULL
                                              ));
        }
        
    }
    while (0);
    
    
}