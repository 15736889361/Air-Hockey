//
//  GlobalEnum.h 全局枚举类
//  Air-Hockey
//
//  Created by mini02 on 15/6/3.
//
//

#ifndef __Air_Hockey__GlobalEnum__
#define __Air_Hockey__GlobalEnum__

#include <stdio.h>

enum
{
    kTagGameEdage,
    kTagGameLayer,
    kTagPlayer,
    kTagBall,
};

enum
{
    kZorderGameLayer,   //gamelayer
    kZorderGameEdage,   //物理边框
};

enum
{
    kMaskGameEdage = 1 << 0,
    kMaskBall = 1 << 1,
    kMaskPlayer = 1 << 2,
};

#endif /* defined(__Air_Hockey__GlobalEnum__) */
