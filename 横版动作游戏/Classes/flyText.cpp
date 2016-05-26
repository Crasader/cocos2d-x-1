//
//  flyText.cpp
//  practice
//
//  Created by zwj on 16/5/25.
//
//

#include "flyText.hpp"

FlyText *FlyText::create(const char *ch)
{
    FlyText *flyText=new FlyText();
    if (flyText&&flyText->init(ch)) {
        flyText->autorelease();
        return flyText;
    }
    CC_SAFE_DELETE(flyText);
    return  nullptr;


}

bool FlyText::init(const char *ch)
{
    label=Label::createWithSystemFont(ch, "", 30);
    label->setColor(Color3B::RED);
    this->addChild(label);
       return true;


}

void FlyText::startAnimation()
{

    auto easeIn=EaseExponentialIn::create(Spawn::create(MoveBy::create(.7f, Point(0,150)),FadeOut::create(0.7f), NULL));

    auto sequence=Sequence::create(easeIn,
                                   CallFunc::create([&](){this->removeObject();}) ,NULL);

    label->runAction(sequence);
}

void FlyText::removeObject()
{
    stopAllActions();
    removeAllChildrenWithCleanup(true);
    this->removeAllChildren();

}