//
//  randomStars.cpp
//  MyCppGame
//
//  Created by zwj on 16/6/14.
//
//

#include "randomStars.hpp"
#include <time.h>
#include "ConstellationSprite.hpp"

//构造，传入创建层，星星数量，闪烁数量
randomStars::randomStars(Layer* layerIn,int starNum,int shineStarNum,int constellationNum)
{

    this->layer=layerIn;
    this->starNum=starNum;
    this->shineStarNum=shineStarNum;
    this->constellationNum=constellationNum;
    //向量大小定义为100，避免反复申请内存
    //starsVector.resize(100);
    starsVector.reserve(100);
    starsVector.clear();
}

//生成随机位置的星星

void randomStars::randomPosition()

{   std::srand(unsigned(time(NULL)));
    
   
    SpriteBatchNode* starsBatchNode=SpriteBatchNode::create("star.png");
    starsBatchNode->setPosition(Point::ZERO);
    auto size=Director::getInstance()->getVisibleSize();
    
    //生成星星 starNum个
    for (int i=0; i<starNum; i++)
    {
        //随机坐标
        float x=random(0.2f, 0.9f)*size.width;
        float y=((size.height/5)*2.5+rand_0_1()*size.height/5)*0.8;
        
        //创建星星
        auto star=Sprite::createWithTexture(starsBatchNode->getTexture());
        star->setPosition(Point(x,y));
        
        
        //随机生成大小不一的星星
        star->setScale(random(1.0f, 2.0f));
        
        layer->addChild(star,100);
        
        //starsVector.push_back(star);
        starsVector.pushBack(star);
    }
    
    //星座...........
    
    //如果传入的星座编号不为0，则生成
    if (constellationNum>0&&constellationNum<13)
    {
        constellation=constellationSprite::createConstellationSprite(constellationNum);
        //调整位置和大小
        switch (constellationNum)
        {
            case 1://baiyang
            {
                constellation->setPosition(700,550);
                

                break;
            }
                case 2:  //jinniu
            {
                
                constellation->setPosition(700,550);
                constellation->setRotation(100);
                
                break;
            }
                
                case 3: //shuangzi
            {
                constellation->setPosition(500,550);
               

                break;
            }
            case 4://shuangyu
            {
                constellation->setPosition(400,550);
                constellation->setRotation(-50);

                break;
            }

            case 5: //mojie
            {
                constellation->setPosition(600,500);
               

                break;
            }

            case 6: //chunv
            {
                constellation->setPosition(600,600);
             

                break;
            }

            case 7:  //sheshou
            {
                constellation->setPosition(600,550);
               

                break;
            }

            case 8: //shuiping
            {
                constellation->setPosition(700,550);
                constellation->setRotation(40);
                break;
            }

            case 9:  //tianping
            {
                constellation->setPosition(530,550);
               

                break;
            }
            case 10:  //shizi
            {
                constellation->setPosition(430,550);
               
                break;
            }

            case 11:
            {
                constellation->setPosition(600,600);
               

                break;
            }

            case 12:
            {
                constellation->setPosition(700,550);
                

                break;
            }


            default:
                break;
        }
       
       
        constellation->setAnchorPoint(Point(0.5,0.5));
        layer->addChild(constellation,100);
        
        //压入vector
        
        //starsVector.push_back(constellation);
        starsVector.pushBack(constellation);
        
    }
   
    
    
    
    
    
    
   
    
    //检查生成的星星有无重叠
   
    int i, j;
    for (i=0; i<starNum; i++)
    { //0号星星依次与其他星星比较
        for (j=0; j<starNum; )
        {
            //两个星星有交叠
            if (i!=j)
            {
                
                if (starsVector.at(i)->getBoundingBox().intersectsRect(starsVector.at(j)->getBoundingBox()))
                {
                    starsVector.at(i)->setPosition(random(0.05f, 0.95f)*size.width,random(0.5f, 0.95f)*size.height);
                    //有交叠则重置坐标，并重头比较坐标
                    j=0;
                }
                else
                {
                    ++j;
                }

            }
            else
            { ++j;}
            
        }
    }
    
    
    
       //闪烁
    for (int i=0; i<shineStarNum; i++)
    {
        //fadeout
        auto act1=FadeOut::create(random(0.5f, 2.0f));
        
        //fadein
        auto act2=FadeIn::create(random(0.5f, 2.0f));
        
        //delay
        auto delay=DelayTime::create(random(0.0f, 10.0f));
        
        
       // starsVector[i]->runAction(RepeatForever::create(Sequence::create(act1,act2,delay, NULL)));
        
        starsVector.at(i)->runAction(RepeatForever::create(Sequence::create(act1,act2,delay, NULL)));
        
    }

}

