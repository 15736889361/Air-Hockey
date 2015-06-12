//
//  Ball.cpp
//  Air-Hockey
//
//  Created by mini02 on 15/6/3.
//
//

#include "Ball.h"
#include "GameLayer.h"

Ball::Ball()
{
    
}
Ball::~Ball()
{
    
}

Ball* Ball::create(int type,Vec2 position)
{
    Ball* ball = new Ball();
    
    if (ball && ball->init(type, position))
    {
        ball->autorelease();
        return ball;
    }
    else
    {
        CC_SAFE_DELETE(ball);
        return nullptr;
    }
}

bool Ball::init(int type, Vec2 position)
{
    if (!Sprite::init()) return false;
    
    initWithFile("puck.png");
    setPosition(position);
    
    bindingBody();
    
    return true;
}

void Ball::bindingBody()
{
    auto body = PhysicsBody::createCircle(radius());
    
    setPhysicsBody(body);
    
//    body->getShape(0)->setDensity(0.3f);
    body->getShape(0)->setFriction(0.3f);
    body->getShape(0)->setRestitution(1.0f);
    
    body->setCategoryBitmask(1);    // 0001
    body->setCollisionBitmask(1);   // 0001
    body->setContactTestBitmask(1); // 0001
    
}

void Ball::update(float dt)
{
    
}

float Ball::radius()
{
    CCAssert(getTexture() != nullptr,"getTexture is null");
    return getTexture()->getContentSize().width * 0.5f;
}


void Ball::reset()
{
    
}