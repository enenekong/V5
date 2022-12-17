#pragma once
#include"robotMovement.h"


//———————————————————————————————————————————————-————//
/**********************************↓让代码运行的基础支撑↓***********************************************/



extern float Ball_x;
extern float Ball_y;

extern float Will_Ball_x;
extern float Will_Ball_y;


//敌方机器人位置信息
//每次使用时需要确认初始化更新，否则默认为0
//Means :	Simplify the location of local robots
//Note  :	The function must be called updateInfomation or initialized, otherwise the default is 0 
static struct tagOPPR_POS_POS {
	float x = 0.0f;
	float y = 0.0f;
}OPPR_POS[5];

//敌方机器人信息
//每次使用时需要确认初始化更新，否则默认为0
//Means :	Simplify the information of local robots
//Note  :	The function must be called updateInfomation or initialized, otherwise the default is 0 
static struct tagOPPR_OTHER {
	float right_wheel = 0.0f;
	float left_wheel = 0.0f;
	float rotation = 0.0f;
}OPPR_OTHER[5];

//存放当前周期开始算的前四拍球的数据
//Means :	Test historical Ball data(4) 
static struct tagLASTBALL {
	float x = 0.0f;
	float y = 0.0f;
}LASTBALL[4];

//简化调用敌方机器人信息
// 只能在bottomp文件内使用，其他无效（默认为0）
// 如果您仅仅在Startmain函数上使用，无需做任何事，否则您应该优先调用GetOPPR_POS(),才能更新有效
/*
Function :	Simplify the location of local robots
Note     :	Can only be used inside "bottomp" files, otherwise invalid (default is 0) 
tips     :	If you use it on the Startmain function, nothing is required, otherwise you should call GetOPPR_POSobot() first for the update to work
*/
void GetOPPR_POS(const Simuro::Field& field);
 
//获取球的历史3周期的位置信息X和Y
// 只能在bottomp文件内使用，其他无效（默认为0）
// 如果您仅仅在Startmain函数上使用，无需做任何事，否则您应该优先调用GetLASTBALL(),才能更新有效
/*
Function	:	Get the position data of the ball's historical 3 periods 
Note		:	Can only be used inside "bottomp" files, otherwise invalid (default is 0)
tips		:	If you use it on the Startmain function, nothing is required, otherwise you should call GetLASTBALL() first for the update to work
*/
void GetLASTBALL(const Simuro::Field& field);

//功能      ：  返回球的坐标X
//Function  :	Predict the position Y of the ball after five units of time
float PredictWill_bx(const Simuro::Field& field, unsigned int Expect_the_cycle);

//返回球的坐标X
//Function  :	Predict the position X of the ball after five units of time
float PredictWill_by(const Simuro::Field& field, unsigned int Expect_the_cycle);

//功能      ：  （可动态）预测球的坐标
//Function  :	Predict the position of the ball
void PredictBAll_n(const Simuro::Field& field);

//功能      ：  简化调用跑位函数 Go1() 来到达一个点
//Function  :   Simplify calling the running function  Go1 to reach a point
void MoveTo(size_t n, const Simuro::Field& field);



//———————————————————————————————————————————---———————//
/**********************************↑让代码运行的基础支撑↑***********************************************/
//———————————————————————————————————————————————————-//



/**********************************↓程序被调用，即运行入口↓*********************************************/


//策略执行函数
//Policy Execution 
void StartMain(Simuro::Field& field);


/**********************************↑程序被调用，即运行入口↑*********************************************/
//———————————————————————————————————————————————————//



/**********************************↓测试模块，检验功能是否正常↓*****************************************/



//Function : Test historical data 
void LASTBALL_TEXT(const Simuro::Field& field);



//Function : text
void trry(Simuro::Field& field);



/**********************************↑测试模块，检验功能是否正常↑*****************************************/
//———————————————————————————————————————————————————-//



/**********************************↓编写你的策略，成为强大的球队↓***************************************/
//——————————————————————10号 Messi————————————————————————-//















/**********************************↑编写你的策略，成为强大的球队↑***************************************/













