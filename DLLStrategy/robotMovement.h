#pragma once
#include"data.h"
#include<algorithm>
#include <queue>

// ����һ�������˵����٣�����֤���ٵķ�Χ�� [-125��125]
inline void Run(Simuro::Robot* robot, const float Lspeed, const float Rspeed) noexcept
{
    robot->wheel = { Lspeed,Rspeed };
       
}

void Go1(Simuro::Robot& robot, const float x, const float y);