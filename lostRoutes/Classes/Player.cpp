//
//  Player.cpp
//  lostRoutes
//
//  Created by zwj on 16/5/7.
//
//

#include "Player.hpp"


Player *Player::createWithSpriteFrameName(const char *spriteFrameName)
{
    Player *player=new Player();
    if (player&&player->initWithSpriteFrameName(spriteFrameName)) {
        player->autorelease();
        
       
        
        
    
        Point verts[]=
        {
            Point(-43.5,15.5),
            Point(-23.5,33),
            Point(28.5,34),
            Point(48,17.5),
            Point(0,-39.5)};
        
        auto body=PhysicsBody::createPolygon(verts, 5);
        
        body->setCategoryBitmask(0x01);
        body->setCollisionBitmask(0x02);
        body->setContactTestBitmask(0x01);
        player->setPhysicsBody(body);
        return player;
        
    }

    CC_SAFE_DELETE(player);
    return nullptr;

}

void Player::setPosition(const cocos2d::Point &newPosition)
{
    auto screenSize=Director::getInstance()->getVisibleSize();
    
    float halfWidth=this->getContentSize().width/2;
    float halfHeight=this->getContentSize().height/2;
    float pos_x=newPosition.x;
    float pos_y=newPosition.y;
    
    if (pos_x<halfWidth) {
        pos_x=halfWidth;
    }else
        if (pos_x>(screenSize.width-halfWidth)) {
            pos_x=screenSize.width-halfWidth;
        }
    if (pos_y < halfHeight) {
        pos_y = halfHeight;
    } else if (pos_y > (screenSize.height - halfHeight)) {
        pos_y = screenSize.height - halfHeight;
    }
    Sprite::setPosition(Point(pos_x,pos_y));
    Sprite::setAnchorPoint(Point(0.5,0.5));
    
}