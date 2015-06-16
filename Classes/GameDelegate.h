//
//  GameLayer.h 场景切换类
//  Air-Hockey
//
//  Created by mogoolib on 15/5/21.
//
//

#ifndef __Air_Hockey__GameDelegate__
#define __Air_Hockey__GameDelegate__

#include "cocos2d.h"

//layers
#include "GameLayer.h"

//global
#include "GlobalEnum.h"
#include "GlobalConstant.h"

USING_NS_CC;

class GameDelegate
{
public:
    
    GameDelegate();
    ~GameDelegate();
    
    static GameDelegate* getInstance();
    
    //LOGO界面
    void openSceneStart();
    
    //主菜单界面 MainMenu
    void openSceneMainMenu();
    
    //游戏主逻辑界面
    void openSceneGame();
    
    //配置界面 Configure
    void openSceneConfigure();
    
    //关于界面 About
    void openSceneAbout();
    
    //关于界面 Help
    void openSceneHelp();
    
    //退出
    void exit();
    
private:
    
    static GameDelegate* _instance;
    
    void init();
    
};

#endif /* defined(__Air_Hockey__GameDelegate__) */