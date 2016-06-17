//
//  ConstellationSprite.cpp
//  MyCppGame
//
//  Created by zwj on 16/6/17.
//
//

#include "ConstellationSprite.hpp"

constellationSprite::constellationSprite(int num)
{

    constellationNum=num;


}


constellationSprite* constellationSprite::createConstellationSprite(int num)
{

    constellationSprite* constellation=new constellationSprite(num);
    auto starBatchNode=SpriteBatchNode::create("star.png");
    
    if (constellation)
    {
      
        switch (num)
        {
                
            case 0:
                return nullptr;
                break;
            case 1:
            {   constellation->autorelease();
                constellation->initWithTexture(starBatchNode->getTexture());
               //auto starSprite0=Sprite::createWithTexture(starBatchNode->getTexture());
                auto starSprite1=Sprite::createWithTexture(starBatchNode->getTexture());
                auto starSprite2=Sprite::createWithTexture(starBatchNode->getTexture());
                auto starSprite3=Sprite::createWithTexture(starBatchNode->getTexture());
                
                //坐标
                starSprite1->setPosition(Point(95,-10));
                starSprite1->setAnchorPoint(Point(0.5,0.5));
                starSprite2->setPosition(Point(155,-36));
                starSprite2->setAnchorPoint(Point(0.5,0.5));
                starSprite3->setPosition(Point(162,-75));
                starSprite3->setAnchorPoint(Point(0.5,0.5));
                
                
                
                constellation->addChild(starSprite1,10);
                constellation->addChild(starSprite2,10);
                constellation->addChild(starSprite3,10);
                constellation->setPosition(0,0);
                
                
                
                
                //line
                auto line0=DrawNode::create();
                line0->drawLine(constellation->getPosition()+Point(20,5), constellation->getPosition()+starSprite1->getPosition(), Color4F::WHITE);
                constellation->addChild(line0,0);
                auto line1=DrawNode::create();
                line1->drawLine(constellation->getPosition()+starSprite1->getPosition(),constellation->getPosition()+ starSprite2->getPosition(), Color4F::WHITE);
                constellation->addChild(line1,0);
                auto line2=DrawNode::create();
                line2->drawLine(constellation->getPosition()+starSprite2->getPosition(), constellation->getPosition()+starSprite3->getPosition(), Color4F::WHITE);
                
                constellation->addChild(line2,0);
                
                
                return constellation;
                break;
            }
            default:
                break;
        }

    }

    
    else
    {
        CC_SAFE_DELETE(constellation);
        return nullptr;
    }




}