#pragma once
#include"data.h"
#include<algorithm>
#include <queue>

// 设置一个机器人的轮速，并保证轮速的范围是 [-125，125]
inline void Run(Simuro::Robot* robot, const float Lspeed, const float Rspeed) noexcept
{
    robot->wheel = { Lspeed,Rspeed };
       
}

void Go1(Simuro::Robot& robot, const float x, const float y);