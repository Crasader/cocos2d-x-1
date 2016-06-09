//
//  MusicHelpLayer.cpp
//  jump
//
//  Created by zwj on 16/6/9.
//
//

#include "MusicHelpLayer.hpp"
#include "MusicLayer.hpp"
#include "ParticlSystemHelp.hpp"
#include "MusicManager.hpp"

MusicHelpLayer::MusicHelpLayer(Layer* layerIn)
{

    this->layer=layerIn;
    sh=((MusicLayer*)layer)->sh;


}


void MusicHelpLayer::initCreateSprite()
{
    ParticleSystemHelp* psh=new ParticleSystemHelp();
    psh->createSnow();
    ((MusicLayer*)layer)->addChild(psh->psq3,10);
    
    sh->backgroundRoll();
    sh->createSiJiao();
    sh->createGround();
    
    sh->allSp[1] = sh->createSprite(NULL, Rect(832,150,869-832,180-150), sh->batchNode, 0.5f, 0.5f, 45, 540-37, 63, 55, GoBackZOrder);
    sh->allSp[1]->setRotation(-90.0f);
    sh->AaddEventListenerSprite (sh->allSp[1]);
    
    sh->createSprite(NULL, Rect(903,638,1015-903,696-638), sh->batchNode, 0.5f, 0.5f,  420, 320, 150, 60, GroundZOrder+5);
    
    Rect recta;
    if (MusicManager::onEffect==true)
    {
        recta= Rect(196,187,233-196,225-187);
    }
    
    else
    {
    recta = Rect(234,188,271-234,224-188);
    
    }
    sh->allSp[2] = sh->createSprite(NULL, recta, sh->batchNode, 0.5f, 0.5f, 590, 320, 70, 70, GoBackZOrder);
    sh->AaddEventListenerSprite(sh->allSp[2]);
    
    //“Ù¿÷ Œƒ◊÷Õº∆¨
    sh->createSprite(NULL, Rect(731,640,842-731,696-640), sh->batchNode, 0.5f, 0.5f, 420, 240, 150, 60, GroundZOrder+5);
    if(MusicManager::onSound == true)
    {
        recta = Rect(0,184,38,38);//‘›Õ£  µƒ“Ù¿÷ø™∆Ù◊¥Ã¨   µƒÕº∆¨
    }
    else
    {
        recta = Rect(40,186,76-40,225-186);//‘›Õ£  µƒ“Ù¿÷πÿ±’◊¥Ã¨   µƒÕº∆¨
    }
    //“Ù¿÷∞¥≈•
    sh->allSp[3] = sh->createSprite(NULL, recta, sh->batchNode, 0.5f, 0.5f, 590, 240, 70, 70, GoBackZOrder);
    sh->AaddEventListenerSprite(sh->allSp[3]);
    
    //πÿø®Õº∆¨±≥æ∞
    sh->createSprite(NULL, Rect(649, 508,1004-649,637-508), sh->batchNode, 0.5f, 0.5f, WIDTH/2, 270, 600, 250, GoBackZOrder-1);
    
    //∞Ÿƒ…ø∆ºº Œƒ◊÷Õº∆¨
    sh->createSprite(NULL, Rect(36,224,269-36,281-224), sh->batchNode, 0.5f, 0.5f, WIDTH/4+50, HEIGHT/8, 250, 60, GroundZOrder+1);
    //∞Ê»®À˘”– Œƒ◊÷Õº∆¨
    sh->createSprite(NULL, Rect(40,284,276-40,343-284), sh->batchNode, 0.5f, 0.5f, WIDTH/4*3-50, HEIGHT/8, 250, 60, GroundZOrder+1);
    //“Ù¿÷”Î“Ù–ß Œƒ◊÷Õº∆¨
    sh->createSprite(NULL, Rect(732,640,1015-732,696-640), sh->batchNode, 0.5f, 0.5f, WIDTH/2, HEIGHT-60, 450, 80, GroundZOrder+1);
    
}

bool MusicHelpLayer::JudgeSp(cocos2d::Sprite *sp)
{

    if (sp==sh->allSp[1])
    {
        ( (MusicLayer*)layer)->tsm->goMenuLayer();
    }
    if(sp == sh->allSp[2])
    {
        if(MusicManager::onEffect == true)
        {
            MusicManager::onEffect = false;
            UserDefault::getInstance()->setBoolForKey("5", MusicManager::onEffect);
            UserDefault::getInstance()->flush();
        }
        else
        {
            MusicManager::onEffect = true;
            UserDefault::getInstance()->setBoolForKey("5", MusicManager::onEffect);
            UserDefault::getInstance()->flush();
        }
        sh->batchNode->removeChild(sh->allSp[2],true);
        Rect recta;
        if(MusicManager::onEffect == true)
        {
            recta = Rect(196,187,233-196,225-187);//“Ù–ßø™∆Ù◊¥Ã¨   µƒÕº∆¨
        }
        else
        {
            recta = Rect(234,188,271-234,224-188);//“Ù–ßπÿ±’◊¥Ã¨   µƒÕº∆¨
        }
        //“Ù–ß∞¥≈•
        sh->allSp[2] = sh->createSprite(NULL, recta, sh->batchNode, 0.5f, 0.5f, 590, 320, 70, 70, GoBackZOrder);
        sh->AaddEventListenerSprite(sh->allSp[2]);
        
        return true;
    }
    if(sp == sh->allSp[3])//À˘∞¥æ´¡È »Ù «   µƒ∞¥≈•
    {
        if(MusicManager::onSound == true)
        {
            MusicManager::pauseBackgroundMusic();
        }
        else
        {
            if(MusicManager::noPlaySound == true)
            {
                MusicManager::onSound = true;
                UserDefault::getInstance()->setBoolForKey("6", MusicManager::onSound);
                UserDefault::getInstance()->flush();
                MusicManager::playMenuLayerMusic();
                MusicManager::noPlaySound = false;
            }
            else
            {
                MusicManager::resumeBackgroundMusic();
            }
        }
        sh->batchNode->removeChild(sh->allSp[3],true);
        Rect recta;
        if(MusicManager::onSound == true)
        {
            recta = Rect(0,184,38,38);//‘›Õ£  µƒ“Ù¿÷ø™∆Ù◊¥Ã¨   µƒÕº∆¨
        }
        else
        {
            recta = Rect(40,186,76-40,225-186);//‘›Õ£  µƒ“Ù¿÷πÿ±’◊¥Ã¨   µƒÕº∆¨
        }
        //“Ù¿÷∞¥≈•
        sh->allSp[3] = sh->createSprite(NULL, recta, sh->batchNode, 0.5f, 0.5f, 590, 240, 70, 70, GoBackZOrder);
        sh->AaddEventListenerSprite(sh->allSp[3]);
        return true;
    }
    else
        return false;
    
}

