#include<fstream.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<dos.h>
#include<windows.h>

#define end cout<<endl;

char city_list[][30]={"AGRA","AHMEDABAD","BANGALORE","MUMBAI",
							"KOLKATA","DELHI","HYDERABAD","JAIPUR"
					  	  ,"LUCKNOW","CHENNAI","PUNE","SRINAGAR",};

char *one[]={" "," One"," Two"," Three"," Four"," Five"," Six",
            " Seven"," Eight"," Nine"," Ten"," Eleven"," Twelve",
				" Thirteen"," Fourteen"," Fifteen"," Sixteen",
            " Seventeen"," Eighteen"," Nineteen"};

char *ten[]={" "," "," Twenty"," Thirty"," Forty"," Fifty",
				 " Sixty", " Seventy"," Eighty"," Ninety"};


/****************************************************************************************/

int i;

void menu();
void pass();

void admin();
void customer();

/*************   SPF   **************/

void output_box_date_n_time(int check_if_end_needed,char title[]);
void No_converter(long,char[]);
void No_coverter_caller(int n);
void empty_file_remove(char file[],int check);
void Info_popUp(char TITLE[],char subTITLE[],char sub2TITLE[],int Var);
void loading(char TITLE[],char subTITLE[]);
int user_confirmation(char TITLE[],char subTITLE[]);
void Mv_logo();
void clear_area_for_view_tour();
void change_pass();
int take_correct_numeric_value(float &input);
void lock(int valcheck);
int confirmation();
void authentication_wait(int sec);
void show_error();
int give_id(int type);
int give_datacount(int type);


void show_blanks_in_modify_tour();
void show_blanks_in_Admin();
void show_blanks_in_Customer();





/*************   AREA CLEAR FUNCTION   **************/

void clear_area_for_view_tour()
{
  for(int x=68;x<122;x++)
	for(int y=17;y<41;y++)
   	{
      gotoxy(x,y);cout<<" ";
		}
}

void show_blanks_in_Customer()
{
	int x=5;
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
	gotoxy(13,27+x*3);cout<<"     ";
   gotoxy(38,47);cout<<"       ";

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



/*************   AREA CLEAR FUNCTION   **************/



/*************   COLOURED POPUP BOXES   **************/



void Info_popUp(char TITLE[],char subTITLE[]="\0",char sub2TITLE[]="\0",int Var=0)
{
   int len=strlen(TITLE);
   int len2=strlen(subTITLE);
   int len3=strlen(sub2TITLE);

  textbackground(6);
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
   gotoxy(40+((44-len3)/2),30);cputs(sub2TITLE);cputs("   :   ");cprintf("%d",Var);
   Sleep(600);
   gotoxy(45+((44-len)/2),19);int n=len; while(n-->0) cputs(" ");
   gotoxy(45+((44-len2)/2),23);n=len2; while(n-->0) cputs(" ");

   Sleep(200);

   }
   textbackground(0);

}



void loading(char TITLE[],char subTITLE[])
{
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

  	gotoxy(52,29);putch(219); 	gotoxy(80,29);putch(219);


   gotoxy(52,30);putch(223);
   				for(int i=0;i<27;i++)
   				{
               	putch(223);
               }
               putch(223);

    gotoxy(55,29);textbackground(4);cputs("                         ");


  int l=0,i=0,loop=2; //looping looding loop = no of times for loads
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
   if(i==5) {
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

}

int user_confirmation(char TITLE[],char subTITLE[]="\0")
{
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
   gotoxy(44+((44-len2)/2),24);cputs(subTITLE);

int op1,op2;
char opt1,opt2;

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

 op1=opt1;
 if(op1==13)
 	{
   	if(pos==0)
      	{
   textbackground(1);
   gotoxy(57,25);cputs("                  ");
   gotoxy(57,26);cputs("     CONTINUE     ");
   gotoxy(57,27);cputs("                  ");
   Sleep(1000);
   textbackground(0);
         return 0;
         }
      else
      {
      textbackground(1);
      gotoxy(57,29);cputs("                  ");
      gotoxy(57,30);cputs("     CANCELED     ");
      gotoxy(57,31);cputs("                  ");
      Sleep(1200);
         textbackground(0);
      	return 1;
      }
   }

 else  if((op1==72)||(op1==80))
 {
   if(pos==0) pos=1;
   else pos=0;

 	switch(pos)
   {
 	case 0 :
   			 textbackground(5);
             gotoxy(57,25);cputs("                  ");
             gotoxy(57,26);cputs("     CONTINUE     ");
             gotoxy(57,27);cputs("                  ");
             textbackground(4);
             gotoxy(57,29);cputs("                  ");
             gotoxy(57,30);cputs("      CANCEL      ");
             gotoxy(57,31);cputs("                  ");

             break;
   case 1 :
   			 textbackground(4);
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

/*************   COLOURED POPUP BOXES   **************/

void Mv_logo()
{
  int x=23,y=18;
   kbhit();
   highvideo();
  int n=100;
  while(n-->0)
  {
  textcolor(random(16));
  y=8;
  while(y!=48)
  {
  gotoxy(x-7,y++);cputs("");
  }
  }
  clrscr();

  while(!kbhit())
  {
  y=18;
  textcolor(random(16)+6);
  gotoxy(x,y++);cputs("                                                   ");
  gotoxy(x,y++);cputs("                                                 ");
  gotoxy(x,y++);cputs("                                               ");
  gotoxy(x,y++);cputs("                                             ");
  gotoxy(x,y++);cputs("                                           ");
  gotoxy(x,y++);cputs("                                          ");
  gotoxy(x,y++);cputs("                                          ");
  gotoxy(x,y++);cputs("                                          ");
  gotoxy(x,y++);cputs("                                          ");
  gotoxy(x,y++);cputs("                                            ");
  gotoxy(x,y++);cputs("                                             ");
  gotoxy(x,y++);cputs("                                               ");
  gotoxy(x,y++);cputs("                                                          ");
  gotoxy(x,y++);cputs("                                                           ");
  gotoxy(x,y++);cputs("                                                            ");

  Sleep(50);

}
clrscr();
getch();

}


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
        	gotoxy(x,y);cout<<"\t\t\t\t\t";
         isdone=1;
   	}

 else {
   		input=val;
      	isdone=0;
   	}

   return isdone;
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
   int n=2;
   while(n-->0)
   {

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

    if(n==1)
    {
    gotoxy(57,31);x=3;while(x-->0) putch(ch);cout<<"         ";
    x=3;while(x-->0) putch(ch);
    }


      Sleep(500);
		textcolor(10);


    }
   }

}

int confirmation()
{
int ans;
textcolor(6);
cputs(" ARE YOU SURE YOU WANT TO CONTINUE ? (Y/N) ");
while(1)
{
ans=getch();

if((ans=='N')||(ans=='n'))
	{
   return 1;
   }
else  if((ans=='y')||(ans=='Y'))
		return 0;
}
} /* gotoxy(43,34);
   if(confirmation()) */

void authentication_wait(int sec)
{
	textcolor(3);
   gotoxy(55,17);
   cputs("PLEASE  WAIT   :   ");
   for(int i=sec;i>0;i--)
   	{
      gotoxy(73,17);cout<<i;
      Sleep(800);
      }
}



void show_error()
{
gotoxy(52,42);cout<<"!!!   WRONG OPTION   !!!";
}



void No_coverter_caller(int n)
{
		No_converter((n/10000000)," Crore ");
		No_converter(((n/100000)%100)," Lakh ");
		No_converter(((n/1000)%100)," Thousand ");
 		No_converter(((n/100)%10)," Hundred ");
 		No_converter((n%100)," ");
}

void No_converter(long n,char ch[])
{
 (n>19)?cout<<ten[n/10]<<one[n%10]:cout<<one[n];
 if(n) cout<<ch;
}


  void titlebox(char title[]="\0")
  {
   while(!kbhit())
   {
   textcolor(4);
  	gotoxy(66-(strlen(title)*0.5),7);textcolor(2);
	cputs(title);

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
	Sleep(40);   if(kbhit()) break;

   gotoxy(66-(strlen(title)*0.5),7);for(int i=0;i<strlen(title);i++) cputs(" ");

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

   }
   gotoxy(66-(strlen(title)*0.5),7);textcolor(2);
   cputs(title);
  }


void output_box_date_n_time(int check_if_end_needed=0)
{

textcolor(3);
gotoxy(5,2);putch(201);
for(int i=0;i<120;i++) putch(205);
putch(187);

for(i=3;i<8;i++)
{	gotoxy(5,i); putch(186); gotoxy(126,i); putch(186); }

gotoxy(5,8); putch(200);
for(i=0;i<120;i++) putch(205);
putch(188);

struct date d;
struct time t;

getdate(&d);
int day=d.da_day;
int mon=d.da_mon;
int year=d.da_year;

gettime(&t);
int hour=t.ti_hour;
int min=t.ti_min;

textcolor(4);
gotoxy(42,4);

cputs("---|        TOURS AND TRAVELS SYSTEM        |---");

textcolor(5);

gotoxy(107,7); cputs(" TIME  :  ");cprintf("%d",hour);cputs(":");cprintf("%d",min);
gotoxy(9,7);  cputs(" DATE  :  ");cprintf("%d",day);cputs("/");cprintf("%d",mon);cputs("/");cprintf("%d",year);

textcolor(3);

if(check_if_end_needed==0)
{
gotoxy(5,9);putch(201);
for(int i=0;i<120;i++) putch(205);
putch(187);

for(i=10;i<50;i++)
{	gotoxy(5,i); putch(186); gotoxy(126,i); putch(186); }

gotoxy(5,50); putch(200);
for(i=0;i<120;i++) putch(205);
putch(188);
}

/*else
{
for(int i=8;i<43;i++)
{	gotoxy(2,i); putch(186); gotoxy(79,i); putch(186); }
}*/

}

/*************   ADMIN PASS   **************/

class admin_pass
{
   private : char pass[10];

	public :
   admin_pass()
   {
   	strcpy(pass,"VIGZ");
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

/*************   ADMIN PASS   **************/


/*************   TRAVELS - CLASS    **************/

struct tdate
{
	int dd,mm,yy;
};


	class TRAVELS
{
	public : char mode_travel[20];
   			char cust_name[20],from[20],dest[20],email[20];
            int amount,no_tickets;
				int cust_phone,travel_id;
            tdate cDay;

            void view_TRAVELS();
            void view_city(int frm);
   			void book_TRAVELS();
            void view_book();
            void view_book(int check);
            void cancel_travel();
            void view_bookings();
				TRAVELS()
            {
					cDay.yy=2013;
               travel_id=0;
            }

};

/*************   TRAVELS - CLASS    **************/

/*************   TRAVELS - MEMBER FUNCTIONS    **************/

	  void TRAVELS::book_TRAVELS()
{
   TRAVELS trvl;
	clrscr();
   int frm,to,op;

   output_box_date_n_time(0);

   textcolor(2);
   gotoxy(55,7);cputs("* * BOOK MY TRAVEL  ");

   gotoxy(45,16);cputs("*  PLEASE ENTER THE FOLLOWING DETAILS  *");

   gotoxy(42,22);cputs("PLEASE ENTER YOUR NAME              :     ");
   gets(cust_name);

   gotoxy(42,26);cputs("PLEASE ENTER YOUR EMAIL              :     ");
   gets(email);

   gotoxy(42,30);cputs("PLEASE  ENTER YOUR PHONE NO.         :     ");
   cin>>cust_phone;

   do{
   clrscr();

   gotoxy(47,14);cout<<"* * SELECT YOOR PICKUP CITY  * *";

   view_city(99);

   gotoxy(64,43);cin>>frm;

   if(!((frm>=1)&&(frm<=12)))
   {
   show_error();
  	}
   }while(!((frm>=1)&&(frm<=12)));

   strcpy(from,city_list[frm-1]);

   do{
   clrscr();

   gotoxy(47,14);cout<<"* * SELECT YOUR DESTINATION CITY  * *";

   view_city(frm);
   gotoxy(64,43);cin>>to;

   if(!((frm>=1)&&(frm<=12)))
   {
	gotoxy(27,1);cout<<" ! ! WRONG OPTION ! !";
   }
   }
   while(!((to>=1)&&(to<=12)&&(frm!=to)));

   strcpy(dest,city_list[to-1]);

   clrscr();

   output_box_date_n_time(0);
   gotoxy(55,7);cout<<"* * BOOK MY TRAVEL  ";


   gotoxy(50,16);cout<<"PLEASE ENTER DATE OF JOURNEY";
   do
   {
   gotoxy(76,20);cout<<"\t\t\t\t\t\t\t";

   gotoxy(45,20);cout<<"ENTER MONTH (In Digits.)            :         ";
   cin>>cDay.mm;
   }while(!((cDay.mm>=1)&&(cDay.mm<=12)));

   do
   {
   gotoxy(76,21);cout<<"\t\t\t\t\t\t\t";
   gotoxy(45,23);cout<<"ENTER DATE                          :         ";
   cin>>cDay.dd;
   }while(!((cDay.mm>=1)&&(cDay.mm<=31)));


   gotoxy(41,28);cout<<"PLEASE ENTER NO. OF TICKEST REQUIRED      :     ";
   cin>>no_tickets;

   do
   {
   gotoxy(50,31);cout<<"PLEASE CHOOSE MODE OF TRAVEL ";
   gotoxy(47,35);cout<<"1. BUS         ( A/C and VOLVO )";
   gotoxy(47,37);cout<<"2. MINI VAN        (PRIVATE)";
   gotoxy(47,39);cout<<"3. TAXI            (PRIVATE)\n\n\t\t\t\t\t\t";cin>>op;
   }while(!((op==1)||(op==2)||(op==3)));
   if(op==1) strcpy(mode_travel,"BUS");
   else if(op==2) strcpy(mode_travel,"MINI VAN");
   else if(op==3) strcpy(mode_travel,"TAXI");
   randomize();
   amount=((random(5)*3000-random(5)*100)*no_tickets);
   travel_id=give_id(3);

	gotoxy(52,44);cout<<" ! ! BOOKING SUCCESS  ! !";

   gotoxy(50,46);cout<<"Your Booking Id is   -    ";
   cout<<travel_id;
   gotoxy(43,48);cout<<"!!  Please Remember It For Future Purposes  !!";

	getch();
   clrscr();
   output_box_date_n_time(0);


   view_book(1);
   }


      void TRAVELS::view_book(int check)

{

   for(i=12;i<40;i++){ gotoxy(31,i);putch(178); }
	for(i=12;i<40;i++){ gotoxy(100,i);putch(178); }

textcolor(1);
gotoxy(31,11);for(i=0;i<69;i++) putch(205);
gotoxy(59,13);cout<<"##  TRIP TICKET  ##";
gotoxy(31,15);for(i=0;i<69;i++) putch(205);
gotoxy(44,17);cout<<"CUSTOMER   NAME          :";gotoxy(80,17);puts(cust_name);
gotoxy(44,18);cout<<"CUSTOMER   PHONE         :";gotoxy(80,18);cout<<(cust_phone);
gotoxy(44,19);cout<<"CUSTOMER   EMAIL         :";gotoxy(80,18);puts(email);
gotoxy(31,21);for(i=0;i<69;i++) putch(205);
gotoxy(45,23);cout<<"BOARDING FROM           :";gotoxy(77,23);puts(from);
gotoxy(45,24);cout<<"DESTINATION             :";gotoxy(77,24);puts(dest);
gotoxy(45,26);cout<<"DATE OF JOURNEY         :";gotoxy(77,26);cout<<cDay.dd<<" / "<<cDay.mm<<" / "<<"2013";
gotoxy(45,28);cout<<"MODE OF TRAVEL          :";gotoxy(77,28);puts(mode_travel);
gotoxy(45,29);cout<<"No. OF PERSONS          :";gotoxy(77,29);cout<<no_tickets;
gotoxy(31,31);for(i=0;i<69;i++) putch(205);
gotoxy(53,32);for(i=0;i<28;i++) putch(224);
gotoxy(53,33);putch(224);putch(224);cout<<"     TOTAL AMOUNT :     ";putch(224);putch(224);
gotoxy(53,35);putch(224);putch(224);cout<<"      Rs. "<<amount; gotoxy(79,33);putch(224);putch(224);
gotoxy(53,36);for(i=0;i<28;i++) putch(224);
gotoxy(40,38);cout<<"Rs. : ";No_coverter_caller(amount);cout<<" ONLY ";
gotoxy(31,39);for(i=0;i<69;i++) putch(205);
getch();
}


      void TRAVELS::view_book()
{
    clrscr();
    output_box_date_n_time(0);
    TRAVELS trvl[30];

    fstream fin;
    fin.open("TRAVEL_BOOKINGS.dat",ios::binary|ios::in);
	 if(!fin)
             {
             clrscr();
             output_box_date_n_time(0);
             gotoxy(41,24);
             cout<<" NO TRAVEL BOOKINGS ";
             getch();
             admin();
             }

	gotoxy(58,7);cputs("TRAVEL BOOKINGS ");

   int i=0;
	while(1)
   {
    fin.read((char*)&trvl[i],sizeof(TRAVELS));
    i++;
    if(fin.eof()) break;
   }

 int totaldetails=give_datacount(3);

 int op1,op2;
 char opt1,opt2;
 int done=0;


   i=0;

 trvl[i].view_bookings();

   do
   {
   opt1=getch();
   	op1=opt1;
      if(op1==13)
      	{
          admin();
         }

     else if(op1==0)
      	{
         	do
            {
             opt2=getch();
             op2=opt2;

             switch(op2)
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

         do
         {
               opt1=getch();
               op1=opt1;

               if(op1==0) break;
          else if(op1==13) admin();

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
   gotoxy(47,17);cputs("BOOKING ID       -        ");cout<<travel_id;
   textcolor(2);
   gotoxy(36,21);cputs("CUSTOMER NAME               :         ");puts(cust_name);
   gotoxy(36,23);cputs("CUSTOMER EMAIL              :         ");puts(email);
   gotoxy(36,25);cputs("CUSTOMER PHONE              :         ");cout<<cust_phone;
	gotoxy(36,27);cputs("FROM                        :         ");puts(from);
	gotoxy(36,28);cputs("DESTINATION                 :         ");cout<<dest;
   gotoxy(36,31);cputs("ON DATE                     :         ");cout<<cDay.dd<<" / "<<cDay.mm<<" / "<<"2013";
   gotoxy(36,34);cputs("MODE                        :         ");puts(mode_travel);
   gotoxy(36,37);cputs("No. OF PERSONS              :         ");cout<<no_tickets;
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


    void TRAVELS::cancel_travel()
{
	 clrscr();
    output_box_date_n_time(0);

	 TRAVELS trvl;
    int id;
    int datacount=give_datacount(3);

    fstream oldf,newf;
    oldf.open("TRAVEL_BOOKINGS.dat",ios::binary|ios::in);
    if(!oldf)
    			 {
             gotoxy(57,26);
             textcolor(12);
             cputs(" NO TRAVEL BOOKINGS ");
             getch();
             customer();
             }

    gotoxy(42,14);cout<<"PLEASE ENTER YOU BOOKING ID   : ";
    cin>>id;
	 newf.open("temp.dat",ios::binary|ios::out);
    int found=0;
    clrscr();
    output_box_date_n_time(0);
    while(1)
    {
    	oldf.read((char*)&trvl,sizeof(TRAVELS));

       if(oldf.eof()) break;

     if(id==trvl.travel_id)
     	{
      trvl.view_book(0);
      found=1;
      break;
      }

    datacount++;

   }
     if(!found)
	{
   datacount=0;
   show_error();
   getch();
   cancel_travel();
  }

    oldf.close();

    char ans;

    oldf.open("TRAVEL_BOOKINGS.dat",ios::binary|ios::in);

    oldf.read((char*)&trvl,sizeof(TRAVELS));
 do
  {
   if(id==trvl.travel_id)
 {  gotoxy(30,wherey()+3);
 cout<<"ARE YOU SURE YOU WANT TO CANCEL THIS BOOKING ? (Y/N) ";

    ans=getch();
    	if((ans=='Y')||(ans=='y'))
    	{
      gotoxy(40,wherey()+5);
      cout<<"! !    BOOKING CANCELED    ! !";
      oldf.read((char*)&trvl,sizeof(TRAVELS)); continue; }

  		else
      {
      gotoxy(40,wherey()+6);
      cout<<"!  !  BOOKING NOT CANCELLED  ! !\n";
      datacount=0;
      }
  }
       	newf.write((char*)&trvl,sizeof(TRAVELS));
         oldf.read((char*)&trvl,sizeof(TRAVELS));

  }while(!oldf.eof());

   getch();
   newf.close();
   oldf.close();

   remove("TRAVEL_BOOKINGS.dat");
   rename("temp.dat","TRAVEL_BOOKINGS.dat");

   empty_file_remove("TRAVEL_BOOKINGS.dat",datacount);
 }




		void TRAVELS::view_city(int frm)
	{
      output_box_date_n_time(0);

      gotoxy(55,7);cout<<"* * BOOK MY TRAVEL  ";

      for(i=0;i<6;i++)
   {
   if(frm==(i+1)) continue;
   gotoxy(36,(i*4)+20);cout<<(i+1)<<".  ";puts(city_list[i]);

   }
      for(i=0;i<6;i++)
   {
   if(frm==(i+6)) continue;
   gotoxy(76,(i*4)+20);cout<<(i+6)<<".  ";puts(city_list[i+6]);

   }
   }


/*************   TRAVELS - MEMBER FUNCTIONS    **************/



	class tour
{
	public : char tourname[20],place[20],day[40],city[30],details[200];
   			int tour_no;
            float tariff;
};


	class admin_tour : public tour
{
	public : admin_tour()
   			{
            	strcpy(tourname,"\0");
               strcpy(place,"\0");
               strcpy(day,"\0");
					strcpy(details,"\0");
               tour_no=0;
               tariff=0;
            }
          int view_tour();
   		 void view_tour(int chk);
				void entry();
   			void remove_tour();
            void modify_tour();
};

		void admin_tour::entry()
   {
   clrscr();

	output_box_date_n_time(0);
   admin_tour adm;

   textcolor(1);

   gotoxy(50,14);cputs("PLEASE ENTER TOUR PACKAGE DETAILS ");

   textcolor(2);
   gotoxy(42,20);cputs("Enter Tour  NAME                 :        ");
   titlebox("* *  TOUR ENRTY  * *");
   textcolor(2);
   gotoxy(42,20);cputs("Enter Tour  NAME                 :        ");
   gets(tourname);
   gotoxy(42,23);cputs("Enter Tour  CITY                 :        ");
   gets(city);
   gotoxy(42,26);cputs("Enter Tour  PLACES               :        ");
   gets(place);
   gotoxy(42,29);cputs("Enter Tour  DETAILS              :        ");
   gets(details);
   gotoxy(42,32);cputs("Enter Tour  DAYS                 :        ");
   gets(day);



   do{
   gotoxy(42,35);cputs("Enter Tour  FARE                 :        ");
	}while(take_correct_numeric_value(tariff));
   tour_no=give_id(1);

   if(user_confirmation("DO YOU WANT TO SAVE  ?")) admin();
   loading("!!    SAVING DETAILS    !!"," PLEASE WAIT ");
   Info_popUp("!!     ENTRY  IS  SUCCESSFUL     !!","THE  PACKAGE  HAS  BEEN  SAVED","TOUR  ID  is ",tour_no);
   getch();
}

    int admin_tour::view_tour()
  {

   admin_tour adm;
   fstream fin;

	fin.open("TOUR_PACKAGES.dat",ios::binary|ios::in);
   if(!fin)
             {
             gotoxy(57,26);
             textcolor(12);
             cputs(" NO TOUR PACKAGES ");
             getch();
             admin();
             }

   gotoxy(52,12);cout<<"PLEASE SELECT THE PACKAGE  : ";

   int totaldetails=give_datacount(1);
   totaldetails;

      int op1,op2;
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

   admn[i].view_tour(0);
    titlebox("* * TOUR PACKAGES * *");

   do
   {
   opt1=getch();
   	op1=opt1;
      if(op1==13)
      	{
         gotoxy(43,48);
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
     else if(op1==0)
      	{
         	do
            {
             opt2=getch();
             op2=opt2;

             switch(op2)
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
              admn[i].view_tour(0);

              titlebox("* * TOUR PACKAGES * *");

             do
             {
             opt1=getch();
               op1=opt1;

               if(op1==0) break;
          else if(op1==13)
         {
          gotoxy(43,48);
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
             }while(done==0);
          }while(done==0);
      }
     }while(done==0);

    return done;
}




  void admin_tour::view_tour(int j)
  {
  	textcolor(3);
   gotoxy(10,((j*14)+15));for(int i=0;i<112;i++) putch(205);
   textcolor(1);
   gotoxy(51,((j*14)+17));cputs("TOUR No.     -      ");cout<<tour_no;
   textcolor(2);
   gotoxy(36,((j*14)+21));cputs("TOUR NAME                   :         ");puts(tourname);
   gotoxy(36,((j*14)+25));cputs("TOUR CITY                   :         ");puts(city);
	gotoxy(36,((j*14)+28));cputs("PLACES                      :         ");puts(place);
   gotoxy(36,((j*14)+31));cputs("DETAILS                     :         ");puts(details);
   gotoxy(36,((j*14)+34));cputs("TOUR DAYS                   :         ");puts(day);
   gotoxy(36,((j*14)+37));cputs("TARIFF                      :         Rs. ");cout<<tariff;
   gotoxy(36,((j*14)+40));cputs("  Only Rs.       -          Rs. ");
   No_coverter_caller(tariff);
   textcolor(3);
   gotoxy(10,((j*14)+44));for(int i=0;i<112;i++) putch(205);

   textcolor(15);
   gotoxy(15,((j*14)+46)); cputs("<=========");
   gotoxy(107,((j*14)+46));cputs("=========>");
   textcolor(5);
   gotoxy(17,((j*14)+48));cputs("PREVIOUS");
   gotoxy(109,((j*14)+48));cputs("NEXT");
   textcolor(15);
   gotoxy(57,((j*14)+46));cputs("ENTER = SELECT");

   }

    void admin_tour::modify_tour()
	{
     clrscr();
    output_box_date_n_time(0);
    gotoxy(55,7);cout<<"* *  MODIFY TOUR  * *";

    admin_tour adm;
    int mod; char ans;
    fstream file;
    file.open("TOUR_PACKAGES.dat",ios::binary|ios::in);
    if(!file)
             {
             gotoxy(57,26);
             textcolor(12);
             cputs(" NO TOUR PACKAGES ");
             getch();
             admin();
             }

    file.close();

    file.open("TOUR_PACKAGES.dat",ios::binary|ios::in|ios::out);

   	mod=adm.view_tour();

     clrscr();
     output_box_date_n_time(0);

    gotoxy(55,7);cout<<"* *  MODIFY TOUR  * *";
    int loopend=0;
    int found=0;
    long pos;
	 do
    {
    	pos=file.tellg();
      file.read((char*)&adm,sizeof(admin_tour));
  		if(file.eof()) break;

      if(mod==adm.tour_no)
{
   found++;
   gotoxy(50,13);cout<<"*  *  ENTER NEW RECORDS   *  *";
   gotoxy(10,16);for(int i=0;i<112;i++) putch(205);
   gotoxy(18,18);cout<<"   RECORD NAME   \t\t\t   OLD VALUE\t\t\t\tNEW  VALUE";
   gotoxy(10,20);for(int i=0;i<112;i++) putch(205);


   gotoxy(22,24);cout<<"TOUR No.   \t\t:\t\t";cout<<adm.tour_no;
   gotoxy(22,27);cout<<"TOUR NAME  \t\t:\t\t";puts(adm.tourname);
   gotoxy(22,30);cout<<"TOUR CITY  \t\t:\t\t";puts(adm.city);
	gotoxy(22,33);cout<<"PLACES     \t\t:\t\t";puts(adm.place);
   gotoxy(22,36);cout<<"DETAILS    \t\t:\t\t";puts(adm.details);
   gotoxy(22,39);cout<<"TOUR DAYS  \t\t:\t\t";puts(adm.day);
   gotoxy(22,42);cout<<"TOUR FARE  \t\t:\t\t";cout<<adm.tariff;

   gotoxy(46,47);cout<<" SAVE INFO. ";

   int op1,op2;
   char opt1,opt2;
   int x=13,y=27,x1=90;

   	 gotoxy(13,27);cout<<"====>";

       do{

       opt1=getch();
       op1=opt1;
       if(op1==13)
       {
       gotoxy(x1,27);
       gets(adm.tourname);
       }

       }while(op1!=0);

 	 	if(op1==0)
       {

       	do
         {
         opt2=getch();
         op2=opt2;

         switch(op2)
         {
         	case 72 :   if(y==27) y=45;
            				else y-=3;

								break;

            case 80 :   if(y==45) y=27;
            				else y+=3;

                        break;
         default : break;
         };
         do
          {
                  show_blanks_in_modify_tour();

						if(y==45)
                 	{
                  gotoxy(38,47);cout<<"====>";
                  }
                        else
                        {
                        gotoxy(x,y);cout<<"====>";
                        }
                        opt1=getch();
            				op1=opt1;
                        if(op1==0) break;

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
                           gotoxy(x1,42);
                           cin>>adm.tariff;
                        	}
                        else if(y==45)
                         {
                           gotoxy(x1,45);
                           gotoxy(58,47);cout<<" ARE YOU SURE YOU WANT TO SAVE ?(Y/N)";
                           ans=getch();
                           if((ans=='N')||(ans=='n'))
                           {
                            gotoxy(58,49);cout<<" ALL MODIFICATIONS CANCELLED ";
                            getch();
                            admin();
                           }
                           	loopend=1;
                              gotoxy(55,48);cout<<"SAVING......";
                         }
                  }
             }while(!((op1==0)||(op1==13)));


       }while(loopend==0);
       }
   getch();
   }
   }while(loopend==0);

   if(!found)
  {

   show_error();
   getch();
   modify_tour();
  }

   file.seekg(pos);

   file.write((char*)&adm,sizeof(admin_tour));

  	file.close();
   admin();
  }

   void admin_tour::remove_tour()
	{
    clrscr();
    output_box_date_n_time(0);

    admin_tour adm;
    int rm;
    int datacount=0;
    fstream oldf,newf;

    oldf.open("TOUR_PACKAGES.dat",ios::binary|ios::in);
    if(!oldf)
             {
             gotoxy(57,26);
             textcolor(12);
             cputs(" NO TOUR PACKAGES ");
             getch();
             admin();
             }

    newf.open("temp.dat",ios::binary|ios::out);

    datacount=give_datacount(1);

    rm=adm.view_tour();

    loading("DELETING THE PACKAGE ", " PLEASE WAIT ");
    Info_popUp("!!    DELETION  SUCCESSFULL    !!","PACKAGE DELETED","DELETED PACKAGE Id - ",rm);

    oldf.close();

	 oldf.open("TOUR_PACKAGES.dat",ios::binary|ios::in);
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

	remove("TOUR_PACKAGES.dat");
   rename("temp.dat","TOUR_PACKAGES.dat");

  empty_file_remove("TOUR_PACKAGES.dat",datacount);
  getch();
  admin();

 }


    /****************************************************************************************/


	class cust_tour : public tour
{
	public : char cust_name[30],cust_email[30];
   			int cust_phone;
            float totamount;
            int no_seats;
            tdate cDay;
            cust_tour()

				{
            	strcpy(tourname,"0/");
               strcpy(place,"0/");
               strcpy(day,"0/");
               strcpy(details,"0/");
               tour_no=totamount=no_seats=0;
               tariff=0;
            }

            void view_book(int iscust);
            void view_book();
            void view_bookings();
            void book_tour();
   			void cancel_tour();

};

void cust_tour::view_book(int iscust)
{

clrscr();
output_box_date_n_time();

for(i=12;i<40;i++){ gotoxy(31,i);putch(178); }
for(i=12;i<40;i++){ gotoxy(101,i);putch(178); }

gotoxy(31,11);for(i=0;i<71;i++) putch(220);
gotoxy(59,13);cout<<"##  TRIP TICKET  ##";
gotoxy(31,15);for(i=0;i<71;i++) putch(220);
gotoxy(44,17);cout<<"CUSTOMER NAME             :";gotoxy(79,17);puts(cust_name);
gotoxy(44,18);cout<<"CUSTOMER PHONE            :";gotoxy(79,18);cout<<cust_phone;
gotoxy(44,19);cout<<"CUSTOMER EMAIL            :";gotoxy(79,19);puts(cust_email);
gotoxy(31,21);for(i=0;i<71;i++) putch(220);
gotoxy(45,23);cout<<"TOUR NAME               :";gotoxy(77,23);puts(tourname);
gotoxy(45,24);cout<<"TOUR CITY               :";gotoxy(77,24);puts(city);
gotoxy(45,26);cout<<"DATE OF JOURNEY         :";gotoxy(77,26);cout<<cDay.dd<<" / "<<cDay.mm<<" / "<<"2013";
gotoxy(45,28);cout<<"No. OF PERSONS          :";gotoxy(77,28);cout<<no_seats;
gotoxy(31,30);for(i=0;i<71;i++) putch(220);
gotoxy(53,32);for(i=0;i<30;i++) putch(224);
gotoxy(53,33);putch(224);putch(224);cout<<"      TOTAL AMOUNT :       ";putch(224);putch(224);
gotoxy(53,35);putch(224);putch(224);cout<<"       Rs. "<<totamount; gotoxy(81,35); putch(224);putch(224);
gotoxy(53,36);for(i=0;i<30;i++) putch(224);
gotoxy(38,38);cout<<"Rs. : ";No_coverter_caller(totamount);cout<<" ONLY ";
gotoxy(31,39);for(i=0;i<71;i++) putch(220);

/*textcolor(3);
gotoxy(45,45);cputs(" PRINT THIS TICKET  ? (Y/N) ");
while(1)
{
char ans=getch();

if((ans=='y')||(ans=='Y'))
	{
   cout<<" print function ready nhi hai ";
   break;
   }
else  if((ans=='N')||(ans=='n'))
			break;
}//call print function... par abhi bana nhi hai...
*/getch();

}

void cust_tour::view_book()
{
 clrscr();
 output_box_date_n_time(0);

 fstream fin;

 fin.open("TOUR_BOOKINGS.dat",ios::binary|ios::in);
 if(!fin)
 {
 gotoxy(57,26);
  textcolor(12);
  cputs(" NO TOUR BOOKINGS ");
  getch();
 admin();
 }

 gotoxy(54,7); cputs(" **  TOUR BOOKINGS  **");

 int totaldetails=give_datacount(2);

 int op1,op2;
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

   custm[i].view_bookings();
   do
   {
   opt1=getch();
   	op1=opt1;
      if(op1==13)
      	{
          admin();
         }

     else if(op1==0)
      	{
         	do
            {
             opt2=getch();
             op2=opt2;

             switch(op2)
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

         do
         {
               opt1=getch();
               op1=opt1;

               if(op1==0) break;
          else if(op1==13) admin();

             }while(1);
          }while(1);
      }
     }while(1);

}

void cust_tour::view_bookings()
{
textcolor(3);
   gotoxy(10,15);for(int i=0;i<112;i++) putch(205);
   textcolor(1);
   gotoxy(49,17);cputs("BOOKING ID     -      ");cout<<tour_no;
   textcolor(2);
   gotoxy(36,21);cputs("CUSTOMER NAME               :         ");puts(cust_name);
   gotoxy(36,25);cputs("CUSTOMER EMAIL              :         ");puts(cust_email);
	gotoxy(36,28);cputs("CUSTOMER PHONE              :         ");cout<<cust_phone;
   gotoxy(36,31);cputs("TOUR NAME                   :         ");puts(tourname);
   gotoxy(36,34);cputs("TOUR DATE                   :         ");cout<<cDay.dd<<" / "<<cDay.mm<<" / "<<"2013";
   gotoxy(36,37);cputs("TOTAL AMOUNT                :         Rs. ");cout<<totamount;
   gotoxy(36,40);cputs("  Only Rs.       -          Rs.  ");
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








void cust_tour::book_tour()
	{     clrscr();
         cust_tour cust,c;
         admin_tour adm;

         fstream temp;

         temp.open("TOUR_PACKAGES.dat",ios::binary|ios::in);
         if(!temp)
             {
             output_box_date_n_time(0);
             gotoxy(57,26);
             textcolor(12);
             cputs(" NO TOUR PACKAGES ");
             getch();
             customer();
             }
         output_box_date_n_time(0);
			gotoxy(57,7);;cout<<"** BOOK TOUR **";
         gotoxy(43,18);cout<<" ENTER YOUR NAME     :     ";
         gets(cust.cust_name);
         gotoxy(43,22);cout<<" ENTER YOUR EMAIL    :     ";
         gets(cust.cust_email);
         gotoxy(43,26);cout<<" ENTER YOUR PHONE    :     ";
         cin>>cust_phone;
         gotoxy(40,33);cout<<" PLEASE SELECT TOUR PACKAGE.....";
         getch();

         clrscr();
         output_box_date_n_time(0);

         int tm=adm.view_tour();

         clrscr();
         output_box_date_n_time(0);

         gotoxy(57,7);;cout<<"** BOOK TOUR **";

         gotoxy(48,14);cout<<"PLEASE ENTER DATE OF JOURNEY";
         do
         {
         gotoxy(76,18);cout<<"\t\t\t\t\t\t\t";
         gotoxy(45,18);cout<<"ENTER MONTH (In Digits.)   :     ";
         cin>>cust.cDay.mm;
         }while(!((cust.cDay.mm>=1)&&(cust.cDay.mm<=12)));

         do
         {
         gotoxy(76,21);cout<<"\t\t\t\t\t\t\t";
         gotoxy(45,21);cout<<"ENTER DATE                 :     ";
         cin>>cust.cDay.dd;
         }while(!((cust.cDay.mm>=1)&&(cust.cDay.mm<=31)));

         gotoxy(42,27);cout<<"PLEASE ENTER NO. OF TICKEST REQUIRED  :  ";
         cin>>cust.no_seats;

         temp.close();

         cust.tour_no=give_id(2);

         fstream temp2;
         temp2.open("TOUR_BOOKINGS.dat",ios::binary|ios::app);
         fstream t;
         t.open("TOUR_PACKAGES.dat",ios::binary|ios::in);
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

        gotoxy(50,37);cout<<"  ! !  BOOKING SUCCESS  ! ! ";
        gotoxy(50,41);cout<<"   Your Booking Id is    -    ";
        cout<<cust.tour_no;
        gotoxy(43,45);cout<<"!!  Please Remember It For Future Purposes  !!";


		  getch();clrscr();

        cust.view_book(0);

        getch();

        t.close();temp2.close();
   }

    	void cust_tour::cancel_tour()
   {
    clrscr();

    output_box_date_n_time();
    gotoxy(57,7);cout<<"**  CANCEL TRIP  ";
    cust_tour cust;

    int id;
    int datacount=0;
    fstream oldf,newf;

    oldf.open("TOUR_BOOKINGS.dat",ios::binary|ios::in);
    if(!oldf)
    {
             gotoxy(57,26);
             textcolor(12);
             cputs(" NO TOUR BOOKINGS ");
             getch();
             customer();
    }

    gotoxy(32,17);cout<<"PLEASE ENTER YOU BOOKING ID : ";
    cin>>id;

	 newf.open("temp.dat",ios::binary|ios::out);
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
     if(!found)
		{

   		show_error();
   		getch();
   		cancel_tour();
      }
    oldf.close();

    char ans;

	 oldf.open("TOUR_BOOKINGS.dat",ios::binary|ios::in);
    oldf.read((char*)&cust,sizeof(cust_tour));
 do
  {
   if(id==cust.tour_no)
 { gotoxy(30,wherey()+3);
 cout<<"ARE YOU SURE YOU WANT TO CANCEL THIS BOOKING ? (Y/N)";
    cin>>ans;
    	if((ans=='Y')||(ans=='y'))
    	{gotoxy(40,wherey()+6);
      cout<<"!  !    BOOKING CANCELED    !  !";
      oldf.read((char*)&cust,sizeof(cust_tour)); continue; }
   else
   {gotoxy(40,wherey()+6);
   cout<<"!  !  BOOKING NOT CANCELLED   !  !\n";
   datacount=0;
   }

  }
       	newf.write((char*)&cust,sizeof(cust_tour));
         oldf.read((char*)&cust,sizeof(cust_tour));
  }while(!oldf.eof());

   getch();
   newf.close();
   oldf.close();

   remove("TOUR_BOOKINGS.dat");
   rename("temp.dat","TOUR_BOOKINGS.dat");

   empty_file_remove("TOUR_BOOKINGS.dat",datacount);
 }
   /****************************************************************************************/


void admin()
{
clrscr();

admin_tour adm;
cust_tour cust;
TRAVELS trvl;

   output_box_date_n_time(0);

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



	fstream fout;
   fstream fin;

   char op1,op2;
   int opt1,opt2;
   int x=44,y=18;

	gotoxy(x,18);textcolor(15);cputs("=====>");


   titlebox("*  *  ADMINISTRATOR MENU  *  *");

   do{
   opt1=getch();
   op1=opt1;

   }while(!((op1==13)||(op1==27)||(op1==0)));
   if(op1==27) menu();

   else if(op1==13)
   {
	 	 	cust.view_book();

        	clrscr();

         admin();
   }
    else if(op1==0)
       {

       	do
         {
         opt2=getch();
         op2=opt2;


    switch(op2)
    {
     	case 72 : if(y==18) y=36;
     				else y-=3;

               break;

	case 80:   if(y==36) y=18;
    				else y+=3;

             break;
    default : break;
   };

          	do
             {
               show_blanks_in_Admin();

 				 gotoxy(x,y);textcolor(15);cputs("=====>");

             titlebox("*  *  ADMINISTRATOR MENU  *  *");

               opt1=getch();

               op1=opt1;
               if(op1==0) break;

               if(op1==27) menu();

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
				fout.open("TOUR_PACKAGES.dat",ios::binary|ios::app);
				adm.entry();
            clrscr();
			  	fout.write((char*)&adm,sizeof(admin_tour));
            fout.close();
            admin();
            }
       else if(y==27)
            {
            clrscr();
            output_box_date_n_time(0);

    			adm.view_tour();
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
      }while(!((op1==0)||(op1==13)||(op1==27)));

}while(1);

}
}

void change_pass()
{
  clrscr();
  output_box_date_n_time(0);

  gotoxy(55,7);
  cout<<"CHANGE MY PASSWORD ";
  char passwrd[7];

  fstream passfile;
  passfile.open("ADMIN_PASS.dat",ios::binary|ios::in);

  admin_pass A;

  passfile.read((char*)&A,sizeof(admin_pass));

  A.getcode(passwrd);
  passfile.close();

  passfile.open("ADMIN_PASS.dat",ios::binary|ios::out);

  do{

   output_box_date_n_time(0);

	char tmp[10];
   textcolor(6);

   gotoxy(40,17);cout<"                                  ";
   gotoxy(46,20);
	cputs("  PLEASE ENTER THE OLD PASSWORD   ");

   textcolor(15);
   gotoxy(42,46);
   cputs("     **  ( Press Escape To Go Back )  **");

   gotoxy(63,23);
	cout<<"         ";
	gotoxy(63,23);

	for(i=0;i<10;i++)
	{
	  tmp[i]=getch();

     if(tmp[i]==27 )
      {
     	admin();
      }

	  if(tmp[i]==13 )
		{
		tmp[i]='\0';
		break;
      }

     cputs("*");

     if(tmp[i]==8)
     {
     	i-=2;
      gotoxy(wherex()-2,wherey());cout<<"  ";
      gotoxy(wherex()-2,wherey());
     }

   }
  if(!strcmp(tmp,passwrd))
  {
  		break;
  }
  else
   {
    gotoxy(55,35);
    cout<<" WRONG  PASSWORD ";
    getch();
    admin();
   }

   break;

	}while(1);

	clrscr();
   output_box_date_n_time(0);

   gotoxy(47,20);cout<<" ENTER A NEW PASSWORD    (Max 5)";

   char checkpass1[6];
   char checkpass2[6];
   gotoxy(47,22);
   for(i=0;i<5;i++)
	{
	  checkpass1[i]=getch();

     if(checkpass1[i]==27 )
      {
     	admin();
      }

	  if(checkpass1[i]==13 )
		{
		checkpass1[i]='\0';
		break;
		}

      cputs("*");


     if(checkpass1[i]==8)
     {
     	i-=2;
      gotoxy(wherex()-2,wherey());cout<<"  ";
      gotoxy(wherex()-2,wherey());
     }
   }
   gotoxy(47,24);cout<<"ENTER THE PASSWORD AGAIN";
   gotoxy(47,26);

   for(i=0;i<5;i++)
	{
	  checkpass2[i]=getch();

     if(checkpass2[i]==27 )
      {
     	admin();
      }

	  if(checkpass2[i]==13 )
		{
		checkpass2[i]='\0';
		break;
		}

      cputs("*");

     if(checkpass2[i]==8)
     {
     	i-=2;
      gotoxy(wherex()-2,wherey());cout<<"  ";
      gotoxy(wherex()-2,wherey());
     }
   }
      if(!strcmp(checkpass1,checkpass2))
      {
      gotoxy(56,34);cout<<"PASSWORD CHANGED";
      getch();

      A.givecode(checkpass2);

      passfile.write((char*)&A,sizeof(admin_pass));
      passfile.close();

      }

      else
      {
         gotoxy(55,28);cout<<"PASSWORD DON'T MATCH";
         gotoxy(55,30);cout<<"    TRY AGAIN";
      	getch();
      }
  }



/****************************************************************************************/

void customer()
{
clrscr();
output_box_date_n_time(0);

cust_tour cust;
TRAVELS trvl;
fstream file;


   textcolor(5);
   gotoxy(54,20);cputs("<>  Book My Tour");
   gotoxy(54,23);cputs("<>  Book My Travels ");
   gotoxy(54,26);cputs("<>  Cancel My Tour Bookings ");
   gotoxy(54,29);cputs("<>  Cancel My Travel Bookings ");
   gotoxy(54,32);cputs("<>  Offer Of The Day !!");


   textcolor(8);
   gotoxy(46,45);cputs("( *  *   Press Esc To Go Back   *  * )");
   gotoxy(38,48);cputs("(   Use Up And Down Arrows To Select And Press Enter   )");

   fstream f;

   char op1,op2;
   int opt1,opt2;
   int x=45,y=20;

   gotoxy(x,20);textcolor(15);cputs("=====>");
   titlebox("*  *   CUSTOMER  MENU   *  *");

   do
   {
   opt1=getch();
   op1=opt1;

   }while(!((op1==13)||(op1==27)||(op1==0)));

   if(op1==27) menu();

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
         op2=opt2;

    switch(op2)
    {
     	case 72 : if(y==20) y=32;
     				 else y-=3;
                break;

		case 80 : if(y==32) y=20;
     				 else y+=3;
                break;

      default : break;
    };

    do
     {
     show_blanks_in_Customer();
      gotoxy(x,y);textcolor(15);cputs("=====>");

      titlebox("*  *   CUSTOMER  MENU   *  *");

              opt1=getch();

              op1=opt1;
      if(op1==0) break;

      if(op1==27) menu();

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
               file.open("TRAVEL_BOOKINGS.dat",ios::binary|ios::app);
    				trvl.book_TRAVELS();
               file.write((char*)&trvl,sizeof(trvl));
               file.close();
    	         clrscr();customer();
               break;
          }
         else if(y==26)
          {
          cust.cancel_tour();
          clrscr();
          customer();
          break;
          }
         else if(y==29)
          {
          trvl.cancel_travel();
          customer();
          break;
          }
         else if(y==32)
          {
          customer();
          break;
          }
         }
		}while(!((op1==0)||(op1==13)||(op1==27)));
 }while(1);
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
case 1 :	file.open("TOUR_PACKAGES.dat",ios::binary|ios::in);
			if(!file) return 1;

			while(!file.eof())
			{
   			file.read((char*)&adm,sizeof(admin_tour));
   		}
   		rtn=(adm.tour_no+1);
   		file.close();

   		return rtn;
case 2 : file.open("TOUR_BOOKINGS.dat",ios::binary|ios::in);
         if(!file) return 1;

		while(!file.eof())
		{
   	file.read((char*)&cust,sizeof(cust_tour));
   	}
   	rtn=(cust.tour_no+1);
   	file.close();
   	return rtn;

case 3 : file.open("TRAVEL_BOOKINGS.dat",ios::binary|ios::in);
			if(!file) return 1;

			while(!file.eof())
		{
   	file.read((char*)&trvl,sizeof(TRAVELS));
   	}
   	rtn=(trvl.travel_id+1);
   	file.close();

   	return rtn;
};
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

case 1 :  file.open("TOUR_PACKAGES.dat",ios::binary|ios::in);
			if(!file) return 1;

		while(1)
		{
      file.read((char*)&adm,sizeof(admin_tour));
      if(file.eof()) break;
      rtn++;
   	}
   	file.close();
   	return rtn;

case 2 : file.open("TOUR_BOOKINGS.dat",ios::binary|ios::in);
         if(!file) return 1;

			while(1)
		{
       file.read((char*)&cust,sizeof(cust_tour));

       if(file.eof()) break;
      rtn++;

   	}

      file.close();
   	return rtn;
case 3 : file.open("TRAVEL_BOOKINGS.dat",ios::binary|ios::in);
			if(!file) return 1;

			while(1)
		{
   	file.read((char*)&trvl,sizeof(TRAVELS));
      	if(file.eof()) break;
      rtn++;
      }
   	return rtn;
};
}


 void empty_file_remove(char file[],int check)
 {
    if(check==1)
    	remove(file);
 }


  void pass()
{  admin();
	clrscr();

   int attempts=3;
   char passwrd[7];

   fstream passfile;
   passfile.open("ADMIN_PASS.dat",ios::binary|ios::in);

   admin_pass A;

   passfile.read((char*)&A,sizeof(admin_pass));
   A.getcode(passwrd);

   do{
   int len=strlen(passwrd);

   output_box_date_n_time();

	char tmp[10];
   textcolor(6);

   gotoxy(40,17);cout<"                                  ";
   gotoxy(50,20);
	cputs("  AUTHENTICATION REQUIRED   ");cputs("( ");cout<<attempts;cputs(" )");
   attempts-=1;;
   lock(0);
   textcolor(15);
   gotoxy(39,46);
   cputs("     * *  (  Press Escape To Go Back  )  * *");
   textcolor(8);
   gotoxy(62,23);
   textcolor(15);
   cputs("                          ");
   gotoxy(62,23);

   for(int c=0;c<len;c++)
   	cputs("-");


	gotoxy(62,23);

	for(i=0;i<10;i++)
	{

	  tmp[i]=getch();

     if(tmp[i]==27 )
      {
     	menu();
      }

	  if(tmp[i]==13 )
		{
		tmp[i]='\0';
		break;
		}

     cputs("*");

     if(tmp[i]==8)
     {
     	i-=2;
      gotoxy(wherex()-2,wherey());cout<<"  ";
      gotoxy(wherex()-2,wherey());
     }
   }
			if(!strcmp(tmp,passwrd))
				{
      				lock(1);
                  Sleep(1000);
                  clrscr();
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
   void main()
  {
    menu();
    textcolor(15);
    gotoxy(23,7);
	 for(int i=23, j=106;i<107;i++,j--)
    {
    gotoxy(i,7);Sleep(10);putch(177);
    gotoxy(j,21);
	  Sleep(1); putch(177);
     }
    for(int i=8,j=21;i<22;i++,j--)
	{	gotoxy(23,j); putch(177); gotoxy(106,i); putch(177);  Sleep(20);}Sleep(300);


    textcolor(12);
	 gotoxy(34,12);cputs("#     #    ####    #         ###      ##      #     #    #### ");Sleep(150);
	 gotoxy(34,13);cputs("#     #    #       #       #        #    #    # # # #    #    ");Sleep(150);
	 gotoxy(34,14);cputs("#  #  #    ####    #       #        #    #    #  #  #    #### ");Sleep(150);
	 gotoxy(34,15);cputs("# # # #    #       #       #        #    #    #     #    #    ");Sleep(150);
	 gotoxy(34,16);cputs("#     #    ####    #####     ###      ##      #     #    #### ");Sleep(150);

     textcolor(15);
     gotoxy(23,26);
	  for(i=0;i<84;i++) { Sleep(0.1);putch(177); }
     gotoxy(23,38);
	  for(i=0;i<84;i++) { Sleep(0.1);putch(177); }
     for(i=26;i<38;i++)
	 { 	gotoxy(23,i); putch(177); gotoxy(106,i); putch(177); Sleep(20); }

     textcolor(10);
     int x=1;
     while(x-->0)
     {
	  gotoxy(48,30);cputs("   THE  MV  TRAVELS AND TOURISM   ");Sleep(110);
     gotoxy(49,30);cputs("   THE  MV  TRAVELS AND TOURISM   ");Sleep(110);
     gotoxy(50,30);cputs("   THE  MV  TRAVELS AND TOURISM   ");Sleep(110);
     gotoxy(49,30);cputs("   THE  MV  TRAVELS AND TOURISM   ");Sleep(110);
     }

     x=1;
     while(x-->0)
     {
	  gotoxy(52,33);cputs("  MADE BY -  M. VIGNESH ");Sleep(100);
     gotoxy(53,33);cputs("  MADE BY -  M. VIGNESH ");Sleep(100);
     gotoxy(54,33);cputs("  MADE BY -  M. VIGNESH ");Sleep(100);
     gotoxy(53,33);cputs("  MADE BY -  M. VIGNESH ");Sleep(100);

     }

    getch(); clrscr();

    menu();
  }

void menu()
{
	clrscr();
	char opt1;
   output_box_date_n_time(0);

   textcolor(3);
   gotoxy(48,7);

	    textcolor(6);
		 gotoxy(55,23);
   	cputs("<>   ADMINISTRATOR");
		 gotoxy(55,29);
		cputs("<>   CUSTOMER");

      textcolor(8);
	gotoxy(38,46);
   cputs("(   Use Up And Down Arrow To Select And Press Enter   )");

   	textcolor(15);
      int op1;
      gotoxy(42,23);
      cputs("======>");
      gotoxy(80,23);
      cputs("<======");

      titlebox("!!    PLEASE SELECT YOUR ACCOUNT    !!");


      int pos=0;
do
{

 opt1=getch();
 op1=opt1;

      if(op1==13)
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

   else if((op1==72)||(op1==80))
 {
 		if(pos==0) pos=1;
   		else pos=0;

         switch(pos)
      {
        	case 0:
         			textcolor(15);
         			gotoxy(42,23); cputs("======>");
         	      gotoxy(42,29); cputs("       ");
                  gotoxy(80,23); cputs("<======");
                  gotoxy(80,29); cputs("       ");
                  titlebox("!!    PLEASE SELECT YOUR ACCOUNT    !!");

                  break;

         case 1 :
         			textcolor(15);
         			gotoxy(42,23); cputs("       ");
                  gotoxy(42,29); cputs("======>");
                  gotoxy(80,23); cputs("       ");
                 	gotoxy(80,29); cputs("<======");
                  titlebox("!!    PLEASE SELECT YOUR ACCOUNT    !!");

                  break;

         default : break;
      };

 }


}while(1);

}
