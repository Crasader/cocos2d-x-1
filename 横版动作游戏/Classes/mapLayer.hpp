//
//  mapLayer.hpp
//  practice
//
//  Created by zwj on 16/5/21.
//
//

#ifndef mapLayer_hpp
#define mapLayer_hpp

#include <stdio.h>
#include <iostream>
#include <cocos2d.h>
#include <ui/CocosGUI.h>
USING_NS_CC;
using namespace ui;

class mapLayer:public Layer
{

public:
    CREATE_FUNC(mapLayer);
    virtual bool init();
    void setBackGround(const char *fileName);
    


private:
    ImageView *bgImageView;
    
};

#endif /* mapLayer_hpp */
