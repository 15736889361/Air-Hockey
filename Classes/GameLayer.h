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
#include "Constant.h"
#include "SmartRes.h"

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

	//init ui
	void initUI();
    
    //init physics
    void initPhysics();

	//initialize ball
	void initBall();
    
	//
	void initOther();


	virtual bool onTouchBegan(Touch *touch, Event *event);

	void update(float dt);
private:
    
	b2World* _world;
    
};

#endif /* defined(__Air_Hockey__GameLayer__) */
