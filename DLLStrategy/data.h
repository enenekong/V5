#pragma once
#include"platform.h"
#include<cmath>


const float PI = 3.1415926f;//


//赋值机器人轮速所用
//每次使用时需要初始化，否则默认为0
//Means :  Assign the robot's wheel speed
//Note  :  Each time you use this variable, you need to assign a value, otherwise the default is 0 
static struct tagROBOT_WHEEL_S {
	float left = 0.0f;
	float right = 0.0f;
}ROBOT_WHEEL_S[5];

//所需要到达的目标点
//每次使用时需要初始化，否则默认为0
//Means :  Target point that needs to be reached
//Note	:  Each time you use this variable, you need to assign a value, otherwise the default is 0 
static struct tagSELFR_TO {
	float x = 0.0f;
	float y = 0.0f;
}MY_R_TO[5];

//功能      ： 返回 两个点 之间的向量转角 [0, 360] 逆时针
//Function	:  Returns the angle vector between the robot and a point
const float Angle(const float x1, const float y1, const float x2, const float y2) noexcept;

//功能      ：返回 机器人与某点 之间的向量转角 [0, 360] 逆时针
//Function	: Returns the angle vector between two points
const float Angle(const Simuro::Robot &robot, float x, float y);

//功能      ：返回 某点与某点 之间的距离
//Function	: Returns the distance between two points 
const float Diss(const float x1, const float y1, const float x2, const float y2)noexcept;


//功能      ：返回机器人与某点 之间的距离
//Function	: Returns the distance between the robot a point 
const float Diss(const Simuro::Robot& robot, const float x2, const float y2)noexcept;


//功能      : 更新信息
//注意		：信息不更新将导致无法预测的错误，在执行过程中，在逻辑上要先优先使用
///Function	: update information
//Note		: information not being updated will result in unpredictable errors 
//		      During execution, you must logically takes precedence 
void UpdateInformation(const Simuro::Field& field);

void ShowData_TXT(const Simuro::Field& field);


