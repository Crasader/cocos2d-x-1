//
//  baseFSM.hpp
//  practice
//
//  Created by zwj on 16/5/23.
//
//

#ifndef baseFSM_hpp
#define baseFSM_hpp

#include <stdio.h>
#include <cocos2d.h>
#include "baseRole.hpp"

USING_NS_CC;

class baseFSM:public Ref
{
public:
    static baseFSM *createFSM(baseRole *baserole);
    bool init(baseRole *baserole);

    void switchMoveStat(int dir);
    void changeToDefault();
    void changeToAttack();
    void changeToRight();
    void changeToLeft();
    void changeToDead();
    void changeToEnemy();
    void shifang();
    baseRole *role;
};

#endif /* baseFSM_hpp */
