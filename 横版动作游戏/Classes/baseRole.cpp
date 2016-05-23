//
//  baseRole.cpp
//  practice
//
//  Created by zwj on 16/5/21.
//
//

#include "baseRole.hpp"

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
    
    
    
    
   

    return  true;
}