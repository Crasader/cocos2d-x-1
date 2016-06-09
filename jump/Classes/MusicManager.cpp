//
//  MusicManager.cpp
//  jump
//
//  Created by zwj on 16/6/9.
//
//

#include "MusicManager.hpp"

bool MusicManager::onSound=true;
bool MusicManager::onEffect=true;
bool MusicManager::noPlaySound=false;

void MusicManager::loadMusic()
{
    onEffect=UserDefault::getInstance()->getBoolForKey("5",true);
    onSound=UserDefault::getInstance()->getBoolForKey("6", true);
    CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic(
                                                                            "sound/BackOnTrack.mp3"
                                                                            );
    CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic(
                                                                            "sound/menuLoop.mp3"
                                                                            );
    CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic(
                                                                            "sound/CantLetGo.mp3"
                                                                            );
    CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect(
                                                                   "sound/explode_11.ogg"
                                                                   );
    CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect(
                                                                   "sound/playSound_01.ogg"
                                                                   );
    CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect(
                                                                   "sound/quitSound_01.ogg"
                                                                   );
}

void MusicManager::resumeBackgroundMusic()
{
    onSound=true;
    UserDefault::getInstance()->setBoolForKey("6", onSound);
    UserDefault::getInstance()->flush();
    
    SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
    return;

}
void MusicManager::pauseBackgroundMusic()
{
    onSound=false;
    UserDefault::getInstance()->setBoolForKey("6", onSound );
    UserDefault::getInstance()->flush();
    SimpleAudioEngine::getInstance()->pauseBackgroundMusic();


}

void MusicManager::playExplosionEffect()//“Ù–ß
{
    if(onEffect == false)
    {
        return;
    }
    //‘›Õ£±≥æ∞“Ù¿÷
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("sound/explode_11.ogg");	//≤•∑≈“Ù–ß
    return;
}
void MusicManager::playFlyLayerEffect()//Ω¯»Îπÿø® ±µƒ“Ù–ß
{
    if(onEffect == false)
    {
        return;
    }
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("sound/playSound_01.ogg");	//≤•∑≈“Ù–ß
    return;
}
void MusicManager::playPauseMenuEffect()//‘›Õ£≤Àµ•÷–µ„ª˜≤Àµ• ±µƒ“Ù–ß
{
    if(onEffect == false)
    {
        return;
    }
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("sound/quitSound_01.ogg");	//≤•∑≈“Ù–ß
    return;
}
void MusicManager::playMenuLayerMusic()//≤Àµ•±≥æ∞“Ù¿÷
{
    if(onSound == false)
    {
        return;
    }
    //≤•∑≈±≥æ∞“Ù¿÷
    CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic
    (
     "sound/menuLoop.mp3",
     true
     );
    return;
}
void MusicManager::playGameLayerMusic()
{
    if(onSound == false)
    {
        return;
    }
    //≤•∑≈±≥æ∞“Ù¿÷
    CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic
    (
     "sound/BackOnTrack.mp3",
     true
     );
    return;
    
}
void MusicManager::playFlyLayerMusic()//FlyLayerµƒ±≥æ∞“Ù¿÷
{
    if(onSound == false)
    {
        return;
    }
    //≤•∑≈±≥æ∞“Ù¿÷
    CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic
    (
     "sound/CantLetGo.mp3",
     true
     );
    return;
}