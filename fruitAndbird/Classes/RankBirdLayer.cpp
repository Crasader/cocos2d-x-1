//
//  RankBirdLayer.cpp
//  fruitAndbird
//
//  Created by zwj on 16/5/27.
//
//

#include "RankBirdLayer.hpp"

bool rankBirdLayer::init()
{

    if (!Layer::init()) {
        return false;
    }

    Size visibleSize=Director::getInstance()->getVisibleSize();
    Point origin=Director::getInstance()->getVisibleOrigin();
    
    Sprite *backGround=Sprite::create("night.png");
    backGround->setAnchorPoint(Point(0,0));
    backGround->setPosition(Point(origin.x,origin.y+visibleSize.height-backGround->getContentSize().height));
    this->addChild(backGround,0);
    Sprite *floor=Sprite::create("floor.png");
    floor->setAnchorPoint(Point(0,0));
    floor->setPosition(0,0);
    this->addChild(floor);
    floor->runAction(RepeatForever::create(Sequence::create(MoveTo::create(0.5, Point(-120,0)),MoveTo::create(0,Point(0,0)), NULL)));
    
    Sprite *rank=Sprite::create("rankBackground.png");
    rank->setPosition(270,530);
    this->addChild(rank);
    Sprite *title=Sprite::create("rankBird.png");
    title->setPosition(270,850);
    this->addChild(title,1);
    
    
    MenuItemImage *menuItem=MenuItemImage::create("menu.png", "menu_off.png", CC_CALLBACK_1(rankBirdLayer::menuCallBack0, this));
    menuItem->setPosition(80,50);
    MenuItemImage *nextItem=MenuItemImage::create("next.png", "next_off.png", CC_CALLBACK_1(rankBirdLayer::menuCallBack1, this));
    nextItem->setPosition(460,50);
    
    Menu *menu=Menu::create(menuItem,nextItem, NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu,10);
    
    //排行的显示
    int *tempBird= new int[5];
    for (int i=0; i<5; i++) {
        std::string score;
        std::string number=StringUtils::format("%d",(i+1)); //创建string
        tempBird[i]=atoi(scoreBird[i].c_str());// atoi(const char *) 转换为int; .c_str()将std::string转换为char ＊
        if (tempBird[i]==0) {
            score="-";
        }
    
    else
    {
        score=scoreBird[i];
    }
    
        labels=Label::createWithTTF(number, "FZKATJW.ttf", 60,Size::ZERO,TextHAlignment::LEFT,TextVAlignment::TOP);
        rank->addChild(labels,2);
        labels->setPosition(Point(90,280-(50*i)));
        labels->enableOutline(Color4B(187,187,187,255),2);
        
        labels=Label::createWithTTF(score, "FZKATJW.ttf", 60,Size::ZERO,TextHAlignment::LEFT,TextVAlignment::TOP);
        rank->addChild(labels,2);
        labels->setPosition(Point(315,280-(50*i)));
        labels->enableOutline(Color4B(187,187,187,255),2);
        
    }

    return  true;
}

void rankBirdLayer::save(int newScore)
{
    std::string score;
    std::string oldScore;
    int *tempBird=new int[5];
    for (int i=0; i<5; i++) {
        tempBird[i]=atoi(scoreBird[i].c_str());
    }
    for (int i=4; i>=0; i--) {
        if (newScore>=tempBird[i]) {
            score=StringUtils::format("%d",newScore);
            if (i!=4) {
                oldScore=StringUtils::format("%d",tempBird[i]);
                UserDefault::getInstance()->setStringForKey(StringUtils::format("b%d",(i+1)).c_str(), oldScore);
            }
            UserDefault::getInstance()->setStringForKey(StringUtils::format("b%d",i).c_str(), score);
        }
        else
            break;
    }
    UserDefault::getInstance()->flush();

}
void rankBirdLayer::load()
{
    for (int i=0 ; i<5; i++)
    {
        scoreBird[i]=UserDefault::getInstance()->getStringForKey(StringUtils::format("b%d",i).c_str(),"0");
    }


}

void rankBirdLayer::menuCallBack0(cocos2d::Ref *pSender)
{
    sceneManager->goToMainScene();

}
void rankBirdLayer::menuCallBack1(cocos2d::Ref *pSender)
{
    sceneManager->goToRankFruitScene();
}