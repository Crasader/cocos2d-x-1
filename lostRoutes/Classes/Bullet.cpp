//
//  Bullet.cpp
//  lostRoutes
//
//  Created by zwj on 16/5/7.
//
//

#include "Bullet.hpp"


Bullet* Bullet::createWithSpriteFrameName(const char *spriteFrameName)
{
    auto bullet=new Bullet();
    if (spriteFrameName&& bullet->initWithSpriteFrameName(spriteFrameName)) {
        
        bullet->autorelease();
        bullet->setVisible(false);
        
        auto body=PhysicsBody::createBox(bullet->getContentSize());
        
        body->setCategoryBitmask(0x01);
        body->setCollisionBitmask(0x02);
        body->setContactTestBitmask(0x01);
        
        bullet->setPhysicsBody(body);
        return bullet;
        
    }
    CC_SAFE_DELETE(bullet);
    return nullptr;
}
void Bullet::shootFromPlayer(Player *player)
{

    this->setPosition(player->getPosition()+Point(0,player->getContentSize().height/2));
    this->setVisible(true);
    this->unscheduleUpdate();
    this->scheduleUpdate();

}

void Bullet::update(float dt)
{
    auto screenSize=Director::getInstance()->getVisibleSize();

    
    this->setPosition(Point(this->getPosition()+veclocity*dt));
    if (this->getPosition().y>screenSize.height) {
        this->setVisible(false);
        this->unscheduleUpdate();
        this->removeFromParent();
    }


}