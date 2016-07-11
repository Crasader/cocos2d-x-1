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
#include "shopLayer.hpp"



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
    
    //日记内容
    labelText=Label::createWithTTF("", "fonts/china.ttf", 25);
    labelText->setColor(Color3B::RED);
    labelText->setDimensions(size.width/4+50, size.height/2);
    labelText->setPosition(size.width/4+50,size.height/2);
    this->addChild(labelText,1);
    
    //日记string
    age0String="嗯，是的，他来了！......................";
    age10String="哦哦哦，他突然间已经10岁了！！！................ ";
    age15String="你已经是个大人样了，但是在我眼里，你永远是那个跟我要星星的孩子。............";
    age20String="嘿，儿子。大学的生活怎么样？爸爸的眼睛越来越不中用了，感觉天上的星星越来越多啊。不过，既然你好不容易回来一次，咱们去摘星星吧！";
    age25String="一转眼他已经25岁了。他已经习惯了一个人在外生活了吧。 而且我已经不能像过去那样轻易地摘到星星了。但是总想为他做些什么。嗯，要不，就这样吧，用梯子！";
    
    //bookMark
    age=UserDefault::getInstance()->getIntegerForKey("age", 0);
    //生成书签页数量
    //age传入
    BookMark(age);

    
    
    
    
    //开始游戏按钮
    auto goMenuLabel=Label::createWithTTF("摘星星！", "fonts/china.ttf", 40);
    goMenuLabel->setColor(Color3B::RED);
    auto goMenuButton=MenuItemLabel::create(goMenuLabel, CC_CALLBACK_0(StarBookLayer::startGame, this));
    goMenuButton->setPosition(Point(687,122));
  
    
    
    //交互按钮
    auto interButton=MenuItemImage::create("intertack.png", "intertack.png", CC_CALLBACK_1(StarBookLayer::shopCallBack, this));
    interButton->setPosition(size.width/4, size.height/4);
       auto menu=Menu::create(goMenuButton,interButton, NULL);
    menu->setPosition(0,0);
    this->addChild(menu,10);
    auto interLabel=Label::createWithTTF("互动", "fonts/china.ttf", 30);
    interLabel->setColor(Color3B::RED);
    interLabel->setPosition(interButton->getPosition()+Point(0,-40));
    this->addChild(interLabel);
    
  
    
    
    

    
     return  true;
}


//书签
void  StarBookLayer::BookMark(int bookMarkIndex)
{
    
    switch (bookMarkIndex)
    {

            
            
        case 25:
            
        {
        
            //第一次日记的效果
            int age25= UserDefault::getInstance()->getIntegerForKey("25", 1);
            if (age25==1)
            {
                
                UserDefault::getInstance()->setIntegerForKey("25", 0);
                
                auto bookMarkSprite25=Sprite::create("mark25.png");
                auto bookMarkSprite25_s=Sprite::create("mark25.png");
                bookMarkSprite25_s->setScale(1.2);
                
                auto markButton25=MenuItemSprite::create(bookMarkSprite25, bookMarkSprite25_s, CC_CALLBACK_1(StarBookLayer::label25Callback, this));
                markButton25->runAction(Sequence::create(
                                                         ScaleTo::create(0, 0),
                                                         DelayTime::create(2.0f),
                                                         ScaleTo::create(0.1, 0.8),
                                                         
                                                         ScaleTo::create(0.1, 1.6),
                                                         ScaleTo::create(0.1, 2.0),
                                                         ScaleTo::create(0.1, 1.6),
                                                         ScaleTo::create(0.1, 1),
                                                         NULL));
                markButton25->setPosition(Point(889,213));
                auto menu=Menu::create(markButton25, NULL);
                menu->setPosition(0,0);
                this->addChild(menu,markIndex,54);
                
                //大透明背景
                //日记打字效果
                auto bg2=Sprite::create("bg2.png");
                bg2->setPosition(size.width/2,size.height/2);
                this->addChild(bg2,markIndex+10);
                bg2->setOpacity(100);
                bg2->runAction(Sequence::create(DelayTime::create(10.0),RemoveSelf::create(), NULL));
                dirayString=age25String;
                labelText->setPosition(size.width/2+50,size.height/2);
                labelText->setScale(1.5);
                labelText->runAction(Sequence::create(DelayTime::create(10.0),Spawn::create(MoveTo::create(1.0f, Point(size.width/4+50,size.height/2)), ScaleTo::create(1.0f, 1.0f),NULL), NULL));
              //  this->addChild(labelText,markIndex+11);
                
                this->schedule(schedule_selector(StarBookLayer::textOut), 0.05);
                
                
            }
            
            else
            {
            
            auto bookMarkSprite25=Sprite::create("mark25.png");
            auto bookMarkSprite25_s=Sprite::create("mark25.png");
            bookMarkSprite25_s->setScale(1.2);
            
            auto markButton25=MenuItemSprite::create(bookMarkSprite25, bookMarkSprite25_s, CC_CALLBACK_1(StarBookLayer::label25Callback, this));
            markButton25->setPosition(Point(889,213));
            auto menu=Menu::create(markButton25, NULL);
            menu->setPosition(0,0);
            this->addChild(menu,markIndex,54);
            
          
            //如果是当前mark，则显示其内容
            if (bookMarkIndex==25)
            {
                
                
                labelText->setString(age25String);
              // this->addChild(labelText,markIndex);
               
            }
  }
            
        }
            
        case 20:
        {
             //第一次日记的效果
            int age20= UserDefault::getInstance()->getIntegerForKey("20", 1);
            if (age20==1)
            {
                
                UserDefault::getInstance()->setIntegerForKey("20", 0);
                
                auto bookMarkSprite25=Sprite::create("mark20.png");
                auto bookMarkSprite25_s=Sprite::create("mark20.png");
                bookMarkSprite25_s->setScale(1.2);
                
                auto markButton25=MenuItemSprite::create(bookMarkSprite25, bookMarkSprite25_s, CC_CALLBACK_1(StarBookLayer::label25Callback, this));
                markButton25->runAction(Sequence::create(ScaleTo::create(0, 0),
                                                         DelayTime::create(2.0f),
                                                         ScaleTo::create(0.1, 0.8),
                                                         
                                                         ScaleTo::create(0.1, 1.6),
                                                         ScaleTo::create(0.1, 2.0),
                                                        ScaleTo::create(0.1, 1.6),
                                                         ScaleTo::create(0.1, 1),

                                                         NULL));
                markButton25->setPosition(Point(889,296));
                auto menu=Menu::create(markButton25, NULL);
                menu->setPosition(0,0);
                this->addChild(menu,markIndex-1,54);
                
                //大透明背景
                //日记打字效果
                auto bg2=Sprite::create("bg2.png");
                bg2->setPosition(size.width/2,size.height/2);
                this->addChild(bg2,markIndex+10);
                bg2->setOpacity(100);
                bg2->runAction(Sequence::create(DelayTime::create(15.0),RemoveSelf::create(), NULL));
                dirayString=age20String;
                labelText->setPosition(size.width/2+50,size.height/2);
                labelText->setScale(1.5);
                labelText->runAction(Sequence::create(DelayTime::create(15.0),Spawn::create(MoveTo::create(1.0f, Point(size.width/4+50,size.height/2)), ScaleTo::create(1.0f, 1.0f),NULL), NULL));
               // this->addChild(labelText,markIndex+11);
                
                this->schedule(schedule_selector(StarBookLayer::textOut), 0.05);
                
            }
            else
            {
            //显示获得的星座和相应日记
            if (bookMarkIndex==20)
            {
                setGetedConsent(20);
                 labelText->setString(age20String);
            }
            
            auto bookMarkSprite20=Sprite::create("mark20.png");
            auto bookMarkSprite20_s=Sprite::create("mark20.png");
            bookMarkSprite20_s->setScale(1.2);

            auto markButton20=MenuItemSprite::create(bookMarkSprite20, bookMarkSprite20_s, CC_CALLBACK_1(StarBookLayer::label20Callback, this));
            markButton20->setPosition(Point(889,296));
            auto menu=Menu::create(markButton20, NULL);
            menu->setPosition(0,0);
            this->addChild(menu,markIndex-1,53);

          }
        }
            
            case 15:
        {
             //第一次日记的效果
            int age15= UserDefault::getInstance()->getIntegerForKey("15", 1);
            if (age15==1)
            {
                
                UserDefault::getInstance()->setIntegerForKey("15", 0);
                
                auto bookMarkSprite25=Sprite::create("mark15.png");
                auto bookMarkSprite25_s=Sprite::create("mark15.png");
                bookMarkSprite25_s->setScale(1.2);
                
                auto markButton25=MenuItemSprite::create(bookMarkSprite25, bookMarkSprite25_s, CC_CALLBACK_1(StarBookLayer::label25Callback, this));
                markButton25->runAction(Sequence::create(ScaleTo::create(0, 0),
                                                         DelayTime::create(2.0f),
                                                         ScaleTo::create(0.1, 0.8),
                                                         
                                                         ScaleTo::create(0.1, 1.6),
                                                         ScaleTo::create(0.1, 2.0),
                                                         ScaleTo::create(0.1, 1.6),
                                                         ScaleTo::create(0.1, 1),

                                                         NULL));
                markButton25->setPosition(Point(889,379));
                auto menu=Menu::create(markButton25, NULL);
                menu->setPosition(0,0);
                this->addChild(menu,markIndex-2,54);
                
                
                
                //大透明背景
                //日记打字效果
                auto bg2=Sprite::create("bg2.png");
                bg2->setPosition(size.width/2,size.height/2);
                this->addChild(bg2,markIndex+10);
                bg2->setOpacity(100);
                bg2->runAction(Sequence::create(DelayTime::create(10.0),RemoveSelf::create(), NULL));
                dirayString=age15String;
                labelText->setPosition(size.width/2+50,size.height/2);
                labelText->setScale(1.5);
                labelText->runAction(Sequence::create(DelayTime::create(10.0),Spawn::create(MoveTo::create(1.0f, Point(size.width/4+50,size.height/2)), ScaleTo::create(1.0f, 1.0f),NULL), NULL));
                //this->addChild(labelText,markIndex+11);
                
                this->schedule(schedule_selector(StarBookLayer::textOut), 0.05);
            }
            else
            {
            //显示获得的星座
            if (bookMarkIndex==15)
            {
                setGetedConsent(15);
                labelText->setString(age15String);
            }
            auto bookMarkSprite15=Sprite::create("mark15.png");
          auto bookMarkSprite15_s=Sprite::create("mark15.png");
            bookMarkSprite15_s->setScale(1.2);
            auto markButton15=MenuItemSprite::create(bookMarkSprite15, bookMarkSprite15_s, CC_CALLBACK_1(StarBookLayer::label15Callback, this));
            markButton15->setPosition(Point(889,379));
            auto menu=Menu::create(markButton15, NULL);
            menu->setPosition(0,0);
           this->addChild(menu,markIndex-2,52);
          
            //如果是当前mark，则显示其内容
            if (bookMarkIndex==15)
            {
                
              
                 //this->addChild(labelText,markIndex-2);
            }
        }
        }
            
            
            
            //age=10
        case 10:
        {
             //第一次日记的效果
            int age10= UserDefault::getInstance()->getIntegerForKey("10", 1);
            if (age10==1)
            {
                
                UserDefault::getInstance()->setIntegerForKey("10", 0);
                
                auto bookMarkSprite25=Sprite::create("mark10.png");
                auto bookMarkSprite25_s=Sprite::create("mark10.png");
                bookMarkSprite25_s->setScale(1.2);
                
                auto markButton25=MenuItemSprite::create(bookMarkSprite25, bookMarkSprite25_s, CC_CALLBACK_1(StarBookLayer::label25Callback, this));
                markButton25->runAction(Sequence::create(ScaleTo::create(0, 0),
                                                         DelayTime::create(2.0f),
                                                         ScaleTo::create(0.1, 0.8),
                                                         
                                                         ScaleTo::create(0.1, 1.6),
                                                         ScaleTo::create(0.1, 2.0),
                                                         ScaleTo::create(0.1, 1.6),
                                                         ScaleTo::create(0.1, 1),

                                                         NULL));
                markButton25->setPosition(Point(889,462));
                auto menu=Menu::create(markButton25, NULL);
                menu->setPosition(0,0);
                this->addChild(menu,markIndex-3,54);
                
                
                //大透明背景
                //日记打字效果
                auto bg2=Sprite::create("bg2.png");
                bg2->setPosition(size.width/2,size.height/2);
                this->addChild(bg2,markIndex+10);
                bg2->setOpacity(100);
                bg2->runAction(Sequence::create(DelayTime::create(10.0),RemoveSelf::create(), NULL));
                
                dirayString=age10String;
                labelText->setPosition(size.width/2+50,size.height/2);
                labelText->setScale(1.5);
                labelText->runAction(Sequence::create(DelayTime::create(10.0),Spawn::create(MoveTo::create(1.0f, Point(size.width/4+50,size.height/2)), ScaleTo::create(1.0f, 1.0f),NULL), NULL));
                
                this->schedule(schedule_selector(StarBookLayer::textOut), 0.05);
                
                
                         }
            else
            {
            //显示获得的星座
            if (bookMarkIndex==10)
            {
                  setGetedConsent(10);
                labelText->setString(age10String);

            }
            auto bookMarkSprite10=Sprite::create("mark10.png");
            auto bookMarkSprite10_2=Sprite::create("mark10.png");
            bookMarkSprite10_2->setScale(1.2);

            
            auto markButton10=MenuItemSprite::create(bookMarkSprite10, bookMarkSprite10_2, CC_CALLBACK_1(StarBookLayer::label10Callback, this));
            markButton10->setPosition(Point(889,462));
          
            auto menu=Menu::create(markButton10, NULL);
            menu->setPosition(0,0);
            this->addChild(menu,markIndex-3,51);
           
        }
        
        }
            
            
            
    //age=0
        case 0:
        {
            if (bookMarkIndex==0)
            {
                setGetedConsent(0);
            }
            
            
            
            auto bookMarkSprite0=Sprite::create("mark0.png");
           auto bookMarkSprite0_2=Sprite::create("mark0.png");
            bookMarkSprite0_2->setScale(1.2);
            
            auto markButton0=MenuItemSprite::create(bookMarkSprite0, bookMarkSprite0_2, CC_CALLBACK_1(StarBookLayer::label0Callback, this));
            markButton0->setPosition(Point(889,545));
           
            auto menu=Menu::create(markButton0, NULL);
            menu->setPosition(0,0);
            this->addChild(menu,markIndex-4,50);
            
            if (bookMarkIndex==0)
            {
//
                labelText->setString(age0String);
                
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
    int j=0;
    for (int i=0; i<12; i++)
    {
       // __String*str=static_cast<__String*>( arry->objectAtIndex(i));
       
        //int a =str->intValue();
        if (arry[i].asInt()==1)
        {
            conllenVecetor.at(i)->setVisible(true);
           
            conllenVecetor.at(i)->setPosition(Point(580+k*110,520-j*110));
            k++;
            if (k%3==0)
            {
                ++j;
                k=0;
            }
        }
        else
        {
            conllenVecetor.at(i)->setVisible(false);
            
        }
        
    }


}



//////////////
void StarBookLayer::startGame()
{
    getAllgetedConsetn();
    switch (age) {
        case 0:
        {//第一关，1颗星星
            gsm->goinfoLayer(4, 0, 1);
           // gsm->goLadderLayer(1,1);
            break;
        }
        case 10:
        {//设置关卡数据
            int starNum=random(6, 10);
            int shinNum=random(2, 5);
            
            //星座概率出现
             //方便设置标记已获取的星座，就不再出现
            getAllgetedConsetn();
            int conNum=random(0, 20);
         //getedCon前12个元素为1-12,其余为0，获取了号星座为0, 防止重复出现
            gsm->goMenuLayer(starNum, shinNum,getedCon[conNum]);
            
            break;
        }
        case 15:
        {//设置关卡数据
            int starNum=random(11, 15);
            int shinNum=random(5, 8);
            
            //星座概率出现
            //方便设置标记已获取的星座，就不再出现
            getAllgetedConsetn();
            int conNum=random(0, 20);
            //getedCon前12个元素为1-12,其余为0，获取了号星座为0, 防止重复出现
            gsm->goMenuLayer(starNum, shinNum,getedCon[conNum]);
            
            break;
        }
        case 20:
        {//设置关卡数据
            int starNum=random(16, 20);
            int shinNum=random(10, 15);
            
            //星座概率出现
            //方便设置标记已获取的星座，就不再出现
            getAllgetedConsetn();
            int conNum=random(0, 12);
            //getedCon前12个元素为1-12,其余为0，获取了号星座为0, 防止重复出现
            gsm->goMenuLayer(starNum, shinNum,getedCon[conNum]);
            
            break;
        }
            
        case 25:
        {//梯子关
            bool firstTime=UserDefault::getInstance()->getBoolForKey("LADDER", false);
            if (firstTime)
            {
                gsm->goLadderLayer(1, 1);
                
                UserDefault::getInstance()->setBoolForKey("LADDER", true);
            }
            else
            {
            //关卡信息
                
                int wind=random(-5, 5);
                int cloud=random(2, 5);
                
                gsm->goLadderLayer(wind, cloud);
            
            }
            
            
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
    int arrName[]={0,10,15,20};
    for (int i=0; i<sizeof(arrName)/sizeof(int); i++)
    {
        
        char key[12];
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

//标签按钮回调
//age:0
void StarBookLayer::label0Callback(cocos2d::Ref *pSender)
{
    
    //跳转到选择的页，并显示内容
    
    
    setGetedConsent(0);
    labelText->setString(age0String);
    
    this->reorderChild(this->getChildByTag(50),markIndex);
    
    
    
    
}


//age:10
void StarBookLayer::label10Callback(cocos2d::Ref *pSender)
{
    
    setGetedConsent(10);
    labelText->setString(age10String);
     this->reorderChild(this->getChildByTag(51),markIndex);
   
}

void StarBookLayer::label15Callback(cocos2d::Ref *pSender)
{

    setGetedConsent(15);
    labelText->setString(age15String);
  this->reorderChild(this->getChildByTag(52),markIndex);

}

void StarBookLayer::label20Callback(cocos2d::Ref *pSender)
{
    
    setGetedConsent(20);
    labelText->setString(age20String);
    this->reorderChild(this->getChildByTag(53),markIndex);
    
}

void StarBookLayer::label25Callback(cocos2d::Ref *pSender)
{
    
    labelText->setString(age25String);
    this->reorderChild(this->getChildByTag(54),markIndex);
    
}


//shop 回调
void StarBookLayer::shopCallBack(cocos2d::Ref *pSender)
{


   
        shopLayer* layer=shopLayer::create();
       // layer->setAnchorPoint(Point(0.5,0.5));
        
        layer->setPosition(0,0);
        layer->runAction(Sequence::create(
                                          ScaleTo::create(0.1, 0),
                                          ScaleTo::create(0.1, 0.3),
                                          ScaleTo::create(0.1, 0.6),
                                          ScaleTo::create(0.1, 0.8),
                                          ScaleTo::create(0.1, 1),
                                          NULL));
    
        this->addChild(layer,2000);
      
        
    
        
    
   


}



//打字效果回调
void StarBookLayer::textOut(float dt)
{
    if (textStr==dirayString)
    {
        textIndex=0;
        unschedule(schedule_selector(StarBookLayer::textOut));
        
    }
    else
    {

    textStr= dirayString.substr(0,textIndex);
    textIndex++;
    labelText->setString(textStr);
    
    }
}