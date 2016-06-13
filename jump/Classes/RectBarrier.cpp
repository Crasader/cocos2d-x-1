//
//  RectBarrier.cpp
//  jump
//
//  Created by zwj on 16/6/13.
//
//

#include "Barrier.hpp"
#include "GameLayer.hpp"
#include "FlyLayer.hpp"
#include "LevelLayer.hpp"
#include "MenuLayer.hpp"
#include "ChoiceCubeLayer.hpp"
#include "MusicLayer.hpp"

RectBarrier::RectBarrier
(
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
    idChar = 'R';//…Ë÷√æÿ–Œ’œ∞≠ŒÔid
    sp = Sprite::createWithTexture(((GameLayer*)(layer))->sh->batchNode->getTexture(),recta);//¥¥Ω®æ´¡È∂‘œÛ
    //	sp = Sprite::create(pic);//¥¥Ω®æ´¡È
    sp->setAnchorPoint(Point(0.5f,0.5f));//…Ë÷√æ´¡Èµƒ√™µ„   …ËŒ™÷––ƒµ„
    sp->setPosition(Point(spLocationX,spLocationY));//…Ë÷√æ´¡ÈµƒŒª÷√
    Size size=sp->getContentSize();//ªÒ»°æ´¡Èµƒ≥ﬂ¥Á
    float scaleX=spLengthX/size.width;//º∆À„≥ˆæ´¡ÈX∑ΩœÚÀı∑≈±»
    float scaleY=spLengthY/size.height;//º∆À„≥ˆæ´¡ÈY∑ΩœÚÀı∑≈±»
    sp->setScaleX(scaleX);//…Ë÷√æ´¡ÈX∑ΩœÚÀı∑≈±»
    sp->setScaleY(scaleY);//…Ë÷√æ´¡ÈY∑ΩœÚÀı∑≈±»
    //	layer->addChild(sp,localZOrder);//Ω´æ´¡ÈÃÌº”µΩ≤ºæ∞÷–
    if(layer->getTag() == INDEX_GRAMLAYER)
    {
        ((GameLayer*)(layer))->sh->batchNode->addChild(sp,localZOrder);//Ω´æ´¡ÈÃÌº”µΩ≤ºæ∞÷–
    }
    else if(layer->getTag() == INDEX_MENULAYER)
    {
        ((MenuLayer*)(layer))->sh->batchNode->addChild(sp,localZOrder);//Ω´æ´¡ÈÃÌº”µΩ≤ºæ∞÷–
    }
    else if(layer->getTag() == INDEX_FLYLAYER)
    {
        ((FlyLayer*)(layer))->sh->batchNode->addChild(sp,localZOrder);//Ω´æ´¡ÈÃÌº”µΩ≤ºæ∞÷–
    }
    else if(layer->getTag() == INDEX_CHOICECUBELAYER)
    {
        ((ChoiceCubeLayer*)(layer))->sh->batchNode->addChild(sp,localZOrder);//Ω´æ´¡ÈÃÌº”µΩ≤ºæ∞÷–
    }
    else if(layer->getTag() == INDEX_MUSICLAYER)
    {
        ((MusicLayer*)(layer))->sh->batchNode->addChild(sp,localZOrder);//Ω´æ´¡ÈÃÌº”µΩ≤ºæ∞÷–
    }
    
    
    this->P = sp->getPosition();//º«¬º’œ∞≠ŒÔµ±«∞Œª÷√
}
//Ã¯‘æ∑ΩøÈµƒ◊Û±ﬂ∂˘  –°”⁄µ»”⁄   ’œ∞≠ŒÔµƒ”“±ﬂ  ≤¢«“   Ã¯‘æ∑ΩøÈµƒ”“±ﬂ∂˘  ¥Û”⁄µ»”⁄   ’œ∞≠ŒÔµƒ◊Û±ﬂ     ±   Ω¯––≈ˆ◊≤ºÏ≤‚
bool RectBarrier::collision(JumpCube* jc)
{
    float jcBottom = jc->sp->getPosition().y - jc->lengthY/2;//Ã¯‘æ∑ΩøÈµƒœ¬±ﬂ∂˘
    float rbTop = this->sp->getPosition().y + this->lengthY/2;//’œ∞≠ŒÔµƒ…œ±ﬂ∂˘
    
    float jcZ = jc->sp->getPosition().x-jc->lengthX/2;//Ã¯‘æ∑ΩøÈµƒ◊Û±ﬂ
    float jcY = jc->sp->getPosition().x+jc->lengthX/2;//Ã¯‘æ∑ΩøÈµƒ”“±ﬂ
    float rbZ = this->sp->getPosition().x - this->lengthX/2;//’œ∞≠ŒÔµƒ◊Û±ﬂ∂˘
    float rbY = this->sp->getPosition().x + this->lengthX/2;//’œ∞≠ŒÔµƒ◊Û±ﬂ∂˘
    
    if(jc->sp->getPosition().x<rbZ && jcY>=rbZ)//Ã¯‘æ∑ΩøÈµƒ÷–µ„x◊¯±Í  –°”⁄ ’œ∞≠ŒÔµƒ◊Û±ﬂ && Ã¯‘æ∑ΩøÈµƒ”“±ﬂ  ¥Û”⁄µ»”⁄   ’œ∞≠ŒÔµƒ◊Û±ﬂ∂˘
    {
        if(jcBottom<rbTop)//Ã¯‘æ∑ΩøÈµƒœ¬±ﬂ∂˘  –°”⁄ ’œ∞≠ŒÔµƒ…œ±ﬂ∂˘
        {
            jc->explode();//µ˜”√∑ΩøÈµƒ±¨’®∑Ω∑®
            return true;
        }
        else//Ã¯‘æ∑ΩøÈµƒœ¬±ﬂ∂˘  ¥Û”⁄µ»”⁄  ’œ∞≠ŒÔµƒ…œ±ﬂ∂˘
        {
            if(jcBottom <= rbTop)//Ã¯‘æ∑ΩøÈµƒœ¬±ﬂ∂˘  –°”⁄µ»”⁄  ’œ∞≠ŒÔµƒ…œ±ﬂ∂˘
            {
                jc->refleshAngleAndPosition(rbTop + jc->lengthY/2);//µ˜”√∏¸–¬∑ΩøÈ◊ÀÃ¨µƒ∑Ω∑®
            }
            return false;
        }
    }
    else//Ã¯‘æ∑ΩøÈµƒ÷–µ„x◊¯±Í  ¥Û”⁄   ’œ∞≠ŒÔµƒ◊Û±ﬂ    ≤¢«“¥À ±µƒjcBottom“—æ≠¥Û”⁄µ»”⁄rbTop¡À
    {
        if(jcBottom <= rbTop)//Ã¯‘æ∑ΩøÈµƒœ¬±ﬂ∂˘  –°”⁄µ»”⁄  ’œ∞≠ŒÔµƒ…œ±ﬂ∂˘
        {
            jc->refleshAngleAndPosition(rbTop + jc->lengthY/2);//µ˜”√∏¸–¬∑ΩøÈ◊ÀÃ¨µƒ∑Ω∑®
        }
        return false;
    }
}
bool RectBarrier::collisionFo(FlyObject* fo)
{
    float rbTop = this->sp->getPosition().y + this->lengthY/2;//’œ∞≠ŒÔµƒ…œ±ﬂ∂˘
    float rbBottom = this->sp->getPosition().y - this->lengthY/2;//’œ∞≠ŒÔµƒœ¬±ﬂ∂˘
    float rbZ = this->sp->getPosition().x - this->lengthX/2;//’œ∞≠ŒÔµƒ◊Û±ﬂ∂˘
    float rbY = this->sp->getPosition().x + this->lengthX/2;//’œ∞≠ŒÔµƒ”“±ﬂ∂˘
    
    if(fo->maxX>=rbZ && fo->minY>=rbTop && fo->minX<=rbY)//∑…––∆˜µƒ”“±ﬂ ¥Û”⁄ ’œ∞≠ŒÔµƒ◊Û±ﬂ   ∑…––∆˜µƒœ¬±ﬂ¥Û”⁄µ»”⁄’œ∞≠ŒÔµƒ…œ±ﬂ  ∑…––∆˜µƒ◊Û±ﬂ–°”⁄µ»”⁄’œ∞≠ŒÔµƒ”“±ﬂ
    {
        if(rbTop>fo->heightDown)//’œ∞≠ŒÔµƒ…œ±ﬂ∂˘¥Û”⁄∑…––∆˜µƒ∑…––œ¬œﬁ
        {
            fo->heightDown = rbTop;//…Ë÷√∑…––∆˜µƒ∑…––œ¬œﬁ
        }
        return false;
    }
    if(fo->maxX>=rbZ && fo->maxY<=rbBottom && fo->minX<=rbY)//∑…––∆˜µƒ”“±ﬂ ¥Û”⁄ ’œ∞≠ŒÔµƒ◊Û±ﬂ   ∑…––∆˜µƒ…œ±ﬂ–°”⁄µ»”⁄’œ∞≠ŒÔµƒœ¬±ﬂ  ∑…––∆˜µƒ◊Û±ﬂ–°”⁄µ»”⁄’œ∞≠ŒÔµƒ”“±ﬂ
    {
        if(rbBottom<fo->heightUp)//’œ∞≠ŒÔµƒœ¬±ﬂ∂˘–°”⁄∑…––∆˜µƒ∑…––…œœﬁ
        {
            fo->heightUp = rbBottom;//…Ë÷√∑…––∆˜µƒ∑…––…œœﬁ
        }
        return false;
    }
    if(fo->minX>rbY)//∑…––∆˜µƒ◊Û±ﬂ¥Û”⁄’œ∞≠ŒÔµƒ”“±ﬂ
    {
        if(rbTop == fo->heightDown)//’œ∞≠ŒÔµƒ…œ±ﬂ∂˘ µ»”⁄ ∑…––∆˜µƒ∑…––œ¬œﬁ
        {
            fo->heightDown = HEIGHT_EDGE;//…Ë÷√∑…––∆˜µƒ∑…––œ¬œﬁ
        }
        if(rbBottom == fo->heightUp)//’œ∞≠ŒÔµƒœ¬±ﬂ∂˘ µ»”⁄ ∑…––∆˜µƒ∑…––…œœﬁ
        {
            fo->heightUp = HEIGHT - HEIGHT_EDGE;//…Ë÷√∑…––∆˜µƒ∑…––…œœﬁ
        }
        return false;
    }
    if(fo->minX<rbZ && fo->maxX>rbZ)//∑…––∆˜µƒ”“±ﬂ –°”⁄ ’œ∞≠ŒÔµƒ◊Û±ﬂ   ∑…––∆˜µƒ◊Û±ﬂ ¥Û”⁄ ’œ∞≠ŒÔµƒ”“±ﬂ
    {
        if(fo->maxY<rbBottom || fo->minY>rbTop)//∑…––∆˜µƒ…œ±ﬂ  –°”⁄ ’œ∞≠ŒÔµƒœ¬±ﬂ     ªÚ’ﬂ      ∑…––∆˜µƒœ¬±ﬂ  ¥Û”⁄ ’œ∞≠ŒÔµƒ…œ±ﬂ
        {
            return false;
        }
        
        if (fo->sp->boundingBox().intersectsRect(sp->boundingBox()))//≈–∂œ∑…––∆˜∫Õ’œ∞≠ŒÔ÷Æ∫Û «∑Ò¥Ê‘⁄ΩªºØ//≈–∂œ∑…––∆˜À˘‘⁄µƒ∞¸Œß∫–”Î’œ∞≠ŒÔÀ˘‘⁄µƒ∞¸Œß∫– «∑Ò”–ΩªºØ
        {
            fo->explode();//µ˜”√∑…––∆˜µƒ±¨’®∑Ω∑®
            return true;
        }
        else
        {
            return false;
        }
    }
}
