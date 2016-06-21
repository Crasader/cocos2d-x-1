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
    Sprite* backGround=Sprite::create("bg.png");
    backGround->setPosition(size.width/2,size.height/2);
    backGround->setScale(1.2);
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
    talkingLabel=Label::createWithSystemFont("", "Marker Felt.ttf", 30);
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
            talkingBox->runAction(Sequence::create(Show::create(),DelayTime::create(3),Hide::create() NULL));
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
    
                std::string constelationString;
               
               
                
                switch (collensation)
                {
                    case 1:
                        constelationString="yeap, u get the Aries!";
                        break;
                        
                    default:
                        break;
                }
                //提示效果
                auto collLabel=Label::createWithSystemFont(constelationString.c_str(), "Marker Felt.ttf", 50);
                collLabel->setColor(Color3B::WHITE);
                collLabel->setPosition(400,500);
                
                //action
                auto effecNode=NodeGrid::create();
                this->addChild(effecNode);
                effecNode->addChild(collLabel);
                //水波效果
                auto  collLabelact1=Ripple3D::create(5.0f, Size(20,20), collLabel->getPosition(), 360, 2, 5);
                effecNode->runAction(Sequence::create(collLabelact1,RemoveSelf::create(), NULL));
                
                
                
                //移除特效
                auto collact1=ScaleTo::create(2.5f, 2);
                auto collact2=MoveTo::create(2.5f, Point(300,350));
              
                stars->starsVector.back()->runAction(Sequence::create(Spawn::create(collact1,collact2, NULL), RemoveSelf::create(),NULL));
                
                
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
            stars->starsVector.pop_back();
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