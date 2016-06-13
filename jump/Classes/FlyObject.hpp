//
//  FlyObject.hpp
//  jump
//
//  Created by zwj on 16/6/11.
//
//

#ifndef FlyObject_hpp
#define FlyObject_hpp

#include <stdio.h>
#include <cocos2d.h>
#include "Constant.h"
#include "ParticlSystemHelp.hpp"

USING_NS_CC;

class FlyObject
{
public:
    Sprite* sp1;
    Sprite* sp2;
    Sprite* sp;
    
    std::string* st;
    Point P;
    float r;
    float vJump = 450.0f;//上下移动的速度
    float vRotationJump = 320.0f;//旋转时的速度
    
    ParticleSystemHelp* psh;
    
    Layer* layer;
    
    float maxY;
    float minY;
    float maxX;
    float minX;
    float lengthX;
    float lengthY;
    
    float heightUp;
    float heightDown;
    
    FlyObject(std::string* stTemp, Layer* layer,
              Rect recta, float spLocationX, float spLocationY, float spLengthX, float spLengthY,
              Rect recta1, float sp1LocationX, float sp1LocationY, float sp1LengthX, float sp1LengthY,
              int localZOrder);
    ~FlyObject();
    
    void updata();
    void up();
    void down();
    void updataData();
    void explode();
    
    
    
};
#endif /* FlyObject_hpp */
