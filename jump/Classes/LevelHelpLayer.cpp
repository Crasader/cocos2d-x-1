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
#include "GameLayer.hpp"
#include "FlyLayer.hpp"

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

void LevelHelpLayer::changeLevel(int levelNum, int direction)
{
    int sign=1;
    if (direction==1) {
        sign=1;
    }
    else if (direction==0)
    {
        sign=-1;
    
    }
    
   	if(levelNum == 1)
    {
        //πÿø®Õº∆¨±≥æ∞
        sh->allSp[14] = sh->createSprite(new std::string("1"), Rect(649, 508,1004-649,637-508), sh->batchNode, 0.5f, 0.5f, sign*WIDTH+WIDTH/2, HEIGHT/2, 575, 200, GoBackZOrder-1);
        sh->AaddEventListenerSprite(sh->allSp[14]);
        //°∞πÿ°±◊÷
        sh->allSp[15] = sh->createSprite(NULL, Rect(738, 696, 974-738, 751-696), sh->batchNode, 0.5f, 0.5f, sign*WIDTH+WIDTH/2, HEIGHT/2, 380, 75, GoBackZOrder-1);
        sh->AaddEventListenerSprite(sh->allSp[15]);
        //¡≥ Õº∆¨
        sh->allSp[19] = sh->createSprite(NULL, Rect(499,205,530-499,237-205), sh->batchNode, 0.5f, 0.5f, sign*WIDTH+WIDTH/2-575/2+575/8, HEIGHT/2, 66, 66, GoBackZOrder-1);
        sh->AaddEventListenerSprite(sh->allSp[19]);
        
        sh->allSp[12]->setColor(Color3B(0,91,186));
        sh->allSp[13]->setColor(Color3B(0,91,186));
        sh->allSp[16]->setColor(Color3B(0,91,186));
        sh->allSp[21]->setColor(Color3B(0,91,186));
        sh->allSp[20]->setColor(Color3B(0,80,163));
    }
    else if(levelNum == 2)
    {
        //πÿø®Õº∆¨±≥æ∞
        sh->allSp[14] = sh->createSprite(new std::string("2"), Rect(649, 508,1004-649,637-508), sh->batchNode, 0.5f, 0.5f, sign*WIDTH+WIDTH/2, HEIGHT/2, 575, 200, GoBackZOrder-1);
        sh->AaddEventListenerSprite(sh->allSp[14]);
        //°∞πÿ°±◊÷
        sh->allSp[15] = sh->createSprite(NULL, Rect(740, 753, 974-740, 807-753), sh->batchNode, 0.5f, 0.5f, sign*WIDTH+WIDTH/2, HEIGHT/2, 380, 75, GoBackZOrder-1);
        sh->AaddEventListenerSprite(sh->allSp[15]);
        //¡≥ Õº∆¨
        sh->allSp[19] = sh->createSprite(NULL, Rect(0,88,30,118-88), sh->batchNode, 0.5f, 0.5f, sign*WIDTH+WIDTH/2-575/2+575/8, HEIGHT/2, 66, 66, GoBackZOrder-1);
        sh->AaddEventListenerSprite(sh->allSp[19]);
        
        sh->allSp[12]->setColor(Color3B(180,88,0));
        sh->allSp[13]->setColor(Color3B(180,88,0));
        sh->allSp[16]->setColor(Color3B(180,88,0));
        sh->allSp[21]->setColor(Color3B(180,88,0));
        sh->allSp[20]->setColor(Color3B(149,73,0));
    }
    else if(levelNum == 3)
    {
        //πÿø®Õº∆¨±≥æ∞
        sh->allSp[14] = sh->createSprite(new std::string("3"), Rect(649, 508,1004-649,637-508), sh->batchNode, 0.5f, 0.5f, sign*WIDTH+WIDTH/2, HEIGHT/2, 575, 200, GoBackZOrder-1);
        sh->AaddEventListenerSprite(sh->allSp[14]);
        //°∞πÿ°±◊÷
        sh->allSp[15] = sh->createSprite(NULL, Rect(368, 496, 605-368, 555-496), sh->batchNode, 0.5f, 0.5f, sign*WIDTH+WIDTH/2+4, HEIGHT/2, 373, 75, GoBackZOrder-1);
        sh->AaddEventListenerSprite(sh->allSp[15]);
        //¡≥ Õº∆¨
        sh->allSp[19] = sh->createSprite(NULL, Rect(30,88,60-30,118-88), sh->batchNode, 0.5f, 0.5f, sign*WIDTH+WIDTH/2-575/2+575/8, HEIGHT/2, 66, 66, GoBackZOrder-1);
        sh->AaddEventListenerSprite(sh->allSp[19]);
        
        sh->allSp[12]->setColor(Color3B(219,0,0));
        sh->allSp[13]->setColor(Color3B(219,0,0));
        sh->allSp[16]->setColor(Color3B(219,0,0));
        sh->allSp[21]->setColor(Color3B(219,0,0));
        sh->allSp[20]->setColor(Color3B(152,0,0));
    }
    
}

bool LevelHelpLayer::JudgeSp(cocos2d::Sprite *sp)
{
    
    if(sp == sh->allSp[7])//À˘∞¥æ´¡È »Ù «∑µªÿº¸
    {
        ((LevelLayer*)(layer))->gsm->goMenuLayer();
        return true;
    }
    else if(sp == sh->allSp[8])//À˘∞¥æ´¡È »Ù «◊Û≤‡∞¥≈•
    {
        int index = ((LevelLayer*)(layer))->indexLevel;
        index--;
        if(index == 0)
        {
            index = 3;
        }
        changeLevel(index, 0);
        moveEffect(0);
        ((LevelLayer*)(layer))->indexLevel = index;
        return true;
    }
    else if(sp == sh->allSp[9])//À˘∞¥æ´¡È »Ù «”“≤‡∞¥≈•
    {
        int index = ((LevelLayer*)(layer))->indexLevel;
        index++;
        if(index == 4)
        {
            index = 1;
        }
        changeLevel(index, 1);
        moveEffect(1);
        ((LevelLayer*)(layer))->indexLevel = index;
        return true;
    }
    else if(sp == sh->allSp[10] ||  sp == sh->allSp[11] || sp == sh->allSp[18])//À˘∞¥æ´¡È »Ù «πÿø®±≥æ∞
    {
       // MusicManager::playFlyLayerEffect();
        std::string* spS=(std::string*)sh->allSp[10]->getUserData();
        char spC = spS->at(0);
        if(spC == '1')
        {
            ((GameLayer*)(layer))->gsm->goGameLayer(1);
        }
        else if(spC == '2')
        {
            //((FlyLayer*)(layer))->gsm->goFlayLayer();
        }
        else if(spC == '3')
        {
            ((GameLayer*)(layer))->gsm->goGameLayer(3);
        }
        return true;
    }
    else
        return false;}

void LevelHelpLayer::moveEffect(int dirction)
{
    
    int sign=-1;
    if (dirction==1)
    {
        sign=-1;
    }
    else if(dirction==0)
    {
        sign=1;
    }
    sh->allSp[10]->runAction(Sequence::create(MoveBy::create(0.5, Point(sign*WIDTH,0)),RemoveSelf::create(true), NULL));
    sh->allSp[11]->runAction(Sequence::create(
                                              MoveBy::create(0.5,Point(sign*WIDTH,0)),
                                              RemoveSelf::create(true),
                                              NULL));
    sh->allSp[18]->runAction(Sequence::create(
                                              MoveBy::create(0.5,Point(sign*WIDTH,0)),
                                              RemoveSelf::create(true),
                                              NULL));
    sh->allSp[14]->runAction(MoveBy::create(0.5,Point(sign*WIDTH,0)));
    sh->allSp[15]->runAction(MoveBy::create(0.5,Point(sign*WIDTH,0)));
    sh->allSp[19]->runAction(MoveBy::create(0.5,Point(sign*WIDTH,0)));
    sh->allSp[10] = sh->allSp[14];
    sh->allSp[11] = sh->allSp[15];
    sh->allSp[18] = sh->allSp[19];
    
}