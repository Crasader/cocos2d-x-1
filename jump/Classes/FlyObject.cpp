//
//  FlyObject.cpp
//  jump
//
//  Created by zwj on 16/6/11.
//
//

#include "FlyObject.hpp"
#include "FlyLayer.hpp"

FlyObject::FlyObject(std::string* stTemp, Layer* layer,
                     Rect recta, float spLocationX, float spLocationY, float spLengthX, float spLengthY,
                     Rect recta1, float sp1LocationX, float sp1LocationY, float sp1LengthX, float sp1LengthY,
                     int localZOrder)
{
    this->layer=layer;
    this->st=stTemp;
    this->lengthX=spLengthX;
    this->lengthY=sp1LengthX/2+sp1LocationY;
    
    sp=Sprite::create();
    sp->setContentSize(Size(spLengthX,sp1LengthX/2+sp1LocationY));
    sp->setPosition(Point(JCX,JCY));
    layer->addChild(sp,1);
    
    P=sp->getPosition();
    r=sp->getRotation();
    
    sp2=Sprite::createWithTexture(((FlyLayer*)layer)->sh->batchNode->getTexture(), recta);
    sp2->setAnchorPoint(Point(0.5,0.5));
    sp2->setPosition(Point(spLocationX,spLocationY));
    Size size=sp2->getContentSize();
    float scaleX=spLengthX/size.width;
    float scaleY=spLengthY/size.height;
    sp2->setScale(scaleX, scaleY);
    sp2->setColor(Color3B(102,204,35));
    sp->addChild(sp2,localZOrder);
    
    sp1 = Sprite::createWithTexture(((FlyLayer*)(layer))->sh->batchNode->getTexture(),recta1);//创建精灵
    sp1->setAnchorPoint(Point(0.5f,0.5f));//设置精灵的锚点   设为中心点
    sp1->setPosition(Point(sp1LocationX,sp1LocationY));//设置精灵的位置
    size=sp1->getContentSize();//获取精灵的尺寸
    scaleX=sp1LengthX/size.width;//计算出精灵X方向缩放比
    scaleY=sp1LengthY/size.height;//计算出精灵Y方向缩放比
    sp1->setScaleX(scaleX);//设置精灵X方向缩放比
    sp1->setScaleY(scaleY);//设置精灵Y方向缩放比
    sp1->setColor(Color3B(102,204,35));
    sp->addChild(sp1,localZOrder);//将精灵添加到布景中
    
    heightUp=HEIGHT-HEIGHT_EDGE;
    heightDown=HEIGHT_EDGE;
    
    updataData();
    
    psh=new ParticleSystemHelp();
    layer->addChild(psh->psq1,BatchNodeZOrder-1);
    psh->psq12->retain();
    psh->psq1->setVisible(false);
    psh->isPsq1=false;
    
    psh->psq1->setSourcePosition(Point(minX,minY/2+maxY/2-5));
    psh->psq1->resetSystem();
    psh->psq1->setVisible(true);
    psh->isPsq1=true;
    
    psh->psq1->retain();
    
    }

FlyObject::~FlyObject()
{
    delete st;
}

void FlyObject::updata()
{
    psh->psq1->setSourcePosition(Point(minX,minY/2+maxY/2-5));

    updataData();
    if(((FlyLayer*)(layer))->isTouch == true)//判断手指是否触控到了屏幕
    {
        up();//调用上升方法
    }
    else
    {
        down();//调用下降方法
    }
}

void FlyObject::up()
{
    if (P.y+lengthY/2 > heightUp-1)
    {
        if (r<0)
        {
            sp->setRotation(r+vRotationJump*0.8*INTERVALJC);
            r=sp->getRotation();
        }
        else
        {
            sp->setRotation(0);
            r=sp->getRotation();
        
        }
    }
    else
    {
        sp->setPosition(Point(P.x,P.y+vJump*INTERVALJC));
        P=sp->getPosition();
        if (r>-20)
        {
            sp->setRotation(r-vRotationJump*INTERVALJC);
            r=sp->getRotation();
        }
    
    
    }
    
}
void FlyObject::down()
{
    if(P.y-lengthY/2  < heightDown+1 )//判断飞行器的下边是否到达下限   并且此时还处于倾斜状态
    {
        if(r>0)//判断当前旋转角是否小于0
        {
            sp->setRotation(r - vRotationJump * INTERVALJC);//设置飞行器的旋转角
            r = sp->getRotation();//记录当前旋转角
        }
        else
        {
            sp->setRotation(0);//设置飞行器的旋转角
            r = sp->getRotation();//记录当前旋转角
        }
    }
    else
    {
        sp->setPosition(Point(P.x, P.y - vJump * 0.8f * INTERVALJC));//设置飞行器的位置
        P = sp->getPosition();//记录飞行器当前位置
        if(r<20)//判断当前旋转角是否小于一个常量
        {
            sp->setRotation(r + vRotationJump * INTERVALJC);//设置飞行器的旋转角
            r = sp->getRotation();//记录当前旋转角
        }
    }
    
}
void FlyObject::updataData()
{
    Rect rect = sp->getBoundingBox();//获取精灵当前的包围盒区域
    minX = rect.origin.x;//获取飞行器最左侧的X值
    maxX = minX + rect.size.width;//获取飞行器最右侧的X值
    minY = rect.origin.y;//获取飞行器下边的高度值
    maxY = minY + rect.size.height;//获取飞行器上边的高度值
}

void FlyObject::explode()
{
    sp1->setVisible(false);
    sp->setVisible(false);//设置方块精灵不可见
    
    psh->psq1->stopSystem();
    layer->addChild(psh->psq12,BatchNodeZOrder-1);//添加爆炸效果
    
    psh->psq12->setSourcePosition(Point(minX/2+maxX/2-150 , minY/2+maxY/2-70));
    psh->psq12->resetSystem();
    psh->psq1->setVisible(true);
    
}