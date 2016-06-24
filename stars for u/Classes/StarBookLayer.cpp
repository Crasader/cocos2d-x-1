//
//  StarBookLayer.cpp
//  MyCppGame
//
//  Created by zwj on 16/6/16.
//
//

#include "StarBookLayer.hpp"
#include "MenuLayer.hpp"
#include <time.h>


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
    //初始化获取的星座数组
   
    for (int i=0; i<12; i++)
    {
        getedCon[i]=i+1;
    }
    
    
    srand(unsigned(time(NULL)));
    
    size=Director::getInstance()->getVisibleSize();
    //创建12星座的Spirte并设置不可见
    auto conllentSprite1=Sprite::create("C1.png");
    conllentSprite1->setVisible(false);
    this->addChild(conllentSprite1,10);
    
    auto conllentSprite2=Sprite::create("C2.png");
    conllentSprite2->setVisible(false);
    this->addChild(conllentSprite2,10);
    
    auto conllentSprite3=Sprite::create("C3.png");
    conllentSprite3->setVisible(false);
    this->addChild(conllentSprite3,10);
    
    auto conllentSprite4=Sprite::create("C4.png");
    conllentSprite4->setVisible(false);
    this->addChild(conllentSprite4,10);
    
    auto conllentSprite5=Sprite::create("C5.png");
    conllentSprite5->setVisible(false);
    this->addChild(conllentSprite5,10);
    
    auto conllentSprite6=Sprite::create("C6.png");
    conllentSprite6->setVisible(false);
    this->addChild(conllentSprite6,10);
    
    auto conllentSprite7=Sprite::create("C7.png");
    conllentSprite7->setVisible(false);
    this->addChild(conllentSprite7,10);
    
    auto conllentSprite8=Sprite::create("C8.png");
    conllentSprite8->setVisible(false);
    this->addChild(conllentSprite8,10);
    
    auto conllentSprite9=Sprite::create("C9.png");
    conllentSprite9->setVisible(false);
    this->addChild(conllentSprite9,10);
    
    auto conllentSprite10=Sprite::create("C10.png");
    conllentSprite10->setVisible(false);
    this->addChild(conllentSprite10,10);
    
    auto conllentSprite11=Sprite::create("C11.png");
    conllentSprite11->setVisible(false);
    this->addChild(conllentSprite11,10);
    
    auto conllentSprite12=Sprite::create("C12.png");
    conllentSprite12->setVisible(false);
    this->addChild(conllentSprite12,10);
    
    conllenVecetor.pushBack(conllentSprite1);
    conllenVecetor.pushBack(conllentSprite2);
     conllenVecetor.pushBack(conllentSprite3);
    conllenVecetor.pushBack(conllentSprite4);
    conllenVecetor.pushBack(conllentSprite5);
    conllenVecetor.pushBack(conllentSprite6);
    conllenVecetor.pushBack(conllentSprite7);
    conllenVecetor.pushBack(conllentSprite8);
    conllenVecetor.pushBack(conllentSprite9);
    conllenVecetor.pushBack(conllentSprite10);
    conllenVecetor.pushBack(conllentSprite11);
    conllenVecetor.pushBack(conllentSprite12);
    
    //book
    
    bookSprite=Sprite::create("book.png");
    //bookSprite->setScale(1, 0.86);
    bookSprite->setPosition(Point(size.width/2,size.height/2));
    this->addChild(bookSprite,0);
    
    
    
    //bookMark
    age=UserDefault::getInstance()->getIntegerForKey("age", 0);
    //生成书签页数量
    //age传入
    BookMark(10);
    

    //开始游戏按钮
    auto goMenuLabel=Label::createWithSystemFont("Go for stars", "Marker Felt.ttf", 40);
    goMenuLabel->setColor(Color3B::RED);
    auto goMenuButton=MenuItemLabel::create(goMenuLabel, CC_CALLBACK_0(StarBookLayer::startGame, this));
    goMenuButton->setPosition(Point(687,122));
    auto menu=Menu::create(goMenuButton, NULL);
    menu->setPosition(0,0);
    this->addChild(menu,10);
    
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
    
    std::string writablePath=FileUtils::getInstance()->getWritablePath();
    std::string fullPath=writablePath+"List.plist";
    //auto root=__Dictionary::createWithContentsOfFile(fullPath.c_str());
    auto root=FileUtils::getInstance()->getValueMapFromFile(fullPath.c_str());
    bool isExit=false;
    isExit=FileUtils::getInstance()->isFileExist(fullPath);
    if (!isExit)
    {
        log("no plist");
    }
    
    
    //auto arry=static_cast<__Array*>(root->objectForKey(buf));
    auto arry=root[buf].asValueVector();
    
    //显示
    int k=0;//坐标偏移
    for (int i=0; i<12; i++)
    {
       // __String*str=static_cast<__String*>( arry->objectAtIndex(i));
       
        //int a =str->intValue();
        if (arry[i].asInt()==1)
        {
            conllenVecetor.at(i)->setVisible(true);
            conllenVecetor.at(i)->setPosition(Point(580+k*110,520));
            k++;
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
  
  //跳转到选择的页，并显示内容
    
 
            setGetedConsent(0);
           diary->setTexture("man2.png");
    
    
  

}


//age:10
void StarBookLayer::label10Callback(cocos2d::Ref *pSender)
{
    
     setGetedConsent(10);
     diary->setTexture("diary_0.png");
        
    

    
}

//////////////
void StarBookLayer::startGame()
{
    getAllgetedConsetn();
    switch (age) {
        case 0:
        {//第一关，1颗星星
           //gsm->goMenuLayer(1, 0, 0);
            gsm->goMenuLayer(8, 4,1);
            break;
        }
        case 10:
        {//设置关卡数据
            int starNum=random(6, 10);
            int shinNum=random(2, 5);
            
            //星座概率出现
             //方便设置标记已获取的星座，就不再出现
            getAllgetedConsetn();
            int conNum=random(0, 99);
         //getedCon前12个元素为1-12,其余为0，获取了号星座为0, 防止重复出现
            gsm->goMenuLayer(starNum, shinNum,getedCon[conNum]);
            
            break;
        }
        default:
            break;
    }

 


}


//获取所有已经得到的星座

void StarBookLayer::getAllgetedConsetn()
{
    
    auto sharedFile=FileUtils::getInstance();
    auto writablePath=sharedFile->getWritablePath();
    std:: string path=writablePath+"List.plist";
   // auto root=__Dictionary::createWithContentsOfFile(path.c_str());
    auto root=FileUtils::getInstance()->getValueMapFromFile(path.c_str());

    //章节
    int arrName[]={0,10};
    for (int i=0; i<sizeof(arrName)/sizeof(int); i++)
    {
        
        char key[4];
        sprintf(key, "A%d",arrName[i]);
//        auto dataArr=static_cast<__Array*>(root->objectForKey(key));
        auto arr= root[key].asValueVector();
        
        
        
        
        for (int j=0; j<12; j++)
        {
//            __String* str=static_cast<__String*>(dataArr->getObjectAtIndex(j));
//            int value=str->intValue();
            if (arr[j].asInt()==1)
            {
                
                getedCon[j]=0;
                
            }
            
        }
        
        
        
    }



}