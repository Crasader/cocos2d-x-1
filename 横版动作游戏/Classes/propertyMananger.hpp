//
//  propertyMananger.hpp
//  practice
//
//  Created by zwj on 16/5/21.
//
//

#ifndef propertyMananger_hpp
#define propertyMananger_hpp

#include <stdio.h>
#include <cocos2d.h>
USING_NS_CC;

class propertyManager:public Ref
{

public:
    CREATE_FUNC(propertyManager);
    virtual bool init();
    CC_SYNTHESIZE(int, id, ID);
    CC_SYNTHESIZE(int, hp, HP);
    CC_SYNTHESIZE(int, atk, ATK);
    CC_SYNTHESIZE(int, speed, SPEED);
    CC_SYNTHESIZE(unsigned int, locklimit, LOCKLIMIT);
    CC_SYNTHESIZE(unsigned int, atkLimit, ATKLIMIT);
    CC_SYNTHESIZE(std::string, armtureName, ArmtureName);
    CC_SYNTHESIZE(std::string, dataName, DataName);
    CC_SYNTHESIZE(std::string, playerName, PlayerName);
    CC_SYNTHESIZE(Rect, hitRect, HitRect);
    CC_SYNTHESIZE(Point, hitpoint, HitPoint);
    CC_SYNTHESIZE(Rect, getRect, GetRect);
    CC_SYNTHESIZE(Point, getpoint, GetPoint);
};
#endif /* propertyMananger_hpp */
