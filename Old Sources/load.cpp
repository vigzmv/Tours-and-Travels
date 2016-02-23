#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

void main()
{
	char TITLE[]="PLEASE WAIT";
   char subTITLE[]="WAITING.......";

   int len=strlen(TITLE);
   int len2=strlen(subTITLE);

  textbackground(4);
   gotoxy(5,4);putch(201);
   				for(int i=0;i<43;i++)
   				{
               	putch(205);
               }
               putch(187);
   for(int i=5;i<20;i++)
   				{
               	gotoxy(5,i);putch(186); 	gotoxy(49,i);putch(186);
               }
   gotoxy(5,20);putch(200);
   				for(int i=0;i<43;i++)
   				{
               	putch(205);
               }
               putch(188);
   for(int i=5;i<20;i++)
   {
   gotoxy(6,i);
   cputs("                                           ");
   }

   gotoxy(6+((44-len)/2),10);cputs(TITLE);
   gotoxy(6+((44-len2)/2),13);cputs(subTITLE);


   gotoxy(13,16);putch(220);
   				for(int i=0;i<27;i++)
   				{
               	putch(220);
               }
               putch(220);

  	gotoxy(13,17);putch(219); 	gotoxy(41,17);putch(219);

   gotoxy(13,18);putch(223);
   				for(int i=0;i<27;i++)
   				{
               	putch(223);
               }
               putch(223);


  int l=0;
  while(!kbhit())
  {

   l=0;
  	while(l++<34)
  	{
   if(l>8)
   {
   gotoxy(l+5,17);textbackground(4);cputs(" ");
   }
   if(l<28)
   {
   gotoxy(13+l,17);textbackground(1);cputs(" ");
   }
   Sleep(50);
  	}
   textbackground(4);
   l=0;
   while(l++<27)
  {
  	gotoxy(13+l,17);cputs(" ");
  }
  }

  getch();

}
