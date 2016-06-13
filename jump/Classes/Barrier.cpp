//
//  Barrier.cpp
//  jump
//
//  Created by zwj on 16/6/6.
//
//

#include "Barrier.hpp"

Barrier::Barrier(std::string* stTemp, Layer* layer, Rect recta, float spLocationX, float spLocationY, float spLengthX, float spLengthY, int localZOrder)
{

    this->st=stTemp;
    this->lengthX=spLengthX;
    this->lengthY=spLengthY;
    this->timeOunt=0;

}
Barrier::~Barrier()
{
    delete st;
}

bool Barrier::collision(JumpCube *jc){}
bool Barrier::collisionFo(FlyObject *fo){}
void Barrier::reflesh()
{
    timeOunt++;
    sp->setPosition(Point(P.x-V*timeOunt*INTERVAL,P.y));

}