//
//  Enemy.hpp
//  lostRoutes
//
//  Created by zwj on 16/5/7.
//
//

#ifndef Enemy_hpp
#define Enemy_hpp
#include "SystemHeader.hpp"
#include <stdio.h>


//定义图片的宏名称
#define Enemy_Stone "gameplay.stone1.png"
#define Enemy_1 "gameplay.enemy-1.png"
#define Enemy_2 "gameplay.enemy-2.png"
#define Enemy_Planet "gameplay.enemy.planet.png"


//定义敌人的类型
typedef enum {

EnemyTypeStone=0,
    EnemyTypeEnemy1,
    EnemyTypeEnemy2,
    EnemyTypePlanet


}EnemyTypes;


class Enemy:public Sprite
{

    //cc_synthesize(类型，变量名，方法名)为protected类数据的set和get方法的宏。  prviate 只能被本类访问； protected可被本类、子类访问。
    CC_SYNTHESIZE(EnemyTypes, enemyType, EnemyType);
    CC_SYNTHESIZE(int, initalHitPoints, InitalHitPoints);
    CC_SYNTHESIZE(int, hitPoints, HitPoints);
    CC_SYNTHESIZE(Point, velocity, Velocity);
public:
    
    //构造函数
    Enemy(EnemyTypes enemyType);
    
    //
    void spawn();
    
    //update函数
    virtual void update(float dt);
    
    
    
    static Enemy* createWithEnemyTypes(EnemyTypes enemyType);

};



#endif /* Enemy_hpp */
