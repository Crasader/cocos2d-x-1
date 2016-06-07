//
//  ParticlSystemHelp.hpp
//  jump
//
//  Created by zwj on 16/6/7.
//
//

#ifndef ParticlSystemHelp_hpp
#define ParticlSystemHelp_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "Constant.h"
USING_NS_CC;

class ParticleSystemHelp
{

    
public:
    ParticleSystemQuad* psq1=ParticleSystemQuad::create("dragEffect.plist");
    bool isPsq1=false;
    
    ParticleSystemQuad* psq12=ParticleSystemQuad::create("explodeEffect.plist");

    ParticleSystemQuad* psq3;
    
public:
    
    //创建了一种特效
    ParticleSystemHelp(){};
    void createSnow()
    {
        psq3=ParticleSnow::create();
        psq3->retain();
        psq3->setTexture(Director::getInstance()->getTextureCache()->addImage("snow.png"));
        psq3->setPosition(Point(WIDTH/2,HEIGHT));
        psq3->setLife(3);
        psq3->setLifeVar(1);
        psq3->setGravity(Point(0,-10));
        psq3->setSpeed(130);
        psq3->setSpeedVar(30);
        psq3->setStartColor(Color4F(0.9, 0.9, 0.9, 1));
        psq3->setStartColorVar(Color4F(0, 0, 0.1, 1));
        psq3->setEmissionRate(psq3->getTotalParticles()/psq3->getLife());
        
    
    };


};

#endif /* ParticlSystemHelp_hpp */
