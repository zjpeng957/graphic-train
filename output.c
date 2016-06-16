#include"dataProcessor.h"
#include"input.h"
#include<stdio.h>
#include<time.h>
#include<windows.h>
#include"output.h"
#include"egg.h"
double A1[2],A2[2],B1[2],B2[2],C1[2],C2[2];
int a,b;
HEGG EggCount;
char countTime[5];
void Draw_Track()
{

    a=1000/trainA.trackLen;//横比例
    b=1000/trainA.trackLen;//纵比例

    /*轨道*/
   //EggStart (1000,800);
   MovePen(375,500);
   SetPen  (RED,10);//轨道颜色和宽度
//A轨道
   DrawLine (-trainA.trackLen/4*a,0);
   DrawLine (0,trainA.trackLen/4*b);
   trainA.LeftX=GetPenXPos ();
   trainA.LeftY=GetPenYPos ();
   DrawLine (trainA.trackLen/4*a,0);
   DrawLine (0,-trainA.trackLen/4*b);
   trainA.RightX=GetPenXPos ();
   trainA.RightY=GetPenYPos ();
//B轨道
   SetPen  (DARK_MAGENTA,10);
   OffsetPen(0, (trainA.trackLen/2-a1_out)*b);
   DrawLine (0,(a1_out-a1_in)*b);
   trainB.LeftX=GetPenXPos ();
   trainB.LeftY=GetPenYPos ();
   DrawLine ((trainB.trackLen/2-a1_out+a1_in)*a,0);
   DrawLine (0,(-a1_out+a1_in)*b);
   trainB.RightX=GetPenXPos ();
   trainB.RightY=GetPenYPos ();
   DrawLine (-(trainB.trackLen/2-a1_out+a1_in)*a,0);
//C轨道
   SetPen  (BLUE ,10);
   OffsetPen((trainA.trackLen/2-a2_in)*a, -(trainA.trackLen/2-a1_out)*b);
   DrawLine ((a2_in-a2_out)*a,0);
   trainC.LeftX=GetPenXPos ();
   trainC.LeftY=GetPenYPos ();
   DrawLine (0,-(trainC.trackLen/2-a2_out+a2_in)*b);
   DrawLine ((a2_out-a2_in)*a,0);
   trainC.RightX=GetPenXPos ();
   trainC.RightY=GetPenYPos ();
   DrawLine (0,(trainC.trackLen/2-a2_out+a2_in)*b);
//轨道颜色
   MovePen(1100,700);
   DrawBitmap("轨道颜色.BMP");
}
void Draw_ProbePoint()
{
    HEGG hEggs[8];

/*AB公共轨道A*/
     if(trainB.state!=S1||trainB.state!=S3)
     {
     hEggs[0] = LayEgg();
     EggStart (1000,800);
     MovePen(375,500);
     OffsetPen(-40,(trainA.trackLen/2-a1_in)*b);
     DrawBitmap("绿灯.BMP");
     OffsetPen (-30,(a1_in-a1_out)*b);
     DrawBitmap("绿灯.BMP");
     }

     else
     {
     hEggs[1] = LayEgg();
     EggStart (1000,800);
     MovePen(375,500);
     OffsetPen (-40,(trainA.trackLen/2-a1_in)*b);
     DrawBitmap("红灯.BMP");
     OffsetPen (-30,(a1_in-a1_out)*b);
     DrawBitmap("红灯.BMP");
     }

/*AB公共轨道B*/
     if(aPos!=1)
     {
     hEggs[2] = LayEgg();
     EggStart (1000,800);
     MovePen(375+10,500+(trainA.trackLen/2-a1_out)*b-10);
     DrawBitmap("绿灯.BMP");
     OffsetPen (-30,(a1_out-a1_in)*b);
     DrawBitmap("绿灯.BMP");
     }

     else
     {
     hEggs[3] = LayEgg();
     EggStart (1000,800);
     MovePen(375+10,500+(trainA.trackLen/2-a1_out)*b-10);
     DrawBitmap("红灯.BMP");
     OffsetPen (-30,(a1_out-a1_in)*b);
     DrawBitmap("红灯.BMP");
     }

/*AC公共轨道A*/
     if(trainC.state!=S1||trainC.state!=S3)
     {
     hEggs[4] = LayEgg();
     EggStart (1000,800);
     MovePen(375+(trainA.trackLen/2-a2_in)*a, 500+50);
     DrawBitmap("绿灯.BMP");
     OffsetPen ((a2_in-a2_out)*a-30,0);
     DrawBitmap("绿灯.BMP");
     }

     else
     {
     hEggs[5] = LayEgg();
     EggStart (1000,800);
     MovePen(375+(trainA.trackLen/2-a2_in)*a, 500+50);
     DrawBitmap("红灯.BMP");
     OffsetPen ((a2_in-a2_out)*a-30,0);
     DrawBitmap("红灯.BMP");
     }

/*AC公共轨道C*/
     if(aPos!=2)
     {
     hEggs[6] = LayEgg();
     EggStart (1000,800);
     MovePen(375+(trainA.trackLen/2-a2_in)*a+10, 500-10);
     DrawBitmap("绿灯.BMP");
     OffsetPen ((a2_in-a2_out)*a-20,0);
     DrawBitmap("绿灯.BMP");
     }

     else
     {
     hEggs[7] = LayEgg();
     EggStart (1000,800);
     MovePen(375+(trainA.trackLen/2-a2_in)*a+10, 500-10);
     DrawBitmap("红灯.BMP");
     OffsetPen ((a2_in-a2_out)*a-20,0);
     DrawBitmap("红灯.BMP");
     }

}

void Draw_Train(double PosX,double PosY,char *String)
{

   MovePen(PosX, PosY);
   DrawBitmap(String);
}


void Count_time(char NaMe,int count_time)
{
	FILE *output;
	output=fopen("output.txt","a+");
	fprintf(output,"距离%c重新启动还有%d秒\n",NaMe,count_time);
	sprintf(countTime,"%02d S",count_time);
	SetActiveEgg(EggCount);
    switch(NaMe)
    {
        case 'A':MovePen((-130.0+trainA.LeftX+trainA.RightX)/2.0,(trainA.LeftY+trainA.RightY)/2.0);
                 DrawString("停靠倒计时：");
                 SetPenColor(RED);
                 DrawString(countTime);
                 SetPenColor(BLACK);
                 if(count_time<1)
                 {
                     MovePen((-130.0+trainA.LeftX+trainA.RightX)/2.0,(trainA.LeftY+trainA.RightY)/2.0);
                     DrawString("                                           ");
                 }
                 break;
        case 'B':MovePen((-130.0+trainB.LeftX+trainB.RightX)/2.0,(trainB.LeftY+trainB.RightY)/2.0);
                 DrawString("停靠倒计时：");
                 SetPenColor(DARK_MAGENTA);
                 DrawString(countTime);
                 SetPenColor(BLACK);
                 if(count_time<1)
                 {
                     MovePen((-130.0+trainB.LeftX+trainB.RightX)/2.0,(trainB.LeftY+trainB.RightY)/2.0);
                     DrawString("                                           ");
                 }
                 break;
        case 'C':MovePen(trainC.RightX+10,(trainC.LeftY+trainC.RightY)/2.0);
                 DrawString("停靠倒计时：");
                 SetPenColor(BLUE);
                 DrawString(countTime);
                 SetPenColor(BLACK);
                 if(count_time<1)
                 {
                     MovePen(trainC.RightX+10,(trainC.LeftY+trainC.RightY)/2.0);
                     DrawString("                                           ");
                 }
                 break;
    }
	fclose(output);
}
void Output_information(void)
{
        int runTime;
        FILE *output;
        runTime=clock()/CLOCKS_PER_SEC;

        output=fopen("output.txt","a+");

        fprintf(output,"\n当前运行时间是%ds",runTime);
        printf("\n当前运行时间是%ds",runTime);

        //A小火车的信息
        if(trainA.direction==1)
        {
            fprintf(output,"\n小火车A运行方向为：顺时针. ");
            printf("\n小火车A运行方向为：顺时针. ");
        }
        else
        {
            fprintf(output,"小火车A运行方向为：逆时针. ");
            printf("小火车A运行方向为：逆时针. ");
        }
        fprintf(output," 所处位置为：%.1f. 速度为： ",trainA.position);
        printf(" 所处位置为：%.1f. 速度为： ",trainA.position);
        if(trainA.state==S3||trainA.state==S4||trainA.state==S5)
        {
            fprintf(output,"0 m/s.");
            printf("0 m/s.");
        }
        else
        {
            fprintf(output,"%.1f m/s.",trainA.speed);
            printf("%.1f m/s.",trainA.speed);
        }


        printf("所处状态为：");
        switch(trainA.state)//判断A当前所运行的轨道
        {
            case S1:fprintf(output,"运行-非公共轨道.\n");
                    printf("运行-非公共轨道.\n");
                    break;
            case S2:fprintf(output,"运行-公共轨道.\n");
                    printf("运行-公共轨道.\n");
                    break;
            case S3:fprintf(output,"暂停-非公共轨道.\n");
                    printf("暂停-非公共轨道.\n");
                    break;
            case S4:fprintf(output,"停靠-公共轨道.\n");
                    printf("停靠-公共轨道.\n");
                    break;
            case S5:fprintf(output,"暂停-等待公共轨道.\n");
                    printf("暂停-等待公共轨道.\n");
                    break;
        }

        //B小火车的信息
        if(trainB.direction==1)
        {
            fprintf(output,"\n小火车B运行方向为：顺时针. ");
            printf("\n小火车B运行方向为：顺时针. ");
        }
        else
        {
            fprintf(output,"小火车B运行方向为：逆时针. ");
            printf("小火车B运行方向为：逆时针. ");
        }
        fprintf(output," 所处位置为：%.1f. 速度为：",trainB.position);
        printf(" 所处位置为：%.1f. 速度为：",trainB.position);
        if(trainB.state==S3||trainB.state==S4||trainB.state==S5)
        {
            fprintf(output,"0 m/s.");
            printf("0 m/s.");
        }
        else
        {
            fprintf(output,"%.1f m/s.",trainB.speed);
            printf("%.1f m/s.",trainB.speed);
        }

        printf("所处状态为：");
        switch(trainB.state)//判断B当前所运行的轨道
        {
            case S1:fprintf(output,"运行-非公共轨道.\n");
                    printf("运行-非公共轨道.\n");
                    break;
            case S2:fprintf(output,"运行-公共轨道.\n");
                    printf("运行-公共轨道.\n");
                    break;
            case S3:fprintf(output,"暂停-非公共轨道.\n");
                    printf("暂停-非公共轨道.\n");
                    break;
            case S4:fprintf(output,"停靠-公共轨道.\n");
                    printf("停靠-公共轨道.\n");
                    break;
            case S5:fprintf(output,"暂停-等待公共轨道.\n");
                    printf("暂停-等待公共轨道.\n");
                    break;
        }

        //C小火车的信息
        if(trainC.direction==1)
        {
            fprintf(output,"小火车C运行方向为：顺时针. ");
            printf("小火车C运行方向为：顺时针. ");
        }
        else
        {
            fprintf(output,"小火车C运行方向为：逆时针. ");
            printf("小火车C运行方向为：逆时针. ");
        }
        fprintf(output," 所处位置为：%.1f. 速度为：",trainC.position);
        printf(" 所处位置为：%.1f. 速度为：",trainC.position);
        if(trainC.state==S3||trainC.state==S4||trainC.state==S5)
        {
            fprintf(output,"0 m/s.");
            printf("0 m/s.");
        }
        else
        {
            fprintf(output,"%.1f m/s.",trainC.speed);
            printf("%.1f m/s.",trainC.speed);
        }

        printf("所处状态为：");
        switch(trainC.state)//判断C当前所运行的轨道
        {
            case S1:fprintf(output,"运行-非公共轨道.\n");
                    printf("运行-非公共轨道.\n");
                    break;
            case S2:fprintf(output,"运行-公共轨道.\n");
                    printf("运行-公共轨道.\n");
                    break;
            case S3:fprintf(output,"暂停-非公共轨道.\n");
                    printf("暂停-非公共轨道.\n");
                    break;
            case S4:fprintf(output,"停靠-公共轨道.\n");
                    printf("停靠-公共轨道.\n");
                    break;
            case S5:fprintf(output,"暂停-等待公共轨道.\n");
                    printf("暂停-等待公共轨道.\n");
                    break;
        }
        fprintf(output,"当前的策略是快车先行策略.\n");
        printf("当前的策略是快车先行策略.\n");

        //公共轨道状态
        if(trainA.detected==1)
		{
			fprintf(output,"A-B公共轨道被A占用.\n");
        	printf("A-B公共轨道被A占用.\n");
		}
		 if(trainA.detected==2)
		{
			fprintf(output,"A-C公共轨道被A占用.\n");
        	printf("A-C公共轨道被A占用.\n");
		}
		if(trainB.state==S2||trainB.state==S3)
		{
			fprintf(output,"A-B公共轨道被B占用.\n");
        	printf("A-B公共轨道被B占用.\n");
		}
		if(trainC.state==S2||trainC.state==S3)
		{
			fprintf(output,"A-C公共轨道被C占用.\n");
        	printf("A-C公共轨道被C占用.\n");
		}
		if(trainA.detected!=1&&trainB.state!=S2&&trainB.state!=S3)
        {
			fprintf(output,"A-B公共轨道空闲.\n");
        	printf("A-B公共轨道空闲.\n");
		}
		if(trainA.detected!=2&&trainC.state!=S2&&trainC.state!=S3)
        {
			fprintf(output,"A-C公共轨道空闲.\n");
        	printf("A-C公共轨道空闲.\n");
		}
		fclose(output);

}
