#pragma once
#include"robotMovement.h"


extern float Ball_x;

extern float Ball_y;


//敌方机器人位置信息
//每次使用时需要确认初始化更新，否则默认为0
//Means : Simplify the location of local robots
//Note  : The function must be called updateInfomation or initialized, otherwise the default is 0 
static struct tagOPPR_POS_POS {
	float x = 0.0f;
	float y = 0.0f;
}OPPR_POS[5];

//敌方机器人信息
//每次使用时需要确认初始化更新，否则默认为0
//Means : Simplify the information of local robots
//Note  : The function must be called updateInfomation or initialized, otherwise the default is 0 
static struct tagOPPR_OTHER {
	float right_wheel = 0.0f;
	float left_wheel = 0.0f;
	float rotation = 0.0f;
}OPPR_OTHER[5];


//简化调用敌方机器人信息
// 只能在bottomp文件内使用，其他无效（默认为0）
// 如果您尽在Startmain函数上使用，无需做任何事，否则您应该优先调用GetOPPR_POS(),才能更新有效
/*
Function :	Simplify the location of local robots
Note     :	Can only be used inside "bottomp" files, otherwise invalid (default is 0) 
tips     :	If you use it on the Startmain function, nothing is required, otherwise you should call GetOPPR_POSobot first for the update to work
*/
void GetOPPR_POS(const Simuro::Field& field);
 

//功能      ：  简化调用跑位函数 Go1() 来到达一个点
//Function  :   Simplify calling the running function  Go1 to reach a point
void MoveTo(size_t n, const Simuro::Field& field);


//策略执行函数
//Policy Execution 
void StartMain(Simuro::Field& field);


//Function : text
void trry(Simuro::Field& field);



