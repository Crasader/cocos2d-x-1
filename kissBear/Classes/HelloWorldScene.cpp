#include "HelloWorldScene.h"
#include <iostream>
USING_NS_CC;


Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
   



    

    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();


    auto bg=Sprite::create("bg1.png");
    bg->setPosition(visibleSize.width/2,visibleSize.height/2);
    addChild(bg);
    
    auto wc1=Sprite::create("wc.png");
    wc1->setPosition(100,200);
    wc1->setTag(1);
    addChild(wc1);
    
    auto wc2=Sprite::create("wc.png");
    wc2->setPosition(300,200);
    wc2->setTag(2);
    addChild(wc2);
    
    auto wc3=Sprite::create("wc.png");
    wc3->setPosition(500,200);
    wc3->setTag(3);
    addChild(wc3);
    
    auto wc4=Sprite::create("wc.png");
    wc4->setPosition(100,400);
    wc4->setTag(4);
    addChild(wc4);
    
    auto wc5=Sprite::create("wc.png");
    wc5->setPosition(300,400);
    wc5->setTag(5);
    addChild(wc5);
    
    auto wc6=Sprite::create("wc.png");
    wc6->setPosition(500,400);
    wc6->setTag(6);
    addChild(wc6);
    
    
    auto wc7=Sprite::create("wc.png");
    wc7->setPosition(100,600);
    wc7->setTag(7);
    addChild(wc7);
    
    auto wc8=Sprite::create("wc.png");
    wc8->setPosition(300,600);
    wc8->setTag(8);
    addChild(wc8);
    
    auto wc9=Sprite::create("wc.png");
    wc9->setPosition(500,600);
    wc9->setTag(9);
    addChild(wc9);
    
    

    
    this->schedule(schedule_selector(HelloWorld::bearShow), interval);
    
    bear=Sprite::create("b.png");
    bear->setPosition(-100,100);
    addChild(bear);
    
    wo=Sprite::create("wo.png");
    wo->setPosition(-100,100);
    this->addChild(wo);
    
    
    kiss=Sprite::create("m.png");
    kiss->setVisible(false);
    addChild(kiss);

    auto scoreString=__String::createWithFormat("%d", score);
    auto scoreLabel=Label::createWithTTF(scoreString->getCString(), "Marker Felt.ttf", 50);
    scoreLabel->setPosition(300,820);
    scoreLabel->setTag(101);
    this->addChild(scoreLabel);

    
    
    //TOUCH
   
  listener=EventListenerTouchOneByOne::create();
    listener->onTouchBegan=[this](Touch *touch,Event *event)
    {
    
        auto touchPoint=touch->getLocation();
        
     
        auto bearSize=bear->getContentSize();
        
     
        auto touchPointInBear=bear->convertToNodeSpace(touchPoint);
        auto rect=Rect(0, 0, bearSize.width, bearSize.height);
        if (rect.containsPoint(touchPointInBear)) {
            
            
            j[n-1]=99;
            kiss->setVisible(true);
            kiss->setPosition(bear->getPosition());
            kiss->setRotation(20);
            bear->setVisible(false);
            bear->removeFromParent();
            wo->setVisible(false);
            wo->removeFromParent();
            
            score=score+1;
            log("touched,score =%d,level=%d",score,level);
           
            switch (score){
                   
                case 10:
                    interval=1.5;
                    this->unscheduleAllSelectors();
                    this->schedule(schedule_selector(HelloWorld::bearShow), interval);
                    break;
                case 15:
                    interval=1;
                    this->unscheduleAllSelectors();
                    this->schedule(schedule_selector(HelloWorld::bearShow), interval);
                    break;
                case 20:
                    interval=1;
                    this->unscheduleAllSelectors();
                    this->schedule(schedule_selector(HelloWorld::bearShow), interval);
                    break;
                case 25:
                    interval=0.6;
                    this->unscheduleAllSelectors();
                    this->schedule(schedule_selector(HelloWorld::bearShow), interval);
                    break;
                case 30:
                    interval=0.7;
                    this->unscheduleAllSelectors();
                    this->schedule(schedule_selector(HelloWorld::bearShow), interval);
                    break;
                case 35:
                    interval=1;
                    this->unscheduleAllSelectors();
                    this->schedule(schedule_selector(HelloWorld::bearShow), interval);
                    break;
               case 40:
                    interval=0.5;
                    this->unscheduleAllSelectors();
                    this->schedule(schedule_selector(HelloWorld::bearShow), interval);
                    break;
                case 50:
                    interval=0.3;
                    this->unscheduleAllSelectors();
                    this->schedule(schedule_selector(HelloWorld::bearShow), interval);
                    break;




            }
            
            if (this->getChildByTag(101)==nullptr) {
                log("non");
            }
            this->removeChildByTag(101);
            auto scoreString=__String::createWithFormat("%d", score);
            auto scoreLabel=Label::createWithTTF(scoreString->getCString(), "Marker Felt.ttf", 50);
            scoreLabel->setPosition(300,820);
            scoreLabel->setTag(101);
            this->addChild(scoreLabel);
            
            
        }
    
        return false;
    };
    
    
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
    return true;
}
void HelloWorld::setBearPosition()
{
    
  
       Size visibleSize = Director::getInstance()->getVisibleSize();
    
    i=CCRANDOM_0_1()*9;
    
    
    for (int a=0; a<n; a++) {
        while(j[a]==i)
        {
         i=CCRANDOM_0_1()*9;
            a=0;
        }
        
    }
    j[n]=i;
    log("%d",i);

    n=n+1;
    
    
    wo=Sprite::create("wo.png");
    wo->setPosition(bearP[i]);
    this->addChild(wo);
    
    bear=Sprite::create("b.png");
    bear->setVisible(true);

    bear->setPosition(bearP[i]);
    this->addChild(bear);
    
    
    
  
    
    
    //如果出现x个bear，则判定结束
    
    if (this->getChildrenCount()>30) {
        
        
        this->pause();
        auto nodes=this->getChildren();
        for (const auto &node :nodes) {
            node->pause();
            
        }
        
        auto scoreStringVoer=__String::createWithFormat(" Game Over! Score is %d", score);
        auto scoreLabelVoer=Label::createWithTTF(scoreStringVoer->getCString(), "Marker Felt.ttf", 50);
        scoreLabelVoer->setColor(Color3B::RED);
        scoreLabelVoer->setPosition(visibleSize.width/2,visibleSize.height/1.8);
        addChild(scoreLabelVoer);
        
        
        auto restartBtn=MenuItemFont::create("Restart", CC_CALLBACK_0(HelloWorld::restartGame, this           ));
        restartBtn->setColor(Color3B::RED);
        auto mu=Menu::create(restartBtn, NULL);
        mu->setPosition(visibleSize.width/2,visibleSize.height/3);

        addChild(mu);
    }
    
}

void HelloWorld::bearShow(float dt)
{
    kiss->setVisible(false);
    this->setBearPosition();}



void HelloWorld::restartGame()
{
    this->removeAllChildren();
    Director::getInstance()->getEventDispatcher()->removeEventListener(listener);
    Director::getInstance()->popScene();

}


