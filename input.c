#include<stdio.h>
#include<stdlib.h>
#include"dataProcessor.h"
#include "egg.h"
#include "dataProcessor.h"
#define EGG_LENGTH 1300
#define EGG_WIDTH 800
#define INPUT_LEFT_UP_X 10//��������Ͻ�x
#define INPUT_LEFT_UP_Y 200//��������Ͻ�y
#define INPUT_RIGHT_DOWN_X 1290//��������½�x
#define INPUT_RIGHT_DOWN_Y 10//��������½�y
#define DISTANCE 2//����������еļ��
#define PASS_LEFT_UP_X 970//��ť�����Ͻ�x
#define PASS_LEFT_UP_Y 80//��ť�����Ͻ�y
#define PASS_RIGHT_DOWN_X 1290//��ť�����½�x
#define PASS_RIGHT_DOWN_Y 10//��ť�����½�y

Button buttonA, buttonB, buttonC, buttonDetected;
HEGG EggSwitch,EggBottom;

void inputControlFun(void);
void createInputFrame(double x1,double y1,double x2,double y2, double distance);
double showDeleteInput(double x1, double y1, double x2, double y2, double distance,char* string,int k);
void passSelectInit(double x1,double y1,double x2,double y2);
void confirmComplete(double x1, double y1, double x2, double y2);
void isDefault(double x1, double y1, double x2, double y2);

//int main(void)
void inputControlFun(void)//��������ܵ��Ⱥ���
{
    //EggStart(EGG_LENGTH,EGG_WIDTH);
    isDefault(320, 400, 900, 250);//�Ƿ�Ĭ������
    passSelectInit(PASS_LEFT_UP_X, PASS_LEFT_UP_Y, PASS_RIGHT_DOWN_X, PASS_RIGHT_DOWN_Y);//ѡ��ͨ����������������
    //WaitForExit();
    //return 0;
}

void createInputFrame(double x1, double y1, double x2, double y2, double distance)//��������Ϣ����
{
    double bytes;
    double lineDistance=1;
    bytes=GetStringWidth("��");
    MovePen(x1,y1);
    /*���������*/
    DrawLine(x2-x1,0);
    DrawLine(0,y2-y1);
    DrawLine(x1-x2,0);
    DrawLine(0,y1-y2);
    /*������*/
    MovePen(x1+(x2-x1)/4,y1);
    DrawLine(0,y2-y1);
    MovePen(x1+(x2-x1)*2/4,y1);
    DrawLine(0,y2-y1);
    MovePen(x1+(x2-x1)*3/4,y1);
    DrawLine(0,y2-y1);
    //A��
    MovePen(x1+distance,y1-distance);
    DrawString("A����Ϣ��");
    MovePen(x1+distance,y1-2*distance-bytes);
    DrawString("�����ͣ�1��ʾ�쳵��2��ʾ��������");
    OffsetPen(0,-bytes-lineDistance);
    DrawLine(50,0);

    MovePen(x1+distance,y1-3*distance-2*bytes);
    DrawString("���ٶȣ�m/s����0��10����");
    OffsetPen(0,-bytes-lineDistance);
    DrawLine(50,0);

    MovePen(x1+distance,y1-4*distance-3*bytes);
    DrawString("����˳ʱ��Ϊ1����ʱ��Ϊ-1����");
    OffsetPen(0,-bytes-lineDistance);
    DrawLine(50,0);

    MovePen(x1+distance,y1-5*distance-4*bytes);
    DrawString("������ȣ�m����0��100����");
    OffsetPen(0,-bytes-lineDistance);
    DrawLine(50,0);

    MovePen(x1+distance,y1-6*distance-5*bytes);
    DrawString("��ʼλ��(0���������)��");
    OffsetPen(0,-bytes-lineDistance);
    DrawLine(50,0);

    MovePen(x1+distance,y1-7*distance-6*bytes);
    DrawString("����ʱ�䣨�ӳ���ʼ������/s����");
    OffsetPen(0,-bytes-lineDistance);
    DrawLine(50,0);

    MovePen(x1+distance,y1-8*distance-7*bytes);
    DrawString("�������ͣ��ʱ�䣺");
    OffsetPen(0,-bytes-lineDistance);
    DrawLine(50,0);

    //B��
    MovePen(x1+(x2-x1)/4+distance,y1-distance);
    DrawString("B����Ϣ��");
    MovePen(x1+(x2-x1)/4+distance,y1-2*distance-bytes);
    DrawString("�����ͣ�1��ʾ�쳵��2��ʾ��������");
    OffsetPen(0,-bytes-lineDistance);
    DrawLine(50,0);

    MovePen(x1+(x2-x1)/4+distance,y1-3*distance-2*bytes);
    DrawString("���ٶȣ�m/s����0��10����");
    OffsetPen(0,-bytes-lineDistance);
    DrawLine(50,0);

    MovePen(x1+(x2-x1)/4+distance,y1-4*distance-3*bytes);
    DrawString("����˳ʱ��Ϊ1����ʱ��Ϊ-1����");
    OffsetPen(0,-bytes-lineDistance);
    DrawLine(50,0);

    MovePen(x1+(x2-x1)/4+distance,y1-5*distance-4*bytes);
    DrawString("������ȣ�m����0��100����");
    OffsetPen(0,-bytes-lineDistance);
    DrawLine(50,0);

    MovePen(x1+(x2-x1)/4+distance,y1-6*distance-5*bytes);
    DrawString("��ʼλ��(0���������)��");
    OffsetPen(0,-bytes-lineDistance);
    DrawLine(50,0);

    MovePen(x1+(x2-x1)/4+distance,y1-7*distance-6*bytes);
    DrawString("����ʱ�䣨�ӳ���ʼ������/s����");
    OffsetPen(0,-bytes-lineDistance);
    DrawLine(50,0);

    MovePen(x1+(x2-x1)/4+distance,y1-8*distance-7*bytes);
    DrawString("�������ͣ��ʱ�䣺");
    OffsetPen(0,-bytes-lineDistance);
    DrawLine(50,0);

    //C��
    MovePen(x1+(x2-x1)*2/4+distance,y1-distance);
    DrawString("C����Ϣ��");
    MovePen(x1+(x2-x1)*2/4+distance,y1-2*distance-bytes);
    DrawString("�����ͣ�1��ʾ�쳵��2��ʾ��������");
    OffsetPen(0,-bytes-lineDistance);
    DrawLine(50,0);

    MovePen(x1+(x2-x1)*2/4+distance,y1-3*distance-2*bytes);
    DrawString("���ٶȣ�m/s����0��10����");
    OffsetPen(0,-bytes-lineDistance);
    DrawLine(50,0);

    MovePen(x1+(x2-x1)*2/4+distance,y1-4*distance-3*bytes);
    DrawString("����˳ʱ��Ϊ1����ʱ��Ϊ-1����");
    OffsetPen(0,-bytes-lineDistance);
    DrawLine(50,0);

    MovePen(x1+(x2-x1)*2/4+distance,y1-5*distance-4*bytes);
    DrawString("������ȣ�m����0��100����");
    OffsetPen(0,-bytes-lineDistance);
    DrawLine(50,0);

    MovePen(x1+(x2-x1)*2/4+distance,y1-6*distance-5*bytes);
    DrawString("��ʼλ��(0���������)��");
    OffsetPen(0,-bytes-lineDistance);
    DrawLine(50,0);

    MovePen(x1+(x2-x1)*2/4+distance,y1-7*distance-6*bytes);
    DrawString("����ʱ�䣨�ӳ���ʼ������/s����");
    OffsetPen(0,-bytes-lineDistance);
    DrawLine(50,0);

    MovePen(x1+(x2-x1)*2/4+distance,y1-8*distance-7*bytes);
    DrawString("�������ͣ��ʱ�䣺");
    OffsetPen(0,-bytes-lineDistance);
    DrawLine(50,0);

    //̽���
    MovePen(x1+(x2-x1)*3/4+distance,y1-distance);
    DrawString("̽�����Ϣ��");
    MovePen(x1+(x2-x1)*3/4+distance,y1-2*distance-bytes);
    DrawString("A����B������A�������̽��㣺");
    OffsetPen(0,-bytes-lineDistance);
    DrawLine(50,0);

    MovePen(x1+(x2-x1)*3/4+distance,y1-3*distance-2*bytes);
    DrawString("A����B������A���ĳ���̽��㣺");
    OffsetPen(0,-bytes-lineDistance);
    DrawLine(50,0);

    MovePen(x1+(x2-x1)*3/4+distance,y1-4*distance-3*bytes);
    DrawString("A����B������B�������̽��㣺");
    OffsetPen(0,-bytes-lineDistance);
    DrawLine(50,0);

    MovePen(x1+(x2-x1)*3/4+distance,y1-5*distance-4*bytes);
    DrawString("A����B������B���ĳ���̽��㣺");
    OffsetPen(0,-bytes-lineDistance);
    DrawLine(50,0);

    MovePen(x1+(x2-x1)*3/4+distance,y1-6*distance-5*bytes);
    DrawString("A����C������A�������̽��㣺");
    OffsetPen(0,-bytes-lineDistance);
    DrawLine(50,0);

    MovePen(x1+(x2-x1)*3/4+distance,y1-7*distance-6*bytes);
    DrawString("A����C������A���ĳ���̽��㣺");
    OffsetPen(0,-bytes-lineDistance);
    DrawLine(50,0);

    MovePen(x1+(x2-x1)*3/4+distance,y1-8*distance-7*bytes);
    DrawString("A����C������C�������̽��㣺");
    OffsetPen(0,-bytes-lineDistance);
    DrawLine(50,0);

    MovePen(x1+(x2-x1)*3/4+distance,y1-9*distance-8*bytes);
    DrawString("A����C������C���ĳ���̽��㣺");
    OffsetPen(0,-bytes-lineDistance);
    DrawLine(50,0);
}


double showDeleteInput(double x1, double y1, double x2, double y2, double distance,char* string,int k)//����������ֺ���
{
    char strForInput[200]={'\0'};//���������ַ����ַ�����
    char spaceStrForInput[200]={'\0'};//�����������Ŀհ��ַ�����
    int cntForInput=0;//�������
    double save;//�������ַ����ĸ�����
    double bytes=GetStringWidth("��");
    int j,i;
    double X1,Y1,X2,Y2;//���浱ǰ������Ͻ���������½�����
    double X,Y;//��ȡ��������
    X1=x1+distance+GetStringWidth(string);//����X
    Y1=y1-(k+1)*distance-k*bytes;//����Y
    X2=x1+distance+GetStringWidth(string)+50;//����X
    Y2=y1-(k+2)*distance-(k+1)*bytes;//����Y
    for(i=0;i<15;i++)//��ʼ������ַ�
    {
        spaceStrForInput[i]=' ';
    }
    while(1)
    {
        while(!(WaitForEvent()==KEYDOWN)){}//��δ���� KEYDOWN�¼�������������������������ʲô��������
        if(GetStruckKey() == VK_LBUTTON)//�����������������ģʽ
        {
            X = GetMouseX();
            Y = GetMouseY();
            if((X >= X1 && X <= X2) && (Y >= Y2 && Y <= Y1))//����������涨�ķ�Χ��
                {
                    //�����û����룬����Escʱ�˳�����
                    while(1)
                    {
                        while(!(WaitForEvent() == KEYDOWN)) {}//�Ǽ��̺��������ʱʲô������
                        strForInput[cntForInput] = GetStruckKey();
                        if(strForInput[cntForInput]==-67||strForInput[cntForInput]==VK_SUBTRACT)//ʹ�������븺��
                            strForInput[cntForInput]='-';
                        else if(strForInput[cntForInput]==VK_NUMPAD1)//С��������
                            strForInput[cntForInput]='1';
                        else if(strForInput[cntForInput]==VK_NUMPAD2)
                            strForInput[cntForInput]='2';
                        else if(strForInput[cntForInput]==VK_NUMPAD3)
                            strForInput[cntForInput]='3';
                        else if(strForInput[cntForInput]==VK_NUMPAD4)
                            strForInput[cntForInput]='4';
                        else if(strForInput[cntForInput]==VK_NUMPAD5)
                            strForInput[cntForInput]='5';
                        else if(strForInput[cntForInput]==VK_NUMPAD6)
                            strForInput[cntForInput]='6';
                        else if(strForInput[cntForInput]==VK_NUMPAD7)
                            strForInput[cntForInput]='7';
                        else if(strForInput[cntForInput]==VK_NUMPAD8)
                            strForInput[cntForInput]='8';
                        else if(strForInput[cntForInput]==VK_NUMPAD9)
                            strForInput[cntForInput]='9';
                        else if(strForInput[cntForInput]==VK_NUMPAD0)
                            strForInput[cntForInput]='0';
                        if( strForInput[cntForInput] == VK_ESCAPE )//������ESC��ʱ�˳�����ģʽ
                        {
                            break;
                        }
                        else
                        {
                            MovePen(X1,Y1);
                            DrawString(strForInput);//��ʾ�ַ���
                        }
                        cntForInput++;
                    }
                    cntForInput = 0;
                    save=atof(strForInput);
                    for(j = 0; j < 200; ++j) strForInput[j] = '\0';
                    printf("input\n");//����ģʽ��ɺ����input����
                }
        }
        else if(GetStruckKey() == VK_BACK)//��������Backspace����ַ�
        {
            X = GetMouseX();
            Y = GetMouseY();
            if((X >= X1 && X <= X2) && (Y >= Y2 && Y <= Y1))	//input��ť������
                {
                    MovePen(X1,Y1);
                    DrawString(spaceStrForInput);
                    printf("clear\n");//�����ɺ����clear����

                }
        }
        if(GetStruckKey()==VK_RBUTTON)//�������м����������
        {
            printf("complete\n");
            break;
        }

    }
    return save;
}

void passSelectInit(double x1,double y1,double x2,double y2)  //�ж�ͨ�еĺ���
{
    double distance1;//y��ļ��
    double distance2;//x��ļ��
    MovePen(x1,y1);
    /*���������*/
    DrawLine(x2-x1,0);
    DrawLine(0,y2-y1);
    DrawLine(x1-x2,0);
    DrawLine(0,y1-y2);
    MovePen(x1,y1-30);
    DrawLine(x2-x1,0);
    //����ť˵����
    MovePen(x1+(x2-x1)/4,y1-30);//30�ǰ�ť˵���Ŀ��
    DrawLine(0,y2-y1+30);
    MovePen(x1+(x2-x1)*2/4,y1-30);
    DrawLine(0,y2-y1+30);
    MovePen(x1+(x2-x1)*3/4,y1-30);
    DrawLine(0,y2-y1+30);
    distance1=(30-GetStringWidth("��"))/2;
    distance2=(x2-x1-GetStringWidth("�ж�ͨ�а�ť"))/2;
    MovePen(x1+distance2,y1-distance1);
    DrawString("�ж�ͨ�а�ť");
    //A��ť
    distance1=(y1-y2-30-GetStringWidth("��"))/2;
    distance2=((x2-x1)/4-GetStringWidth("A��"))/2;
    MovePen(x1+distance2,y1-30-distance1);
    DrawString("A��");
    buttonA.X1=x1;
    buttonA.Y1=y1-30;
    buttonA.X2=x1+(x2-x1)/4;
    buttonA.Y2=y2;
    //B��ť
    distance1=(y1-y2-30-GetStringWidth("��"))/2;
    distance2=((x2-x1)/4-GetStringWidth("B��"))/2;
    MovePen(x1+(x2-x1)/4+distance2,y1-30-distance1);
    DrawString("B��");
    buttonB.X1=x1+(x2-x1)/4;
    buttonB.Y1=y1-30;
    buttonB.X2=x1+(x2-x1)*2/4;
    buttonB.Y2=y2;
    //C��ť
    distance1=(y1-y2-30-GetStringWidth("��"))/2;
    distance2=((x2-x1)/4-GetStringWidth("C��"))/2;
    MovePen(x1+(x2-x1)*2/4+distance2,y1-30-distance1);
    DrawString("C��");
    buttonC.X1=x1+(x2-x1)*2/4;
    buttonC.Y1=y1-30;
    buttonC.X2=x1+(x2-x1)*3/4;
    buttonC.Y2=y2;
    //�������水ť
    distance1=(y1-y2-30-GetStringWidth("��"))/2;
    distance2=((x2-x1)/4-GetStringWidth("��������"))/2;
    MovePen(x1+(x2-x1)*3/4+distance2,y1-30-distance1);
    DrawString("��������");
    buttonDetected.X1=x1+(x2-x1)*3/4;
    buttonDetected.Y1=y1-30;
    buttonDetected.X2=x2;
    buttonDetected.Y2=y2;

}

void confirmComplete(double x1, double y1, double x2, double y2)//ȷ����ɰ�ť����
{
    MovePen(x1,y1);
    DrawLine(x2-x1,0);
    DrawLine(0,y2-y1);
    DrawLine(x1-x2,0);
    DrawLine(0,y1-y2);
    double distance1;
    double distance2;
    double X,Y;
    SetPenColor(RED);
    distance1=(x2-x1-GetStringWidth("�������"))/2;
    distance2=(y1-y2-GetStringWidth("��"))/2;
    MovePen(x1+distance1,y1-distance2);
    DrawString("�������");
    SetPenColor(BLACK);
    while(1)
    {
        while(!(WaitForEvent()==KEYDOWN)){}
        if(GetStruckKey() == VK_LBUTTON)
        {
            X = GetMouseX();
            Y = GetMouseY();
            if((X >= x1 && X <= x2) && (Y >= y2 && Y <= y1))//����������涨�ķ�Χ��
            {
                EatEgg();//�Ե���ɼ�����Ϣ�����ĵ�
                break;
            }
        }
    }

}


void isDefault(double x1, double y1, double x2, double y2)//�Ƿ�ʹ��Ĭ�����ú���
{
    LayEgg();//�Ƿ�ĵ�
    int i;
    double parameter;
    double distance1;
    double distance2;
    MovePen(x1+235,y1+20);
    DrawString("�Ƿ�ʹ��Ĭ������");
    MovePen(x1,y1);
    DrawLine(x2-x1,0);
    DrawLine(0,y2-y1);
    DrawLine(x1-x2,0);
    DrawLine(0,y1-y2);
    MovePen(x1+(x2-x1)/2,y1);
    DrawLine(0,y2-y1);
    distance1=((x2-x1)/2-GetStringWidth("��"))/2;
    distance2=(y1-y2-GetStringWidth("��"))/2;
    MovePen(x1+distance1,y1-distance2);
    DrawString("��");
    MovePen(x1+(x2-x1)/2+distance1,y1-distance2);
    DrawString("��");
    double X,Y;
    while(1)
    {
        while(!(WaitForEvent()==KEYDOWN)){}
        if(GetStruckKey() == VK_LBUTTON)
        {
            X = GetMouseX();
            Y = GetMouseY();
            if((X >= x1 && X <= x1+(x2-x1)/2) && (Y >= y2 && Y <= y1))//����������涨�ķ�Χ��
            {
                printf("ʹ��Ĭ������\n");
                EatEgg();
                break;
            }
            else if((X > x1+(x2-x1)/2 && X <= x2) && (Y >= y2 && Y <= y1))
            {
                printf("��ʹ��Ĭ������\n\n");
                printf("�������ʹ�÷������£�\n");
                printf("1. ������ʱӦһ��һ��һ�����롣\n");
                printf("2. ���������Ϊ����ģʽ������BackspaceΪ���ģʽ������Ҽ�Ϊȷ��ģʽ��\n");
                printf("3. ��������ģʽ��������Ӧ�����ֺ󣬵��ESC�����˳�����ģʽ����ʱ������Ӧ������Backspace����������Ӧ���֣�\n   �ٴ��������ϡ��������Ҽ�����������ɽ�����һ������롣\n");
                printf("4. ��ȫ����Ϣ������ɺ󣬻������ɰ�ť����������������Ϣ���롣\n");
                EatEgg();
                LayEgg();
                createInputFrame(INPUT_LEFT_UP_X, INPUT_LEFT_UP_Y, INPUT_RIGHT_DOWN_X, INPUT_RIGHT_DOWN_Y, DISTANCE);//����������Ϣ��
                printf("\n���濪ʼ����A����Ϣ��\n");
                for(i=1;i<=7;i++)//����A����Ϣ������
                {   //parameter=0,ʡ����
                    switch(i)
                    {
                        case 1:trainA.type = (int)showDeleteInput(INPUT_LEFT_UP_X, INPUT_LEFT_UP_Y, INPUT_RIGHT_DOWN_X, INPUT_RIGHT_DOWN_Y, DISTANCE,"�����ͣ�1��ʾ�쳵��2��ʾ��������",i);break;
                        case 2:trainA.speed = showDeleteInput(INPUT_LEFT_UP_X, INPUT_LEFT_UP_Y, INPUT_RIGHT_DOWN_X, INPUT_RIGHT_DOWN_Y, DISTANCE,"���ٶȣ�m/s����0��10����",i);break;
                        case 3:trainA.direction = (int)showDeleteInput(INPUT_LEFT_UP_X, INPUT_LEFT_UP_Y, INPUT_RIGHT_DOWN_X, INPUT_RIGHT_DOWN_Y, DISTANCE,"����˳ʱ��Ϊ1����ʱ��Ϊ-1����",i);break;
                        case 4:trainA.trackLen = showDeleteInput(INPUT_LEFT_UP_X, INPUT_LEFT_UP_Y, INPUT_RIGHT_DOWN_X, INPUT_RIGHT_DOWN_Y, DISTANCE,"������ȣ�m����0��100����",i);break;
                        case 5:trainA.position = showDeleteInput(INPUT_LEFT_UP_X, INPUT_LEFT_UP_Y, INPUT_RIGHT_DOWN_X, INPUT_RIGHT_DOWN_Y, DISTANCE,"��ʼλ��(0���������)��",i);break;
                        case 6:trainA.time = showDeleteInput(INPUT_LEFT_UP_X, INPUT_LEFT_UP_Y, INPUT_RIGHT_DOWN_X, INPUT_RIGHT_DOWN_Y, DISTANCE,"����ʱ�䣨�ӳ���ʼ������/s����",i);break;
                        case 7:trainA.restTime = showDeleteInput(INPUT_LEFT_UP_X, INPUT_LEFT_UP_Y, INPUT_RIGHT_DOWN_X, INPUT_RIGHT_DOWN_Y, DISTANCE,"�������ͣ��ʱ�䣺",i);break;
                    }
                }
                printf("A����Ϣ�Ѿ�������ɡ�\n");

                printf("���濪ʼ����B����Ϣ��\n");
                for(i=1;i<=7;i++)//����B����Ϣ������
                {
                    parameter=(INPUT_RIGHT_DOWN_X-INPUT_LEFT_UP_X)/4;
                    switch(i)
                    {
                        case 1:trainB.type = (int)showDeleteInput(INPUT_LEFT_UP_X+parameter, INPUT_LEFT_UP_Y, INPUT_RIGHT_DOWN_X, INPUT_RIGHT_DOWN_Y, DISTANCE,"�����ͣ�1��ʾ�쳵��2��ʾ��������",i);break;
                        case 2:trainB.speed = showDeleteInput(INPUT_LEFT_UP_X+parameter, INPUT_LEFT_UP_Y, INPUT_RIGHT_DOWN_X, INPUT_RIGHT_DOWN_Y, DISTANCE,"���ٶȣ�m/s����0��10����",i);break;
                        case 3:trainB.direction = (int)showDeleteInput(INPUT_LEFT_UP_X+parameter, INPUT_LEFT_UP_Y, INPUT_RIGHT_DOWN_X, INPUT_RIGHT_DOWN_Y, DISTANCE,"����˳ʱ��Ϊ1����ʱ��Ϊ-1����",i);break;
                        case 4:trainB.trackLen = showDeleteInput(INPUT_LEFT_UP_X+parameter, INPUT_LEFT_UP_Y, INPUT_RIGHT_DOWN_X, INPUT_RIGHT_DOWN_Y, DISTANCE,"������ȣ�m����0��100����",i);break;
                        case 5:trainB.position = showDeleteInput(INPUT_LEFT_UP_X+parameter, INPUT_LEFT_UP_Y, INPUT_RIGHT_DOWN_X, INPUT_RIGHT_DOWN_Y, DISTANCE,"��ʼλ��(0���������)��",i);break;
                        case 6:trainB.time = showDeleteInput(INPUT_LEFT_UP_X+parameter, INPUT_LEFT_UP_Y, INPUT_RIGHT_DOWN_X, INPUT_RIGHT_DOWN_Y, DISTANCE,"����ʱ�䣨�ӳ���ʼ������/s����",i);break;
                        case 7:trainB.restTime = showDeleteInput(INPUT_LEFT_UP_X+parameter, INPUT_LEFT_UP_Y, INPUT_RIGHT_DOWN_X, INPUT_RIGHT_DOWN_Y, DISTANCE,"�������ͣ��ʱ�䣺",i);break;
                    }
                }
                printf("B����Ϣ�Ѿ�������ɡ�\n");

                printf("���濪ʼ����C����Ϣ��\n");
                for(i=1;i<=7;i++)//����C����Ϣ������
                {
                    parameter=(INPUT_RIGHT_DOWN_X-INPUT_LEFT_UP_X)*2/4;
                    switch(i)
                    {
                        case 1:trainC.type = (int)showDeleteInput(INPUT_LEFT_UP_X+parameter, INPUT_LEFT_UP_Y, INPUT_RIGHT_DOWN_X, INPUT_RIGHT_DOWN_Y, DISTANCE,"�����ͣ�1��ʾ�쳵��2��ʾ��������",i);break;
                        case 2:trainC.speed = showDeleteInput(INPUT_LEFT_UP_X+parameter, INPUT_LEFT_UP_Y, INPUT_RIGHT_DOWN_X, INPUT_RIGHT_DOWN_Y, DISTANCE,"���ٶȣ�m/s����0��10����",i);break;
                        case 3:trainC.direction = (int)showDeleteInput(INPUT_LEFT_UP_X+parameter, INPUT_LEFT_UP_Y, INPUT_RIGHT_DOWN_X, INPUT_RIGHT_DOWN_Y, DISTANCE,"����˳ʱ��Ϊ1����ʱ��Ϊ-1����",i);break;
                        case 4:trainC.trackLen = showDeleteInput(INPUT_LEFT_UP_X+parameter, INPUT_LEFT_UP_Y, INPUT_RIGHT_DOWN_X, INPUT_RIGHT_DOWN_Y, DISTANCE,"������ȣ�m����0��100����",i);break;
                        case 5:trainC.position = showDeleteInput(INPUT_LEFT_UP_X+parameter, INPUT_LEFT_UP_Y, INPUT_RIGHT_DOWN_X, INPUT_RIGHT_DOWN_Y, DISTANCE,"��ʼλ��(0���������)��",i);break;
                        case 6:trainC.time = showDeleteInput(INPUT_LEFT_UP_X+parameter, INPUT_LEFT_UP_Y, INPUT_RIGHT_DOWN_X, INPUT_RIGHT_DOWN_Y, DISTANCE,"����ʱ�䣨�ӳ���ʼ������/s����",i);break;
                        case 7:trainC.restTime = showDeleteInput(INPUT_LEFT_UP_X+parameter, INPUT_LEFT_UP_Y, INPUT_RIGHT_DOWN_X, INPUT_RIGHT_DOWN_Y, DISTANCE,"�������ͣ��ʱ�䣺",i);break;
                    }
                }
                printf("C����Ϣ�Ѿ�������ɡ�\n");

                printf("���濪ʼ����̽�����Ϣ��\n");
                for(i=1;i<=8;i++)//����̽�����Ϣ������
                {
                    parameter=(INPUT_RIGHT_DOWN_X-INPUT_LEFT_UP_X)*3/4;
                    switch(i)
                    {
                        case 1:a1_in = showDeleteInput(INPUT_LEFT_UP_X+parameter, INPUT_LEFT_UP_Y, INPUT_RIGHT_DOWN_X, INPUT_RIGHT_DOWN_Y, DISTANCE,"A����B������A�������̽��㣺",i);break;
                        case 2:a1_out = showDeleteInput(INPUT_LEFT_UP_X+parameter, INPUT_LEFT_UP_Y, INPUT_RIGHT_DOWN_X, INPUT_RIGHT_DOWN_Y, DISTANCE,"A����B������A���ĳ���̽��㣺",i);break;
                        case 3:b_in = showDeleteInput(INPUT_LEFT_UP_X+parameter, INPUT_LEFT_UP_Y, INPUT_RIGHT_DOWN_X, INPUT_RIGHT_DOWN_Y, DISTANCE,"A����B������B�������̽��㣺",i);break;
                        case 4:b_out = showDeleteInput(INPUT_LEFT_UP_X+parameter, INPUT_LEFT_UP_Y, INPUT_RIGHT_DOWN_X, INPUT_RIGHT_DOWN_Y, DISTANCE,"A����B������B���ĳ���̽��㣺",i);break;
                        case 5:a2_in = showDeleteInput(INPUT_LEFT_UP_X+parameter, INPUT_LEFT_UP_Y, INPUT_RIGHT_DOWN_X, INPUT_RIGHT_DOWN_Y, DISTANCE,"A����C������A�������̽��㣺",i);break;
                        case 6:a2_out = showDeleteInput(INPUT_LEFT_UP_X+parameter, INPUT_LEFT_UP_Y, INPUT_RIGHT_DOWN_X, INPUT_RIGHT_DOWN_Y, DISTANCE,"A����C������A���ĳ���̽��㣺",i);break;
                        case 7:c_in = showDeleteInput(INPUT_LEFT_UP_X+parameter, INPUT_LEFT_UP_Y, INPUT_RIGHT_DOWN_X, INPUT_RIGHT_DOWN_Y, DISTANCE,"A����C������C�������̽��㣺",i);break;
                        case 8:c_out = showDeleteInput(INPUT_LEFT_UP_X+parameter, INPUT_LEFT_UP_Y, INPUT_RIGHT_DOWN_X, INPUT_RIGHT_DOWN_Y, DISTANCE,"A����C������C���ĳ���̽��㣺",i);break;
                    }
                }
                printf("̽�����Ϣ������ɣ�\n");
                printf("��������ϵ���ɼ�");
                confirmComplete(320, 400, 900, 250);
                EatEgg();
                break;
            }
        }

    }
}
void Switch(void)
{

    EggSwitch=LayEgg();

    MovePen(1150,400);
    trainA.Switch.X1=GetPenXPos();
    trainA.Switch.Y1=GetPenYPos();
    trainA.Switch.X2=trainA.Switch.X1+100;
    trainA.Switch.Y2=trainA.Switch.Y1-100;
    DrawBitmap("run.bmp");

    MovePen(1150,300);
    trainB.Switch.X1=GetPenXPos();
    trainB.Switch.Y1=GetPenYPos();
    trainB.Switch.X2=trainB.Switch.X1+100;
    trainB.Switch.Y2=trainB.Switch.Y1-100;
    DrawBitmap("run.bmp");

    MovePen(1150,200);
    trainC.Switch.X1=GetPenXPos();
    trainC.Switch.Y1=GetPenYPos();
    trainC.Switch.X2=trainC.Switch.X1+100;
    trainC.Switch.Y2=trainC.Switch.Y1-100;
    DrawBitmap("run.bmp");

    MovePen(1100,370);
    SetPenColor(RED);
    DrawString("A");
    MovePen(1100,270);
    SetPenColor(DARK_MAGENTA);
    DrawString("B");
    MovePen(1100,170);
    SetPenColor(BLUE);
    DrawString("C");

}













