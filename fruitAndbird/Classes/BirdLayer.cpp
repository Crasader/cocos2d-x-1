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
    this->addChild(pLabelAtlas);
    
    pause=Sprite::create("pause.png");
    pause->setPosition(Point(32,928));
    this->addChild(pause,10);
    
    EventListenerTouchOneByOne* listenerPause=EventListenerTouchOneByOne::create();
    listenerPause->setSwallowTouches(true);
    listenerPause->onTouchBegan = CC_CALLBACK_2(birdLayer::onTouchPause, this);
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listenerPause, pause);
    
    initBird();
    bird=Sprite::create();//----------
    bird->setPosition(Point(140+origin.x,origin.y+floor->getContentSize().height+backGround->getContentSize().height/2));
    bird->runAction(RepeatForever::create(animAc));
    auto listener=EventListenerTouchOneByOne::create();
    listener->onTouchBegan=CC_CALLBACK_2(birdLayer::onTouchBegan0, this);
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
    Animate* animte=Animate::create(animation);
    
    
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

    Director::getInstance()->setDepthTest(true);
    effecNode->runAction(SplitRows::create(0.5f, 30));
    initColumn1();
    initColumn2();
    birdRun();
    Director::getInstance()->getScheduler()->schedule(schedule_selector(birdLayer::update_column), this, 0.05, false);
    Director::getInstance()->getScheduler()->schedule(schedule_selector(birdLayer::update_bird), this, 0.05, false);
    
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
    columnUnder1->updateWithBatchNode(columnNode1, Rect(0,0,96,400), false, Rect(0,30,96,400));//?
    columnUnder1->setAnchorPoint(Point(0,0));
    columnUnder1->setContentSize(Size(96,height1));
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
    columnOn1->setAnchorPoint(Point(0,0));
    columnOn1->setContentSize(Size(96,height2));
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


