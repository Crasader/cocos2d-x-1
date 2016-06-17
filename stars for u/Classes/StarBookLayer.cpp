//
//  StarBookLayer.cpp
//  MyCppGame
//
//  Created by zwj on 16/6/16.
//
//

#include "StarBookLayer.hpp"


StarBookLayer* StarBookLayer::create()
{

    StarBookLayer* layer=new StarBookLayer();
    
    if (layer&&layer->init())
    {
        layer->autorelease();
        return  layer;
    }
    
    CC_SAFE_DELETE(layer);
    return nullptr;
}


bool StarBookLayer::init()
{
    if (!Layer::init())
    {
        return false;
    }
    
    size=Director::getInstance()->getVisibleSize();
   
    
    
    //book
    
     bookSprite=Sprite::create("book.png");
    bookSprite->setScale(0.8,0.7);
    bookSprite->setPosition(Point(size.width/2,size.height/2));
    this->addChild(bookSprite,0);
    
    
    
    //bookMark
    int i=UserDefault::getInstance()->getIntegerForKey("age", 0);
    //生成书签
    BookMark(i);
    
   
   
        return  true;
}


//书签
void  StarBookLayer::BookMark(int i)
{
    switch (i)
    {
        case 0:
            
            auto bookMarkSprite=Sprite::create("book mark.png");
            bookMarkSprite->setPosition(Point(900,500));
            bookSprite->addChild(bookMarkSprite);
            
           
            
            
            break;
            
    }



}

void StarBookLayer::label0Callback(cocos2d::Ref *pSender)
{
    log("oooo");

}


