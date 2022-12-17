#include"bottom.h"
#include"data.h"
#include"robotMovement.h"
#include<fstream>



//—————————————————————————————————————————————————--—//
/**********************************↓让代码运行的基础支撑↓**********************************************/


extern float Will_Ball_x = 0.0f;//The predicted coordinates of the sphere x 
extern float Will_Ball_y = 0.0f;//The predicted coordinates of the sphere y

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

void GetLASTBALL(const Simuro::Field& field)
{
    const float bx = field.ball.position.x;
    const float by = field.ball.position.y;

    size_t now = field.tick;

    //static size_t time = 0;
    //if(now > 5 && (now % 3) == 0)
    //time = now - 3;

 /*   if (now >= 3 && now < 7) {
        if (now == 3)
            LASTBALL[0] = { bx, by};
        if (now == 4)
            LASTBALL[1] = { bx, by };
        if (now == 5)
            LASTBALL[2] = { bx, by };
        if (now == 6)
            LASTBALL[3] = { bx, by };

    }*/

     if (now >= 2) {
        LASTBALL[0] = LASTBALL[1];
        LASTBALL[1] = LASTBALL[2];
        LASTBALL[2] = LASTBALL[3];
        LASTBALL[3] = { bx, by };
      }

}

void PredictBAll_n(const Simuro::Field& field)
{
    PredictWill_bx(field, 5);
    PredictWill_by(field, 5);
    Will_Ball_x = PredictWill_bx(field, 5);
    Will_Ball_y = PredictWill_by(field, 5);

}

void MoveTo(size_t n, Simuro::Field& field)
{
    Go1(field.selfRobots[n], MY_R_TO[n].x, MY_R_TO[n].y);
}

float PredictWill_bx(const Simuro::Field& field , unsigned int Expect_the_cycle)
{

    float cx = 0.f;
    for (int i = 0; i < 3; i++) {
        float cx_i = LASTBALL[i + 1].x - LASTBALL[i].x;
        cx = cx + cx_i;
    }
    cx = cx / 3.0f;
    const float will_bx = field.ball.position.x + cx * Expect_the_cycle;
    return will_bx;
}

float PredictWill_by(const Simuro::Field& field, unsigned int Expect_the_cycle)
{

    float cy = 0.f;
    for (int i = 0; i < 3; i++) {
        float cy_i = LASTBALL[i + 1].y - LASTBALL[i].y;
        cy = cy + cy_i;
    }
    cy = cy / 3.0f;
    const float will_by = field.ball.position.y + cy * Expect_the_cycle;
    return will_by;
}




//———————————————————————————————————————————————————-//
/**********************************↑让代码运行的基础支撑↑***********************************************/
//—————————————————————————————————————————————————-——//



/**********************************↓程序被调用，即运行入口↓*********************************************/


void StartMain(Simuro::Field& field)
{
    //update the data、opponent robot、Ball information 
    GetOPPR_POS(field);
    GetLASTBALL(field);
    PredictBAll_n(field);

    //测试函数
    //Text Function
    trry(field);


    //所有策略调用
    //Run Code



    //输出数据测试
    //output the test data
    LASTBALL_TEXT(field);

    
}


/**********************************↑程序被调用，即运行入口↑*********************************************/
//———————————————————————————————————————————————————-//



/**********************************↓测试模块，检验功能是否正常↓*****************************************/


void LASTBALL_TEXT(const Simuro::Field& field)
{


    std::fstream file;

    //create a Txt field named ShowData_TXT,if tick >= 2
    if (field.tick < 3) {
        file.open("./LASTBALL.txt", std::fstream::out);
        file << "——————-———创建成功-—————————" << std::endl;
        file << "——————-——FIRA比赛数据——————-——" << std::endl << "\n";
    }
    else
        file.open("./LASTBALL.txt", std::fstream::app);


    //Determine whether the file is created successfully 
    //If successful, continue the file 
    if (file.is_open()) {
        file.setf(std::ios::fixed);
        file.setf(std::ios::showpoint);
        size_t countR = 0;    
        file << "周期" << field.tick << std::endl;
        for (const auto &n : LASTBALL) {
            file << "LASTBALL\t" << countR << "\t(" << n.x << ","
                << n.y << ")\n" << std::endl;
            countR++;
        }

        file << "预测球坐标是\t" << "(" << Will_Ball_x << "," << Will_Ball_y << ")" << std::endl;

    }


    file.close();  //关闭文件流
}

void trry(Simuro::Field& field)
{

    /*MY_R_TO[2].x = -72.f;
    MY_R_TO[2].y = -72.f;
    MoveTo(2, field);*/
    
    MY_R_TO[1].x = -10002.f;
    MY_R_TO[1].y = -12.f;
    MoveTo(1, field);
    
  

    Go1(field.selfRobots[1], Ball_x, Ball_y);

    //Go1(field.selfRobots[1], Will_Ball_x, Will_Ball_y);

    //Go1(field.selfRobots[3], OPPR_POS[0].x, OPPR_POS[0].y);

    //Go1(field.selfRobots[1], OPPR_POS[0].x, OPPR_POS[0].y);

}



/**********************************↑测试模块，检验功能是否正常↑*****************************************/
//———————————————————————————————————————————————————-//



/**********************************↓编写你的策略，成为强大的球队↓***************************************/
//——————————————————————10号 Messi————————————————————————-//















/**********************************↑编写你的策略，成为强大的球队↑***************************************/

