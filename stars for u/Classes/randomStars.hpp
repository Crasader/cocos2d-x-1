//
//  randomStars.hpp
//  MyCppGame
//
//  Created by zwj on 16/6/14.
//
//

#ifndef randomStars_hpp
#define randomStars_hpp

#include <stdio.h>
#include "cocos2d.h"
#include  <math.h>

USING_NS_CC;

class randomStars
{
public:
    randomStars(Layer* layerIn,int , int);
    void randomPosition();
    //星星向量
    std::vector<Sprite*> starsVector;
    
    Layer* layer;
    
    //星星数量
    int starNum;
    int shineStarNum;



};

#endif /* randomStars_hpp */
