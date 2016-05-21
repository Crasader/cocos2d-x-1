//
//  SceneManager.hpp
//  practice
//
//  Created by zwj on 16/5/19.
//
//

#ifndef SceneManager_hpp
#define SceneManager_hpp

#include <stdio.h>
#include <cocos2d.h>

USING_NS_CC;

class SceneManager
{
public:
    Scene *loadScene;
    Scene *openScene;
    Scene *clockScene;

    void createLoadScene();
    void goOpenScene();
    void goClockScecne();
};

#endif /* SceneManager_hpp */
