//
//  GameLayer.h
//  Air-Hockey
//
//  Created by mogoolib on 15/5/21.
//
//

#ifndef __Air_Hockey__GameLayer__
#define __Air_Hockey__GameLayer__

//tool
#include "GlobalConstant.h"
#include "SmartRes.h"

#include "cocos2d.h"
#include "Box2D/Box2D.h"

//entity
#include "Ball.h"

USING_NS_CC;

class GameLayer : public Layer
{
public:
    GameLayer();
    ~GameLayer();
    
    static GameLayer* create();
    
    virtual bool init();

	//init ui
	void initUI();
    
    //init physics
    void initPhysics();

	//initialize ball
	void initBall();
    
	//initialize other
	void initOther();

    //default update
	void update(float dt);
private:
    
	//b2World* _world;
    
    CC_SYNTHESIZE(b2World*, _world, World);
    
    CC_SYNTHESIZE(Ball*, _ball, Ball);

};

#endif /* defined(__Air_Hockey__GameLayer__) */
