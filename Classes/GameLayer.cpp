//
//  GameLayer.cpp
//  Air-Hockey
//
//  Created by mogoolib on 15/5/21.
//
//

#include "GameLayer.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

using namespace ui;
using namespace cocostudio::timeline;

GameLayer::GameLayer()
{
	_world = nullptr;
}
GameLayer::~GameLayer()
{
	CC_SAFE_DELETE(_world);
}

GameLayer* GameLayer::create()
{
    auto layer = new GameLayer();
    
    if (layer && layer->init())
    {
        layer->autorelease();
        return layer;
    }
    else
    {
        CC_SAFE_DELETE(layer);
        return nullptr;
    }
}

bool GameLayer::init()
{
    if ( !Layer::init() )
    {
        return false;
    }

	initUI();

	initPhysics();
    
    return true;
}

void GameLayer::initUI()
{
	auto layer = CSLoader::createNode("MainScene.csb");
	addChild(layer);

}

//init physics
void GameLayer::initPhysics()
{
    //init world
	 b2Vec2 gravity;
	 gravity.SetZero();

	_world = new b2World(gravity);
	_world->SetAllowSleeping(true);
	_world->SetContinuousPhysics(true);

	//init walls
	
	b2BodyDef def;
	def.position.SetZero();

	b2Body *walls = _world->CreateBody(&def);

	b2EdgeShape shape;

	//up
	shape.Set(b2Vec2(0,_s_height / PTM_RATIO),b2Vec2(_s_width / PTM_RATIO,_s_height / PTM_RATIO));
	walls->CreateFixture(&shape,0);

	//down
	shape.Set(b2Vec2(0,0),b2Vec2(_s_width / PTM_RATIO,0));
	walls->CreateFixture(&shape,0);

	//left
	shape.Set(b2Vec2(0,0),b2Vec2(0,_s_height / PTM_RATIO));
	walls->CreateFixture(&shape,0);

	//right
	shape.Set(b2Vec2(_s_width / PTM_RATIO,0),b2Vec2(_s_width / PTM_RATIO,_s_height / PTM_RATIO));
	walls->CreateFixture(&shape,0);
}

void GameLayer::initOther()
{
	this->scheduleUpdate();
}

void  GameLayer::update(float dt)
{
	_world->Step(dt,10,10);
}