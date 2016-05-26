//
//  baseFSM.cpp
//  practice
//
//  Created by zwj on 16/5/23.
//
//

#include "baseFSM.hpp"

baseFSM* baseFSM::createFSM(baseRole *baserole)
{
    baseFSM *basefsm=new baseFSM();
    if (basefsm&&basefsm->init(baserole)) {
        basefsm->autorelease();
        return basefsm;
    }
    CC_SAFE_DELETE(basefsm);
    return  nullptr;


}
bool baseFSM::init(baseRole *baserole)
{

    role=baserole;
    
    return true;
}

void baseFSM::switchMoveStat(int dir)
{
    if (role->state==ROLE_ATTACK) {
        return;
    }
    switch (dir) {
        case 0:
            this->changeToDefault();
            break;
        case 1:
            this->changeToRight();
            break;
        case 3:
            this->changeToLeft();
        default:
            role->getarmature()->stopAllActions();
            break;
    }

}

void baseFSM::changeToDefault()
{
    if (role->state!=ROLE_DEFAULT &&role->state!=ROLE_DEAD) {
        role->state=ROLE_DEFAULT;
        role->getarmature()->getAnimation()->play("default");
    }

}
void baseFSM::changeToAttack()
{
    if (role->state!=ROLE_ATTACK &&role->state!=ROLE_DEAD) {
        role->state=ROLE_ATTACK;
        role->getarmature()->getAnimation()->play("attack",-1,0);
   
    }

}
void baseFSM::changeToDead(){
    if (role->state!=ROLE_DEAD) {
        role->state=ROLE_DEAD;
        role->getarmature()->getAnimation()->play("gethit", -1,0);
    }


}
void baseFSM::changeToEnemy()
{
}

void baseFSM::changeToRight()
{
    if (role->state!=ROLE_MOVE &&role->state!=ROLE_DEAD) {
        role->state=ROLE_MOVE;
    }
//    if (role->face==FACE_RIGHT) {
        std::string  movent=role->getarmature()->getAnimation()->getCurrentMovementID();
        char *nowMovent=const_cast<char *>(movent.c_str());
        if (strcmp(nowMovent, "run_front") !=0) {
            role->getarmature()->getAnimation()->play("run_front");
        }
//}
//    }else
//    {
//        std::string  movent=role->getarmature()->getAnimation()->getCurrentMovementID();
//        char *nowMovent=const_cast<char *>(movent.c_str());
//        if (strcmp(nowMovent, "run_back")==0) {
//            role->getarmature()->getAnimation()->play("run_back");
//
//    }
//    
//    }
    role->setPosition(role->getPositionX()+role->property->getSPEED(),role->getPositionY());
}

void baseFSM::changeToLeft()
{
    if (role->state!=ROLE_MOVE &&role->state!=ROLE_DEAD) {
        role->state=ROLE_MOVE;
    }
    if (role->face==FACE_RIGHT) {
        std::string  movent=role->getarmature()->getAnimation()->getCurrentMovementID();
        char *nowMovent=const_cast<char *>(movent.c_str());
        if (strcmp(nowMovent, "run_back")!=0) {
            role->getarmature()->getAnimation()->play("run_back");
        }
    }else
    {
        std::string  movent=role->getarmature()->getAnimation()->getCurrentMovementID();
        char *nowMovent=const_cast<char *>(movent.c_str());
        if (strcmp(nowMovent, "run_front")!=0) {
            role->getarmature()->getAnimation()->play("run_front");
            
        }
        
    }
    role->setPosition(role->getPositionX()-role->property->getSPEED(),role->getPositionY());
}

void baseFSM::shifang()
{

    role=nullptr;
    CC_SAFE_RELEASE(this);
}