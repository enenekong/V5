#include"bottom.h"
#include"data.h"
#include"robotMovement.h"



void GetOPPR_POS(const Simuro::Field& field)
{
    for (size_t i = 0; i < 5; i++) {
        OPPR_POS[i].x = field.opponentRobots[i].position.x;
        OPPR_POS[i].y = field.opponentRobots[i].position.y;
        OPPR_OTHER[i].left_wheel = field.opponentRobots[i].wheel.leftSpeed;
        OPPR_OTHER[i].right_wheel = field.opponentRobots[i].wheel.rightSpeed;
        OPPR_OTHER[i].rotation = field.opponentRobots[i].rotation;
    }
}


void MoveTo(size_t n, Simuro::Field& field)
{
    Go1(field.selfRobots[n], MY_R_TO[n].x, MY_R_TO[n].y);
}


void StartMain(Simuro::Field& field)
{
   //update the data ofopponent robot 
    GetOPPR_POS(field); 

    
    trry(field);
   

}


void trry(Simuro::Field& field)
{

    //MY_R_TO[2].x = -72.f;
    //MY_R_TO[2].y = -72.f;
    //MoveTo(2, field);

    //MY_R_TO[1].x = -12.f;
    //MY_R_TO[1].y = -12.f;
    //MoveTo(1, field);

    Go1(field.selfRobots[1], Ball_x, Ball_y);

    Go1(field.selfRobots[3], OPPR_POS[0].x, OPPR_POS[0].y);



}



