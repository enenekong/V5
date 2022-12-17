#pragma once
#include"robotMovement.h"


//����������������������������������������������������������������������������������������������-��������//
/**********************************���ô������еĻ���֧�š�***********************************************/



extern float Ball_x;
extern float Ball_y;

extern float Will_Ball_x;
extern float Will_Ball_y;


//�з�������λ����Ϣ
//ÿ��ʹ��ʱ��Ҫȷ�ϳ�ʼ�����£�����Ĭ��Ϊ0
//Means :	Simplify the location of local robots
//Note  :	The function must be called updateInfomation or initialized, otherwise the default is 0 
static struct tagOPPR_POS_POS {
	float x = 0.0f;
	float y = 0.0f;
}OPPR_POS[5];

//�з���������Ϣ
//ÿ��ʹ��ʱ��Ҫȷ�ϳ�ʼ�����£�����Ĭ��Ϊ0
//Means :	Simplify the information of local robots
//Note  :	The function must be called updateInfomation or initialized, otherwise the default is 0 
static struct tagOPPR_OTHER {
	float right_wheel = 0.0f;
	float left_wheel = 0.0f;
	float rotation = 0.0f;
}OPPR_OTHER[5];

//��ŵ�ǰ���ڿ�ʼ���ǰ�����������
//Means :	Test historical Ball data(4) 
static struct tagLASTBALL {
	float x = 0.0f;
	float y = 0.0f;
}LASTBALL[4];

//�򻯵��õз���������Ϣ
// ֻ����bottomp�ļ���ʹ�ã�������Ч��Ĭ��Ϊ0��
// �����������Startmain������ʹ�ã��������κ��£�������Ӧ�����ȵ���GetOPPR_POS(),���ܸ�����Ч
/*
Function :	Simplify the location of local robots
Note     :	Can only be used inside "bottomp" files, otherwise invalid (default is 0) 
tips     :	If you use it on the Startmain function, nothing is required, otherwise you should call GetOPPR_POSobot() first for the update to work
*/
void GetOPPR_POS(const Simuro::Field& field);
 
//��ȡ�����ʷ3���ڵ�λ����ϢX��Y
// ֻ����bottomp�ļ���ʹ�ã�������Ч��Ĭ��Ϊ0��
// �����������Startmain������ʹ�ã��������κ��£�������Ӧ�����ȵ���GetLASTBALL(),���ܸ�����Ч
/*
Function	:	Get the position data of the ball's historical 3 periods 
Note		:	Can only be used inside "bottomp" files, otherwise invalid (default is 0)
tips		:	If you use it on the Startmain function, nothing is required, otherwise you should call GetLASTBALL() first for the update to work
*/
void GetLASTBALL(const Simuro::Field& field);

//����      ��  �����������X
//Function  :	Predict the position Y of the ball after five units of time
float PredictWill_bx(const Simuro::Field& field, unsigned int Expect_the_cycle);

//�����������X
//Function  :	Predict the position X of the ball after five units of time
float PredictWill_by(const Simuro::Field& field, unsigned int Expect_the_cycle);

//����      ��  ���ɶ�̬��Ԥ���������
//Function  :	Predict the position of the ball
void PredictBAll_n(const Simuro::Field& field);

//����      ��  �򻯵�����λ���� Go1() ������һ����
//Function  :   Simplify calling the running function  Go1 to reach a point
void MoveTo(size_t n, const Simuro::Field& field);



//��������������������������������������������������������������������������������������---��������������//
/**********************************���ô������еĻ���֧�š�***********************************************/
//������������������������������������������������������������������������������������������������������-//



/**********************************�����򱻵��ã���������ڡ�*********************************************/


//����ִ�к���
//Policy Execution 
void StartMain(Simuro::Field& field);


/**********************************�����򱻵��ã���������ڡ�*********************************************/
//������������������������������������������������������������������������������������������������������//



/**********************************������ģ�飬���鹦���Ƿ�������*****************************************/



//Function : Test historical data 
void LASTBALL_TEXT(const Simuro::Field& field);



//Function : text
void trry(Simuro::Field& field);



/**********************************������ģ�飬���鹦���Ƿ�������*****************************************/
//������������������������������������������������������������������������������������������������������-//



/**********************************����д��Ĳ��ԣ���Ϊǿ�����ӡ�***************************************/
//��������������������������������������������10�� Messi������������������������������������������������-//















/**********************************����д��Ĳ��ԣ���Ϊǿ�����ӡ�***************************************/













