#include "HelloWorldScene.h"

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
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("texture/loading_texture.plist");
    
    //beijing
    auto bg=TMXTiledMap::create("map/red_bg.tmx");
    this->addChild(bg);
    
    //logo
    auto logo=Sprite::createWithSpriteFrameName("logo.png");
    logo->setPosition(visibleSize.width/2,visibleSize.height/2);
    this->addChild(logo);
    
    //loading
    auto loading =Sprite::createWithSpriteFrameName("loding4.png");
    loading->setPosition(logo->getPosition()-Point(0,logo->getContentSize().height/2+30));
    
    //loading donghua
    Animation *animation =Animation::create();
    for (int i=1; i<=4; i++) {
        __String *frameName=__String::createWithFormat("loding%d.png",i);
      SpriteFrame* spriteFrame=  SpriteFrameCache::getInstance()->getSpriteFrameByName(frameName->getCString());
        animation->addSpriteFrame(spriteFrame);
    }
    animation->setDelayPerUnit(0.5);
    animation->setRestoreOriginalFrame(true);
    
    Animate *animate=Animate::create(animation);
    loading->runAction(RepeatForever::create(animate));
    
    
   this-> addChild(loading);
    
    //异步加载缓存
m_nNumberOfLoad=0;
    Director::getInstance()->getTextureCache()->addImageAsync("texture/home_texture.png", CC_CALLBACK_1(HelloWorld::loadingTextureCallback, this)  );// 忘记
    Director::getInstance()->getTextureCache()->addImageAsync("texture/setting_texture.png", CC_CALLBACK_1(HelloWorld::loadingTextureCallback, this)  );
    Director::getInstance()->getTextureCache()->addImageAsync("texture/gameplay_texture.png", CC_CALLBACK_1(HelloWorld::loadingTextureCallback, this)  );
    
    
    
    return true;
}


  //异步加载缓存
void HelloWorld::loadingTextureCallback(cocos2d::Texture2D *texture)
{
    switch (m_nNumberOfLoad++)  //先引用，后增加
    {
        case 0:
            SpriteFrameCache::getInstance()->addSpriteFramesWithFile("texture/home_texture.plist",texture);// 忘记
            break;
        case 1:
            SpriteFrameCache::getInstance()->addSpriteFramesWithFile("texture/setting_texture.plist",texture);
            break;
        case 2:
            SpriteFrameCache::getInstance()->addSpriteFramesWithFile("texture/gameplay_texture.plist",texture);
            break;
    }
    if (m_nNumberOfLoad==3) {
        auto rs=TransitionFlipX::create(0.5,HomeMenuLayer::createScene());
        Director::getInstance()->replaceScene(rs);
    }
  
    
}
