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
    
    
    
    
    
   
    labelString="时光流逝。总有一天我会离去.虽然，我并不富裕，也没有权力,但我会把我所有的爱都给你。";
    labelStr="";
     stringLabel=Label::createWithTTF(labelStr.c_str(), "fonts/china.ttf", 40);
    stringLabel->setDimensions(size.width/2-20, size.height*0.8);
    
    stringLabel->setColor(Color3B::RED);
    stringLabel->setPosition(size.width/2,size.height/2);
    
    this->addChild(stringLabel);
    
    this->schedule(schedule_selector(gameOverLayer::labelUpdate), 0.03);
    
    //延迟5秒，字幕放完，回调下一个画面
    stringLabel->runAction(Sequence::create(DelayTime::create(5.0),CallFunc::create(CC_CALLBACK_0(gameOverLayer::okCallBack, this)), NULL));
    
    
    
    
    
    
    

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
    stringLabel->setString("");
    
    
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
   
    
    //
    std::string famliyStr1="虽然他很忙，但是他每周都回回来看我。我们经常去看夜空中的星星。";
    std::string famliyStr2="虽然我一直告诉他家庭的重要性，但是，他好像还没明白。自从他工作以后，我们很少见面。";
    std::string hobbyStr1="空闲的时候，他会摆弄他的电子产品，那是他的爱好。有个喜欢的东西真好啊！";
    std::string hobbyStr2="他好像从来没提起过他的业余爱好。我不是给他灌输了太多学习的重要性？希望他找到自己真正喜欢的东西。";
    
    std::string examStr1="他空闲的时候仍然会看书，他说活到老学到老。 看来儿时的教育还是对他相当有影响的。";
    std::string examStr2="虽然他小的时候我经常跟他讲学习的重要性，但是现在看来他好像没怎么听进去。";
    
    std::string friendsStr1="他身边有一群要好的朋友。他们都很喜欢和他相处。";
    std::string friendsStr2="但是他总是孤身一人。或许他小的时候应该多跟他聊聊与他人交往方面的。";
    
    //学习第一
    if (arr[3]==EXAM)
    {
        labelString="他的梦想实现了，他成了一名大学教授。";
        
        if (arr[2]==FAMILY)
        {
            if (FAMILY>=10)
            {
                labelString+=famliyStr1;
            }
            else
            {
            labelString+=famliyStr2;
            }
            
        }
        if (arr[2]==HOBBY)
        {
            if (HOBBY>=10)
            {
                labelString+=hobbyStr1;
            }
            else
            {
                labelString+=hobbyStr2;
            }
            
        }
        if (arr[2]==FRIENDS)
        {
            if (FRIENDS>=10)
            {
                labelString+=friendsStr1;
            }
            else
            {
             labelString+=famliyStr2;
            }
            
        }
        
    }
    
       //家庭第一
    else if(arr[3]==FAMILY)
    {
         labelString="他在外漂泊了几年之后，他仍然觉得家庭是最重要的。他回到了故乡，过着和我一样的生活。";
        
        if (arr[2]==EXAM)
        {
            if (EXAM>=10)
            {
              labelString+=examStr1;
            }
            else
            {
            
            labelString+=examStr2;
                
            }
            
        }
        if (arr[2]==HOBBY)
        {
            if (HOBBY>=10)
            {
               labelString+=hobbyStr1;
            }
            else
            {
             labelString+=hobbyStr2;
            
            }
            
        }
        if (arr[2]==FRIENDS)
        {
            if (FRIENDS>=10)
            {
                labelString+=friendsStr1;
            }
            else
            {
             labelString+=friendsStr2;
            
            }
        }
        
    }
    
    //爱好第一
    else if (arr[3]==HOBBY)
    {
        labelString="他从小就喜欢电脑，现在他成了一名电脑工程师，找到了他喜欢做的事情。";
        if (arr[2]==EXAM)
        {
            if (EXAM>=10)
            {
                labelString+=examStr1;
            }
            else
            {
                
                labelString+=examStr2;
                
            }

        }
        if (arr[2]==FRIENDS)
        {
            if (FRIENDS>=10)
            {
                labelString+=famliyStr1;
            }
            else
            {
                labelString+=friendsStr2;
                
            }
        }

        if (arr[2]==FAMILY)
        {
            if (FAMILY>=10)
            {
                labelString+=famliyStr1;
            }
            else
            {
                labelString+=famliyStr2;
            }
            
        }

        
    
    }
    
    //社交第一
    else if (arr[3]==FRIENDS)
    {
    
       labelString="他很擅于和人打交道。所以他去做销售了。很棒。";
        
        if (arr[2]==EXAM)
        {
            if (EXAM>=10)
            {
                labelString+=examStr1;
            }
            else
            {
                
                labelString+=examStr2;
                
            }
            
        }
        
        if (arr[2]==FAMILY)
        {
            if (FAMILY>=10)
            {
                labelString+=famliyStr1;
            }
            else
            {
                labelString+=famliyStr2;
            }
            
        }
        if (arr[2]==HOBBY)
        {
            if (HOBBY>=10)
            {
                labelString+=hobbyStr1;
            }
            else
            {
                labelString+=hobbyStr2;
                
            }
            
        }

        
        
    }
    stringLabel->runAction(FadeIn::create(0.1));
    stringLabel->setDimensions(size.width/2-20, size.height*0.8);
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