//
//  baseRole.hpp
//  practice
//
//  Created by zwj on 16/5/21.
//
//

#ifndef baseRole_hpp
#define baseRole_hpp

#include <stdio.h>
#include <cocos2d.h>
#include "propertyMananger.hpp"
#include "cocostudio/CocoStudio.h"

USING_NS_CC;
using namespace cocostudio;

typedef enum{
    TYPE_HERO=1,
    TYPE_MONSTER=2
} ROLE_TYPE;

class baseRole:public Node
{
public:
    static baseRole *creatWithProperty(propertyManager *manager);
    bool init(propertyManager *manager);
    
    propertyManager *property;
    
    ROLE_TYPE type;
    CC_SYNTHESIZE(Armature*, armature, armature);
    
};

#endif /* baseRole_hpp */
