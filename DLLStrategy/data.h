#pragma once
#include"platform.h"
#include<cmath>


const float PI = 3.1415926f;//


//��ֵ��������������
//ÿ��ʹ��ʱ��Ҫ��ʼ��������Ĭ��Ϊ0
//Means :  Assign the robot's wheel speed
//Note  :  Each time you use this variable, you need to assign a value, otherwise the default is 0 
static struct tagROBOT_WHEEL_S {
	float left = 0.0f;
	float right = 0.0f;
}ROBOT_WHEEL_S[5];

//����Ҫ�����Ŀ���
//ÿ��ʹ��ʱ��Ҫ��ʼ��������Ĭ��Ϊ0
//Means :  Target point that needs to be reached
//Note	:  Each time you use this variable, you need to assign a value, otherwise the default is 0 
static struct tagSELFR_TO {
	float x = 0.0f;
	float y = 0.0f;
}MY_R_TO[5];

//����      �� ���� ������ ֮�������ת�� [0, 360] ��ʱ��
//Function	:  Returns the angle vector between the robot and a point
const float Angle(const float x1, const float y1, const float x2, const float y2) noexcept;

//����      ������ ��������ĳ�� ֮�������ת�� [0, 360] ��ʱ��
//Function	: Returns the angle vector between two points
const float Angle(const Simuro::Robot &robot, float x, float y);

//����      ������ ĳ����ĳ�� ֮��ľ���
//Function	: Returns the distance between two points 
const float Diss(const float x1, const float y1, const float x2, const float y2)noexcept;


//����      �����ػ�������ĳ�� ֮��ľ���
//Function	: Returns the distance between the robot a point 
const float Diss(const Simuro::Robot& robot, const float x2, const float y2)noexcept;


//����      : ������Ϣ
//ע��		����Ϣ�����½������޷�Ԥ��Ĵ�����ִ�й����У����߼���Ҫ������ʹ��
///Function	: update information
//Note		: information not being updated will result in unpredictable errors 
//		      During execution, you must logically takes precedence 
void UpdateInformation(const Simuro::Field& field);

void ShowData_TXT(const Simuro::Field& field);


