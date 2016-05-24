//
//  BaseAi.cpp
//  practice
//
//  Created by zwj on 16/5/24.
//
//

#include "BaseAi.hpp"
#include "roleController.hpp"
#include "baseFSM.hpp"

BaseAi * BaseAi::createAI(baseRole *role)
{
    BaseAi *ai=new BaseAi();
    if (ai&&ai->init(role)) {
        ai->autorelease();
        return ai;
    }
    CC_SAFE_DELETE(ai);
    return nullptr;

}

bool BaseAi::init(baseRole *role)
{

    baserole=role;

    return true;
}

void BaseAi::startRoleAi()
{

    Director::getInstance()->getScheduler()->schedule(schedule_selector(BaseAi::updateFunc), this, (float)1/60, false );



}
void BaseAi::stopRoleAi()
{}

void BaseAi::updateFunc(float dt)
{
    std::vector<baseRole*>roleVec;
    if (baserole->type==TYPE_HERO) {
        roleVec=roleController::getInstance()->monsterVec;
    }
    else if(baserole->type==TYPE_MONSTER)
    {
        roleVec=roleController::getInstance()->heroVec;
    }
    int roleID=0;
    if (roleVec.size()!=0) {
        float distance=Director::getInstance()->getWinSize().width;
        for (int i=0; i<roleVec.size(); i++) {
            float newDis=abs(baserole->getPosition().getDistance(roleVec[i]->getPosition()));
            if (newDis<distance) {
                roleID=i;
                distance=newDis;
            }
            
    
        }
        
        if (roleVec[roleID]->getPosition().x>baserole->getPosition().x) {
            baserole->changeFace(FACE_RIGHT);
        }
        else{
        
            baserole->changeFace(FACE_LEFT);
        
        }
        
    }
    
    else
    {
        return;
    }
    if (baserole->type ==TYPE_MONSTER)
    {
        Point enemyPos=roleVec[roleID]->getPosition();
        if (baserole->getPosition().getDistance(enemyPos)<baserole->property->getLOCKLIMIT())
        {
            if (baserole->getPosition().getDistance(enemyPos)<baserole->property->getATKLIMIT())
            {
                baserole->getbaseFsm()->changeToAttack();
            }
            else{
                if (baserole->face==FACE_LEFT &&baserole->state!=ROLE_ATTACK) {
                    baserole->getbaseFsm()->changeToLeft();
                }  else if(baserole->face==FACE_RIGHT &&baserole->state!=ROLE_ATTACK)
                {
                    baserole->getbaseFsm()->changeToRight();
                }
            }
            
            }
        }
    }
    
