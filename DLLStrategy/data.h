#pragma once
#include"platform.h"
#include<cmath>

const float PI = 3.1415926f;


static  int a = 10;


// 返回 两个点 之间的向量转角 [0, 360] 逆时针
const float Angle(const float x1, const float y1, const float x2, const float y2) noexcept;

// 返回 机器人与某点 之间的向量转角 [0, 360] 逆时针
const float Angle(const Simuro::Robot &robot, float x, float y);

//返回 某点与某点 之间的距离
const float Diss(const float x1, const float y1, const float x2, const float y2)noexcept;

// 返回 机器人与某点 之间的距离
const float Diss(const Simuro::Robot& robot, const float x2, const float y2)noexcept;

void returnBall_x(Simuro::Field* field);//用于更新球的位置X

void returnBall_y(Simuro::Field* field);//用于更新求的位置Y





