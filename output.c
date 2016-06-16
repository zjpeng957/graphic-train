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

    a=1000/trainA.trackLen;//�����
    b=1000/trainA.trackLen;//�ݱ���

    /*���*/
   //EggStart (1000,800);
   MovePen(375,500);
   SetPen  (RED,10);//�����ɫ�Ϳ��
//A���
   DrawLine (-trainA.trackLen/4*a,0);
   DrawLine (0,trainA.trackLen/4*b);
   trainA.LeftX=GetPenXPos ();
   trainA.LeftY=GetPenYPos ();
   DrawLine (trainA.trackLen/4*a,0);
   DrawLine (0,-trainA.trackLen/4*b);
   trainA.RightX=GetPenXPos ();
   trainA.RightY=GetPenYPos ();
//B���
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
//C���
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
//�����ɫ
   MovePen(1100,700);
   DrawBitmap("�����ɫ.BMP");
}
void Draw_ProbePoint()
{
    HEGG hEggs[8];

/*AB�������A*/
     if(trainB.state!=S1||trainB.state!=S3)
     {
     hEggs[0] = LayEgg();
     EggStart (1000,800);
     MovePen(375,500);
     OffsetPen(-40,(trainA.trackLen/2-a1_in)*b);
     DrawBitmap("�̵�.BMP");
     OffsetPen (-30,(a1_in-a1_out)*b);
     DrawBitmap("�̵�.BMP");
     }

     else
     {
     hEggs[1] = LayEgg();
     EggStart (1000,800);
     MovePen(375,500);
     OffsetPen (-40,(trainA.trackLen/2-a1_in)*b);
     DrawBitmap("���.BMP");
     OffsetPen (-30,(a1_in-a1_out)*b);
     DrawBitmap("���.BMP");
     }

/*AB�������B*/
     if(aPos!=1)
     {
     hEggs[2] = LayEgg();
     EggStart (1000,800);
     MovePen(375+10,500+(trainA.trackLen/2-a1_out)*b-10);
     DrawBitmap("�̵�.BMP");
     OffsetPen (-30,(a1_out-a1_in)*b);
     DrawBitmap("�̵�.BMP");
     }

     else
     {
     hEggs[3] = LayEgg();
     EggStart (1000,800);
     MovePen(375+10,500+(trainA.trackLen/2-a1_out)*b-10);
     DrawBitmap("���.BMP");
     OffsetPen (-30,(a1_out-a1_in)*b);
     DrawBitmap("���.BMP");
     }

/*AC�������A*/
     if(trainC.state!=S1||trainC.state!=S3)
     {
     hEggs[4] = LayEgg();
     EggStart (1000,800);
     MovePen(375+(trainA.trackLen/2-a2_in)*a, 500+50);
     DrawBitmap("�̵�.BMP");
     OffsetPen ((a2_in-a2_out)*a-30,0);
     DrawBitmap("�̵�.BMP");
     }

     else
     {
     hEggs[5] = LayEgg();
     EggStart (1000,800);
     MovePen(375+(trainA.trackLen/2-a2_in)*a, 500+50);
     DrawBitmap("���.BMP");
     OffsetPen ((a2_in-a2_out)*a-30,0);
     DrawBitmap("���.BMP");
     }

/*AC�������C*/
     if(aPos!=2)
     {
     hEggs[6] = LayEgg();
     EggStart (1000,800);
     MovePen(375+(trainA.trackLen/2-a2_in)*a+10, 500-10);
     DrawBitmap("�̵�.BMP");
     OffsetPen ((a2_in-a2_out)*a-20,0);
     DrawBitmap("�̵�.BMP");
     }

     else
     {
     hEggs[7] = LayEgg();
     EggStart (1000,800);
     MovePen(375+(trainA.trackLen/2-a2_in)*a+10, 500-10);
     DrawBitmap("���.BMP");
     OffsetPen ((a2_in-a2_out)*a-20,0);
     DrawBitmap("���.BMP");
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
	fprintf(output,"����%c������������%d��\n",NaMe,count_time);
	sprintf(countTime,"%02d S",count_time);
	SetActiveEgg(EggCount);
    switch(NaMe)
    {
        case 'A':MovePen((-130.0+trainA.LeftX+trainA.RightX)/2.0,(trainA.LeftY+trainA.RightY)/2.0);
                 DrawString("ͣ������ʱ��");
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
                 DrawString("ͣ������ʱ��");
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
                 DrawString("ͣ������ʱ��");
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

        fprintf(output,"\n��ǰ����ʱ����%ds",runTime);
        printf("\n��ǰ����ʱ����%ds",runTime);

        //AС�𳵵���Ϣ
        if(trainA.direction==1)
        {
            fprintf(output,"\nС��A���з���Ϊ��˳ʱ��. ");
            printf("\nС��A���з���Ϊ��˳ʱ��. ");
        }
        else
        {
            fprintf(output,"С��A���з���Ϊ����ʱ��. ");
            printf("С��A���з���Ϊ����ʱ��. ");
        }
        fprintf(output," ����λ��Ϊ��%.1f. �ٶ�Ϊ�� ",trainA.position);
        printf(" ����λ��Ϊ��%.1f. �ٶ�Ϊ�� ",trainA.position);
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


        printf("����״̬Ϊ��");
        switch(trainA.state)//�ж�A��ǰ�����еĹ��
        {
            case S1:fprintf(output,"����-�ǹ������.\n");
                    printf("����-�ǹ������.\n");
                    break;
            case S2:fprintf(output,"����-�������.\n");
                    printf("����-�������.\n");
                    break;
            case S3:fprintf(output,"��ͣ-�ǹ������.\n");
                    printf("��ͣ-�ǹ������.\n");
                    break;
            case S4:fprintf(output,"ͣ��-�������.\n");
                    printf("ͣ��-�������.\n");
                    break;
            case S5:fprintf(output,"��ͣ-�ȴ��������.\n");
                    printf("��ͣ-�ȴ��������.\n");
                    break;
        }

        //BС�𳵵���Ϣ
        if(trainB.direction==1)
        {
            fprintf(output,"\nС��B���з���Ϊ��˳ʱ��. ");
            printf("\nС��B���з���Ϊ��˳ʱ��. ");
        }
        else
        {
            fprintf(output,"С��B���з���Ϊ����ʱ��. ");
            printf("С��B���з���Ϊ����ʱ��. ");
        }
        fprintf(output," ����λ��Ϊ��%.1f. �ٶ�Ϊ��",trainB.position);
        printf(" ����λ��Ϊ��%.1f. �ٶ�Ϊ��",trainB.position);
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

        printf("����״̬Ϊ��");
        switch(trainB.state)//�ж�B��ǰ�����еĹ��
        {
            case S1:fprintf(output,"����-�ǹ������.\n");
                    printf("����-�ǹ������.\n");
                    break;
            case S2:fprintf(output,"����-�������.\n");
                    printf("����-�������.\n");
                    break;
            case S3:fprintf(output,"��ͣ-�ǹ������.\n");
                    printf("��ͣ-�ǹ������.\n");
                    break;
            case S4:fprintf(output,"ͣ��-�������.\n");
                    printf("ͣ��-�������.\n");
                    break;
            case S5:fprintf(output,"��ͣ-�ȴ��������.\n");
                    printf("��ͣ-�ȴ��������.\n");
                    break;
        }

        //CС�𳵵���Ϣ
        if(trainC.direction==1)
        {
            fprintf(output,"С��C���з���Ϊ��˳ʱ��. ");
            printf("С��C���з���Ϊ��˳ʱ��. ");
        }
        else
        {
            fprintf(output,"С��C���з���Ϊ����ʱ��. ");
            printf("С��C���з���Ϊ����ʱ��. ");
        }
        fprintf(output," ����λ��Ϊ��%.1f. �ٶ�Ϊ��",trainC.position);
        printf(" ����λ��Ϊ��%.1f. �ٶ�Ϊ��",trainC.position);
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

        printf("����״̬Ϊ��");
        switch(trainC.state)//�ж�C��ǰ�����еĹ��
        {
            case S1:fprintf(output,"����-�ǹ������.\n");
                    printf("����-�ǹ������.\n");
                    break;
            case S2:fprintf(output,"����-�������.\n");
                    printf("����-�������.\n");
                    break;
            case S3:fprintf(output,"��ͣ-�ǹ������.\n");
                    printf("��ͣ-�ǹ������.\n");
                    break;
            case S4:fprintf(output,"ͣ��-�������.\n");
                    printf("ͣ��-�������.\n");
                    break;
            case S5:fprintf(output,"��ͣ-�ȴ��������.\n");
                    printf("��ͣ-�ȴ��������.\n");
                    break;
        }
        fprintf(output,"��ǰ�Ĳ����ǿ쳵���в���.\n");
        printf("��ǰ�Ĳ����ǿ쳵���в���.\n");

        //�������״̬
        if(trainA.detected==1)
		{
			fprintf(output,"A-B���������Aռ��.\n");
        	printf("A-B���������Aռ��.\n");
		}
		 if(trainA.detected==2)
		{
			fprintf(output,"A-C���������Aռ��.\n");
        	printf("A-C���������Aռ��.\n");
		}
		if(trainB.state==S2||trainB.state==S3)
		{
			fprintf(output,"A-B���������Bռ��.\n");
        	printf("A-B���������Bռ��.\n");
		}
		if(trainC.state==S2||trainC.state==S3)
		{
			fprintf(output,"A-C���������Cռ��.\n");
        	printf("A-C���������Cռ��.\n");
		}
		if(trainA.detected!=1&&trainB.state!=S2&&trainB.state!=S3)
        {
			fprintf(output,"A-B�����������.\n");
        	printf("A-B�����������.\n");
		}
		if(trainA.detected!=2&&trainC.state!=S2&&trainC.state!=S3)
        {
			fprintf(output,"A-C�����������.\n");
        	printf("A-C�����������.\n");
		}
		fclose(output);

}
