//
//  laderLayer.cpp
//  MyCppGame
//
//  Created by zwj on 16/6/30.
//
//

#include "laderLayer.hpp"
#define PTM_RATIO 32




laderLayer* laderLayer::create()
{

    laderLayer *layer=new laderLayer();
    
    if (layer&&layer->init())
    {
        layer->autorelease();
        return layer;
    }
    CC_SAFE_DELETE(layer);
    return nullptr;
}

bool laderLayer::init()
{
    if (!Layer::init())
    {
        return false;
    }

    
    auto size=Director::getInstance()->getVisibleSize();
    

    auto bg=Sprite::create("bg_L.png");
    bg->setPosition(Point(size.width/2,size.height/2));
    this->addChild(bg);
    
    
    
    //box2d
    this->initPhysic();
    

    
    auto ladderbacthnode=SpriteBatchNode::create("ladder_s.png");

    //ladder
    auto ladder=Sprite::createWithTexture(ladderbacthnode->getTexture());
    ladder->setPosition(size.width/2,ladder->getContentSize().height*0.7);
    this->addChild(ladder);
    
    //wuliqingying
    b2BodyDef bodyDef;
    bodyDef.type=b2_dynamicBody;
    bodyDef.position.Set(size.width/2/PTM_RATIO, ladder->getContentSize().height*0.7/PTM_RATIO);
    b2Body* body=world->CreateBody(&bodyDef);
    body->SetUserData(ladder);
    
    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(1, 1);
    
    b2FixtureDef fixtureDef;
    fixtureDef.shape=&dynamicBox;
    fixtureDef.density=1.0;
    fixtureDef.friction=0.3;
    body->CreateFixture(&fixtureDef);
    
    scheduleUpdate();
    //
    
    setTouchEnabled(true);
    setTouchMode(ccTouchesMode::ONE_BY_ONE);
    setSwallowsTouches(true);
    
    
   star=Sprite::create("star_L.png");
    star->setPosition(400,400);
    this->addChild(star);
    

    //zanting
    auto pasueLabel=Label::createWithSystemFont("Pause", "Marker Felt.ttf", 40);
    pasueLabel->setColor(Color3B::RED);
    auto pasueButton=MenuItemLabel::create(pasueLabel,CC_CALLBACK_1(laderLayer::goBackCallBack, this));
    pasueButton->setPosition(pasueButton->getContentSize().width/2+5,size.height-pasueButton->getContentSize().height);
    auto menu=Menu::create(pasueButton, NULL);
    menu->setPosition(0,0);
    this->addChild(menu);
    
    this->schedule(schedule_selector(laderLayer::starFunc), 0.1);
    return  true;
}


void laderLayer::goBackCallBack(cocos2d::Ref *pSender)
{

    gsm->goBookLayer();

}

void laderLayer::update(float dt)
{

    float timeStep = 0.03f;
    int32 velocityIterations = 8;
    int32 positionIterations = 1;
    
    
    world->Step(timeStep, velocityIterations, positionIterations);
    
    
    for (b2Body* b = world->GetBodyList(); b; b = b->GetNext())
    {
        if (b->GetUserData() != nullptr) {
            Sprite* sprite = (Sprite*)b->GetUserData();
            sprite->setPosition( Vec2( b->GetPosition().x *
                                      PTM_RATIO, b->GetPosition().y * PTM_RATIO) );
            sprite->setRotation( -1 * CC_RADIANS_TO_DEGREES(b->GetAngle()) );
        }
    }
}




void laderLayer::starFunc(float dt)
{

    



}


bool laderLayer::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event)
{
    
    auto size=Director::getInstance()->getVisibleSize();
    auto ladderbacthnode=SpriteBatchNode::create("ladder_s.png");
    
    
    //ladder
    auto ladder=Sprite::createWithTexture(ladderbacthnode->getTexture());
    ladder->setPosition(touch->getLocation());
    this->addChild(ladder);
    
    //wuliqingying
    b2BodyDef bodyDef;
    bodyDef.type=b2_dynamicBody;
    float32 x=touch->getLocation().x;
    float32 y=touch->getLocation().y;
    bodyDef.position.Set(x/PTM_RATIO,y/PTM_RATIO);
    b2Body* body=world->CreateBody(&bodyDef);
    body->SetUserData(ladder);
    
    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(0.8, 0.8);
    
    b2FixtureDef fixtureDef;
    fixtureDef.shape=&dynamicBox;
    //midu
    fixtureDef.density=100;
    //moca
    fixtureDef.friction=1.0;
    
    //tanxing
    fixtureDef.restitution=0;

    body->CreateFixture(&fixtureDef);



}


void laderLayer::initPhysic()
{
    Size s = Director::getInstance()->getVisibleSize();
    //重力参数
    b2Vec2 gravity;                                                         
    gravity.Set(0.0f, -10.0f);
    //创建世界
    world = new b2World(gravity);
    // 允许物体是否休眠
    world->SetAllowSleeping(true);
    // 开启连续物理测试
    world->SetContinuousPhysics(true);
    
    //地面物体定义
    b2BodyDef groundBodyDef;
    //左下角
    groundBodyDef.position.Set(0, 0);
    
    
    //创建地面物体
    b2Body* groundBody = world->CreateBody(&groundBodyDef);
    
    
    //定义一个有边的形状
    b2EdgeShape groundBox;
    
    
    // 底部
    groundBox.Set(b2Vec2(0,0), b2Vec2(s.width/PTM_RATIO,0));
    //使用夹具固定形状到物体上
    groundBody->CreateFixture(&groundBox,0);
    
    
    // 顶部
    groundBox.Set(b2Vec2(0,s.height/PTM_RATIO),
                  b2Vec2(s.width/PTM_RATIO,s.height/PTM_RATIO));
    groundBody->CreateFixture(&groundBox,0);
    
    
    // 左边
    groundBox.Set(b2Vec2(0,s.height/PTM_RATIO), b2Vec2(0,0));
    groundBody->CreateFixture(&groundBox,0);
    
    
    // 右边
    groundBox.Set(b2Vec2(s.width/PTM_RATIO,s.height/PTM_RATIO),
                  b2Vec2(s.width/PTM_RATIO,0));
    groundBody->CreateFixture(&groundBox,0);
    
    



}

void laderLayer::onExit()
{
    Layer::onExit();
  CC_SAFE_DELETE(world);
    log("delete world");

}