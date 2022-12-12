// DLLStrategy.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include "platform.h"
#include "adapter.h"

#include"robotMovement.h"
#include"data.h"
#include"bottom.h"

#include<iostream>
#include "xstring"
#include<string>
#include<typeinfo>
#include<sstream>
#include<locale>
#include<vector>

using namespace Simuro;
using namespace Adapter;
using namespace std;


extern float Ball_x;
extern float Ball_y;


int race_state = -1;//处于何种定位球状态，0是开球，其他遵从JudgeType
int race_state_trigger = -1;//哪一方触发了定位球


//打印比赛状态
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
void GetTeamInfo(TeamInfo *teamInfo)
{
    SendLog(L"V/DLLStrategy:GetTeamInfo()");
    static const wchar_t teamName[] = L"DLLStrategy";//在此处改名字
    static constexpr size_t len = sizeof(teamName);
    memcpy(teamInfo->teamName, teamName, len);
}

/**
* 摆位信息，进行定位球摆位
*/
void GetPlacement(Field* field) {
	SendLog(L"V/Strategy:GetPlacement()");
	auto robots = field->selfRobots;

	if (race_state == JudgeType::PlaceKick)//开球
	{
		SendLog(L"开球摆位");
		if (race_state_trigger == Team::Self)//开球进攻
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
		else if (race_state_trigger == Team::Opponent)//开球防守
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
		else//None人触发
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
void GetInstruction(Field *field)
{
    SendLog(L"V/DLLStrategy:GetInstruction()");
	//务必更新数据
	returnBall_x(field);
	returnBall_y(field);

	/*if (Ball_x < 0.f)
		throw 1;*/

	//策略运行的
	trry(*field); 



	//文件流读取，方便调试
	//注意：比赛前一定要注释掉


}

