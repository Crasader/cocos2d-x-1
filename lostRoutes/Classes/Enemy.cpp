//
//  Enemy.cpp
//  lostRoutes
//
//  Created by zwj on 16/5/7.
//
//

#include "Enemy.hpp"

//构造函数
Enemy::Enemy(EnemyTypes enemyType)
{
    this->enemyType=enemyType;
    this->initalHitPoints=1;
    this->velocity=Point::ZERO;
}


//创建敌人
Enemy * Enemy::createWithEnemyTypes(EnemyTypes enemyType)
{
    //实例化（会调用构造函数）
    Enemy *enemy=new Enemy(enemyType);
    
    //初始化敌人图像frame
    const char *enemyFrameName=Enemy_Stone;
    
    
    //根据传入的enemyType，实现不同的敌人图像及其属性
    switch (enemyType) {
        case EnemyTypeStone:
            enemyFrameName=Enemy_Stone;  //Enemy_Stone 宏定义的图像 ："gameplay.stone1.png"
            enemy->initalHitPoints=3;
            break;
        case EnemyTypeEnemy1:
            enemyFrameName=Enemy_1;
            enemy->initalHitPoints=10;
            break;
        case EnemyTypeEnemy2:
            enemyFrameName=Enemy_2;
            enemy->initalHitPoints=5;
            break;
            case EnemyTypePlanet:
            enemyFrameName=Enemy_Planet;
            enemy->initalHitPoints=15;
            break;
    }

    //将创建的enemy初始化为enemyFrameName对应的图像，相当于create（）。
    if (enemy&&enemy->initWithSpriteFrameName(enemyFrameName))
    {
        enemy->autorelease();
        
        
        //准备碰撞监测的body
        auto body=PhysicsBody::create();
        
        //后面的if 语句可使用switch来重构

        //对stone和planet类型的敌人，使用circle创建body
        if (enemyType==EnemyTypeStone || enemyType==EnemyTypePlanet) {
            body->addShape(PhysicsShapeCircle::create(enemy->getContentSize().width/2-5));
        }
        else
            
            //对敌人1类型，对其边界的6个点进行创建body
            if(enemyType==EnemyTypeEnemy1)
            {Point verts[]={
                Point(-2.5,-45.75),
                Point(-29.5,-27.25),
                Point(-53, -0.25),
                Point(-34,43.25),
                Point(28, 44.25),
                Point(55,-2.25)};
                body->addShape(PhysicsShapePolygon::create(verts, 6));
        }else
            if (enemyType==EnemyTypeEnemy2) {
                Point verts[] ={
                    Point(1.25, 32.25),
                    Point(36.75, -4.75),
                    Point( 2.75, -31.75),
                    Point(-35.75,-3.25)};
                body->addShape(PhysicsShapePolygon::create(verts, 4));
            }
        
        //A的categoryBit与B的collisionBit 进行与运算，决定是否可以发生碰撞事件。
        body->setCategoryBitmask(0x01);
        body->setCollisionBitmask(0x02);//敌人自己不能发生碰撞事件
        
        //A的contactBit 与B的contactBit进行与，决定是否可以发送接触事件
        body->setContactTestBitmask(0x01);
        //body->setVelocity(Point(0,-100));
        
        enemy->setPhysicsBody(body);
        enemy->setVisible(false);
        enemy->spawn();
        
        enemy->unscheduleUpdate();
        enemy->scheduleUpdate();
    
        return  enemy;//返回
        
}
    //若空，则返回空
    CC_SAFE_DELETE(enemy);
    return nullptr;
    }


//upate函数
void Enemy::update(float dt)
{
    
    switch (this->getEnemyType()) {
        case EnemyTypeStone:
            this->setRotation(this->getRotation()-5);
            break;
        case EnemyTypePlanet:
            this->setRotation(this->getRotation()+5);
            break;
    }
    
    //移动的距离＝速度乘以事件
    Point moveLen=velocity *dt;


    this->setPosition(this->getPosition()+moveLen);  //this指的是上面谁调用的scheduleUpdate（）
    
   // 如果跑到屏幕下面不可见
    if (this->getPosition().y+this->getContentSize().height/2<0) {
        this->spawn();
    }
    
}

//重置敌人位置
void Enemy::spawn(){
    auto screenSize=Director::getInstance()->getVisibleSize();
    float yPos=screenSize.height+this->getContentSize().height/2;
    
    //随机设置x轴
    float xPos=CCRANDOM_0_1()*(screenSize.width-this->getContentSize().width)+this->getContentSize().width/2;
    this->setPosition(Point(xPos,yPos));
    this->setAnchorPoint(Point(0.5,0.5));
    
    
    hitPoints=initalHitPoints;
    this->setVisible(true);
    
    


}