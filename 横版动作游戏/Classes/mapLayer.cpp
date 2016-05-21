//
//  mapLayer.cpp
//  practice
//
//  Created by zwj on 16/5/21.
//
//

#include "mapLayer.hpp"
bool mapLayer::init()
{





    return  true;
}

void mapLayer::setBackGround(const char *fileName)
{

    if (bgImageView==nullptr) {
        bgImageView=ImageView::create();
        bgImageView->setAnchorPoint(Point(0,0));
        bgImageView->setPosition(Point(0,0));
        this->addChild(bgImageView);
    }
    bgImageView->loadTexture(fileName);


}