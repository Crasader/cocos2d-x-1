//
//  Game.cpp
//  lostRoutes
//
//  Created by zwj on 16/5/8.
//
//

#include "Game.hpp"


//创建物理引擎场景
Scene *Game::createScene()
{
//!!!!!!!此场景有物理引擎
    auto scene=Scene::createWithPhysics();
    PhysicsWorld *phyWolrd=scene->getPhysicsWorld();
    phyWolrd->setGravity(Point(0,0));
    auto layer=Game::create();
    scene->addChild(layer);
    return scene;

}

bool Game::init()
{
    if (!Layer::init()) {
        return false;
    }
    
    this->initBG();
    
        return true;
}



//初始化在此函数进行
void Game::onEnter()
{
    Layer::onEnter();
    auto size=Director::getInstance()->getVisibleSize();
    
    //buttons
    auto pauseSprite=Sprite::createWithSpriteFrameName("gameplay.button.pause.png");
    auto pauseMenuItem=MenuItemSprite::create(pauseSprite, pauseSprite, CC_CALLBACK_1(Game::menuPauseCallback,this));
    auto pauseMenu=Menu::create(pauseMenuItem, NULL);
    pauseMenu->setPosition(Point(30,size.height-28));
    this->addChild(pauseMenu,20,999);
    
    //stones
    auto stone1=Enemy::createWithEnemyTypes(EnemyTypeStone);
    stone1->setVelocity(Point(0,-100));
    this->addChild(stone1,10,GameSceneNodeBatchTagEnemy);
    
    //planet
    auto planet=Enemy::createWithEnemyTypes(EnemyTypePlanet);
    planet->setVelocity(Point(0,-50));
    this->addChild(planet,10,GameSceneNodeBatchTagEnemy);
    
    //enemy1
    auto enemy1=Enemy::createWithEnemyTypes(EnemyTypeEnemy1);
    enemy1->setVelocity(Point(0,-80));
    this->addChild(enemy1,10,GameSceneNodeBatchTagEnemy);
    
    //enemy2
    auto enemy2=Enemy::createWithEnemyTypes(EnemyTypeEnemy2);
    enemy2->setVelocity(Point(0,-100));
    this->addChild(enemy2,10,GameSceneNodeBatchTagEnemy);
    
    //player
    player=Player::createWithSpriteFrameName("gameplay.fighter.png");
    player->setHitPoints(5);
    player->setPosition(Point(size.width/2,70));
    addChild(player,10,GameSceneNodeTagFighter);
    
    
    //触摸监听
    touchPlayerlistener=EventListenerTouchOneByOne::create();
    touchPlayerlistener->setSwallowTouches(true);
        touchPlayerlistener->onTouchBegan=[](Touch *touch, Event *event)
    {        return true;
    };
    
    touchPlayerlistener->onTouchMoved=[](Touch *touch,Event *event)
    {
        auto sprite=static_cast<Sprite*>( event->getCurrentTarget());
        auto position=touch->getLocation();
        sprite->setPosition(sprite->getPosition()+touch->getDelta());
    };
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchPlayerlistener, player);
    
    
    //玩家与敌人碰撞
    contactListener=EventListenerPhysicsContact::create();
    
    contactListener->onContactBegin=[this](PhysicsContact &contact)
    {
        auto spriteA=contact.getShapeA()->getBody()->getNode();
        auto spriteB=contact.getShapeB()->getBody()->getNode();
           Node *enemy0=nullptr;
        if (spriteA->getTag()==GameSceneNodeTagFighter &&spriteB->getTag()==GameSceneNodeBatchTagEnemy) {
            enemy0=spriteB;
        }
        if (spriteA->getTag()==GameSceneNodeBatchTagEnemy && spriteB->getTag()==GameSceneNodeTagFighter) {
            enemy0=spriteA;
        }
        if (enemy0!=nullptr) {
            this->handleFighterCollidingWithEnemy((Enemy*) enemy0);
            return false;
        }
        
        
        //炮弹与敌人
        Node *enmey00=nullptr;
        if (spriteA->getTag()==GameSceneNodeBatchTagBullet &&spriteB->getTag()==GameSceneNodeBatchTagEnemy) {
            if (!spriteA->isVisible()) {
                return false;
            }
            enmey00=spriteB;
            spriteA->setVisible(false);
        }
        if (spriteA->getTag() == GameSceneNodeBatchTagEnemy
            && spriteB->getTag() == GameSceneNodeBatchTagBullet)
        {
            //不可见的炮弹不发生碰撞
            if (!spriteB->isVisible())
                return false;
            //使得炮弹消失
            spriteB->setVisible(false);
            enmey00 = spriteA;
        }
        if (enmey00 != nullptr)
        {
            this->handleBulletCollidingWithEnemy((Enemy*)enmey00);
            return false;
        }
        
        return false;
};
    Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(contactListener, 1);
    
    this->schedule(schedule_selector(Game::shootBullet), 0.2);
    this->score=0;
    this->scorePlaceholder=0;
    
    this->updateStatusBarScore();
    this->updateStatusBarPlayer();
    
    
    
}

void Game::initBG()
{
    auto visibleSize=Director::getInstance()->getVisibleSize();
   
    //背景，级别0，tag为GameSceneNodeBatchTagBackground
    auto bg=TMXTiledMap::create("map/blue_bg.tmx");
    //bg->setPosition(visibleSize.width/2,visibleSize.height/2);
    this->addChild(bg, 0, GameSceneNodeBatchTagBackground);
    
    

    
    //
    
    auto sprite1=Sprite::createWithSpriteFrameName("gameplay.bg.sprite-1.png");
    sprite1->setPosition(-50,-50);
    addChild(sprite1,0,GameSceneNodeBatchTagBackground);
    
    FiniteTimeAction *ac1=(FiniteTimeAction *) MoveBy::create(20, Point(500,600));
    FiniteTimeAction *ac2=ac1->reverse();
    
    ActionInterval *as1=Sequence::create(ac1,ac2, NULL);
    sprite1->runAction(RepeatForever::create(EaseSineInOut::create(as1)));
    
    //
    auto sprite2=Sprite::createWithSpriteFrameName("gameplay.bg.sprite-2.png");
    sprite2->setPosition(visibleSize.width,0);
    addChild(sprite2,0,GameSceneNodeBatchTagBackground);
    
    FiniteTimeAction *ac3=(FiniteTimeAction*)MoveBy::create(10, Point(-500,600));
    FiniteTimeAction *ac4=(FiniteTimeAction* ) (ac3->reverse());
    ActionInterval *as2=Sequence::create(ac3,ac4, NULL);
    sprite2->runAction(RepeatForever::create(EaseExponentialInOut::create(as2)));
    
    }

void Game::menuPauseCallback(Ref *pSender)
{
    //pause
    this->pause();
    for (const auto &node: this->getChildren())
    {
        node->pause();
    }
    auto size=Director::getInstance()->getVisibleSize();
    
    auto backNormal=Sprite::createWithSpriteFrameName("gameplay.button.back.png");
    auto backSelected=Sprite::createWithSpriteFrameName("gameplay.button.back-on.png");
    auto backMenuItem=MenuItemSprite::create(backNormal, backSelected,CC_CALLBACK_1(Game::menuBack, this));
    
    
    auto resumeNormal=Sprite::createWithSpriteFrameName("gameplay.button.resume.png");
    auto resumeSelected=Sprite::createWithSpriteFrameName("gameplay.button.resume-on.png");
    auto resumeMenuItem=MenuItemSprite::create(resumeNormal, resumeSelected, CC_CALLBACK_1(Game::menuResume, this));
    
    
    
    auto mu=Menu::create(backMenuItem,resumeMenuItem, NULL);
    mu->alignItemsVertically();
    addChild(mu,20,100);
    
    
    
    
}
void Game::menuBack(cocos2d::Ref *pSender)
{

    Director::getInstance()->popScene();
    

}

void Game::menuResume(cocos2d::Ref *pSender)
{
   ;
    this->resume();
    for(const auto &node :this->getChildren())
    {
        node->resume();
    
    }

    this->removeChildByTag(100);

}


void Game::shootBullet(float dt)
{
    if (player &&player->isVisible()) {
        auto bullet=Bullet::createWithSpriteFrameName("gameplay.bullet.png");
        bullet->setVeclocity(Point(0,300));
        addChild(bullet,0,GameSceneNodeBatchTagBullet);
        bullet->shootFromPlayer(player);
}
  
}
void Game::updateStatusBarScore()
{
    
    auto size=Director::getInstance()->getVisibleSize();
    Node *n=this->getChildByTag(GameSceneNodeTagStatusBarScore);
    if (n) {
        this->removeChildByTag(GameSceneNodeTagStatusBarScore);
    }
    if (this->score<0) {
        this->score=0;
    }
    __String *score=__String::createWithFormat("%d",this->score);
    auto lblScore=Label::createWithTTF(score->getCString(), "hanyi.ttf", 40);
    lblScore->setPosition(size.width/2,(size.height-lblScore->getContentSize().height/2));
    this->addChild(lblScore,20,GameSceneNodeTagStatusBarScore);
    

}
void Game::handleBulletCollidingWithEnemy(Enemy *enemy)
{
    enemy->setHitPoints(enemy->getHitPoints()-1);
    
    if (enemy->getHitPoints()<=0) {
//        Node *node = this->getChildByTag(GameSceneNodeBatchTagEnemy);
//        
//        if (node) {
//            this->removeChildByTag(GameSceneNodeBatchTagEnemy);
//        }
        ParticleFire *explosion=ParticleFire::create();
        explosion->setDuration(1);
        explosion->setPosition(enemy->getPosition());
        this->addChild(explosion,0,GameSceneNodeTagExplosionParticleSystem);
    
        switch (enemy->getEnemyType()) {
            case EnemyTypeStone:
                score+=EnemeyPlanet_Score;
                scorePlaceholder+=EnemeyPlanet_Score;
                break;
             case EnemyTypeEnemy1:
                score+=Enemey1_Socre;
                scorePlaceholder+=Enemey1_Socre;
                break;
                case EnemyTypeEnemy2:
                score+=Enemey2_Score;
                scorePlaceholder+=Enemey2_Score;
                break;
            default:
                score+=Enemey2_Score;
                scorePlaceholder+=Enemey2_Score;
                break;
        }
        if (scorePlaceholder>=1000) {
            player->setHitPoints(player->getHitPoints()+1);
            this->updateStatusBarPlayer();
            scorePlaceholder-=1000;
        }
        this->updateStatusBarScore();
        enemy->setVisible(false);
        enemy->spawn();
        
    }
    
    
    
}
void Game::handleFighterCollidingWithEnemy(Enemy *enmey)
{
    auto size=Director::getInstance()->getVisibleSize();
    auto node =this->getChildByTag(GameSceneNodeTagExplosionParticleSystem);
    if (node) {
        this->removeChild(node);
    }
    ParticleSystem *explosion=ParticleFire::create();
     explosion->setDuration(1);
    explosion->setPosition(enmey->getPosition());
    
    this->addChild(explosion,2,GameSceneNodeTagExplosionParticleSystem);

    enmey->setVisible(false);
    enmey->spawn();
    
    player->setHitPoints(player->getHitPoints()-1);
    this->updateStatusBarPlayer();
    if (player->getHitPoints()<=0) {
        this->pause();
        auto nodes=this->getChildren();
        for (const auto &node:nodes) {
            node->pause();
            
        }
        
        auto bg=Sprite::createWithSpriteFrameName("gameover.top.png");
        bg->setPosition(size.width/2,size.height/2);
        this->addChild(bg);
        
        __String *score=__String::createWithFormat("%d",this->score);
        auto gamevoerLabel=Label::createWithTTF(score->getCString(), "hanyi.ttf", 200);
        gamevoerLabel->setPosition(bg->getPosition());
        bg->addChild(gamevoerLabel);
        
        
        auto okButton=MenuItemFont::create("OK", CC_CALLBACK_1(Game::menuBack, this));
        okButton->setScale(10);
        auto menu=Menu::create(okButton, NULL);
        menu->setPosition(bg->getPosition()-Point(0,300));
        
        this->addChild(menu);
        
        
    
    }
    else{
        player->setPosition(Point(size.width/2,70));
        auto ac1=Show::create();
        auto ac2=FadeIn::create(1);
        auto sac=Sequence::create(ac1,ac2, NULL);
        
        player->runAction(sac);
    
    }
    
    
}
void Game::onExit()
{

    Layer::onExit();
    this->unschedule(schedule_selector(Game::shootBullet));
    
    Director::getInstance()->getEventDispatcher()->removeEventListener(contactListener);
    Director::getInstance()->getEventDispatcher()->removeEventListener(touchPlayerlistener);
    auto nodes=this->getChildren();
    for (const auto &node:nodes) {
        this->removeChild(node);
    }


}

void Game::updateStatusBarPlayer()
{
    auto size=Director::getInstance()->getVisibleSize();
    
    //清楚之前的得分显示，以免重叠
    Node *n=this->getChildByTag(GameSceneNodeTagStatusBarFighterNode);
    if (n) {
        this->removeChildByTag(GameSceneNodeTagStatusBarFighterNode);
    }


    Sprite *fg=Sprite::createWithSpriteFrameName("gameplay.life.png");
    fg->setPosition(size.width-60,size.height-20);
    this->addChild(fg,20,GameSceneNodeTagStatusBarFighterNode);

    Node *n2=this->getChildByTag(GameSceneNodeTagStatusBarLifeNode);
    if (n2) {
        this->removeChildByTag(GameSceneNodeTagStatusBarLifeNode);
        
    }
    if (player->getHitPoints()<0) {
        player->setHitPoints(0);
    }
    //Label的使用：  
    __String *life=__String::createWithFormat("%d",player->getHitPoints());
    auto lblLife=Label::createWithTTF(life->getCString(), "hanyi.ttf", 30);
    lblLife->setPosition(fg->getPosition()+Point(30,0));
    addChild(lblLife,20,GameSceneNodeTagStatusBarLifeNode);
    

}
void Game::onEnterTransitionDidFinish(){
Layer::onEnterTransitionDidFinish();
}
