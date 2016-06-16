#ifndef _input_H
#define _input_H

#include "egg.h"
#include "dataProcessor.h"
#define EGG_LENGTH 1300
#define EGG_WIDTH 800
#define INPUT_LEFT_UP_X 10//输入框左上角x
#define INPUT_LEFT_UP_Y 200//输入框左上角y
#define INPUT_RIGHT_DOWN_X 1290//输入框右下角x
#define INPUT_RIGHT_DOWN_Y 10//输入框右下角y
#define DISTANCE 2//字与框，行与行的间距
#define PASS_LEFT_UP_X 970//按钮框左上角x
#define PASS_LEFT_UP_Y 80//按钮框左上角y
#define PASS_RIGHT_DOWN_X 1290//按钮框右下角x
#define PASS_RIGHT_DOWN_Y 10//按钮框右下角y

extern Button buttonA, buttonB, buttonC, buttonDetected;

void inputControlFun(void);//输入界面总调度函数
void createInputFrame(double x1,double y1,double x2,double y2, double distance);//画输入信息框函数
double showDeleteInput(double x1, double y1, double x2, double y2, double distance,char* string,int k);//界面输入呈现函数
void passSelectInit(double x1,double y1,double x2,double y2);//判断通行的函数
void confirmComplete(double x1, double y1, double x2, double y2);//确认完成按钮函数
void isDefault(double x1, double y1, double x2, double y2);//是否使用默认配置函数
void Switch(void);
extern HEGG EggSwitch;

#endif // _input_H
