//
//  BaseAi.hpp
//  practice
//
//  Created by zwj on 16/5/24.
//
//

#ifndef BaseAi_hpp
#define BaseAi_hpp

#include <stdio.h>
#include <cocos2d.h>
#include "baseRole.hpp"
USING_NS_CC;

class BaseAi:public Ref
{

public:
    static BaseAi *createAI(baseRole *role);
    bool init(baseRole *role);
    void startRoleAi();
    void stopRoleAi();
    void updateFunc(float dt);
    void purge();
    
    baseRole *baserole;

};
#endif /* BaseAi_hpp */
