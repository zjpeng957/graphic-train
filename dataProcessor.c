#include "dataProcessor.h"
#include "input.h"
#include "output.h"
#include<stdio.h>
#include<time.h>
#include<math.h>
#include "GraProcessor.h"

Train trainA={SPEED,POSITION+2,1,CLWISE,TRACKLEN,TIME,S1,0,FAST},
      trainB={SPEED,POSITION,1,ANTICLWISE,TRACKLEN,TIME,S1,0,SLOW},
      trainC={SPEED,POSITION,1,CLWISE,TRACKLEN,TIME,S1,0,SLOW};


//分别代表公共轨道的起点和终点
double a1_in=7.0,a1_out=10.0,a2_in=14.0,a2_out=17.0,b_in=19.0,b_out=16.0,c_in=2.0,c_out=5.0;
Point A1_in,A1_out,A2_in,A2_out,B_in,B_out,C_in,C_out;
int aPos=0;
double scale;
double a1Mid,a2Mid,bMid,cMid;

HEGG countA,countB,countC;

//移动火车到下一位置，在run函数开始时调用
void move(Train *train)
{
    double distance,d;
    d=(train->speed/INTERVAL)*scale;

    SetActiveEgg(train->Egg);
    if(train->direction==CLWISE)
    {
        distance=train->position+train->speed/INTERVAL;

        switch(train->flag)
        {
            case 1: if(!(train->PosY>train->LeftY))
                    {
                        train->PosY=train->PosY+d;
                        OffsetEgg(0,d);//移动火车
                    }
                    if(train->PosY>train->LeftY)
                    {
                        train->flag=2;
                        train->PosY=train->LeftY;
                    }
                    break;
            case 2: if(!(train->PosX>train->RightX))
                    {
                        train->PosX=train->PosX+d;
                        OffsetEgg(d,0);//移动火车
                    }
                    if(train->PosX>train->RightX)
                    {
                        train->flag=3;
                        train->PosX=train->RightX;
                    }
                    break;
            case 3: if(!(train->PosY<train->RightY))
                    {
                        train->PosY=train->PosY-d;
                        OffsetEgg(0,-d);//移动火车
                    }
                    if(train->PosY<train->RightY)
                    {
                        train->flag=4;
                        train->PosY=train->RightY;
                    }
                    break;
            case 4: if(!(train->PosX<train->LeftX))
                    {
                        train->PosX=train->PosX-d;
                        OffsetEgg(-d,0);//移动火车
                    }
                    if(train->PosX<train->LeftX)
                    {
                        train->flag=1;
                        train->PosX=train->LeftX;
                    }
                    break;
        }
    }
    else
    {
        distance=train->position-train->speed/INTERVAL;

        switch(train->flag)
        {
            case 1: if(!(train->PosY<train->RightY))
                    {
                        train->PosY=train->PosY-d;
                        OffsetEgg(0,-d);//移动、火车
                    }
                    if(train->PosY<train->RightY)
                    {
                        train->flag=4;
                        train->PosY=train->RightY;
                    }
                    break;
            case 2: if(!(train->PosX<train->LeftX))
                    {
                        train->PosX=train->PosX-d;
                        OffsetEgg(-d,0);//移动、火车
                    }
                    if(train->PosX<train->LeftX)
                    {
                        train->flag=1;
                        train->PosX=train->LeftX;
                    }
                    break;
            case 3: if(!(train->PosY>train->LeftY))
                    {
                        train->PosY=train->PosY+d;
                        OffsetEgg(0,d);//移动、火车
                    }
                    if(train->PosY>train->LeftY)
                    {
                        train->flag=2;
                        train->PosY=train->LeftY;
                    }
                    break;
            case 4: if(!(train->PosX>train->RightX))
                    {
                        train->PosX=train->PosX+d;
                        OffsetEgg(d,0);//移动、火车
                    }
                    if(train->PosX>train->RightX)
                    {
                        train->flag=3;
                        train->PosX=train->RightX;
                    }
                    break;
        }
    }

    if(distance>train->trackLen) train->position=distance-train->trackLen;
    else if(distance<POSITION) train->position=distance+train->trackLen;
    else train->position=distance;
}

//模拟火车的运行,实现火车的状态迁移，用户设置完初始信息后调用
void run(void)
{
    static int i=0;
    //scale=1000.0/trainA.trackLen;
    if((trainA.direction==CLWISE&&a1_in>a1_out)||(trainA.direction==ANTICLWISE&&a1_in<a1_out)) a1Mid=((a1_in+a1_out+trainA.trackLen)/2.0)-trainA.trackLen;
    else a1Mid=(a1_in+a1_out)/2.0;
    if((trainA.direction==CLWISE&&a2_in>a2_out)||(trainA.direction==ANTICLWISE&&a2_in<a2_out)) a2Mid=((a2_in+a2_out+trainA.trackLen)/2.0)-trainA.trackLen;
    else a2Mid=(a2_in+a2_out)/2.0;
    if((trainB.direction==CLWISE&&b_in>b_out)||(trainB.direction==ANTICLWISE&&b_in<b_out)) bMid=((b_in+b_out+trainB.trackLen)/2.0)-trainB.trackLen;
    else bMid=(b_in+b_out)/2.0;
    if((trainC.direction==CLWISE&&c_in>c_out)||(trainC.direction==ANTICLWISE&&c_in<c_out)) cMid=((c_in+c_out+trainC.trackLen)/2.0)-trainC.trackLen;
    else cMid=(c_in+c_out)/2.0;

    SetAutoUpdate(0);
    //judge();
    JudgeAB();
    JudgeAC();

    runA();
    runB();
    runC();
    if(i++%100==0) Output_information();
    Update();
}

//判断哪辆火车进入公共轨道，当有车要进入公共轨道时调用
void judge(void)
{
    int flag1=0,flag2=0;//用于火车交替记录
    int con;

        //LayEgg();
        if(trainA.detected==1&&trainB.detected&&aPos!=1)
        {

            switch(con=control())
            {
                case 1: trainA.state=S2;
                        trainB.state=S5;
                        trainB.position=b_in;
                        break;
                case 2: trainA.state=S5;
                        trainB.state=S2;
                        trainA.position=a1_in;
                        break;
                case 4:if(trainA.type==FAST&&trainB.type==SLOW)
                        {
                            trainA.state=S2;
                            trainB.state=S5;
                            trainB.position=b_in;
                        }
                        else if(trainB.type==FAST&&trainA.type==SLOW)
                        {
                            trainA.state=S5;
                            trainB.state=S2;
                            trainA.position=a1_in;
                        }
                        //火车类型相同采用交替策略
                        else if(trainA.type==trainB.type)
                        {
                            if(flag1==0)
                            {
                                trainA.state=S2;
                                trainB.state=S5;
                                trainB.position=b_in;
                                flag1=1;
                            }
                            else
                            {
                                trainA.state=S5;
                                trainB.state=S2;
                                trainA.position=a1_in;
                                flag1=0;
                            }
                        }
                        Output_information();

                }
        }

        else if(trainA.detected==2&&trainC.detected&&aPos!=2)
        {

            //printf("小火车A和C即将进入公共轨道，");
            switch(con=control())
            {
                case 1: trainA.state=S2;
                        trainC.state=S5;
                        trainC.position=c_in;
                        break;
                case 3: trainA.state=S5;
                        trainC.state=S2;
                        trainA.position=a2_in;
                        break;
                case 4: if(trainA.type==FAST&&trainC.type==SLOW)
                        {
                            trainA.state=S2;
                            trainC.state=S5;
                            trainC.position=c_in;
                        }
                        else if(trainC.type==FAST&&trainA.type==SLOW)
                        {
                            trainA.state=S5;
                            trainC.state=S2;
                            trainA.position=a2_in;
                        }
                        else if(trainA.type==trainC.type)
                        {
                            if(flag2==0)
                            {
                                trainA.state=S2;
                                trainC.state=S5;
                                flag2=1;
                                trainC.position=c_in;
                            }
                            else
                            {
                                trainA.state=S5;
                                trainC.state=S2;
                                flag2=0;
                                trainA.position=a2_in;
                            }
                        }
            }
        }



    else if(trainA.detected==1&&(trainB.state==S2||trainB.state==S4))
        trainA.state=S5;
    else if(trainA.detected==2&&(trainC.state==S2||trainC.state==S4))
        trainA.state=S5;
    else if(trainB.detected&&aPos==1)
        trainB.state=S5;
    else if(trainC.detected&&aPos==2)
        trainC.state=S5;
    else if(trainA.detected==1)
        aPos=1;
    else if(trainA.detected==2)
        aPos=2;

    trainB.detected=0;
    trainC.detected=0;
    //EatEgg();
}
void runA(void)
{
    static int ai=0;
    if(trainA.time>0.0)
            trainA.time=trainA.time-0.01;
        else
        {
            switch(trainA.state)
            {
                //运行-非公共轨道
                case S1:move(&trainA);
                        //判断是否即将进入公共轨道
                        if((trainA.RightX-trainA.PosX<0.1)&&(fabs(trainA.PosY-A1_in.y)<(trainA.speed/INTERVAL)*scale))
                                trainA.detected=1;//,trainA.state=S2;
                        else if((trainA.PosY-trainA.RightY<0.1)&&(fabs(trainA.PosX-A2_in.x)<(trainA.speed/INTERVAL)*scale))
                                trainA.detected=2;//,trainA.state=S2;
                        break;
                //运行-公共轨道
                case S2:move(&trainA);
                        if(trainA.direction==CLWISE)
                            {
                                if(trainA.detected==1)
                                    {
                                        if(trainA.PosY<(trainB.LeftY+trainB.RightY)/2.0&&ai==0)
                                        {
                                            if(trainA.restTime!=0.0)
                                            {
                                                trainA.position=a1Mid;
                                                trainA.PosY=(trainB.LeftY+trainB.RightY)/2.0;
                                                trainA.state=S4;
                                                Count_time('A',trainA.restTime-(double)ai/INTERVAL);
                                            }
                                            ai=1;
                                        }
                                        else if(trainA.PosY<trainB.RightY&&ai!=0) trainA.detected=0,ai=0,trainA.state=S1,aPos=0;
                                    }
                                else if(trainA.detected==2)
                                    {
                                        if(trainA.PosX<(trainC.LeftX+trainC.RightX)/2.0&&ai==0)
                                        {
                                            if(trainA.restTime!=0.0)
                                            {
                                                trainA.position=a2Mid;
                                                trainA.PosX=(trainC.LeftX+trainC.RightX)/2.0;
                                                trainA.state=S4;
                                                Count_time('A',trainA.restTime-(double)ai/INTERVAL);
                                            }
                                            ai=1;
                                        }
                                        else if(trainA.PosX<trainC.LeftX&&ai!=0) trainA.detected=0,ai=0,trainA.state=S1,aPos=0;
                                    }
                            }
                        if(trainA.direction==ANTICLWISE)
                            {
                                if(trainA.detected==1)
                                    {
                                        if(trainA.PosY>(trainB.LeftY+trainB.RightY)/2.0&&ai==0)
                                        {
                                            if(trainA.restTime!=0.0)
                                            {
                                                trainA.position=a1Mid;
                                                trainA.PosY=(trainB.LeftY+trainB.RightY)/2.0;
                                                trainA.state=S4;
                                                Count_time('A',trainA.restTime-(double)ai/INTERVAL);
                                            }
                                            ai=1;
                                        }
                                        else if(trainA.PosY>trainB.LeftY&&ai!=0) trainA.detected=0,ai=0,trainA.state=S1,aPos=0;
                                    }
                                if(trainA.detected==2)
                                    {
                                        if(trainA.PosX>(trainC.LeftX+trainC.RightX)/2.0&&ai==0)
                                        {
                                            if(trainA.restTime!=0.0)
                                            {
                                                trainA.position=a2Mid;
                                                trainA.PosX=(trainC.LeftX+trainC.RightX)/2.0;
                                                trainA.state=S4;
                                                Count_time('A',trainA.restTime-(double)ai/INTERVAL);
                                            }
                                            ai=1;
                                        }
                                        else if(trainA.PosX>trainC.RightX&&ai!=0) trainA.detected=0,ai=0,trainA.state=S1,aPos=0;
                                    }
                            }

                        break;
                //暂停-非公共轨道
                case S3:break;
                //停靠-公共轨道
                case S4:ai++;
                        if(ai%(int)INTERVAL==0)//停靠倒计时
                            Count_time('A',trainA.restTime-(double)ai/INTERVAL);
                        if((double)ai/INTERVAL>trainA.restTime)
                        {
                            trainA.state=S2;
                            move(&trainA);
                        }

                        break;
                //暂停-等待公共轨道
                case S5:if(trainA.detected==1)
                            if(trainB.state!=S2&&trainB.state!=S4)
                            {
                                trainA.state=S2;
                                aPos=1;
                                move(&trainA);
                            }
                        if(trainA.detected==2)
                            if(trainC.state!=S2&&trainC.state!=S4)
                            {
                                aPos=2;
                                trainA.state=S2;
                                move(&trainA);
                            }
                        break;
            }
        }
}
void runB(void)
{
    static int bi=0;
    if(trainB.time>0.0)
            trainB.time=trainB.time-0.01;
        else
        {
            switch(trainB.state)
            {
                case S1:move(&trainB);
                        if(trainB.direction==CLWISE)
                        {
                            if((trainB.PosY-trainB.RightY)<0.1&&fabs(trainB.LeftX-trainB.PosX)<(trainB.speed/INTERVAL)*scale)
                                trainB.detected=1;//,trainB.state=S2;
                        }
                        else
                        {
                            if((trainB.LeftY-trainB.PosY)<0.1&&fabs(trainB.LeftX-trainB.PosX)<(trainB.speed/INTERVAL)*scale)
                                trainB.detected=1;
                        }
                        break;
                case S2:move(&trainB);
                        if(trainB.direction==CLWISE)
                                {
                                    if(trainB.PosY>(trainB.LeftY+trainB.RightY)/2.0&&bi==0)
                                    {
                                        if(trainB.restTime!=0.0)
                                            {
                                                trainB.position=bMid;
                                                trainB.PosY=(trainB.LeftY+trainB.RightY)/2.0;
                                                trainB.state=S4;
                                                Count_time('B',trainB.restTime-(double)bi/INTERVAL);
                                            }
                                        bi=1;
                                    }
                                    else if(trainB.PosX>trainB.LeftX&&bi!=0) trainB.detected=0,bi=0,trainB.state=S1;
                                }
                        else
                                {
                                    if(trainB.PosY<(trainB.LeftY+trainB.RightY)/2.0&&bi==0)
                                    {
                                        if(trainB.restTime!=0.0)
                                        {
                                            trainB.position=bMid;
                                            trainB.state=S4;
                                            trainB.PosY=(trainB.LeftY+trainB.RightY)/2.0;
                                            Count_time('B',trainB.restTime-(double)bi/INTERVAL);
                                        }
                                        bi=1;
                                    }
                                    else if(trainB.PosX>trainB.LeftX&&bi!=0) trainB.detected=0,bi=0,trainB.state=S1;
                                }
                        break;
                case S3:break;
                case S4:bi++;
                        if(bi%(int)INTERVAL==0)
                                Count_time('B',trainB.restTime-(double)bi/INTERVAL);
                        if((double)bi/INTERVAL>trainB.restTime)
                        {
                            trainB.state=S2;
                            move(&trainB);
                        }
                        break;
                case S5:if(trainA.state!=S2&&trainA.state!=S4)
                        {
                            trainB.state=S2;
                            move(&trainB);
                        }
                        break;
            }
        }
}
void runC(void)
{
   static int ci=0;
   if(trainC.time>0.0)
            trainC.time=trainC.time-0.01;
        else
        {
            switch(trainC.state)
            {
                case S1:move(&trainC);
                        if(trainC.direction==CLWISE)
                        {
                            if((trainC.PosX-trainC.LeftX)<0.1&&fabs(trainC.LeftY-trainC.PosY)<(trainC.speed/INTERVAL)*scale)
                                trainC.detected=1;//,trainB.state=S2;
                        }
                        else
                        {
                            if((trainC.RightX-trainC.PosX)<0.1&&fabs(trainC.LeftY-trainC.PosY)<(trainC.speed/INTERVAL)*scale)
                                trainC.detected=1;
                        }
                       /* if(fabs(trainC.position-c_in)<trainC.speed/INTERVAL)
                                trainC.detected=1,trainC.state=S2;*/
                        break;
                case S2:move(&trainC);
                        if(trainC.direction==CLWISE)
                                {
                                    if(trainC.PosX>(trainC.LeftX+trainC.RightX)/2.0&&ci==0)
                                    {

                                        if(trainC.restTime!=0.0)
                                            {
                                                trainC.position=cMid;
                                                trainC.PosX=(trainC.LeftX+trainC.RightX)/2.0;
                                                trainC.state=S4;
                                                Count_time('C',trainC.restTime-(double)ci/INTERVAL);
                                            }
                                        ci=1;
                                    }
                                    else if(trainC.PosY<trainC.LeftY&&ci!=0) trainC.detected=0,ci=0,trainC.state=S1;

                                }
                        else
                                {
                                    if(trainC.PosX<(trainC.LeftX+trainC.RightX)/2.0&&ci==0)
                                    {
                                        if(trainC.restTime!=0.0)
                                            {
                                                trainC.position=cMid;
                                                trainC.PosX=(trainC.LeftX+trainC.RightX)/2.0;
                                                trainC.state=S4;
                                                Count_time('C',trainC.restTime-(double)ci/INTERVAL);
                                            }
                                        ci=1;
                                    }
                                    else if(trainC.PosY<trainC.LeftY&&ci!=0) trainC.detected=0,ci=0,trainC.state=S1;
                                }
                        break;
                case S3:break;
                case S4:ci++;
                        if(ci%(int)INTERVAL==0)
                            Count_time('C',trainC.restTime-(double)ci/INTERVAL);
                        if((double)ci/INTERVAL>trainC.restTime)
                        {
                            trainC.state=S2;
                            move(&trainC);
                        }
                        break;
                case S5:if(trainA.state!=S2&&trainA.state!=S4)
                        {
                            trainC.state=S2;
                            move(&trainC);
                        }
                        break;
            }
        }
}
void OriginalPos(void)
{
    double LA,LB,LC;
    double dis=trainA.LeftY-trainB.LeftY,a=trainA.LeftY-trainA.RightY;
    double widB=trainB.LeftY-trainB.RightY,lenB=trainB.RightX-trainB.LeftX;
    double widC=trainC.LeftY-trainC.RightY,lenC=trainC.RightX-trainC.LeftX;
    scale=1000.0/trainA.trackLen;

    if(trainA.direction==CLWISE)
    {
        if(trainA.position<=a1_in)
            LA=(a1_in-trainA.position)*scale;
        else
            LA=(trainA.trackLen+a1_in-trainA.position)*scale;

        A1_in.x=trainB.LeftX;
        A1_in.y=trainB.LeftY;
        A1_out.x=trainB.LeftX;
        A1_out.y=trainB.RightY;

        A2_in.x=trainC.RightX;
        A2_in.y=trainC.LeftY;
        A2_out.x=trainC.LeftX;
        A2_out.y=trainC.LeftY;
    }
    else
    {
        if(trainA.position<=a1_out)
            LA=(a1_out-trainA.position)*scale;
        else
            LA=(trainA.trackLen+a1_out-trainA.position)*scale;

        A1_in.x=trainB.LeftX;
        A1_in.y=trainB.RightY;
        A1_out.x=trainB.LeftX;
        A1_out.y=trainB.LeftY;

        A2_in.x=trainC.LeftX;
        A2_in.y=trainC.LeftY;
        A2_out.x=trainC.RightX;
        A2_out.y=trainC.LeftY;
    }
    printf("%f\n",LA/scale);

    if(trainB.direction==CLWISE)
    {
        if(trainB.position<=b_in)
            LB=(b_in-trainB.position)*scale;
        else
            LB=(trainB.trackLen+b_in-trainB.position)*scale;

        B_in.x=trainB.LeftX;
        B_in.y=trainB.RightY;
        B_out.x=trainB.LeftX;
        B_out.y=trainB.LeftY;
    }
    else
    {
        if(trainB.position<=b_out)
            LB=(b_out-trainB.position)*scale;
        else
            LB=(trainB.trackLen+b_out-trainB.position)*scale;

        B_in.x=trainB.LeftX;
        B_in.y=trainB.LeftY;
        B_out.x=trainB.LeftX;
        B_out.y=trainB.RightY;
    }

    if(trainC.direction==CLWISE)
    {
        if(trainC.position<=c_in)
            LC=(c_in-trainC.position)*scale;
        else
            LC=(trainC.trackLen+c_in-trainC.position)*scale;

        C_in.x=trainC.LeftX;
        C_in.y=trainC.LeftY;
        C_out.x=trainC.RightX;
        C_out.y=trainB.LeftY;
    }
    else
    {
        if(trainC.position<=c_out)
            LC=(c_out-trainC.position)*scale;
        else
            LC=(trainC.trackLen+c_out-trainC.position)*scale;

        C_in.x=trainC.RightX;
        C_in.y=trainC.LeftY;
        C_out.x=trainC.LeftX;
        C_out.y=trainB.LeftY;
    }
    printf("%f %f\n",LB,LC);

    //计算A的初始位置
    if(dis>LA)
    {
        trainA.PosX=trainA.RightX;
        trainA.PosY=trainB.LeftY+LA;
        trainA.flag=3;
    }
    else if(dis+a>LA)
    {
        trainA.PosX=trainA.RightX-(LA-dis);
        trainA.PosY=trainA.LeftY;
        trainA.flag=2;
    }
    else if(dis+2.0*a>LA)
    {
        trainA.PosX=trainA.LeftX;
        trainA.PosY=trainA.LeftY-(LA-dis-a);
        trainA.flag=1;
    }
    else if(dis+3.0*a>LA)
    {
        trainA.PosX=trainA.LeftX+(LA-dis-2*a);
        trainA.PosY=trainA.RightY;
        trainA.flag=4;
    }
    else
    {
        trainA.PosX=trainA.RightX;
        trainA.PosY=trainA.RightY+(LA-dis-3*a);
        trainA.flag=3;
    }

    //计算B的初始位置
    if(LB<lenB)
    {
        trainB.PosX=trainB.LeftX+lenB;
        trainB.PosY=trainB.RightY;
        trainB.flag=4;
    }
    else if(LB<lenB+widB)
    {
        trainB.PosX=trainB.RightX;
        trainB.PosY=trainB.RightY+LB-lenB;
        trainB.flag=3;
    }
    else if(LB<2.0*lenB+widB)
    {
        trainB.PosX=trainB.RightX-(LB-lenB-widB);
        trainB.PosY=trainB.LeftY;
        trainB.flag=2;
    }
    else
    {
        trainB.PosX=trainB.LeftX;
        trainB.PosY=trainB.LeftY-(LB-lenB-lenB-widB);
        trainB.flag=1;
    }

    //计算C的初始位置
    if(LC<widC)
    {
        trainC.PosX=trainC.LeftX;
        trainC.PosY=trainC.LeftY-LC;
        trainC.flag=1;
    }
    else if(LC<widC+lenC)
    {
        trainC.PosX=trainC.LeftX+LC-widC;
        trainC.PosY=trainC.RightY;
        trainC.flag=4;
    }
    else if(LC<widC+widC+lenC)
    {
        trainC.PosX=trainC.RightX;
        trainC.PosY=trainC.RightY+LC-widC-lenC;
        trainC.flag=3;
    }
    else
    {
        trainC.PosX=trainC.RightX-(LC-widC-widC-lenC);
        trainC.PosY=trainC.LeftY;
        trainC.flag=2;
    }
    trainA.Egg=LayEgg();
    Draw_Train(trainA.PosX-20,trainA.PosY+20,"A.bmp");
    trainB.Egg=LayEgg();
    Draw_Train(trainB.PosX-20,trainB.PosY+20,"B.bmp");
    trainC.Egg=LayEgg();
    Draw_Train(trainC.PosX-20,trainC.PosY+20,"C.bmp");
}
void JudgeAB(void)
{
    //A,B同时到达入站探测点
        int flag1=0;//用于火车交替记录
        int con;

        //LayEgg();
        if(trainA.detected==1&&trainB.detected&&aPos!=1)
        {

            switch(con=control())
            {
                case 1: trainA.state=S2;
                        trainB.state=S5;
                        trainB.position=b_in;
                        aPos=1;
                        break;
                case 2: trainA.state=S5;
                        trainB.state=S2;
                        trainA.position=a1_in;
                        break;
                case 4:if(trainA.type==FAST&&trainB.type==SLOW)
                        {
                            trainA.state=S2;
                            trainB.state=S5;
                            trainB.position=b_in;
                            aPos=1;
                        }
                        else if(trainB.type==FAST&&trainA.type==SLOW)
                        {
                            trainA.state=S5;
                            trainB.state=S2;
                            trainA.position=a1_in;
                        }
                        //火车类型相同采用交替策略
                        else if(trainA.type==trainB.type)
                        {
                            if(flag1==0)
                            {
                                trainA.state=S2;
                                trainB.state=S5;
                                trainB.position=b_in;
                                flag1=1;
                                aPos=1;
                            }
                            else
                            {
                                trainA.state=S5;
                                trainB.state=S2;
                                trainA.position=a1_in;
                                flag1=0;
                            }
                        }
                        Output_information();

                }
        }

    //A到达入站探测点而B在公共轨道内
    else if(trainA.detected==1&&(trainB.state==S2||trainB.state==S4)&&aPos!=1)
    {
        trainA.state=S5;
    }
    //B到达入站探测点而A在公共轨道内
    else if(trainA.detected==1&&aPos==1&&trainB.detected==1)
    {
        trainB.state=S5;
    }
    //只有A即将进入公共轨道
    else if(trainA.detected==1&&trainB.detected==0&&trainB.state!=S2&&trainB.state!=S4&&trainA.state!=S4)
    {
        trainA.state=S2;
        aPos=1;
    }
    //只有B即将进入公共轨道
    else if(trainB.detected==1&&trainA.detected!=1&&aPos!=1)
    {
        trainB.state=S2;
    }
    trainB.detected=0;
}
void JudgeAC(void)
{
    //A,C同时到达入站探测点
    int flag2=0,con;
    if(trainA.detected==2&&trainC.detected&&aPos!=2)
        {

            //printf("小火车A和C即将进入公共轨道，");
            switch(con=control())
            {
                case 1: trainA.state=S2;
                        trainC.state=S5;
                        trainC.position=c_in;
                        break;
                case 3: trainA.state=S5;
                        trainC.state=S2;
                        trainA.position=a2_in;
                        break;
                case 4: if(trainA.type==FAST&&trainC.type==SLOW)
                        {
                            trainA.state=S2;
                            trainC.state=S5;
                            trainC.position=c_in;
                        }
                        else if(trainC.type==FAST&&trainA.type==SLOW)
                        {
                            trainA.state=S5;
                            trainC.state=S2;
                            trainA.position=a2_in;
                        }
                        else if(trainA.type==trainC.type)
                        {
                            if(flag2==0)
                            {
                                trainA.state=S2;
                                trainC.state=S5;
                                flag2=1;
                                trainC.position=c_in;
                            }
                            else
                            {
                                trainA.state=S5;
                                trainC.state=S2;
                                flag2=0;
                                trainA.position=a2_in;
                            }
                        }
            }
        }
    //A到达入站探测点而C在公共轨道内
    else if(trainA.detected==2&&(trainC.state==S2||trainC.state==S4)&&aPos!=2)
    {
        trainA.state=S5;
    }
    //C到达入站探测点而A在公共轨道内
    else if(trainA.detected==2&&aPos==2&&trainC.detected==1)
    {
        trainC.state=S5;
    }
    //只有A即将进入公共轨道
    else if(trainA.detected==2&&trainC.detected==0&&trainC.state!=S2&&trainC.state!=S4&&trainA.state!=S4)
    {
        trainA.state=S2;
        aPos=2;
    }
    //只有C即将进入公共轨道
    else if(trainC.detected==1&&trainA.detected!=2&&aPos!=2)
    {
        trainC.state=S2;
    }
    trainC.detected=0;
}
