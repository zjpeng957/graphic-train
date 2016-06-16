#ifndef DATAPROCESSOR_H_INCLUDED
#define DATAPROCESSOR_H_INCLUDED

#include "egg.h"
//�����õ�Ĭ�ϲ���
#define SPEED 3.0//��Ĭ���ٶ�
#define POSITION 0.0//Ĭ������λ��
#define TIME 4.0//Ĭ������ʱ��
#define CLWISE 1//˳ʱ�루Ĭ�ϣ�
#define ANTICLWISE 0//��ʱ��
#define TRACKLEN 24.0//Ĭ�Ϲ������
#define FAST 1
#define SLOW 2
#define HALFWIDTH 25
#define HALFLENGTH 25
#define INTERVAL 100.0

//��״̬
#define S1 1//����-�ǹ������
#define S2 2//����-�������
#define S3 3//��ͣ-�ǹ������
#define S4 4//ͣ��-�������
#define S5 5//��ͣ-�ȴ��������

typedef struct button{
    double X1;//��ť���Ͻǵ�X����
    double Y1;//��ť�����Ͻ�Y����
    double X2;//��ť�����½�X����
    double Y2;//��ť�����½�Y����
} Button;

//�洢����Ϣ�Ľṹ��
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

//�洢�����𳵵Ľṹ��
extern Train trainA,trainB,trainC;
//�ֱ����������������յ�
extern double a1_in,a1_out,a2_in,a2_out,b_in,b_out,c_in,c_out;
extern int aPos;
extern double A1[2],A2[2],B1[2],B2[2],C1[2],C2[2];//���������������
extern int a,b;//�������

//�ƶ��𳵵���һλ�ã���run������ʼʱ����
void move(Train *train);

//��ʱ,״̬ת�����������
void timeout(double time);

//ģ��𳵵�����,ʵ�ֻ𳵵�״̬Ǩ�ƣ��û��������ʼ��Ϣ�����
void run(void);

//�ж������𳵽��빫����������г�Ҫ���빫�����ʱ����
void judge(void);
void runA();
void runB();
void runC();

#endif // DATAPROCESSOR_H_INCLUDED
