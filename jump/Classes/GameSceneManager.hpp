//
//  GameSceneManager.hpp
//  jump
//
//  Created by zwj on 16/6/6.
//
//

#ifndef GameSceneManager_hpp
#define GameSceneManager_hpp

#include <stdio.h>
#include <cocos2d.h>
USING_NS_CC;

class GameSceneManager
{

public:
   static void createScene();
    void goFlayLayer();
    void goMenuLayer();
    void goLevelLayer();
    void goGameLayer(int index);
    void goMusicLayer();
    void goChoiceCubeLayer();




};

#endif /* GameSceneManager_hpp */
