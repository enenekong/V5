#pragma once
#include"platform.h"
#include<cmath>

const float PI = 3.1415926f;


static  int a = 10;


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
void updateInformation(const Simuro::Field& field);


