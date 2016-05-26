//
//  roleController.cpp
//  practice
//
//  Created by zwj on 16/5/23.
//
//

#include "roleController.hpp"
static roleController *rolecontroller=nullptr;

roleController *roleController::getInstance()
{

    if (rolecontroller==nullptr) {
        rolecontroller=new(std::nothrow) roleController();
        rolecontroller->init();
    }

    return  rolecontroller;

}

bool roleController::init()
{





    return  true;
}

baseRole *roleController::getHero()
{
    for (int i=0; i<heroVec.size(); i++) {
        if (heroVec[i]->property->getID() == this->getheroid()) {
            return  heroVec[i];
        }
    }

    return  nullptr;
}
void roleController::purge()
{
    if (heroVec.size()!=0) {
        for (int i=0; i<heroVec.size(); i++) {
            heroVec[i]->shifang();
        }
    }
    if (monsterVec.size()!=0) {
        for (int i=0; i<monsterVec.size(); i++) {
            monsterVec[i]->shifang();
        }
    }

    heroVec.clear();
    heroVec.shrink_to_fit();
    monsterVec.clear();
    monsterVec.shrink_to_fit();
}
