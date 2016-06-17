//
//  ConstellationSprite.hpp
//  MyCppGame
//
//  Created by zwj on 16/6/17.
//
//

#ifndef ConstellationSprite_hpp
#define ConstellationSprite_hpp

#include <stdio.h>
#include "cocos2d.h"

USING_NS_CC;
class constellationSprite:public Sprite
{
public:
    
    constellationSprite(int num);
    
    static constellationSprite* createConstellationSprite(int num);

    int constellationNum;


};

#endif /* ConstellationSprite_hpp */
