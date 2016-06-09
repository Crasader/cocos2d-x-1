//
//  LevelHelpLayer.cpp
//  jump
//
//  Created by zwj on 16/6/9.
//
//

#include "LevelHelpLayer.hpp"
#include "LevelLayer.hpp"
#include "ParticlSystemHelp.hpp"

LevelHelpLayer::LevelHelpLayer(Layer* layerIn)
{

    this->layer=layerIn;
    sh=((LevelLayer*)layer)->sh;
}

void LevelHelpLayer::initCreateSp()
{

    ParticleSystemHelp* psh=new ParticleSystemHelp();
    psh->createSnow();
    ((LevelLayer*)layer)->addChild(psh->psq3,10);
    

    
    sh->createSprite(NULL, Rect(0,391,389-0,424-391), sh->batchNode, 0.5f, 1.0f, WIDTH/2, HEIGHT, 560, 52, GoBackZOrder);
    
    //◊Û…œΩ« µƒ∑µªÿº¸∞¥≈•
    sh->allSp[7] = sh->createSprite(NULL, Rect(871,154,910-871,186-154), sh->batchNode, 0.5f, 0.5f, 45, 540-37, 63, 55, GoBackZOrder);
    sh->allSp[7]->setRotation(-90.0f);
    sh->AaddEventListenerSprite(sh->allSp[7]);
    
    //◊Ûœ¬Ω« µƒÕº∆¨
    sh->createSprite(NULL, Rect(825,386,897-825,457-386), sh->batchNode, 0.0f, 0.0f, 0, 0, 120, 120, GoBackZOrder);
    
    //πÿø®—°‘Ò  Õº∆¨
    sh->createSprite(NULL, Rect(6,600,246-6,657-600), sh->batchNode, 0.5f, 0.5f, WIDTH/2, HEIGHT/4*3+25, 270, 70, GoBackZOrder);
    
    //”“œ¬Ω« µƒÕº∆¨
    Sprite* sp = sh->createSprite(NULL, Rect(825,386,897-825,457-386), sh->batchNode, 0.0f, 0.0f, WIDTH-120, 0, 120, 120, GoBackZOrder);
    sp->setFlippedX(true);
    
    //◊Û≤‡ µƒ∞¥≈•
    sh->allSp[8] = sh->createSprite(NULL, Rect(949, 65,1009-949,93-65), sh->batchNode, 0.5f, 1.0f, 64, HEIGHT/2, 325-233, 942-894, GoBackZOrder);
    sh->allSp[8]->setRotation(90.0f);
    sh->allSp[8]->setFlippedX(true);
    sh->AaddEventListenerSprite(sh->allSp[8]);
    
    //”“≤‡ µƒ∞¥≈•
    sh->allSp[9] = sh->createSprite(NULL, Rect(949, 65,1009-949,93-65), sh->batchNode, 0.5f, 1.0f, 894, HEIGHT/2, 325-233, 942-894, GoBackZOrder);
    sh->allSp[9]->setRotation(-90.0f);
    sh->AaddEventListenerSprite(sh->allSp[9]);
    
    //¥¥Ω®µÿ√Ê∫Õ±≥æ∞
    sh->allSp[12] = sh->createSprite(NULL, Rect(129,685,243-129,802-685), sh->batchNode, 0.5f, 1.0f, WIDTH/8, 85, WIDTH/4, 85, GroundZOrder-1);//¥¥Ω®æÿ–Œ
    sh->allSp[12]->setColor(Color3B(0,91,186));
    sh->allSp[13] = sh->createSprite(NULL, Rect(129,685,243-129,802-685), sh->batchNode, 0.5f, 1.0f, WIDTH/8*3, 85, WIDTH/4, 85, GroundZOrder-1);//¥¥Ω®æÿ–Œ
    sh->allSp[13]->setColor(Color3B(0,91,186));
    sh->allSp[16] = sh->createSprite(NULL, Rect(129,685,243-129,802-685), sh->batchNode, 0.5f, 1.0f, WIDTH/8*5, 85, WIDTH/4, 85, GroundZOrder-1);//¥¥Ω®æÿ–Œ
    sh->allSp[16]->setColor(Color3B(0,91,186));
    sh->allSp[21] = sh->createSprite(NULL, Rect(129,685,243-129,802-685), sh->batchNode, 0.5f, 1.0f, WIDTH/8*7, 85, WIDTH/4, 85, GroundZOrder-1);//¥¥Ω®æÿ–Œ
    sh->allSp[21]->setColor(Color3B(0,91,186));
    sh->allSp[20] = sh->createStaticSprite(NULL, "game_bg_01_001-hd.png", 0.0f, 0.0f, 0, 0, WIDTH, HEIGHT);//¥¥Ω®±≥æ∞æ´¡È
    sh->allSp[20]->setColor(Color3B(0,80,163));
    layer->addChild(sh->allSp[20],GroundZOrder-2);
    
    //πÿø®Õº∆¨‘≤Ω«æÿ–Œ±≥æ∞
    sh->allSp[10] = sh->createSprite(new std::string("1"), Rect(649, 508,1004-649,637-508), sh->batchNode, 0.5f, 0.5f, WIDTH/2, HEIGHT/2, 575, 200, GoBackZOrder-1);
    sh->AaddEventListenerSprite(sh->allSp[10]);
    //°∞πÿ°±◊÷
    sh->allSp[11] = sh->createSprite(NULL, Rect(738, 696, 974-738, 751-696), sh->batchNode, 0.5f, 0.5f, WIDTH/2, HEIGHT/2, 380, 75, GoBackZOrder-1);
    sh->AaddEventListenerSprite(sh->allSp[11]);
    //¡≥ Õº∆¨
    sh->allSp[18] = sh->createSprite(NULL, Rect(499,205,530-499,237-205), sh->batchNode, 0.5f, 0.5f, WIDTH/2-575/2+575/8, HEIGHT/2, 66, 66, GoBackZOrder-1);
    sh->AaddEventListenerSprite(sh->allSp[18]);
    ((LevelLayer*)(layer))->indexLevel = 1;
}


