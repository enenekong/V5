#pragma once
#include"robotMovement.h"


extern float Ball_x;

extern float Ball_y;


//�з�������λ����Ϣ
//ÿ��ʹ��ʱ��Ҫȷ�ϳ�ʼ�����£�����Ĭ��Ϊ0
//Means : Simplify the location of local robots
//Note  : The function must be called updateInfomation or initialized, otherwise the default is 0 
static struct tagOPPR_POS_POS {
	float x = 0.0f;
	float y = 0.0f;
}OPPR_POS[5];

//�з���������Ϣ
//ÿ��ʹ��ʱ��Ҫȷ�ϳ�ʼ�����£�����Ĭ��Ϊ0
//Means : Simplify the information of local robots
//Note  : The function must be called updateInfomation or initialized, otherwise the default is 0 
static struct tagOPPR_OTHER {
	float right_wheel = 0.0f;
	float left_wheel = 0.0f;
	float rotation = 0.0f;
}OPPR_OTHER[5];


//�򻯵��õз���������Ϣ
// ֻ����bottomp�ļ���ʹ�ã�������Ч��Ĭ��Ϊ0��
// ���������Startmain������ʹ�ã��������κ��£�������Ӧ�����ȵ���GetOPPR_POS(),���ܸ�����Ч
/*
Function :	Simplify the location of local robots
Note     :	Can only be used inside "bottomp" files, otherwise invalid (default is 0) 
tips     :	If you use it on the Startmain function, nothing is required, otherwise you should call GetOPPR_POSobot first for the update to work
*/
void GetOPPR_POS(const Simuro::Field& field);
 

//����      ��  �򻯵�����λ���� Go1() ������һ����
//Function  :   Simplify calling the running function  Go1 to reach a point
void MoveTo(size_t n, const Simuro::Field& field);


//����ִ�к���
//Policy Execution 
void StartMain(Simuro::Field& field);


//Function : text
void trry(Simuro::Field& field);



