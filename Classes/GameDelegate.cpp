﻿//
//  GameLayer.h
//  Air-Hockey
//
//  Created by mogoolib on 15/5/21.
//
//

#include "GameDelegate.h"

GameDelegate* GameDelegate::_instance = NULL;

GameDelegate::GameDelegate()
{
    
}

GameDelegate::~GameDelegate()
{
    CC_SAFE_DELETE(_instance);
}

GameDelegate* GameDelegate::getInstance()
{
    if (!_instance)
    {
        _instance = new GameDelegate();
        _instance->init();
    }
    
    return _instance;
}

void GameDelegate::init()
{
    
}

void GameDelegate::openSceneStart()
{
    //    CCScene *pScene = CCScene::create();
    //	pScene->addChild(StartLayer::create());
    //    pScene->addChild(GameSoundEffectLayer::create());
    //
    //    CCDirector::sharedDirector()->runWithScene(pScene);
}

void GameDelegate::openSceneMainMenu()
{
    //	CCScene *pScene = CCScene::create();
    //	pScene->addChild(MenuLayer::create());
    //    pScene->addChild(GameSoundEffectLayer::create());
    //
    //    CCDirector::sharedDirector()->replaceScene(pScene);
}

void GameDelegate::openSceneHelp()
{
    //	CCScene *pScene = CCScene::create();
    //	pScene->addChild(GameHelp::create());
    //    pScene->addChild(GameSoundEffectLayer::create());
    //	CCDirector::sharedDirector()->replaceScene(pScene);
}

void GameDelegate::openSceneConfigure()
{
    //	CCScene *pScene = CCScene::create();
    //	pScene->addChild(GameConfigure::create());
    //    pScene->addChild(GameSoundEffectLayer::create());
    //
    //	CCDirector::sharedDirector()->replaceScene(pScene);
}

void GameDelegate::openSceneAbout()
{
    //	CCScene *pScene = CCScene::create();
    //	pScene->addChild(GameAbout::create());
    //    pScene->addChild(GameSoundEffectLayer::create());
    //
    //	CCDirector::sharedDirector()->replaceScene(pScene);
}

void GameDelegate::openSceneGame()
{
    Vec2 gravity(0.0f,PHYCISC_GRAIVTY_Y);
    
    auto pScene = Scene::createWithPhysics();
    
    auto world = pScene->getPhysicsWorld();
    //设置重力
    world->setGravity(gravity);
    //测试模式
    world->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);

    pScene->addChild(GameLayer::create(),kZorderGameLayer,kTagGameLayer);
    
    Director::getInstance()->runWithScene(pScene);
    //    Director::getInstance()->replaceScene(pScene);
}

void GameDelegate::exit()
{
    Director::getInstance()->end();
}