#include"bottom.h"
#include"data.h"


//²âÊÔº¯Êý
//Function : text
void trry(Simuro::Field& field)
{
    const float L = Diss(field.selfRobots[1], Ball_x, Ball_y);
    if (L > 10.f)
        Go1(field.selfRobots[1], Ball_x, Ball_y);
}




