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

}
GameLayer::~GameLayer()
{

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

	initEntity();

	initOther();
    
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
    
    auto body = PhysicsBody::createEdgeBox(_s_winsize,PHYSICSBODY_MATERIAL_DEFAULT,PHYCISC_DEBUG_W);
    
    auto node = Node::create();
    node->setPosition(_s_center);
    node->setPhysicsBody(body);
    
    addChild(node,kZorderGameEdage,kTagGameEdage);
}

void GameLayer::initEntity()
{
    _ball = Ball::create(0, _s_center);
    addChild(_ball);
    
    _player = Player::create(1, Vec2(_s_center.x, _s_center.y / 3));
    addChild(_player);

}

void GameLayer::initOther()
{
    
    
    auto contact = EventListenerPhysicsContact::create();
    contact->onContactBegin = CC_CALLBACK_1(GameLayer::onContactBegin, this);
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contact, this);
    
}

bool GameLayer::onContactBegin(cocos2d::PhysicsContact &contact)
{
    log("2222");
    return true;
}

void GameLayer::onExit()
{
    Layer::onExit();
    
    Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
}

void  GameLayer::update(float dt)
{

}