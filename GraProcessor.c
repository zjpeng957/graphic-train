#include "dataProcessor.h"
#include "GraProcessor.h"
#include "input.h"
#include "output.h"
#include "egg.h"
void switchABC(Train *,double,double);
void events(void)
{
    EVENT_TYPE ev;
    double x,y;

    StartTimer(10);
    while((ev=WaitForEvent())!=EXIT)
    {
        switch(ev)
        {
            case TIMER: run();
                        break;
            case KEYDOWN:
                if(GetStruckKey()==VK_LBUTTON)
                {
                    x=GetMouseX();y=GetMouseY();

                    PressTrain(&trainA,x,y);
                    PressTrain(&trainB,x,y);
                    PressTrain(&trainC,x,y);
                    switchABC(&trainA,x,y);
                    switchABC(&trainB,x,y);
                    switchABC(&trainC,x,y);
                }
                break;
        }
    }
    StopTimer();

}
void PressTrain(Train *train,double x,double y)
{
    if((x>train->PosX-HALFLENGTH&&x<train->PosX+HALFLENGTH)&&(y<train->PosY+HALFWIDTH&&y>train->PosY-HALFWIDTH))
    {
        SetActiveEgg(EggSwitch);
        if(train->state==S1)
        {
            train->state=S3;
            MovePen(train->Switch.X1,train->Switch.Y1);
            DrawBitmap("stop.bmp");
        }
        else if(train->state==S3)
        {
            train->state=S1;
            MovePen(train->Switch.X1,train->Switch.Y1);
            DrawBitmap("run.bmp");
        }
    }
}
int control(void)
{
   int ev;
   double x,y;
   while((ev=WaitForEvent())!=EXIT)
   {
        if(ev==KEYDOWN)
        {
            if(GetStruckKey()==VK_LBUTTON)
            {
                x=GetMouseX();y=GetMouseY();

                if(FirstToRun(buttonA,x,y)) return 1;
                if(FirstToRun(buttonB,x,y)) return 2;
                if(FirstToRun(buttonC,x,y)) return 3;
                if(FirstToRun(buttonDetected,x,y)) return 4;
            }
        }
   }
}
int FirstToRun(Button but,double x,double y)
{
    if((x>but.X1&&x<but.X2)&&(y<but.Y1&&y>but.Y2))
        return 1;
    else return 0;
}
void switchABC(Train *train,double x,double y)
{
    if(x>train->Switch.X1&&x<train->Switch.X2&&y<train->Switch.Y1&&y>train->Switch.Y2)
    {
        SetActiveEgg(EggSwitch);
        if(train->state==S1)
        {
            train->state=S3;
            MovePen(train->Switch.X1,train->Switch.Y1);
            DrawBitmap("stop.bmp");
        }
        else if(train->state==S3)
        {
            train->state=S1;
            MovePen(train->Switch.X1,train->Switch.Y1);
            DrawBitmap("run.bmp");
        }
    }
}
