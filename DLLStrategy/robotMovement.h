#pragma once
#include"data.h"
#include<algorithm>
#include <queue>

// 功能     ：设置一个机器人的轮速
// Function : Set the wheel speed of a robot
inline void Run(Simuro::Robot& robot, const float Lspeed, const float Rspeed) noexcept
{
    robot.wheel = { Lspeed,Rspeed };
       
}


//功能     ：使一个机器人以直线跑到目标位置（x,y）
//Function : Make a robot run in a straight line to the target position (x,y) 
void Go1(Simuro::Robot& robot, const float x, const float y);



