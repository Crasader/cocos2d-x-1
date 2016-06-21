//
//  StarBookLayer.cpp
//  MyCppGame
//
//  Created by zwj on 16/6/16.
//
//

#include "StarBookLayer.hpp"
#include "MenuLayer.hpp"


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
    //生成关卡选择
    BookMark(10);
    
   
   
        return  true;
}


//书签
void  StarBookLayer::BookMark(int i)
{
    switch (i)
    {

            //age=10
        case 10:
        {
            //book mark
            auto bookMarkSprite10=Sprite::create("book mark.png");
            bookMarkSprite10->setPosition(Point(800,350));
            this->addChild(bookMarkSprite10);
            
            
            //age label
            auto label10=Label::createWithSystemFont("age:10", "Marker Felt.ttf", 30);
            auto menuLabel10=MenuItemLabel::create(label10,CC_CALLBACK_1(StarBookLayer::label10Callback, this));
            menuLabel10->setPosition(0,0);

            menu=Menu::create(menuLabel10, NULL);
            menu->setPosition(bookMarkSprite10->getContentSize().width/2,bookMarkSprite10->getContentSize().height/2);
            bookMarkSprite10->addChild(menu,100);

            
        
        }
            
            
            
    //age=0
        case 0:
        {
            //book mark
            auto bookMarkSprite0=Sprite::create("book mark.png");
            bookMarkSprite0->setPosition(Point(800,420));
            this->addChild(bookMarkSprite0);
            
            //age label
            auto label0=Label::createWithSystemFont("age:0", "Marker Felt.ttf", 30);
            auto menuLabel0=MenuItemLabel::create(label0,CC_CALLBACK_1(StarBookLayer::label0Callback, this));
            menuLabel0->setPosition(0,0);
            
            menu=Menu::create(menuLabel0, NULL);
            menu->setPosition(bookMarkSprite0->getContentSize().width/2,bookMarkSprite0->getContentSize().height/2);
            bookMarkSprite0->addChild(menu,100);
            
            
            //日记文字
            
            
            
            
        }

    }



}


//age:0
void StarBookLayer::label0Callback(cocos2d::Ref *pSender)
{
    //5克星星，2个闪闪，1号白羊座
    gsm->goMenuLayer(5,2,1);

}


//age:10
void StarBookLayer::label10Callback(cocos2d::Ref *pSender)
{
  
    //gsm->goStarCollectionLayer();
}

