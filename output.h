#ifndef OUTPUT_H_INCLUDED
#define OUTPUT_H_INCLUDED
void Output_information(void);
void Count_time(char NaMe,int count_time);
void output_track(void);
void output_Beinformation();
void Draw_Track();
void Draw_ProbePoint();
void Draw_Train(double PosX,double PosY,char *String);
extern double A1[2],A2[2],B1[2],B2[2],C1[2],C2[2];
extern HEGG EggCount;
#endif
