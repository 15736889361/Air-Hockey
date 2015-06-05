//
//  Ball.cpp
//  Air-Hockey
//
//  Created by mini02 on 15/6/3.
//
//

#include "Ball.h"
#include "GameLayer.h"

Ball::Ball(GameLayer* game,int type,Vec2 position):b2Sprite(game,type)
{
    _startPosition = position;
}
Ball::~Ball()
{
    
}

Ball* Ball::create(GameLayer* game,int type,Vec2 position)
{
    Ball* ball = new Ball(game,type,position);
    
    if (ball)
    {
        ball->initBall();
        
        ball->autorelease();
        
        return ball;
    }
    else
    {
        CC_SAFE_DELETE(ball);
        return nullptr;
    }
}


void Ball::initBall()
{
    //init texture
    initWithFile("puck.png");

//    b2BodyDef def;
//    def.type = b2_dynamicBody;
//    
//    _sBody = _sGame->getWorld()->CreateBody(&def);
//    _sBody->SetLinearDamping(1.2f);
//    _sBody->SetAngularDamping(0.8f);
//    
//    b2CircleShape shape;
//    shape.m_radius = radius() / PTM_RATIO;
//    
//    b2FixtureDef fixDef;
//    fixDef.shape = &shape;
//    fixDef.density = 1.0f;//密度 不能为0.0
//    fixDef.friction = 0.2f;//摩擦力
//    fixDef.restitution = 0.3f;//弹力
//    
//    _sBody->CreateFixture(&fixDef);
//    _sBody->SetUserData(this);
    
    setStartPosition(_startPosition);
}


void Ball::update(float dt)
{
    //b2Sprite::update(dt);
}

float Ball::radius()
{
    CCAssert(getTexture() != nullptr,"getTexture is null");
    return getTexture()->getContentSize().width * 0.5f;
}


void Ball::reset()
{
    
}