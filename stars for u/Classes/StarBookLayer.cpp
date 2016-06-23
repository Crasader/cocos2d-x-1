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
    //创建12星座的Spirte并设置不可见
    auto conllentSprite1=Sprite::create("1.png");
    conllentSprite1->setPosition(Point(640,500));
    conllentSprite1->setVisible(false);
    this->addChild(conllentSprite1,10);
    auto conllentSprite2=Sprite::create("2.png");
    conllentSprite2->setPosition(Point(640,200));
    conllentSprite2->setVisible(false);
    this->addChild(conllentSprite2,10);
    
    conllenVecetor.push_back(conllentSprite1);
    conllenVecetor.push_back(conllentSprite2);
    

    
    
    //book
    
    bookSprite=Sprite::create("book.png");
    //bookSprite->setScale(1, 0.86);
    bookSprite->setPosition(Point(size.width/2,size.height/2));
    this->addChild(bookSprite,0);
    
    
    
    //bookMark
    int i=UserDefault::getInstance()->getIntegerForKey("age", 0);
    //生成书签页数量
    BookMark(10);
    
    
    
        return  true;
}


//书签
void  StarBookLayer::BookMark(int bookMarkIndex)
{
    
    
    
    switch (bookMarkIndex)
    {

            //age=10
        case 10:
        {
            //显示获得的星座
            if (bookMarkIndex==10)
            {
                  setGetedConsent(10);
            }
          
            //book mark
            auto bookMarkSprite10=Sprite::create("mark_gree.png");
            bookMarkSprite10->setPosition(Point(889,462));
            this->addChild(bookMarkSprite10,2);
            
            
            //age label
            auto label10=Label::createWithSystemFont("10", "Marker Felt.ttf", 30);
            auto menuLabel10=MenuItemLabel::create(label10,CC_CALLBACK_1(StarBookLayer::label10Callback, this));
            menuLabel10->setPosition(0,0);

            menu=Menu::create(menuLabel10, NULL);
            menu->setPosition(bookMarkSprite10->getContentSize().width/2,bookMarkSprite10->getContentSize().height/2);
            bookMarkSprite10->addChild(menu,100);

            //如果是当前mark，则显示其内容
            if (bookMarkIndex==10)
            {
                diary=Sprite::create("diary_0.png");
                diary->setPosition(320,320);
                this->addChild(diary,2);
            }
            
        
        }
            
            
            
    //age=0
        case 0:
        {
            if (bookMarkIndex==0)
            {
                setGetedConsent(0);
            }
            
            //book mark
            auto bookMarkSprite0=Sprite::create("mark_red.png");
            bookMarkSprite0->setPosition(Point(889,545));
            this->addChild(bookMarkSprite0,1);
            
            //age label
            auto label0=Label::createWithSystemFont("0", "Marker Felt.ttf", 30);
            auto menuLabel0=MenuItemLabel::create(label0,CC_CALLBACK_1(StarBookLayer::label0Callback, this));
            menuLabel0->setPosition(0,0);
            
            menu=Menu::create(menuLabel0, NULL);
            menu->setPosition(bookMarkSprite0->getContentSize().width/2,bookMarkSprite0->getContentSize().height/2);
            bookMarkSprite0->addChild(menu,100);
            
            
            if (bookMarkIndex==0)
            {
                diary=Sprite::create("man2.png");
                diary->setPosition(320,320);
                this->addChild(diary,2);
            }
            

            
            
            
        }

    }



}
// 显示获得的星座
void StarBookLayer::setGetedConsent(int i)
{
    char buf[4];
    sprintf(buf, "A%d",i);
    
 

    //读取Plist
    auto sharedFileUtis=FileUtils::getInstance();
    std::string writePath=sharedFileUtis->getWritablePath();
    std::string fullPath="List.plist";
    auto root=__Dictionary::createWithContentsOfFile(fullPath.c_str());
    bool isExit=false;
    isExit=sharedFileUtis->isFileExist(fullPath);
    if (!isExit)
    {
        log("wronggg");
    }
    
    
    auto arry=static_cast<__Array*>(root->objectForKey(buf));
    
    
    //显示
    for (int i=0; i<2; i++)
    {
        __String*str=static_cast<__String*>( arry->objectAtIndex(i));
        
        int a =str->intValue();
        if (a==1)
        {
            conllenVecetor.at(i)->setVisible(true);
        }
        else
        {
            conllenVecetor.at(i)->setVisible(false);
            
        }
        
    }


}


//age:0
void StarBookLayer::label0Callback(cocos2d::Ref *pSender)
{
  
  //跳转到选择的mark页，并显示内容
    
 
        setGetedConsent(0);
           diary->setTexture("man2.png");
   

    

}


//age:10
void StarBookLayer::label10Callback(cocos2d::Ref *pSender)
{
    
    setGetedConsent(10);
     diary->setTexture("diary_0.png");
        
    

    
}

