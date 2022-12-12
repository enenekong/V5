#include"data.h"

extern float Ball_x = 0.0;
extern float Ball_y = 0.0;




//���ڸ������λ��X
void returnBall_x(Simuro::Field* field )
{
    Ball_x = field->ball.position.x;
}


//���ڸ������λ��Y
void returnBall_y(Simuro::Field* field)
{
    Ball_y = field->ball.position.y;
}

// ���� ĳ����ĳ�� ֮��ľ���
const float Diss(const float x1, const float y1, const float x2, const float y2)noexcept
{
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

// ���� ��������ĳ�� ֮��ľ���
const float Diss(const Simuro::Robot &robot, const float x2, const float y2)noexcept
{
    return Diss(robot.position.x, robot.position.y, x2, y2);
}

// ���� ��������ĳ�� ֮�������ת�� [0, 360] ��ʱ��
const float Angle(const Simuro::Robot &robot, float x, float y)
{
    return Angle(robot.position.x, robot.position.y, x, y);
}


// ���� ������ ֮�������ת�� [0, 360] ��ʱ��
const float Angle(const float x1, const float y1, const float x2, const float y2) noexcept
{
    float angle = 0.F, L = Diss(x1, y1, x2, y2);
    if (L == 0.F) { L = 0.001F; }  //��ֹ��ĸΪ 0
    if ((y2 - y1) / L > 1.F) { angle = 90.F; }
    else if ((y2 - y1) / L < -1.F) {
        angle = -90.F;
    }
    else {
        angle = asin((y2 - y1) / L) * 180.F / PI;
    }

    if (y1 <= y2 && x2 <= x1) { angle = 180.F - angle; }  //�����������y1 = y2
    else if (y2 < y1) {
        if (x2 < x1) { angle = 180.F - angle; }
        else if (x1 < x2) {
            angle += 360.F;
        }
    }
    return angle;
}

