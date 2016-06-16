#ifndef _input_H
#define _input_H

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

extern Button buttonA, buttonB, buttonC, buttonDetected;

void inputControlFun(void);//��������ܵ��Ⱥ���
void createInputFrame(double x1,double y1,double x2,double y2, double distance);//��������Ϣ����
double showDeleteInput(double x1, double y1, double x2, double y2, double distance,char* string,int k);//����������ֺ���
void passSelectInit(double x1,double y1,double x2,double y2);//�ж�ͨ�еĺ���
void confirmComplete(double x1, double y1, double x2, double y2);//ȷ����ɰ�ť����
void isDefault(double x1, double y1, double x2, double y2);//�Ƿ�ʹ��Ĭ�����ú���
void Switch(void);
extern HEGG EggSwitch;

#endif // _input_H
