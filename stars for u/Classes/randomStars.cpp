//
//  randomStars.cpp
//  MyCppGame
//
//  Created by zwj on 16/6/14.
//
//

#include "randomStars.hpp"
#include <time.h>
randomStars::randomStars(Layer* layerIn)
{

    this->layer=layerIn;

}

void randomStars::randomPosition()

{   std::srand(unsigned(time(NULL)));
    
    //星星的 bat
    SpriteBatchNode* starsBatchNode=SpriteBatchNode::create("1.png");
    starsBatchNode->setPosition(Point::ZERO);
    auto size=Director::getInstance()->getVisibleSize();
    
    for (int i=0; i<10; i++)
    {
        
        float x=rand_0_1()*size.width;
        float y=size.height/2+rand_0_1()*size.height/2;
        auto star=Sprite::createWithTexture(starsBatchNode->getTexture());
        star->setPosition(Point(x,y));
        layer->addChild(star);
        starsVector.push_back(star);
     
     
    }




}