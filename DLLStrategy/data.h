#pragma once
#include"platform.h"
#include<cmath>

const float PI = 3.1415926f;


static  int a = 10;


// ���� ������ ֮�������ת�� [0, 360] ��ʱ��
const float Angle(const float x1, const float y1, const float x2, const float y2) noexcept;

// ���� ��������ĳ�� ֮�������ת�� [0, 360] ��ʱ��
const float Angle(const Simuro::Robot &robot, float x, float y);

//���� ĳ����ĳ�� ֮��ľ���
const float Diss(const float x1, const float y1, const float x2, const float y2)noexcept;

// ���� ��������ĳ�� ֮��ľ���
const float Diss(const Simuro::Robot& robot, const float x2, const float y2)noexcept;

void returnBall_x(Simuro::Field* field);//���ڸ������λ��X

void returnBall_y(Simuro::Field* field);//���ڸ������λ��Y





