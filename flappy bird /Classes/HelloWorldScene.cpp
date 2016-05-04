#include "HelloWorldScene.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::createWithPhysics();
   // scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
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
    
    


    addBird();
    //initWorld();
    addBarContainer();
    addGround();
    
    setTouchEnabled(true);
    setTouchMode(Touch::DispatchMode::ONE_BY_ONE);
    
   schedule(schedule_selector(HelloWorld::addBar), 1);
 

    
    auto listener =EventListenerPhysicsContact::create();
    listener->onContactBegin = CC_CALLBACK_1(HelloWorld::ContactBegin, this );
    
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
    
         return true;
}


void HelloWorld::addBird(){

    bird=Sprite::create("bird.png");
    bird->setTag(123);
    auto body=PhysicsBody::createBox(bird->getContentSize());
    body->setContactTestBitmask(0xFFFFFFFF);
    bird->setPhysicsBody(body);
    bird->setPosition(50,200);
    addChild(bird);

}
void HelloWorld::initWorld(){
    auto size=Director::getInstance()->getVisibleSize();
    auto edge=PhysicsBody::createEdgeBox(size);
    auto edgeNod=Node::create();
    edgeNod->setPhysicsBody(edge);
    edgeNod->setPosition(size.width/2,size.height/2);
    addChild(edgeNod);

}
void HelloWorld::addGround(){
    auto backGround=Sprite::create("ground.png");
    auto groundBody=PhysicsBody::createBox (backGround->getContentSize());
    groundBody->setContactTestBitmask(0xFFFFFFFF);
    //groundBody->setDynamic(false);
    groundBody->setEnable(false);
    backGround->setPhysicsBody(groundBody);
    backGround->setPosition(backGround->getContentSize().width/2 ,backGround->getContentSize().height/2);
    addChild(backGround);


}
void HelloWorld::addBar(float dt){
    offset=-rand()%50;
    
    auto size =Director::getInstance()->getVisibleSize();
    auto up_bar=Sprite::create("up_bar.png");
    bodyNumber=bodyNumber+2;
    
    
    auto up_barBody=PhysicsBody::createBox(up_bar->getContentSize());
    up_barBody->setContactTestBitmask(0xFFFFFFFF);
    up_barBody->setVelocity(Point(-100,0));
    up_barBody->setGravityEnable(false);
    up_bar->setPhysicsBody(up_barBody);
    up_bar->setPosition(size.width/2+110,size.height/2+up_bar->getContentSize().height);
    barContainer-> addChild(up_bar);

    
    
    
      auto down_bar=Sprite::create("down_bar.png");
    auto down_barBody=PhysicsBody::createBox(down_bar->getContentSize());
    down_barBody->setContactTestBitmask(0xFFFFFFFF);
    down_barBody->setVelocity(Point(-100,0));
    down_barBody->setGravityEnable(false);
    down_bar->setPhysicsBody(down_barBody);
    down_bar->setPosition(size.width/2+110,size.height/2-up_bar->getContentSize().height/2);
    barContainer->addChild(down_bar);

    

    }


bool HelloWorld::onTouchBegan(cocos2d::Touch *t, cocos2d::Event *e){

    bird->getPhysicsBody()->setVelocity(Point(0,80));   //seVelocity()

    return false;
}

void HelloWorld::addBarContainer(){
    barContainer=Sprite::create();
    addChild(barContainer);
}



void HelloWorld:: stopGame(){
  unschedule(schedule_selector(HelloWorld::addBar));
    Vector<PhysicsBody *> bodies=bird->getPhysicsBody()->getWorld()->getAllBodies();
    int i=0;
    for (i; i<=bodyNumber; i++) {
        if (bodies.at(i)->getPosition().x<10) {
            score=score+1;
            
            
                        std::cout<<"score is ::"<<score/2<<std::endl;

        
            
            
        }
        
            }
    //显示分数的label
    auto label=Label::create("0", "Courier", 50);
    label->setPosition(100,100);
    label->setColor(Color3B::RED);
    this->addChild(label);
    CCString *strScore=  CCString::createWithFormat("%d",score/2);
    label->setString(strScore->getCString() );
    //显示分数的label

    
    
    Director::getInstance()->pause();
    
    
}


bool HelloWorld::ContactBegin(cocos2d::PhysicsContact &contact){
    
    
            auto spriteA = (Sprite *)contact.getShapeA()->getBody()->getNode();
            auto spriteB=(Sprite *)contact.getShapeB()->getBody()->getNode();
            if (spriteA->getTag() == 123 ||spriteB->getTag() ==123 ){
         
            
                
          
                
                MessageBox("failed", "failed");
              
        
                
                                stopGame();
                return false;
            }
    return false;
}

void HelloWorld::scoreFunc(float dt){

  
}
