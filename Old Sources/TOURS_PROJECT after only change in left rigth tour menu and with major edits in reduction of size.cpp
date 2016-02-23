#include<fstream.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<dos.h>
#include<windows.h>

#define end cout<<endl;

char city_list[][30]={"AGRA","AHMEDABAD","BANGALORE","MUMBAI",
							"KOLKATA","DELHI","HYDERABAD","JAIPUR"
					  	  ,"LUCKNOW","CHENNAI","PUNE","SRINAGAR",};

char *one[]={" "," One"," Two"," Three"," Four"," Five"," Six",
            " Seven"," Eight"," Nine"," Ten"," Eleven"," Twelve",
				" Thirteen"," Fourteen"," Fifteen"," Sixteen",
            " Seventeen"," Eighteen"," Nineteen"};

char *ten[]={" "," "," Twenty"," Thirty"," Forty"," Fifty",
				 " Sixty", " Seventy"," Eighty"," Ninety"};


/****************************************************************************************/

int i;
char passwrd[10]={'1','2','3','4'};

void menu();
void pass();

void admin();
void customer();

/*************   SPF   **************/

void output_box_date_n_time(int check_if_end_needed);
void No_converter(long,char[]);
void No_coverter_caller(int n);
void empty_file_remove(char file[],int check);
int give_id(int type);
int give_datacount(int type);
void Mv_logo()
{
  int x=24,y=18;



  while(!kbhit())
  {
  textcolor(random(16));
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

  gotoxy(random(80)+44,random(35)+16);cputs("                                      ");
  gotoxy(random(80)+44,random(30)+16);cputs("                                       ");
  gotoxy(random(40)+44,random(10)+16);cputs("                                      ");
  gotoxy(random(40)+44,random(13)+16);cputs("                                       ");
  gotoxy(random(60)+44,random(20)+16);cputs("                                      ");
  gotoxy(random(20)+44,random(25)+16);cputs("                                       ");

	}
clrscr();
}


void clear_area_for_view_tour()
{
  for(int x=68;x<122;x++)
	for(int y=17;y<41;y++)
   	{
      gotoxy(x,y);cout<<" ";
		}
}


void change_pass();

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
   gotoxy(56,17);
   cputs("PLEASE  WAIT  :   ");
   for(int i=sec;i>0;i--)
   	{
      gotoxy(73,17);cout<<i;
      Sleep(700);
      }
}



void show_error()
{
gotoxy(52,41);cout<<"!!!   WRONG OPTION   !!!";
}

show_blanks_in_modify_tour()
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

void show_blanks_in_Customer()
{
	int x=5;
   while(x-->0)
   {
   gotoxy(44,(20+(x*3)));cout<<"       ";
   }
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
gotoxy(42,4); cputs("---|        TOURS AND TRAVELS SYSTEM        |---");
gotoxy(61,7);  //title goes here...

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
            void view_city();
   			void book_TRAVELS();
            void view_book();
            void view_book(int check);
            void cancel_travel();

				TRAVELS()
            {
					cDay.yy=2013;
               travel_id=0;
            }

};

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

   gotoxy(42,25);cout<<"PLEASE ENTER YOUR EMAIL              :     ";
   gets(email);

   gotoxy(42,28);cout<<"PLEASE  ENTER YOUR PHONE NO.         :     ";
   cin>>cust_phone;

   do{
   clrscr();

   gotoxy(50,14);cout<<"* * SELECT YOOR PICKUP CITY  ";

   view_city();

   gotoxy(64,43);cin>>frm;

   if(!((frm>=1)&&(frm<=12)))
   {
   show_error();
  	getch();
   }
   }while(!((frm>=1)&&(frm<=12)));

   strcpy(from,city_list[frm-1]);

   do{
   clrscr();

   gotoxy(47,14);cout<<"* * SELECT YOUR DESTINATION CITY  ";

   view_city();
   gotoxy(64,43);cin>>to;

   if(!((frm>=1)&&(frm<=12)))
   {
	gotoxy(27,1);cout<<" ! ! WRONG OPTION ! !";
   getch();
   }
   }
   while(!((to>=1)&&(to<=12)&&(frm!=to)));

   strcpy(dest,city_list[to-1]);

   clrscr();

   output_box_date_n_time(0);
   gotoxy(55,7);cout<<"* * BOOK MY TRAVEL  ";


   gotoxy(50,16);cout<<"PLEASE ENTER DATE OF JOURNEY";
   gotoxy(45,20);cout<<"ENTER MONTH (In No.)            :         ";cin>>cDay.mm;
   gotoxy(45,23);cout<<"ENTER DATE                      :         ";cin>>cDay.dd;

   gotoxy(45,28);cout<<"PLEASE ENTER NO. OF TICKEST REQUIRED  :  ";
   cin>>no_tickets;

   gotoxy(50,31);cout<<"PLEASE CHOOSE MODE OF TRAVEL ";
   gotoxy(47,35);cout<<"1. BUS         ( A/C and VOLVO )";
   gotoxy(47,37);cout<<"2. MINI VAN        (PRIVATE)";
   gotoxy(47,39);cout<<"3. TAXI            (PRIVATE)";cin>>op;

   if(op==1) strcpy(mode_travel,"BUS");
   else if(op==2) strcpy(mode_travel,"MINI VAN");
   else if(op==3) strcpy(mode_travel,"TAXI");
   randomize();
   amount=((random(5)*1000-random(5)*100)*no_tickets);
   travel_id=give_id(3);

	gotoxy(52,42);cout<<" ! ! BOOKING SUCCESS  ! !";
   cout<<travel_id;
   getch();clrscr();

   view_book(1);

   }


      void TRAVELS::view_book(int check)

{
   output_box_date_n_time(0);
	for(i=12;i<40;i++){ gotoxy(17,i);putch(178); }
	for(i=12;i<40;i++){ gotoxy(87,i);putch(178); }

gotoxy(17,11);for(i=0;i<69;i++) putch(205);
gotoxy(45,13);cout<<"##  TRIP TICKET  ##";
gotoxy(17,15);for(i=0;i<69;i++) putch(205);
gotoxy(30,17);cout<<"CUSTOMER   NAME          :";gotoxy(65,17);puts(cust_name);
gotoxy(30,18);cout<<"CUSTOMER   PHONE         :";gotoxy(65,18);cout<<(cust_phone);
gotoxy(30,19);cout<<"CUSTOMER   EMAIL         :";gotoxy(65,18);puts(email);
gotoxy(17,21);for(i=0;i<69;i++) putch(205);
gotoxy(31,23);cout<<"BOARDING FROM           :";gotoxy(63,23);puts(from);
gotoxy(31,24);cout<<"DESTINATION             :";gotoxy(63,24);puts(dest);
gotoxy(31,26);cout<<"DATE OF JOURNEY         :";gotoxy(63,26);cout<<cDay.dd<<" / "<<cDay.mm<<" / "<<"2013";
gotoxy(31,28);cout<<"MODE OF TRAVEL          :";gotoxy(63,28);puts(mode_travel);
gotoxy(31,29);cout<<"No. OF PERSONS          :";gotoxy(63,29);cout<<no_tickets;
gotoxy(17,31);for(i=0;i<69;i++) putch(205);
gotoxy(39,32);for(i=0;i<28;i++) putch(224);
gotoxy(39,33);putch(224);putch(224);cout<<"     TOTAL AMOUNT :     ";putch(224);putch(224);
gotoxy(39,35);putch(224);putch(224);cout<<"      Rs. "<<amount; gotoxy(67,33);putch(224);putch(224);
gotoxy(39,36);for(i=0;i<28;i++) putch(224);
gotoxy(26,38);cout<<"Rs. : ";No_coverter_caller(amount);cout<<" ONLY ";
gotoxy(17,39);for(i=0;i<69;i++) putch(205);
getch();
}


      void TRAVELS::view_book()
{
    TRAVELS trvl;

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
    gotoxy(7,1);for(i=0;i<69;i++) putch(205);
    gotoxy(33,2);cout<<"TRAVEL BOOKINGS ";
    gotoxy(7,3);for(i=0;i<69;i++) putch(205);


	while(1)
   {
    fin.read((char*)&trvl,sizeof(TRAVELS));

			if(fin.eof()) break;

    end cout<<"    ";for(i=0;i<75;i++) putch(220);end end
    cout<<"\t\t CUSTOMER NAME          :      ";puts(trvl.cust_name);end
    cout<<"\t\t BOOKING ID             :      "<<trvl.travel_id;end
    cout<<"\t\t EMAIL                  :      "<<trvl.travel_id;end
    cout<<"\t\t PHONE No.              :      "<<trvl.travel_id;end end
	 cout<<"\t\t FROM                   :      ";puts(trvl.from);end
    cout<<"\t\t TO                     :      ";puts(trvl.dest);end
    cout<<"\t\t ON DATE                :      ";cout<<trvl.cDay.dd<<" / "<<trvl.cDay.mm<<" / "<<"2013";end
	 cout<<"\t\t BY                     :      ";puts(trvl.mode_travel);end
    cout<<"\t\t No. Of PERSONS         :      ";cout<<trvl.no_tickets;end
    cout<<"\t\t DATE OF BOOKING        :      ";cout<<trvl.cDay.dd<<" / "<<trvl.cDay.mm<<" / "<<"2013";end
    cout<<"\t\t TOTAL AMOUNT RECEIVED  :      Rs. "<<trvl.amount;end end

	}

    getch();
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

    gotoxy(22,2);cout<<"PLEASE ENTER YOU BOOKING ID ";
	 newf.open("temp.dat",ios::binary|ios::out);
    gotoxy(57,2);cin>>id;
    int found=0;
    while(1)
    {
    	oldf.read((char*)&trvl,sizeof(TRAVELS));

       if(oldf.eof()) break;

     if(id==trvl.travel_id)
     	{
      trvl.view_book(0);
      found=1;
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
 {      cout<<"     ARE YOU SURE YOU WANT TO CANCEL THIS BOOKING ? (Y/N) \n";

    ans=getch();
    	if((ans=='Y')||(ans=='y'))
    	{ cout<<"\n\n\n\n\n                 ! !    BOOKING CANCELED    ! !";
      oldf.read((char*)&trvl,sizeof(TRAVELS)); continue; }

  		else
      {
      cout<<"\n\n\n\n\n            !  !  BOOKING NOT CANCELLED  ! !\n";
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




		void TRAVELS::view_city()
	{
      output_box_date_n_time(0);

      gotoxy(55,7);cout<<"* * BOOK MY TRAVEL  ";

      for(i=0;i<6;i++)
   {	gotoxy(44,(i*3)+20);cout<<(i+1)<<".  ";puts(city_list[i]);

   }
      for(i=0;i<6;i++)
   {	gotoxy(80,(i*3)+20);cout<<(i+6)<<".  ";puts(city_list[i+6]);

   }
   }


   /****************************************************************************************/


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

	output_box_date_n_time();
   admin_tour adm;

   gotoxy(56,7);cputs("* *  TOUR ENRTY  * *");
   textcolor(1);
   gotoxy(47,14);cputs("PLEASE ENTER TOUR PACKAGE DETAILS ");

   textcolor(2);
   gotoxy(42,20);cputs("Enter Tour  NAME                 :        ");
   gets(tourname);
   gotoxy(42,22);cputs("Enter Tour  CITY                 :        ");
   gets(city);
   gotoxy(42,24);cputs("Enter Tour  PLACES               :        ");
   gets(place);
   gotoxy(42,26);cputs("Enter Tour  DETAILS              :        ");
   gets(details);
   gotoxy(42,28);cputs("Enter Tour  DAYS                 :        ");
   gets(day);

   do{
   gotoxy(42,30);cputs("Enter Tour  FARE                 :        ");
	}while(take_correct_numeric_value(tariff));
   tour_no=give_id(1);

   gotoxy(43,34);
   if(confirmation()) admin();

   textcolor(5);
   gotoxy(47,40);cputs("!!    ENTRY  IS  SUCCESSFUL    !!");
   gotoxy(48,44);cputs("        TOUR ID  is    :   ");cout<<tour_no<<"  ";
   getch();
}

    int admin_tour::view_tour()
  {

   admin_tour adm;
   int j=0;
   fstream fin;

	gotoxy(54,7);cputs("* * TOUR PACKAGES * *");
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

   do
   {
   opt1=getch();
   	op1=opt1;
      if(op1==13)
      	{
         gotoxy(43,48);
         if(confirmation())
          {
          	gotoxy(53,49);cout<<" CANCELLED ";
            getch();
            gotoxy(43,48);cout<<"\t\t\t\t\t\t";
            gotoxy(53,49);cout<<"\t\t\t\t\t\t\t\t\t";
          }

          else
          {
          gotoxy(53,49);cout<<" DONE !! ";
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

             do
             {
             opt1=getch();
               op1=opt1;

               if(op1==0) break;
          else if(op1==13)
         {
          gotoxy(43,48);
         if(confirmation())
          {
          	gotoxy(53,49);cout<<" CANCELLED ";
            getch();
            gotoxy(43,48);cout<<"\t\t\t\t\t\t\t\t";
            gotoxy(53,49);cout<<"\t\t\t\t\t\t\tt\t\t";
          }
          else
          {
          gotoxy(53,49);cout<<" DONE !! ";
          done=admn[i].tour_no;
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
    gotoxy(56,7);cputs("* *  REMOVE TOUR  * *");

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


    char ans; oldf.close();

    clrscr();
    output_box_date_n_time(0);

	 oldf.open("TOUR_PACKAGES.dat",ios::binary|ios::in);
    oldf.read((char*)&adm,sizeof(admin_tour));
do
  {
  if(rm==adm.tour_no)
  {
   gotoxy(40,20);cout<<"ARE YOU SURE YOU WANT TO REMOVE THIS PACKAGE (Y/N)? ";
    ans=getch();

    	if((ans=='Y')||(ans=='y'))
    	{
      gotoxy(52,25);cout<<"! !        DELETED        ! !";
      oldf.read((char*)&adm,sizeof(admin_tour));
      getch();
		continue;
      }

  		else
      {
      gotoxy(52,25);cout<<"!  !  PACKAGE NOT DELETED ! !\n";
      getch();
      datacount=0;
      }
  }
       	newf.write((char*)&adm,sizeof(admin_tour));
         oldf.read((char*)&adm,sizeof(admin_tour));

 }while(!oldf.eof());

   newf.close();
   oldf.close();

	remove("TOUR_PACKAGES.dat");
   rename("temp.dat","TOUR_PACKAGES.dat");

  empty_file_remove("TOUR_PACKAGES.dat",datacount);


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

textcolor(3);
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
getch();

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

 gotoxy(54,7); cout<<" **  TOUR BOOKINGS  **";

 int totaldetails=give_datacount(2);
 totaldetails;

 int op1,op2;
 char opt1,opt2;
 cust_tour custm[30];
 int done=0;

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
}








/*cout<<"\t     CUSTOMER NAME            :             ";puts(cust_name);end end
cout<<"\t     CUSTOMER EMAIL           :             ";puts(cust_email);end
cout<<"\t     CUSTOMER PHONE           :             "<<cust_phone;end end
cout<<"\t     TOUR NAME                :             ";puts(tourname);end
cout<<"\t     TOUR DATE                :             ";cout<<cDay.dd<<" / "<<cDay.mm<<" / "<<"2013";end
cout<<"\t     No. OF TICKESTS          :             ";cout<<no_seats;end end
cout<<"\t     TOTAL AMOUNT             :             Rs. "<<totamount; end
No_coverter_caller(totamount); end end

cout<<"    ";for(int i=0;i<73;i++) putch(205);
*/



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

         cust.tour_no=give_id(3);

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

        gotoxy(50,32);cout<<"  ! !  BOOKING SUCCESS  ! ! ";
		  getch();clrscr();

        cust.view_book(0);

        getch();

        t.close();temp2.close();
   }

    	void cust_tour::cancel_tour()
   {
    clrscr();

    output_box_date_n_time();
    gotoxy(42,7);cout<<"** CANCEL TRIP ";
    cust_tour cust;

    int id;
    int datacount=0;
    fstream oldf,newf;

    oldf.open("TOUR_BOOKINGS.dat",ios::binary|ios::in);
    if(!oldf)
    {
             clrscr();
             output_box_date_n_time(0);
             output_box_date_n_time(0);
             gotoxy(57,26);
             textcolor(12);
             cputs(" NO TOUR PACKAGES ");
             getch();
             customer();
    }

    gotoxy(32,15);cout<<"PLEASE ENTER YOU BOOKING ID : ";
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
 {      cout<<"\n\t\t     ARE YOU SURE YOU WANT TO CANCEL THIS BOOKING ? (Y/N) \n";
    cin>>ans;
    	if((ans=='Y')||(ans=='y'))
    	{ cout<<"\n\n\t\t\t\t    !  !    BOOKING CANCELED    !  !";
      oldf.read((char*)&cust,sizeof(cust_tour)); continue; }
   else
   {
   cout<<"\n\n\t\t\t\t   !  !  BOOKING NOT CANCELLED   !  !\n";
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

   gotoxy(48,7);cputs(" *  *   ADMINISTRATOR  MENU   *  *");
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

   gotoxy(x,18);cout<<"=====>";

   do{
   opt1=getch();
   op1=opt1;

   }while(!((op1==13)||(op1==27)||(op1==0)));
   if(op1==27) menu();

   else if(op1==13)
   {
           fin.open("TOUR_BOOKINGS.dat",ios::binary|ios::in);
        	if(!fin)
     		{
        		clrscr();
            output_box_date_n_time(0);
        		gotoxy(57,26);
            textcolor(12);
            cputs(" NO TOUR BOOKINGS ");
            getch();
        		admin();
	  		}

         clrscr();
         gotoxy(29,4); cout<<" ** TOUR BOOKINGS **";

         output_box_date_n_time(0);

	 	 	while(1)
       	{
        	fin.read((char*)&cust,sizeof(cust_tour));
        	if(fin.eof()) break;

    	 	cust.view_book();
        	}

        	getch();clrscr();
    		 fin.close();
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
               gotoxy(x,y);cout<<"=====>";

               opt1=getch();

               op1=opt1;
               if(op1==0) break;

               if(op1==27) menu();

               if(opt1==13)
             {
       if(y==18)
               {
                fin.open("TOUR_BOOKINGS.dat",ios::binary|ios::in);
               	if(!fin)
             		{
             		output_box_date_n_time(0);
             gotoxy(57,26);
             textcolor(12);
             cputs(" NO TOUR PACKAGES ");
             getch();
             admin();
				 		}

             	clrscr();
             	gotoxy(29,4); cout<<" ** TOUR BOOKINGS **";

             	output_box_date_n_time(0);

				 	while(1)
             	{
             	fin.read((char*)&cust,sizeof(cust_tour));
              	if(fin.eof()) break;

    			 	cust.view_book();
             	}

             	getch();clrscr();
            		 fin.close();
             	admin();
					}
		else if(y==21)
             {
                clrscr();
                gotoxy(29,4); cout<<" ** TRAVEL BOOKINGS ** ";
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


   gotoxy(52,7);cputs("*  *   CUSTOMER  MENU   *  *");
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

   gotoxy(x,20);cout<<"=====>";
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
      gotoxy(x,y);cout<<"=====>";

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
{
	clrscr();

   int attempts=3;
   char passwrd[7];

   fstream passfile;
   passfile.open("ADMIN_PASS.dat",ios::binary|ios::in);

   admin_pass A;

   passfile.read((char*)&A,sizeof(admin_pass));
   A.getcode(passwrd);

   do{

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
   gotoxy(63,23);
	cout<<"            ";
	gotoxy(63,23);

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
  		admin();
    Mv_logo();
    textcolor(15);
    gotoxy(23,7);
	 for(i=0;i<84;i++) { Sleep(1);putch(177); }
    gotoxy(23,21);
	 for(i=0;i<84;i++) { Sleep(1); putch(177); }
    for(i=8;i<22;i++)
	{	gotoxy(23,i); putch(177); gotoxy(106,i); putch(177);  Sleep(20);}Sleep(300);


    textcolor(12);
	 gotoxy(34,12);cputs("#     #    ####    #         ###      ##      #     #    #### ");Sleep(170);
	 gotoxy(34,13);cputs("#     #    #       #       #        #    #    # # # #    #    ");Sleep(170);
	 gotoxy(34,14);cputs("#  #  #    ####    #       #        #    #    #  #  #    #### ");Sleep(170);
	 gotoxy(34,15);cputs("# # # #    #       #       #        #    #    #     #    #    ");Sleep(170);
	 gotoxy(34,16);cputs("#     #    ####    #####     ###      ##      #     #    #### ");Sleep(170);

     textcolor(15);
     gotoxy(23,26);
	  for(i=0;i<84;i++) { Sleep(0.1);putch(177); }
     gotoxy(23,38);
	  for(i=0;i<84;i++) { Sleep(0.1);putch(177); }
     for(i=26;i<38;i++)
	 { 	gotoxy(23,i); putch(177); gotoxy(106,i); putch(177); Sleep(20); }

     textcolor(10);
     int x=3;
     while(x-->0)
     {
	  gotoxy(48,30);cputs("   THE STAR TRAVELS AND TOURISM   ");Sleep(110);
     gotoxy(49,30);cputs("   THE STAR TRAVELS AND TOURISM   ");Sleep(110);
     gotoxy(50,30);cputs("   THE STAR TRAVELS AND TOURISM   ");Sleep(110);
     gotoxy(49,30);cputs("   THE STAR TRAVELS AND TOURISM   ");Sleep(110);
     }

     x=3;
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
	char op1,op2;
   output_box_date_n_time(0);

   textcolor(3);
   gotoxy(48,7);
	cputs("!!   PLEASE SELECT YOUR ACCOUNT   !!");
       textcolor(6);
		 gotoxy(55,23);
   	cputs("<>   ADMINISTRATOR");
		 gotoxy(55,29);
		cputs("<>   CUSTOMER");

      textcolor(8);
	gotoxy(38,46);
   cputs("(   Use Up And Down Arrow To Select And Press Enter   )");

   	textcolor(15);
      int opt1,opt2;
      gotoxy(42,23);
      cputs("======>");
      gotoxy(80,23);
      cputs("<======");
      gotoxy(31,24);
      op1=getch();
      opt1=op1;

      if(opt1==13)
      pass();

   else if(opt1==0)
 {
	do{
      op2=getch();
      opt2=op2;
		switch(opt2)
       {
        	case 72: do
         	    {
         			gotoxy(42,23); cputs("======>");
         	      gotoxy(42,29); cputs("       ");
                  gotoxy(80,23); cputs("<======");
                  gotoxy(80,29); cputs("       ");

                 	op1=getch();
                  opt1=op1;
                  if(opt1==13)
                  	pass();
                else if(opt1==0)
                  	break;
                else if(!((opt1==0)||(opt1==13)))
                {
                textcolor(15);
                gotoxy(52,42);cputs("!!!  WRONG OPTION   !!!");
                }

            }while(!((opt1==0)||(opt1==13)));
            		break;
         case 80 : do
         			{
         			gotoxy(42,23); cputs("       ");
                  gotoxy(42,29); cputs("======>");
                  gotoxy(80,23); cputs("       ");
                 	gotoxy(80,29); cputs("<======");

                   op1=getch();
                   opt1=op1;

                   if(opt1==13)
                  	customer();

                  else if(opt1==0)
								break;

                  else if(!((opt1==0)||(opt1==13)))
                {
                textcolor(15);
            	gotoxy(52,42);cputs("!!!  WRONG OPTION   !!!");
                 }

            }while(!((opt1==0)||(opt1==13)));
            break;

  		default: textcolor(15);
      			gotoxy(52,42);cputs("!!!  WRONG OPTION   !!!");
      };

}while(1);

}
  else
  {
  		textcolor(15);
  		gotoxy(52,42);cputs("!!!  WRONG OPTION   !!!");
   	menu();
      }
}


