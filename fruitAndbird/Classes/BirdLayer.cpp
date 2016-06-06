//
//  BirdLayer.cpp
//  fruitAndbird
//
//  Created by zwj on 16/5/27.
//
//

#include "BirdLayer.hpp"
#include <time.h>
#include "MainLayer.hpp"
#include "GameLayer.hpp"
#include "RankBirdLayer.hpp"
#include "SimpleAudioEngine.h"

bool birdLayer::init()
{
    if (!Layer::init())
    {
        return false;
    }

    Size visibleSize=Director::getInstance()->getVisibleSize();
    Point origin=Director::getInstance()->getVisibleOrigin();
    
    stopFlag=false;
    gameFlag=true;
    readyFlag=true;
    overFlag=false;
    
    int i=random();
    
    if (i%2==0)
    {
        backGround=Sprite::create("morning.png");
    }
    if (i%2==1)
    {
        backGround=Sprite::create("night.png");
    }
    backGround->setAnchorPoint(Point(0,0));
    backGround->setPosition(Point(origin.x,origin.y+visibleSize.height-backGround->getContentSize().height));
    this->addChild(backGround,0);
    
    effecNode=NodeGrid::create();
    this->addChild(effecNode,1);
    ready=Sprite::create("readyBird.png");
    ready->setPosition(Point(visibleSize.width/2,visibleSize.height/2));
    effecNode->addChild(ready,10);
    
    floor=Sprite::create("floor.png");
    floor->setAnchorPoint(Point(0,0));
    floor->setPosition(0,0);
    this->addChild(floor);
    floor->runAction(RepeatForever::create(Sequence::create(MoveTo::create(0.5, Point(-120,0)),MoveTo::create(0, Point(0,0)), NULL)));
    
    
    
    pLabelAtlas=LabelAtlas::create("0", "number.png", 48, 64, '0');
    pLabelAtlas->setPosition(Point(visibleSize.width/2,visibleSize.height/5*4));
    this->addChild(pLabelAtlas,4);
    
    pause=Sprite::create("pause.png");
    
    auto pauseItem=MenuItemSprite::create(pause, pause, CC_CALLBACK_1(birdLayer::onTouchPause, this));
    pauseItem->setPosition(Point(32,928));
    auto menu=Menu::create(pauseItem, NULL);
    menu->setPosition(0,0);
    this->addChild(menu);
    
    initBird();
    bird=Sprite::create();//----------
    bird->setPosition(Point(140,400));
    bird->runAction(RepeatForever::create(animAc));
    this->addChild(bird,2);
    auto listener=EventListenerTouchOneByOne::create();
    listener->onTouchBegan=CC_CALLBACK_2(birdLayer::onTouchBegan0, this);
    listener->setSwallowTouches(true);
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
    
    
    return true;
}

void birdLayer::initBird()
{
    //帧动画
    SpriteFrameCache* sfc=SpriteFrameCache::getInstance();
    sfc->addSpriteFramesWithFile("bird.plist", "birdP.png");
    std::string animBird[3]=
    {
    
        "bird1.png",
        "bird2.png",
        "bird3.png"
    
    };
    Vector<SpriteFrame*> animFrames;
    animFrames.pushBack(sfc->getSpriteFrameByName(animBird[0]));
    animFrames.pushBack(sfc->getSpriteFrameByName(animBird[1]));
    animFrames.pushBack(sfc->getSpriteFrameByName(animBird[2]));
    
    Animation *anim=Animation::createWithSpriteFrames(animFrames,0.1f);
    animAc=Animate::create(anim);
    animAc->retain();


    //另一种方法
    /*
    Animation* animation=Animation::create();
    
    for (int i=1; i<4; i++)
    {
        __String *frameNames=__String::createWithFormat("bird%d",i);
        
      auto spriteFrames= SpriteFrameCache::getInstance()->getSpriteFrameByName(frameNames->getCString());
        
        animation->addSpriteFrame(spriteFrames);
        
    }
    animation->setDelayPerUnit(0.1f);
    animation->setRestoreOriginalFrame(true);
    animAc=Animate::create(animation);
    
    
    */
    
    
}

int birdLayer::random()
{
    srand((unsigned)time(NULL));
    int number=rand()%5+1;
    return number;
}

bool birdLayer::onTouchBegan0(cocos2d::Touch *touch, cocos2d::Event *event)
{
    
    Point birdPosition=bird->getPosition();
    if (gameFlag)
    {
        if (readyFlag)
        {
            startGame();
            
            readyFlag=false;
        }
        if (MainLayer::soundFlag)
        {
            wingSound();
        }
        
        int move =105;
        auto action=Spawn::createWithTwoActions(MoveTo::create(0.2, Point(birdPosition.x,birdPosition.y+move)), RotateTo::create(0, -30));
        bird->stopAllActions();
        bird->runAction(RepeatForever::create(animAc));
        bird->runAction(Sequence::create(CallFunc::create(CC_CALLBACK_0(birdLayer::setRunFlag1, this)),action,CallFunc::create(CC_CALLBACK_0(birdLayer::setRunFlag2, this)),RotateTo::create(2.0, 90), NULL));
    }
    return true;
}
void birdLayer::setRunFlag1()
{
    runFlag=true;

}
void birdLayer::setRunFlag2()
{
    runFlag=false;
}


void birdLayer::startGame()
{

    Director::getInstance()->setDepthTest(false);
    effecNode->runAction(SplitRows::create(0.5f, 30));
    initColumn1();
    initColumn2();
    birdRun();
    Director::getInstance()->getScheduler()->schedule(schedule_selector(birdLayer::update_column), this, 0.05, false);
    Director::getInstance()->getScheduler()->schedule(schedule_selector(birdLayer::update_bird), this, 0.05, false);
    
}

void birdLayer::birdRun()
{

    Point birdPosition=bird->getPosition();
    
    Size floorSize=floor->getContentSize();
    float time=(birdPosition.y-150)/123;
    bird->runAction(MoveTo::create(time, Point(birdPosition.x,floorSize.height+40)));
}
void birdLayer::update_column(float dt)
{

    Point columnPosition1=columnUnder1->getPosition();
    Point columnPosition2=columnUnder2->getPosition();
    
    Size columnSize=columnUnder1->getContentSize();
    if (columnPosition1.x<=-columnSize.width)
    {
        removeChild(columnUnder1);
        removeChild(columnOn1);
        initColumn1();
        
    }
    if (columnPosition2.x<=-columnSize.width)
    {
        removeChild(columnUnder2);
        removeChild(columnOn2);
        initColumn2();
    }
}


void birdLayer::update_bird(float dt)
{
    if (gameFlag&&!runFlag)
    {
        birdRun();
    }
    Point birdPosition=bird->getPosition();
    Size birdSize=bird->getContentSize();
    Size floorSize=floor->getContentSize();
    
    //屏幕同一时间只有4根柱子
    Point columnPosition1=columnUnder1->getPosition();
    Point columnPosition2=columnOn1->getPosition();
    Point columnPosition3=columnUnder2->getPosition();
    Point columnPosition4=columnOn2->getPosition();
    
    if (birdPosition.x>columnPosition1.x&&columnFlag1)
    {
        count++;
        string num=StringUtils::toString(count);
        pLabelAtlas->setString(num);
        if (MainLayer::soundFlag)
        {
            pointSound();
        }
        columnFlag1=false;
    }
    if (birdPosition.x>columnPosition3.x&&columnFlag2)
    {
        count++;
        string num=StringUtils::toString(count);
        pLabelAtlas->setString(num);
        if (MainLayer::soundFlag)
        {
            pointSound();
        }
        columnFlag2=false;
    }
    
  
//碰撞检测
    auto birdRect=Rect(birdPosition.x,birdPosition.y,birdSize.width/2,birdSize.height/2);
    //floor
    auto floorRect=Rect(0,0,floorSize.width,floorSize.height);
    if (birdRect.intersectsRect(floorRect))
    {
        if (gameFlag&&MainLayer::soundFlag)
        {
            dieSound();
        }
        //log("碰撞地面");
        
        gameOver();
    }
    //columnUnder1
    auto columnUnder1Rect=Rect(columnPosition1.x,columnPosition1.y,columnUnder1->getContentSize().width,columnUnder1->getContentSize().height);
    if (birdRect.intersectsRect(columnUnder1Rect))
    {
        if (gameFlag&&MainLayer::soundFlag)
        {
            dieSound();
        }
        //log("碰撞柱子");
        
        gameOver();
    }

    //columnUNder2
    auto columnUnder2Rect=Rect(columnPosition3.x,columnPosition3.y,columnUnder2->getContentSize().width,columnUnder2->getContentSize().height);
    
    if (birdRect.intersectsRect(columnUnder2Rect))
    {
        if (gameFlag&&MainLayer::soundFlag)
        {
            dieSound();
        }
        log("碰撞柱子");
        
        gameOver();
    }
    //columnOn1
    auto columnOn1Rect=Rect(columnPosition2.x,columnPosition2.y,columnOn1->getContentSize().width,columnOn1->getContentSize().height);
    
    if (birdRect.intersectsRect(columnOn1Rect))
    {
        if (gameFlag&&MainLayer::soundFlag)
        {
            dieSound();
        }
        //log("碰撞柱子");
        
        gameOver();
    }

    //columnOn2
    auto columnOn2Rect=Rect(columnPosition4.x,columnPosition4.y,columnOn2->getContentSize().width,columnOn2->getContentSize().height);
    
    if (birdRect.intersectsRect(columnOn2Rect))
    {
        if (gameFlag&&MainLayer::soundFlag)
        {
            dieSound();
        }
       // log("碰撞柱子");
        
        gameOver();
    }
    
}

void birdLayer::gameOver()
{

    gameFlag=false;
    Point birdPosition=bird->getPosition();
    Size birdSize=bird->getContentSize();
    Size floorSize=floor->getContentSize();
    floor->stopAllActions();
    columnOn1->stopAllActions();
    columnOn2->stopAllActions();
    columnUnder2->stopAllActions();
    columnUnder1->stopAllActions();
    
    bird->stopAllActions();
    bird->runAction(Sequence::create(Spawn::createWithTwoActions(MoveTo::create(0.2, Point(birdPosition.x,floorSize.height+birdSize.width/2)),RotateTo::create(0.2, 90)),NULL));
    
    
    if (!overFlag)
    {
        replay();
    }

}
void birdLayer::replay()
{

    
    
    overFlag=true;
    
    string medal;
    removeChild(pLabelAtlas);
    Sprite* over =Sprite::create("gameOver.png");
    over->setPosition(Point(270,1200));
    this->addChild(over,10);
    
    overRank=Sprite::create("scoreOver.png");
    overRank->setPosition(Point(270,-100));
    this->addChild(overRank,10);
    
    replayItem=MenuItemImage::create("replay.png", "replay_off.png", CC_CALLBACK_1(birdLayer::menuCallBack0, this));
    replayItem->setPosition(Point(150,-250));
    menuItem=MenuItemImage::create("menu.png", "menu_off.png", CC_CALLBACK_1(birdLayer::menuCallBack1, this));
    menuItem->setPosition(Point(380,-250));
    
    Menu* menu=Menu::create(replayItem,menuItem, NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu,10);
    
    
    rankBirdLayer *rank=rankBirdLayer::create();
    //实例化了，无法实现rankbirdLayer的读取
    rank->load();
    rank->save(count);
    
    int i=atoi(rank->scoreBird[0].c_str());
    string tempScore=StringUtils::format("%d",count);
    Label * newScore=Label::createWithTTF(tempScore, "FZKATJW.ttf", 50,Size::ZERO,TextHAlignment::LEFT,TextVAlignment::TOP);
    
    newScore->setColor(Color3B::YELLOW);
    newScore->enableOutline(Color4B(187,187,187,255),2);
    overRank->addChild(newScore);
    newScore->setPosition(Point(320,130));
    
    if (i<count)
    {
        Label* ss=Label::createWithTTF(tempScore,"FZKATJW.ttf",50,Size::ZERO,TextHAlignment::LEFT,TextVAlignment::TOP);
        ss->setColor(Color3B::YELLOW );
        ss->enableOutline(Color4B(187,187,187,255),2);
        overRank->addChild(ss);
        ss->setPosition(Point(320,50));
        
    }
    else
    {
    
        Label* ss=Label::createWithTTF(rank->scoreBird[0], "FZKATJW.ttf", 50,Size::ZERO,TextHAlignment::LEFT,TextVAlignment::TOP ) ;
        ss->setColor(Color3B::YELLOW);
        ss->enableOutline(Color4B(187,187,187,255),2);
        overRank->addChild(ss);
        ss->setPosition(Point(320,50));
    }
    if (count>=atoi(rank->scoreBird[2].c_str()))
    {
        medal="third.png";
        
        if (count>=atoi(rank->scoreBird[1].c_str()))
        {
            medal="slider.png";
            if (count>=atoi(rank->scoreBird[0].c_str()))
            {
                medal="gold.png";
            }
        }
        Sprite* gold=Sprite::create(medal);
        overRank->addChild(gold);
        gold->setPosition(Point(90,88));
    }
    over->runAction(Sequence::create(
                                     MoveTo::create(0.2, Point(270,70)),
                                     CallFunc::create(CC_CALLBACK_0(birdLayer::moveObject, this)),
                                     NULL));
    
    
    
    
}
void birdLayer::moveObject()
{
    overRank->runAction(MoveTo::create(0.6, Point(270,550)));
    replayItem->runAction(MoveTo::create(0.6, Point(150,380)));
    menuItem->runAction(MoveTo::create(0.6, Point(380,380)));

}
void birdLayer::menuCallBack0(cocos2d::Ref *pSender)
{
    sceneManager->goToFlappyScene(1);
}
void birdLayer::menuCallBack1(cocos2d::Ref *pSender)
{
    sceneManager->goToMainScene();
}

void birdLayer::initColumn1()
{
    Size visibleSize=Director::getInstance()->getVisibleSize();
    Size backSzie=backGround->getContentSize();
    Size floorSize=floor->getContentSize();
    
    int i=random();
    int height1=400/i;
    int height2=backSzie.height-height1-196;
    
    //SpriteBatchNode：一次性绘制多个相同的图像
    SpriteBatchNode* columnNode1=SpriteBatchNode::create("column1.png");
    SpriteBatchNode* columnNode2=SpriteBatchNode::create("column2.png");
    columnFlag1=true;
    
    //Scale9Sprite的用法
    columnUnder1=Scale9Sprite::create();
    columnUnder1->updateWithBatchNode(columnNode1, Rect(0,0,96,400), false, Rect(0,0,96,370));//?
    
    columnUnder1->setContentSize(Size(96,height1));
    columnUnder1->setAnchorPoint(Point(0,0));
    if (count>0)
    {
        columnUnder1->setPosition(Point(visibleSize.width,floorSize.height));
    }
    else
    {
        columnUnder1->setPosition(Point(visibleSize.width*2,floorSize.height));
    
    }

    columnOn1=Scale9Sprite::create();
    columnOn1->updateWithBatchNode(columnNode2, Rect(0,0,96,400), false, Rect(0,0,96,370));//?
    columnOn1->setContentSize(Size(96,height2));
    columnOn1->setAnchorPoint(Point(0,0));
    if (count>0)
    {
        columnOn1->setPosition(Point(visibleSize.width,visibleSize.height-height2));
    }
    else
    {
        columnOn1->setPosition(Point(visibleSize.width*2,visibleSize.height-height2));
    
    }
    this->addChild(columnUnder1);
    this->addChild(columnOn1,0);
    columnUnder1->runAction(RepeatForever::create(MoveBy::create(0.1, Point(-25,0))));
    columnOn1->runAction(RepeatForever::create(MoveBy::create(0.1, Point(-25,0))));
    
}

void birdLayer::initColumn2()
{
    columnFlag2=true;
    Size visibleSize=Director::getInstance()->getVisibleSize();
    Size backSize=backGround->getContentSize();
    Size floorSize=floor->getContentSize();
    
    int i=random();
    
    int height1=400/i;
    int height2=backSize.height-height1-196;
    Point columnPosition=columnUnder1->getPosition();
    
    SpriteBatchNode* columnNode1=SpriteBatchNode::create("column1.png");
    SpriteBatchNode* columnNode2=SpriteBatchNode::create("column2.png");
    columnUnder2=Scale9Sprite::create();
    columnUnder2->updateWithBatchNode(columnNode1, Rect(0,0,96,400), false, Rect(0,0,96,370));
    columnUnder2->setAnchorPoint(Point(0,0));
    columnUnder2->setContentSize(Size(96,height1));
    columnUnder2->setPosition(Point(columnPosition.x+320,floorSize.height));
    columnOn2=Scale9Sprite::create();
    columnOn2->updateWithBatchNode(columnNode2, Rect(0,0,96,400), false, Rect(0,0,96,370));
    columnOn2->setAnchorPoint(Point(0,0));
    columnOn2->setPosition(Point(columnPosition.x+320,visibleSize.height-height2));
    this->addChild(columnOn2,0);
    this->addChild(columnUnder2,0);
    columnOn2->runAction(RepeatForever::create(MoveBy::create(0.1, Point(-25,0))));
    columnUnder2->runAction(RepeatForever::create(MoveBy::create(0.1, Point(-25,0))));


}

void birdLayer::pointSound()
{}
void birdLayer::wingSound()
{}
void birdLayer::dieSound()
{}
bool birdLayer::onTouchPause(Ref* pSender)
{
    if (!gameFlag)
    {
        return  false;
    }
    if (!stopFlag)
    {
           stopFlag=true;
        pause->setTexture("continue_pause.png");
        Director::getInstance()->pause();
        
        pauseBack=Sprite::create("setBackground.png");
        pauseBack->setPosition(Point(270,600));
        this->addChild(pauseBack,10);
        
        Sprite* music=Sprite::create("music.png");
        pauseBack->addChild(music);
        music->setPosition(120,300);
        
        
        CheckBox* checkMenu=CheckBox::create("sound.png", "sound_off.png", "sound_off.png", "sound_stop.png", "sound_stop.png");
        pauseBack->addChild(checkMenu,1);
        checkMenu->::birdLayer::setPosition(350,300);
        checkMenu->setSelected(!MainLayer::musicFlag);
        checkMenu->addEventListener(CC_CALLBACK_2(birdLayer::selectedEvent0, this));
        
        MenuItemImage* conItem = MenuItemImage::create(
                                                       "continue.png",
                                                       "continue_off.png",
                                                       CC_CALLBACK_1(::birdLayer::menuCallBack3, this) //µ„ª˜ ±÷¥––µƒªÿµ˜∑Ω∑®
                                                       );
        conItem->setPosition(Point(80, 80));
        //∑µªÿ÷˜≤Àµ•
        MenuItemImage* backItem = MenuItemImage::create(
                                                        "menu.png",
                                                        "menu_off.png",
                                                        CC_CALLBACK_1(::birdLayer::menuCallBack2, this) //µ„ª˜ ±÷¥––µƒªÿµ˜∑Ω∑®
                                                        );
        backItem->setPosition(Point(225, 80));
        //∑µªÿ÷˜≤Àµ•
        MenuItemImage* againItem = MenuItemImage::create(
                                                         "replay.png",
                                                         "replay_off.png",
                                                         CC_CALLBACK_1(::birdLayer::menuCallBack4, this) //µ„ª˜ ±÷¥––µƒªÿµ˜∑Ω∑®
                                                         );
        againItem->setPosition(Point(370, 80));
        
        Menu* menu = Menu::create(againItem, conItem, backItem, NULL);
        //…Ë÷√≤Àµ•Œª÷√
        menu->setPosition(Point::ZERO);
        pauseBack->addChild(menu,1);

        
    }
 
    
    
    
    
    
    
    
    return  true;
}

void birdLayer::selectedEvent0(cocos2d::Ref *pSender, CheckBox::EventType type)
{

    switch (type)
    {
        case cocos2d::ui::CheckBox::EventType::SELECTED:
            CocosDenshion::SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
            MainLayer::musicFlag=false;
            break;
            
            case cocos2d::ui::CheckBox::EventType::UNSELECTED:
            CocosDenshion::SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
            MainLayer::musicFlag=true;
            break;
        default:
            break;
    }

}

void birdLayer::menuCallBack3(cocos2d::Ref *pSender)
{
    stopFlag=false;
    this->removeChild(pauseBack);
    pause->setTexture("pause.png");
    Director::getInstance()->resume();

}
void birdLayer::menuCallBack2(cocos2d::Ref *pSender)
{
    Director::getInstance()->resume();
    sceneManager->goToMainScene();

}
void birdLayer::menuCallBack4(cocos2d::Ref *pSender)
{
    Director::getInstance()->resume();
    sceneManager->goToFlappyScene(1);

}
