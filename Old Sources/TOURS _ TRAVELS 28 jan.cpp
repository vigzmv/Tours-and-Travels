/* ------------------------------------------------------*/
                     /* HEADER FILES */
/* ------------------------------------------------------*/


#include<fstream.h>
#include<iostream.h>
#include<stdio.h>              
#include<conio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#include<dos.h>
#include<windows.h>
#include<direct.h>


char city_list[][30]={"AGRA","AHMEDABAD","BANGALORE","MUMBAI",
							"KOLKATA","DELHI","HYDERABAD","JAIPUR",
					  	  "LUCKNOW","CHENNAI","PUNE","SRINAGAR",};

char *one[]={" "," One"," Two"," Three"," Four"," Five"," Six",
            " Seven"," Eight"," Nine"," Ten"," Eleven"," Twelve",
				" Thirteen"," Fourteen"," Fifteen"," Sixteen",
            " Seventeen"," Eighteen"," Nineteen"};

char *ten[]={" "," "," Twenty"," Thirty"," Forty"," Fifty",
				" Sixty", " Seventy"," Eighty"," Ninety"};


/* ------------------------------------------------------*/
                 /* PROGRAMING FUNCTIONS */
/* ------------------------------------------------------*/

void menu();
void pass();
void admin();
void customer();
void Mv_logo();
void change_pass();

void output_box_date_n_time();
void titlebox(char title[],int a,int b);
void show_error();

void No_converter(long,char[]);
void No_coverter_caller(int n);
void empty_file_remove(char file[],int check);

void clear_area_for_view_tour();
void show_blanks_in_Customer();
void show_blanks_in_modify_tour();
void show_blanks_in_Admin();

void lock(int valcheck);
void authentication_wait(int sec);

void CursorControl(int T_F);
void Info_popUp(char TITLE[],char subTITLE[],char sub2TITLE[],int Var);
void loading(char TITLE[],char subTITLE[]);
int user_confirmation(char TITLE[],char subTITLE[]);
int take_correct_input(char out[],int x,int y);
int give_id(int type);
int give_datacount(int type);

void SetWindow(int Width, int Height)
{
    _COORD coord;
    coord.X = Width;
    coord.Y = Height;

    _SMALL_RECT Rect;
    Rect.Top = 0;
    Rect.Left = 0;
    Rect.Bottom = Height - 1;
    Rect.Right = Width - 1;

    // Get handle of the standard output
    HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);
    // Set screen buffer size to that specified in coord
    SetConsoleScreenBufferSize(Handle, coord);
    // Set the window size to that specified in Rect
    SetConsoleWindowInfo(Handle, TRUE, &Rect);
}


/* ------------------------------------------------------*/
                 /* FUNCTION DEFINITIONS */
/* ------------------------------------------------------*/


/* ---------------- WINDOW FORMAT FUNCTIONS ----------------*/

	void output_box_date_n_time()
{
 textcolor(1);
 gotoxy(5,2);putch(201);
 for(int i=0;i<120;i++) putch(205);
 putch(187);

 for(int i=3;i<8;i++)
 {	gotoxy(5,i); putch(186); gotoxy(126,i); putch(186); }

 gotoxy(5,8); putch(200);
 for(int i=0;i<120;i++) putch(205);
 putch(188);

 struct date d;
 struct time t;
 // Taking System date and Time
 getdate(&d);
 int day=d.da_day;
 int mon=d.da_mon;
 int year=d.da_year;

 gettime(&t);
 int hour=t.ti_hour;
 int min=t.ti_min;

 textcolor(4);
 gotoxy(42,4);
 // Viewing Title, System date and Time
 cputs("---|        TOURS AND TRAVELS SYSTEM        |---");

 textcolor(5);
 gotoxy(107,7); cputs(" TIME  :  ");if(hour<10) cputs("0");cprintf("%d",hour);cputs(":");if(min<10) cputs("0");cprintf("%d",min);
 gotoxy(9,7);  cputs(" DATE  :  ");cprintf("%d",day);cputs("/");cprintf("%d",mon);cputs("/");cprintf("%d",year);

 textcolor(1);

 gotoxy(5,9);putch(201);
 for(int i=0;i<120;i++) putch(205);
 putch(187);

 for(int i=10;i<50;i++)
 {	gotoxy(5,i); putch(186); gotoxy(126,i); putch(186); }

 gotoxy(5,50); putch(200);
 for(int i=0;i<120;i++) putch(205);
 putch(188);
}

	void titlebox(char title[]="\0",int x=0,int y=0)
{
  	textbackground(0);
   struct time t;
   int sec,min,hour;
   CursorControl(0);

   while(!kbhit())
   {
   CursorControl(0);
   gettime(&t);

   sec=t.ti_sec;
   hour=t.ti_hour;
   min=t.ti_min;

   textcolor(5);
   gotoxy(117,7);
   if(hour<10) cputs("0");
   cprintf("%d",hour);cputs(":");
   if(min<10) cputs("0");
   cprintf("%d",min);
   gotoxy(122,7);cputs(":");
   if(sec<10) cputs("0");
   cprintf("%d",sec);
   textbackground(0);
   textcolor(4);
  	gotoxy(66-(strlen(title)*0.5),7);textcolor(2);
	cputs(title);
   if(x)
   {
   CursorControl(1);
   gotoxy(x,y);
   Sleep(40);   if(kbhit()) break;
   Sleep(40);   if(kbhit()) break;
   Sleep(40);   if(kbhit()) break;
   Sleep(40);   if(kbhit()) break;
   Sleep(40);   if(kbhit()) break;
   Sleep(40);   if(kbhit()) break;
   Sleep(40);   if(kbhit()) break;
   Sleep(40);   if(kbhit()) break;
	Sleep(40);   if(kbhit()) break;
   Sleep(40);   if(kbhit()) break;
	Sleep(40);   if(kbhit()) break;
   Sleep(40);   if(kbhit()) break;
   Sleep(40);   if(kbhit()) break;
   Sleep(40);   if(kbhit()) break;
   CursorControl(0);
   }
   else
   {
   Sleep(40);   if(kbhit()) break;
   Sleep(40);   if(kbhit()) break;
   Sleep(40);   if(kbhit()) break;
   Sleep(40);   if(kbhit()) break;
   Sleep(40);   if(kbhit()) break;
   Sleep(40);   if(kbhit()) break;
   Sleep(40);   if(kbhit()) break;
   Sleep(40);   if(kbhit()) break;
	Sleep(40);   if(kbhit()) break;
   Sleep(40);   if(kbhit()) break;
   Sleep(40);   if(kbhit()) break;
	Sleep(40);   if(kbhit()) break;
	Sleep(40);   if(kbhit()) break;
   Sleep(40);   if(kbhit()) break;
   Sleep(40);   if(kbhit()) break;
   }
   Sleep(40);   if(kbhit()) break;
	Sleep(40);   if(kbhit()) break;

   gotoxy(66-(strlen(title)*0.5),7);for(unsigned int i=0;i<strlen(title);i++) cputs(" ");

   Sleep(40);   if(kbhit()) break;
	Sleep(40);   if(kbhit()) break;
	Sleep(40);   if(kbhit()) break;
   Sleep(40);   if(kbhit()) break;
   Sleep(40);   if(kbhit()) break;
   Sleep(40);   if(kbhit()) break;
	Sleep(40);   if(kbhit()) break;
   Sleep(40);   if(kbhit()) break;
	Sleep(40);   if(kbhit()) break;

	gotoxy(66-(strlen(title)*0.5),7);textcolor(2);
   cputs(title);
   gotoxy(117,7);cputs("  :  :  ");
   gotoxy(66-(strlen(title)*0.5),7);textcolor(2);
   cputs(title);
  }
  	gotoxy(66-(strlen(title)*0.5),7);textcolor(2);
   cputs(title);
   CursorControl(1);
}

	void show_error()
{
textcolor(4);
gotoxy(48,48);cputs("! ! !    WRONG OPTION    ! ! !");
}


	void No_coverter_caller(int n)
{
		No_converter( (n/10000000)," Crore ");
		No_converter(((n/100000)%100)," Lakh ");
		No_converter(((n/1000)%100)," Thousand ");
 		No_converter(((n/100)%10)," Hundred ");
 		No_converter( (n%100)," ");
}

	void No_converter(long n,char ch[])
{
 if(n>19)
 {
 cout<<ten[n/10]<<one[n%10];
 }

 else
 cout<<one[n];

 if(n) cout<<ch;

}


/* ------------------- AREA CLEARERS -------------------*/


	void clear_area_for_view_tour()
{
  for(int x=68;x<126;x++)
  for(int y=17;y<41;y++)
  {
   gotoxy(x,y);cout<<' ';
  }
}


	void show_blanks_in_Customer()
{
	int x=6;
   while(x-->0)
   {
   gotoxy(44,(20+(x*3)));cout<<"       ";
   }
}


	void show_blanks_in_modify_tour()
{
	int x=7;
	while(x-->0)
	{
	gotoxy(13,27+x*3);cout<<"      ";
   gotoxy(38,47);cout<<"        ";
	}
}

	void show_blanks_in_Admin()
{
 	int x=7;
   while(x-->0)
  {
   gotoxy(44,(18+(x*3)));cout<<"      ";
  }
}


/* ------------------- POP Ups & Graphics -------------------*/

	void Mv_logo()
{
	//Stating Screen
  int x=24,y1,y2;
  int n=30;
  while(n-->0)
  {
  textbackground(random(16));
	clrscr();
   Sleep(50);
  }
  textbackground(0);

  clrscr();


  while(!kbhit())
  {
  y2=8;
  textcolor(random(6)+10);
  gotoxy(x,y2++);cputs("                                             ");
  gotoxy(x,y2++);cputs("                                           ");
  gotoxy(x,y2++);cputs("                                         ");
  gotoxy(x,y2++);cputs("                                       ");
  gotoxy(x,y2++);cputs("                                      ");
  gotoxy(x,y2++);cputs("                                      ");
  gotoxy(x,y2++);cputs("                                      ");
  gotoxy(x,y2++);cputs("                                      ");
  gotoxy(x,y2++);cputs("                                      ");
  gotoxy(x,y2++);cputs("                                        ");
  gotoxy(x,y2++);cputs("                                         ");
  gotoxy(x,y2++);cputs("                                           ");
  gotoxy(x,y2++);cputs("                                                      ");
  gotoxy(x,y2++);cputs("                                                       ");
  gotoxy(x,y2++);cputs("                                                        ");

  Sleep(30);
  y1=30;

  gotoxy(x+5,y1++);cputs("                                       ");
  gotoxy(x+5,y1++);cputs("                                           ");
  gotoxy(x+5,y1++);cputs("                                             ");
  gotoxy(x+5,y1++);cputs("                                          ");
  gotoxy(x+5,y1++);cputs("                                             ");
  gotoxy(x+5,y1++);cputs("                                          ");
  gotoxy(x+5,y1++);cputs("                                          ");
  gotoxy(x+5,y1++);cputs(" ");
  gotoxy(x+5,y1++);cputs(" ");
  gotoxy(x+5,y1++);cputs(" ");
  gotoxy(x+14,y1++);cputs("                                       ");
  gotoxy(x+14,y1++);cputs("                                                ");
  gotoxy(x+14,y1++);cputs("                                                  ");
  gotoxy(x+14,y1++);cputs("                                          ");
  gotoxy(x+14,y1++);cputs("                                                  ");
  gotoxy(x+14,y1++);cputs("                                                ");
  gotoxy(x+14,y1++);cputs("                                          ");

  Sleep(11);
	}
  // Clearing the Screen Slowly
 for(int x1=74,x2=73;x1>23;x1--,x2++)
 	{
   	Sleep(20);
    for(int y=6;y<50;y++)
  	  {
            gotoxy(x1,y);cout<<" ";
            gotoxy(x2,y);cout<<" ";
     }
   }
 clrscr();
 getch();

}

	void lock(int valcheck)
{
   CursorControl(0);
	int x;
	int ch=2;
   int n=2;

   if(valcheck==0)
   {
   while(n-->0)
   {
   if(n!=1)
   {
   textcolor(4);
   }
   else { textcolor(12); }

   gotoxy(58,29);x=9;cout<<"   ";while(x-->0) putch(ch);

   gotoxy(58,30);x=13;cout<<" ";while(x-->0) putch(ch);

   gotoxy(58,31);
   x=3;while(x-->0) putch(ch);cout<<"         ";
   x=3;while(x-->0) putch(ch);

   gotoxy(58,32);
   x=3;while(x-->0) putch(ch);cout<<"         ";
   x=3;while(x-->0) putch(ch);

   gotoxy(58,33);x=15;while(x-->0) putch(ch);

   gotoxy(58,34);x=15;while(x-->0) putch(ch);

   gotoxy(58,35);x=15;while(x-->0) putch(ch);

   gotoxy(58,36);
   x=6;while(x-->0) putch(ch);cout<<"   ";
   x=6;while(x-->0) putch(ch);

   gotoxy(58,37);
   x=6;while(x-->0) putch(ch);cout<<"   ";
   x=6;while(x-->0) putch(ch);

   gotoxy(58,38);
   x=7;while(x-->0) putch(ch);cout<<" ";
   x=7;while(x-->0) putch(ch);

   gotoxy(58,39);
   x=7;while(x-->0) putch(ch);cout<<" ";
   x=7;while(x-->0) putch(ch);

   gotoxy(58,40);x=15;while(x-->0) putch(ch);

   gotoxy(58,41);x=15;while(x-->0) putch(ch);

   gotoxy(58,42);x=13;cout<<" ";while(x-->0) putch(ch);

   Sleep(200);
   }
 }

   else
  {
   textcolor(18);
   n=2;
   while(n-->0)
   {

   gotoxy(58,27);
   x=9;cout<<"   ";while(x-->0) putch(ch);

   gotoxy(58,28);x=13;cout<<" ";while(x-->0) putch(ch);

   gotoxy(58,29);
   x=3;while(x-->0) putch(ch);cout<<"         ";
   x=3;while(x-->0) putch(ch);

   gotoxy(58,30);
   x=3;while(x-->0) putch(ch);cout<<"         ";
   x=3;while(x-->0) putch(ch);

   gotoxy(58,31);
   x=3;while(x-->0) putch(ch);cout<<"         ";
   x=3;while(x-->0) putch(ch);

   gotoxy(58,32);x=3; while(x-->0) putch(ch);cout<<"             ";

   gotoxy(58,33);x=15;while(x-->0) putch(ch);

   gotoxy(58,34);x=15;while(x-->0) putch(ch);

   gotoxy(58,35);x=15;while(x-->0) putch(ch);

   gotoxy(58,36);
   x=6; while(x-->0) putch(ch);cout<<"   ";
   x=6; while(x-->0) putch(ch);

   gotoxy(58,37);
   x=6; while(x-->0) putch(ch);cout<<"   ";
   x=6; while(x-->0) putch(ch);

   gotoxy(58,38);
   x=7; while(x-->0) putch(ch);cout<<" ";
   x=7; while(x-->0) putch(ch);

   gotoxy(58,39);
   x=7; while(x-->0) putch(ch);cout<<" ";
   x=7; while(x-->0) putch(ch);

   gotoxy(58,40);x=15;while(x-->0) putch(ch);

   gotoxy(58,41);x=15;while(x-->0) putch(ch);

   gotoxy(58,42);x=13;cout<<" ";while(x-->0) putch(ch);

   	if(n==0)
   	{
      gotoxy(58,31);x=3; while(x-->0) putch(ch);cout<<"             ";
      }

      Sleep(500);
		textcolor(10);
   }
  }
}

	void authentication_wait(int sec)
{
	CursorControl(0);
   textcolor(3);
   gotoxy(55,15);
   cputs("PLEASE  WAIT   :   ");

   for(int i=sec;i>0;i--)
   {
      gotoxy(77,17);cout<<i;
      Sleep(800);
   }
   CursorControl(1);
}

	void Info_popUp(char TITLE[],char subTITLE[]="\0",char sub2TITLE[]="\0",int Var=0)
{
	CursorControl(0);
   int len=strlen(TITLE);
   int len2=strlen(subTITLE);
   int len3=strlen(sub2TITLE);

   textbackground(2);
   textcolor(0);
   gotoxy(40,14);putch(201);
   for(int i=0;i<51;i++)
  {
    putch(205);
  }
   putch(187);
   for(int i=15;i<37;i++)
  {
    gotoxy(40,i);putch(186); 	gotoxy(92,i);putch(186);
  }
   gotoxy(40,36);putch(200);
   for(int i=0;i<51;i++)
  {
    putch(205);
  }
   putch(188);
   for(int i=15;i<36;i++)
  {
    gotoxy(41,i);
    cputs("                                                   ");
  }

   while(!kbhit())
 {
  gotoxy(45+((44-len)/2),19);cputs(TITLE);
  gotoxy(45+((44-len2)/2),23);cputs(subTITLE);
  if(Var!=0)
  {
  gotoxy(40+((44-len3)/2),30);cputs(sub2TITLE);cputs("   :   ");cprintf("%d",Var);
  }
  Sleep(600);
  gotoxy(45+((44-len)/2),19);int n=len; while(n-->0) cputs(" ");
  gotoxy(45+((44-len2)/2),23);n=len2; while(n-->0) cputs(" ");

  Sleep(200);

 }
   textbackground(0);
   CursorControl(1);
}



	void loading(char TITLE[],char subTITLE[])
{
	CursorControl(0);
   int len=strlen(TITLE);
   int len2=strlen(subTITLE);

  textbackground(1);
  gotoxy(44,16);putch(201);
  for(int i=0;i<43;i++)
 {
  putch(205);
 }
  putch(187);
  for(int i=17;i<32;i++)
 {
  gotoxy(44,i);putch(186); 	gotoxy(88,i);putch(186);
 }
  gotoxy(44,32);putch(200);
  for(int i=0;i<43;i++)
 {
  putch(205);
 }
  putch(188);
  for(int i=17;i<32;i++)
 {
  gotoxy(45,i);
  cputs("                                           ");
 }

  gotoxy(45+((44-len)/2),20);cputs(TITLE);
  gotoxy(45+((44-len2)/2),25);cputs(subTITLE);

  gotoxy(52,28);putch(220);
  for(int i=0;i<27;i++)
 {
  putch(220);
 }
  putch(220);

 gotoxy(52,29);putch(219);
 gotoxy(80,29);putch(219);

 gotoxy(52,30);putch(223);
 for(int i=0;i<27;i++)
 {
  putch(223);
 }
  putch(223);

  gotoxy(55,29);textbackground(4);cputs("                         ");

  int l=0,i=0,loop=2;

  while(loop-->0)
{
   l=0;
  	while(l++<34)
 {
   if(l>8)
  {
   gotoxy(l+44,29);textbackground(4);cputs(" ");
  }
   textbackground(1);

   gotoxy(45+((44-len2)/2)+(len2+i++),25);cputs(".");
   if(i==5)
  {
   gotoxy(45+((44-len2)/2)+len2,25);cputs("      ");

   i=0;
  }
   if(l<28)
  {
   gotoxy(52+l,29);textbackground(2);cputs(" ");
  }
   Sleep(50);
 }
   textbackground(4);
   l=0;
   while(l++<27)
 {
  	gotoxy(52+l,29);cputs(" ");
 }
}

  textbackground(1);
  gotoxy(52,28);cputs("                             ");
  gotoxy(52,29);cputs("                             ");
  gotoxy(52,30);cputs("                             ");

  textbackground(4);
  int n=2;

  while(n-->0)
 {
  gotoxy(52,28);cputs("                             ");
  gotoxy(52,29);cputs("  !         DONE          !  ");
  gotoxy(52,30);cputs("                             ");

  Sleep(400);
  gotoxy(52,29);cputs("                             ");
  Sleep(200);
  gotoxy(52,29);cputs("  !         DONE          !  ");
 }

  Sleep(400);
  textbackground(0);
  CursorControl(1);
}


	int user_confirmation(char TITLE[],char subTITLE[]="\0")
{
   CursorControl(0);
   int len=strlen(TITLE);
   int len2=strlen(subTITLE);

  	textbackground(4);
   textcolor(8);
   gotoxy(44,16);putch(201);
   for(int i=0;i<43;i++)
  {
   putch(205);
  }
   putch(187);
   for(int i=17;i<32;i++)
  {
   gotoxy(44,i);putch(186);
   gotoxy(88,i);putch(186);
  }
   gotoxy(44,32);putch(200);
   for(int i=0;i<43;i++)
  {
  	putch(205);
  }
   putch(188);
   for(int i=17;i<32;i++)
  {
   gotoxy(45,i);
   cputs("                                           ");
  }

  gotoxy(45+((44-len)/2),20);cputs(TITLE);
  gotoxy(44+((44-len2)/2),24);cputs(subTITLE);

 char opt1;

 textbackground(5);
  gotoxy(57,25);cputs("                  ");
  gotoxy(57,26);cputs("     CONTINUE     ");
  gotoxy(57,27);cputs("                  ");
 textbackground(4);
  gotoxy(57,29);cputs("                  ");
  gotoxy(57,30);cputs("      CANCEL      ");
  gotoxy(57,31);cputs("                  ");
 int pos=0;

 do
 {
 opt1=getch();

 if(opt1==13)
  {
   if(pos==0)
   {
   textbackground(1);
   gotoxy(57,25);cputs("                  ");
   gotoxy(57,26);cputs("     CONTINUE     ");
   gotoxy(57,27);cputs("                  ");
   Sleep(1000);
   textbackground(0);CursorControl(1);
   return 0;
   }
   else
   {
   textbackground(1);
   gotoxy(57,29);cputs("                  ");
   gotoxy(57,30);cputs("     CANCELED     ");
   gotoxy(57,31);cputs("                  ");
   Sleep(1200);
   textbackground(0);CursorControl(1);
   return 1;
   }
  }

 else  if((opt1==72)||(opt1==80))
 {
   if(pos==0) pos=1;
   else pos=0;

 	switch(pos)
 {
 case 0 : textbackground(5);
           gotoxy(57,25);cputs("                  ");
           gotoxy(57,26);cputs("     CONTINUE     ");
           gotoxy(57,27);cputs("                  ");
          textbackground(4);
           gotoxy(57,29);cputs("                  ");
           gotoxy(57,30);cputs("      CANCEL      ");
           gotoxy(57,31);cputs("                  ");

           break;
 case 1 : textbackground(4);
           gotoxy(57,25);cputs("                  ");
           gotoxy(57,26);cputs("     CONTINUE     ");
           gotoxy(57,27);cputs("                  ");
          textbackground(5);
           gotoxy(57,29);cputs("                  ");
           gotoxy(57,30);cputs("      CANCEL      ");
           gotoxy(57,31);cputs("                  ");

           break;

 default : break;
   };

  }
 }while(1);
}


/*----------------- CONTROLERS -------------------*/


	void empty_file_remove(char file[],int check)
{
    if(check==1)
   {
    remove(file);
   }
}


	void CursorControl(int T_F)
{
HANDLE cont = GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_CURSOR_INFO CusorInfo;

GetConsoleCursorInfo(cont,&CusorInfo);
CusorInfo.bVisible=T_F;
SetConsoleCursorInfo(cont,&CusorInfo);
}


	int take_correct_input(char out[],int x,int y)
{
   char str[100];
   long int i=0;
	while(1)
   {
     gotoxy(x,y);cputs(out);
     gotoxy(wherex()+i+1,y);
     str[i]=getch();
    if(i>11)
    	continue;
    else if(str[i]=='\r')
    {
	 	if(i!=0)
     {
       	str[i]='\0';
         break;
     }
    }
    else if(str[i]=='\b')
    {
     	if(i!=0)
     	{  i--;
            	cout<<'\b'<<" "<<'\b';
      }
    }
   else if(isdigit(str[i]))
    {
     	textcolor(10);
     	cout<<str[i];
     	i++;
    }
   else textcolor(12);
   }
   textcolor(0);

   return atoi(str);

}


/* ------------------------------------------------------*/
               /* USER DEFINED CLASSES */
/* ------------------------------------------------------*/


/*************  CLASS - ADMIN PASS   **************/

    class admin_pass
{
   private : char pass[10];

	public :

    admin_pass()
   {
   	strcpy(pass,"vigz");
   }

    void getcode(char code[])
   {
   	strcpy(code,pass);
   }

    void givecode(char code[])
   {
   	strcpy(pass,code);
   }

};


/*************   CLASS - TRAVELS     **************/


   struct tdate
{
	int dd,mm,yy;
};

	class TRAVELS
{

   char mode_travel[20],email[20];
   char cust_name[30],from[30],dest[30];
   int amount,no_tickets;
	long int cust_phone;
   tdate cDay;
   public :
   int travel_id;
   void view_TRAVELS();
   void view_city(int frm);
   void book_TRAVELS();
   void view_book();
   void view_book(int check);
   void cancel_travel(int WHOcalls);
   void view_bookings();

   TRAVELS()
   {
    strcpy(cust_name,"\0");
    strcpy(from,"\0");
    strcpy(dest,"\0");
    strcpy(email,"\0");
    strcpy(cust_name,"\0");
    amount=0;
    no_tickets=0;
    cust_phone=0;
    cDay.yy=2014;
    travel_id=0;
   }

};

/*************   TRAVELS - MEMBER FUNCTIONS    **************/

	 void TRAVELS::book_TRAVELS()
{
   TRAVELS trvl;
	int frm,to,op;

   clrscr();
   output_box_date_n_time();

   textcolor(2);

   gotoxy(45,16);cputs("*  PLEASE ENTER THE FOLLOWING DETAILS  *");

   gotoxy(42,22);cputs("PLEASE ENTER YOUR NAME               :     ");
   titlebox("*  *   BOOK MY TRAVEL   *  * ",85,22);

   gotoxy(42,22);cputs("PLEASE ENTER YOUR NAME               :     ");
   gets(trvl.cust_name);

   gotoxy(42,26);cputs("PLEASE ENTER YOUR EMAIL              :     ");
   gets(trvl.email);

   trvl.cust_phone=take_correct_input("ENTER YOUR PHONE                     :    ",42,30);
   textcolor(2);

 do
 {
   clrscr();

   gotoxy(49,14);cputs("*  *  SELECT YOOR PICKUP CITY   *  *");

   view_city(69);

   textcolor(2);
   frm=take_correct_input("ENTER CITY CODE    :  ",50,44);

   if(!((frm>=1)&&(frm<=12)))
  {
   show_error();
   getch();
  }

 }while(!((frm>=1)&&(frm<=12)));

 strcpy(trvl.from,city_list[frm-1]);

 do
 {
   clrscr();
   textcolor(2);
   gotoxy(49,14);cputs("*  *  SELECT YOUR DESTINATION CITY   *  *");

   view_city(frm);
   textcolor(2);
   to=take_correct_input("ENTER CITY CODE    :  ",50,44);

   if(!((to>=1)&&(to<=12)))
  {
   show_error();
   getch();
  }
 }while(!((to>=1)&&(to<=12)&&(frm!=to)));

  strcpy(trvl.dest,city_list[to-1]);

  clrscr();
  output_box_date_n_time();

   gotoxy(50,16);cputs("PLEASE ENTER DATE OF JOURNEY");
  do
  {
   gotoxy(76,20);cout<<"\t\t\t";
   textcolor(2);
   gotoxy(45,20);cputs("ENTER MONTH (In Digits.)        :         ");
   titlebox("*  *   BOOK MY TRAVEL   *  * ",86,20);
   trvl.cDay.mm=take_correct_input("ENTER MONTH (In Digits.)        :        ",45,20);

  }while(!((trvl.cDay.mm>=1)&&(trvl.cDay.mm<=12)));

  do
  {
   gotoxy(76,24);cout<<"\t\t\t";
   textcolor(2);
   trvl.cDay.dd=take_correct_input("ENTER DATE                      :        ",45,24);

  }while(!((trvl.cDay.dd>=1)&&(trvl.cDay.dd<=31)));

  textcolor(2);
  trvl.no_tickets=take_correct_input("PLEASE ENTER NO. OF TICKEST REQUIRED  : ",45,28);

  do
  {
   gotoxy(47,40);cout<<"\t\t\t";
   textcolor(2);
   gotoxy(50,32);cputs("PLEASE CHOOSE MODE OF TRAVEL ");
   textcolor(2);
   gotoxy(47,35);cputs("1. BUS         ( A/C and VOLVO )");
   gotoxy(47,37);cputs("2. MINI VAN        (PRIVATE)");
   gotoxy(47,39);cputs("3. TAXI            (PRIVATE)");
   op=take_correct_input("",46,40);

  }while(!((op==1)||(op==2)||(op==3)));

   if(op==1) strcpy(trvl.mode_travel,"BUS");
   else if(op==2) strcpy(trvl.mode_travel,"MINI VAN");
   else if(op==3) strcpy(trvl.mode_travel,"TAXI");

   randomize();
   trvl.amount=(((random(7)+7)*200+random(5)*10)*trvl.no_tickets);
   trvl.travel_id=give_id(3);

   textcolor(4);
   gotoxy(52,43);cputs("TRAVEL COST IS    :   Rs  ");cout<<trvl.amount;

   if(user_confirmation("DO YOU WANT TO BOOK THIS  ?")) customer();

   fstream file;

   file.open("TOURS & TRAVELS DATA/TRAVEL_BOOKINGS.dat",ios::binary|ios::app);
   file.write((char*)&trvl,sizeof(TRAVELS));
   file.close();

   loading("!!    SENDING  REQUEST    !!"," PLEASE  WAIT");
   Info_popUp("!!   BOOIKING  SUCCESSFULL   !!","PLEASE  REMEMBER  YOUR  ID","BOOKING  ID  Is  - ",trvl.travel_id);

	clrscr();
   output_box_date_n_time();

   trvl.view_book(1);
   getch();
   user_confirmation("Do You Want To PRINT This ?");
 	loading("! !  PRINTING   ! !","PLEASE WAIT");
   getch();
}

    void TRAVELS::view_book(int check)
{
 textcolor(3);
 int i;
 for(i=15;i<43;i++){ gotoxy(31,i);putch(178); }
 for(i=15;i<43;i++){ gotoxy(101,i);putch(178); }

 gotoxy(31,14);for(i=0;i<71;i++) putch(220);
 gotoxy(32,18);for(i=0;i<69;i++) putch(220);
 gotoxy(32,33);for(i=0;i<69;i++) putch(220);
 gotoxy(54,35);for(i=0;i<28;i++) putch(224);
 gotoxy(32,23);for(i=0;i<69;i++) putch(220);
 gotoxy(54,38);for(i=0;i<28;i++) putch(224);
 gotoxy(31,42);for(i=0;i<71;i++) putch(223);

 textcolor(4);
 gotoxy(48,16);cputs("##          TRAVEL TICKET          ##");
 textcolor(2);
 gotoxy(44,20);cputs("CUSTOMER   NAME          :");gotoxy(80,20);puts(cust_name);
 gotoxy(44,21);cputs("CUSTOMER   PHONE         :");gotoxy(80,21);cout<<cust_phone;
 gotoxy(44,22);cputs("CUSTOMER   EMAIL         :");gotoxy(80,22);puts(email);
 gotoxy(45,26);cputs("BOARDING FROM           :");gotoxy(77,26);puts(from);
 gotoxy(45,27);cputs("DESTINATION             :");gotoxy(77,27);puts(dest);
 gotoxy(45,29);cputs("DATE OF JOURNEY         :");gotoxy(77,29);cout<<cDay.dd<<" / "<<cDay.mm<<" / "<<"2014";
 gotoxy(45,30);cputs("MODE OF TRAVEL          :");gotoxy(77,30);puts(mode_travel);
 gotoxy(45,31);cputs("No. OF PERSONS          :");gotoxy(77,31);cout<<no_tickets;
 textcolor(5);
 gotoxy(53,36);putch(224);putch(224);cputs("      TOTAL AMOUNT :      ");putch(224);putch(224);
 gotoxy(53,37);putch(224);putch(224);cout<<"       Rs. ";cout<<amount; gotoxy(81,37); putch(224);putch(224);
 gotoxy(41,40);cputs("Rs. : ");No_coverter_caller(amount);cout<<" - ONLY ";
 getch();
 }


    void TRAVELS::view_book()
{
    clrscr();
    output_box_date_n_time();
    TRAVELS trvl[30];

    fstream fin;
    fin.open("TOURS & TRAVELS DATA/TRAVEL_BOOKINGS.dat",ios::binary|ios::in);
   if(!fin)
   {
    Info_popUp("\0","! !    NO TRAVEL BOOKINGS    ! !","\0",0);
    getch();
    fin.close();
    admin();
   }

   int i=0;
   while(1)
   {
    fin.read((char*)&trvl[i],sizeof(TRAVELS));
    i++;
    if(fin.eof()) break;
   }

  fin.close();

  int totaldetails=give_datacount(3);

  char opt1,opt2;
  int done=0;
  i=0;

  trvl[i].view_bookings();
  titlebox("*  *   TRAVEL BOOKINGS   *  *");
  CursorControl(0);

  do
  {
   opt1=getch();
 	if(opt1=='\r')
  	{
    admin();
   }

   else if(opt1==0)
  	{
  	do
    {
     opt2=getch();

     switch(opt2)
   {
    	case 77 : if(i==(totaldetails-1))
        			 i=0;
                else  i++;
                break;

      case 75 : if(i==0)
        			 i=totaldetails-1;
                else  i--;
                break;

      default : break;
    };

    clear_area_for_view_tour();
    trvl[i].view_bookings();
    titlebox("*  *   TRAVEL BOOKINGS   *  *");
    CursorControl(0);

    do
    {
    opt1=getch();

    if(opt1==0) break;
    else if(opt1==13) admin();

    }while(1);
   }while(1);
  }
 }while(1);
}


    void TRAVELS::view_bookings()
{
 textcolor(3);
  gotoxy(10,13);for(int i=0;i<112;i++) putch(205);
 textcolor(1);
  gotoxy(44,17);cputs("BOOKING ID          --          ");cout<<travel_id;
 textcolor(2);
  gotoxy(36,21);cputs("CUSTOMER NAME               ::         ");puts(cust_name);
  gotoxy(36,23);cputs("CUSTOMER EMAIL              ::         ");puts(email);
  gotoxy(36,25);cputs("CUSTOMER PHONE              ::         ");cout<<cust_phone;
  gotoxy(36,27);cputs("PICK UP FROM                ::         ");puts(from);
  gotoxy(36,28);cputs("DESTINATION                 ::         ");cout<<dest;
  gotoxy(36,31);cputs("ON DATE                     ::         ");cout<<cDay.dd<<" / "<<cDay.mm<<" / "<<"2014";
  gotoxy(36,34);cputs("MODE                        ::         ");puts(mode_travel);
  gotoxy(36,37);cputs("No. OF PERSONS              ::         ");cout<<no_tickets;
  gotoxy(36,40);cputs("  Only Rs.       -          Rs.     ");
 No_coverter_caller(amount);
 textcolor(3);
  gotoxy(10,44);for(int i=0;i<112;i++) putch(205);
 textcolor(15);
  gotoxy(15,46); cputs("<=========");
  gotoxy(107,46);cputs("=========>");
 textcolor(5);
  gotoxy(17,48);cputs("PREVIOUS");
  gotoxy(109,48);cputs("NEXT");
}


    void TRAVELS::cancel_travel(int WHOcalls)
{
 clrscr();
 output_box_date_n_time();

 TRAVELS trvl;
 int id;
 int datacount=give_datacount(3);

 fstream oldf,newf;

 oldf.open("TOURS & TRAVELS DATA/TRAVEL_BOOKINGS.dat",ios::binary|ios::in);

  if(!oldf)
 {
  Info_popUp("\0","! !    NO TRAVEL BOOKINGS    ! !","\0",0);
  getch();
  oldf.close();
  customer();
 }

 textcolor(2);
  gotoxy(45,17);cputs("PLEASE ENTER YOUR BOOKING ID   :  ");
  titlebox("*  *   MY TRAVEL  BOOKING   *  *",78,17);

  id=take_correct_input("PLEASE ENTER YOUR BOOKING ID   : ",45,17);
 textcolor(2);

 int found=0;

  while(1)
 {
 	oldf.read((char*)&trvl,sizeof(TRAVELS));

   if(oldf.eof()) break;

    if(id==trvl.travel_id)
   {
    clrscr();
    output_box_date_n_time();
    trvl.view_book(0);
    found=1;
    break;
   }

 datacount++;

 }

 oldf.close();

 if(!found)
 {
  datacount=0;
  show_error();
  getch();
  customer();
 }

  if(WHOcalls==0) customer();

  newf.open("TOURS & TRAVELS DATA/temp.dat",ios::binary|ios::out);

  oldf.open("TOURS & TRAVELS DATA/TRAVEL_BOOKINGS.dat",ios::binary|ios::in);

   while(!oldf.eof())
{
   oldf.read((char*)&trvl,sizeof(TRAVELS));

   if(oldf.eof()) break;

   if(id==trvl.travel_id)
 {
 	 if((!(user_confirmation("DO YOU WANT TO CANCEL THIS  ?"))))
  {
   loading("!!    SENDING  REQUEST    !!","PLEASE WAIT");
  Info_popUp("!!   CANCELLATION  SUCCESSFULL   !!","BOOKING  HAS  BEEN  CANCELLED","YOUR  ID  was  - ",id);
  getch();
  }

   else
  {
  newf.write((char*)&trvl,sizeof(TRAVELS));
  datacount=0;
  }
 }
  else
  newf.write((char*)&trvl,sizeof(TRAVELS));

}
  newf.close();
  oldf.close();

  remove("TOURS & TRAVELS DATA/TRAVEL_BOOKINGS.dat");
  rename("TOURS & TRAVELS DATA/temp.dat","TOURS & TRAVELS DATA/TRAVEL_BOOKINGS.dat");

  empty_file_remove("TOURS & TRAVELS DATA/TRAVEL_BOOKINGS.dat",datacount);

}

	void TRAVELS::view_city(int frm)
{
   output_box_date_n_time();
   textcolor(5);
   int i;

   for(i=0;i<6;i++)
 {
   if(frm==(i+1)) continue;
   gotoxy(36,(i*4)+20);cout<<(i+1)<<".  ";cputs(city_list[i]);
 }

      for(i=0;i<6;i++)
 {
   if(frm==(i+6)) continue;
   gotoxy(76,(i*4)+20);cout<<(i+6)<<".  ";cputs(city_list[i+6]);
 }
   textcolor(2);
   gotoxy(50,44);cputs("ENTER CITY CODE    :  ");
   titlebox("*  *   BOOK MY TRAVEL   *  *");
}



/*************   CLASS - TOUR     **************/


	class tour
{
	public : char tourname[50],place[200],city[50],day[50],details[300];
   			int tour_no;
            float tariff;
            void view_tours();
};

 	void tour::view_tours()
{
textcolor(3);
  gotoxy(10,13);for(int i=0;i<112;i++) putch(205);
 textcolor(1);
  gotoxy(45,17);cputs("TOUR No.         -          ");cout<<tour_no;
 textcolor(2);
  gotoxy(36,21);cputs("TOUR NAME                 :             ");puts(tourname);
  gotoxy(36,25);cputs("TOUR CITY                 :             ");puts(city);
  gotoxy(36,28);cputs("PLACES                    :             ");puts(place);
  gotoxy(36,31);cputs("DETAILS                   :             ");puts(details);
  gotoxy(36,34);cputs("TOUR DAYS                 :             ");puts(day);
  gotoxy(36,37);cputs("TARIFF                    :             Rs. ");cout<<tariff;
  gotoxy(36,40);cputs("  Only Rs.       -        Rs. ");
  No_coverter_caller(tariff);
 textcolor(3);
  gotoxy(10,44);for(int i=0;i<112;i++) putch(205);

 textcolor(15);
  gotoxy(15,46); cputs("<=========");
  gotoxy(107,46);cputs("=========>");
 textcolor(5);
  gotoxy(17,48);cputs("PREVIOUS");
  gotoxy(109,48);cputs("NEXT");
 textcolor(15);
  gotoxy(57,46);cputs("ENTER = SELECT");
}


/*************   CLASS - ADMIN_TOUR : TOUR     **************/


	class admin_tour : public tour
{
	public : int view_tour(char WHOcalls);
   		   void entry();
   		   void remove_tour();
            void modify_tour();


   admin_tour()
  {
  	strcpy(tourname,"\0");
   strcpy(place,"\0");
   strcpy(day,"\0");
   strcpy(details,"\0");
   tour_no=0;
   tariff=0;
  }
};


/*************  ADMIN_TOUR : TOUR - MEMBER FUNCTIONS     **************/


		void admin_tour::entry()
{
  clrscr();
  output_box_date_n_time();

  admin_tour adm;

  textcolor(1);

  gotoxy(50,14);cputs("PLEASE ENTER TOUR PACKAGE DETAILS ");

 textcolor(2);
  gotoxy(42,20);cputs("Enter Tour  NAME                 :        ");
  titlebox("* *  TOUR ENRTY  * *",84,20);
 textcolor(2);
  gotoxy(42,20);cputs("Enter Tour  NAME                 :        ");
  gets(adm.tourname);
  gotoxy(42,23);cputs("Enter Tour  CITY                 :        ");
  gets(adm.city);
  gotoxy(42,26);cputs("Enter Tour  PLACES               :        ");
  gets(adm.place);
  gotoxy(42,29);cputs("Enter Tour  DETAILS              :        ");
  gets(adm.details);
  gotoxy(42,32);cputs("Enter Tour  DAYS                 :        ");
  gets(adm.day);
  adm.tariff=take_correct_input("Enter Tour  FARE                 :       ",42,35);
  adm.tour_no=give_id(1);

  if(user_confirmation("DO YOU WANT TO SAVE  ?")) admin();

  fstream fout;
  fout.open("TOURS & TRAVELS DATA/TOUR_PACKAGES.dat",ios::binary|ios::app);
  fout.write((char*)&adm,sizeof(admin_tour));
  fout.close();

  loading("!!    SAVING DETAILS    !!","PLEASE WAIT");
  Info_popUp("!!     ENTRY  IS  SUCCESSFUL     !!","THE  PACKAGE  HAS  BEEN  SAVED","TOUR  ID  is ",adm.tour_no);

  getch();

}


int admin_tour::view_tour(char WHOcalls)
{

   admin_tour adm;
   fstream fin;

	fin.open("TOURS & TRAVELS DATA/TOUR_PACKAGES.dat",ios::binary|ios::in);
    if(!fin)
   {
     Info_popUp("\0","! !    NO TOUR PACKAGES    ! !","\0",0);
     getch();
     fin.close();
     admin();
   }

   int totaldetails=give_datacount(1);
   totaldetails;

   char opt1,opt2;
   admin_tour admn[30];
   int done=0;
   int i=0;

    while(1)
   {
    fin.read((char*)&admn[i],sizeof(admin_tour));
    i++;
    if(fin.eof()) break;
   }

   i=0;
   fin.close();

   admn[i].view_tours();
   titlebox("*  *   TOUR PACKAGES   *  *");
   CursorControl(0);

  do
  {
   opt1=getch();

   if(opt1==13)
  {
    if(WHOcalls=='C')
   {
      if(user_confirmation("DO YOU WANT TO CONTINUE  ?","\0"))
     {
      customer();
     }

      else
     {
      done=admn[i].tour_no;
      return done;
     }
   }
    else if(WHOcalls=='A')
    {
     admin();
    }

    else
   {
     if(user_confirmation("DO YOU WANT TO CONTINUE  ?","\0"))
    {
      admin();
    }

    else
    {
     done=admn[i].tour_no;
     return done;
    }
   }
  }
     else if(opt1==0)
  {
  	do
    {
     opt2=getch();

     switch(opt2)
    {
    	case 77 : if(i==(totaldetails-1))
        			 i=0;
                else  i++;
                break;

      case 75 : if(i==0)
        			 i=totaldetails-1;
                else  i--;
                break;

      default : break;
     };

     clear_area_for_view_tour();
     admn[i].view_tours();

     titlebox("*  *   TOUR PACKAGES   *  *");
     CursorControl(0);

      do
      {
       opt1=getch();

     if(opt1==0) break;
     else if(opt1==13)
    {
      if(WHOcalls=='C')
      {
      	gotoxy(52,12);textcolor(2);cputs("PLEASE SELECT THE PACKAGE  : ");

      if(user_confirmation("DO YOU WANT TO CONTINUE  ?","\0"))
       {
       	customer();
       }

    else
       {
        done=admn[i].tour_no;
        return done;
       }
     }
    else if(WHOcalls=='A')
      {
        admin();
      }
    else
    {
     if(user_confirmation("DO YOU WANT TO CONTINUE  ?","\0"))
       {
       	admin();
       }

     else
       {
        done=admn[i].tour_no;
        return done;
       }
      }
     }
    }while(done==0);
   }while(done==0);
  }
 }while(done==0);

  return done;
}


   void admin_tour::modify_tour()
{
    clrscr();
    output_box_date_n_time();

    admin_tour adm;
    int mod;
    fstream file;

    file.open("TOURS & TRAVELS DATA/TOUR_PACKAGES.dat",ios::binary|ios::in);

  if(!file)
  {
   Info_popUp("\0","! !    NO TOUR PACKAGES    ! !","\0",0);
   getch();
   file.close();
   admin();
  }


  file.close();

  mod=adm.view_tour('M');

  clrscr();
  output_box_date_n_time();

  file.open("TOURS & TRAVELS DATA/TOUR_PACKAGES.dat",ios::binary|ios::in|ios::out);

  int loopend=0;
  long pos;
  do
   {
     pos=file.tellg();
     file.read((char*)&adm,sizeof(admin_tour));
  	  if(file.eof()) break;

     if(mod==adm.tour_no)
    {
   gotoxy(51,12);textcolor(2);cputs("*  *  ENTER NEW RECORDS   *  *");
   gotoxy(10,16);for(int i=0;i<112;i++) putch(205);
   gotoxy(18,18);cout<<"   RECORD NAME   \t\t\t   OLD VALUE\t\t\t   NEW  VALUE";
   gotoxy(10,20);for(int i=0;i<112;i++) putch(205);

  textcolor(5);gotoxy(22,24);cputs("TOUR No.   ");cout<<"\t :\t\t";cout<<adm.tour_no;
   gotoxy(22,27);cputs("TOUR NAME ");cout<<"\t\t : \t\t";puts(adm.tourname);
   gotoxy(22,30);cputs("TOUR CITY ");cout<<"\t\t : \t\t";puts(adm.city);
	gotoxy(22,33);cputs("PLACES    ");cout<<"\t\t : \t\t";puts(adm.place);
   gotoxy(22,36);cputs("DETAILS   ");cout<<"\t\t : \t\t";puts(adm.details);
   gotoxy(22,39);cputs("TOUR DAYS ");cout<<"\t\t : \t\t";puts(adm.day);
   gotoxy(22,42);cputs("TOUR FARE ");cout<<"\t\t : \t\t";cout<<adm.tariff;

 textcolor(16);
 textbackground(2);
  gotoxy(51,46);cputs("                               ");
  gotoxy(51,47);cputs("          SAVE   INFO          ");
  gotoxy(51,48);cputs("                               ");
 textbackground(0);

  char opt1,opt2;
  int x=13,y=27,x1=93;

  gotoxy(13,27);textcolor(15);cputs("=====>");
  titlebox("* *  MODIFY TOUR  * *");

  do
  {
   opt1=getch();

   if(opt1==13)
   {
   gotoxy(x1,27);
   gets(adm.tourname);
   }

  }while(opt1!=0);

 if(opt1==0)
  {
  	do
    {
     opt2=getch();

     switch(opt2)
     {
      	case 72 : if(y==27) y=45;
        				 else y-=3;
                   break;

         case 80 : if(y==45) y=27;
            		 else y+=3;
                   break;

         default : break;
     };

      do
       {
         show_blanks_in_modify_tour();

		   if(y==45)
         {
            textcolor(10);
  				textbackground(4);
  			    gotoxy(51,46);cputs("                               ");
  				 gotoxy(51,47);cputs("          SAVE   INFO          ");
  				 gotoxy(51,48);cputs("                               ");
				 titlebox("* *  MODIFY TOUR  * *");
            textbackground(0);

         }
         else
         {
           textcolor(16);
  			  textbackground(2);
  			   gotoxy(51,46);cputs("                               ");
  				gotoxy(51,47);cputs("          SAVE   INFO          ");
				gotoxy(51,48);cputs("                               ");
            textbackground(0);
            gotoxy(x,y);textcolor(15);cputs("=====>");
            titlebox("* *  MODIFY TOUR  * *");
         }

            opt1=getch();

            if(opt1==0) break;

         		switch(opt1)
     				{
                   case 72 : if(y==27) y=45;
        				 else y-=3;
                   break;

        				 case 80 : if(y==45) y=27;
            		 else y+=3;
                   break;
   			   };

            if(opt1==13)
         {
             if(y==27)
            	{
                gotoxy(x1,27);
                gets(adm.tourname);
               }
        else if(y==30)
             	{
                gotoxy(x1,30);
                gets(adm.city);
              	}
        else if(y==33)
              	{
                gotoxy(x1,33);
                gets(adm.place);
              	}
        else if(y==36)
              	{
                gotoxy(x1,36);
                gets(adm.details);
            	}
        else if(y==39)
              	{
                gotoxy(x1,39);
                gets(adm.day);
              	}
        else if(y==42)
              	{
                adm.tariff=take_correct_input("",92,42);
               }
        else if(y==45)
               {
            if(user_confirmation("DO YOU WANT TO SAVE  ?"))
            		{
            		file.close();
            		admin();
            		}
         else
            {
       loading("MODIFYING THE PACKAGE ","PLEASE WAIT");
    	 Info_popUp("!!    MODIFICATION  SUCCESSFULL    !!","PACKAGE MODIFIED","MODIFIED  PACKAGE  Id - ",mod);
       loopend=1;
				}
     }

      CursorControl(0);
    }
   }while(!((opt1==0)||(opt1==13)));


  }while(loopend==0);
 }
 getch();

 }
 }while(loopend==0);

  file.seekg(pos);

  file.write((char*)&adm,sizeof(admin_tour));

 file.close();
 admin();

}


  void admin_tour::remove_tour()
{
  clrscr();
  output_box_date_n_time();

  admin_tour adm;
  int rm;
  int datacount=0;
  fstream oldf,newf;

  oldf.open("TOURS & TRAVELS DATA/TOUR_PACKAGES.dat",ios::binary|ios::in);
   if(!oldf)
    {
     Info_popUp("\0","! !    NO TOUR PACKAGES    ! !","\0",0);
     getch();
     oldf.close();
     admin();
    }

   oldf.close();

   datacount=give_datacount(1);

   rm=adm.view_tour('R');

  loading("DELETING  THE  PACKAGE","PLEASE WAIT");
  Info_popUp("!!    DELETION  SUCCESSFULL    !!","PACKAGE  DELETED","DELETED  PACKAGE  Id - ",rm);

  newf.open("TOURS & TRAVELS DATA/temp.dat",ios::binary|ios::out);

  oldf.open("TOURS & TRAVELS DATA/TOUR_PACKAGES.dat",ios::binary|ios::in);
  oldf.read((char*)&adm,sizeof(admin_tour));
 do
  {
  if(rm==adm.tour_no)
   {
    oldf.read((char*)&adm,sizeof(admin_tour));
   }
    newf.write((char*)&adm,sizeof(admin_tour));
    oldf.read((char*)&adm,sizeof(admin_tour));

  }while(!oldf.eof());

  newf.close();
  oldf.close();

  remove("TOURS & TRAVELS DATA/TOUR_PACKAGES.dat");
  rename("TOURS & TRAVELS DATA/temp.dat","TOURS & TRAVELS DATA/TOUR_PACKAGES.dat");

  empty_file_remove("TOURS & TRAVELS DATA/TOUR_PACKAGES.dat",datacount);
  getch();
  admin();

}



/*************   CLASS - CUST_TOUR : TOUR     **************/


	class cust_tour : public tour
{
	private :
				char cust_name[50],cust_email[50];
   			long int cust_phone;
            float totamount;
            int no_seats;
            tdate cDay;
	public :
            void view_book(int iscust);
            void view_book();
            void view_bookings();
            void book_tour();
   			void cancel_tour(int Whocalls);
    cust_tour()
  	{
    strcpy(tourname,"0/");
    strcpy(place,"0/");
    strcpy(day,"0/");
    strcpy(cust_name,"0/");
    strcpy(cust_email,"0/");
    cust_phone=tour_no=totamount=no_seats=0;
    tariff=0;
    cDay.yy=2014;
   }


};

/*************   CUST_TOUR : MEMBER FUNCTIONS     **************/

	void cust_tour::book_tour()
{
	clrscr();
   cust_tour cust,c;
   admin_tour adm;

   fstream temp;

   temp.open("TOURS & TRAVELS DATA/TOUR_PACKAGES.dat",ios::binary|ios::in);
   if(!temp)
   {
     output_box_date_n_time();
     Info_popUp("\0","! !    NO TOUR PACKAGES    ! !","\0",0);
     getch();
     temp.close();
     customer();
   }

  output_box_date_n_time();
  textcolor(2);
   gotoxy(43,18);cputs(" ENTER YOUR NAME           :        ");
  titlebox("*  *   BOOK MY TOUR   *  *",79,18);
   gotoxy(43,18);cputs(" ENTER YOUR NAME           :        ");
   gets(cust.cust_name);
   gotoxy(43,22);cputs(" ENTER YOUR EMAIL          :        ");
   gets(cust.cust_email);
   cust.cust_phone=take_correct_input(" ENTER YOUR PHONE          :       ",43,26);
  textcolor(2);
   gotoxy(40,33);cputs(" PLEASE SELECT TOUR PACKAGE.....");
   getch();

  clrscr();
  output_box_date_n_time();

  int tm=adm.view_tour('C');

  clrscr();
  output_box_date_n_time();
  textcolor(2);

   gotoxy(52,14);cputs("PLEASE ENTER DATE OF JOURNEY");
  do
   {
    textcolor(2);
     gotoxy(76,18);cout<<"\t\t\t";
     gotoxy(45,18);cputs("ENTER MONTH (In Digits.)        :        ");
     titlebox("*  *   BOOK MY TOUR   *  *",86,18);
     cust.cDay.mm=take_correct_input("ENTER MONTH (In Digits.)        :       ",45,18);
   }while(!((cust.cDay.mm>=1)&&(cust.cDay.mm<=12)));

  do{
   textcolor(2);
    gotoxy(76,21);cout<<"\t\t\t";
    cust.cDay.dd=take_correct_input("ENTER DATE                      :       ",45,21);
  }while(!((cust.cDay.dd>=1)&&(cust.cDay.dd<=31)));

  textcolor(2);
  cust.no_seats=take_correct_input("PLEASE ENTER NO. OF TICKEST REQUIRED     :   ",42,27);

  temp.close();

  cust.tour_no=give_id(2);

  if(user_confirmation("DO YOU WANT TO BOOK THIS  ?")) customer();

  fstream temp2;
  temp2.open("TOURS & TRAVELS DATA/TOUR_BOOKINGS.dat",ios::binary|ios::app);
  fstream t;
  t.open("TOURS & TRAVELS DATA/TOUR_PACKAGES.dat",ios::binary|ios::in);
  while(1)
 {
  t.read((char*)&adm,sizeof(admin_tour));

  if(t.eof()) break;

  if(tm==adm.tour_no)
  {
   strcpy(cust.tourname,adm.tourname);
   strcpy(cust.place,adm.place);
   strcpy(cust.details,adm.details);
   strcpy(cust.day,adm.day);
   strcpy(cust.city,adm.city);
   cust.totamount=cust.no_seats*adm.tariff;
   temp2.write((char*)&cust,sizeof(cust_tour));
  }
}
 t.close();
 temp2.close();

loading("!!    SENDING  REQUEST    !!","PLEASE WAIT");
Info_popUp("!!     BOOKING  IS  SUCCESSFUL     !!","PLEASE  REMEMBER  YOUR  ID","BOOKING  ID  is ",cust.tour_no);

 clrscr();
 cust.view_book(0);
 getch();
 user_confirmation("Do You Want To PRINT This ?");
 loading("! !  PRINTING   ! !","PLEASE WAIT");
 getch();
}


   void cust_tour::view_book(int iscust)
{

 clrscr();
 output_box_date_n_time();
 textcolor(3);
 int i;
 for(i=15;i<43;i++){ gotoxy(31,i); putch(178); }
 for(i=15;i<43;i++){ gotoxy(101,i); putch(178); }

 gotoxy(31,14);for(i=0;i<71;i++) putch(220);
 gotoxy(32,18);for(i=0;i<69;i++) putch(220);
 gotoxy(32,33);for(i=0;i<69;i++) putch(220);
 gotoxy(54,35);for(i=0;i<28;i++) putch(224);
 gotoxy(32,23);for(i=0;i<69;i++) putch(220);
 gotoxy(54,38);for(i=0;i<28;i++) putch(224);
 gotoxy(31,42);for(i=0;i<71;i++) putch(223);

 textcolor(4);
  gotoxy(49,16);cputs("##          TOUR TICKET          ##");
 textcolor(2);
  gotoxy(44,20);cputs("CUSTOMER NAME            :");gotoxy(77,20);puts(cust_name);
  gotoxy(44,21);cputs("CUSTOMER PHONE           :");gotoxy(77,21);cout<<cust_phone;
  gotoxy(44,22);cputs("CUSTOMER EMAIL           :");gotoxy(77,22);puts(cust_email);
  gotoxy(45,26);cputs("TOUR NAME               :");gotoxy(76,26);puts(tourname);
  gotoxy(45,27);cputs("TOUR CITY               :");gotoxy(76,27);puts(city);
  gotoxy(45,29);cputs("DATE OF JOURNEY         :");gotoxy(76,29);cout<<cDay.dd<<" / "<<cDay.mm<<" / "<<"2014";
  gotoxy(45,31);cputs("No. OF PERSONS          :");gotoxy(76,31);cout<<no_seats;
 textcolor(5);
  gotoxy(53,36);putch(224);putch(224);cputs("      TOTAL AMOUNT :      ");putch(224);putch(224);
  gotoxy(53,37);putch(224);putch(224);cputs("       Rs. ");cout<<totamount; gotoxy(81,37); putch(224);putch(224);
  gotoxy(38,40);cputs("Rs. :");No_coverter_caller(totamount);cout<<" - ONLY ";
  getch();
}

   void cust_tour::view_book()
{
 clrscr();
 output_box_date_n_time();

 fstream fin;

 fin.open("TOURS & TRAVELS DATA/TOUR_BOOKINGS.dat",ios::binary|ios::in);
 if(!fin)
 {
  Info_popUp("\0","! !    NO TOUR BOOKINGS    ! !","\0",0);
  getch();
  fin.close();
  admin();
 }

 int totaldetails=give_datacount(2);

 char opt1,opt2;
 cust_tour custm[30];

 int i=0;

 while(1)
   {
    fin.read((char*)&custm[i],sizeof(cust_tour));
    i++;
    if(fin.eof()) break;
   }

 i=0;
 fin.close();

 custm[i].view_bookings();
 titlebox("*  *   TOUR BOOKINGS   *  *");
 CursorControl(0);

 do
  {
  opt1=getch();
   if(opt1==13)
   {
    admin();
   }

   else if(opt1==0)
   {
   do
     {
      opt2=getch();

       switch(opt2)
      {
       	case 77 : if(i==(totaldetails-1))
           			 i=0;
                   else  i++;
                   break;

         case 75 : if(i==0)
           			 i=totaldetails-1;
                   else  i--;
                   break;
        default : break;
      };

         clear_area_for_view_tour();
         custm[i].view_bookings();
         titlebox("*  *   TOUR BOOKINGS   *  *");
         CursorControl(0);

         do
         {
            opt1=getch();

            if(opt1==0) break;
       else if(opt1==13) admin();

         }while(1);
      }while(1);
    }
   }while(1);

}

  void cust_tour::view_bookings()
{
 textcolor(3);
  gotoxy(10,13);for(int i=0;i<112;i++) putch(205);
 textcolor(1);
  gotoxy(44,17);cputs("BOOKING ID         --       ");cout<<tour_no;
 textcolor(2);
  gotoxy(36,21);cputs("CUSTOMER NAME              ::         ");puts(cust_name);
  gotoxy(36,25);cputs("CUSTOMER EMAIL             ::         ");puts(cust_email);
  gotoxy(36,28);cputs("CUSTOMER PHONE             ::         ");cout<<cust_phone;
  gotoxy(36,31);cputs("TOUR NAME                  ::         ");puts(tourname);
  gotoxy(36,34);cputs("TOUR DATE                  ::         ");cout<<cDay.dd<<" / "<<cDay.mm<<" / "<<"2014";
  gotoxy(36,37);cputs("TOTAL AMOUNT               ::         Rs. ");cout<<totamount;
  gotoxy(36,40);cputs("  Only Rs.       -         Rs.  ");
  No_coverter_caller(totamount);
  textcolor(3);
  gotoxy(10,44);for(int i=0;i<112;i++) putch(205);

 textcolor(15);
  gotoxy(15,46); cputs("<=========");
  gotoxy(107,46);cputs("=========>");
 textcolor(5);
  gotoxy(17,48);cputs("PREVIOUS");
  gotoxy(109,48);cputs("NEXT");
}

  void cust_tour::cancel_tour(int Whocalls)
{
 clrscr();

 output_box_date_n_time();

 cust_tour cust;

 int id;
 int datacount=0;
 fstream oldf,newf;

 oldf.open("TOURS & TRAVELS DATA/TOUR_BOOKINGS.dat",ios::binary|ios::in);
 if(!oldf)
 {
  Info_popUp("\0","! !    NO TOUR BOOKINGS    ! !","\0",0);
  getch();
  oldf.close();
  customer();
 }
  textcolor(2);
  gotoxy(45,17);cputs("PLEASE ENTER YOU BOOKING ID    :  ");
  titlebox("*  *   MY TOUR BOOKING  *  * ",80,17);

  id=take_correct_input("PLEASE ENTER YOU BOOKING ID    : ",45,17);
  textcolor(2);

  int found=0;
  while(1)
  {
   oldf.read((char*)&cust,sizeof(cust_tour));
    if(oldf.eof()) break;

    if(id==cust.tour_no)
  	{
    cust.view_book(0);
    found++;
   }
   datacount++;

   }

  oldf.close();

    if(!found)
  	{
  	show_error();
   getch();
   customer();
   }

  if(Whocalls==0) customer();

  fstream oldff;

   oldff.open("TOURS & TRAVELS DATA/TOUR_BOOKINGS.dat",ios::binary|ios::in);
   newf.open("TOURS & TRAVELS DATA/temp.dat",ios::binary|ios::out);

  while(!oldff.eof())
  {
   oldff.read((char*)&cust,sizeof(cust_tour));

   if(oldff.eof()) break;

   if(id==cust.tour_no)
 {
    if((!(user_confirmation("DO YOU WANT TO CANCEL THIS  ?"))))
  {
   loading("!!    SENDING  REQUEST    !!","PLEASE WAIT");
   Info_popUp("!!   CANCELLATION  SUCCESSFULL   !!","BOOKING  HAS  BEEN  CANCELLED","YOUR  ID  was  - ",id);
   getch();
	}

    else
  {
   datacount=0;
   newf.write((char*)&cust,sizeof(cust_tour));
  }
 }
  else
  {
   newf.write((char*)&cust,sizeof(cust_tour));
  }
 }

 newf.close();
 oldff.close();

 remove("TOURS & TRAVELS DATA/TOUR_BOOKINGS.dat");
 rename("TOURS & TRAVELS DATA/temp.dat","TOURS & TRAVELS DATA/TOUR_BOOKINGS.dat");

 empty_file_remove("TOURS & TRAVELS DATA/TOUR_BOOKINGS.dat",datacount);

}


/* ------------------------------------------------------*/
/*----------------  MENU MENU FUNCTIONS  ---------------- */
/* ------------------------------------------------------*/

	void main()
{
	SetWindow(131,51);
   mkdir("TOURS & TRAVELS DATA");
   CursorControl(0);
   Mv_logo();
   textcolor(15);
   int i;
    gotoxy(23,7);
	 for(int i=23,j=106;i<107;i++,j--)
   {
     gotoxy(i,7);Sleep(5);putch(177);
     gotoxy(j,21);
     Sleep(12); putch(177);
   }
    for(int i=8,j=21;i<22;i++,j--)
	{	gotoxy(23,j); putch(177); gotoxy(106,i); putch(177);  Sleep(50);}
   Sleep(400);

   textcolor(12);
	 gotoxy(34,12);cputs("#     #    ####    #        ####     ####     #     #    #### ");Sleep(250);
	 gotoxy(34,13);cputs("#     #    #       #       #        #    #    # # # #    #    ");Sleep(250);
	 gotoxy(34,14);cputs("#  #  #    ####    #       #        #    #    #  #  #    #### ");Sleep(250);
	 gotoxy(34,15);cputs("# # # #    #       #       #        #    #    #     #    #    ");Sleep(250);
	 gotoxy(34,16);cputs("#     #    ####    #####    ####     ####     #     #    #### ");Sleep(250);

    textcolor(15);
     gotoxy(23,26);

	  for(i=0;i<84;i++) { putch(177); }
     gotoxy(23,38);
	  for(i=0;i<84;i++) { putch(177); }
     for(i=26;i<38;i++)
	 { 	gotoxy(23,i); putch(177); gotoxy(106,i); putch(177); Sleep(50); }

   textcolor(10);

   char str[]="    THE  MV  TOURS AND TRAVELS   ";
   char str1[]="      MADE BY -  M. VIGNESH      ";

    for(int i=0,j=strlen(str1);str[i];i++,j--)
    {
    	gotoxy(47+i,30);putch(str[i]);Sleep(35);
      gotoxy(47+j,33);putch(str1[j]);Sleep(35);
    }

   Sleep(200);

   while(!kbhit())
  {
     gotoxy(47,30);cout<<"\t\t\t\t\t\t";
     gotoxy(47,33);cout<<"\t\t\t\t\t\t";
     Sleep(250);
     gotoxy(47,30);cputs(str);
     gotoxy(47,33);cputs(str1);
     Sleep(700);
  }
    CursorControl(1);
	 getch(); clrscr();

    menu();
}

   void menu()
{
	clrscr();
	output_box_date_n_time();

   char opt1;

   textcolor(3);
   gotoxy(48,7);

	    textcolor(6);
		 gotoxy(55,23);
   	cputs("<>   ADMINISTRATOR");
		 gotoxy(55,29);
		cputs("<>   CUSTOMER");

  textcolor(8);
   gotoxy(46,45);cputs("(  *  *   Press Esc To Go Back   *  *  )");
	gotoxy(38,48);
   cputs("(   Use Up And Down Arrow To Select And Press Enter   )");

  textcolor(15);
      gotoxy(42,23);
      cputs("======>");
      gotoxy(80,23);
      cputs("<======");

      titlebox("!!    PLEASE SELECT YOUR ACCOUNT    !!");
      CursorControl(0);

      int pos=0;
 do
 {

 opt1=getch();

      if(opt1==13)
      {
   	if(pos==0)
      	{
   		pass();
         }
      else
   	   {
      	customer();
      	}
      }

   else if(opt1==27)
   	{
        if(user_confirmation("DO YOU WANT TO EXIT ?"))
       {
        	menu();
       }
        else
       {
        CursorControl(0);
        textbackground(1);
        int x=30;
         while(x-->22)
         {
        int y=17;
          while(y++<30)
          {
        gotoxy(49,y);cputs("                                   ");
          }
        gotoxy(49,x);cputs("     !!  THANKS FOR USING  !!      ");
           if(x<26)
           {
        gotoxy(49,x+4);cputs("          By : M.VIGNESH           ");
           }
        Sleep(150);
          }
        Sleep(2000);
        exit(0);
        }
      }

   else if((opt1==72)||(opt1==80))
 {
 		if(pos==0) pos=1;
   		else pos=0;

         switch(pos)
      {
        	case 0:  textcolor(15);
         			gotoxy(42,23); cputs("======>");
         	      gotoxy(42,29); cputs("       ");
                  gotoxy(80,23); cputs("<======");
                  gotoxy(80,29); cputs("       ");
                  break;

         case 1 : textcolor(15);
         			gotoxy(42,23); cputs("       ");
                  gotoxy(42,29); cputs("======>");
                  gotoxy(80,23); cputs("       ");
                 	gotoxy(80,29); cputs("<======");
                  break;

         default : break;
      };
      titlebox("!!    PLEASE SELECT YOUR ACCOUNT    !!");
      CursorControl(0);
 }

}while(1);

}


   void admin()
{
 clrscr();

 admin_tour adm;
 cust_tour cust;
 TRAVELS trvl;

   output_box_date_n_time();

   textcolor(5);

   gotoxy(54,18);cputs("<>  View Tour Bookings ");
   gotoxy(54,21);cputs("<>  View Travels Bookings ");
   gotoxy(54,24);cputs("<>  Create Tour Packages");
   gotoxy(54,27);cputs("<>  View Tour Packages ");
   gotoxy(54,30);cputs("<>  Modify Tour Packages ");
   gotoxy(54,33);cputs("<>  Delete Tour Packages ");
   gotoxy(54,36);cputs("<>  Change Password ");

   textcolor(8);
   gotoxy(46,45);cputs("(  *  *   Press Esc To Go Back   *  *  )");
   gotoxy(38,48);cputs("(   Use Up And Down Arrows To Select And Press Enter   )");

   char opt1,opt2;
   int x=44,y=18;

	gotoxy(x,y);textcolor(15);cputs("=====>");


   titlebox("*  *  ADMINISTRATOR MENU  *  *");
   CursorControl(0);
   do{
   opt1=getch();

   }while(!((opt1==13)||(opt1==27)||(opt1==0)));
   if(opt1==27) menu();

   else if(opt1==13)
   {
	 	 	cust.view_book();

        	clrscr();

         admin();
   }
    else if(opt1==0)
       {

       	do
         {
         opt2=getch();

 switch(opt2)
 {
  	case 72 : if(y==18) y=36;
     			 else y-=3;
             break;

	case 80:  if(y==36) y=18;
    			 else y+=3;
             break;

   default : break;
 };

    	do
       {
        show_blanks_in_Admin();

        gotoxy(x,y);textcolor(15);cputs("=====>");

        titlebox("*  *  ADMINISTRATOR MENU  *  *");
        CursorControl(0);
        opt1=getch();

           if(opt1==0) break;

           if(opt1==27) menu();

           if(opt1==13)
             {
		      if(y==18)
            {
             cust.view_book();
             clrscr();
             admin();
		   	}
		else if(y==21)
             {
                trvl.view_book();
                admin();
             }

      else if(y==24)
           {
				adm.entry();
            clrscr();
			  	admin();
           }
       else if(y==27)
           {
            clrscr();
            output_box_date_n_time();
        		adm.view_tour('A');
            admin();
           }

		else if(y==30)
           {
            adm.modify_tour();
            admin();
           }
      else if(y==33)
           {
            adm.remove_tour();
            admin();
           }
      else if(y==36)
           {
            change_pass();
            admin();
           }
      }
      }while(!((opt1==0)||(opt1==13)||(opt1==27)));

	}while(1);

 }
}


	void customer()
{
 clrscr();
 output_box_date_n_time();

 cust_tour cust;
 TRAVELS trvl;


  textcolor(5);
   gotoxy(54,20);cputs("<>  Book My Tour");
   gotoxy(54,23);cputs("<>  Book My Travels ");
   gotoxy(54,26);cputs("<>  View My Tour Bookings");
   gotoxy(54,29);cputs("<>  View My Travel Bookings");
   gotoxy(54,32);cputs("<>  Cancel My Tour Bookings ");
   gotoxy(54,35);cputs("<>  Cancel My Travel Bookings ");

  textcolor(8);
   gotoxy(46,45);cputs("( *  *   Press Esc To Go Back   *  * )");
   gotoxy(38,48);cputs("(   Use Up And Down Arrows To Select And Press Enter   )");

   char opt1,opt2;
   int x=45,y=20;


   gotoxy(x,y);textcolor(15);cputs("=====>");
   titlebox("*  *    CUSTOMER  MENU    *  *");
   CursorControl(0);
   do
   {
   opt1=getch();

   }while(!((opt1==13)||(opt1==27)||(opt1==0)));

   if(opt1==27) menu();

   else if(opt1==13)
       {
        cust.book_tour();clrscr();
        customer();
       }

   else if(opt1==0)
 {
			do
         {
         opt2=getch();

    switch(opt2)
    {
     	case 72 : if(y==20) y=35;
     				 else y-=3;
                break;

		case 80 : if(y==35) y=20;
     				 else y+=3;
                break;

      default : break;
    };

    do
     {
     show_blanks_in_Customer();
      gotoxy(x,y);textcolor(15);cputs("=====>");

      titlebox("*  *    CUSTOMER  MENU    *  *");
      CursorControl(0);
      opt1=getch();

      if(opt1==0) break;

      if(opt1==27) menu();

      if(opt1==13)
      {
         if(y==20)
          {
             cust.book_tour();clrscr();
             customer();
             break;
          }

       	else if(y==23)
         {
          trvl.book_TRAVELS();
          customer();
          break;
         }
         else if(y==26)
         {
          cust.cancel_tour(0);
          customer();
          break;
         }
         else if(y==29)
         {
          trvl.cancel_travel(0);
          customer();
          break;
         }
         else if(y==32)
         {
          cust.cancel_tour(1);
          customer();
          break;
         }
         else if(y==35)
        {
        	trvl.cancel_travel(1);
         customer();
         break;
        }

       }
		}while(!((opt1==0)||(opt1==13)||(opt1==27)));
     }while(1);
	}

}


	void pass()
{
	clrscr();

   int attempts=3;
   char passwrd[7];

   fstream passfile;
   passfile.open("TOURS & TRAVELS DATA/ADMIN_PASS.dat",ios::binary|ios::in);

   admin_pass A;

   passfile.read((char*)&A,sizeof(admin_pass));
   A.getcode(passwrd);
   output_box_date_n_time();
   textcolor(6);
   gotoxy(50,17);
	cputs("  Authentication Required   ");
   gotoxy(54,24);
   textcolor(4);
   cputs("Pass   :");
   textcolor(4);
   gotoxy(54,21);
   CursorControl(1);
   char *str=" Administrator";
   cputs("User   :  ");
   for(int i=0;str[i];i++)
      {
   	cout<<str[i];
      Sleep(250);
      }
   CursorControl(0);

   do{
   int len=strlen(passwrd);

   output_box_date_n_time();

	char tmp;
   char PAS[10];
   textcolor(6);

   gotoxy(44,17);cout<"                                  ";
   gotoxy(50,17);
	cputs("  Authentication Required   ");cputs("( ");cout<<attempts;cputs(" )");
   attempts-=1;;
   textcolor(7);
   gotoxy(40,46);
   cputs("     * *  (  Press Escape To Go Back  )  * *");
   textcolor(8);
   gotoxy(54,25);
   textcolor(15);
   cputs("                          ");
   gotoxy(54,24);
   textcolor(4);
   cputs("Pass   :");
   gotoxy(65,24);
   textcolor(8);
   for(int c=0;c<len;c++)
   	cputs("-");
   lock(0);
	gotoxy(65,24);
   int i=0;
	while(1)
	{
   	tmp=getch();

     if((i+1)>strlen(passwrd))
     {
     if(tmp==13)
		{
      PAS[i]='\0';
		break;
		}

     else if(tmp==8)
     {
      if(i!=0)
      {
      	if(i<=len)
      	cout<<'\b'<<"-"<<'\b';
         else
         cout<<'\b'<<" "<<'\b';
      	i--;
      }
     }
     }
     else if(tmp==27 )
      {
     	menu();
      }

	 else if(tmp==13)
		{
      PAS[i]='\0';
		break;
		}

    else if(tmp==8)
     {
      if(i!=0)
      {
      	if(i<=len)
      	cout<<'\b'<<"-"<<'\b';
         else
         cout<<'\b'<<" "<<'\b';
      	i--;
      }
     }

     else
     {
     	PAS[i]=tmp;
      i++;
      textcolor(8);
      cputs("*");
     }
   }
			if(!strcmp(PAS,passwrd))
				{
      				lock(1);
                  Sleep(1000);
                  admin();
      		}
	else
   {
      lock(0);
      if(attempts==0)
      {
      	authentication_wait(9);
         pass();
		}
   }
 }while(1);
}


	void change_pass()
{
  clrscr();
  output_box_date_n_time();


  char passwrd[10];

  fstream passfile;
  passfile.open("TOURS & TRAVELS DATA/ADMIN_PASS.dat",ios::binary|ios::in);

  admin_pass A;

  passfile.read((char*)&A,sizeof(admin_pass));

  A.getcode(passwrd);
  passfile.close();

  char tmp;

  do{

   output_box_date_n_time();

	char PAS[10];
   unsigned int i=0;
   textcolor(6);

   gotoxy(40,17);cout<"                                  ";
   gotoxy(50,20);
	cputs("PLEASE ENTER THE OLD PASSWORD   ");

   textcolor(8);
   gotoxy(47,46);
   cputs("**  ( Press Escape To Go Back )  **");

   gotoxy(60,23);
	for(unsigned int c=0;c<strlen(passwrd);c++)
   	cputs("-");

   titlebox("*  *   CHANGE MY PASSWORD   *  *",60,23);
   textcolor(7);
   gotoxy(60,23);
	for(unsigned int c=0;c<strlen(passwrd);c++)
   	cputs("-");
	gotoxy(60,23);
   while(1)
   {
     if(i>15) break;
	  tmp=getch();

     if(tmp==27 )
      {
     	admin();
      }

	  else if(tmp==13 )
		{
      PAS[i]='\0';
		break;
		}

    else if(tmp==8)
     {
      if(i!=0)
      {
      if(i<=strlen(passwrd))
      	cout<<'\b'<<"-"<<'\b';
         else
      cout<<'\b'<<" "<<'\b';
      i--;
      }
     }

     else
     {
     	PAS[i]=tmp;
      i++;
      cputs("*");
     }
   }

  if(!strcmp(PAS,passwrd))
  {
  		break;
  }
  else
   {
    gotoxy(55,35);
    textcolor(2);
    cputs(" WRONG  PASSWORD ");
    getch();
    admin();
   }

   break;

	}while(1);

	clrscr();
   output_box_date_n_time();

   textcolor(4);
   gotoxy(50,20);cputs("ENTER A NEW PASSWORD ");
   titlebox("*  *   CHANGE MY PASSWORD   *  *",47,22);

   char checkpass1[6];
   char checkpass2[6];
   int i=0;
   gotoxy(47,22);
   while(1)
   {
     if(i>15) break;
	  tmp=getch();
     if(tmp==27 )
      {
     	admin();
      }

	  else if(tmp==13 )
		{
		checkpass1[i]='\0';
		break;
		}
     else if(tmp==8)
     {
      if(i!=0)
      {
         cout<<'\b'<<" "<<'\b';
      	i--;
      }
     }
		else
     {
     	checkpass1[i]=tmp;
      i++;
      cputs("*");
     }
   }
   textcolor(4);
   gotoxy(50,24);cputs("ENTER THE PASSWORD AGAIN");
   gotoxy(47,26);
   i=0;
   textcolor(2);
   while(1)
   {
	  tmp=getch();

     if(tmp==27 )
      {
     	admin();
      }

	  else if(tmp==13 )
		{
		checkpass2[i]='\0';
		break;
		}
     else if(tmp==8)
     {
      if(i!=0)
      {
      cout<<'\b'<<" "<<'\b';
      i--;
      }
     }
		else
     {
     	checkpass2[i]=tmp;
      i++;
      cputs("*");
     }
   }
      if(!strcmp(checkpass1,checkpass2))
      {
      textcolor(2);
      gotoxy(57,34);cputs("PASSWORD CHANGED");
      getch();

      A.givecode(checkpass2);
      passfile.open("TOURS & TRAVELS DATA/ADMIN_PASS.dat",ios::binary|ios::out);
      passfile.write((char*)&A,sizeof(admin_pass));
      passfile.close();

      }

      else
      {
      	textcolor(2);
         gotoxy(55,28);cputs("PASSWORD DON'T MATCH");
         gotoxy(55,30);cputs("    TRY AGAIN");
      	getch();
      }
  }


	int give_id(int type)
{
 int rtn;
 fstream file;
 admin_tour adm;
 cust_tour cust;
 TRAVELS trvl;

 switch(type)
 {
 case 1 : file.open("TOURS & TRAVELS DATA/TOUR_PACKAGES.dat",ios::binary|ios::in);
			 if(!file) return 1;

			 while(!file.eof())
			 {
   			file.read((char*)&adm,sizeof(admin_tour));
   		 }
   		 rtn=(adm.tour_no+1);
   		 file.close();
   		 return rtn;

 case 2 : file.open("TOURS & TRAVELS DATA/TOUR_BOOKINGS.dat",ios::binary|ios::in);
          if(!file) return 111;

			while(!file.eof())
		 {
   	  file.read((char*)&cust,sizeof(cust_tour));
   	 }
   	  rtn=(cust.tour_no+111);
   	  file.close();
   	  return rtn;

case 3 : file.open("TOURS & TRAVELS DATA/TRAVEL_BOOKINGS.dat",ios::binary|ios::in);
			if(!file) return 111;

			while(!file.eof())
		  {
   	   file.read((char*)&trvl,sizeof(TRAVELS));
   	  }
   	   rtn=(trvl.travel_id+111);
   	   file.close();
         return rtn;
	};
   return 0;
}

	int give_datacount(int type)
{
 int rtn=0;
 fstream file;
 admin_tour adm;
 cust_tour cust;
 TRAVELS trvl;

  switch(type)
 {

 case 1 : file.open("TOURS & TRAVELS DATA/TOUR_PACKAGES.dat",ios::binary|ios::in);
			if(!file) return 1;

		    while(1)
    	   {
          file.read((char*)&adm,sizeof(admin_tour));
          if(file.eof()) break;
          rtn++;
   	   }
   	   file.close();
   	   return rtn;

case 2 : file.open("TOURS & TRAVELS DATA/TOUR_BOOKINGS.dat",ios::binary|ios::in);
         if(!file) return 1;

			while(1)
		  {
         file.read((char*)&cust,sizeof(cust_tour));
		   if(file.eof()) break;
         rtn++;
   	  }
        file.close();
   	  return rtn;

case 3 : file.open("TOURS & TRAVELS DATA/TRAVEL_BOOKINGS.dat",ios::binary|ios::in);
			if(!file) return 1;

			while(1)
        {
   	   file.read((char*)&trvl,sizeof(TRAVELS));
         if(file.eof()) break;
         rtn++;
        }
        file.close();
   	  return rtn;
	};
   return 0;
}
