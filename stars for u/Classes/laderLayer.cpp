//
//  laderLayer.cpp
//  MyCppGame
//
//  Created by zwj on 16/6/30.
//
//

#include "laderLayer.hpp"
#define PTM_RATIO 32


laderLayer::laderLayer(int windNum, int cloudNum)
{
    wind=windNum;

    cloud=cloudNum;

}

laderLayer* laderLayer::create(int windNum, int cloudNum)
{

    laderLayer *layer=new laderLayer(windNum,cloudNum);
    
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
    
//bg
    auto bg=Sprite::create("bg_L.png");
    bg->setPosition(Point(size.width/2,size.height/2));
    this->addChild(bg);
    
    bodyVector.resize(100);
    bodyVector.clear();
    
    //box2d
    this->initPhysic();


    auto ladderbacthnode=SpriteBatchNode::create("ladder_s.png");

    
    scheduleUpdate();
    //touch
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
    
    
    //随机出现的云
    auto cloud_s=Sprite::create("cloud_S.png");
    cloud_s->setTag(1000);
    float x=random(100, 800);
    float y=random(250, 500);
    cloud_s->setPosition(x,y);
    this->addChild(cloud_s);
    
    b2BodyDef cloudBodyDef;
    cloudBodyDef.type=b2_dynamicBody;
    cloudBodyDef.position.Set(x/PTM_RATIO, y/PTM_RATIO);
    
    b2Body* cloudBody=world->CreateBody(&cloudBodyDef);
    cloudBody->SetUserData(cloud_s);
    cloudBody->ApplyLinearImpulse(b2Vec2(-1, 0), cloudBody->GetPosition(), true);
    cloudBody->SetGravityScale(0);
    
    b2PolygonShape cloudBox;
    cloudBox.SetAsBox(2, 1);
    
    b2FixtureDef cloudFix;
    cloudFix.shape=&cloudBox;
    cloudFix.density=50;
    cloudFix.friction=0.1;
    cloudFix.restitution=0;
    cloudBody->CreateFixture(&cloudFix);
    
    
   
    
  
    return  true;
}

//返回
void laderLayer::goBackCallBack(cocos2d::Ref *pSender)
{

    gsm->goBookLayer();

}
//box2d的update
void laderLayer::update(float dt)
{

    float timeStep = 0.03f;
    int32 velocityIterations = 8;
    int32 positionIterations =1;
    int i1=0;
    
    world->Step(timeStep, velocityIterations, positionIterations);
    
    //sprite移动
    for (b2Body* b = world->GetBodyList(); b; b = b->GetNext())
    {
        if (b->GetUserData() != nullptr) {
            Sprite* sprite = (Sprite*)b->GetUserData();
            sprite->setPosition( Vec2( b->GetPosition().x *
                                      PTM_RATIO, b->GetPosition().y * PTM_RATIO) );
           
           // sprite->setRotation( -1 * CC_RADIANS_TO_DEGREES(b->GetAngle()) );
            
            if (sprite->getPosition().y<=sprite->getContentSize().height)
            {
                i1++;
                log("i=====%d",i1);
            }
            if (i1>=2)
            {
                this->pause();
                log("falie");
            }
        
           
            
            
        }
    }
    
    
    //胜利判断
    int i =k;
    int index=0;
        
        while(i>1)
        {
            
            if (this->getChildByTag(i)->getBoundingBox().intersectsRect(this->getChildByTag(i-1)->getBoundingBox()))
            {
                index++;
                log("i=%d",index);
                
            }
            i--;
            
        }
        
    
    
    
    if ( index==k-1  &&k>2)
    {
        if (this->getChildByTag(k)->getBoundingBox().intersectsRect(star->getBoundingBox()))
        {
            this->pause();
            
        }
        
    }
   
    
    
    
    
    
}





//
bool laderLayer::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event)
{
    
    k++;
    auto size=Director::getInstance()->getVisibleSize();
    auto ladderbacthnode=SpriteBatchNode::create("ladder_s.png");
    
    auto touchPoint=touch->getLocation();
    
    
    
    //ladder
    auto ladder=Sprite::createWithTexture(ladderbacthnode->getTexture());
    ladder->setPosition(touch->getLocation());
    ladder->setTag(k);
    this->addChild(ladder);
    
    
    
    return true;

}


//

void laderLayer::onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *event)
{

   
    this->getChildByTag(k)->setPosition(touch->getLocation());
 
    //放大提示
    for (int i=1; i<=k; i++)
        
    {
        this->getChildByTag(i)->setScale(1.5);
        
    }
    



}

void laderLayer::onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *event)
{

    //放大提示
    
    for (int i=1; i<=k; i++)
        
    {
        this->getChildByTag(i)->setScale(1.0);
        
    }

   
    //wuliqingying
    b2BodyDef bodyDef;
    bodyDef.type=b2_dynamicBody;
    float32 x=touch->getLocation().x;
    float32 y=touch->getLocation().y;
    bodyDef.position.Set(x/PTM_RATIO,y/PTM_RATIO);
    b2Body* body=world->CreateBody(&bodyDef);
    
    bodyVector.push_back(body);
    //5层以上有随机外力
    if (k>=5)
    {
        //引入风向
        body->ApplyLinearImpulse(b2Vec2(1, 0), body->GetPosition(), true);
        int x=random(20,30)*wind;
        log("x=%d",x);
        bodyVector.at(k/2)->ApplyLinearImpulse(b2Vec2(x, 0), bodyVector.at(k/2)->GetPosition(), true);
        bodyVector.at(k/2-1)->ApplyLinearImpulse(b2Vec2(x, 0), bodyVector.at(k/2-1)->GetPosition(), true);
        bodyVector.at(k/2+1)->ApplyLinearImpulse(b2Vec2(x, 0), bodyVector.at(k/2+1)->GetPosition(), true);
    }
    
    body->SetUserData(this->getChildByTag(k));
    
    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(0.8, 0.8);
    
    b2FixtureDef fixtureDef;
    fixtureDef.shape=&dynamicBox;
    //midu
    fixtureDef.density=100;
    //moca
    fixtureDef.friction=0.5;
    
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
  

}