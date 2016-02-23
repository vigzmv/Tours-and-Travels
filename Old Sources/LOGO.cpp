#include<fstream.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<dos.h>
#include<windows.h>

void main()
{

 getch();
  int x=34,y=15;

  while(!kbhit())
  {
  textcolor(random(16));
   y=18;
  gotoxy(x,y++);cputs("                                                 ");
  gotoxy(x,y++);cputs("                                               ");
  gotoxy(x,y++);cputs("                                             ");
  gotoxy(x,y++);cputs("                                           ");
  gotoxy(x,y++);cputs("                                         ");
  gotoxy(x,y++);cputs("                                        ");
  gotoxy(x,y++);cputs("                                        ");
  gotoxy(x,y++);cputs("                                        ");
  gotoxy(x,y++);cputs("                                        ");
  gotoxy(x,y++);cputs("                                          ");
  gotoxy(x,y++);cputs("                                           ");
  gotoxy(x,y++);cputs("                                             ");
  gotoxy(x,y++);cputs("                                                        ");
  gotoxy(x,y++);cputs("                                                         ");
  gotoxy(x,y++);cputs("                                                          ");

  gotoxy(random(80)+34,random(35)+16);cputs("                                      ");
  gotoxy(random(80)+34,random(30)+16);cputs("                                       ");
  gotoxy(random(40)+34,random(10)+16);cputs("                                      ");
  gotoxy(random(40)+34,random(13)+16);cputs("                                       ");
  gotoxy(random(60)+34,random(20)+16);cputs("                                      ");
  gotoxy(random(20)+34,random(25)+16);cputs("                                       ");

 }
  int x1=84;
  for(int x1=80,x2=85;x1<150;x1++,x2--)
    {
      for(int y=18;y<36;y++)
      {
      	gotoxy(x1,y);cout<<" ";
         gotoxy(x2,y);cout<<" ";

      }
      Sleep(1);
    }
     int n=7;
     while(n-->0)
     {

     for(int x=5;x<100;x=x+4)
      	{gotoxy(x,33);cputs("#");
         gotoxy(x,43);cputs("#");

         }
         Sleep(100);
      gotoxy(2,33);cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t";
      gotoxy(2,43);cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t";
      gotoxy(2,37);cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t";

      for(int x=6;x<100;x=x+4)
      	{gotoxy(x,33);cputs("#");
         gotoxy(x,43);cputs("#");
         gotoxy(x,37);
         }
         Sleep(100);
      gotoxy(2,33);cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t";
      gotoxy(2,43);cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t";
      gotoxy(2,37);cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t";

      for(int x=7;x<100;x=x+4)
      	{gotoxy(x,33);cputs("#");
         gotoxy(x,43);cputs("#");
         gotoxy(x,37);}
         Sleep(100);
      gotoxy(2,33);cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t";
       gotoxy(2,43);cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t";
       gotoxy(2,37);cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t";

      for(int x=8;x<100;x=x+4)
      	{gotoxy(x,33);cputs("#");
         gotoxy(x,43);cputs("#");
         gotoxy(x,37);}
         Sleep(100);
      gotoxy(2,33);cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t";
      gotoxy(2,43);cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t";
      gotoxy(2,37);cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t";

     }
    getch();

  getch();


}
