//
//  JumpCube.hpp
//  jump
//
//  Created by zwj on 16/6/11.
//
//

#ifndef JumpCube_hpp
#define JumpCube_hpp

#include <stdio.h>
#include "Constant.h"
#include "ParticlSystemHelp.hpp"
USING_NS_CC;

class JumpCube
{
public:
    Sprite* sp;
    std::string* st;
    
    Point p;
    float r;
    float lengthX;
    float lengthY;
    
    float vJump=JCJH/timeJump;
    float vRotationJump=90;
    bool isJump=false;
    
    float vDown=vJump;
    bool isDown=false;
    
    int timeCount=0;
    
    ParticleSystemHelp* psh;
    Layer* layer;
    JumpCube(std::string* stTemp, Layer* layer, Rect recta, float spLocationX, float spLocationY, float spLength, int localZOrder);
    ~JumpCube();
    void reflesh(float maxH);
    void Jump();
    void Down();
    void refleshAngleAndPosition(float y);
    void explode();


};

#endif /* JumpCube_hpp */
