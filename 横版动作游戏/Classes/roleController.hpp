//
//  roleController.hpp
//  practice
//
//  Created by zwj on 16/5/23.
//
//

#ifndef roleController_hpp
#define roleController_hpp

#include <stdio.h>
#include <cocos2d.h>
#include "baseRole.hpp"
#include <iostream>
USING_NS_CC;

class roleController:public Ref
{

public:
    static roleController * getInstance();
    bool init();
    
public:
    std::vector<baseRole *>heroVec;
    std::vector<baseRole *>monsterVec;
    
    
};

#endif /* roleController_hpp */
