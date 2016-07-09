//
//  gameOverLayer.cpp
//  MyCppGame
//
//  Created by zwj on 16/7/6.
//
//

#include "gameOverLayer.hpp"
#include <string>
#include <algorithm>


bool gameOverLayer::init()
{

    if (!Layer::init())
    {
        return  false;
    }
    size=Director::getInstance()->getVisibleSize();
    
    
    
    
    
    labelString="Time flies. Someday, I will leave.\n I am not rich , I am not famous.\n But I gave you all I have.";
    labelStr="";
     stringLabel=Label::createWithSystemFont(labelStr.c_str(), "Marker Felt.ttf", 40);
    
    stringLabel->setColor(Color3B::RED);
    stringLabel->setPosition(size.width/2,size.height/2);
    
    this->addChild(stringLabel);
    
    this->schedule(schedule_selector(gameOverLayer::labelUpdate), 0.05);
    
    //延迟5秒，字幕放完，回调下一个画面
    stringLabel->runAction(Sequence::create(DelayTime::create(10.0),CallFunc::create(CC_CALLBACK_0(gameOverLayer::okCallBack, this)), NULL));
    
    
    
    
    
    
    

    return true;
}



//label回调
void gameOverLayer::labelUpdate(float dt)
{
    
    if (labelStr==labelString)
    {
        //清零方便其他调用
        strIndex=0;
        unschedule(schedule_selector(gameOverLayer::labelUpdate));
        
    }
    else
    {
    labelStr=labelString.substr(0,strIndex);
    
    strIndex++;
    
    stringLabel->setString(labelStr);

    }
}
//字幕回调
void gameOverLayer::okCallBack()
{
    //
stringLabel->runAction(Sequence::create(FadeOut::create(2.0),CallFunc::create(CC_CALLBACK_0(gameOverLayer::labelOverCallback, this)), NULL));
    
    
    
}

//字幕结束回调
void gameOverLayer::labelOverCallback()
{
    //获取所有数据
    int growth=UserDefault::getInstance()->getIntegerForKey("GROWTH", 0);
    int relation=UserDefault::getInstance()->getIntegerForKey("RELATION", 0);
    int age=UserDefault::getInstance()->getIntegerForKey("age", 0);
    
    int EXAM=UserDefault::getInstance()->getIntegerForKey("EXAM", 0);
    int FAMILY=UserDefault::getInstance()->getIntegerForKey("FAMILY", 0);
    int HOBBY=UserDefault::getInstance()->getIntegerForKey("HOBBY", 0);
    int FRIENDS=UserDefault::getInstance()->getIntegerForKey("FRIENDS", 0);
    
    

    //arr排序
    std::vector<int >arr;
    arr.push_back(EXAM);
    arr.push_back(FAMILY);
    arr.push_back(HOBBY);
    arr.push_back(FRIENDS);
    std::sort(arr.begin(), arr.end());
   
    
    
    if (arr[3]==EXAM)
    {
        labelString="He becomes a PHD.";
    }
    else if(arr[3]==FAMILY)
    {
         labelString="With all the talks we had,\nhe think famliy is the most important.\nHe stay home, behind me, living a sipmple life. ";
    }
    else if (arr[3]==HOBBY)
    {
        labelString="He becomes  a  football player.";
    
    }
    else if (arr[3]==FRIENDS)
    {
    
       labelString="He becomes  a  salesman.";
    }
    stringLabel->runAction(FadeIn::create(0));
    stringLabel->setDimensions(200, 100);
    stringLabel->setPosition(size.width/4,size.height/2);
    this->schedule(schedule_selector(gameOverLayer::labelUpdate), 0.05);
    
   

    
    
    
    
    
    
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
    
    //获得的星座
    int consArr[12]={0};
    //
    auto filePath=FileUtils::getInstance()->getWritablePath();
    std::string fullpath=filePath+"List.plist";
    auto root=FileUtils::getInstance()->getValueMapFromFile(fullpath.c_str());
    
    std::string chapter[4]={"A0","A10","A15","A20"};
    for (int j=0; j<4; j++)
    {
        auto arr=root[chapter[j]].asValueVector();
        for (int i=0; i<12; i++)
        {
            if (arr[i].asInt()==1)
            {
                consArr[i]=1;
                //arr[i]=0; 测试时不清零....///////////////
            }
        }
        root[chapter[j]]=arr;
        FileUtils::getInstance()->writeToFile(root, fullpath.c_str());
    }
    
    int k=0;
    int j=0;
    for (int i=0; i<12; i++)
    {
        if (consArr[i]==1)
        {
            conllenVecetor.at(i)->setScale(0);
            conllenVecetor.at(i)->setVisible(true);
            
            conllenVecetor.at(i)->setPosition(Point(580+k*110,520-j*110));
            conllenVecetor.at(i)->runAction(Sequence::create(ScaleTo::create(0.15, 0.4),
                                                             ScaleTo::create(0.15, 0.7),
                                                             ScaleTo::create(0.15, 1.0),
                                                             NULL));
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
    
    auto sprite=Sprite::create();
    sprite->runAction(Sequence::create(DelayTime::create(5.0f),CallFunc::create(CC_CALLBACK_0(gameOverLayer::labelOverCallback2, this)), NULL));

}


void gameOverLayer::labelOverCallback2()
{








}