//
//  GameLayer.h 游戏布景类
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
#include "GlobalEnum.h"

#include "cocos2d.h"
#include "Box2D/Box2D.h"

//entity
#include "Ball.h"
#include "Player.h"

USING_NS_CC;

class GameLayer : public Layer
{
public:
    GameLayer();
    ~GameLayer();
    
    static GameLayer* create();
    
    virtual bool init();
    
    virtual void onExit();

	//init ui
	void initUI();
    
    //init physics
    void initPhysics();

	//initialize entity
	void initEntity();
    
	//initialize other
	void initOther();

    //default update
	void update(float dt);
    
    //collision
    bool onContactBegin(PhysicsContact& contact);
    
private:
    
    CC_SYNTHESIZE(Player*, _player, MyPlayer);
    
    CC_SYNTHESIZE(Ball*, _ball, MyBall);

};

#endif /* defined(__Air_Hockey__GameLayer__) */
