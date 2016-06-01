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
    pause->setPosition(Point(32,928));
    auto menuItem=MenuItemSprite::create(pause, pause, CC_CALLBACK_1(birdLayer::onTouchPause, this));

    
    
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
    log("111111\n");
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
        log("碰撞地面");
        
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
        log("碰撞柱子");
        
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
        log("碰撞柱子");
        
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
        log("碰撞柱子");
        
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
        //replay();
    }

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
     log("222222\n");
    return  true;
}

