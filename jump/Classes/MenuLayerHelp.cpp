//
//  MenuLayerHelp.cpp
//  jump
//
//  Created by zwj on 16/6/6.
//
//

#include "MenuLayerHelp.hpp"
#include "MenuLayer.hpp"


MenuLayerHelp::MenuLayerHelp(Layer* layerIn)
{

    this->layer=layerIn;
    
    //获取menulayer的管理指针
    sh=((MenuLayer*)(layer))->sh;

}

void MenuLayerHelp::initCreateSprite()
{
    //左上角的退出按钮
    sh->allSp[7]=sh->createSprite(NULL, Rect(832,150,869-832,180-150), sh->batchNode, 0.5f, 0.5f, 45, 540-37, 63, 55, GoBackZOrder);
    sh->allSp[7]->setRotation(-90);
    sh->AaddEventListenerSprite(sh->allSp[7]);
    
    //
    sh->allSp[20] = sh->createSprite(NULL, Rect(307,644,413-307,750-644), sh->batchNode, 0.5f, 0.5f, WIDTH/2, HEIGHT/2, 179, 179, GroundZOrder+1);
    sh->AaddEventListenerSprite(sh->allSp[20]);
    
    //
    
    sh->allSp[21] = sh->createSprite(NULL, Rect(590,339,66,66), sh->batchNode, 0.5f, 0.5f, 293, HEIGHT/2, 114, 114, GroundZOrder+1);
    sh->AaddEventListenerSprite(sh->allSp[21]);

    //
    sh->allSp[22] = sh->createSprite(NULL, Rect(390,384,66,66), sh->batchNode, 0.5f, 0.5f, 666, HEIGHT/2, 114, 114, GroundZOrder+1);
    sh->AaddEventListenerSprite(sh->allSp[22]);
    
    
    //
    sh->createSiJiao();
    
    sh->createSprite(NULL, Rect(383,574,616-383,631-574), sh->batchNode, 0.5f, 0.5f, WIDTH/2, (HEIGHT/2+80+HEIGHT)/2, 510, 120, GroundZOrder+1);
    
    sh->createGround();

    sh->backgroundRoll();
}

//判断精灵是否为进入选择管卡的按钮
bool MenuLayerHelp::JudgeSp(cocos2d::Sprite *sp)
{
    if(sp == sh->allSp[20])
{
   ((MenuLayer*)(layer))->gsm->goLevelLayer();
    return true;
}
else if(sp == sh->allSp[21])
{
    ((MenuLayer*)(layer))->gsm->goChoiceCubeLayer();
    return true;
}
else if(sp == sh->allSp[22])
{
    ((MenuLayer*)(layer))->gsm->goMusicLayer();
    return true;
}
    
else if(sp == sh->allSp[7])
{
    Director::getInstance()->end();
    return true;
}
    else
        return false;
}