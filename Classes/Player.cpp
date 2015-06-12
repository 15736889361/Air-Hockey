//
//  Player.cpp
//  Air-Hockey
//
//  Created by mini02 on 15/6/12.
//
//

#include "Player.h"

Player::Player()
{
    
}

Player::~Player()
{
    
}

Player* Player::create(int type,Vec2 position)
{
    Player* play = new Player();
    
    if (play && play->init(type, position))
    {
        play->autorelease();
        return play;
    }
    else
    {
        CC_SAFE_DELETE(play);
        return nullptr;
    }
    
}

bool Player::init(int type,Vec2 position)
{
    if (!Sprite::init()) return false;
    
    initWithFile("mallet.png");
    setPosition(position);
    
    bindingBody();
    
    return true;
}

void Player::bindingBody()
{
    auto body = PhysicsBody::createCircle(radius());
    
    setPhysicsBody(body);
    
//    body->getShape(0)->setDensity(0.3f);
    body->getShape(0)->setFriction(0.3f);
    body->getShape(0)->setRestitution(1.0f);
    
    body->setCategoryBitmask(1);    // 0001
    body->setCollisionBitmask(1);   // 0001
    body->setContactTestBitmask(1); // 0001
    
    
    body->applyImpulse(Vec2(0, -40000));
    
}

void Player::reset()
{
    
}

void Player::update(float dt)
{
    
}

float Player::radius()
{
    CCAssert(getTexture() != nullptr,"getTexture is null");
    return getTexture()->getContentSize().width * 0.5f;
}
