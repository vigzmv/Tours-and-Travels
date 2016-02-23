#include<iostream.h>
#include<conio.h>
#include<ctype.h>
#include<stdio.h>
#include<Windows.h>

int take_correct_numeric_value(float &input)
{

float val;
int isdone=1;
int x=wherex();
int y=wherey();

   	cin>>val;

		if(cin.fail())
   	{
   		cin.clear();
        	cin.ignore();
         gotoxy(x,y);cout<<"\t\t\t\t";

   	}
   else
   	{
   		input=val;
      	isdone=0;
   	}

   return isdone;
}


void show_blanks_for_looading_menu(int x,int y)
{
  gotoxy(x,y);
  cout<<" ";
}

void Loading()
{

	clrscr();

   int x,y;

   char str[]={"!!   PLESE WAIT    ! !"};
   int lim=2;
   int k=1;

   while(lim-->0)
   {

    x=53;y=77;
   for(int i=0,j=6;i<34;i++)
   {

      textcolor(j++);
      if(j==15) j=0;
   	gotoxy(x--,12);putch(174);


      gotoxy(y++,12);putch(175);
      Sleep(20);

      show_blanks_for_looading_menu(x+3,12);
      show_blanks_for_looading_menu(y-3,12);

      textcolor(k);
      if(k==6) k=1;
      gotoxy(56,12);
      puts(str);
   }
       show_blanks_for_looading_menu(x-3,12);
       show_blanks_for_looading_menu(y+3,12);
       k++;

   for(int i=0,l=6;i<30;i++)
   {

      textcolor(l++);
      if(l==15) l=0;
   	gotoxy(x++,12);putch(175);

      gotoxy(y--,12);putch(174);
      Sleep(20);

      show_blanks_for_looading_menu(x-3,12);
      show_blanks_for_looading_menu(y+3,12);
      textcolor(k);
      if(k==6) k=1;
      gotoxy(56,12);puts(str);
   }
      show_blanks_for_looading_menu(x+3,12);
      show_blanks_for_looading_menu(y-3,12);
      k++;
   }

   getch();
}


void lock(int valcheck)
{  int x;
int ch=2;
   if(valcheck==0)
   {
   textcolor(12);

   gotoxy(57,29);x=9;cout<<"   ";while(x-->0) putch(ch);

   gotoxy(57,30);x=13;cout<<" ";while(x-->0) putch(ch);

   gotoxy(57,31);x=3;
   while(x-->0) putch(ch);cout<<"         ";
   x=3;while(x-->0) putch(ch);

   gotoxy(57,32);x=3;
   while(x-->0) putch(ch);cout<<"         ";
   x=3;while(x-->0) putch(ch);

   gotoxy(57,33);x=15;while(x-->0) putch(ch);

   gotoxy(57,34);x=15;while(x-->0) putch(ch);

   gotoxy(57,35);x=15;while(x-->0) putch(ch);

   gotoxy(57,36);x=6;while(x-->0) putch(ch);
   cout<<"   ";x=6;while(x-->0) putch(ch);

   gotoxy(57,37);x=6;while(x-->0) putch(ch);
   cout<<"   ";x=6;while(x-->0) putch(ch);

   gotoxy(57,38);x=7;while(x-->0) putch(ch);
   cout<<" ";x=7;while(x-->0) putch(ch);

   gotoxy(57,39);x=7;while(x-->0) putch(ch);
   cout<<" ";x=7;while(x-->0) putch(ch);

   gotoxy(57,40);x=15;while(x-->0) putch(ch);

   gotoxy(57,41);x=15;while(x-->0) putch(ch);

   gotoxy(57,42);x=13;cout<<" ";
   while(x-->0) putch(ch);

   }

   /************************************************/
   else
   {

   textcolor(18);

   gotoxy(57,27);
   x=9;cout<<"   ";while(x-->0) putch(ch);

   gotoxy(57,28);x=13;cout<<" ";while(x-->0) putch(ch);

   gotoxy(57,29);x=3;while(x-->0) putch(ch);cout<<"         ";
   x=3;while(x-->0) putch(ch);

   gotoxy(57,30);x=3;while(x-->0) putch(ch);cout<<"         ";
   x=3;while(x-->0) putch(ch);

   gotoxy(57,31);x=3;while(x-->0) putch(ch);cout<<"             ";

   gotoxy(57,32);x=3;while(x-->0) putch(ch);cout<<"             ";

   gotoxy(57,33);x=15;while(x-->0) putch(ch);

   gotoxy(57,34);x=15;while(x-->0) putch(ch);

   gotoxy(57,35);x=15;while(x-->0) putch(ch);

   gotoxy(57,36);x=6;while(x-->0) putch(ch);
   cout<<"   ";x=6;while(x-->0) putch(ch);

   gotoxy(57,37);x=6;while(x-->0) putch(ch);cout<<"   ";
   x=6;while(x-->0) putch(ch);

   gotoxy(57,38);x=7;while(x-->0) putch(ch);cout<<" ";
   x=7; while(x-->0) putch(ch);

   gotoxy(57,39);x=7;while(x-->0) putch(ch);cout<<" ";
   x=7; while(x-->0) putch(ch);

   gotoxy(57,40);x=15;while(x-->0) putch(ch);

   gotoxy(57,41);x=15;while(x-->0) putch(ch);

   gotoxy(57,42);x=13;cout<<" ";while(x-->0) putch(ch);

   /*****************************************************/

   Sleep(1300);

   textcolor(10);

   gotoxy(57,27);
   x=9;cout<<"   ";while(x-->0) putch(ch);

   gotoxy(57,28);x=13;cout<<" ";while(x-->0) putch(ch);

   gotoxy(57,29);x=3;while(x-->0) putch(ch);cout<<"         ";
   x=3;while(x-->0) putch(ch);

   gotoxy(57,30);x=3;while(x-->0) putch(ch);cout<<"         ";
   x=3;while(x-->0) putch(ch);

   gotoxy(57,31);x=3;while(x-->0) putch(ch);cout<<"             ";

   gotoxy(57,32);x=3;while(x-->0) putch(ch);cout<<"             ";

   gotoxy(57,33);x=15;while(x-->0) putch(ch);

   gotoxy(57,34);x=15;while(x-->0) putch(ch);

   gotoxy(57,35);x=15;while(x-->0) putch(ch);

   gotoxy(57,36);x=6;while(x-->0) putch(ch);
   cout<<"   ";x=6;while(x-->0) putch(ch);

   gotoxy(57,37);x=6;while(x-->0) putch(ch);cout<<"   ";
   x=6;while(x-->0) putch(ch);

   gotoxy(57,38);x=7;while(x-->0) putch(ch);cout<<" ";
   x=7; while(x-->0) putch(ch);

   gotoxy(57,39);x=7;while(x-->0) putch(ch);cout<<" ";
   x=7; while(x-->0) putch(ch);

   gotoxy(57,40);x=15;while(x-->0) putch(ch);

   gotoxy(57,41);x=15;while(x-->0) putch(ch);

   gotoxy(57,42);x=13;cout<<" ";while(x-->0) putch(ch);
   }
}

int confirmation()
{
int ans;
textcolor(6);
cputs(" ARE YOU SURE YOU WANT TO CONTINUE ? (Y/N) ");
ans=getch();

if((ans=='y')||(ans=='Y'))
{
	return 1;
}
else return 0;
} /* gotoxy(43,34);
   if(!confirmation()) */

void authentication_wait(int sec)
{
	textcolor(3);
   gotoxy(56,17);
   cputs("PLEASE  WAIT  :   ");
   for(int i=sec;i>0;i--)
   	{
      gotoxy(73,17);cout<<i;
      Sleep(700);
      }
}



