//
//  TrangleBarrier.cpp
//  jump
//
//  Created by zwj on 16/6/13.
//
//

#include "Barrier.hpp"
#include "GameLayer.hpp"
#include "FlyLayer.hpp"

TriangleBarrier::TriangleBarrier(
 std::string* stTemp,
 Layer* layer,
 Rect recta,
 float spLocationX,
 float spLocationY,
 float spLengthX,
 float spLengthY,
 int localZOrder
 ):Barrier(stTemp, layer, recta, spLocationX, spLocationY, spLengthX, spLengthY, localZOrder)

{
    idChar='T';
    sp=Sprite::createWithTexture(((GameLayer*)layer)->sh->batchNode->getTexture(),recta);
    sp->setAnchorPoint(Point(0.50,0.5));
    sp->setPosition(Point(spLocationX,spLocationY));
    Size size=sp->getContentSize();//获取精灵的尺寸
    float scaleX=spLengthX/size.width;//计算出精灵X方向缩放比
    float scaleY=spLengthY/size.height;//计算出精灵Y方向缩放比
    sp->setScaleX(scaleX);//设置精灵X方向缩放比
    sp->setScaleY(scaleY);//设置精灵Y方向缩放比
    //	layer->addChild(sp,localZOrder);//将精灵添加到布景中
    if(layer->getTag() == INDEX_GRAMLAYER)
    {
        ((GameLayer*)(layer))->sh->batchNode->addChild(sp,localZOrder);//将精灵添加到布景中
    }
    else if(layer->getTag() == INDEX_FLYLAYER)
    {
        ((FlyLayer*)(layer))->sh->batchNode->addChild(sp,localZOrder);//将精灵添加到布景中
    }
    
    this->P = sp->getPosition();//记录障碍物当前位置
    
    
}

bool TriangleBarrier::collision(JumpCube *jc)
{
    Point point(jc->sp->getPosition().x-this->sp->getPosition().x,jc->sp->getPosition().y-this->sp->getPosition().y);
    float distance=point.getLength();
    float length=jc->lengthX/2+this->lengthX/2;
    if (distance<=length)
    {
        jc->explode();
        return true;
    }
    else
    {
        return false;
    }
    
}
bool TriangleBarrier::collsionFo(FlyObject *fo)
{
    if (fo->sp->boundingBox().intersectsRect(sp->getBoundingBox()))
    {
        fo->explode();
        return  true;
    }
    else
    {
        return false;
    }
}