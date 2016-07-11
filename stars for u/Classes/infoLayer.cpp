//
//  infoLayer.cpp
//  MyCppGame
//
//  Created by zwj on 16/6/29.
//
//

#include "infoLayer.hpp"


#include "MenuLayer.hpp"
#include "randomStars.hpp"
#include <math.h>
#include "ConstellationSprite.hpp"
#include <string>

//create()方法
infoLayer* infoLayer::create(int starNum,int shinStarNum,int collNum)
{
    
    infoLayer* layer=new infoLayer(starNum,shinStarNum,collNum);
    
    if (layer&&layer->init())
    {
        layer->autorelease();
        return layer;
    }
    CC_SAFE_DELETE(layer);
    return nullptr;
}

//构造
infoLayer::infoLayer(int starNum, int ShineStar,int collNum)
{
    this->collensation=collNum;
    this->starNum=starNum;
    this->shineStarNum=ShineStar;
    lineNum=0;
}

//init()方法

bool infoLayer::init()
{
    if (!Layer::init())
    {
        return false;
    }
    
    
    
    //亲密值
    Relation= UserDefault::getInstance()->getIntegerForKey("RELATION", 0);
    
    //成长值
    growth= UserDefault::getInstance()->getIntegerForKey("GROWTH", 0);
    
    
    //星星的生成：starNum\shineStarNum\collensation
    stars =new randomStars(this,starNum,shineStarNum,collensation);
    size=Director::getInstance()->getVisibleSize();
    
    //背景
    Sprite* backGround=Sprite::create("bg_L.png");
    backGround->setPosition(size.width/2,size.height/2);
    this->addChild(backGround,0);
    
    
    backGround2=Sprite::create("bg_2.png");
    backGround2->setPosition(size.width/2,backGround2->getContentSize().height/2);
    // backGround->setScale(1.2);
    this->addChild(backGround2,1);
    
    //布置星星
    stars->randomPosition();
    
    
    
    //boy
    Sprite* boy=Sprite::create("boy-hand.png");
    boy->setPosition(200,100);
    boy->setScale(0.8f);
    this->addChild(boy,102,101);
    
    
    
    //暂停按钮
    auto pasueLabel=Label::createWithTTF("退出", "fonts/china.ttf" ,40);
    pasueLabel->setColor(Color3B::RED);
    auto pasueButton=MenuItemLabel::create(pasueLabel,CC_CALLBACK_1(infoLayer::goBackCallBack, this));
    pasueButton->setPosition(pasueButton->getContentSize().width/2+5,size.height-pasueButton->getContentSize().height);
    auto menu=Menu::create(pasueButton, NULL);
    menu->setPosition(0,0);
    this->addChild(menu);
    
    
    
    
    //hand
    pointer=Sprite::create("hand.png");
    pointer->setAnchorPoint(Point(0,0.5));
    pointer->setScale(1.5);
    pointer->setPosition(215,95);
    this->addChild(pointer,103,102);
    pointToStar();
    
    
    
    
    //timer
    moon=Sprite::create("moon_2.png");
    moon->setPosition(Point(moon->getContentSize().width,490));
    moon->setAnchorPoint(Point(0,0));
    moon->setTag(10);
    this->addChild(moon,0);
    //this->schedule(schedule_selector(infoLayer::timerFunc), 0.1f);
    
    
    //开启触摸
    setTouchEnabled(true);
    setSwallowsTouches(true);
    setTouchMode(kCCTouchesOneByOne);
    
    
 
    
     jiantou=Sprite::create("jiantou.png");
    jiantou->setAnchorPoint(Point(0,0));
    jiantou->setPosition(pointer->getPosition()+Point(20,40));
    this->addChild(jiantou,999);
    jiantou->setTag(2);
    
    
    infoLabel=Sprite::create("info1.png");
    infoLabel->setPosition(jiantou->getPosition()+Point(0,70));
    infoLabel->setScale(2);
    this->addChild(infoLabel,1000);
    infoLabel->setTag(1);
    
    
    
//    auto okLabel=Label::createWithSystemFont("Ok", "Maker Flet.ttf", 50);
//    okLabel->setColor(Color3B::RED);
//    auto okButton=MenuItemLabel::create(okLabel, CC_CALLBACK_1(infoLayer::infoCallBak, this));
//    okButton->setPosition(800,60);
//    auto menu2=Menu::create(okButton, NULL);
//    menu2->setPosition(0,0);
//    this->addChild(menu2,1001);
    
    
    
    
    return true;
}


//void infoLayer::infoCallBak(cocos2d::Ref *pSender)
//{
//    k++;
//    switch (k) {
//        case 1:
//            jiantou->setPosition(stars->starsVector.back()->getPosition()+Point(0,5));
//            infoLabel->setTexture("info2.png");
//            infoLabel->setPosition(jiantou->getPosition()+Point(0,70));
//    
//            
//            break;
//            case 2:
//            jiantou->setPosition(size.width/2,size.height/2);
//            infoLabel->setTexture("info3.png");
//            this->schedule(schedule_selector(infoLayer::timerFunc), 0.1f);
//            break;
//        case 3:
//            
//                      
//            break;
//            
//        default:
//            
//            break;
//    }
//
//}



//talkingBox打字效果回调

void infoLayer::talkingBoxFunc(float dt)
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
bool infoLayer::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event)
{
    
    
    k++;
    switch (k) {
        case 1:
            jiantou->setPosition(stars->starsVector.back()->getPosition()+Point(0,5));
            infoLabel->setTexture("info2.png");
            infoLabel->setPosition(jiantou->getPosition()+Point(0,70));
            
            
            break;
        case 2:
            infoLabel->setPosition(size.width/2,size.height/2);
            infoLabel->setTexture("info3.png");
            this->schedule(schedule_selector(infoLayer::timerFunc), 0.1f);
            break;
        case 3:
            
            this->removeChildByTag(1);
            this->removeChildByTag(2);
            break;
            
        default:
            
            break;
    }

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
                this->addChild(line,2);
                lineNum=0;
                lineShow=true;
            }
            
            
            //错误提示效果
            auto act1=ScaleTo::create(0.3, 2.5);
            auto act2=ScaleTo::create(0.3, 1.5);
            stars->starsVector.at(i)->runAction(Sequence::create(act1,act2, NULL));
            

            
            
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
            conllGeted=true;
            
            //记录获取了的星座,以其序号为key
            
            
            
            
            switch (collensation)
            {
                case 1:  //baiyang
                {  //提示信息
                    
                    
                    //显示连线
                    stars->constellation->getChildByTag(1)->runAction(Sequence::create(Show::create(),Blink::create(1.0f, 3), NULL));
                    
                    
                    
                    stars->constellation->getChildByTag(2)->runAction(Sequence::create(Show::create(),Blink::create(1.0f, 3), NULL));
                    
                    
                    stars->constellation->getChildByTag(3)->runAction(Sequence::create(Show::create(),Blink::create(1.0f, 3), NULL));
                    break;
                    
                }
                case 2:  //jinniu
                {
                    
                    for (int i=1; i<=17; i++)
                    {
                        stars->constellation->getChildByTag(i)->runAction(Sequence::create(Show::create(),Blink::create(1.0f, 3), NULL));
                        
                    }
                    
                    
                    
                    
                    break;
                }
                case 3:  //shuangzi
                    for (int i=0; i<=15; i++)
                    {
                        stars->constellation->getChildByTag(i)->runAction(Sequence::create(Show::create(),Blink::create(1.0f, 3), NULL));
                    }
                    
                    break;
                    
                    
                case 4:  //shuangyu
                    
                    for (int i=0; i<=18; i++)
                    {
                        stars->constellation->getChildByTag(i)->runAction(Sequence::create(Show::create(),Blink::create(1.0f, 3), NULL));
                    }
                    break;
                    
                    
                case 5:  //mojie
                    
                    
                    for (int i=0; i<=10; i++)
                    {
                        stars->constellation->getChildByTag(i)->runAction(Sequence::create(Show::create(),Blink::create(1.0f, 3), NULL));
                    }
                    
                    
                    break;
                    
                    
                case 6:  //chunv
                    
                    for (int i=0; i<=13; i++)
                    {
                        stars->constellation->getChildByTag(i)->runAction(Sequence::create(Show::create(),Blink::create(1.0f, 3), NULL));
                    }
                    
                    
                    
                    break;
                    
                    
                    
                case 7:  //sheshou
                  
                    
                    
                    for (int i=0; i<=21; i++)
                    {
                        stars->constellation->getChildByTag(i)->runAction(Sequence::create(Show::create(),Blink::create(1.0f, 3), NULL));
                    }
                    break;
                    
                    
                case 8:  //shuiping
                   
                    
                    for (int i=0; i<=14; i++)
                    {
                        stars->constellation->getChildByTag(i)->runAction(Sequence::create(Show::create(),Blink::create(1.0f, 3), NULL));
                    }
                    break;
                    
                    
                case 9:  //tianping
                   
                    for (int i=0; i<=7; i++)
                    {
                        stars->constellation->getChildByTag(i)->runAction(Sequence::create(Show::create(),Blink::create(1.0f, 3), NULL));
                    }
                    break;
                    
                    
                case 10:  //shizi
                   
                    
                    for (int i=0; i<=10; i++)
                    {
                        stars->constellation->getChildByTag(i)->runAction(Sequence::create(Show::create(),Blink::create(1.0f, 3), NULL));
                    }
                    break;
                    
                    
                case 11:  //tianxie
                                   for (int i=0; i<=4; i++)
                    {
                        stars->constellation->getChildByTag(i)->runAction(Sequence::create(Show::create(),Blink::create(1.0f, 3), NULL));
                    }
                    break;
                    
                    
                case 12:  //juxie
                    
                    
                    for (int i=0; i<=6; i++)
                    {
                        stars->constellation->getChildByTag(i)->runAction(Sequence::create(Show::create(),Blink::create(1.0f, 3), NULL));
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
        //得分
        score++;
        //亲密值增加
        Relation++;
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
            UserDefault::getInstance()->setIntegerForKey("GROWTH", growth);
            //设置age
           
            UserDefault::getInstance()->setIntegerForKey("age", 10);
                
            
            
            
            
            
            timeOver();
            
            
            
            
        }
        else
        {
            pointToStar();
        }
    }
    
    
    
    
    return false;
}

void infoLayer::pointToStar()
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


//写入plist
void infoLayer::writToPlist()
{
    __String ActionNum;
        ActionNum="A0";
    
    
    
    
    
    
    
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


//timer回调
void infoLayer::timerFunc(float dt)
{
    Sprite* moon =(Sprite*)this->getChildByTag(10);
    
    //下降
    moon->runAction(MoveBy::create(0.1f, Point(0,-2)));
    
    //透明度
    moon->setOpacity(moon->getOpacity()-0.01);
    
    //达到海平面
    if (moon->getPositionY() <=(backGround2->getContentSize().height-moon->getContentSize().height))
    {
        growth++;
        UserDefault::getInstance()->setIntegerForKey("GROWTH", growth);
        //设置age
            UserDefault::getInstance()->setIntegerForKey("age", 10);
            
        
        timeOver();
        unschedule(schedule_selector(infoLayer::timerFunc));
        
    }
    
    
    
}





//时间到
void infoLayer::timeOver()
{
    //移除人
    this->removeChildByTag(100);
    this->removeChildByTag(101);
    this->removeChildByTag(102);
    this->pause();
    
    
    //提示版
    auto bookSprite=Sprite::create("book_s.png");
    bookSprite->setPosition(size.width/2,size.height/2);
    bookSprite->setScale(0, 0);
    this->addChild(bookSprite,1000);
    
    //分值
    char scoreBuf[128];
    sprintf(scoreBuf, "We get %d Stars!",score);
    
    auto scoreLabel=Label::createWithSystemFont(scoreBuf, "Marker Felt.ttf", 30);
    scoreLabel->setColor(Color3B::RED);
    scoreLabel->setPosition(Point(bookSprite->getContentSize().width/4,bookSprite->getContentSize().height-50));
    bookSprite->addChild(scoreLabel);
    
    
    sprintf(scoreBuf, "Relation %d ",Relation);
    auto relationLabel=Label::createWithSystemFont(scoreBuf, "Marker Felt.ttf", 30);
    relationLabel->setColor(Color3B::RED);
    relationLabel->setPosition(Point(bookSprite->getContentSize().width/4,bookSprite->getContentSize().height-50-50));
    bookSprite->addChild(relationLabel);
    
    sprintf(scoreBuf, "Growth %d ",growth);
    auto growtLabel=Label::createWithSystemFont(scoreBuf, "Marker Felt.ttf", 30);
    growtLabel->setColor(Color3B::RED);
    growtLabel->setPosition(Point(bookSprite->getContentSize().width/4,bookSprite->getContentSize().height-50-50-50));
    bookSprite->addChild(growtLabel);
    
    
    
    
    //弹出效果
    bookSprite->runAction(Sequence::create(ScaleTo::create(0, 0),ScaleTo::create(0.1, 0.2),ScaleTo::create(0.1, 0.5),ScaleTo::create(0.1, 0.8), ScaleTo::create(0.1, 1),NULL));
    
    
    
    //确定按钮
    auto okLabel=Label::createWithSystemFont("OK", "Marker Felt.ttf", 40);
    okLabel->setColor(Color3B::RED);
    auto okButton=MenuItemLabel::create(okLabel,CC_CALLBACK_1(infoLayer::goBackCallBack, this));
    okButton->setPosition(bookSprite->getContentSize().width/4,bookSprite->getContentSize().height/4);
    auto menu=Menu::create(okButton, NULL);
    menu->setPosition(0,0);
    bookSprite->addChild(menu);
    
    
    
    
    
    //如果出现了星座
    
    if (collensation!=0 && conllGeted==true)
    {
        auto boardSprite=Sprite::create("mark_2.png");
        boardSprite->setPosition(size.width/2+bookSprite->getContentSize().width/4,size.height/2);
        boardSprite->setScale(0, 0);
        boardSprite->setRotation(-10);
        this->addChild(boardSprite,1001);
        
        
        boardSprite->runAction(Sequence::create(DelayTime::create(1.0f),ScaleTo::create(0, 1),ScaleTo::create(0.1, 0.8),ScaleTo::create(0.1, 0.6),ScaleTo::create(0.1, 0.5), NULL));
        
        char conBuf[10];
        sprintf(conBuf, "C%d.png",collensation);
        auto conSprite=Sprite::create(conBuf);
        conSprite->setPosition(boardSprite->getContentSize().width/2,boardSprite->getContentSize().height/2);
        conSprite->setScale(2.0f);
        boardSprite->addChild(conSprite);
        
        
    }
    
}


void infoLayer::goBackCallBack(cocos2d::Ref *pSender)
{
    
    gsm->goBookLayer();
}