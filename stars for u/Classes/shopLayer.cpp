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
    
    
    //测试用//////////////////
    
    UserDefault::getInstance()->setIntegerForKey("RELATION", 1000);
    
    //测试用
    
    
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
    
   //触摸监听，
    auto dispatcher=Director::getInstance()->getEventDispatcher();
     lisetener=EventListenerTouchOneByOne::create();
    lisetener->onTouchBegan=CC_CALLBACK_2(shopLayer::onTouchBegan, this);
    dispatcher->addEventListenerWithSceneGraphPriority(lisetener, this);
   // dispatcher->addEventListenerWithFixedPriority(lisetener, -100);//注册级别最高
    lisetener->setSwallowTouches(true);
    
    this->setScale(0);
    
    //item
    
    //pointLabel
    int relation=UserDefault::getInstance()->getIntegerForKey("RELATION", 0);
    
    char pointBuf[128];
    sprintf(pointBuf, "Relation Point:%d",relation);
     pointLabel=Label::createWithSystemFont(pointBuf, "Marker Felt.ttf", 30);
    pointLabel->setColor(Color3B::RED);
    pointLabel->setPosition(pointLabel->getContentSize().width-20,bg->getContentSize().height*0.85);
    bg->addChild(pointLabel);
  
    //talk
    auto talkLabel=Label::createWithSystemFont("Have a talk ", "Marker Felt.ttf", 40);
    talkLabel->setColor(Color3B::RED);
    auto talkButton=MenuItemLabel::create(talkLabel, CC_CALLBACK_1(shopLayer::talkCallBack, this));
    talkButton->setPosition(bg->getContentSize().width*0.2+40,bg->getContentSize().height*0.7);
    
    
    
    
    
    
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
    //Director::getInstance()->getEventDispatcher()->removeEventListener(lisetener);
    
    
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
    auto examLabel=Label::createWithSystemFont("exams(2)", "Marker Felt.ttf", 30);
    examLabel->setColor(Color3B::RED);
    auto examButton=MenuItemLabel::create(examLabel, CC_CALLBACK_1(shopLayer::examCallBack, this));
    examButton->setPosition(examButton->getContentSize().width,talkingBox->getContentSize().height-140);
    
    //friends
    auto firendsLabel=Label::createWithSystemFont("friends(2)", "Marker Felt.ttf", 30);
    firendsLabel->setColor(Color3B::RED);
    auto friendsButton=MenuItemLabel::create(firendsLabel, CC_CALLBACK_1(shopLayer::friendsCallBack, this));
    friendsButton->setPosition(friendsButton->getContentSize().width,talkingBox->getContentSize().height-200);


    //hobby
    
    auto footballLabel=Label::createWithSystemFont("hobby(5)", "Marker Felt.ttf", 30);
    footballLabel->setColor(Color3B::RED);
    auto footballButton=MenuItemLabel::create(footballLabel, CC_CALLBACK_1(shopLayer::footballCallBack, this));
    footballButton->setPosition(examButton->getContentSize().width+200,talkingBox->getContentSize().height-140);
    
    
    //family
    auto familylLabel=Label::createWithSystemFont("family(1)", "Marker Felt.ttf", 30);
    familylLabel->setColor(Color3B::RED);
    auto familyButton=MenuItemLabel::create(familylLabel, CC_CALLBACK_1(shopLayer::familyCallBack, this));
    familyButton->setPosition(familyButton->getContentSize().width+200,talkingBox->getContentSize().height-200);
    
    
    auto menu=Menu::create(examButton,friendsButton, footballButton,familyButton,NULL);
    menu->setPosition(0,0);
    talkingBox->addChild(menu);




}


//考试
void shopLayer::examCallBack(cocos2d::Ref *pSender)
{
    int relation=UserDefault::getInstance()->getIntegerForKey("RELATION", 0);
    
    //不够提示
    if ((relation-2)<0)
    {
        auto tipLabel=Label::createWithSystemFont("Not enough Points", "Marker Felt.ttf", 30);
        
        tipLabel->setColor(Color3B::RED);
        tipLabel->setPosition(bg->getPosition().x,60);
        tipLabel->runAction(Sequence::create(Spawn::create(MoveBy::create(2.0, Point(0,50)),FadeOut::create(2.0), NULL),RemoveSelf::create(),NULL));
        this->addChild(tipLabel);
        
        
        
    }
    
    else
    {
        
        
        //提示信息
        Label* tipsLabel=Label::createWithSystemFont("", "Marker Felt.ttf", 30);
        tipsLabel->setColor(Color3B::RED);
        tipsLabel->setPosition(bg->getPosition().x,60);
        
        
        //随机反应
        //喜欢的概率50， 不喜欢25，没反应25
        int index[4]={0,0,1,2};
        int react=random(0, 3);
        relation=relation-2;
         UserDefault::getInstance()->setIntegerForKey("RELATION", relation);
        
         int EXAM=UserDefault::getInstance()->getIntegerForKey("EXAM", 0);
        
        switch (index[react])
        {
                //喜欢
            case 0:
            {
                UserDefault::getInstance()->setIntegerForKey("EXAM", ++EXAM);
                
                //pointLabel
                char pointBuf[128];
                sprintf(pointBuf, "Relation Point:%d",relation);
                pointLabel->setString(pointBuf);
                
                //消费提示
                std::string buf="He seems to get something... \n  Learning Increased! ";
               // auto tipsLabel=Label::createWithSystemFont(buf, "Marker Felt.ttf", 30);
                tipsLabel->setString(buf);
//                tipsLabel->setColor(Color3B::RED);
//                tipsLabel->setPosition(bg->getPosition().x,50);
//                 tipsLabel->runAction(Sequence::create( DelayTime::create(2), Spawn::create(MoveBy::create(2.0, Point(0,50)),FadeOut::create(2.0), NULL),RemoveSelf::create(),NULL));
//                this->addChild(tipsLabel);

                break;
            }
                
                //没反应
                case 1:
            {
                // UserDefault::getInstance()->setIntegerForKey("EXAM", EXAM);
                
                
                //pointLabel
                char pointBuf[128];
                sprintf(pointBuf, "Relation Point:%d",relation);
                pointLabel->setString(pointBuf);
                
                //消费提示
                std::string buf="He has no reaction...  \n  Nothing happened.";
                
               
                
                
//                auto tipsLabel=Label::createWithSystemFont(buf, "Marker Felt.ttf", 30);
//                
//                tipsLabel->setColor(Color3B::RED);
//                tipsLabel->setPosition(bg->getPosition().x,50);
//               tipsLabel->runAction(Sequence::create( DelayTime::create(2), Spawn::create(MoveBy::create(2.0, Point(0,50)),FadeOut::create(2.0), NULL),RemoveSelf::create(),NULL));
//                this->addChild(tipsLabel);
                tipsLabel->setString(buf);
                
                break;
            }
                //讨厌
            case 2:
            {
                 UserDefault::getInstance()->setIntegerForKey("EXAM", --EXAM);
                UserDefault::getInstance()->setIntegerForKey("RELATION", relation-1);
                
                
                //pointLabel
                char pointBuf[128];
                sprintf(pointBuf, "Relation Point:%d",relation-1);
                pointLabel->setString(pointBuf);
                
                //消费提示
                std::string buf="He seems to be unhappy ... \n Learning Decreased!";
                
                
                
//                auto tipsLabel=Label::createWithSystemFont(buf, "Marker Felt.ttf", 30);
//                
//                tipsLabel->setColor(Color3B::RED);
//                tipsLabel->setPosition(bg->getPosition().x,50);
//                tipsLabel->runAction(Sequence::create( DelayTime::create(2), Spawn::create(MoveBy::create(2.0, Point(0,50)),FadeOut::create(2.0), NULL),RemoveSelf::create(),NULL));
//                this->addChild(tipsLabel);

                tipsLabel->setString(buf);
                
                break;
            }
                
            default:
                break;
        }
    

        tipsLabel->runAction(Sequence::create( DelayTime::create(2), Spawn::create(MoveBy::create(2.0, Point(0,50)),FadeOut::create(2.0), NULL),RemoveSelf::create(),NULL));
        this->addChild(tipsLabel);

        
    }

}

//朋友
void shopLayer::friendsCallBack(cocos2d::Ref *pSender)
{
    int relation=UserDefault::getInstance()->getIntegerForKey("RELATION", 0);
    
    //不够提示
    if ((relation-2)<0)
    {
        auto tipLabel=Label::createWithSystemFont("Not enough Points", "Marker Felt.ttf", 30);
        
        tipLabel->setColor(Color3B::RED);
        tipLabel->setPosition(bg->getPosition().x,60);
        tipLabel->runAction(Sequence::create(Spawn::create(MoveBy::create(2.0, Point(0,50)),FadeOut::create(2.0), NULL),RemoveSelf::create(),NULL));
        this->addChild(tipLabel);
        
        
        
    }
    
    else
    {
        //随机反应
        //喜欢的概率50， 不喜欢25，没反应25
        int index[5]={0,0,0,1,2};
        int react=random(0, 4);
        relation-=2;
        UserDefault::getInstance()->setIntegerForKey("RELATION", relation);
        
        int FRIENDS=UserDefault::getInstance()->getIntegerForKey("FRIENDS", 0);
        
        
        //提示信息
        Label* tipsLabel=Label::createWithSystemFont("", "Marker Felt.ttf", 30);
        tipsLabel->setColor(Color3B::RED);
         tipsLabel->setPosition(bg->getPosition().x,60);

        
        switch (index[react])
        {
                //喜欢
            case 0:
            {
                UserDefault::getInstance()->setIntegerForKey("FRIENDS", ++FRIENDS);
                
                //pointLabel
                char pointBuf[128];
                sprintf(pointBuf, "Relation Point:%d",relation);
                pointLabel->setString(pointBuf);
                
                //消费提示
                std::string buf="He talks a lot about the topic! \n Communication Increased!";
                
                
                tipsLabel->setString(buf);
//                auto tipsLabel=Label::createWithSystemFont(buf, "Marker Felt.ttf", 30);
//                
//                tipsLabel->setColor(Color3B::RED);
//                tipsLabel->setPosition(bg->getPosition().x,50);
//                 tipsLabel->runAction(Sequence::create( DelayTime::create(2), Spawn::create(MoveBy::create(2.0, Point(0,50)),FadeOut::create(2.0), NULL),RemoveSelf::create(),NULL));
//                this->addChild(tipsLabel);
                
                break;
            }
                
                //没反应
            case 1:
            {

                
                
                //pointLabel
                char pointBuf[128];
                sprintf(pointBuf, "Relation Point:%d",relation);
                pointLabel->setString(pointBuf);
                
                //消费提示
                std::string buf="He has no interesting ...\n Nothing Happened.";
                
            
                  tipsLabel->setString(buf);
                
//                auto tipsLabel=Label::createWithSystemFont(buf, "Marker Felt.ttf", 30);
//                
//                tipsLabel->setColor(Color3B::RED);
//                tipsLabel->setPosition(bg->getPosition().x,50);
//                tipsLabel->runAction(Sequence::create( DelayTime::create(2), Spawn::create(MoveBy::create(2.0, Point(0,50)),FadeOut::create(2.0), NULL),RemoveSelf::create(),NULL));
//                this->addChild(tipsLabel);
                
                
                break;
            }
                //讨厌
            case 2:
            {
                UserDefault::getInstance()->setIntegerForKey("FRIENDS", --FRIENDS);
                UserDefault::getInstance()->setIntegerForKey("RELATION", relation-2);
                
                
                //pointLabel
                char pointBuf[128];
                sprintf(pointBuf, "Relation Point:%d",relation-2);
                pointLabel->setString(pointBuf);
                
                //消费提示
                std::string buf="Maybe, I should change a topic... \n Communication Decreased! ";
                

                
                  tipsLabel->setString(buf);
//                auto tipsLabel=Label::createWithSystemFont(buf, "Marker Felt.ttf", 30);
//                
//                tipsLabel->setColor(Color3B::RED);
//                tipsLabel->setPosition(bg->getPosition().x,50);
//                 tipsLabel->runAction(Sequence::create( DelayTime::create(2), Spawn::create(MoveBy::create(2.0, Point(0,50)),FadeOut::create(2.0), NULL),RemoveSelf::create(),NULL));
//                this->addChild(tipsLabel);
                
                
                
                break;
            }
                
            default:
                break;
        }
        
        tipsLabel->runAction(Sequence::create( DelayTime::create(2), Spawn::create(MoveBy::create(2.0, Point(0,50)),FadeOut::create(2.0), NULL),RemoveSelf::create(),NULL));
        this->addChild(tipsLabel);
        
        
    }
}


//足球
void shopLayer::footballCallBack(cocos2d::Ref *pSender)
{
   

    int relation=UserDefault::getInstance()->getIntegerForKey("RELATION", 0);
    
    //不够提示
    if ((relation-5)<0)
    {
        auto tipLabel=Label::createWithSystemFont("Not enough Points", "Marker Felt.ttf", 30);
        
        tipLabel->setColor(Color3B::RED);
        tipLabel->setPosition(bg->getPosition().x,60);
        tipLabel->runAction(Sequence::create(Spawn::create(MoveBy::create(2.0, Point(0,50)),FadeOut::create(2.0), NULL),RemoveSelf::create(),NULL));
        this->addChild(tipLabel);
        
        
        
    }
    
    else
    {
        //随机反应
        //喜欢的概率75，没反应25
        int index[3]={0,0,1};
        int react=random(0, 2);
        relation-=5;
        UserDefault::getInstance()->setIntegerForKey("RELATION", relation);
        
        int HOBBY=UserDefault::getInstance()->getIntegerForKey("HOBBY", 0);
        
        //提示信息
        auto tipsLabel=Label::createWithSystemFont("", "Marker Felt.ttf", 30);
        tipsLabel->setColor(Color3B::RED);
        tipsLabel->setPosition(bg->getPosition().x,60);
        
        
        switch (index[react])
        {
                //喜欢
            case 0:
            {
                UserDefault::getInstance()->setIntegerForKey("HOBBY", ++HOBBY);
                
                //pointLabel
                char pointBuf[128];
                sprintf(pointBuf, "Relation Point:%d",relation);
                pointLabel->setString(pointBuf);
                
                //消费提示
                std::string buf="He likes to talk about this topic! \n Specialty Increased！";
                
                tipsLabel->setString(buf);
                
                break;
            }
                
                //没反应
            case 1:
            {
                
                
                
                //pointLabel
                char pointBuf[128];
                sprintf(pointBuf, "Relation Point:%d",relation);
                pointLabel->setString(pointBuf);
                
                //消费提示
                std::string buf="Maybe another day...\n Nothing Happened...";
                tipsLabel->setString(buf);
                
                break;
            }
                //讨厌
                
            default:
                break;
        }
        
        
        tipsLabel->runAction(Sequence::create( DelayTime::create(2), Spawn::create(MoveBy::create(2.0, Point(0,50)),FadeOut::create(2.0), NULL),RemoveSelf::create(),NULL));
        this->addChild(tipsLabel);

        
    }

    
    
}

//家庭
void shopLayer::familyCallBack(cocos2d::Ref *pSender)
{
    
    
    int relation=UserDefault::getInstance()->getIntegerForKey("RELATION", 0);
    
    //不够提示
    if ((relation-1)<0)
    {
        auto tipLabel=Label::createWithSystemFont("Not enough Points", "Marker Felt.ttf", 30);
        
        tipLabel->setColor(Color3B::RED);
        tipLabel->setPosition(bg->getPosition().x,60);
        tipLabel->runAction(Sequence::create(Spawn::create(MoveBy::create(2.0, Point(0,50)),FadeOut::create(2.0), NULL),RemoveSelf::create(),NULL));
        this->addChild(tipLabel);
        
        
        
    }
    
    else
    {
    //家庭固定增加

        relation-=1;
        
        UserDefault::getInstance()->setIntegerForKey("RELATION", relation);
        
        int FAMILY=UserDefault::getInstance()->getIntegerForKey("FAMILY", 0);
        
        //提示信息
        auto tipsLabel=Label::createWithSystemFont("", "Marker Felt.ttf", 30);
        tipsLabel->setColor(Color3B::RED);
        tipsLabel->setPosition(bg->getPosition().x,60);
        
        
        //家庭值++
            UserDefault::getInstance()->setIntegerForKey("FAMILY", ++FAMILY);
                
                //pointLabel
                char pointBuf[128];
                sprintf(pointBuf, "Relation Point:%d",relation);
                pointLabel->setString(pointBuf);
                
                //消费提示
                std::string buf="He seems to understand something... \n Family Increased！";
                
                tipsLabel->setString(buf);
                
        
        tipsLabel->runAction(Sequence::create( DelayTime::create(2), Spawn::create(MoveBy::create(2.0, Point(0,50)),FadeOut::create(2.0), NULL),RemoveSelf::create(),NULL));
        this->addChild(tipsLabel);
        
        
    }
    
    
    
}