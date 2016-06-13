//
//  GDData.hpp
//  jump
//
//  Created by zwj on 16/6/13.
//
//

#ifndef GDData_hpp
#define GDData_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "Barrier.hpp"
USING_NS_CC;

class GDData
{


public:
    
    GDData(Layer* layerIn);
    void createData();
    void createData3();
    void createFlyData();
    void createEightTriangle1(Layer* layer2);
    void createEightTriangle2(Layer* layer2);
    
public:
    std::string* ids;
    Barrier* tb;
    Layer* layer;
};
#endif /* GDData_hpp */
