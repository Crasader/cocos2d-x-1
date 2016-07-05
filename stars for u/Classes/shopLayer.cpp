//
//  shopLayer.cpp
//  MyCppGame
//
//  Created by zwj on 16/7/4.
//
//

#include "shopLayer.hpp"
#include "StarBookLayer.hpp"
#include <time.h>

//extern bool shopOn;


bool shopLayer::init()
{

    if (!Layer::init())
    {
        return false;
        
    }
    
    srand(unsigned(time(NULL)));
    
    auto size=Director::getInstance()->getVisibleSize();
    //大背景，透明
    auto bg2=Sprite::create("bg2.png");
    bg2->setPosition(size.width/2,size.height/2);
    this->addChild(bg2);
    bg2->setOpacity(100);
    
    //商店背景
     bg=Sprite::create("shop.png");
    //this->setContentSize(bg->getContentSize());
    bg->setPosition(size.width/2,size.height/2);
    bg->setTag(100);
    this->addChild(bg);
    
   //触摸监听，注册级别最高
    auto dispatcher=Director::getInstance()->getEventDispatcher();
     lisetener=EventListenerTouchOneByOne::create();
    lisetener->onTouchBegan=CC_CALLBACK_2(shopLayer::onTouchBegan, this);
    dispatcher->addEventListenerWithSceneGraphPriority(lisetener, this);
   // dispatcher->addEventListenerWithFixedPriority(lisetener, -100);
    lisetener->setSwallowTouches(true);
    
    this->setScale(0);
    
    //item
    
    //pointLabel
    relation=UserDefault::getInstance()->getIntegerForKey("RELATION", 0);
    
    char pointBuf[128];
    sprintf(pointBuf, "Relation Point:%d",relation);
    auto pointLabel=Label::createWithSystemFont(pointBuf, "Marker Felt.ttf", 30);
    pointLabel->setColor(Color3B::RED);
    pointLabel->setPosition(pointLabel->getContentSize().width-20,bg->getContentSize().height*0.85);
    bg->addChild(pointLabel);
  
    //talk
    auto talkLabel=Label::createWithSystemFont("Have a talk ", "Marker Felt.ttf", 30);
    talkLabel->setColor(Color3B::RED);
    auto talkButton=MenuItemLabel::create(talkLabel, CC_CALLBACK_1(shopLayer::talkCallBack, this));
    talkButton->setPosition(bg->getContentSize().width*0.2+20,bg->getContentSize().height*0.75);
    
    
    
    
    
    
    auto menu=Menu::create(talkButton,NULL);
    menu->setPosition(0,0);
    bg->addChild(menu);
    


    return true;
}

//触摸回调
bool shopLayer::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event)
{
    auto touchPoint=touch->getLocation();
    
    if (!(this->getChildByTag(100)->getBoundingBox().containsPoint(touchPoint)))
    {
       // shopOn=false;
        this->removeFromParentAndCleanup(true);
    }
    

    return true;
}



void shopLayer::onExit()
{
    Layer::onExit();
    
    //必须手动注销
    Director::getInstance()->getEventDispatcher()->removeEventListener(lisetener);
    
    
    log("onnnnnexit");
}


//
void shopLayer::talkCallBack(cocos2d::Ref *pSender)
{
    
    log("asdasd");
    auto talkingBox=Sprite::create("talkingBox_LL.png");
    talkingBox->setScale(0);
    talkingBox->setPosition(bg->getContentSize().width/2,bg->getContentSize().height/3+30);
    talkingBox->runAction(Sequence::create(ScaleTo::create(0.1, 0.4),
                                           ScaleTo::create(0.1, 0.8),
                                           ScaleTo::create(0.1,1.0),
                                           NULL));
    bg->addChild(talkingBox);
    
    
    
    

    //exam
    auto examLabel=Label::createWithSystemFont("exams(1)", "Marker Felt.ttf", 30);
    examLabel->setColor(Color3B::RED);
    auto examButton=MenuItemLabel::create(examLabel, CC_CALLBACK_1(shopLayer::examCallBack, this));
    examButton->setPosition(examButton->getContentSize().width+15,talkingBox->getContentSize().height-130);
    
    //friends
    auto firendsLabel=Label::createWithSystemFont("friends(2)", "Marker Felt.ttf", 30);
    firendsLabel->setColor(Color3B::RED);
    auto friendsButton=MenuItemLabel::create(firendsLabel, CC_CALLBACK_1(shopLayer::friendsCallBack, this));
    friendsButton->setPosition(friendsButton->getContentSize().width+10,talkingBox->getContentSize().height-170);


    //football
    
    auto footballLabel=Label::createWithSystemFont("football(5)", "Marker Felt.ttf", 30);
    footballLabel->setColor(Color3B::RED);
    auto footballButton=MenuItemLabel::create(footballLabel, CC_CALLBACK_1(shopLayer::footballCallBack, this));
    footballButton->setPosition(footballButton->getContentSize().width+10,talkingBox->getContentSize().height-170-40);
    
    
    
    
    auto menu=Menu::create(examButton,friendsButton, footballButton,NULL);
    menu->setPosition(0,0);
    talkingBox->addChild(menu);




}
//考试
void shopLayer::examCallBack(cocos2d::Ref *pSender)
{
    
    //不够提示
    if ((relation-5)<0)
    {
        auto tipsLabel=Label::createWithSystemFont("Not enough Points", "Marker Felt.ttf", 30);
        
        tipsLabel->setColor(Color3B::RED);
        tipsLabel->setPosition(bg->getPosition().x,50);
        tipsLabel->runAction(Sequence::create(Spawn::create(MoveBy::create(2.0, Point(0,50)),FadeOut::create(2.0), NULL),RemoveSelf::create(),NULL));
        this->addChild(tipsLabel);
        
        
        return;
    }

    UserDefault::getInstance()->setIntegerForKey("RELATION", relation-1);
    
    int EXAM=UserDefault::getInstance()->getIntegerForKey("EXAM", 0);
    
    UserDefault::getInstance()->setIntegerForKey("EXAM", ++EXAM);
    
   
    
    //消费提示
    std::string buf[5]={"exam1","exam2","exam3","exam4","exam5"};
    
    int index=random(0, 4);
    
    
    auto tipsLabel=Label::createWithSystemFont(buf[index], "Marker Felt.ttf", 30);

    tipsLabel->setColor(Color3B::RED);
    tipsLabel->setPosition(bg->getPosition().x,50);
    tipsLabel->runAction(Sequence::create(Spawn::create(MoveBy::create(2.0, Point(0,50)),FadeOut::create(2.0), NULL),RemoveSelf::create(),NULL));
    this->addChild(tipsLabel);
    
    

}
//朋友
void shopLayer::friendsCallBack(cocos2d::Ref *pSender)
{
    
    //不够提示
    if ((relation-5)<0)
    {
        auto tipsLabel=Label::createWithSystemFont("Not enough Points", "Marker Felt.ttf", 30);
        
        tipsLabel->setColor(Color3B::RED);
        tipsLabel->setPosition(bg->getPosition().x,50);
        tipsLabel->runAction(Sequence::create(Spawn::create(MoveBy::create(2.0, Point(0,50)),FadeOut::create(2.0), NULL),RemoveSelf::create(),NULL));
        this->addChild(tipsLabel);
        
        
        return;
    }

    UserDefault::getInstance()->setIntegerForKey("RELATION", relation-2);
    
    int FRIENDS=UserDefault::getInstance()->getIntegerForKey("FRIENDS", 0);
    
    UserDefault::getInstance()->setIntegerForKey("FRIENDS", ++FRIENDS);
    
    //消费提示
    std::string buf[5]={"friends1","friends2","friends3","friends4","friends5"};
    
    int index=random(0, 4);
    
    
    auto tipsLabel=Label::createWithSystemFont(buf[index], "Marker Felt.ttf", 30);
    
    tipsLabel->setColor(Color3B::RED);
    tipsLabel->setPosition(bg->getPosition().x,50);
    tipsLabel->runAction(Sequence::create(Spawn::create(MoveBy::create(2.0, Point(0,50)),FadeOut::create(2.0), NULL),RemoveSelf::create(),NULL));
    this->addChild(tipsLabel);


}


//足球
void shopLayer::footballCallBack(cocos2d::Ref *pSender)
{
    //不够提示
    if ((relation-5)<0)
    {
        auto tipsLabel=Label::createWithSystemFont("Not enough Points", "Marker Felt.ttf", 30);
        
        tipsLabel->setColor(Color3B::RED);
        tipsLabel->setPosition(bg->getPosition().x,50);
        tipsLabel->runAction(Sequence::create(Spawn::create(MoveBy::create(2.0, Point(0,50)),FadeOut::create(2.0), NULL),RemoveSelf::create(),NULL));
        this->addChild(tipsLabel);

        
        return;
    }
    
    UserDefault::getInstance()->setIntegerForKey("RELATION", relation-5);
    
    int FOOTBALL=UserDefault::getInstance()->getIntegerForKey("FOOTBALL", 0);
    
    UserDefault::getInstance()->setIntegerForKey("FOOTBALL", ++FOOTBALL);

    //消费提示
    std::string buf[5]={"FOOTBALL1","FOOTBALL2","FOOTBALL3","FOOTBALL4","FOOTBALL5"};
    
    int index=random(0, 4);
    
    
    auto tipsLabel=Label::createWithSystemFont(buf[index], "Marker Felt.ttf", 30);
    
    tipsLabel->setColor(Color3B::RED);
    tipsLabel->setPosition(bg->getPosition().x,50);
    tipsLabel->runAction(Sequence::create(Spawn::create(MoveBy::create(2.0, Point(0,50)),FadeOut::create(2.0), NULL),RemoveSelf::create(),NULL));
    this->addChild(tipsLabel);


}