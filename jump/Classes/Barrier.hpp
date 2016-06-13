//
//  Barrier.hpp
//  jump
//
//  Created by zwj on 16/6/6.
//
//

#ifndef Barrier_hpp
#define Barrier_hpp

#include <stdio.h>
#include <cocos2d.h>
#include "JumpCube.hpp"
#include "FlyObject.hpp"

USING_NS_CC;

class Barrier
{

public:
    Sprite* sp;
    std::string* st;
    float lengthX;
    float lengthY;
    char idChar;
    int timeOunt;
    Point P;
	Barrier(std::string* stTemp, Layer* layer, Rect recta, float spLocationX, float spLocationY, float spLengthX, float spLengthY, int localZOrder);
    ~Barrier();
    
    virtual bool collision(JumpCube* jc);
    virtual bool collisionFo(FlyObject* fo);//
    void reflesh();


};

class TriangleBarrier:public Barrier
{
public:
    TriangleBarrier(std::string* stTemp, Layer* layer, Rect recta, float spLocationX, float spLocationY, float spLengthX, float spLengthY, int localZOrder);
    bool collision(JumpCube* jc);
    bool  collsionFo(FlyObject* fo);
    

};

class RectBarrier:public Barrier
{
public:
RectBarrier(std::string* stTemp, Layer* layer, Rect recta, float spLocationX, float spLocationY, float spLengthX, float spLengthY, int localZOrder);
    bool collision(JumpCube* jc);
    bool collisionFo(FlyObject* fo);


};

#endif /* Barrier_hpp */
