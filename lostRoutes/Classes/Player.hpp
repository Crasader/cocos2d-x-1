//
//  Player.hpp
//  lostRoutes
//
//  Created by zwj on 16/5/7.
//
//

#ifndef Player_hpp
#define Player_hpp

#include <stdio.h>
#include "SystemHeader.hpp"



class Player:public Sprite
{

    CC_SYNTHESIZE(int, hitPoints, HitPoints);
    CC_SYNTHESIZE(Point, veclocity, Veclocity);
public:
    
    void setPosition(const Point &newPosition);
    static Player *createWithSpriteFrameName(const char* spriteFrameName);


};




#endif /* Player_hpp */
