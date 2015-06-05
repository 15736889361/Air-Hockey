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

#include "b2Sprite.h"

USING_NS_CC;

class Ball : public b2Sprite
{
public:
    
    Ball(GameLayer* game,int type,Vec2 position);
    ~Ball();
    
    static Ball* create(GameLayer* game,int type,Vec2 position);
    
    virtual void reset();
    
    virtual void update(float dt);
    
    float radius();
    
private:
    
    void initBall();
    
    CC_SYNTHESIZE(Vec2, _startPosition, StartPosition);
};


#endif /* defined(__Air_Hockey__Ball__) */
