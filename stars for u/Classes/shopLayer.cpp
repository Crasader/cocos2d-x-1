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
    
 // UserDefault::getInstance()->setIntegerForKey("RELATION", 1000);
    
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
    sprintf(pointBuf, "亲密值:%d",relation);
     pointLabel=Label::createWithTTF(pointBuf, "fonts/china.ttf", 30);
    pointLabel->setColor(Color3B::RED);
    pointLabel->setPosition(pointLabel->getContentSize().width+10,bg->getContentSize().height*0.85);
    bg->addChild(pointLabel);
  
    //talk
    auto talkLabel=Label::createWithTTF("和他聊个天 ", "fonts/china.ttf", 40);
    talkLabel->setColor(Color3B::RED);
    auto talkButton=MenuItemLabel::create(talkLabel, CC_CALLBACK_1(shopLayer::talkCallBack, this));
    talkButton->setPosition(bg->getContentSize().width*0.2+60,bg->getContentSize().height*0.7);
    
    
    
    //提示信息
    tipsLabel=Label::createWithTTF("", "fonts/china.ttf", 30);
    tipsLabel->setColor(Color3B::RED);
    tipsLabel->setPosition(bg->getPosition().x,70);
    this->addChild(tipsLabel);
    
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
    
    
}


//
void shopLayer::talkCallBack(cocos2d::Ref *pSender)
{
    

    auto talkingBox=Sprite::create("talkingBox_LL.png");
    talkingBox->setScale(0);
    talkingBox->setPosition(bg->getContentSize().width/2,bg->getContentSize().height/3+30);
    talkingBox->runAction(Sequence::create(ScaleTo::create(0.1, 0.4),
                                           ScaleTo::create(0.1, 0.8),
                                           ScaleTo::create(0.1,1.0),
                                           NULL));
    bg->addChild(talkingBox);
    
    
    
    

    //exam
    auto examLabel=Label::createWithTTF("学习(2)", "fonts/china.ttf", 30);
    examLabel->setColor(Color3B::RED);
    auto examButton=MenuItemLabel::create(examLabel, CC_CALLBACK_1(shopLayer::examCallBack, this));
    examButton->setPosition(examButton->getContentSize().width,talkingBox->getContentSize().height-140);
    
    //friends
    auto firendsLabel=Label::createWithTTF("朋友(2)", "fonts/china.ttf", 30);
    firendsLabel->setColor(Color3B::RED);
    auto friendsButton=MenuItemLabel::create(firendsLabel, CC_CALLBACK_1(shopLayer::friendsCallBack, this));
    friendsButton->setPosition(friendsButton->getContentSize().width,talkingBox->getContentSize().height-200);


    //hobby
    
    auto footballLabel=Label::createWithTTF("爱好(5)", "fonts/china.ttf", 30);
    footballLabel->setColor(Color3B::RED);
    auto footballButton=MenuItemLabel::create(footballLabel, CC_CALLBACK_1(shopLayer::footballCallBack, this));
    footballButton->setPosition(examButton->getContentSize().width+200,talkingBox->getContentSize().height-140);
    
    
    //family
    auto familylLabel=Label::createWithTTF("家庭(1)", "fonts/china.ttf", 30);
    familylLabel->setColor(Color3B::RED);
    auto familyButton=MenuItemLabel::create(familylLabel, CC_CALLBACK_1(shopLayer::familyCallBack, this));
    familyButton->setPosition(familyButton->getContentSize().width+200,talkingBox->getContentSize().height-200);
    
    
    auto menu=Menu::create(examButton,friendsButton, footballButton,familyButton,NULL);
    menu->setPosition(0,0);
    talkingBox->addChild(menu);




}

//提示动作
void shopLayer::tipsLabelAction()
{   tipsLabel->stopAllActions();
    tipsLabel->setPosition(bg->getPosition().x,60);
    tipsLabel->runAction(Sequence::create(FadeIn::create(0),DelayTime::create(1.0),Spawn::create(MoveBy::create(2.0, Point(0,50)),FadeOut::create(2.0), NULL),NULL));

}

//考试
void shopLayer::examCallBack(cocos2d::Ref *pSender)
{
    tipsLabel->setPosition(bg->getPosition().x,70);
    int relation=UserDefault::getInstance()->getIntegerForKey("RELATION", 0);
    
    //不够提示
    if ((relation-2)<0)
    {
//        auto tipLabel=Label::createWithTTF("亲密值不足", "fonts/china.ttf", 30);
//        
//        tipLabel->setColor(Color3B::RED);
//        tipLabel->setPosition(bg->getPosition().x,60);
//        tipLabel->runAction(Sequence::create(Spawn::create(MoveBy::create(2.0, Point(0,50)),FadeOut::create(2.0), NULL),RemoveSelf::create(),NULL));
//        this->addChild(tipLabel);
              std::string buf="亲密值不足 ";
        tipsLabel->setString(buf);
        tipsLabelAction();
    }
    
    else
    {
        
        
        int index[5];
        int react;
        //CON5技能,学习值增加概率变大
        if (UserDefault::getInstance()->getBoolForKey("CON5", false))
        {
            index[0]=0;
            index[1]=0;
            index[2]=0;
            index[3]=1;
            index[4]=2;
            react= random(0, 4);
            
        }
        
        
        else
        {
            index[0]=0;
            index[1]=0;
            index[2]=1;
            index[3]=2;
            index[4]=2;
        react= random(0, 4);
        }
        //随机反应
      
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
                sprintf(pointBuf, "亲密值:%d",relation);
                pointLabel->setString(pointBuf);
                
                //消费提示
                std::string buf="他好像明白了什么... \n  学习值增加! ";
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
                sprintf(pointBuf, "亲密值:%d",relation);
                pointLabel->setString(pointBuf);
                
                //消费提示
                std::string buf="他好像没什么反应...  \n  什么都没发生.";
                
               
                
                
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
                sprintf(pointBuf, "亲密值:%d",relation-1);
                pointLabel->setString(pointBuf);
                
                //消费提示
                std::string buf="聊这个话题他好像不高兴... \n 学习值减少!";
                
                
                
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
    

       tipsLabelAction();
        //this->addChild(tipsLabel);

        
    }

}

//朋友
void shopLayer::friendsCallBack(cocos2d::Ref *pSender)
{
    int relation=UserDefault::getInstance()->getIntegerForKey("RELATION", 0);
    
    //不够提示
    if ((relation-2)<0)
    {
//        auto tipLabel=Label::createWithTTF("亲密值不足!", "fonts/china.ttf", 30);
//        
//        tipLabel->setColor(Color3B::RED);
//        tipLabel->setPosition(bg->getPosition().x,60);
//        tipLabel->runAction(Sequence::create(Spawn::create(MoveBy::create(2.0, Point(0,50)),FadeOut::create(2.0), NULL),RemoveSelf::create(),NULL));
//        this->addChild(tipLabel);
        
        std::string buf="亲密值不足 ";
        tipsLabel->setString(buf);
        tipsLabelAction();
    }
    
    else
    {
        
        
        int index[5];
        int react;
        //CON6技能,社交值增加概率变大
        if (UserDefault::getInstance()->getBoolForKey("CON6", false))
        {
            index[0]=0;
            index[1]=0;
            index[2]=0;
            index[3]=1;
            index[4]=2;
            react= random(0, 4);
            
        }
        
        
        else
        {
            index[0]=0;
            index[1]=0;
            index[2]=1;
            index[3]=2;
            index[4]=2;
            react= random(0, 4);
        }
        relation-=2;
        UserDefault::getInstance()->setIntegerForKey("RELATION", relation);
        
        int FRIENDS=UserDefault::getInstance()->getIntegerForKey("FRIENDS", 0);
        
        
//        //提示信息
//        Label* tipsLabel=Label::createWithTTF("", "fonts/china.ttf", 30);
//        tipsLabel->setColor(Color3B::RED);
//         tipsLabel->setPosition(bg->getPosition().x,60);

        
        switch (index[react])
        {
                //喜欢
            case 0:
            {
                UserDefault::getInstance()->setIntegerForKey("FRIENDS", ++FRIENDS);
                
                //pointLabel
                char pointBuf[128];
                sprintf(pointBuf, "亲密值:%d",relation);
                pointLabel->setString(pointBuf);
                
                //消费提示
                std::string buf="他好像很感兴趣！ \n 社交值增加!";
                
                
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
                sprintf(pointBuf, "亲密值:%d",relation);
                pointLabel->setString(pointBuf);
                
                //消费提示
                std::string buf="对这个话题他没什么反应。\n 什么都没发生。";
                
            
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
                sprintf(pointBuf, "亲密值:%d",relation-2);
                pointLabel->setString(pointBuf);
                
                //消费提示
                std::string buf="或许我应该换个话题.. \n 社交值降低! ";
                

                
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
        
        tipsLabelAction();
        //        this->addChild(tipsLabel);
        
        
    }
}


//足球
void shopLayer::footballCallBack(cocos2d::Ref *pSender)
{
   

    int relation=UserDefault::getInstance()->getIntegerForKey("RELATION", 0);
    
    //不够提示
    if ((relation-5)<0)
    {
//        auto tipLabel=Label::createWithTTF("亲密值不足！", "fonts/china.ttf", 30);
//        
//        tipLabel->setColor(Color3B::RED);
//        tipLabel->setPosition(bg->getPosition().x,60);
//        tipLabel->runAction(Sequence::create(Spawn::create(MoveBy::create(2.0, Point(0,50)),FadeOut::create(2.0), NULL),RemoveSelf::create(),NULL));
//        this->addChild(tipLabel);
        
        std::string buf="亲密值不足 ";
        tipsLabel->setString(buf);
        tipsLabelAction();
    }
    
    else
    {
        int index[5];
        int react;
        //CON6技能,社交值增加概率变大
        if (UserDefault::getInstance()->getBoolForKey("CON7", false))
        {
            index[0]=0;
            index[1]=0;
            index[2]=0;
            index[3]=1;
            index[4]=0;
            react= random(0, 4);
            
        }
        
        
        else
        {
            index[0]=0;
            index[1]=0;
            index[2]=1;
            index[3]=1;
            index[4]=1;
            react= random(0, 4);
        }

        relation-=5;
        UserDefault::getInstance()->setIntegerForKey("RELATION", relation);
        
        int HOBBY=UserDefault::getInstance()->getIntegerForKey("HOBBY", 0);
        
//        //提示信息
//        auto tipsLabel=Label::createWithSystemFont("", "Marker Felt.ttf", 30);
//        tipsLabel->setColor(Color3B::RED);
//        tipsLabel->setPosition(bg->getPosition().x,60);
        
        
        switch (index[react])
        {
                //喜欢
            case 0:
            {
                UserDefault::getInstance()->setIntegerForKey("HOBBY", ++HOBBY);
                
                //pointLabel
                char pointBuf[128];
                sprintf(pointBuf, "亲密值:%d",relation);
                pointLabel->setString(pointBuf);
                
                //消费提示
                std::string buf="我们聊了很多！ \n 特长值增加！";
                
                tipsLabel->setString(buf);
                
                break;
            }
                
                //没反应
            case 1:
            {
                
                
                
                //pointLabel
                char pointBuf[128];
                sprintf(pointBuf, "亲密值:%d",relation);
                pointLabel->setString(pointBuf);
                
                //消费提示
                std::string buf="或许改天吧。\n 什么都没发生...";
                tipsLabel->setString(buf);
                
                break;
            }
                //讨厌
                
            default:
                break;
        }
        
        tipsLabelAction();
        
    }

    
    
}

//家庭
void shopLayer::familyCallBack(cocos2d::Ref *pSender)
{
    
    
    int relation=UserDefault::getInstance()->getIntegerForKey("RELATION", 0);
    
    //不够提示
    if ((relation-1)<0)
    {
//        auto tipLabel=Label::createWithTTF("亲密值不足！", "fonts/china.ttf", 30);
//        
//        tipLabel->setColor(Color3B::RED);
//        tipLabel->setPosition(bg->getPosition().x,60);
// tipLabel->runAction(Sequence::create(Spawn::create(MoveBy::create(2.0, Point(0,50)),FadeOut::create(2.0), NULL),RemoveSelf::create(),NULL));
//        this->addChild(tipLabel);
        std::string buf="亲密值不足 ";
        tipsLabel->setString(buf);
       tipsLabelAction();
        
    }
    
    else
    {
    //家庭固定增加

        relation-=1;
        
        UserDefault::getInstance()->setIntegerForKey("RELATION", relation);
        
        int FAMILY=UserDefault::getInstance()->getIntegerForKey("FAMILY", 0);
        
//        //提示信息
//        auto tipsLabel=Label::createWithTTF("", "fonts/china.ttf", 30);
//        tipsLabel->setColor(Color3B::RED);
//        tipsLabel->setPosition(bg->getPosition().x,60);
//        
        
        //家庭值++
        std::string buf;
        if (UserDefault::getInstance()->getBoolForKey("CON8", false))
        {
            FAMILY+=2;
            UserDefault::getInstance()->setIntegerForKey("FAMILY", FAMILY);
            //消费提示
            buf="他好像明白了什么。 \n 家庭值大大增加了！";
            

        }
        else
        {   FAMILY+=1;
            UserDefault::getInstance()->setIntegerForKey("FAMILY", FAMILY);
            //消费提示
            buf="他好像明白了什么。 \n 家庭值增加了！";
        }
        
                //pointLabel
                char pointBuf[128];
                sprintf(pointBuf, "亲密值:%d",relation);
                pointLabel->setString(pointBuf);
                
        
                
                tipsLabel->setString(buf);
                
        
       tipsLabelAction();
       
        
        
    }
    
    
    
}