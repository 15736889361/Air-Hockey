//
//  Utils.cpp
//  Air-Hockey
//
//  Created by mini02 on 15/6/15.
//
//

#include "Utils.h"

bool collision_circleWithCircle(Vec2 p1,float r1,Vec2 p2,float r2)
{
    //圆心距
    float distance = p1.getDistance(p2);
    
    return distance < (r1 + r2);
}
