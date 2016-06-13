//
//  JumpCube.cpp
//  jump
//
//  Created by zwj on 16/6/11.
//
//

#include "JumpCube.hpp"
#include "GameLayer.hpp"

JumpCube::JumpCube(std::string* stTemp, Layer* layer, Rect recta, float spLocationX, float spLocationY, float spLength, int localZOrder)
{

    this->lengthX=spLength;
    this->lengthY=spLength;
    this->layer=layer;
    
    this->st=stTemp;
    sp=Sprite::createWithTexture(((GameLayer*)layer)->sh->batchNode->getTexture(), recta);
    sp->setAnchorPoint(Point(0,0));
    sp->setPosition(Point(spLocationX,spLocationY));
    Size size=sp->getContentSize();
    float scaleX=spLength/size.width;
    float scaleY=spLength/size.height;
    sp->setScaleX(scaleX);
    sp->setScaleY(scaleY);
    sp->setColor(Color3B(102,204,35));
    layer->addChild(sp,localZOrder);
    

    p=sp->getPosition();
    r=sp->getRotation();
    
    psh=new ParticleSystemHelp();
    layer->addChild(psh->psq1,BatchNodeZOrder-1);
    psh->psq12->retain();
    psh->psq1->setVisible(false);
    psh->isPsq1=false;

}

JumpCube::~JumpCube()
{
    delete st;
}

void JumpCube::reflesh(float maxH)
{
    if (maxH!=this->sp->getPosition().y)
    {
        isDown=true;
    }
    p=sp->getPosition();
    r=sp->getRotation();
    
}
void JumpCube::Jump()
{
    if (psh->isPsq1==true)
    {
        psh->psq1->retain();
        psh->psq1->stopSystem();
        psh->isPsq1=false;
    }
    timeCount++;
    sp->setPosition(Point(p.x,p.y+vJump*timeCount*INTERVALJC));
    sp->setRotation(r+vRotationJump*timeCount*INTERVALJC);
    
    /////////////
    if (sp->getPosition().y-p.y>=JCJH)
    {
        this->isJump=false;
        timeCount=0;
        p=sp->getPosition();
        sp->setRotation(r+90);
        r=sp->getRotation();
    }

}
void JumpCube::Down()
{
    if (psh->isPsq1==true)
    {
        psh->psq1->retain();
        psh->psq1->stopSystem();
        psh->isPsq1=false;
    }
    timeCount++;
    sp->setPosition(Point(p.x,p.y-vDown*timeCount*INTERVALJC));
    sp->setRotation(r+vRotationJump*timeCount*INTERVALJC);
    


}
void JumpCube::refleshAngleAndPosition(float y)
{

    if (psh->isPsq1==false)
    {
        psh->psq1->setSourcePosition(Point(sp->getPosition().x-lengthX/2,y-lengthY/2));
        psh->psq1->resetSystem();
        psh->psq1->setVisible(true);
        psh->isPsq1=true;
        psh->psq1->retain();
        
        
    }
    float angle=(sp->getRotation()-r);
    if (0<angle) {
        sp->setRotation(r+90);
        this->isDown=false;
        p = Point(sp->getPosition().x,y);//记录方块当前位置
        r = sp->getRotation();//记录方块当前旋转角
        this->sp->setPosition(p);//设置方块精灵位置
    }
}
    void JumpCube::explode()
    {
        psh->psq1->stopSystem();
        layer->addChild(psh->psq12,BatchNodeZOrder-1);//添加爆炸效果
        
        
        psh->psq12->setSourcePosition(Point(sp->getPosition().x-150 , sp->getPosition().y-70));
        psh->psq12->resetSystem();
        
        sp->setVisible(false);//设置方块精灵不可见
        
}