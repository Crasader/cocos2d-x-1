//
//  baseRole.cpp
//  practice
//
//  Created by zwj on 16/5/21.
//
//

#include "baseRole.hpp"
#include "baseFSM.hpp"
#include "BaseAi.hpp"

baseRole* baseRole::creatWithProperty(propertyManager *manager)
{

    baseRole *role=new baseRole();
    if (role &&role->init(manager)) {
        role->autorelease();
        return role;
    }
    CC_SAFE_DELETE(role);
    return  nullptr;

}

bool baseRole::init(propertyManager *manager)
{
    
    
   
    
      property=manager;
   
    
    //获取动画
    ArmatureDataManager::getInstance()->addArmatureFileInfo( property->getDataName());
    armature=Armature::create( property->getArmtureName());
    armature->getAnimation()->play("default");
    this->addChild(armature);
    
  //   armature->getAnimation()->setMovementEventCallFunc(CC_CALLBACK_0(baseRole::animationEvent, this,std::placeholders::_1,std::placeholders::_2,std::placeholders::_3));
    
    armature->getAnimation()->setMovementEventCallFunc(this, movementEvent_selector(baseRole::animationEvent));

    return  true;
}
Rect baseRole::getRealRect(baseRole *role, cocos2d::Rect rect)
{

    Rect realRect=Rect(rect.origin.x+role->getPosition().x, rect.origin.y+role->getPosition().y, rect.size.width, rect.size.height);
    return realRect;


}

void baseRole::animationEvent(Armature *pArmature, MovementEventType movementevent, const std::string &moventIDstr)
{

    const char *movID=moventIDstr.c_str();
    if (strcmp(movID, "attack")==0) {
        if (movementevent==START) {
            
            if (locatedRole!=nullptr&& state!=ROLE_DEAD) {
                if (getRealRect(this, property->getHitRect()).intersectsRect(locatedRole->getRealRect(locatedRole, property->getGetRect()))) {
                    int atk=property->getATK();
                    __String *hp=__String::createWithFormat("%d",atk);
                    locatedRole->fallHp(hp->getCString());
                    locatedRole->property->setHP(locatedRole->property->getHP()-atk);
                    if (locatedRole->property->getHP()<=0) {
                        locatedRole->getBaseai()->stopRoleAi();
                        locatedRole->getbaseFsm()->changeToDead();
                    }
                }
            }
            
        }
        if (movementevent==COMPLETE) {
        this->getbaseFsm()->changeToDefault();
        }
    }


    if (strcmp(movID, "gethit")==0) {
        if (movementevent==COMPLETE) {
            armature->runAction(Sequence::create(FadeOut::create(0.5f), CallFunc::create([=](){state=ROLE_FREE;}),NULL));
        }
    }

}

//攻击框和受击框
void baseRole::draw(cocos2d::Renderer *renderer, const kmMat4 &transform, bool transformUpdated)
{

    _customCommand.init(_globalZOrder);
    _customCommand.func = CC_CALLBACK_0(baseRole::onDraw, this, transform, transformUpdated);
    renderer->addCommand(&_customCommand);

}

void baseRole::onDraw(const kmMat4 &transform, bool transformUpdated)
{
    kmGLPushMatrix();
    kmGLLoadMatrix(&transform);
    
    Rect rect=property->getHitRect();
    DrawPrimitives::setDrawColor4B(0, 0, 255, 255);
    DrawPrimitives::drawRect(Point(rect.getMinX(),rect.getMinY()), Point(rect.getMaxX(),rect.getMaxY()));

    rect=property->getGetRect();
    DrawPrimitives::setDrawColor4B(0, 255, 0, 255);
    DrawPrimitives::drawRect(Point(rect.getMinX(),rect.getMinY()), Point(rect.getMaxX(),rect.getMaxY()));
    
    kmGLPopMatrix();
}

void baseRole::fallHp(const char *hpCount)
{
    FlyText *flyText=FlyText::create(hpCount);
    flyText->startAnimation();
    this->addChild(flyText);


}
void baseRole::changeFace(ROLE_FACE face)
{

    if (face==FACE_LEFT) {
        armature->setScaleX(-1);
        property->setHitRect(Rect(-property->getHitPoint().x-property->getHitRect().size.width,property->getHitRect().origin.y,property->getHitRect().size.width,property->getHitRect().size.height));
    
        this->face=face;
    }
    if (face==FACE_RIGHT) {
        armature->setScaleX(1);
        property->setHitRect(Rect(property->getHitPoint().x, property->getHitRect().origin.y, property->getHitRect().size.width, property->getHitRect().size.height));
        this->face=face;
    }


}
void baseRole::shifang()
{
    this->getbaseFsm()->shifang();
    this->getBaseai()->purge();
    removeFromParent();

}