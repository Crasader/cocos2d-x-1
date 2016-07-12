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
    int starY=random(500, 600);
    int starX=random(200, 700);
    star->setPosition(starX,starY);
    this->addChild(star);
    

    //zanting
    //auto pasueLabel=Label::createWithSystemFont("Pause", "Marker Felt.ttf", 40);
    auto pasueLabel=Label::createWithTTF("暂停", "fonts/china.ttf", 40);


    pasueLabel->setColor(Color3B::RED);
    auto pasueButton=MenuItemLabel::create(pasueLabel,CC_CALLBACK_1(laderLayer::goBackCallBack, this));
    pasueButton->setPosition(pasueButton->getContentSize().width/2+5,size.height-pasueButton->getContentSize().height);
    auto menu=Menu::create(pasueButton, NULL);
    menu->setPosition(0,0);
    this->addChild(menu);
    
    
    //风力提示
    char windBuf[128];
    char *dirBuf;
    sprintf(windBuf, "风力:%d 级",abs(wind));
   
    if (wind<0)
    {
        dirBuf="风向: 左";
    }
    if (wind>0)
    {
        dirBuf="风向: 右";
    }
    
    //风力
    auto windLabel=Label::createWithTTF(windBuf, "fonts/china.ttf", 40);
    windLabel->setColor(Color3B::RED);
    windLabel->setPosition(windLabel->getContentSize().width/2+5,size.height-pasueButton->getContentSize().height-50);
    this->addChild(windLabel);
    
    //风向
    auto windDirLabel=Label::createWithTTF(dirBuf, "fonts/china.ttf", 40);
    windDirLabel->setColor(Color3B::RED);
    windDirLabel->setPosition(windDirLabel->getContentSize().width/2+5,size.height-pasueButton->getContentSize().height-100);
    this->addChild(windDirLabel);

    //随机出现的云
    for (int i=0; i<cloud; i++)
    {
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
        int Impluse=random(-2, 2);
        cloudBody->ApplyLinearImpulse(b2Vec2(Impluse, 0), cloudBody->GetPosition(), true);
        cloudBody->SetGravityScale(0);
        b2PolygonShape cloudBox;
        cloudBox.SetAsBox(2, 1);
        b2FixtureDef cloudFix;
        cloudFix.shape=&cloudBox;
        cloudFix.density=50;
        cloudFix.friction=0.1;
        cloudFix.restitution=0;
        cloudBody->CreateFixture(&cloudFix);

    }
    
   
    
  
    return  true;
}

//返回
void laderLayer::goBackCallBack(cocos2d::Ref *pSender)
{

    //结束游戏
    int gameOver=UserDefault::getInstance()->getIntegerForKey("GROWTH", 0);
    //结束需要的成长值////////////////////////////////////////////////////////////
    if (gameOver>=2)
    {
        gsm->goGameOverLayer();
       
        
        
    }
else
{
    gsm->goBookLayer();
}
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
             //失败判断，有两个的位置低于箱子高度
            if (sprite->getPosition().y<=sprite->getContentSize().height/2)
            {
                i1++;
              
            }
                    }
    }
    //失败
    if (i1>=2)
    {
        this->pause();
        fail();
    }
    
    //胜利判断
    int i =k;
    int index=0;
        
        while(i>1)
        {
            //每个箱子都想接
            if (this->getChildByTag(i)->getBoundingBox().intersectsRect(this->getChildByTag(i-1)->getBoundingBox()))
            {
                index++;
               
                
            }
            i--;
            
        }
        
    
    
    
    if ( index==k-1  &&k>2)
    {
        if (this->getChildByTag(k)->getBoundingBox().intersectsRect(star->getBoundingBox()))
        {
            this->pause();
            win();
            
            
            
        }
        
    }
   

}
//fail

void laderLayer::fail()
{

    auto size=Director::getInstance()->getVisibleSize();
    int growth=UserDefault::getInstance()->getIntegerForKey("GROWTH", 0);
    int relation=UserDefault::getInstance()->getIntegerForKey("RELATION", 0);
    growth+=1;
    
    UserDefault::getInstance()->setIntegerForKey("GROWTH", growth);
    
    
    //背景
    auto bookSprite=Sprite::create("book_s.png");
    bookSprite->setPosition(size.width/2,size.height/2);
    bookSprite->setScale(0, 0);
    this->addChild(bookSprite,1000);
    
    //label
    char buf[128]={0};
    sprintf(buf, "成长值:%d",growth);
    auto growthLabel=Label::createWithTTF(buf, "fonts/china.ttf", 40);
    growthLabel->setColor(Color3B::RED);
    growthLabel->setPosition(Point(bookSprite->getContentSize().width/4,bookSprite->getContentSize().height-100));
    //bookSprite->addChild(growthLabel);
    
    
    sprintf(buf, "亲密值:%d",relation);
    auto relationLabel=Label::createWithTTF(buf, "fonts/china.ttf", 40);
    relationLabel->setColor(Color3B::RED);
    relationLabel->setPosition(Point(bookSprite->getContentSize().width/4,bookSprite->getContentSize().height-150));
    bookSprite->addChild(relationLabel);
    
    //弹出效果
    bookSprite->runAction(Sequence::create(ScaleTo::create(0, 0),ScaleTo::create(0.1, 0.2),ScaleTo::create(0.1, 0.5),ScaleTo::create(0.1, 0.8), ScaleTo::create(0.1, 1),NULL));
    
    
    
    //确定按钮
    auto okLabel=Label::createWithSystemFont("OK", "Marker Felt.ttf", 40);
    okLabel->setColor(Color3B::RED);
    auto okButton=MenuItemLabel::create(okLabel,CC_CALLBACK_1(laderLayer::goBackCallBack, this));
    okButton->setPosition(bookSprite->getContentSize().width/4,bookSprite->getContentSize().height/4);
    auto menu=Menu::create(okButton, NULL);
    menu->setPosition(0,0);
    bookSprite->addChild(menu);
    
    //失败提示
    auto failLabel=Label::createWithTTF("失败\n看来我已经老了。。", "fonts/china.ttf", 25);
     failLabel->setColor(Color3B::RED);
    failLabel->setPosition(Point(3*bookSprite->getContentSize().width/4+10,bookSprite->getContentSize().height-100));
    failLabel->runAction(Sequence::create(FadeOut::create(0.0),FadeIn::create(2.0f), NULL));
    bookSprite->addChild(failLabel);
    
    
    
}

//win
void laderLayer::win()
{
    auto size=Director::getInstance()->getVisibleSize();
    int growth=UserDefault::getInstance()->getIntegerForKey("GROWTH", 0);
    int relation=UserDefault::getInstance()->getIntegerForKey("RELATION", 0);
    
    growth++;
    relation+=5;
    
    UserDefault::getInstance()->setIntegerForKey("GROWTH", growth);
    UserDefault::getInstance()->setIntegerForKey("RELATION", relation);
    
    //背景
    auto bookSprite=Sprite::create("book_s.png");
    bookSprite->setPosition(size.width/2,size.height/2);
    bookSprite->setScale(0, 0);
    this->addChild(bookSprite,1000);
    
    //label
    char buf[128];
    sprintf(buf, "成长值:%d",growth);
    auto growthLabel=Label::createWithTTF(buf, "fonts/china.ttf", 40);
    growthLabel->setColor(Color3B::RED);
    growthLabel->setPosition(Point(bookSprite->getContentSize().width/4,bookSprite->getContentSize().height-100));
    //bookSprite->addChild(growthLabel);
    
    sprintf(buf, "亲密值:%d",relation);
    auto relationLabel=Label::createWithTTF(buf, "fonts/china.ttf", 40);
    relationLabel->setColor(Color3B::RED);
    relationLabel->setPosition(Point(bookSprite->getContentSize().width/4,bookSprite->getContentSize().height-150));
    bookSprite->addChild(relationLabel);
    
    //弹出效果
    bookSprite->runAction(Sequence::create(ScaleTo::create(0, 0),ScaleTo::create(0.1, 0.2),ScaleTo::create(0.1, 0.5),ScaleTo::create(0.1, 0.8), ScaleTo::create(0.1, 1),NULL));
    
    
    
    //确定按钮
    auto okLabel=Label::createWithSystemFont("OK", "Marker Felt.ttf", 40);
    okLabel->setColor(Color3B::RED);
    auto okButton=MenuItemLabel::create(okLabel,CC_CALLBACK_1(laderLayer::goBackCallBack, this));
    okButton->setPosition(bookSprite->getContentSize().width/4,bookSprite->getContentSize().height/4);
    auto menu=Menu::create(okButton, NULL);
    menu->setPosition(0,0);
    bookSprite->addChild(menu);
    
    
    //win提示
    auto winLabel=Label::createWithTTF("成功!\n看来我还可以为他做点什么！", "fonts/china.ttf", 25);
    winLabel->setColor(Color3B::RED);
    winLabel->setPosition(Point(3*bookSprite->getContentSize().width/4+10,bookSprite->getContentSize().height-100));
    winLabel->runAction(Sequence::create(FadeOut::create(0.0),FadeIn::create(2.0f), NULL));
    bookSprite->addChild(winLabel);
    



}


//触摸
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
    if (k>=5&&k<8)
    {
        //引入风向
        body->ApplyLinearImpulse(b2Vec2(1, 0), body->GetPosition(), true);
        int x=random(50,60)*wind;
        log("x=%d",x);
        bodyVector.at(k/2)->ApplyLinearImpulse(b2Vec2(x, 0), bodyVector.at(k/2)->GetPosition(), true);
        bodyVector.at(k/2-1)->ApplyLinearImpulse(b2Vec2(x, 0), bodyVector.at(k/2-1)->GetPosition(), true);
        bodyVector.at(k/2+1)->ApplyLinearImpulse(b2Vec2(x, 0), bodyVector.at(k/2+1)->GetPosition(), true);
    }
    if (k>=8)
    {
        //引入风向
        body->ApplyLinearImpulse(b2Vec2(1, 0), body->GetPosition(), true);
        int x=random(60,80)*wind;
        log("x=%d",x);
        bodyVector.at(k/2)->ApplyLinearImpulse(b2Vec2(x, 0), bodyVector.at(k/2)->GetPosition(), true);
        bodyVector.at(k/2-1)->ApplyLinearImpulse(b2Vec2(x, 0), bodyVector.at(k/2-1)->GetPosition(), true);
        bodyVector.at(k/2+1)->ApplyLinearImpulse(b2Vec2(x, 0), bodyVector.at(k/2+1)->GetPosition(), true);
        bodyVector.at(1)->ApplyLinearImpulse(b2Vec2(x, 0), bodyVector.at(1)->GetPosition(), true);
        bodyVector.at(2)->ApplyLinearImpulse(b2Vec2(x, 0), bodyVector.at(2)->GetPosition(), true);
        bodyVector.at(3)->ApplyLinearImpulse(b2Vec2(x, 0), bodyVector.at(3)->GetPosition(), true);
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


