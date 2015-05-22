//
//  GameLayer.cpp
//  Air-Hockey
//
//  Created by mogoolib on 15/5/21.
//
//

#include "GameLayer.h"

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
    
    initPhysics();
    
    return true;
}

//init physics
void GameLayer::initPhysics()
{
    
}