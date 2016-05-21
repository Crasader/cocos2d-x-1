//
//  SceneManger.hpp
//  practice
//
//  Created by zwj on 16/5/20.
//
//

#ifndef SceneManger_hpp
#define SceneManger_hpp

#include <stdio.h>
#include <cocos2d.h>
USING_NS_CC;

class SceneManager
{

public:
    Scene *startScene;
    Scene *gameScene;
    void createScene();
    void toGameScene();


};

#endif /* SceneManger_hpp */
