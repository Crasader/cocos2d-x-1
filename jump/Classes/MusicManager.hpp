//
//  MusicManager.hpp
//  jump
//
//  Created by zwj on 16/6/9.
//
//

#ifndef MusicManager_hpp
#define MusicManager_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "SimpleAudioEngine.h"
USING_NS_CC;
using namespace CocosDenshion;


class MusicManager
{
public:
    
    static bool onSound;
    static bool onEffect;
    static bool noPlaySound;
    static void loadMusic();//º”‘ÿ±≥æ∞“Ù¿÷
    
    static void resumeBackgroundMusic();//ºÃ–¯±≥æ∞“Ù¿÷
    static void pauseBackgroundMusic();//‘›Õ£±≥æ∞“Ù¿÷
    
    
    static void playExplosionEffect();//±¨’® ±µƒ“Ù–ß
    static void playFlyLayerEffect();//Ω¯»Îπÿø® ±µƒ“Ù–ß
    static void playPauseMenuEffect();//‘›Õ£≤Àµ•÷–µ„ª˜≤Àµ• ±µƒ“Ù–ß
    
    static void playGameLayerMusic();//gameLayerµƒ±≥æ∞“Ù¿÷
    static void playFlyLayerMusic();//FlyLayerµƒ±≥æ∞“Ù¿÷
    static void playMenuLayerMusic();//≤Àµ•±≥æ∞“Ù¿÷
    
    
};

#endif /* MusicManager_hpp */
