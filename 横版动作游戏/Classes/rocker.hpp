//
//  rocker.hpp
//  practice
//
//  Created by zwj on 16/5/21.
//
//

#ifndef rocker_hpp
#define rocker_hpp

#include <stdio.h>
#include <cocos2d.h>
USING_NS_CC;

typedef enum
{
    tag_rocker,
    tag_rockerBG
    
}tagForHRocker;

typedef enum
{

    rocker_stay=0,
    rocker_right,
    rocker_up,
    rocker_left,
    rocker_down,

}tagDirction;

class rocker :public Layer
{

public:
    static rocker *createRocker(const char * rockerImage,const char * rockerBgImage, Point positon);
    void startRocker(bool _isStopother);
    void stopRocker();
    
    int rockDirection;
    bool rockerRun;
    CREATE_FUNC(rocker);
private:
    void rockerInit(const char *image, const char *bgImage, Point position);
    bool isCanMove;
    float getRad(Point position1, Point pos2);
    Point rockerBGPostion;
    float rockerBGR;
    bool onTouchBegan(Touch *touch,Event *event);
    void onTouchMoved(Touch *touch,Event *event);
    void onTouchEnded(Touch *touch,Event *event);
    Point getAnglePosition(float r,float angle);
};

#endif /* rocker_hpp */
