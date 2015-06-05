//
//  b2Sprite.h
//  Air-Hockey
//
//  Created by mini02 on 15/6/3.
//
//

#ifndef __Air_Hockey__b2Sprite__
#define __Air_Hockey__b2Sprite__

#include "cocos2d.h"
#include "Box2D/Box2D.h"

#include "GlobalConstant.h"

USING_NS_CC;

class GameLayer;
class b2Sprite : public Sprite
{
public:
    b2Sprite(GameLayer* game,int type);
    virtual ~b2Sprite();
    
    virtual void setSpritePosition(Vec2 position);
    virtual void update(float dt);
    virtual void reset();
    
public:
    //body
    CC_SYNTHESIZE(b2Body*, _sBody, SBody);
    //
    CC_SYNTHESIZE(GameLayer*, _sGame, SGame);
    //sprite type
    CC_SYNTHESIZE(int, _sType, SType);
};

#endif /* defined(__Air_Hockey__b2Sprite__) */
