//
//  MenuLayer.cpp
//  MyCppGame
//
//  Created by zwj on 16/6/13.
//
//

#include "MenuLayer.hpp"
#include "randomStars.hpp"
#include <math.h>
#include "ConstellationSprite.hpp"
#include <string>

//create()方法
MenuLayer* MenuLayer::create(int starNum,int shinStarNum,int collNum)
{

    MenuLayer* layer=new MenuLayer(starNum,shinStarNum,collNum);
    
    if (layer&&layer->init())
    {
        layer->autorelease();
        return layer;
    }
    CC_SAFE_DELETE(layer);
    return nullptr;
}

//构造
MenuLayer::MenuLayer(int starNum, int ShineStar,int collNum)
{
    this->collensation=collNum;
    this->starNum=starNum;
    this->shineStarNum=ShineStar;
    Relation=0;
    relationString=(char*)malloc(sizeof(int));
    rgrowthString=(char*)malloc(sizeof(int));
    lineNum=0;
}

//init()方法

bool MenuLayer::init()
{
    if (!Layer::init())
    {
        return false;
    }
    
    
    
    //亲密值
    Relation= UserDefault::getInstance()->getIntegerForKey("RELATION", 0);
    sprintf(relationString, "亲密值：%d",Relation);
    RelationLabel=Label::createWithSystemFont(relationString, "", 30);
    RelationLabel->setPosition(Point(300,200));
    RelationLabel->setColor(Color3B::WHITE);
    this->addChild(RelationLabel,10);
    
     //成长值
    growth= UserDefault::getInstance()->getIntegerForKey("GROWTH", 0);
    sprintf(rgrowthString, "成长值：%d",growth);
    growthLabel=Label::createWithSystemFont(rgrowthString, "", 30);
    growthLabel->setPosition(Point(300,400));
    growthLabel->setColor(Color3B::WHITE);
    this->addChild(growthLabel,10);
    
    
    //星星的生成：starNum\shineStarNum\collensation
   stars =new randomStars(this,starNum,shineStarNum,collensation);
   size=Director::getInstance()->getVisibleSize();
    
    //背景
    Sprite* backGround=Sprite::create("bg_L.png");
    backGround->setPosition(size.width/2,size.height/2);
   // backGround->setScale(1.2);
    this->addChild(backGround,0);
    

    //布置星星
    stars->randomPosition();
    
    //MAN
    Sprite* man=Sprite::create("man2.png");
    man->setPosition(100,100);
    man->setScale(0.8f);
    this->addChild(man);
    
 
    
    //boy
    Sprite* boy=Sprite::create("boy-hand.png");
    boy->setPosition(200,100);
    boy->setScale(0.8f);
    this->addChild(boy);
    
    //talkingBox
    talkingBox=Sprite::create("talkingBox_L.png");
    talkingBox->setAnchorPoint(Point(0.5,0.5));
    talkingBox->setPosition(370,80);
    this->addChild(talkingBox);

     talkingString="i want that one,dad";
    talkingLabel=Label::createWithSystemFont("", "Marker Felt.ttf", 25);
    talkingLabel->setPosition(160,40);
    talkingLabel->setColor(Color3B::WHITE);
    talkingBox->addChild(talkingLabel);
   
    //schdule（）函数实现打字效果
    this->schedule(schedule_selector(MenuLayer::talkingBoxFunc), 0.1f);
    
    //说完话隐藏
    talkingBox->runAction(Sequence::create(DelayTime::create(5),Hide::create(), NULL));
    
    

 
    
    
    
    //hand
    pointer=Sprite::create("hand.png");
    pointer->setAnchorPoint(Point(0,0.5));
    pointer->setScale(1.5);
    pointer->setPosition(215,95);
    this->addChild(pointer,100);
    pointToStar();

    //开启触摸
    setTouchEnabled(true);
    setSwallowsTouches(true);
    setTouchMode(kCCTouchesOneByOne);


   
   
    
    return true;
}

//talkingBox打字效果回调

void MenuLayer::talkingBoxFunc(float dt)
{
    if (talkingString==talkingStr)
    {
        index=0;
    }
    else
    {
    talkingStr=talkingString.substr(0,index);
    index++;
    talkingLabel->setString(talkingStr.c_str());
    }
}

//触摸监控
bool MenuLayer::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event)
{
    
    
    //触摸点位置
    auto touchPoint=touch->getLocation();
    
    if (stars->starsVector.empty())
    {
        return false;
    }
    
    //判断触摸点是否在其他星星上
    for (int i=0; i<stars->starsVector.size(); i++)
    {
      //触摸点在星星上且不在正确的星星上
        if ((stars->starsVector.at(i)->getBoundingBox().containsPoint(touchPoint))&& stars->starsVector.at(i)!=stars->starsVector.back())
        {
            //提示线
            if (lineShow==false)
            {
                lineNum++;
            }
            
            if (lineNum>=3&&lineShow==false)
            {
                //提示线条
                line=DrawNode::create();
                line->drawLine(Point(215,95),  (stars->starsVector.back())->getPosition(), Color4F::WHITE);
                this->addChild(line,0);
                lineNum=0;
                lineShow=true;
            }
            
            
            //错误提示效果
            talkingString="no,not that one,dad~";
            talkingBox->runAction(Sequence::create(Show::create(),DelayTime::create(5),Hide::create(),NULL));
            auto act1=ScaleTo::create(0.3, 2);
            auto act2=ScaleTo::create(0.3, 1);
            stars->starsVector.at(i)->runAction(Sequence::create(act1,act2, NULL));
            
            //点错亲密值降低
            if (Relation>0)
            {
                --Relation;
                
                sprintf(relationString, "亲密值：%d",Relation);
                RelationLabel->cleanup();
                RelationLabel->setString(relationString);
                
                UserDefault::getInstance()-> setIntegerForKey("RELATION", Relation);
                
            }
            
            
        }
        
        
    }
    
    
    
    
    //触摸指向的星星back()
        if ((stars->starsVector.back())->getBoundingBox().containsPoint(touchPoint))
        {
           
            //若点击了星座
            if (stars->starsVector.back()==stars->constellation)
            {
               //写入plist
                
                writToPlist();
                
                //记录获取了的星座,以其序号为key
              
                
               
                
                switch (collensation)
                {
                    case 1:  //baiyang
                    {  //提示信息
                        talkingString="yeap, we get the Aries!";
                        talkingBox->runAction(Sequence::create(Show::create(),DelayTime::create(5),Hide::create(),NULL));
                        
                        
                         //显示连线
                        stars->constellation->getChildByTag(1)->runAction(Sequence::create(Show::create(),Blink::create(1.0f, 2), NULL));
                      
                       
                        
                         stars->constellation->getChildByTag(2)->runAction(Sequence::create(Show::create(),Blink::create(1.0f, 2), NULL));
                        
                        
                         stars->constellation->getChildByTag(3)->runAction(Sequence::create(Show::create(),Blink::create(1.0f, 2), NULL));
                        break;
                        
                }
                    case 2:  //jinniu
                    {talkingString="yeap, we get the Taurus!";
                        talkingBox->runAction(Sequence::create(Show::create(),DelayTime::create(5),Hide::create(),NULL));
                        
                        
                        for (int i=1; i<=17; i++)
                        {
                            //stars->constellation->getChildByTag(i)->runAction(Sequence::create(Show::create(),Blink::create(1.0f, 2), NULL));
                            stars->constellation->getChildByTag(i)->setVisible(true);
                        }
                        
                        
                        
                        
                        break;
                    }
                    case 3:  //shuangzi
                        talkingString="yeap, we get the Gemini!";
                        talkingBox->runAction(Sequence::create(Show::create(),DelayTime::create(5),Hide::create(),NULL));
                        
                        for (int i=0; i<=15; i++)
                        {
                            stars->constellation->getChildByTag(i)->runAction(Sequence::create(Show::create(),Blink::create(2.0f, 5), NULL));
                        }
                        
                        break;
                        
                        
                    case 4:  //shuangyu
                        talkingString="yeap, we get the Pisces!";
                        talkingBox->runAction(Sequence::create(Show::create(),DelayTime::create(5),Hide::create(),NULL));
                        
                        for (int i=0; i<=18; i++)
                        {
                            stars->constellation->getChildByTag(i)->runAction(Sequence::create(Show::create(),Blink::create(2.0f, 5), NULL));
                        }
                        break;
                        
                        
                    case 5:  //mojie
                        talkingString="yeap, we get the Capricorn!";
                        talkingBox->runAction(Sequence::create(Show::create(),DelayTime::create(5),Hide::create(),NULL));
                        
                        for (int i=0; i<=10; i++)
                        {
                            stars->constellation->getChildByTag(i)->runAction(Sequence::create(Show::create(),Blink::create(2.0f, 5), NULL));
                        }

                        
                        break;
                        
                        
                    case 6:  //chunv
                        talkingString="yeap, we get the Virgo!";
                        talkingBox->runAction(Sequence::create(Show::create(),DelayTime::create(5),Hide::create(),NULL));
                        for (int i=0; i<=13; i++)
                        {
                            stars->constellation->getChildByTag(i)->runAction(Sequence::create(Show::create(),Blink::create(2.0f, 5), NULL));
                        }

                        
                        
                        break;
                        
                        
                        
                    case 7:  //sheshou
                        talkingString="yeap, we get the Sagittarius!";
                        talkingBox->runAction(Sequence::create(Show::create(),DelayTime::create(5),Hide::create(),NULL));
                        
                        
                        for (int i=0; i<=21; i++)
                        {
                            stars->constellation->getChildByTag(i)->runAction(Sequence::create(Show::create(),Blink::create(2.0f, 5), NULL));
                        }
                        break;
                        
                        
                    case 8:  //shuiping
                        talkingString="yeap, we get the Aquarius!";
                        talkingBox->runAction(Sequence::create(Show::create(),DelayTime::create(5),Hide::create(),NULL));
                        
                        for (int i=0; i<=14; i++)
                        {
                            stars->constellation->getChildByTag(i)->runAction(Sequence::create(Show::create(),Blink::create(2.0f, 5), NULL));
                        }
                        break;
                        
                        
                    case 9:  //tianping
                        talkingString="yeap, we get the Libra!";
                        talkingBox->runAction(Sequence::create(Show::create(),DelayTime::create(5),Hide::create(),NULL));
                        for (int i=0; i<=7; i++)
                        {
                            stars->constellation->getChildByTag(i)->runAction(Sequence::create(Show::create(),Blink::create(2.0f, 5), NULL));
                        }
                        break;
                        
                        
                    case 10:  //shizi
                        talkingString="yeap, we get the Leo!";
                        talkingBox->runAction(Sequence::create(Show::create(),DelayTime::create(5),Hide::create(),NULL));
                        
                        for (int i=0; i<=10; i++)
                        {
                            stars->constellation->getChildByTag(i)->runAction(Sequence::create(Show::create(),Blink::create(2.0f, 5), NULL));
                        }
                        break;
                        
                        
                    case 11:  //tianxie
                        talkingString="yeap, we get the Scorpio!";
                        talkingBox->runAction(Sequence::create(Show::create(),DelayTime::create(5),Hide::create(),NULL));
                        for (int i=0; i<=4; i++)
                        {
                            stars->constellation->getChildByTag(i)->runAction(Sequence::create(Show::create(),Blink::create(2.0f, 5), NULL));
                        }
                        break;
                        
                        
                    case 12:  //juxie
                        talkingString="yeap, we get the Cancer!";
                        talkingBox->runAction(Sequence::create(Show::create(),DelayTime::create(5),Hide::create(),NULL));
                        
                        
                        for (int i=0; i<=6; i++)
                        {
                            stars->constellation->getChildByTag(i)->runAction(Sequence::create(Show::create(),Blink::create(2.0f, 5), NULL));
                        }
                        break;
                        
                    default:
                        break;
                }

                
                
               
                auto collact1=DelayTime::create(2.0f);
                
                auto collact2=ScaleTo::create(2.0f, 1.5);
                
              
             //   stars->starsVector.back()->runAction(Sequence::create(Spawn::create(collact1, collact2,NULL), RemoveSelf::create(),NULL));
                
                
            }
            
            else
            {
           //若点在星星上，则移除此星星
            //移除特效
            auto act1=MoveTo::create(1.0f, Point(size.width/2,size.height/2));
            auto act2=ScaleTo::create(1.0f, 3.0f);
            
            //爆炸效果
            auto act3=ParticleExplosion::create();
            act3->setPosition(Point::ZERO);
            act3->setLife(1.0f);
            act3->setScale(0.2f);
       
          (stars->starsVector.back())->addChild(act3);
            
            //EASESINEOUT:正弦加速
            (stars->starsVector.back())->runAction(Sequence::create(EaseSineOut::create(Spawn::create(act1,act2, NULL)),RemoveSelf::create(), NULL));
            }
            
            
            //清除提示线条
            if (lineShow)
            {
                line->removeFromParent();
                lineShow=false;
                
            }
            
            //亲密值增加
            Relation++;
            sprintf(relationString, "亲密值：%d",Relation);
            RelationLabel->cleanup();
            RelationLabel->setString(relationString);
            UserDefault::getInstance()->setIntegerForKey("RELATION", Relation);
            
      
            
            //弹出点击正确的星星
            //stars->starsVector.pop_back();
            stars->starsVector.popBack();
            //错误计数清零
             lineNum=0;
            pointer->setRotation(0);
            // 若空，则胜利
            if (stars->starsVector.empty())
            {
                //成长值＋＋
                growth++;
                win();
                
                
                
                
            }
            else
            {
            pointToStar();
            }
        }
  
    
    
    
    return false;
}

void MenuLayer::pointToStar()
{
    
    if (stars->starsVector.empty())
    {
        return ;
    }
    
    //星星的坐标
     //测试指向0号星星
    
    auto starToPoint= (stars->starsVector.back())->getPosition();
    log("x=%lf,y=%lf\n",starToPoint.x,starToPoint.y);
    //正切
    
    log("pointerX=%lf,pointerY=%lf\n",pointer->getPosition().x,pointer->getPosition().y);
    double tanAngle=(starToPoint.y-pointer->getPosition().y)/(starToPoint.x-pointer->getPosition().x);
    log("tanAngle=%lf\n",tanAngle);
    //反正切
    double Angle=atan(tanAngle)*180/3.141592653;
    log("angle=%lf\n",Angle);
   
        //正数顺时针旋转节点，负数逆时针旋转节点。
    if (Angle<=0)
    {
        
         pointer->setRotation(-(180-fabs(Angle)));
    }
    if (Angle>=0)
    {
         pointer->setRotation(-Angle);
    }
   
    }

void MenuLayer::win()
{

    


}

//提示
void MenuLayer::info(int starNum)
{
//第一关
    if (starNum==1)
    {
        
        auto act1=ScaleTo::create(0.5, 2);
        auto act2=ScaleTo::create(0.5, 1);
        
        stars->starsVector.back()->runAction(RepeatForever::create(Sequence::create(act1,act2, NULL)));
        
        
        
    }
    
    


}

//写入plist
void MenuLayer::writToPlist()
{
    __String ActionNum;
    
    if (starNum>5&&starNum<=10)
    {
    ActionNum="A10";
    }

    
    
    
    std::  string writaBle=FileUtils::getInstance()->getWritablePath();
    std::string path=writaBle+"List.plist";
    
     //跟目录是dic类型
    auto  root=FileUtils::getInstance()->getValueMapFromFile(path.c_str());
    
        //各个章节是arry
    auto arr=root[ActionNum.getCString()].asValueVector();
    arr[collensation-1]=1;
    root[ActionNum.getCString()]=arr;
    FileUtils::getInstance()->writeToFile(root, path.c_str());
   

}