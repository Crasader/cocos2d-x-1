#include "HelloWorldScene.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
   //创建物理场景
    auto scene = Scene::createWithPhysics();
    
    //绘制调试框
   // scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
  
    
    auto layer = HelloWorld::create();
    scene->addChild(layer);
    return scene;
}


bool HelloWorld::init()
{
   
    if ( !Layer::init() )
    {
        return false;
    }
    

    
    


    addBird();
    //initWorld();
    addBarContainer();
    addGround();
    
    setTouchEnabled(true);
    setTouchMode(Touch::DispatchMode::ONE_BY_ONE);
    
    
    //每秒调用addBar一次
   schedule(schedule_selector(HelloWorld::addBar), 1);
 

    //碰撞监测
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
    groundBody->setGravityEnable(false);
    backGround->setPhysicsBody(groundBody);
    backGround->setPosition(backGround->getContentSize().width/2 ,backGround->getContentSize().height/2);
    addChild(backGround);


}
void HelloWorld::addBar(float dt){
    
    //bar的随机偏移量
    offset=-rand()%50;
    
    auto size =Director::getInstance()->getVisibleSize();
    auto up_bar=Sprite::create("up_bar.png");

    
    
    auto up_barBody=PhysicsBody::createBox(up_bar->getContentSize());
    up_barBody->setContactTestBitmask(0xFFFFFFFF);
    up_barBody->setVelocity(Point(-100,0));
    up_barBody->setGravityEnable(false);
    up_bar->setPhysicsBody(up_barBody);
    up_bar->setPosition(size.width/2+110,size.height/2+up_bar->getContentSize().height+offset);
    barContainer-> addChild(up_bar);

    
    
    
      auto down_bar=Sprite::create("down_bar.png");
    auto down_barBody=PhysicsBody::createBox(down_bar->getContentSize());
    down_barBody->setContactTestBitmask(0xFFFFFFFF);
    down_barBody->setVelocity(Point(-100,0));
    down_barBody->setGravityEnable(false);
    down_bar->setPhysicsBody(down_barBody);
    down_bar->setPosition(size.width/2+110,size.height/2-up_bar->getContentSize().height/2-offset);
    barContainer->addChild(down_bar);

    

    }


bool HelloWorld::onTouchBegan(cocos2d::Touch *t, cocos2d::Event *e){

    bird->getPhysicsBody()->setVelocity(Point(0,80));   //seVelocity()

    return false;
}

//创建一个barContainer，以便主函数先添加bar，再添加地板，使得地板遮盖bar。
void HelloWorld::addBarContainer(){
    barContainer=Sprite::create();
    addChild(barContainer);
}



void HelloWorld:: stopGame(){
    
    //停止addBar的更新
  unschedule(schedule_selector(HelloWorld::addBar));
    
//判断得分————————————————————————————————
    // 获取物理世界的所有刚体，返回值为Vector<PhysicsBody *>
    auto bodies=bird->getPhysicsBody()->getWorld()->getAllBodies();
    

    
    //遍历vector,找到已经经过小鸟的bar
    //body为bodies遍历时，每次取出的元素
    for (const auto& body:bodies) {
        if (body->getPosition().x<0) {
            score=score+1;
        }
        
        
        
    }

    //显示分数的label，必须传入const char*类型
    auto label=Label::create("0", "Courier", 50);
    label->setPosition(100,100);
    label->setColor(Color3B::RED);
    this->addChild(label);
    
    //转换为const char＊类型
    auto strScore=__String::createWithFormat("%d",score/2);
    label->setString(strScore->getCString() );
    


    
    //终止游戏
    Director::getInstance()->pause();
    
    
}


bool HelloWorld::ContactBegin(cocos2d::PhysicsContact &contact){
    
    //getNode()返回值为Node类型，需要转换为Sprite类型
            auto spriteA = static_cast<Sprite *>(contact.getShapeA()->getBody()->getNode());
            auto spriteB=static_cast<Sprite *>(contact.getShapeB()->getBody()->getNode());
            if (spriteA->getTag() == 123 ||spriteB->getTag() ==123 ){
                MessageBox("failed", "failed");
                                stopGame();
                return false;
            }
    return false;
}


