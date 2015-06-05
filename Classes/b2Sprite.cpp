//
//  b2Sprite.cpp
//  Air-Hockey
//
//  Created by mini02 on 15/6/3.
//
//

#include "b2Sprite.h"

b2Sprite::b2Sprite(GameLayer* game,int type)
{
    _sGame = game;
    _sType = type;
}

b2Sprite::~b2Sprite()
{
    
}

void b2Sprite::setSpritePosition(Vec2 position)
{
    setPosition(position);
    
//    if (_sBody)
//    {
//        _sBody->SetTransform(b2Vec2(position.x / PTM_RATIO, position.y / PTM_RATIO), _sBody->GetAngle());
//    }
}

void b2Sprite::update(float dt)
{
    if (_sBody)
    {
        setPositionX(_sBody->GetPosition().x * PTM_RATIO);
        setPositionY(_sBody->GetPosition().y * PTM_RATIO);
        setRotation(CC_RADIANS_TO_DEGREES(_sBody->GetAngle() * -1));
    }
}

void b2Sprite::reset()
{
    
}


