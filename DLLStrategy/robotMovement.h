#pragma once
#include"data.h"
#include<algorithm>
#include <queue>

// ����     ������һ�������˵�����
// Function : Set the wheel speed of a robot
inline void Run(Simuro::Robot& robot, const float Lspeed, const float Rspeed) noexcept
{
    robot.wheel = { Lspeed,Rspeed };
       
}


//����     ��ʹһ����������ֱ���ܵ�Ŀ��λ�ã�x,y��
//Function : Make a robot run in a straight line to the target position (x,y) 
void Go1(Simuro::Robot& robot, const float x, const float y);



