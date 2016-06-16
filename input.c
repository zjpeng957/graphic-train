#include<stdio.h>
#include<stdlib.h>
#include"dataProcessor.h"
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

Button buttonA, buttonB, buttonC, buttonDetected;
HEGG EggSwitch,EggBottom;

void inputControlFun(void);
void createInputFrame(double x1,double y1,double x2,double y2, double distance);
double showDeleteInput(double x1, double y1, double x2, double y2, double distance,char* string,int k);
void passSelectInit(double x1,double y1,double x2,double y2);
void confirmComplete(double x1, double y1, double x2, double y2);
void isDefault(double x1, double y1, double x2, double y2);

//int main(void)
void inputControlFun(void)//输入界面总调度函数
{
    //EggStart(EGG_LENGTH,EGG_WIDTH);
    isDefault(320, 400, 900, 250);//是否默认配置
    passSelectInit(PASS_LEFT_UP_X, PASS_LEFT_UP_Y, PASS_RIGHT_DOWN_X, PASS_RIGHT_DOWN_Y);//选择通过函数，在主蛋中
    //WaitForExit();
    //return 0;
}

void createInputFrame(double x1, double y1, double x2, double y2, double distance)//画输入信息框函数
{
    double bytes;
    double lineDistance=1;
    bytes=GetStringWidth("火");
    MovePen(x1,y1);
    /*画输入外框*/
    DrawLine(x2-x1,0);
    DrawLine(0,y2-y1);
    DrawLine(x1-x2,0);
    DrawLine(0,y1-y2);
    /*画竖线*/
    MovePen(x1+(x2-x1)/4,y1);
    DrawLine(0,y2-y1);
    MovePen(x1+(x2-x1)*2/4,y1);
    DrawLine(0,y2-y1);
    MovePen(x1+(x2-x1)*3/4,y1);
    DrawLine(0,y2-y1);
    //A火车
    MovePen(x1+distance,y1-distance);
    DrawString("A火车信息：");
    MovePen(x1+distance,y1-2*distance-bytes);
    DrawString("火车类型（1表示快车，2表示慢车）：");
    OffsetPen(0,-bytes-lineDistance);
    DrawLine(50,0);

    MovePen(x1+distance,y1-3*distance-2*bytes);
    DrawString("火车速度（m/s）（0到10）：");
    OffsetPen(0,-bytes-lineDistance);
    DrawLine(50,0);

    MovePen(x1+distance,y1-4*distance-3*bytes);
    DrawString("方向（顺时针为1，逆时针为-1）：");
    OffsetPen(0,-bytes-lineDistance);
    DrawLine(50,0);

    MovePen(x1+distance,y1-5*distance-4*bytes);
    DrawString("轨道长度（m）（0到100）：");
    OffsetPen(0,-bytes-lineDistance);
    DrawLine(50,0);

    MovePen(x1+distance,y1-6*distance-5*bytes);
    DrawString("初始位置(0至轨道长度)：");
    OffsetPen(0,-bytes-lineDistance);
    DrawLine(50,0);

    MovePen(x1+distance,y1-7*distance-6*bytes);
    DrawString("启动时间（从程序开始运行起/s）：");
    OffsetPen(0,-bytes-lineDistance);
    DrawLine(50,0);

    MovePen(x1+distance,y1-8*distance-7*bytes);
    DrawString("公共轨道停留时间：");
    OffsetPen(0,-bytes-lineDistance);
    DrawLine(50,0);

    //B火车
    MovePen(x1+(x2-x1)/4+distance,y1-distance);
    DrawString("B火车信息：");
    MovePen(x1+(x2-x1)/4+distance,y1-2*distance-bytes);
    DrawString("火车类型（1表示快车，2表示慢车）：");
    OffsetPen(0,-bytes-lineDistance);
    DrawLine(50,0);

    MovePen(x1+(x2-x1)/4+distance,y1-3*distance-2*bytes);
    DrawString("火车速度（m/s）（0到10）：");
    OffsetPen(0,-bytes-lineDistance);
    DrawLine(50,0);

    MovePen(x1+(x2-x1)/4+distance,y1-4*distance-3*bytes);
    DrawString("方向（顺时针为1，逆时针为-1）：");
    OffsetPen(0,-bytes-lineDistance);
    DrawLine(50,0);

    MovePen(x1+(x2-x1)/4+distance,y1-5*distance-4*bytes);
    DrawString("轨道长度（m）（0到100）：");
    OffsetPen(0,-bytes-lineDistance);
    DrawLine(50,0);

    MovePen(x1+(x2-x1)/4+distance,y1-6*distance-5*bytes);
    DrawString("初始位置(0至轨道长度)：");
    OffsetPen(0,-bytes-lineDistance);
    DrawLine(50,0);

    MovePen(x1+(x2-x1)/4+distance,y1-7*distance-6*bytes);
    DrawString("启动时间（从程序开始运行起/s）：");
    OffsetPen(0,-bytes-lineDistance);
    DrawLine(50,0);

    MovePen(x1+(x2-x1)/4+distance,y1-8*distance-7*bytes);
    DrawString("公共轨道停留时间：");
    OffsetPen(0,-bytes-lineDistance);
    DrawLine(50,0);

    //C火车
    MovePen(x1+(x2-x1)*2/4+distance,y1-distance);
    DrawString("C火车信息：");
    MovePen(x1+(x2-x1)*2/4+distance,y1-2*distance-bytes);
    DrawString("火车类型（1表示快车，2表示慢车）：");
    OffsetPen(0,-bytes-lineDistance);
    DrawLine(50,0);

    MovePen(x1+(x2-x1)*2/4+distance,y1-3*distance-2*bytes);
    DrawString("火车速度（m/s）（0到10）：");
    OffsetPen(0,-bytes-lineDistance);
    DrawLine(50,0);

    MovePen(x1+(x2-x1)*2/4+distance,y1-4*distance-3*bytes);
    DrawString("方向（顺时针为1，逆时针为-1）：");
    OffsetPen(0,-bytes-lineDistance);
    DrawLine(50,0);

    MovePen(x1+(x2-x1)*2/4+distance,y1-5*distance-4*bytes);
    DrawString("轨道长度（m）（0到100）：");
    OffsetPen(0,-bytes-lineDistance);
    DrawLine(50,0);

    MovePen(x1+(x2-x1)*2/4+distance,y1-6*distance-5*bytes);
    DrawString("初始位置(0至轨道长度)：");
    OffsetPen(0,-bytes-lineDistance);
    DrawLine(50,0);

    MovePen(x1+(x2-x1)*2/4+distance,y1-7*distance-6*bytes);
    DrawString("启动时间（从程序开始运行起/s）：");
    OffsetPen(0,-bytes-lineDistance);
    DrawLine(50,0);

    MovePen(x1+(x2-x1)*2/4+distance,y1-8*distance-7*bytes);
    DrawString("公共轨道停留时间：");
    OffsetPen(0,-bytes-lineDistance);
    DrawLine(50,0);

    //探测点
    MovePen(x1+(x2-x1)*3/4+distance,y1-distance);
    DrawString("探测点信息：");
    MovePen(x1+(x2-x1)*3/4+distance,y1-2*distance-bytes);
    DrawString("A车、B车公轨A车的入口探测点：");
    OffsetPen(0,-bytes-lineDistance);
    DrawLine(50,0);

    MovePen(x1+(x2-x1)*3/4+distance,y1-3*distance-2*bytes);
    DrawString("A车、B车公轨A车的出口探测点：");
    OffsetPen(0,-bytes-lineDistance);
    DrawLine(50,0);

    MovePen(x1+(x2-x1)*3/4+distance,y1-4*distance-3*bytes);
    DrawString("A车、B车公轨B车的入口探测点：");
    OffsetPen(0,-bytes-lineDistance);
    DrawLine(50,0);

    MovePen(x1+(x2-x1)*3/4+distance,y1-5*distance-4*bytes);
    DrawString("A车、B车公轨B车的出口探测点：");
    OffsetPen(0,-bytes-lineDistance);
    DrawLine(50,0);

    MovePen(x1+(x2-x1)*3/4+distance,y1-6*distance-5*bytes);
    DrawString("A车、C车公轨A车的入口探测点：");
    OffsetPen(0,-bytes-lineDistance);
    DrawLine(50,0);

    MovePen(x1+(x2-x1)*3/4+distance,y1-7*distance-6*bytes);
    DrawString("A车、C车公轨A车的出口探测点：");
    OffsetPen(0,-bytes-lineDistance);
    DrawLine(50,0);

    MovePen(x1+(x2-x1)*3/4+distance,y1-8*distance-7*bytes);
    DrawString("A车、C车公轨C车的入口探测点：");
    OffsetPen(0,-bytes-lineDistance);
    DrawLine(50,0);

    MovePen(x1+(x2-x1)*3/4+distance,y1-9*distance-8*bytes);
    DrawString("A车、C车公轨C车的出口探测点：");
    OffsetPen(0,-bytes-lineDistance);
    DrawLine(50,0);
}


double showDeleteInput(double x1, double y1, double x2, double y2, double distance,char* string,int k)//界面输入呈现函数
{
    char strForInput[200]={'\0'};//储存输入字符的字符数组
    char spaceStrForInput[200]={'\0'};//用于清空输入的空白字符数组
    int cntForInput=0;//数组参数
    double save;//存输入字符串的浮点型
    double bytes=GetStringWidth("火");
    int j,i;
    double X1,Y1,X2,Y2;//储存当前框的左上角坐标和右下角坐标
    double X,Y;//获取鼠标的坐标
    X1=x1+distance+GetStringWidth(string);//左上X
    Y1=y1-(k+1)*distance-k*bytes;//左上Y
    X2=x1+distance+GetStringWidth(string)+50;//左下X
    Y2=y1-(k+2)*distance-(k+1)*bytes;//左下Y
    for(i=0;i<15;i++)//初始化清空字符
    {
        spaceStrForInput[i]=' ';
    }
    while(1)
    {
        while(!(WaitForEvent()==KEYDOWN)){}//若未遇到 KEYDOWN事件（键盘输入或者鼠标点击），则什么都不做。
        if(GetStruckKey() == VK_LBUTTON)//鼠标左键点击进入输入模式
        {
            X = GetMouseX();
            Y = GetMouseY();
            if((X >= X1 && X <= X2) && (Y >= Y2 && Y <= Y1))//鼠标点击在所规定的范围内
                {
                    //回显用户输入，按下Esc时退出输入
                    while(1)
                    {
                        while(!(WaitForEvent() == KEYDOWN)) {}//非键盘和鼠标输入时什么都不做
                        strForInput[cntForInput] = GetStruckKey();
                        if(strForInput[cntForInput]==-67||strForInput[cntForInput]==VK_SUBTRACT)//使可以输入负号
                            strForInput[cntForInput]='-';
                        else if(strForInput[cntForInput]==VK_NUMPAD1)//小键盘输入
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
                        if( strForInput[cntForInput] == VK_ESCAPE )//当按下ESC键时退出输入模式
                        {
                            break;
                        }
                        else
                        {
                            MovePen(X1,Y1);
                            DrawString(strForInput);//显示字符串
                        }
                        cntForInput++;
                    }
                    cntForInput = 0;
                    save=atof(strForInput);
                    for(j = 0; j < 200; ++j) strForInput[j] = '\0';
                    printf("input\n");//输入模式完成后输出input字样
                }
        }
        else if(GetStruckKey() == VK_BACK)//键盘输入Backspace清除字符
        {
            X = GetMouseX();
            Y = GetMouseY();
            if((X >= X1 && X <= X2) && (Y >= Y2 && Y <= Y1))	//input按钮被按下
                {
                    MovePen(X1,Y1);
                    DrawString(spaceStrForInput);
                    printf("clear\n");//清除完成后输出clear字样

                }
        }
        if(GetStruckKey()==VK_RBUTTON)//点击鼠标中键，输入完成
        {
            printf("complete\n");
            break;
        }

    }
    return save;
}

void passSelectInit(double x1,double y1,double x2,double y2)  //判断通行的函数
{
    double distance1;//y轴的间距
    double distance2;//x轴的间距
    MovePen(x1,y1);
    /*画输入外框*/
    DrawLine(x2-x1,0);
    DrawLine(0,y2-y1);
    DrawLine(x1-x2,0);
    DrawLine(0,y1-y2);
    MovePen(x1,y1-30);
    DrawLine(x2-x1,0);
    //画按钮说明框
    MovePen(x1+(x2-x1)/4,y1-30);//30是按钮说明的宽度
    DrawLine(0,y2-y1+30);
    MovePen(x1+(x2-x1)*2/4,y1-30);
    DrawLine(0,y2-y1+30);
    MovePen(x1+(x2-x1)*3/4,y1-30);
    DrawLine(0,y2-y1+30);
    distance1=(30-GetStringWidth("按"))/2;
    distance2=(x2-x1-GetStringWidth("判断通行按钮"))/2;
    MovePen(x1+distance2,y1-distance1);
    DrawString("判断通行按钮");
    //A按钮
    distance1=(y1-y2-30-GetStringWidth("车"))/2;
    distance2=((x2-x1)/4-GetStringWidth("A车"))/2;
    MovePen(x1+distance2,y1-30-distance1);
    DrawString("A车");
    buttonA.X1=x1;
    buttonA.Y1=y1-30;
    buttonA.X2=x1+(x2-x1)/4;
    buttonA.Y2=y2;
    //B按钮
    distance1=(y1-y2-30-GetStringWidth("车"))/2;
    distance2=((x2-x1)/4-GetStringWidth("B车"))/2;
    MovePen(x1+(x2-x1)/4+distance2,y1-30-distance1);
    DrawString("B车");
    buttonB.X1=x1+(x2-x1)/4;
    buttonB.Y1=y1-30;
    buttonB.X2=x1+(x2-x1)*2/4;
    buttonB.Y2=y2;
    //C按钮
    distance1=(y1-y2-30-GetStringWidth("车"))/2;
    distance2=((x2-x1)/4-GetStringWidth("C车"))/2;
    MovePen(x1+(x2-x1)*2/4+distance2,y1-30-distance1);
    DrawString("C车");
    buttonC.X1=x1+(x2-x1)*2/4;
    buttonC.Y1=y1-30;
    buttonC.X2=x1+(x2-x1)*3/4;
    buttonC.Y2=y2;
    //快慢交替按钮
    distance1=(y1-y2-30-GetStringWidth("车"))/2;
    distance2=((x2-x1)/4-GetStringWidth("快慢交替"))/2;
    MovePen(x1+(x2-x1)*3/4+distance2,y1-30-distance1);
    DrawString("快慢交替");
    buttonDetected.X1=x1+(x2-x1)*3/4;
    buttonDetected.Y1=y1-30;
    buttonDetected.X2=x2;
    buttonDetected.Y2=y2;

}

void confirmComplete(double x1, double y1, double x2, double y2)//确认完成按钮函数
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
    distance1=(x2-x1-GetStringWidth("输入完成"))/2;
    distance2=(y1-y2-GetStringWidth("输"))/2;
    MovePen(x1+distance1,y1-distance2);
    DrawString("输入完成");
    SetPenColor(BLACK);
    while(1)
    {
        while(!(WaitForEvent()==KEYDOWN)){}
        if(GetStruckKey() == VK_LBUTTON)
        {
            X = GetMouseX();
            Y = GetMouseY();
            if((X >= x1 && X <= x2) && (Y >= y2 && Y <= y1))//鼠标点击在所规定的范围内
            {
                EatEgg();//吃掉完成键和信息输入框的蛋
                break;
            }
        }
    }

}


void isDefault(double x1, double y1, double x2, double y2)//是否使用默认配置函数
{
    LayEgg();//是否的蛋
    int i;
    double parameter;
    double distance1;
    double distance2;
    MovePen(x1+235,y1+20);
    DrawString("是否使用默认配置");
    MovePen(x1,y1);
    DrawLine(x2-x1,0);
    DrawLine(0,y2-y1);
    DrawLine(x1-x2,0);
    DrawLine(0,y1-y2);
    MovePen(x1+(x2-x1)/2,y1);
    DrawLine(0,y2-y1);
    distance1=((x2-x1)/2-GetStringWidth("是"))/2;
    distance2=(y1-y2-GetStringWidth("是"))/2;
    MovePen(x1+distance1,y1-distance2);
    DrawString("是");
    MovePen(x1+(x2-x1)/2+distance1,y1-distance2);
    DrawString("否");
    double X,Y;
    while(1)
    {
        while(!(WaitForEvent()==KEYDOWN)){}
        if(GetStruckKey() == VK_LBUTTON)
        {
            X = GetMouseX();
            Y = GetMouseY();
            if((X >= x1 && X <= x1+(x2-x1)/2) && (Y >= y2 && Y <= y1))//鼠标点击在所规定的范围内
            {
                printf("使用默认配置\n");
                EatEgg();
                break;
            }
            else if((X > x1+(x2-x1)/2 && X <= x2) && (Y >= y2 && Y <= y1))
            {
                printf("不使用默认配置\n\n");
                printf("本输入框使用方法如下：\n");
                printf("1. 在输入时应一项一项一次输入。\n");
                printf("2. 点击鼠标左键为输入模式，键盘Backspace为清除模式，鼠标右键为确认模式。\n");
                printf("3. 进入输入模式，输入相应的数字后，点击ESC键可退出输入模式，此时，在相应区域点击Backspace键则可清除相应数字，\n   再次输入如上。点击鼠标右键完成输入后则可进入下一项的输入。\n");
                printf("4. 在全部信息输入完成后，会出现完成按钮，点击则最终完成信息输入。\n");
                EatEgg();
                LayEgg();
                createInputFrame(INPUT_LEFT_UP_X, INPUT_LEFT_UP_Y, INPUT_RIGHT_DOWN_X, INPUT_RIGHT_DOWN_Y, DISTANCE);//建立输入信息框
                printf("\n下面开始输入A火车信息：\n");
                for(i=1;i<=7;i++)//进行A火车信息的配置
                {   //parameter=0,省略了
                    switch(i)
                    {
                        case 1:trainA.type = (int)showDeleteInput(INPUT_LEFT_UP_X, INPUT_LEFT_UP_Y, INPUT_RIGHT_DOWN_X, INPUT_RIGHT_DOWN_Y, DISTANCE,"火车类型（1表示快车，2表示慢车）：",i);break;
                        case 2:trainA.speed = showDeleteInput(INPUT_LEFT_UP_X, INPUT_LEFT_UP_Y, INPUT_RIGHT_DOWN_X, INPUT_RIGHT_DOWN_Y, DISTANCE,"火车速度（m/s）（0到10）：",i);break;
                        case 3:trainA.direction = (int)showDeleteInput(INPUT_LEFT_UP_X, INPUT_LEFT_UP_Y, INPUT_RIGHT_DOWN_X, INPUT_RIGHT_DOWN_Y, DISTANCE,"方向（顺时针为1，逆时针为-1）：",i);break;
                        case 4:trainA.trackLen = showDeleteInput(INPUT_LEFT_UP_X, INPUT_LEFT_UP_Y, INPUT_RIGHT_DOWN_X, INPUT_RIGHT_DOWN_Y, DISTANCE,"轨道长度（m）（0到100）：",i);break;
                        case 5:trainA.position = showDeleteInput(INPUT_LEFT_UP_X, INPUT_LEFT_UP_Y, INPUT_RIGHT_DOWN_X, INPUT_RIGHT_DOWN_Y, DISTANCE,"初始位置(0至轨道长度)：",i);break;
                        case 6:trainA.time = showDeleteInput(INPUT_LEFT_UP_X, INPUT_LEFT_UP_Y, INPUT_RIGHT_DOWN_X, INPUT_RIGHT_DOWN_Y, DISTANCE,"启动时间（从程序开始运行起/s）：",i);break;
                        case 7:trainA.restTime = showDeleteInput(INPUT_LEFT_UP_X, INPUT_LEFT_UP_Y, INPUT_RIGHT_DOWN_X, INPUT_RIGHT_DOWN_Y, DISTANCE,"公共轨道停留时间：",i);break;
                    }
                }
                printf("A火车信息已经输入完成。\n");

                printf("下面开始输入B火车信息：\n");
                for(i=1;i<=7;i++)//进行B火车信息的配置
                {
                    parameter=(INPUT_RIGHT_DOWN_X-INPUT_LEFT_UP_X)/4;
                    switch(i)
                    {
                        case 1:trainB.type = (int)showDeleteInput(INPUT_LEFT_UP_X+parameter, INPUT_LEFT_UP_Y, INPUT_RIGHT_DOWN_X, INPUT_RIGHT_DOWN_Y, DISTANCE,"火车类型（1表示快车，2表示慢车）：",i);break;
                        case 2:trainB.speed = showDeleteInput(INPUT_LEFT_UP_X+parameter, INPUT_LEFT_UP_Y, INPUT_RIGHT_DOWN_X, INPUT_RIGHT_DOWN_Y, DISTANCE,"火车速度（m/s）（0到10）：",i);break;
                        case 3:trainB.direction = (int)showDeleteInput(INPUT_LEFT_UP_X+parameter, INPUT_LEFT_UP_Y, INPUT_RIGHT_DOWN_X, INPUT_RIGHT_DOWN_Y, DISTANCE,"方向（顺时针为1，逆时针为-1）：",i);break;
                        case 4:trainB.trackLen = showDeleteInput(INPUT_LEFT_UP_X+parameter, INPUT_LEFT_UP_Y, INPUT_RIGHT_DOWN_X, INPUT_RIGHT_DOWN_Y, DISTANCE,"轨道长度（m）（0到100）：",i);break;
                        case 5:trainB.position = showDeleteInput(INPUT_LEFT_UP_X+parameter, INPUT_LEFT_UP_Y, INPUT_RIGHT_DOWN_X, INPUT_RIGHT_DOWN_Y, DISTANCE,"初始位置(0至轨道长度)：",i);break;
                        case 6:trainB.time = showDeleteInput(INPUT_LEFT_UP_X+parameter, INPUT_LEFT_UP_Y, INPUT_RIGHT_DOWN_X, INPUT_RIGHT_DOWN_Y, DISTANCE,"启动时间（从程序开始运行起/s）：",i);break;
                        case 7:trainB.restTime = showDeleteInput(INPUT_LEFT_UP_X+parameter, INPUT_LEFT_UP_Y, INPUT_RIGHT_DOWN_X, INPUT_RIGHT_DOWN_Y, DISTANCE,"公共轨道停留时间：",i);break;
                    }
                }
                printf("B火车信息已经输入完成。\n");

                printf("下面开始输入C火车信息：\n");
                for(i=1;i<=7;i++)//进行C火车信息的配置
                {
                    parameter=(INPUT_RIGHT_DOWN_X-INPUT_LEFT_UP_X)*2/4;
                    switch(i)
                    {
                        case 1:trainC.type = (int)showDeleteInput(INPUT_LEFT_UP_X+parameter, INPUT_LEFT_UP_Y, INPUT_RIGHT_DOWN_X, INPUT_RIGHT_DOWN_Y, DISTANCE,"火车类型（1表示快车，2表示慢车）：",i);break;
                        case 2:trainC.speed = showDeleteInput(INPUT_LEFT_UP_X+parameter, INPUT_LEFT_UP_Y, INPUT_RIGHT_DOWN_X, INPUT_RIGHT_DOWN_Y, DISTANCE,"火车速度（m/s）（0到10）：",i);break;
                        case 3:trainC.direction = (int)showDeleteInput(INPUT_LEFT_UP_X+parameter, INPUT_LEFT_UP_Y, INPUT_RIGHT_DOWN_X, INPUT_RIGHT_DOWN_Y, DISTANCE,"方向（顺时针为1，逆时针为-1）：",i);break;
                        case 4:trainC.trackLen = showDeleteInput(INPUT_LEFT_UP_X+parameter, INPUT_LEFT_UP_Y, INPUT_RIGHT_DOWN_X, INPUT_RIGHT_DOWN_Y, DISTANCE,"轨道长度（m）（0到100）：",i);break;
                        case 5:trainC.position = showDeleteInput(INPUT_LEFT_UP_X+parameter, INPUT_LEFT_UP_Y, INPUT_RIGHT_DOWN_X, INPUT_RIGHT_DOWN_Y, DISTANCE,"初始位置(0至轨道长度)：",i);break;
                        case 6:trainC.time = showDeleteInput(INPUT_LEFT_UP_X+parameter, INPUT_LEFT_UP_Y, INPUT_RIGHT_DOWN_X, INPUT_RIGHT_DOWN_Y, DISTANCE,"启动时间（从程序开始运行起/s）：",i);break;
                        case 7:trainC.restTime = showDeleteInput(INPUT_LEFT_UP_X+parameter, INPUT_LEFT_UP_Y, INPUT_RIGHT_DOWN_X, INPUT_RIGHT_DOWN_Y, DISTANCE,"公共轨道停留时间：",i);break;
                    }
                }
                printf("C火车信息已经输入完成。\n");

                printf("下面开始输入探测点信息：\n");
                for(i=1;i<=8;i++)//进行探测点信息的配置
                {
                    parameter=(INPUT_RIGHT_DOWN_X-INPUT_LEFT_UP_X)*3/4;
                    switch(i)
                    {
                        case 1:a1_in = showDeleteInput(INPUT_LEFT_UP_X+parameter, INPUT_LEFT_UP_Y, INPUT_RIGHT_DOWN_X, INPUT_RIGHT_DOWN_Y, DISTANCE,"A车、B车公轨A车的入口探测点：",i);break;
                        case 2:a1_out = showDeleteInput(INPUT_LEFT_UP_X+parameter, INPUT_LEFT_UP_Y, INPUT_RIGHT_DOWN_X, INPUT_RIGHT_DOWN_Y, DISTANCE,"A车、B车公轨A车的出口探测点：",i);break;
                        case 3:b_in = showDeleteInput(INPUT_LEFT_UP_X+parameter, INPUT_LEFT_UP_Y, INPUT_RIGHT_DOWN_X, INPUT_RIGHT_DOWN_Y, DISTANCE,"A车、B车公轨B车的入口探测点：",i);break;
                        case 4:b_out = showDeleteInput(INPUT_LEFT_UP_X+parameter, INPUT_LEFT_UP_Y, INPUT_RIGHT_DOWN_X, INPUT_RIGHT_DOWN_Y, DISTANCE,"A车、B车公轨B车的出口探测点：",i);break;
                        case 5:a2_in = showDeleteInput(INPUT_LEFT_UP_X+parameter, INPUT_LEFT_UP_Y, INPUT_RIGHT_DOWN_X, INPUT_RIGHT_DOWN_Y, DISTANCE,"A车、C车公轨A车的入口探测点：",i);break;
                        case 6:a2_out = showDeleteInput(INPUT_LEFT_UP_X+parameter, INPUT_LEFT_UP_Y, INPUT_RIGHT_DOWN_X, INPUT_RIGHT_DOWN_Y, DISTANCE,"A车、C车公轨A车的出口探测点：",i);break;
                        case 7:c_in = showDeleteInput(INPUT_LEFT_UP_X+parameter, INPUT_LEFT_UP_Y, INPUT_RIGHT_DOWN_X, INPUT_RIGHT_DOWN_Y, DISTANCE,"A车、C车公轨C车的入口探测点：",i);break;
                        case 8:c_out = showDeleteInput(INPUT_LEFT_UP_X+parameter, INPUT_LEFT_UP_Y, INPUT_RIGHT_DOWN_X, INPUT_RIGHT_DOWN_Y, DISTANCE,"A车、C车公轨C车的出口探测点：",i);break;
                    }
                }
                printf("探测点信息输入完成：\n");
                printf("请点击面板上的完成键");
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













