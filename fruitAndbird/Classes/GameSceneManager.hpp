//
//  GameSceneManager.hpp
//  fruitAndbird
//
//  Created by zwj on 16/5/27.
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
    Scene* mainScene;
    Scene* gameScene;
    Scene* birdScene;
    Scene* fruitScene;
    Scene* musicScene;
    Scene* rankScene;
    Scene* aboutScene;
    Scene* helpScene;

public:
    
    void createMainScene();
    void goToFlappyScene(int);
    void goToSquishyScene(int);
    void goToGameScene();
    void goToSetScene();
    void goToRankBirdScene();
    void goToRankFruitScene();
    void goToAboutScene();
    void goToHelpScene();
    void goToMainScene();


};

#endif /* GameSceneManager_hpp */
