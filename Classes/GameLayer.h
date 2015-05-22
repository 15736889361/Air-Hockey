//
//  GameLayer.h
//  Air-Hockey
//
//  Created by mogoolib on 15/5/21.
//
//

#ifndef __Air_Hockey__GameLayer__
#define __Air_Hockey__GameLayer__

#include <stdio.h>
#include "cocos2d.h"
#include "Box2D/Box2D.h"

USING_NS_CC;

class GameLayer : public Layer
{
public:
    GameLayer();
    ~GameLayer();
    
    static GameLayer* create();
    
    virtual bool init();
    
    //init physics
    void initPhysics();
    
private:
    
    
};

#endif /* defined(__Air_Hockey__GameLayer__) */
