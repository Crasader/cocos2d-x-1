//
//  dataManager.hpp
//  practice
//
//  Created by zwj on 16/5/26.
//
//

#ifndef dataManager_hpp
#define dataManager_hpp

#include <stdio.h>
#include <cocos2d.h>

USING_NS_CC;

class dataManager
{
public:
    static dataManager* getInstance();
    void initWithJsonFile(const char *fileName);
    
    std::vector<std::string> getLevelDataByIndex(int index);
    
    std::string tollgateData;
    std::vector<std::string>_levelDataArry;
    CC_SYNTHESIZE(int, levelIndex, LevelIndex);


};

#endif /* dataManager_hpp */
