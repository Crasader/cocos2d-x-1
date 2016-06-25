//
//  OpeningLayer.cpp
//  MyCppGame
//
//  Created by zwj on 16/6/16.
//
//

#include "OpeningLayer.hpp"


//create()方法
OpeningLayer* OpeningLayer::create()
{
    OpeningLayer* layer=new OpeningLayer();
    
    if (layer&&layer->init())
    {
        layer->autorelease();
        return layer;
        
    }
    else
    {
        CC_SAFE_DELETE(layer);
        return nullptr;
        
    }
}

//init()方法
bool OpeningLayer::init()
{

    if (!Layer::init())
    {
        return false;
    }
    
    Size size=Director::getInstance()->getVisibleSize();
    
    
    
    //背景
    Sprite* backGround=Sprite::create("bg_L.png");
    backGround->setPosition(size.width/2,size.height/2);
    backGround->setScale(1.2);
    this->addChild(backGround,0);
    star->randomPosition();
    
    
    //BOOKlayer的按钮:7号不闪的星星上
    auto goBookLabel=Label::createWithSystemFont("Stars", "Marker Felt.ttf", 40);
    goBookLabel->setColor(Color3B::WHITE);
    auto goBookMenu=MenuItemLabel::create(goBookLabel, CC_CALLBACK_1(OpeningLayer::goBookMenuCallBack, this));
    //7号星星放大
    star->starsVector.at(7)->setScale(2.0);
    
    goBookMenu->setPosition(star->starsVector.at(7)->getPosition()+Point(0,-50));
    
    
    
    
    //settingLayer的按钮:右下角
    auto goSettingLabel=Label::createWithSystemFont("Setting", "Marker Felt.ttf", 30);
    goSettingLabel->setColor(Color3B::WHITE);
    auto goSettingMenu=MenuItemLabel::create(goSettingLabel, CC_CALLBACK_1(OpeningLayer::goSettingCallBack, this));
    goSettingMenu->setPosition(Point(900,50));
    
    
    
   
    
    
    auto menu=Menu::create(goBookMenu,goSettingMenu, NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu);
    
    //按钮附近确保没有星星
    std::vector<Sprite*>::iterator iter;
    iter=star->starsVector.begin();
    for (; iter!=star->starsVector.end(); iter++)
    {
        //判断星星与menu相交
        if ((*iter)->getBoundingBox().intersectsRect(goBookMenu->getBoundingBox()))
        {
            (*iter)->setVisible(false);
           
        }
    }
    
    
    
    
   
    
    createPlist();
    

    return true;

}



//goBookLayer回调
void OpeningLayer::goBookMenuCallBack(cocos2d::Ref *pSender)
{

    gsm->goBookLayer();
   // gsm->goMenuLayer();
}


//goMenu回调
void OpeningLayer::goSettingCallBack(cocos2d::Ref *pSender)
{

    gsm->goSettingLayer();
}


//创建plist
void OpeningLayer::createPlist()
{

    std::string path=FileUtils::getInstance()->getWritablePath();
    
    std::string fullPath=path+"List.plist";
    if ( !FileUtils::getInstance()->isFileExist(fullPath.c_str()))
    {
        ValueMap root;
        ValueVector arry;
        arry.clear();
        root.clear();
        for (int i=0; i<12; i++)
        {
            
            arry.push_back(Value(0));
            
        }
        
        root["A0"]=arry;
        
        FileUtils::getInstance()->writeToFile(root, fullPath.c_str());
         arry.clear();
        
        
        for (int i=0; i<12; i++)
        {
            
            arry.push_back(Value(0));
            
        }
        
        root["A10"]=arry;
         FileUtils::getInstance()->writeToFile(root, fullPath.c_str());
        arry.clear();
        
        for (int i=0; i<12; i++)
        {
            
            arry.push_back(Value(0));
            
        }
        
        root["A12"]=arry;
        FileUtils::getInstance()->writeToFile(root, fullPath.c_str());
         arry.clear();
        
        for (int i=0; i<12; i++)
        {
            
            arry.push_back(Value(0));
            
        }
        
        root["A14"]=arry;
         FileUtils::getInstance()->writeToFile(root, fullPath.c_str());
         arry.clear();
    }
}

