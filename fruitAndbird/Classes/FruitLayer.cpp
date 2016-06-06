//
//  FruitLayer.cpp
//  fruitAndbird
//
//  Created by zwj on 16/5/27.
//
//



#include "MainLayer.hpp"
#include <time.h>
#include "FruitLayer.hpp"
#include "SimpleAudioEngine.h"
using namespace CocosDenshion;



bool fruitLayer:: init()
{
    if (!Layer::init())
    {
        return false;
    }
    
    Size visibleSize=Director::getInstance()->getVisibleSize();
    Point origin=Director::getInstance()->getVisibleOrigin();
    
    stopFlag=false;
    gameFlag=false;
    readyFlag=true;
    actionFlag=false;
    overFlag=false;
    
    fruit=new vector<Sprite*>();
    int i=random();
    if (i%2==0)
    {
        background=Sprite::create("morning.png");
    }
    else
    {
        background=Sprite::create("night.png");
    
    }
    
    background->setAnchorPoint(Point(0,0));
    background->setPosition(Point(origin.x,origin.y+visibleSize.height-background->getContentSize().height));
    this->addChild(background,0);
    
    effectNode=NodeGrid::create();
    this->addChild(effectNode,1);
    ready=Sprite::create("readyFruit.png");
    ready->setPosition(Point(visibleSize.width/2,visibleSize.height/2));
    effectNode->addChild(ready,0);
    
    floor = Sprite::create("floor.png");
    //…Ë÷√√™µ„
    floor->setAnchorPoint(Point(0, 0));
    //…Ë÷√æ´¡È∂‘œÛŒª÷√
    floor->setPosition(Point(origin.x, origin.y));
    this->addChild(floor, 4);
    //µÿ√Êπˆ∂Ø
    floor->runAction(RepeatForever::create(
                                           Sequence::create
                                           (
                                            MoveTo::create(0.5, Point(-120, 0)),
                                            MoveTo::create(0, Point(0, 0)),
                                            NULL
                                            )
                                           ));
    pause = Sprite::create("pause.png");
    //…Ë÷√æ´¡ÈŒª÷√
    pause->setPosition(Point(32, 928));
    this->addChild(pause,10);
    
    
    pause=Sprite::create("pause.png");
    
    auto pauseItem=MenuItemSprite::create(pause, pause, CC_CALLBACK_1(fruitLayer::onTouchPause, this));
    pauseItem->setPosition(Point(32,928));
    auto menu=Menu::create(pauseItem, NULL);
    menu->setPosition(0,0);
    this->addChild(menu);

    
    auto listener=EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true);
    listener->onTouchBegan=CC_CALLBACK_2(fruitLayer::onTouchBegan, this);
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
    
    
    
    return true;
}

void fruitLayer::startGame()
{
    Director::getInstance()->setDepthTest(false);
    effectNode->runAction(SplitCols::create(1.0f, 20));
    Size visibleSize=Director::getInstance()->getVisibleSize();
    
    initColumn1();
    initColumn2();
    gameFlag=true;
    pLabelAtlas=LabelAtlas::create("0", "number.png", 48, 64, '0');
    
    pLabelAtlas->setPosition(Point(visibleSize.width/5,visibleSize.height/5*4));
    this->addChild(pLabelAtlas,4);
    auto director=Director::getInstance();
    auto sched=director->getScheduler();
    
    sched->schedule(schedule_selector(fruitLayer::update_fruit), this, 1,false);
    sched->schedule(schedule_selector(fruitLayer::update_boss), this, 20,false);
    sched->schedule(schedule_selector(fruitLayer::update_column), this, 0.1,false);


}
void fruitLayer::initColumn1()
{
    Size visibleSize=Director::getInstance()->getVisibleSize();
    int i=random();
    int height=-(i*5);
    height1=800-height;
    columnUnder1=Sprite::create("column1.png");
    columnUnder1->setAnchorPoint(Point(0,0));
    columnUnder1->setPosition(Point(visibleSize.width,height));
    columnOn1=Sprite::create("column2.png");
    columnOn1->setAnchorPoint(Point(0,0));
    columnOn1->setPosition(Point(visibleSize.width,height1));
    this->addChild(columnUnder1,3);
    this->addChild(columnOn1,3);
    int speed=count*0.05+15;
    columnUnder1->runAction(RepeatForever::create(MoveBy::create(0.1, Point(-speed,0))));
    columnOn1->runAction(RepeatForever::create(MoveBy::create(0.1, Point(-speed,0))));
}

void fruitLayer::initColumn2()
{
    //ªÒ»°ÀÊª˙ ˝
    int i = random();
    int height = -(i*6);
    height2 = 800 - height;
    //ªÒ»°÷˘◊”1µƒŒª÷√
    Point columnPosition = columnUnder1->getPosition();
    //¥¥Ω®SpriteBatchNode∂‘œÛ
    columnUnder2 = Sprite::create("column1.png");
    //¥¥Ω®SpriteBatchNode∂‘œÛ
    columnOn2 = Sprite::create("column2.png");
    //…Ë÷√√™µ„
    columnUnder2->setAnchorPoint(Point(0, 0));
    //…Ë÷√Œª÷√
    columnUnder2->setPosition(Point(columnPosition.x + 320, height));
    //…Ë÷√√™µ„
    columnOn2->setAnchorPoint(Point(0, 0));
    //…Ë÷√Œª÷√
    columnOn2->setPosition(Point(columnPosition.x + 320, height2));
    //ÃÌº”µΩ≤ºæ∞÷–
    this->addChild(columnUnder2, 3);
    this->addChild(columnOn2, 3);
    int speed = count*0.05 + 15;
    columnUnder2->runAction(RepeatForever::create(MoveBy::create(0.1, Point(-speed, 0))));
    columnOn2->runAction(RepeatForever::create(MoveBy::create(0.1, Point(-speed, 0))));
}

int fruitLayer::random()
{
    srand(unsigned(time(NULL)));
    int number=rand()%5;
    return number;


}

void fruitLayer::update_fruit(float delta)
{

    if (gameFlag)
    {
        int i=random();
        float time=54/(i*2+10);
        string number=StringUtils::format("%d",i);
        string part ="fruit"+number+".png";
        Sprite* ff=Sprite::create(part);
        ff->setPosition(Point(0,(700-i*40)));
        this->addChild(ff,2);
        ff->runAction(MoveTo::create(time, Point(540,i*40)));
        int down=(700-i*40)-450;
        if( (700-i*40)<600)
        {
            down=-down;
        }
        ff->runAction(RepeatForever::create(
                                            Sequence::create(MoveBy::create((time/3), Point(0, -down)), MoveBy::create((time/3), Point(0, down)), NULL)
                                            ));
        
        fruit->push_back(ff);
        
    }
}
void fruitLayer::update_boss(float delta)
{
    if (gameFlag) {
        int i=random();
        boss++;
        bossFlag=true;
        string number=StringUtils::format("%d",i);
        string partBoss="fruit"+number+".png";
        bossSprite=Sprite::create(partBoss);
        bossSprite->setScale(2);
        bossSprite->setPosition(Point(0,600));
        this->addChild(bossSprite,2);
        bossSprite->runAction(MoveTo::create(10, Point(540,600)));
        
        //slider的用法--------------------
        slider=Slider::create();
        slider->loadBarTexture("sliderTrack.png");
        slider->loadProgressBarTexture("blood.png");
        slider->setPercent(100);
        slider->setPosition(Point(0,700));
        this->addChild(slider,2);
        slider->runAction(MoveTo::create(10, Point(540,700)));
                          
        
    }
    
}

void fruitLayer::update_column(float delta)
{
    Size visibleSize=Director::getInstance()->getVisibleSize();
    
    Point columnPosition1=columnUnder1->getPosition();
    Point columnPosition2=columnUnder2->getPosition();

    Size columnSize=columnUnder1->getContentSize();
    if (columnPosition1.x<=-columnSize.width)
    {
        actionFlag=false;
        removeChild(columnUnder1);
        removeChild(columnOn1);
        initColumn1();
    }
    
    if (columnPosition2.x<=-columnSize.width)
    {
        actionFlag=false;
        removeChild(columnUnder2);
        removeChild(columnOn2);
        initColumn2();
    }

    vector<Sprite*>::iterator iter;
    for (iter=fruit->begin(); iter!=fruit->end(); iter++)
    {
        Point fruitPiont=(*iter)->getPosition();
        Size fruitSize=(*iter)->getContentSize();
        if (fruitPiont.x>=(visibleSize.width-fruitSize.width/2))
        {
            gameOver();
        }
    }


}

void fruitLayer::gameOver()
{
    gameFlag=false;
    columnUnder1->stopAllActions();
    columnUnder2->stopAllActions();
    columnOn1->stopAllActions();
    columnOn2->stopAllActions();
    floor->stopAllActions();
    if (bossFlag) {
        bossSprite->stopAllActions();
        slider->stopAllActions();
    }
    vector<Sprite*>::iterator iter;
    for (iter=fruit->begin(); iter!=fruit->end(); iter++)
    {
        (*iter)->stopAllActions();
    }
    if (!overFlag) {
        replay();
    }
}

void fruitLayer::replay()
{
    overFlag = true;
    //Ω±≈∆
    string medal;
    removeChild(pLabelAtlas);
    //----------------------------------------------------------------------------
    Sprite* over = Sprite::create("gameOver.png");
    over->setPosition(Point(270, 1200));
    this->addChild(over, 10);
    
    overRank = Sprite::create("scoreOver.png");
    overRank->setPosition(Point(270, -100));
    this->addChild(overRank, 10);
    
    //÷ÿ–¬ø™ º
    relayItem = MenuItemImage::create(
                                      "replay.png",
                                      "replay_off.png",
                                      CC_CALLBACK_1(fruitLayer::menuCallback0, this) //µ„ª˜ ±÷¥––µƒªÿµ˜∑Ω∑®
                                      );
    relayItem->setPosition(Point(150, -250));
    //∑µªÿ÷˜≤Àµ•
    menuItem = MenuItemImage::create(
                                     "menu.png",
                                     "menu_off.png",
                                     CC_CALLBACK_1(fruitLayer::menuCallback1, this) //µ„ª˜ ±÷¥––µƒªÿµ˜∑Ω∑®
                                     );
    menuItem->setPosition(Point(380, -250));
    
    Menu* menu = Menu::create(relayItem, menuItem, NULL);
    //…Ë÷√≤Àµ•Œª÷√
    menu->setPosition(Point::ZERO);
    this->addChild(menu,10);
    
    //-----------------------------------------------------------------------------
           Sprite* gold = Sprite::create(medal);
        overRank->addChild(gold, 5);
        gold->setPosition(Point(90, 88));
    
    //÷¥––∂Ø◊˜
    over->runAction(
                    Sequence::create(
                                     MoveTo::create(0.2, Point(270, 750)),
                                     CallFunc::create(CC_CALLBACK_0(fruitLayer::moveObject, this)),
                                     NULL
                                     ));
}
void fruitLayer::moveObject()
{
    overRank->runAction(MoveTo::create(0.6, Point(270, 550)));
    relayItem->runAction(MoveTo::create(0.6, Point(150, 380)));
    menuItem->runAction(MoveTo::create(0.6, Point(380, 380)));
}
void fruitLayer::setFlag()
{
    actionFlag = false;
}
bool fruitLayer::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event)
{

    do{
        if(actionFlag)
        {
            return false;
        }
        if(readyFlag)
        {
            startGame();
            readyFlag = false;
        }
        Point columnPosition1 = columnUnder1->getPosition();
        Point columnPosition2 = columnUnder2->getPosition();
        //ªÒ»°ø…º˚«¯”Ú≥ﬂ¥Á
        Size visibleSize = Director::getInstance()->getVisibleSize();
        //ªÒ»°µ±«∞¥•øÿŒª÷√
        Point touchPosition = touch->getLocation();
        //ªÒ»°÷˘◊”µƒŒª“∆
        int compression1 = height1 - 600;
        int compression2 = height2 - 600;
        //…Ë÷√∂Ø◊˜
        Action* action1 = Sequence::create
        (
         MoveBy::create(0.1, Point(0, compression1)),
         CallFunc::create(CC_CALLBACK_0(fruitLayer::check, this)),
         MoveBy::create(0.1, Point(0, -compression1)),
         CallFunc::create(CC_CALLBACK_0(fruitLayer::setFlag, this)),
         NULL
         );
        Action* action2 = Sequence::create
        (
         MoveBy::create(0.1, Point(0, -compression1)),
         CallFunc::create(CC_CALLBACK_0(fruitLayer::check, this)),
         MoveBy::create(0.1, Point(0, compression1)),
         NULL
         );
        Action* action3 = Sequence::create
        (
         MoveBy::create(0.1, Point(0, compression2)),
         CallFunc::create(CC_CALLBACK_0(fruitLayer::check, this)),
         MoveBy::create(0.1, Point(0, -compression2)),
         CallFunc::create(CC_CALLBACK_0(fruitLayer::setFlag, this)),
         NULL
         );
        Action* action4 = Sequence::create
        (
         MoveBy::create(0.1, Point(0, -compression2)),
         CallFunc::create(CC_CALLBACK_0(fruitLayer::check, this)),
         MoveBy::create(0.1, Point(0, compression2)),
         NULL
         );
        if(gameFlag)
        {
            //ªÒ»°÷˘◊”≥ﬂ¥Á¥Û–°
            Size columnSize = columnUnder1->getContentSize();
          
            bool columnCheck1 = true;
            bool columnCheck2 = true;
            if(touchPosition.x<visibleSize.width/2)
            {
                if(columnCheck1)
                {
                    actionFlag = true;
                    columnUnder1->runAction(action1);
                    columnOn1->runAction(action2);
                }else if(columnCheck2)
                {
                    actionFlag = true;
                    columnUnder2->runAction(action3);
                    columnOn2->runAction(action4);
                }
            }else if(touchPosition.x>=visibleSize.width/2)
            {
                if(!columnCheck1)
                {
                    actionFlag = true;
                    columnUnder1->runAction(action1);
                    columnOn1->runAction(action2);
                }else if(!columnCheck2)
                {
                    actionFlag = true;
                    columnUnder2->runAction(action3);
                    columnOn2->runAction(action4);
                
                }
            }
                }//game-------end
    }while(0);
    
    return true;
    
}
void fruitLayer::menuCallback0(Ref* pSender)
{
    sceneManager->goToSquishyScene(1);
}

void fruitLayer::menuCallback1(Ref* pSender)
{
    sceneManager->goToMainScene();
}
void fruitLayer::menuCallback2(Ref* pSender)
{
    Director::getInstance()->resume();
    sceneManager->goToMainScene();
}
void fruitLayer::menuCallback3(Ref* pSender)
{
    stopFlag = false;
    this->removeChild(pauseBack);
    pause->setTexture("pause.png");
    Director::getInstance()->resume();
}
void fruitLayer::menuCallback4(Ref* pSender)
{
    Director::getInstance()->resume();
    sceneManager->goToSquishyScene(1);
}
void fruitLayer::selectedEvent0(Ref* pSender,CheckBox::EventType type)
{
    switch (type)
    {
        case CheckBox::EventType::SELECTED:
            CocosDenshion::SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
            MainLayer::musicFlag = false;
            break;
            
        case CheckBox::EventType::UNSELECTED:
            CocosDenshion::SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
            MainLayer::musicFlag = true;
            break;
        default:
            break;
    }
}
//“Ù–ß∏¥—°øÚ÷¥––∑Ω∑®
void fruitLayer::selectedEvent1(Ref* pSender,CheckBox::EventType type)
{
    switch (type)
    {
        case CheckBox::EventType::SELECTED:
            MainLayer::soundFlag = false;
            break;
        case CheckBox::EventType::UNSELECTED:
            MainLayer::soundFlag = true;
            break;
        default:
            break;
    }
}
//≤•∑≈÷˘◊”œ‡◊≤“Ù–ß
void fruitLayer::wingSound()
{
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("sfx_wing.ogg");
}
//≤•∑≈º–±¨ÀÆπ˚“Ù–ß
void fruitLayer::eatSound()
{
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("eat.wav");
}
bool fruitLayer:: onTouchPause(Ref* pSender)
{}
void fruitLayer::check()
{}