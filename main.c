#include<windows.h>
#include<stdio.h>
#include"input.h"
#include"output.h"
#include"dataProcessor.h"
#include"GraProcessor.h"
#include "egg.h"

int main(void)
{
	//HANDLE ThreadA;
	//hint();
	//ThreadA=CreateThread(NULL,0,ChangeInformation,NULL,0,NULL);//输入函数的线程
	//run();
	EggStart(EGG_LENGTH,EGG_WIDTH);
	inputControlFun();
	Draw_Track();
	Switch();

	Draw_ProbePoint();
	OriginalPos();
	EggCount=LayEgg();
	//WaitForExit();
	events();

	return 0;
 }



