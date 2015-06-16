//
//  Player.h 主角类
//  Air-Hockey
//
//  Created by mini02 on 15/6/12.
//
//

#ifndef __Air_Hockey__Player__
#define __Air_Hockey__Player__

#include "cocos2d.h"

#include "SmartRes.h"
#include "Utils.h"
#include "GlobalEnum.h"

#include "Ball.h"

USING_NS_CC;

enum
{
    STATE_NORMAL = 0,
    STATE_TOUCH,
};

//class Ball;
class Player : public Sprite
{
public:
    
    Player();
    ~Player();
    
    static Player* create(int type,Vec2 position);
    
    bool init(int type,Vec2 position);
    
    void bindingBody();
    
    void reset();
    
    void update(float dt);
    
    float radius();
    
    float getW();
    float getH();
    
    bool onTouchBegin(Touch* touch,Event* event);
    void onTouchMoved(Touch* touch,Event* event);
    void onTouchEnded(Touch* touch,Event* event);
    
private:
    
    int state;
    
    CC_SYNTHESIZE(Vec2, _nextPosition, NextPosition);
    
    CC_SYNTHESIZE(Ball*, _tmpBall, TmpBall);
};

#endif /* defined(__Air_Hockey__Player__) */
