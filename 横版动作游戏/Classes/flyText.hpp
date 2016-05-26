//
//  flyText.hpp
//  practice
//
//  Created by zwj on 16/5/25.
//
//

#ifndef flyText_hpp
#define flyText_hpp

#include <stdio.h>
#include <cocos2d.h>
USING_NS_CC;

class FlyText:public Node
{

public:
    static FlyText *create(const char* ch);
    bool init(const char* ch);
    void startAnimation();
    void removeObject();
    
private:
    Label *label;


};

#endif /* flyText_hpp */
