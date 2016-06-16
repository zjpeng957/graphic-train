#ifndef DATAPROCESSOR_H_INCLUDED
#define DATAPROCESSOR_H_INCLUDED

#include "egg.h"
//火车配置的默认参数
#define SPEED 3.0//火车默认速度
#define POSITION 0.0//默认启动位置
#define TIME 4.0//默认启动时间
#define CLWISE 1//顺时针（默认）
#define ANTICLWISE 0//逆时针
#define TRACKLEN 24.0//默认轨道长度
#define FAST 1
#define SLOW 2
#define HALFWIDTH 25
#define HALFLENGTH 25
#define INTERVAL 100.0

//火车状态
#define S1 1//运行-非公共轨道
#define S2 2//运行-公共轨道
#define S3 3//暂停-非公共轨道
#define S4 4//停靠-公共轨道
#define S5 5//暂停-等待公共轨道

typedef struct button{
    double X1;//按钮左上角的X坐标
    double Y1;//按钮的左上角Y坐标
    double X2;//按钮的右下角X坐标
    double Y2;//按钮的右下角Y坐标
} Button;

//存储火车信息的结构体
typedef struct train{
    double speed;
    double position;
    double time;
    int direction;
    double trackLen;
    double restTime;
    int state;
    int detected;
    int type;
    double PosX;
    double PosY;
    double LeftX;
    double LeftY;
    double RightX;
    double RightY;
    int flag;
    HEGG Egg;
    Button Switch;
} Train;

typedef struct point{
    double x;
    double y;
} Point;

//存储三辆火车的结构。
extern Train trainA,trainB,trainC;
//分别代表公共轨道的起点和终点
extern double a1_in,a1_out,a2_in,a2_out,b_in,b_out,c_in,c_out;
extern int aPos;
extern double A1[2],A2[2],B1[2],B2[2],C1[2],C2[2];//轨道左上右下坐标
extern int a,b;//长宽比例

//移动火车到下一位置，在run函数开始时调用
void move(Train *train);

//计时,状态转换结束后调用
void timeout(double time);

//模拟火车的运行,实现火车的状态迁移，用户设置完初始信息后调用
void run(void);

//判断哪辆火车进入公共轨道，当有车要进入公共轨道时调用
void judge(void);
void runA();
void runB();
void runC();

#endif // DATAPROCESSOR_H_INCLUDED
