//
//  Game.hpp
//  lostRoutes
//
//  Created by zwj on 16/5/8.
//
//

#ifndef Game_hpp
#define Game_hpp

//用于removeChildByTag的各类Tag宏定义
#define GameSceneNodeTagStatusBarFighterNode 301
#define GameSceneNodeTagStatusBarLifeNode 302
#define GameSceneNodeTagStatusBarScore 303

#define GameSceneNodeBatchTagBackground				800
#define GameSceneNodeTagFighter						900
#define GameSceneNodeTagExplosionParticleSystem		901
#define GameSceneNodeBatchTagBullet					902
#define GameSceneNodeBatchTagEnemy					903

#include <stdio.h>
#include "SystemHeader.hpp"
#include "Enemy.hpp"
#include "Player.hpp"
#include "Bullet.hpp"


//定义不同类型的敌人的分值
typedef enum
{
 EnemyStone_Score=5,
    Enemey1_Socre=10,
    Enemey2_Score=15,
    EnemeyPlanet_Score=20


} EnemyScores;

class Game:public Layer
{
private:
    Player *player;
    int score;
    int scorePlaceholder;
    
    //用于退出时，清理事件监听器，否则再次进入会出现bug。
    EventListenerTouchOneByOne *touchPlayerlistener;
    EventListenerPhysicsContact *contactListener;
    
public:
    static Scene *createScene();
    virtual bool init();
    virtual void onExit();
    virtual void onEnter();
    virtual void onEnterTransitionDidFinish();
    void initBG();
    void menuPauseCallback(Ref *pSender);
    void handleFighterCollidingWithEnemy(Enemy * enmey);
    void handleBulletCollidingWithEnemy(Enemy *enemy);
    void shootBullet(float dt);
    void updateStatusBarPlayer();
    void updateStatusBarScore();
    void menuResume(Ref* pSender );
    void menuBack(Ref *pSender);
    
    CREATE_FUNC(Game);

};



#endif /* Game_hpp */
