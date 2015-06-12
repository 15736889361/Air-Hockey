//
//  Ball.h
//  Air-Hockey
//
//  Created by mini02 on 15/6/3.
//
//

#ifndef __Air_Hockey__Ball__
#define __Air_Hockey__Ball__

#include <stdio.h>
#include "cocos2d.h"


USING_NS_CC;

class Ball : public Sprite
{
public:
    
    Ball();
    ~Ball();
    
    static Ball* create(int type,Vec2 position);
    
    bool init(int type,Vec2 position);
    
    void bindingBody();
    
    void reset();
    
    void update(float dt);
    
    float radius();
    
private:
    
};


#endif /* defined(__Air_Hockey__Ball__) */
