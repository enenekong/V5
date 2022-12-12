#include"robotMovement.h"



// 使一个机器人以直线跑到目标位置（x,y）
void Go1(Simuro::Robot& robot, const float x, const float y)
{
    const float angle_robot = robot.rotation < 0.F ? robot.rotation + 360.F : robot.rotation;
    float angle_need = angle_robot - Angle(robot, x, y);
    if (180.F <= angle_need) { angle_need -= 360.F; }
    else if (angle_need < -180.F) {
        angle_need += 360.F;
    }

    const bool flag = 90.F <= fabs(angle_need);
    const float aCircle = flag ? 180.F - fabs(angle_need) : fabs(angle_need);
    float vc = 0.F;  //轮速差，转弯的幅度
    if (aCircle >= 80.F) { vc = 75.F; }
    else if (aCircle >= 40.F) {
        vc = 60.F;
    }
    else if (aCircle >= 10.F) {
        vc = 30.F;
    }
    else if (aCircle >= 5.F) {
        vc = 10.F;
    }
    else if (aCircle >= 2.F) {
        vc = 2.F;
    }
    else {
        vc = 0.F;
    }

    const float L = Diss(robot, x, y);
    float vv = 0.F;
    if (L <= 3.5F) { vv = vc = 0.F; }
    else if (L <= 8.F) {
        vv = 15.F;
    }
    else if (L <= 30.F) {
        vv = 80.F;
    }
    else {
        vv = 112.F;
    }

    if (flag) {  //判断是否反向
        vv = -vv;
        vc = -vc;
    }
    angle_need <= 0.F ? Run(&robot, vv - vc, vv) : Run(&robot, vv, vv - vc);
}

