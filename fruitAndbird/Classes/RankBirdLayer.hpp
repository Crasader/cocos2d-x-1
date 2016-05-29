//
//  RankBirdLayer.hpp
//  fruitAndbird
//
//  Created by zwj on 16/5/27.
//
//

#ifndef RankBirdLayer_hpp
#define RankBirdLayer_hpp

#include <stdio.h>
#include "GameSceneManager.hpp"
USING_NS_CC;

class rankBirdLayer:public Layer
{
public:
    std::string scoreBird[5];
    Label *labels;
     GameSceneManager *sceneManager;
public:
    virtual bool init();
    void save(int);
    void load();
    void menuCallBack0(Ref *pSender);
    void menuCallBack1(Ref *pSender);
    CREATE_FUNC(rankBirdLayer);
   
    
};
#endif /* RankBirdLayer_hpp */
