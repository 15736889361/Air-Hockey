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
    
    body->setCategoryBitmask(kMaskGameEdage);
    body->setContactTestBitmask(kMaskGameEdage|kMaskBall);
    body->setCollisionBitmask(kMaskGameEdage|kMaskBall);
    
    auto node = Node::create();
    node->setPosition(_s_center);
    node->setPhysicsBody(body);
    
    addChild(node,kZorderGameEdage,kTagGameEdage);
}

void GameLayer::initEntity()
{
    _ball = Ball::create(0, _s_center);
    addChild(_ball,2);
    
    float w = _ball->radius();
    
    auto motionStreak = MotionStreak::create(0.5f, 5, w * 2, Color3B::RED, "ball_motionstreak.png");
    this->addChild(motionStreak,1);
    motionStreak->setTag(1011);
    
    _player = Player::create(1, Vec2(_s_center.x, _s_center.y / 3));
    addChild(_player);
    
    _player->setTmpBall(_ball);
}

void GameLayer::initOther()
{
    scheduleUpdate();
    
    //物理碰撞监听
    auto contact = EventListenerPhysicsContact::create();
    contact->onContactBegin = CC_CALLBACK_1(GameLayer::onContactBegin, this);
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contact, this);
}

bool GameLayer::onContactBegin(cocos2d::PhysicsContact &contact)
{
    log("2222");
    
    if ((contact.getShapeA()->getBody()->getCategoryBitmask() & kMaskBall) == kMaskBall)
    {
        //ball do something
    }
    if ((contact.getShapeB()->getBody()->getCategoryBitmask() & kMaskBall) == kMaskBall)
    {
        //ball do something
    }
    
    if ((contact.getShapeA()->getBody()->getCategoryBitmask() & kMaskPlayer) == kMaskPlayer)
    {
        //player do something
    }
    if ((contact.getShapeB()->getBody()->getCategoryBitmask() & kMaskPlayer) == kMaskPlayer)
    {
        //player do something
    }
    
//    auto nodeA = (Sprite*)contact.getShapeA()->getBody()->getNode();
//    auto nodeB = (Sprite*)contact.getShapeB()->getBody()->getNode();
//    
//    if (nodeA == nullptr || nodeB == nullptr)
//    {
//        
//        return false;
//    }
    
    return true;
}

void GameLayer::onExit()
{
    Layer::onExit();
    
    Director::getInstance()->getEventDispatcher()->removeEventListenersForTarget(this);
}

void GameLayer::update(float dt)
{
    auto motion = this->getChildByTag(1011);
    motion->setPosition(_ball->convertToWorldSpaceAR(Vec2::ZERO));
}