//
//  Player.h
//  Air-Hockey
//
//  Created by mini02 on 15/6/12.
//
//

#ifndef __Air_Hockey__Player__
#define __Air_Hockey__Player__

#include "cocos2d.h"

USING_NS_CC;

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
    
};

#endif /* defined(__Air_Hockey__Player__) */
