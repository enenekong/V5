// DLLStrategy.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include "platform.h"
#include "adapter.h"
#include"robotMovement.h"
#include"data.h"
#include"bottom.h"


#include<iostream>

using namespace Simuro;
using namespace Adapter;
using namespace std;


extern float Ball_x;
extern float Ball_y;



int race_state = -1;//处于何种定位球状态，0是开球，其他遵从JudgeType
int race_state_trigger = -1;//哪一方触发了定位球


//打印比赛状态
=========
//处于何种定位球状态，0是开球，其他遵从JudgeType
int race_state = -1;//In which set-piece state it is, 0 is the kick-off, and the others obey JudgeType

//哪一方触发了定位球
int race_state_trigger = -1;// Which side triggered the set - piece


//打印比赛状态
//Print match status 
void OnEvent(EventType type, void* argument) {
	SendLog(L"V/Strategy:OnEvent()");
	if (type == EventType::JudgeResult)
	{
		JudgeResultEvent* judgeResult = static_cast<JudgeResultEvent*>(argument);
		race_state = judgeResult->type;
		race_state_trigger = judgeResult->actor;
		if (judgeResult->type == JudgeType::PlaceKick)
		{
			SendLog(L"Place Kick");
		}
		switch (judgeResult->actor) {
		case Team::Self:
			SendLog(L"By self");
			break;
		case Team::Opponent:
			SendLog(L"By opp");
			break;
		case Team::None:
			SendLog(L"By both");
			break;
		}
	}
}

//获得队伍信息
//Get team information 
void GetTeamInfo(TeamInfo *teamInfo)
{
    SendLog(L"V/DLLStrategy:GetTeamInfo()");
    static const wchar_t teamName[] = L"DLLStrategy";//Change Name here		//在此处改名字
    static constexpr size_t len = sizeof(teamName);
    memcpy(teamInfo->teamName, teamName, len);
}


/**
* 摆位信息，进行定位球摆位
*/

/**
* Positioning information, set - piece positioning
*/
void GetPlacement(Field* field) {
	SendLog(L"V/Strategy:GetPlacement()");
	auto robots = field->selfRobots;

	if (race_state == JudgeType::PlaceKick)// Tee off		//开球
	{
		SendLog(L"开球摆位");
		if (race_state_trigger == Team::Self)//	Tee offense		//开球进攻
		{
			robots[0].position.x = -100;
			robots[0].position.y = 20;
			robots[0].rotation = 0;
			robots[1].position.x = 42;
			robots[1].position.y = 42;
			robots[1].rotation = 180;
			robots[2].position.x = -30;
			robots[2].position.y = -10;
			robots[2].rotation = 0;
			robots[3].position.x = -50;
			robots[3].position.y = 10;
			robots[3].rotation = 0;
			robots[4].position.x = -80;
			robots[4].position.y = 0;
			robots[4].rotation = 0;
		}
		else if (race_state_trigger == Team::Opponent)// Tee Defense		//开球防守
		{
			robots[0].position.x = -100;
			robots[0].position.y = 20;
			robots[0].rotation = 0;
			robots[1].position.x = -10;
			robots[1].position.y = 80;
			robots[1].rotation = -90;
			robots[2].position.x = -30;
			robots[2].position.y = -80;
			robots[2].rotation = -90;
			robots[3].position.x = -50;
			robots[3].position.y = 70;
			robots[3].rotation = -90;
			robots[4].position.x = -80;
			robots[4].position.y = -80;
			robots[4].rotation = -90;
		}
		else// No one triggered   //None人触发
		{

		}
	}
	if (race_state == PenaltyKick)
	{
		if (race_state_trigger == Team::Self)
		{
			robots[0].position.x = -103;
			robots[0].position.y = 0;
			robots[0].rotation = 90;
			robots[1].position.x = 30;
			robots[1].position.y = 0;
			robots[1].rotation = 0;
			robots[2].position.x = -3;
			robots[2].position.y = -10;
			robots[2].rotation = 0;
			robots[3].position.x = -3;
			robots[3].position.y = 10;
			robots[3].rotation = 0;
			robots[4].position.x = -3;
			robots[4].position.y = 0;
			robots[4].rotation = 0;
		}
		if (race_state_trigger == Team::Opponent)
		{
			robots[0].position.x = -105;
			robots[0].position.y = 0;
			robots[0].rotation = 0;
			robots[1].position.x = 30;
			robots[1].position.y = 0;
			robots[1].rotation = 0;
			robots[2].position.x = 10;
			robots[2].position.y = -10;
			robots[2].rotation = 0;
			robots[3].position.x = 10;
			robots[3].position.y = 10;
			robots[3].rotation = 0;
			robots[4].position.x = 10;
			robots[4].position.y = 0;
			robots[4].rotation = 0;
		}
	}
	if (race_state == GoalKick)
	{
		if (race_state_trigger == Team::Self)
		{
			robots[0].position.x = -103;
			robots[0].position.y = 0;
			robots[0].rotation = 0;
			robots[1].position.x = 30;
			robots[1].position.y = 0;
			robots[1].rotation = 0;
			robots[2].position.x = -30;
			robots[2].position.y = -10;
			robots[2].rotation = 0;
			robots[3].position.x = -50;
			robots[3].position.y = 10;
			robots[3].rotation = 0;
			robots[4].position.x = -80;
			robots[4].position.y = 0;
			robots[4].rotation = 0;
			field->ball.position.x = -110 + 15;
			field->ball.position.y = 0;
		}
		if (race_state_trigger == Team::Opponent)
		{
			robots[0].position.x = -105;
			robots[0].position.y = 0;
			robots[0].rotation = 0;
			robots[1].position.x = 30;
			robots[1].position.y = 0;
			robots[1].rotation = 0;
			robots[2].position.x = -30;
			robots[2].position.y = -10;
			robots[2].rotation = 0;
			robots[3].position.x = -50;
			robots[3].position.y = 10;
			robots[3].rotation = 0;
			robots[4].position.x = -80;
			robots[4].position.y = 0;
			robots[4].rotation = 0;
			field->ball.position.x = 0;
			field->ball.position.y = 0;
		}
	}
	if (race_state == FreeKickLeftBot || race_state == FreeKickLeftTop
		|| race_state == FreeKickRightBot || race_state == FreeKickRightTop)
	{
		if (race_state_trigger == Team::Self)
		{
			robots[0].position.x = -103;
			robots[0].position.y = 0;
			robots[0].rotation = 90;
			robots[1].position.x = 30;
			robots[1].position.y = 0;
			robots[1].rotation = 0;
			robots[2].position.x = -30;
			robots[2].position.y = -10;
			robots[2].rotation = 0;
			robots[3].position.x = -3;
			robots[3].position.y = 10;
			robots[3].rotation = 0;
			robots[4].position.x = -3;
			robots[4].position.y = 0;
			robots[4].rotation = 0;
			field->ball.position.x = 0;
			field->ball.position.y = 0;
		}
		if (race_state_trigger == Team::Opponent)
		{
			robots[0].position.x = -105;
			robots[0].position.y = 0;
			robots[0].rotation = 0;
			robots[1].position.x = 30;
			robots[1].position.y = 0;
			robots[1].rotation = 0;
			robots[2].position.x = 10;
			robots[2].position.y = -10;
			robots[2].rotation = 0;
			robots[3].position.x = 10;
			robots[3].position.y = 10;
			robots[3].rotation = 0;
			robots[4].position.x = 10;
			robots[4].position.y = 0;
			robots[4].rotation = 0;
			field->ball.position.x = 0;
			field->ball.position.y = 0;
		}
	}

}


/**
* 获得策略信息
*/

/**
* Get policy information
*/
void GetInstruction(Field *field)
{
    SendLog(L"V/DLLStrategy:GetInstruction()");

	//务必更新数据
	//Policy Execution 
	StartMain(*field);

	//策略运行的地方
	//Where the policy code runs
>>>>>>>>> Temporary merge branch 2
	trry(*field); 



	//文件流读取，方便调试
	//注意：比赛前一定要注释掉
	//File stream reading for easy debugging
	//Note : Be sure to comment out before the game


}

