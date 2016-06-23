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
            //白羊C1
            case 1:
            {   constellation->autorelease();
                constellation->initWithTexture(starBatchNode->getTexture());
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
                //金牛 Taurus C2
            case 2:
            {
                constellation->autorelease();
                constellation->initWithTexture(starBatchNode->getTexture());
                auto starSprite1=Sprite::createWithTexture(starBatchNode->getTexture());
                auto starSprite2=Sprite::createWithTexture(starBatchNode->getTexture());
                auto starSprite3=Sprite::createWithTexture(starBatchNode->getTexture());
                auto starSprite4=Sprite::createWithTexture(starBatchNode->getTexture());
                auto starSprite5=Sprite::createWithTexture(starBatchNode->getTexture());
                auto starSprite6=Sprite::createWithTexture(starBatchNode->getTexture());
                auto starSprite7=Sprite::createWithTexture(starBatchNode->getTexture());
                  auto starSprite8=Sprite::createWithTexture(starBatchNode->getTexture());
                  auto starSprite9=Sprite::createWithTexture(starBatchNode->getTexture());
                  auto starSprite10=Sprite::createWithTexture(starBatchNode->getTexture());
                  auto starSprite11=Sprite::createWithTexture(starBatchNode->getTexture());
                  auto starSprite12=Sprite::createWithTexture(starBatchNode->getTexture());
                  auto starSprite13=Sprite::createWithTexture(starBatchNode->getTexture());
                  auto starSprite14=Sprite::createWithTexture(starBatchNode->getTexture());
                  auto starSprite15=Sprite::createWithTexture(starBatchNode->getTexture());
                    auto starSprite16=Sprite::createWithTexture(starBatchNode->getTexture());
                
                //坐标
                starSprite1->setPosition(Point(95,-33));
                starSprite1->setAnchorPoint(Point(0.5,0.5));
                
                starSprite2->setPosition(Point(165,-66));
                starSprite2->setAnchorPoint(Point(0.5,0.5));
                
                starSprite3->setPosition(Point(235,-81));
                starSprite3->setAnchorPoint(Point(0.5,0.5));
                
                starSprite4->setPosition(Point(296,-56));
                starSprite4->setAnchorPoint(Point(0.5,0.5));
                starSprite4->setScale(2.0);
                
                starSprite5->setPosition(Point(255,-160));
                starSprite5->setAnchorPoint(Point(0.5,0.5));
                
                starSprite6->setPosition(Point(260,-240));
                starSprite6->setAnchorPoint(Point(0.5,0.5));
                
                starSprite7->setPosition(Point(254,-305));
                starSprite7->setAnchorPoint(Point(0.5,0.5));
                
                
                starSprite8->setPosition(Point(190,-283));
                starSprite8->setAnchorPoint(Point(0.5,0.5));
                
                starSprite9->setPosition(Point(107,-285));
                starSprite9->setAnchorPoint(Point(0.5,0.5));
                
                starSprite10->setPosition(Point(59,-263));
                starSprite10->setAnchorPoint(Point(0.5,0.5));
                
                starSprite11->setPosition(Point(57,-221));
                starSprite11->setAnchorPoint(Point(0.5,0.5));
                
                starSprite12->setPosition(Point(73,-162));
                starSprite12->setAnchorPoint(Point(0.5,0.5));
                starSprite4->setScale(2.0);
                
                starSprite13->setPosition(Point(163,-204));
                starSprite13->setAnchorPoint(Point(0.5,0.5));
                
                
                starSprite14->setPosition(Point(124,-117));
                starSprite14->setAnchorPoint(Point(0.5,0.5));
                
                starSprite15->setPosition(Point(-22,-101));
                starSprite15->setAnchorPoint(Point(0.5,0.5));
                
                starSprite16->setPosition(Point(139,-161));
                starSprite16->setAnchorPoint(Point(0.5,0.5));
                starSprite13->setVisible(false);
                
                constellation->addChild(starSprite1,10);
                constellation->addChild(starSprite2,10);
                constellation->addChild(starSprite3,10);
                constellation->addChild(starSprite4,10);
                constellation->addChild(starSprite5,10);
                constellation->addChild(starSprite6,10);
                constellation->addChild(starSprite7,10);
                constellation->addChild(starSprite8,10);
                constellation->addChild(starSprite9,10);
                constellation->addChild(starSprite10,10);
                constellation->addChild(starSprite11,10);
                constellation->addChild(starSprite12,10);
                constellation->addChild(starSprite13,10);
                constellation->addChild(starSprite14,10);
                constellation->addChild(starSprite15,10);
                constellation->addChild(starSprite16,10);
                constellation->setPosition(0,0);
                
                
                
                
                //line
                auto line0=DrawNode::create();
                line0->drawLine(constellation->getPosition()+Point(20,5), constellation->getPosition()+starSprite1->getPosition(), Color4F::WHITE);
                constellation->addChild(line0,0);
                
                auto line1=DrawNode::create();
                line1->drawLine(constellation->getPosition()+starSprite1->getPosition(),constellation->getPosition()+ starSprite14->getPosition(), Color4F::WHITE);
                constellation->addChild(line1,0);
                
                auto line2=DrawNode::create();
                line2->drawLine(constellation->getPosition()+starSprite14->getPosition(), constellation->getPosition()+starSprite2->getPosition(), Color4F::WHITE);
                constellation->addChild(line2,0);
                
                auto line3=DrawNode::create();
                line3->drawLine(constellation->getPosition()+starSprite2->getPosition(), constellation->getPosition()+starSprite3->getPosition(), Color4F::WHITE);
                constellation->addChild(line3,0);
                
                auto line4=DrawNode::create();
                line4->drawLine(constellation->getPosition()+starSprite3->getPosition(), constellation->getPosition()+starSprite4->getPosition(), Color4F::WHITE);
                constellation->addChild(line4,0);
                
                auto line5=DrawNode::create();
                line5->drawLine(constellation->getPosition()+starSprite4->getPosition(), constellation->getPosition()+starSprite5->getPosition(), Color4F::WHITE);
                constellation->addChild(line5,0);
                
                auto line6=DrawNode::create();
                line6->drawLine(constellation->getPosition()+starSprite5->getPosition(), constellation->getPosition()+starSprite6->getPosition(), Color4F::WHITE);
                constellation->addChild(line6,0);
                
                
                auto line7=DrawNode::create();
                line7->drawLine(constellation->getPosition()+starSprite6->getPosition(), constellation->getPosition()+starSprite8->getPosition(), Color4F::WHITE);
                constellation->addChild(line7,0);
                
                auto line8=DrawNode::create();
                line8->drawLine(constellation->getPosition()+starSprite8->getPosition(), constellation->getPosition()+starSprite7->getPosition(), Color4F::WHITE);
                constellation->addChild(line8,0);
                
                auto line9=DrawNode::create();
                line9->drawLine(constellation->getPosition()+starSprite6->getPosition(), constellation->getPosition()+starSprite13->getPosition(), Color4F::WHITE);
                constellation->addChild(line9,0);
                
                auto line10=DrawNode::create();
                line10->drawLine(constellation->getPosition()+starSprite13->getPosition(), constellation->getPosition()+starSprite16->getPosition(), Color4F::WHITE);
                constellation->addChild(line10,0);
                
                auto line11=DrawNode::create();
                line11->drawLine(constellation->getPosition()+starSprite16->getPosition(), constellation->getPosition()+starSprite14->getPosition(), Color4F::WHITE);
                constellation->addChild(line11,0);
                
                auto line12=DrawNode::create();
                line12->drawLine(constellation->getPosition()+starSprite16->getPosition(), constellation->getPosition()+starSprite12->getPosition(), Color4F::WHITE);
                constellation->addChild(line12,0);
                
                auto line13=DrawNode::create();
                line13->drawLine(constellation->getPosition()+starSprite12->getPosition(), constellation->getPosition()+starSprite15->getPosition(), Color4F::WHITE);
                constellation->addChild(line13,0);
                
                auto line14=DrawNode::create();
                line14->drawLine(constellation->getPosition()+starSprite13->getPosition(), constellation->getPosition()+starSprite11->getPosition(), Color4F::WHITE);
                constellation->addChild(line14,0);
                
                auto line15=DrawNode::create();
                line15->drawLine(constellation->getPosition()+starSprite11->getPosition(), constellation->getPosition()+starSprite10->getPosition(), Color4F::WHITE);
                constellation->addChild(line15,0);
                
                auto line16=DrawNode::create();
                line16->drawLine(constellation->getPosition()+starSprite10->getPosition(), constellation->getPosition()+starSprite9->getPosition(), Color4F::WHITE);
                constellation->addChild(line16,0);
                
                constellation->setScale(0.7);
                return constellation;

                
                
                break;
            }
            case 3://双子
            {
                constellation->autorelease();
                constellation->initWithTexture(starBatchNode->getTexture());
                auto starSprite1=Sprite::createWithTexture(starBatchNode->getTexture());
                auto starSprite2=Sprite::createWithTexture(starBatchNode->getTexture());
                auto starSprite3=Sprite::createWithTexture(starBatchNode->getTexture());
                auto starSprite4=Sprite::createWithTexture(starBatchNode->getTexture());
                auto starSprite5=Sprite::createWithTexture(starBatchNode->getTexture());
                auto starSprite6=Sprite::createWithTexture(starBatchNode->getTexture());
                auto starSprite7=Sprite::createWithTexture(starBatchNode->getTexture());
                auto starSprite8=Sprite::createWithTexture(starBatchNode->getTexture());
                auto starSprite9=Sprite::createWithTexture(starBatchNode->getTexture());
                auto starSprite10=Sprite::createWithTexture(starBatchNode->getTexture());
                auto starSprite11=Sprite::createWithTexture(starBatchNode->getTexture());
                auto starSprite12=Sprite::createWithTexture(starBatchNode->getTexture());
                auto starSprite13=Sprite::createWithTexture(starBatchNode->getTexture());
                auto starSprite14=Sprite::createWithTexture(starBatchNode->getTexture());
                auto starSprite15=Sprite::createWithTexture(starBatchNode->getTexture());
                auto starSprite16=Sprite::createWithTexture(starBatchNode->getTexture());
                
                //坐标
                starSprite1->setPosition(Point(73,-36));
                starSprite1->setAnchorPoint(Point(0.5,0.5));
                
                starSprite2->setPosition(Point(153,-15));
                starSprite2->setAnchorPoint(Point(0.5,0.5));
                
                starSprite3->setPosition(Point(146,-140));
                starSprite3->setAnchorPoint(Point(0.5,0.5));
                
                starSprite4->setPosition(Point(170,-235));
                starSprite4->setAnchorPoint(Point(0.5,0.5));
                
                
                starSprite5->setPosition(Point(186,-175));
                starSprite5->setAnchorPoint(Point(0.5,0.5));
                
                starSprite6->setPosition(Point(207,-205));
                starSprite6->setAnchorPoint(Point(0.5,0.5));
                
                starSprite7->setPosition(Point(241,-212));
                starSprite7->setAnchorPoint(Point(0.5,0.5));
                
                
                starSprite8->setPosition(Point(-33,-38));
                starSprite8->setAnchorPoint(Point(0.5,0.5));
                
                starSprite9->setPosition(Point(30,-75.5));
                starSprite9->setAnchorPoint(Point(0.5,0.5));
                starSprite9->setScale(2.0);
                
                starSprite10->setPosition(Point(-10,-71));
                starSprite10->setAnchorPoint(Point(0.5,0.5));
                
                starSprite11->setPosition(Point(-45,-100));
                starSprite11->setAnchorPoint(Point(0.5,0.5));
                
                starSprite12->setPosition(Point(16,-156));
                starSprite12->setAnchorPoint(Point(0.5,0.5));
               
                
                starSprite13->setPosition(Point(68,-205));
                starSprite13->setAnchorPoint(Point(0.5,0.5));
                
                
                starSprite14->setPosition(Point(64,-257));
                starSprite14->setAnchorPoint(Point(0.5,0.5));
                
                starSprite15->setPosition(Point(28,-274));
                starSprite15->setAnchorPoint(Point(0.5,0.5));
                
                starSprite16->setPosition(Point(-11,-210));
                starSprite16->setAnchorPoint(Point(0.5,0.5));
                starSprite16->setVisible(false);
                
                constellation->addChild(starSprite1,10);
                constellation->addChild(starSprite2,10);
                constellation->addChild(starSprite3,10);
                constellation->addChild(starSprite4,10);
                constellation->addChild(starSprite5,10);
                constellation->addChild(starSprite6,10);
                constellation->addChild(starSprite7,10);
                constellation->addChild(starSprite8,10);
                constellation->addChild(starSprite9,10);
                constellation->addChild(starSprite10,10);
                constellation->addChild(starSprite11,10);
                constellation->addChild(starSprite12,10);
                constellation->addChild(starSprite13,10);
                constellation->addChild(starSprite14,10);
                constellation->addChild(starSprite15,10);
                constellation->addChild(starSprite16,10);
                constellation->setPosition(0,0);
                
                
                
                
                //line
                auto line0=DrawNode::create();
                line0->drawLine(constellation->getPosition()+Point(20,5), constellation->getPosition()+starSprite1->getPosition(), Color4F::WHITE);
                constellation->addChild(line0,0);
                
                auto line1=DrawNode::create();
                line1->drawLine(constellation->getPosition()+starSprite1->getPosition(),constellation->getPosition()+ starSprite2->getPosition(), Color4F::WHITE);
                constellation->addChild(line1,0);
                
                auto line2=DrawNode::create();
                line2->drawLine(constellation->getPosition()+starSprite1->getPosition(), constellation->getPosition()+starSprite3->getPosition(), Color4F::WHITE);
                constellation->addChild(line2,0);
                
                auto line3=DrawNode::create();
                line3->drawLine(constellation->getPosition()+starSprite3->getPosition(), constellation->getPosition()+starSprite4->getPosition(), Color4F::WHITE);
                constellation->addChild(line3,0);
                
                auto line4=DrawNode::create();
                line4->drawLine(constellation->getPosition()+starSprite3->getPosition(), constellation->getPosition()+starSprite5->getPosition(), Color4F::WHITE);
                constellation->addChild(line4,0);
                
                auto line5=DrawNode::create();
                line5->drawLine(constellation->getPosition()+starSprite5->getPosition(), constellation->getPosition()+starSprite6->getPosition(), Color4F::WHITE);
                constellation->addChild(line5,0);
                
                auto line6=DrawNode::create();
                line6->drawLine(constellation->getPosition()+starSprite6->getPosition(), constellation->getPosition()+starSprite7->getPosition(), Color4F::WHITE);
                constellation->addChild(line6,0);
                
                
                auto line7=DrawNode::create();
                line7->drawLine(constellation->getPosition()+starSprite8->getPosition(), constellation->getPosition()+starSprite10->getPosition(), Color4F::WHITE);
                constellation->addChild(line7,0);
                
                auto line8=DrawNode::create();
                line8->drawLine(constellation->getPosition()+starSprite10->getPosition(), constellation->getPosition()+starSprite9->getPosition(), Color4F::WHITE);
                constellation->addChild(line8,0);
                
                auto line9=DrawNode::create();
                line9->drawLine(constellation->getPosition()+starSprite10->getPosition(), constellation->getPosition()+starSprite11->getPosition(), Color4F::WHITE);
                constellation->addChild(line9,0);
                
                auto line10=DrawNode::create();
                line10->drawLine(constellation->getPosition()+starSprite10->getPosition(), constellation->getPosition()+starSprite12->getPosition(), Color4F::WHITE);
                constellation->addChild(line10,0);
                
                auto line11=DrawNode::create();
                line11->drawLine(constellation->getPosition()+starSprite12->getPosition(), constellation->getPosition()+starSprite16->getPosition(), Color4F::WHITE);
                constellation->addChild(line11,0);
                
                auto line12=DrawNode::create();
                line12->drawLine(constellation->getPosition()+starSprite12->getPosition(), constellation->getPosition()+starSprite13->getPosition(), Color4F::WHITE);
                constellation->addChild(line12,0);
                
                auto line13=DrawNode::create();
                line13->drawLine(constellation->getPosition()+starSprite13->getPosition(), constellation->getPosition()+starSprite14->getPosition(), Color4F::WHITE);
                constellation->addChild(line13,0);
                
                auto line14=DrawNode::create();
                line14->drawLine(constellation->getPosition()+starSprite16->getPosition(), constellation->getPosition()+starSprite15->getPosition(), Color4F::WHITE);
                constellation->addChild(line14,0);
                
                auto line15=DrawNode::create();
                line15->drawLine(constellation->getPosition()+starSprite1->getPosition(), constellation->getPosition()+starSprite9->getPosition(), Color4F::WHITE);
                constellation->addChild(line15,0);
                
                
                constellation->setScale(0.7);
                return constellation;

                
            
            
                break;
            }
                
            case 4://双鱼
            {
                constellation->autorelease();
                constellation->initWithTexture(starBatchNode->getTexture());
                auto starSprite1=Sprite::createWithTexture(starBatchNode->getTexture());
                auto starSprite2=Sprite::createWithTexture(starBatchNode->getTexture());
                auto starSprite3=Sprite::createWithTexture(starBatchNode->getTexture());
                auto starSprite4=Sprite::createWithTexture(starBatchNode->getTexture());
                auto starSprite5=Sprite::createWithTexture(starBatchNode->getTexture());
                auto starSprite6=Sprite::createWithTexture(starBatchNode->getTexture());
                auto starSprite7=Sprite::createWithTexture(starBatchNode->getTexture());
                auto starSprite8=Sprite::createWithTexture(starBatchNode->getTexture());
                auto starSprite9=Sprite::createWithTexture(starBatchNode->getTexture());
                auto starSprite10=Sprite::createWithTexture(starBatchNode->getTexture());
                auto starSprite11=Sprite::createWithTexture(starBatchNode->getTexture());
                auto starSprite12=Sprite::createWithTexture(starBatchNode->getTexture());
                auto starSprite13=Sprite::createWithTexture(starBatchNode->getTexture());
                auto starSprite14=Sprite::createWithTexture(starBatchNode->getTexture());
                auto starSprite15=Sprite::createWithTexture(starBatchNode->getTexture());
                auto starSprite16=Sprite::createWithTexture(starBatchNode->getTexture());
                auto starSprite17=Sprite::createWithTexture(starBatchNode->getTexture());
                auto starSprite18=Sprite::createWithTexture(starBatchNode->getTexture());
                //坐标
                starSprite1->setPosition(Point(-16,-32));
                starSprite1->setAnchorPoint(Point(0.5,0.5));
                
                starSprite2->setPosition(Point(18,-65));
                starSprite2->setAnchorPoint(Point(0.5,0.5));
                
                starSprite3->setPosition(Point(28,-122));
                starSprite3->setAnchorPoint(Point(0.5,0.5));
                
                starSprite4->setPosition(Point(-17,-195));
                starSprite4->setAnchorPoint(Point(0.5,0.5));
                
                
                starSprite5->setPosition(Point(-45,-238));
                starSprite5->setAnchorPoint(Point(0.5,0.5));
                
                starSprite6->setPosition(Point(-97,-299));
                starSprite6->setAnchorPoint(Point(0.5,0.5));
                
                starSprite7->setPosition(Point(-54,-294));
                starSprite7->setAnchorPoint(Point(0.5,0.5));
                
                
                starSprite8->setPosition(Point(0,-276));
                starSprite8->setAnchorPoint(Point(0.5,0.5));
                
                starSprite9->setPosition(Point(76,-276.5));
                starSprite9->setAnchorPoint(Point(0.5,0.5));
                
                
                starSprite10->setPosition(Point(110,-280));
                starSprite10->setAnchorPoint(Point(0.5,0.5));
                
                starSprite11->setPosition(Point(208,-272));
                starSprite11->setAnchorPoint(Point(0.5,0.5));
                
                starSprite12->setPosition(Point(248,-274));
                starSprite12->setAnchorPoint(Point(0.5,0.5));
                
                
                starSprite13->setPosition(Point(284,-260));
                starSprite13->setAnchorPoint(Point(0.5,0.5));
                
                
                starSprite14->setPosition(Point(315,-279));
                starSprite14->setAnchorPoint(Point(0.5,0.5));
                
                starSprite15->setPosition(Point(322,-304));
                starSprite15->setAnchorPoint(Point(0.5,0.5));
                
                starSprite16->setPosition(Point(285,-311));
                starSprite16->setAnchorPoint(Point(0.5,0.5));
               
                starSprite17->setPosition(Point(246,-314));
                starSprite17->setAnchorPoint(Point(0.5,0.5));
                
                starSprite18->setPosition(Point(233,-293));
                starSprite18->setAnchorPoint(Point(0.5,0.5));
                
                constellation->addChild(starSprite1,10);
                constellation->addChild(starSprite2,10);
                constellation->addChild(starSprite3,10);
                constellation->addChild(starSprite4,10);
                constellation->addChild(starSprite5,10);
                constellation->addChild(starSprite6,10);
                constellation->addChild(starSprite7,10);
                constellation->addChild(starSprite8,10);
                constellation->addChild(starSprite9,10);
                constellation->addChild(starSprite10,10);
                constellation->addChild(starSprite11,10);
                constellation->addChild(starSprite12,10);
                constellation->addChild(starSprite13,10);
                constellation->addChild(starSprite14,10);
                constellation->addChild(starSprite15,10);
                constellation->addChild(starSprite16,10);
                constellation->addChild(starSprite17,10);
                constellation->addChild(starSprite18,10);
                constellation->setPosition(0,0);
                
                
                
                
                //line
                auto line0=DrawNode::create();
                line0->drawLine(constellation->getPosition()+Point(10,5), constellation->getPosition()+starSprite1->getPosition(), Color4F::WHITE);
                constellation->addChild(line0,0);
                
                auto line1=DrawNode::create();
                line1->drawLine(constellation->getPosition()+starSprite1->getPosition(),constellation->getPosition()+ starSprite2->getPosition(), Color4F::WHITE);
                constellation->addChild(line1,0);
                
                auto line2=DrawNode::create();
                line2->drawLine(constellation->getPosition()+starSprite2->getPosition(), constellation->getPosition()+starSprite3->getPosition(), Color4F::WHITE);
                constellation->addChild(line2,0);
                
                auto line3=DrawNode::create();
                line3->drawLine(constellation->getPosition()+starSprite3->getPosition(), constellation->getPosition()+starSprite4->getPosition(), Color4F::WHITE);
                constellation->addChild(line3,0);
                
                auto line4=DrawNode::create();
                line4->drawLine(constellation->getPosition()+starSprite4->getPosition(), constellation->getPosition()+starSprite5->getPosition(), Color4F::WHITE);
                constellation->addChild(line4,0);
                
                auto line5=DrawNode::create();
                line5->drawLine(constellation->getPosition()+starSprite5->getPosition(), constellation->getPosition()+starSprite6->getPosition(), Color4F::WHITE);
                constellation->addChild(line5,0);
                
                auto line6=DrawNode::create();
                line6->drawLine(constellation->getPosition()+starSprite6->getPosition(), constellation->getPosition()+starSprite7->getPosition(), Color4F::WHITE);
                constellation->addChild(line6,0);
                
                
                auto line7=DrawNode::create();
                line7->drawLine(constellation->getPosition()+starSprite7->getPosition(), constellation->getPosition()+starSprite8->getPosition(), Color4F::WHITE);
                constellation->addChild(line7,0);
                
                auto line8=DrawNode::create();
                line8->drawLine(constellation->getPosition()+starSprite8->getPosition(), constellation->getPosition()+starSprite9->getPosition(), Color4F::WHITE);
                constellation->addChild(line8,0);
                
                auto line9=DrawNode::create();
                line9->drawLine(constellation->getPosition()+starSprite9->getPosition(), constellation->getPosition()+starSprite10->getPosition(), Color4F::WHITE);
                constellation->addChild(line9,0);
                
                auto line10=DrawNode::create();
                line10->drawLine(constellation->getPosition()+starSprite10->getPosition(), constellation->getPosition()+starSprite11->getPosition(), Color4F::WHITE);
                constellation->addChild(line10,0);
                
                auto line11=DrawNode::create();
                line11->drawLine(constellation->getPosition()+starSprite11->getPosition(), constellation->getPosition()+starSprite12->getPosition(), Color4F::WHITE);
                constellation->addChild(line11,0);
                
                auto line12=DrawNode::create();
                line12->drawLine(constellation->getPosition()+starSprite12->getPosition(), constellation->getPosition()+starSprite13->getPosition(), Color4F::WHITE);
                constellation->addChild(line12,0);
                
                auto line13=DrawNode::create();
                line13->drawLine(constellation->getPosition()+starSprite13->getPosition(), constellation->getPosition()+starSprite14->getPosition(), Color4F::WHITE);
                constellation->addChild(line13,0);
                
                auto line14=DrawNode::create();
                line14->drawLine(constellation->getPosition()+starSprite14->getPosition(), constellation->getPosition()+starSprite15->getPosition(), Color4F::WHITE);
                constellation->addChild(line14,0);
                
                auto line15=DrawNode::create();
                line15->drawLine(constellation->getPosition()+starSprite15->getPosition(), constellation->getPosition()+starSprite16->getPosition(), Color4F::WHITE);
                constellation->addChild(line15,0);
                
                auto line16=DrawNode::create();
                line16->drawLine(constellation->getPosition()+starSprite16->getPosition(), constellation->getPosition()+starSprite17->getPosition(), Color4F::WHITE);
                constellation->addChild(line16,0);
                
                auto line17=DrawNode::create();
                line17->drawLine(constellation->getPosition()+starSprite17->getPosition(), constellation->getPosition()+starSprite18->getPosition(), Color4F::WHITE);
                constellation->addChild(line17,0);
                
                auto line18=DrawNode::create();
                line18->drawLine(constellation->getPosition()+starSprite18->getPosition(), constellation->getPosition()+starSprite12->getPosition(), Color4F::WHITE);
                constellation->addChild(line18,0);
                
                constellation->setScale(0.7);
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