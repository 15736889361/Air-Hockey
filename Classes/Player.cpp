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
    state = STATE_NORMAL;
    
    _nextPosition = Vec2::ZERO;
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
    
    setTag(kTagPlayer);
    
    setNextPosition(position);
    
    scheduleUpdate();
    
    bindingBody();
    
    auto touch_listener = EventListenerTouchOneByOne::create();
    
    touch_listener->onTouchBegan = CC_CALLBACK_2(Player::onTouchBegin, this);
    touch_listener->onTouchMoved = CC_CALLBACK_2(Player::onTouchMoved, this);
    touch_listener->onTouchEnded = CC_CALLBACK_2(Player::onTouchEnded, this);
    
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touch_listener, this);
    
    return true;
}

void Player::bindingBody()
{
    auto body = PhysicsBody::createCircle(radius());
    
    body->setDynamic(true);
    body->setRotationEnable(false);
    body->setGravityEnable(false);
    
    //    body->getShape(0)->setDensity(0.3f);
    body->getShape(0)->setFriction(0.3f);
    body->getShape(0)->setRestitution(1.0f);
    
    body->setCategoryBitmask(kMaskPlayer);
    body->setCollisionBitmask(kMaskPlayer|kMaskBall);
    body->setContactTestBitmask(kMaskPlayer|kMaskBall);
    
    setPhysicsBody(body);
    
}

bool Player::onTouchBegin(Touch* touch,Event* event)
{
    //if (state != STATE_NORMAL) return false;
    
     Vec2 pos = touch->getLocation();
    
    if (!this->getBoundingBox().containsPoint(pos)) return false;
    
   // state = STATE_TOUCH;
    
    this->setPosition(pos);
    
    return true;
}

void Player::onTouchMoved(Touch* touch,Event* event)
{
    //CCAssert(state == STATE_TOUCH,"");

    Vec2 pos = touch->getLocation();
    
    Vec2 nextPosition = pos;

    //矫正pos坐标1，防止出屏

    nextPosition = Vec2(MAX(nextPosition.x,getW()),MAX(nextPosition.y, getH()));
    
    nextPosition = Vec2(MIN(nextPosition.x, _s_width - getW()), MIN(nextPosition.y, _s_height - getH()));
    
    //限制p1 和 p2的移动范围
//    if (getPositionY() < _s_center.y)
//    {
//        nextPosition.y = MIN(nextPosition.y, _s_center.y - getH());
//    }
//    else
//    {
//        nextPosition.y = MAX(nextPosition.y, _s_center.y + getH());
//    }
    

    if (collision_circleWithCircle(getPosition(), radius(), _tmpBall->getPosition(), _tmpBall->radius()))
    {
        state = STATE_TOUCH;
    }
    
    setNextPosition(nextPosition);

    getPhysicsBody()->setVelocity(Vec2(pos.x - getPositionX(), pos.y - getPositionY()));

    //CCLOG("%f,%f",getPhysicsBody()->getVelocity().x,getPhysicsBody()->getVelocity().y);
}

void Player::onTouchEnded(Touch* touch,Event* event)
{
   // CCAssert(state == STATE_TOUCH,"");
    
    state = STATE_NORMAL;
}

void Player::reset()
{
    
}

void Player::update(float dt)
{
    //setPosition(_nextPosition);
}

float Player::radius()
{
    CCAssert(getTexture() != nullptr,"getTexture is null");
    return getH();
    //getTexture()->getContentSize().width * 0.5f;
}

float Player::getW()
{
    CCAssert(getTexture() != nullptr,"getTexture is null");
    return getTexture()->getContentSize().width * 0.5f;
}

float Player::getH()
{
    CCAssert(getTexture() != nullptr,"getTexture is null");
    return getTexture()->getContentSize().height * 0.5f;
}
