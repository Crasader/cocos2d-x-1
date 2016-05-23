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