//
//  Bullet.hpp
//  lostRoutes
//
//  Created by zwj on 16/5/7.
//
//

#ifndef Bullet_hpp
#define Bullet_hpp

#include <stdio.h>
#include "SystemHeader.hpp"
#include "Player.hpp"


class Bullet:public Sprite
{
    CC_SYNTHESIZE(Point, veclocity, Veclocity);
    
public:
    
    
    static Bullet *createWithSpriteFrameName(const char * spriteFrameName);

    void shootFromPlayer(Player *player);
    virtual void update(float dt);
    


};

#endif /* Bullet_hpp */
