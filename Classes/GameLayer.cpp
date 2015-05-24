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

	auto layer = CSLoader::createNode("MainScene.csb");
	addChild(layer);
    
    return true;
}

//init physics
void GameLayer::initPhysics()
{
    
}