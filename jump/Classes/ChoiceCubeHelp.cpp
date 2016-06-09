//
//  ChoiceCubeHelp.cpp
//  jump
//
//  Created by zwj on 16/6/7.
//
//

#include "ChoiceCubeHelp.hpp"
#include "ChoiceCubeLayer.hpp"

    
ChoiceCubeHelp::ChoiceCubeHelp(Layer* layerIn)
{

    this->layer=layerIn;
    sh=((ChoiceCubeLayer*)(layerIn))->sh;

}


void ChoiceCubeHelp::initCreateSprite()
{

    ParticleSystemHelp* psh=new ParticleSystemHelp();
    psh->createSnow();
    ((ChoiceCubeLayer*)layer)->addChild(psh->psq3,10);
    
    sh->backgroundRoll();
    sh->createSiJiao();
    sh->createGround();
    
    //返回按钮
    sh->allSp[1] = sh->createSprite(NULL, Rect(832,150,869-832,180-150), sh->batchNode, 0.5f, 0.5f, 45, 540-37, 63, 55, GoBackZOrder);
    sh->allSp[1]->setRotation(-90.0f);
    sh->AaddEventListenerSprite(sh->allSp[1]);
    
    //方块
    sh->allSp[2] = sh->createSprite(NULL, Rect(815,80,844-815,111-80), sh->batchNode, 0.5f, 0.5f, 290+100*0, 220+40, 50, 50, GoBackZOrder);
    sh->AaddEventListenerSprite(sh->allSp[2]);
    //∑ΩøÈÕº∆¨
    sh->allSp[3] = sh->createSprite(NULL, Rect(903,123,933-903,153-123), sh->batchNode, 0.5f, 0.5f, 290+100*1, 220+40, 50, 50, GoBackZOrder);
    sh->AaddEventListenerSprite(sh->allSp[3]);
    //∑ΩøÈÕº∆¨
    sh->allSp[4] = sh->createSprite(NULL, Rect(873,116,902-873,147-116), sh->batchNode, 0.5f, 0.5f, 290+100*2, 220+40, 50, 50, GoBackZOrder);
    sh->AaddEventListenerSprite(sh->allSp[4]);
    //∑ΩøÈÕº∆¨
    sh->allSp[5] = sh->createSprite(NULL, Rect(843,117,871-843,147-117), sh->batchNode, 0.5f, 0.5f, 290+100*3, 220+40, 50, 50, GoBackZOrder);
    sh->AaddEventListenerSprite(sh->allSp[5]);
    //∑ΩøÈÕº∆¨
    sh->allSp[6] = sh->createSprite(NULL, Rect(811,112,840-811,142-112), sh->batchNode, 0.5f, 0.5f, 290+100*4, 220+40, 50, 50, GoBackZOrder);
    sh->AaddEventListenerSprite(sh->allSp[6]);
    
    //∑ΩøÈÕº∆¨
    sh->allSp[7] = sh->createSprite(NULL, Rect(780,109,809-780,140-109), sh->batchNode, 0.5f, 0.5f, 290+100*0, 220-40, 50, 50, GoBackZOrder);
    sh->AaddEventListenerSprite(sh->allSp[7]);
    //∑ΩøÈÕº∆¨
    sh->allSp[8] = sh->createSprite(NULL, Rect(751,109,778-751,140-109), sh->batchNode, 0.5f, 0.5f, 290+100*1, 220-40, 50, 50, GoBackZOrder);
    sh->AaddEventListenerSprite(sh->allSp[8]);
    //∑ΩøÈÕº∆¨
    sh->allSp[9] = sh->createSprite(NULL, Rect(718,109,747-718,140-109), sh->batchNode, 0.5f, 0.5f, 290+100*2, 220-40, 50, 50, GoBackZOrder);
    sh->AaddEventListenerSprite(sh->allSp[9]);
    //∑ΩøÈÕº∆¨
    sh->allSp[10] = sh->createSprite(NULL, Rect(686,109,716-686,140-109), sh->batchNode, 0.5f, 0.5f, 290+100*3, 220-40, 50, 50, GoBackZOrder);
    sh->AaddEventListenerSprite(sh->allSp[10]);
    //∑ΩøÈÕº∆¨
    sh->allSp[11] = sh->createSprite(NULL, Rect(655,107,685-655,138-107), sh->batchNode, 0.5f, 0.5f, 290+100*4, 220-40, 50, 50, GoBackZOrder);
    sh->AaddEventListenerSprite(sh->allSp[11]);
    
    getData();
    //µ±«∞—°‘Òµƒ∑ΩøÈÕº∆¨
    sh->allSp[12] = sh->createSprite(NULL, Rect(p1,p2,p3,p4), sh->batchNode, 0.5f, 0.5f, 640, 350, 70, 70, GoBackZOrder);
    
    //πÿø®Õº∆¨±≥æ∞
    sh->createSprite(NULL, Rect(649, 508,1004-649,637-508), sh->batchNode, 0.5f, 0.5f, WIDTH/2, 220, 600, 150, GoBackZOrder-1);
    
    //∞Ÿƒ…ø∆ºº Œƒ◊÷Õº∆¨
    sh->createSprite(NULL, Rect(36,224,269-36,281-224), sh->batchNode, 0.5f, 0.5f, WIDTH/4+50, HEIGHT/8, 250, 60, GroundZOrder+1);
    //∞Ê»®À˘”– Œƒ◊÷Õº∆¨
    sh->createSprite(NULL, Rect(40,284,276-40,343-284), sh->batchNode, 0.5f, 0.5f, WIDTH/4*3-50, HEIGHT/8, 250, 60, GroundZOrder+1);
    //µ±«∞—°‘Ò   Œƒ◊÷Õº∆¨
    sh->createSprite(NULL, Rect(12,534,270-12,594-534), sh->batchNode, 0.5f, 0.5f, 420, 350, 300, 70, GroundZOrder+1);
    //º∏∫ŒÕº∞∏—°‘Ò Œƒ◊÷Õº∆¨
    sh->createSprite(NULL, Rect(7,1,358-7,59-1), sh->batchNode, 0.5f, 0.5f, WIDTH/2, HEIGHT-60, 450, 80, GroundZOrder+1);
}

bool ChoiceCubeHelp::JudgeSp(cocos2d::Sprite *sp)
{
    if (sp==sh->allSp[1])
    {
        ((ChoiceCubeLayer*)layer)->gsm->goMenuLayer();
        return true;
    }
    else if (sp==sh->allSp[2])
    {
        sh->batchNode->removeChild(sh->allSp[12], true);
        sh->allSp[12] = sh->createSprite(NULL, Rect(815,80,844-815,111-80), sh->batchNode, 0.5f, 0.5f, 640, 350, 70, 70, GoBackZOrder);
        p11 = 813;
        p12 = 80;
        p13 = 844-813;
        p14 = 111-80;
        saveData();
        return true;
        
    }
    
    else if(sp == sh->allSp[3])
    {
        sh->batchNode->removeChild(sh->allSp[12],true);
        sh->allSp[12] = sh->createSprite(NULL, Rect(903,123,933-903,153-123), sh->batchNode, 0.5f, 0.5f, 640, 350, 70, 70, GoBackZOrder);
        p11 = 902;
        p12 = 123;
        p13 = 933-902;
        p14 = 153-123;
        saveData();
        return true;
    }
    else if(sp == sh->allSp[4])
    {
        sh->batchNode->removeChild(sh->allSp[12],true);
        sh->allSp[12] = sh->createSprite(NULL, Rect(873,116,902-873,147-116), sh->batchNode, 0.5f, 0.5f, 640, 350, 70, 70, GoBackZOrder);
        p11 = 871;
        p12 = 116;
        p13 = 902-871;
        p14 = 147-116;
        saveData();
        return true;
    }
    else if(sp == sh->allSp[5])
    {
        sh->batchNode->removeChild(sh->allSp[12],true);
        sh->allSp[12] = sh->createSprite(NULL, Rect(843,117,871-843,147-117), sh->batchNode, 0.5f, 0.5f, 640, 350, 70, 70, GoBackZOrder);
        p11 = 841;
        p12 = 117;
        p13 = 871-841;
        p14 = 147-117;
        saveData();
        return true;
    }
    else if(sp == sh->allSp[6])
    {
        sh->batchNode->removeChild(sh->allSp[12],true);
        sh->allSp[12] = sh->createSprite(NULL, Rect(811,112,840-811,142-112), sh->batchNode, 0.5f, 0.5f, 640, 350, 70, 70, GoBackZOrder);
        p11 = 809;
        p12 = 112;
        p13 = 840-809;
        p14 = 142-112;
        saveData();
        return true;
    }
    else if(sp == sh->allSp[7])
    {
        sh->batchNode->removeChild(sh->allSp[12],true);
        sh->allSp[12] = sh->createSprite(NULL, Rect(780,109,809-780,140-109), sh->batchNode, 0.5f, 0.5f, 640, 350, 70, 70, GoBackZOrder);
        p11 = 778;
        p12 = 109;
        p13 = 809-778;
        p14 = 140-109;
        saveData();
        return true;
    }
    else if(sp == sh->allSp[8])
    {
        sh->batchNode->removeChild(sh->allSp[12],true);
        sh->allSp[12] = sh->createSprite(NULL, Rect(751,109,778-751,140-109), sh->batchNode, 0.5f, 0.5f, 640, 350, 70, 70, GoBackZOrder);
        p11 = 747;
        p12 = 109;
        p13 = 778-747;
        p14 = 140-109;
        saveData();
        return true;
    }
    else if(sp == sh->allSp[9])
    {
        sh->batchNode->removeChild(sh->allSp[12],true);
        sh->allSp[12] = sh->createSprite(NULL, Rect(718,109,747-718,140-109), sh->batchNode, 0.5f, 0.5f, 640, 350, 70, 70, GoBackZOrder);
        p11 = 717;
        p12 = 109;
        p13 = 747-717;
        p14 = 140-109;
        saveData();
        return true;
    }
    else if(sp == sh->allSp[10])
    {
        sh->batchNode->removeChild(sh->allSp[12],true);
        sh->allSp[12] = sh->createSprite(NULL, Rect(686,109,716-686,140-109), sh->batchNode, 0.5f, 0.5f, 640, 350, 70, 70, GoBackZOrder);
        p11 = 685;
        p12 = 109;
        p13 = 716-685;
        p14 = 140-109;
        saveData();
        return true;
    }
    else if(sp == sh->allSp[11])
    {
        sh->batchNode->removeChild(sh->allSp[12],true);
        sh->allSp[12] = sh->createSprite(NULL, Rect(655,107,685-655,138-107), sh->batchNode, 0.5f, 0.5f, 640, 350, 70, 70, GoBackZOrder);
        p11 = 654;
        p12 = 107;
        p13 = 685-654;
        p14 = 138-107;
        saveData();
        return true;
    }
    else
        return false;
    
    
    
}
void ChoiceCubeHelp::saveData()
{
    UserDefault::getInstance()->setIntegerForKey("1", p11);
    UserDefault::getInstance()->setIntegerForKey("2", p12);
    UserDefault::getInstance()->setIntegerForKey("3", p13);
    UserDefault::getInstance()->setIntegerForKey("4", p14);
}

void ChoiceCubeHelp::getData()
{

    p1=UserDefault::getInstance()->getIntegerForKey("1", p1);
    p2=UserDefault::getInstance()->getIntegerForKey("2", p2);
    p3=UserDefault::getInstance()->getIntegerForKey("3", p3);
    p4=UserDefault::getInstance()->getIntegerForKey("4", p4);
}