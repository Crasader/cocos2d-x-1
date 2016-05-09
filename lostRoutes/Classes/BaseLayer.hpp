//
//  BaseLayer.hpp
//  lostRoutes
//
//  Created by zwj on 16/5/6.
//
//

#ifndef BaseLayer_hpp
#define BaseLayer_hpp

#include <stdio.h>
#include "SystemHeader.hpp"



class BaseLayer: public Layer{


    
public:
    static Scene *createScene();
    virtual bool init();
    void menuBackCallback(Ref *pSender);
    virtual void onEnterTransitionDidFinish();

    CREATE_FUNC(BaseLayer);
};








#endif /* BaseLayer_hpp */
