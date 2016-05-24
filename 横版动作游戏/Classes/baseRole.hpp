//
//  baseRole.hpp
//  practice
//
//  Created by zwj on 16/5/21.
//
//

#ifndef baseRole_hpp
#define baseRole_hpp

#include <stdio.h>
#include <cocos2d.h>
#include "propertyMananger.hpp"
#include "cocostudio/CocoStudio.h"

class baseFSM;
class BaseAi;

USING_NS_CC;
using namespace cocostudio;

typedef enum{
    TYPE_HERO=1,
    TYPE_MONSTER=2
} ROLE_TYPE;


typedef enum{

    ROLE_DEFAULT=1,
    ROLE_ATTACK,
    ROLE_MOVE,
    ROLE_DEAD,

}ROLE_STATE;

typedef enum {

    FACE_LEFT,
    FACE_RIGHT,

}ROLE_FACE;

class baseRole:public Node
{
public:
    static baseRole *creatWithProperty(propertyManager *manager);
    bool init(propertyManager *manager);
    ROLE_STATE state;
    ROLE_FACE face;
    propertyManager *property;
    void changeFace(ROLE_FACE face);
    ROLE_TYPE type;
    CC_SYNTHESIZE(Armature*, armature, armature);
    CC_SYNTHESIZE(baseFSM*, basefsm, baseFsm);
     CC_SYNTHESIZE(BaseAi*, baseAi, Baseai);
    void animationEvent(Armature *pArmature,MovementEventType movementevent, const std::string & moventIDstr);
       virtual void draw(Renderer *renderer, const kmMat4 &transform, bool transformUpdated) override;
    void onDraw(const kmMat4 &transform, bool transformUpdated);
    CustomCommand _customCommand;
};

#endif /* baseRole_hpp */
