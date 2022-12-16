#include"data.h"
#include<fstream>

extern float Ball_x = 0.0f;

extern float Ball_y = 0.0f;




const float Diss(const float x1, const float y1, const float x2, const float y2)noexcept
{
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

const float Diss(const Simuro::Robot &robot, const float x2, const float y2)noexcept
{
    return Diss(robot.position.x, robot.position.y, x2, y2);
}

const float Angle(const Simuro::Robot &robot, float x, float y)
{
    return Angle(robot.position.x, robot.position.y, x, y);
}

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



void UpdateInformation(const Simuro::Field& field)
{

    //�����������X��Y
    //Update the coordinate information X and Y of the sphere
    Ball_x = field.ball.position.x;
    Ball_y = field.ball.position.y;


 

}


void ShowData_TXT(const Simuro::Field& field)
{


    std::fstream file;
    
    //create a Txt field named ShowData_TXT,if tick >= 2
    if (field.tick < 3) {
        file.open("./ShowData_TXT.txt", std::fstream::out);
        file << "������������-�����������ɹ�-������������������" << std::endl;
        file << "������������-����FIRA�������ݡ�����������-����" << std::endl << "\n";
    }
    else
        file.open("./ShowData_TXT.txt", std::fstream::app);


    //Determine whether the file is created successfully 
    //If successful, continue the file 
    if (file.is_open()) {
        file.setf(std::ios::fixed);
        file.setf(std::ios::showpoint);
        size_t countR = 0;

        file << "������������-��������ǰ��" << field.tick << "���ڡ�����������-������\n" << std::endl;
        for (const auto &n : field.selfRobots) {
            file << "�� �ҷ�" << countR << "�Ż����˵���Ϣ" << std::endl;
            file << "( " << n.position.x << ", " << n.position.y << ")\t"
                << "rotation:" << n.rotation << "\n" << std::endl;
            file << "left_peed:" << n.wheel.leftSpeed << "\t" 
                << "right_peed:" << n.wheel.rightSpeed << std::endl;
            countR++;
        }

        countR = 0;
        for (const auto& n : field.opponentRobots) {
            file << "\n�� �з�" << countR << "�Ż����˵���Ϣ" << std::endl;
            file << "( " << n.position.x << ", " << n.position.y << ")\t"
                << "rotation:" << n.rotation << "\n" << std::endl;
            file << "left_peed:" << n.wheel.leftSpeed << "\t"
                << "right_peed:" << n.wheel.rightSpeed << std::endl;
            countR++;
        }

        file << "������������-���������� "<< field.tick <<"������������������������\n" << std::endl;





        file.close();  //�ر��ļ���
    }



}


/* ���ݲ��Ե���
    1 ������� OK
    2 �򻯵���Ŀ��� OK
    3 MoveTo��λ������Ч OK

*/




