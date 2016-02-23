#include<fstream.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<dos.h>
#include<windows.h>

#define end cout<<endl;
#define line cout<<"  *";for(i=0;i<37;i++) cout<<"=*";

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
char passwrd[10]={'1','2','3','4'};             

void intro();
void menu();
void pass();

void admin();
void customer();

/*************   SPF   **************/

void printing();
void output_box_date_n_time(int check_if_end_needed);
void target_up_down();
void No_converter(long,char[]);
void No_coverter_caller(int n);
int empty_file_remove(char file[],int check);



void No_coverter_caller(int n)
{		No_converter((n/10000000)," Crore ");
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





void target_up_down(int keystroke, int &position)
{
     gotoxy(31,16);cout<<"       ";
     gotoxy(31,18);cout<<"       ";
     gotoxy(31,20);cout<<"       ";
	  gotoxy(31,22);cout<<"       ";
     gotoxy(31,24);cout<<"       ";
     gotoxy(31,26);cout<<"       ";

   if(keystroke==72)
   	{
       if(position==0) position=5;
  else if(position==1) position=5;
  else if(position==2) position=1;
  else if(position==3) position=2;
  else if(position==4) position=3;
  else if(position==5) position=4;
  		}

  else if(keystroke==80)
		{
       if(position==0) position=1;
  else if(position==1) position=2;
  else if(position==2) position=3;
  else if(position==3) position=4;
  else if(position==4) position=5;
  else if(position==5) position=1;
      }

  else {
  gotoxy(39,35);cout<<"!!!   WRONG OPTION   !!!";
       }
}


void output_box_date_n_time(int check_if_end_needed=0)
{

textcolor(15);
gotoxy(5,2);putch(201);
for(int i=0;i<92;i++) putch(205);
putch(187);

for(i=3;i<8;i++)
{	gotoxy(5,i); putch(186); gotoxy(98,i); putch(186); }

gotoxy(5,8); putch(200);
for(i=0;i<92;i++) putch(205);
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

textcolor(12);
gotoxy(36,4); cputs("~~   TOURS AND TRAVELS SYSTEM   ~~");
gotoxy(51,7);  //title goes here...

textcolor(11);
gotoxy(9,7);  cputs(" DATE  :  ");cprintf("%d",day);cputs("/");cprintf("%d",mon);cputs("/");cprintf("%d",year);
gotoxy(79,7); cputs(" TIME  :  ");cprintf("%d",hour);cputs(":");cprintf("%d",min);

textcolor(15);

if(check_if_end_needed==0)
{
gotoxy(5,9);putch(201);
for(int i=0;i<92;i++) putch(205);
putch(187);

for(i=10;i<43;i++)
{	gotoxy(5,i); putch(186); gotoxy(98,i); putch(186); }

gotoxy(5,43); putch(200);
for(i=0;i<92;i++) putch(205);
putch(188);
}

/*else
{
for(int i=8;i<43;i++)
{	gotoxy(2,i); putch(186); gotoxy(79,i); putch(186); }
}*/

}


struct tdate
{
	int dd,mm,yy;
};


	class TRAVELS
{
	public : char mode_travel[20];
   			char cust_name[20],from[20],dest[20];
            int amount,no_tickets;
				int cust_phone,travel_id;
            tdate cDay;

            void view_TRAVELS();
            void view_city();
   			void book_TRAVELS();
            void view_book();
            void view_book(int check);
            void cancel_travel();
            int give_id(TRAVELS trvl);

				TRAVELS()
            {
					cDay.yy=2013;
            }

};

	  void TRAVELS::book_TRAVELS()
{
   TRAVELS trvl;
	clrscr();
   int frm,to,op;

   end line end
   cout<<"\t\t     **  WELCOME TO TRAVELS BOOKING PAGE  **\n\n";
   cout<<"\t\t     *  PLEASE ENTER THE FOLLOWING DETAILS  *\n";

   line end end end

   cout<<"\t\t  PLEASE ENTER YOUR NAME              -     ";
   gets(cust_name);

   cout<<"\n\t\t  PLEASE ENTER YOUR PHONE NO.         -     ";
   cin>>cust_phone;
   do{
   clrscr();
   end line end
   cout<<"\t\t  **  PLEASE SELECT YOUR PICKUP CITY  **";

   end line end view_city();
   cin>>frm;
   if(!((frm>=1)&&(frm<=12)))
   {
   gotoxy(27,1);cout<<" ! ! WRONG OPTION ! !\n";
	getch();
   }
   }while(!((frm>=1)&&(frm<=12)));

   strcpy(from,city_list[frm-1]);

   do{
   clrscr();
   end end line end

   cout<<"\t\t    **  PLEASE SELECT YOUR DESTINATION CITY  **";

   end line view_city();
   cin>>to;
   if(!((frm>=1)&&(frm<=12)))
   {
	gotoxy(27,1);cout<<" ! ! WRONG OPTION ! !\n";
   getch();
   }
   }
   while(!((to>=1)&&(to<=12)&&(frm!=to)));

   strcpy(dest,city_list[to-1]);

   clrscr();
   end line end end end

   cout<<"\t\t        PLEASE ENTER DATE OF JOURNEY \n\n\n\n\n";
   cout<<"\t\t   ENTER MONTH (In No.)     -      ";
   cin>>cDay.mm;end
   cout<<"\t\t   ENTER DATE               -      ";
   cin>>cDay.dd; end line end end

   cout<<"\t\t   PLEASE ENTER NO. OF TICKEST REQUIRED  -  ";
   cin>>no_tickets; end line end end end

   cout<<"\t\t        PLEASE CHOOSE MODE OF TRAVEL \n\n\n\n";
   cout<<"\t\t        1. BUS   ( A/C and VOLVO ) \n\n";
   cout<<"\t\t        2. MINI VAN    (PRIVATE)   \n\n";
   cout<<"\t\t        3. TAXI        (PRIVATE)   \n\n";
   cin>>op;
   end line end end
   if(op==1) strcpy(mode_travel,"BUS");
   else if(op==2) strcpy(mode_travel,"MINI VAN");
   else if(op==3) strcpy(mode_travel,"TAXI");

   amount=((random(5)*1000-random(5)*100)*no_tickets);
   travel_id=give_id(trvl);
	end end end end line end
   cout<<"\t\t    ! ! BOOKING SUCCESS  ! !";
   end line end
   getch();clrscr();
   view_book(1);

   }


      void TRAVELS::view_book(int check)

{	for(i=12;i<40;i++){ gotoxy(17,i);putch(178); }
	for(i=12;i<40;i++){ gotoxy(87,i);putch(178); }

gotoxy(17,11);for(i=0;i<69;i++) putch(205);
gotoxy(45,13);cout<<"##  TRIP TICKET  ##";
gotoxy(17,15);for(i=0;i<69;i++) putch(205);
gotoxy(30,17);cout<<"CUSTOMER NAME             -";gotoxy(65,17);puts(cust_name);
gotoxy(30,18);cout<<"CUSTOMER PHONE            -";gotoxy(65,18);cout<<(cust_phone);
gotoxy(30,19);cout<<"CUSTOMER EMAIL            -";gotoxy(65,18);puts(cust_name);
gotoxy(17,21);for(i=0;i<69;i++) putch(205);
gotoxy(31,23);cout<<"BOARDING FROM           -";gotoxy(63,23);puts(from);
gotoxy(31,24);cout<<"DESTINATION             -";gotoxy(63,24);puts(dest);
gotoxy(31,26);cout<<"DATE OF JOURNEY         -";gotoxy(63,26);cout<<cDay.dd<<" / "<<cDay.mm<<" / "<<"2013";
gotoxy(31,28);cout<<"MODE OF TRAVEL          -";gotoxy(63,28);puts(mode_travel);
gotoxy(31,29);cout<<"No. OF PERSONS          -";gotoxy(63,29);cout<<no_tickets;
gotoxy(17,31);for(i=0;i<69;i++) putch(205);
gotoxy(39,32);for(i=0;i<28;i++) putch(224);
gotoxy(39,33);putch(224);putch(224);cout<<"     TOTAL AMOUNT :      ";putch(220);putch(220);
gotoxy(39,35);putch(224);putch(224);cout<<"      Rs. "<<amount;gotoxy(67,35);putch(220);putch(220);
gotoxy(39,36);for(i=0;i<28;i++) putch(224);
gotoxy(24,38);cout<<"Rs. - ";No_coverter_caller(amount);cout<<" ONLY ";
gotoxy(17,39);for(i=0;i<69;i++) putch(205);
getch();
}


      void TRAVELS::view_book()
{
    TRAVELS trvl;

    gotoxy(7,1);for(i=0;i<69;i++) putch(205);
    gotoxy(33,2);cout<<"TRAVEL BOOKINGS ";
    gotoxy(7,3);for(i=0;i<69;i++) putch(205);

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

    fin.read((char*)&trvl,sizeof(TRAVELS));
   do
   {
    end cout<<"    ";for(i=0;i<75;i++) putch(220);end end
    cout<<"\t\t CUSTOMER NAME          -      ";puts(trvl.cust_name);end
    cout<<"\t\t BOOKING ID             -      "<<trvl.travel_id;end
    cout<<"\t\t EMAIL                  -      "<<trvl.travel_id;end
    cout<<"\t\t PHONE No.              -      "<<trvl.travel_id;end end
	 cout<<"\t\t FROM                   -      ";puts(trvl.from);end
    cout<<"\t\t TO                     -      ";puts(trvl.dest);end
    cout<<"\t\t ON DATE                -      ";cout<<trvl.cDay.dd<<" / "<<trvl.cDay.mm<<" / "<<"2013";end
	 cout<<"\t\t BY                     -      ";puts(trvl.mode_travel);end
    cout<<"\t\t No. Of PERSONS         -      ";cout<<trvl.no_tickets;end
    cout<<"\t\t DATE OF BOOKING        -      ";cout<<trvl.cDay.dd<<" / "<<trvl.cDay.mm<<" / "<<"2013";end
    cout<<"\t\t TOTAL AMOUNT RECEIVED  -      Rs. "<<trvl.amount;end end

    fin.read((char*)&trvl,sizeof(TRAVELS));

   }while(!fin.eof());

    getch();
}

    void TRAVELS::cancel_travel()
{
	clrscr();
	 TRAVELS trvl;
    int id;
    int datacount=0;

    fstream oldf,newf;
    oldf.open("TRAVEL_BOOKINGS.dat",ios::binary|ios::in);
    if(!oldf)
    			{
             clrscr();
             output_box_date_n_time(0);
             gotoxy(41,24);
             cout<<" NO TRAVEL BOOKINGS ";
             getch();
             customer();
             }

    gotoxy(22,2);cout<<"PLEASE ENTER YOU BOOKING ID ";
	 newf.open("temp.dat",ios::binary|ios::out);
    gotoxy(57,2);cin>>id;

    oldf.read((char*)&trvl,sizeof(TRAVELS));
    do
    {
     if(id==trvl.travel_id)
     	trvl.view_book(0);

    oldf.read((char*)&trvl,sizeof(TRAVELS));
    datacount++;

    }while(!oldf.eof());

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
      for(i=0;i<6;i++)
   {	gotoxy(20,(i*3)+8);cout<<(i+1)<<".  ";puts(city_list[i]);
   	end
   }
      for(i=6;i<12;i++)
   {	gotoxy(47,(i*3)-10);cout<<(i+1)<<".  ";puts(city_list[i]);
   	end
   }
   }


   /****************************************************************************************/


	class tour
{
	public : char tourname[20],place[20],day[40],city[30],details[200];
   			int tour_no,tariff;
};


	class admin_tour : public tour
{
	public : admin_tour()
   			{
            	strcpy(tourname,"0/");
               strcpy(place,"0/");
               strcpy(day,"0/");
					strcpy(details,"0/");
               tour_no=0;
               tariff=0;
            }

   			void view_tour();
            void view_tour(int chk);
				int give_id(admin_tour adm);
            void entry();
   			void remove_tour();
};

		void admin_tour::entry()
   {
   clrscr();

	output_box_date_n_time();
   admin_tour adm;

   gotoxy(43,7);cout<<"**  TOUR ENRTY  **";
   gotoxy(35,14);cout<<"PLEASE ENTER TOUR PACKAGE DETAILS ";
   gotoxy(30,20);cout<<"ENTER TOUR NAME                -      ";
   gets(tourname);
   gotoxy(30,22);cout<<"ENTER TOUR CITY                -      ";
   gets(city);
   gotoxy(30,24);cout<<"ENTER TOUR PLACES              -      ";
   gets(place);
   gotoxy(30,26);cout<<"ENTER TOUR DETAILS             -      ";
   gets(details);
   gotoxy(30,28);cout<<"ENTER TOUR DAYS                -      ";
   gets(day);
   gotoxy(30,30);cout<<"ENTER TOUR FARE PER PERSON     -      ";
	cin>>tariff;
   tour_no=give_id(adm);

   gotoxy(35,36);cout<<"!!   ENTRY  IS  SUCCESSFUL  !!";
   gotoxy(35,38);cout<<"        TOUR NO IS    -   "<<tour_no;
   getch();
}


    void admin_tour::view_tour()
  {
   clrscr();

   admin_tour adm;
   int j=0;
   fstream fin;

   output_box_date_n_time(1);

	gotoxy(42,7);cout<<"** TOUR PACKAGES **";
   fin.open("TOUR_PACKAGES.dat",ios::binary|ios::in);
   if(!fin)
             {
             clrscr();
             output_box_date_n_time(0);
             gotoxy(41,24);
             cout<<" NO TOUR PACKAGES ";
             getch();
             admin();
             }
   fin.read((char*)&adm,sizeof(admin_tour));
   do
    {

   gotoxy(27,((j*24)+12));cout<<"TOUR No.                    -        ";cout<<adm.tour_no;
   gotoxy(27,((j*24)+14));cout<<"TOUR NAME                   -        ";puts(adm.tourname);
   gotoxy(27,((j*24)+16));cout<<"TOUR CITY                   -        ";puts(adm.city);
	gotoxy(27,((j*24)+18));cout<<"PLACES                      -        ";puts(adm.place);
   gotoxy(27,((j*24)+20));cout<<"DETAILS                     -        ";puts(adm.details);
   gotoxy(27,((j*24)+23));cout<<"TOUR DAYS                   -        ";puts(adm.day);
   gotoxy(27,((j*24)+25));cout<<"TOUR TICKET PER PERSON      -        Rs. "<<adm.tariff;

   gotoxy(28,((j*24)+27));cout<<" ONLY - ";
   No_coverter_caller(adm.tariff);cout<<" /-";

   gotoxy(10,((j*24)+31));for(int i=0;i<82;i++) putch(205);

   j++;

   fin.read((char*)&adm,sizeof(admin_tour));

   }while(!fin.eof());

    getch();clrscr();
    fin.close();
  }

  void admin_tour::view_tour(int chk)
  {

   end end
   cout<<"\t\t     TOUR No.                   -       ";cout<<tour_no;end end
   cout<<"\t\t     TOUR NAME                  -       ";puts(tourname);end
   cout<<"\t\t     TOUR CITY                  -       ";puts(city);end
   cout<<"\t\t     PLACES                     -       ";puts(place);end
   cout<<"\t\t     DETAILS                    -       ";puts(details);end end
   cout<<"\t\t     TOUR DAYS                  -       ";puts(day);end
   cout<<"\t\t     TOUR TICKET PER PERSON     -       Rs. "<<tariff;end end
	cout<<"\t"; for(int i=0;i<80;i++) putch(205);  end end end

  }

   void admin_tour::remove_tour()
	{
    clrscr();

    output_box_date_n_time(1);
    gotoxy(34,4);cout<<" REMOVE TOUR ";

    admin_tour adm;
    int rm;
    int datacount=0;
    fstream oldf,newf;

    gotoxy(28,7);cout<<"PLEASE SELECT THE PACKAGE ";
    oldf.open("TOUR_PACKAGES.dat",ios::binary|ios::in);
    if(!oldf)
             {
             clrscr();
             output_box_date_n_time(0);
             gotoxy(39,24);
             cout<<"!!  NO TOUR PACKAGES !!";
             getch();
             admin();
             }

    newf.open("temp.dat",ios::binary|ios::out);
    oldf.read((char*)&adm,sizeof(admin_tour));
            do
            {
    			adm.view_tour(0);
            oldf.read((char*)&adm,sizeof(admin_tour));
            datacount++;
            }while(!oldf.eof());
    gotoxy(53,7);cin>>rm;

    clrscr(); end end end
    char ans; oldf.close();

	 oldf.open("TOUR_PACKAGES.dat",ios::binary|ios::in);
    oldf.read((char*)&adm,sizeof(admin_tour));

    output_box_date_n_time(1);

 do
  {
  if(rm==adm.tour_no)
  {
   cout<<"\n\n\n\t\tARE YOU SURE YOU WANT TO REMOVE THIS PACKAGE (Y/N)? ";
    cin>>ans;

    	if((ans=='Y')||(ans=='y'))
    	{
      cout<<"\n\n\n\n\n\\n\\t\t\t! !        DELETED        ! !";
      oldf.read((char*)&adm,sizeof(admin_tour));
		continue;
      }

  		else
      {
      cout<<"\n\n\n\t\t\t!  !  PACKAGE NOT DELETED ! !\n";
      datacount=0;
      }
  }
       	newf.write((char*)&adm,sizeof(admin_tour));
         oldf.read((char*)&adm,sizeof(admin_tour));

  }while(!oldf.eof());

   getch();

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
   			int cust_phone,totamount;
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
            void book_tour();
   			void cancel_tour();
     			int give_id(cust_tour cust);
};

void cust_tour::view_book(int iscust)
{

clrscr();
output_box_date_n_time();

for(i=12;i<40;i++){ gotoxy(17,i);putch(178); }
for(i=12;i<40;i++){ gotoxy(87,i);putch(178); }

gotoxy(17,11);for(i=0;i<71;i++) putch(220);
gotoxy(45,13);cout<<"##  TRIP TICKET  ##";
gotoxy(17,15);for(i=0;i<71;i++) putch(220);
gotoxy(30,17);cout<<"CUSTOMER NAME             -";gotoxy(65,17);puts(cust_name);
gotoxy(30,18);cout<<"CUSTOMER PHONE            -";gotoxy(65,18);cout<<cust_phone;
gotoxy(30,19);cout<<"CUSTOMER EMAIL            -";gotoxy(65,19);puts(cust_email);
gotoxy(17,21);for(i=0;i<71;i++) putch(220);
gotoxy(31,23);cout<<"TOUR NAME               -";gotoxy(63,23);puts(tourname);
gotoxy(31,24);cout<<"TOUR CITY               -";gotoxy(63,24);puts(city);
gotoxy(31,26);cout<<"DATE OF JOURNEY         -";gotoxy(63,26);cout<<cDay.dd<<" / "<<cDay.mm<<" / "<<"2013";
gotoxy(31,28);cout<<"No. OF PERSONS          -";gotoxy(63,28);cout<<no_seats;
gotoxy(17,30);for(i=0;i<71;i++) putch(220);
gotoxy(39,32);for(i=0;i<30;i++) putch(224);
gotoxy(39,33);putch(224);putch(224);cout<<"     TOTAL AMOUNT :       ";putch(220);putch(220);
gotoxy(39,35);putch(224);putch(224);cout<<"      Rs. "<<totamount;gotoxy(67,36);putch(220);putch(220);
gotoxy(39,36);for(i=0;i<30;i++) putch(224);
gotoxy(24,38);cout<<"Rs. - ";No_coverter_caller(totamount);cout<<" ONLY ";
gotoxy(17,39);for(i=0;i<71;i++) putch(220);

getch();

}

void cust_tour::view_book()
{
end end end
cout<<"\t     CUSTOMER NAME            -             ";puts(cust_name);end end
cout<<"\t     CUSTOMER EMAIL           -             ";puts(cust_email);end
cout<<"\t     CUSTOMER PHONE           -             "<<cust_phone;end end
cout<<"\t     TOUR NAME                -             ";puts(tourname);end
cout<<"\t     TOUR DATE                -             ";cout<<cDay.dd<<" / "<<cDay.mm<<" / "<<"2013";end
cout<<"\t     No. OF TICKESTS          -             ";cout<<no_seats;end end
cout<<"\t     TOTAL AMOUNT             -             Rs. "<<totamount; end
No_coverter_caller(totamount); end end

cout<<"    ";for(int i=0;i<73;i++) putch(205);

}


void cust_tour::book_tour()
	{    clrscr();

         cust_tour cust,c;
         admin_tour adm;

         fstream temp;

         temp.open("TOUR_PACKAGES.dat",ios::binary|ios::in);
         if(!temp)
             {
             clrscr();
             output_box_date_n_time(0);
             gotoxy(41,24);
             cout<<" NO TOUR PACKAGES ";
             getch();
             customer();
             }
         output_box_date_n_time(1);
			gotoxy(55,7);;cout<<"** BOOK TOUR **";
         gotoxy(30,14);cout<<" ENTER YOUR NAME     -     ";
         gets(cust.cust_name);
         gotoxy(30,16);cout<<" ENTER YOUR EMAIL    -     ";
         gets(cust.cust_email);
         gotoxy(30,18);cout<<" ENTER YOUR PHONE    -     ";
         cin>>cust_phone;
         gotoxy(30,21);cout<<" PLEASE SELCET TOUR PACKAGE  -  ";


         temp.read((char*)&adm,sizeof(admin_tour));
         do
         {
         adm.view_tour(0);
         temp.read((char*)&adm,sizeof(admin_tour));

			}while(!temp.eof());

         int tm;
         gotoxy(67,21);cin>>tm;

         clrscr();
         output_box_date_n_time();

         gotoxy(45,7);cout<<"** BOOK TOUR **";

         gotoxy(37,14);cout<<"PLEASE ENTER DATE OF JOURNEY";
         gotoxy(35,17);cout<<"ENTER MONTH (In Digits.)   -     ";
         cin>>cust.cDay.mm;
         gotoxy(35,19);cout<<"ENTER DATE                 -     ";
         cin>>cust.cDay.dd;
         gotoxy(32,23);cout<<"PLEASE ENTER NO. OF TICKEST REQUIRED  -  ";
         cin>>cust.no_seats;

         temp.close();

         cust.tour_no=cust.give_id(c);
         fstream temp2;
         temp2.open("TOUR_BOOKINGS.dat",ios::binary|ios::app);
         fstream t;
         t.open("TOUR_PACKAGES.dat",ios::binary|ios::in);

         t.read((char*)&adm,sizeof(admin_tour));
        do{
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

          t.read((char*)&adm,sizeof(admin_tour));

			}while(!t.eof());

        clrscr();

        output_box_date_n_time();

        gotoxy(40,20);cout<<"  ! !  BOOKING SUCCESS  ! ! ";
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
             gotoxy(41,24);
             cout<<" NO TOUR BOOKINGS ";
             getch();
             customer();
    }

    gotoxy(32,15);cout<<"PLEASE ENTER YOU BOOKING ID - ";
    cin>>id;

	 newf.open("temp.dat",ios::binary|ios::out);

    oldf.read((char*)&cust,sizeof(cust_tour));
    do
    {
     if(id==cust.tour_no)
     	cust.view_book(0);
    oldf.read((char*)&cust,sizeof(cust_tour));
    datacount++;
    }while(!oldf.eof());

    oldf.close();

    char ans;

	 oldf.open("TOUR_BOOKINGS.dat",ios::binary|ios::in);
    oldf.read((char*)&cust,sizeof(cust_tour));
 do
  {
   if(id==cust.tour_no)
 {      cout<<"\n\t\t     ARE YOU SURE YOU WANT TO CANCEL THIS BOOKING ? (Y/N) \n";
    ans=getch();
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

   gotoxy(39,7);cout<<"  * *   ADMINISTRATOR  MENU   * *";
   gotoxy(42,16);cout<<"<> VIEW TOUR BOOKINGS ";
   gotoxy(42,18);cout<<"<> VIEW TRAVEL BOOKINGS ";
   gotoxy(42,20);cout<<"<> CREATE NEW TOUR PACKAGES";
   gotoxy(42,22);cout<<"<> VIEW TOUR PACKAGES ";
   gotoxy(42,24);cout<<"<> DELETE TOUR PACKAGES ";
   gotoxy(42,26);cout<<"<> CHANGE PASSWORD ";

   gotoxy(36,38);cout<<"( * * PRESS Esc TO GO BACK * * )";
   gotoxy(28,41);cout<<"( USE UP AND DOWN ARROW TO SELECT AND PRESS ENTER )";

	fstream fout;
   fstream fin;

   char op1,op2;
   int opt1,opt2,pos=1;

   gotoxy(31,16);cout<<" =====>";
      gotoxy(35,29);
      op1=getch();
      opt1=op1;
      if(opt1==13)
   {
   fin.open("TOUR_BOOKINGS.dat",ios::binary|ios::in);
             if(!fin)
             {
             clrscr();
             output_box_date_n_time(0);
             gotoxy(41,24);
             cout<<" NO TOUR PACKAGES ";
             getch();
             admin();
             }
             clrscr();
             gotoxy(29,4); cout<<"** TOUR BOOKINGS **";

             output_box_date_n_time(1);
				 fin.read((char*)&cust,sizeof(cust_tour));
             do
             {
    			 cust.view_book();
             fin.read((char*)&cust,sizeof(cust_tour));
             }while(!fin.eof());

             getch();clrscr();
				 fin.close();
             admin();
   }
    else  if(opt1==0)
 {
	do{
      gotoxy(39,23);
      op2=getch();

      opt2=op2;

      target_up_down(opt2,pos);

      switch(pos)
     {
   case 1:
				gotoxy(31,16);cout<<" =====>";

             do{
                 	op1=getch();
                  opt1=op1;
                  if(opt1==13)
             {

             fin.open("TOUR_BOOKINGS.dat",ios::binary|ios::in);

             if(!fin)
             {
             clrscr();
             output_box_date_n_time(0);
             gotoxy(42,24);
             cout<<"!!   NO BOOKINGS    !!";
             getch();
             admin();
				 }

             clrscr();
             gotoxy(29,4); cout<<" ** TOUR BOOKINGS **";

             output_box_date_n_time(1);
				 fin.read((char*)&cust,sizeof(cust_tour));
             do
             {
    			 cust.view_book();
             fin.read((char*)&cust,sizeof(cust_tour));
             }while(!fin.eof());

             getch();clrscr();
             fin.close();
             admin();
				 }
             else if(opt1==27)
             menu();
             else if(opt1==0)
             break;
             else if (!((opt1==0)||(opt1==13)||(opt1==27)))
             {
             gotoxy(39,35);cout<<"!!!   WRONG OPTION   !!!";
   }
             }while(!((opt1==0)||(opt1==13)||(opt1==27)));
             break;

    case 2 :   do
    				{

               gotoxy(31,18);cout<<" =====>";

               	op1=getch();
                  opt1=op1;
                  if(opt1==13)
                {
                clrscr();
                gotoxy(29,4); cout<<" ** TRAVEL BOOKINGS ** ";
                trvl.view_book();
                admin();
                }

             else if(opt1==27)
             menu();

             else if(opt1==0)
             break;

             else if (!((opt1==0)||(opt1==13)||(opt1==27)))
             {
             gotoxy(39,35);cout<<"!!!   WRONG OPTION   !!!";
   }
             }while(!((opt1==0)||(opt1==13)||(opt1==27)));
             break;

    case 3:  do
           {
           gotoxy(31,20);cout<<" =====>";

                 	op1=getch();
                  opt1=op1;
                  if(opt1==13)
            {
				fout.open("TOUR_PACKAGES.dat",ios::binary|ios::app);
				adm.entry();
            clrscr();
			  	fout.write((char*)&adm,sizeof(admin_tour));
            fout.close();
            admin();
            }

             else if(opt1==27)
             menu();

             else if(opt1==0)
             break;

             else if (!((opt1==0)||(opt1==13)||(opt1==27)))
             {
             gotoxy(39,35);cout<<"!!!   WRONG OPTION   !!!";
   }
            }while(!((opt1==0)||(opt1==13)||(opt1==27)));
             break;

    case  4: do
    			{
            		gotoxy(31,22);cout<<" =====>";

                 	op1=getch();
                  opt1=op1;
                  if(opt1==13)
            {
    			adm.view_tour();
            admin();
            }

				 else if(opt1==27)
             menu();

             else if(opt1==0)
             break;

             else if (!((opt1==0)||(opt1==13)||(opt1==27)))
             {
             gotoxy(39,35);cout<<"!!!   WRONG OPTION   !!!";
   }
             }while(!((opt1==0)||(opt1==13)||(opt1==27)));

             break;
    case 5 : do
    			{
            	gotoxy(31,24);cout<<" =====>";

               op1=getch();
                  opt1=op1;
                  if(opt1==13)
            {
            adm.remove_tour();
            admin();
            }

             else if(opt1==27)
             menu();

             else if(opt1==0)
             break;

             else if (!((opt1==0)||(opt1==13)||(opt1==27)))
				 {
             gotoxy(39,35);cout<<"!!!   WRONG OPTION   !!!";
   }
             }while(!((opt1==0)||(opt1==13)||(opt1==27)));

             break;

      };
   }while(1);
 }

   else if(opt1==27)
   menu();

   else if(opt1!=0)
   {
	gotoxy(39,35);cout<<"!!!   WRONG OPTION   !!!";
   admin();
   }
}

/****************************************************************************************/

void customer()
{
clrscr();

cust_tour cust;
TRAVELS trvl;
fstream file;

   output_box_date_n_time();

   char op1,op2;

   gotoxy(39,7);cout<<"* *   CUSTOMER  MENU   * *";
   gotoxy(42,16);cout<<"<> BOOK MY TOUR";
   gotoxy(42,18);cout<<"<> BOOK MY TRAVELS ";
   gotoxy(42,20);cout<<"<> CANCEL TOUR BOOKINGS ";
   gotoxy(42,22);cout<<"<> CANCEL TRAVEL BOOKINGS ";
   gotoxy(42,24);cout<<"<> OFFER OF THE DAY !!";


   gotoxy(36,38);cout<<"( * * PRESS Esc TO GO BACK * * )";
   gotoxy(28,41);cout<<"( USE UP AND DOWN ARROW TO SELECT AND PRESS ENTER )";

   fstream f;
   int opt1,opt2,pos=1;

   gotoxy(31,16);cout<<" =====>";

      gotoxy(35,29);
      op1=getch();
      opt1=op1;
      if(opt1==13)
             {
             cust.book_tour();clrscr();
             customer();
             }

     else if(opt1==0)
 {
	do{
      gotoxy(39,23);
		op2=getch();

      opt2=op2;

      target_up_down(opt2,pos);

      switch(pos)
     {

   case 1:   gotoxy(31,16);cout<<" =====>";

             do{
                 	op1=getch();
                  opt1=op1;
                  if(opt1==13)
             {
             switch(pos)
				 cust.book_tour();clrscr();
             customer();
             break;
             }

             else if(opt1==27)
             menu();

             else if(opt1==0)
             break;

             else if (!((opt1==0)||(opt1==13)||(opt1==27)))
             {
             gotoxy(39,35);cout<<"!!!   WRONG OPTION   !!!";
             }
             }while(!((opt1==0)||(opt1==13)||(opt1==27)));

             break;

   case 2:  gotoxy(31,18);cout<<" =====>";

             do{
                 	op1=getch();
                  opt1=op1;
                  if(opt1==13)
             {
               file.open("TRAVEL_BOOKINGS.dat",ios::binary|ios::app);
    				trvl.book_TRAVELS();
               file.write((char*)&trvl,sizeof(trvl));
               file.close();
    	         clrscr();customer();break;
             }
				 else if(opt1==27)
             menu();

             else if(opt1==0)
             break;

             else if (!((opt1==0)||(opt1==13)||(opt1==27)))
             {
             gotoxy(39,35);cout<<"!!!   WRONG OPTION   !!!";
             }
             }while(!((opt1==0)||(opt1==13)||(opt1==27)));

             break;

   case 3:  gotoxy(31,20);cout<<" =====>";

				 do{
                 	op1=getch();
                  opt1=op1;
                  if(opt1==13)
             {
               cust.cancel_tour();
               clrscr();
               customer();
               break;
             }
             else if(opt1==27)
             menu();

             else if(opt1==0)
             break;

             else if (!((opt1==0)||(opt1==13)||(opt1==27)))
             {
				 gotoxy(39,35);cout<<"!!!   WRONG OPTION   !!!";
             }
             }while(!((opt1==0)||(opt1==13)||(opt1==27)));

             break;

   case 4:  gotoxy(31,22);cout<<" =====>";

             do{
                 	op1=getch();
                  opt1=op1;
                  if(opt1==13)
             {
               trvl.cancel_travel();
    				customer(); break;
             }

             else if(opt1==27)
             menu();

             else if(opt1==0)
             break;

             else if (!((opt1==0)||(opt1==13)||(opt1==27)))
             {
             gotoxy(39,35);cout<<"!!!   WRONG OPTION   !!!";
             }
             }while(!((opt1==0)||(opt1==13)||(opt1==27)));

             break;

   case 5:   gotoxy(31,24);cout<<" =====>";

   				do{
                 	op1=getch();
                  opt1=op1;
                  if(opt1==13);
             else if(opt1==27)
             menu();

             else if(opt1==0)
             break;

             else if (!((opt1==0)||(opt1==13)||(opt1==27)))
             {
             gotoxy(39,35);cout<<"!!!   WRONG OPTION   !!!";
             }
             }while(!((opt1==0)||(opt1==13)||(opt1==27)));

             break;

   default : gotoxy(39,35);cout<<"!!!   WRONG OPTION   !!!";
      };

   }while(1);

 }

 else if(opt1==27)
   menu();

	else
   {

   gotoxy(39,35);
   cout<<"!!!   WRONG OPTION   !!!";
   customer();
   }
}

int TRAVELS::give_id(TRAVELS trvl)
{

int rtn;
fstream file;

file.open("TRAVEL_BOOKINGS.dat",ios::binary|ios::in);
if(!file) return 1;

while(!file.eof())
	{file.read((char*)&trvl,sizeof(TRAVELS));}
   rtn=(trvl.travel_id+1);
   file.close();

   return rtn;

}

int admin_tour::give_id(admin_tour adm)
{
int rtn;
fstream file;

file.open("TOUR_PACKAGES.dat",ios::binary|ios::in);
if(!file) return 1;

while(!file.eof())
	{file.read((char*)&adm,sizeof(admin_tour));}
   rtn=(adm.tour_no+1);
   file.close();

   return rtn;
}

int cust_tour::give_id(cust_tour cust)
{
int rtn;
fstream file;

file.open("TOUR_BOOKINGS.dat",ios::binary|ios::in);
if(!file) return 1;

while(!file.eof())
	{file.read((char*)&cust,sizeof(cust_tour));}
   rtn=(cust.tour_no+1);
   file.close();
   return rtn;

}

void printing()
 {
      gotoxy(15,7);
     for(i=0;i<48;i++)putch(254);
      gotoxy(15,13);
     for(i=0;i<48;i++)putch(254);
   	gotoxy(33,9); puts("! ! PRINTING  ! !");
      gotoxy(33,11);
      for(i=0;i<7;i++)
		{ 	putch(240); //Sleep(1);
		}

		gotoxy(31,17); puts("! !  PRINTED   ! !");
      getch();
  }

 int empty_file_remove(char file[],int check)
 {
    if(check==1)
    	remove(file);
 }


  void pass()
{
clrscr();

   output_box_date_n_time();

	char tmp[10];
   textcolor(10);
	gotoxy(38,18);
	cputs("!!  ENTER THE PASSWORD  !!");
   textcolor(15);
	gotoxy(47,24);
	for(i=0;i<10;i++)
	{

	  tmp[i]=getch();
	  cputs("*");

	  if(tmp[i]==13 )
		{
		tmp[i]='\0';
		break;
		}
	 }
	gotoxy(38,29);
	if(!strcmp(tmp,passwrd))
		{
      textcolor(12);
		cputs("!!   PASSWORD CORRECT   !! ");
		getch();

		clrscr();
		admin();
      }
	else
		{
      textcolor(12);
		cputs(" !!   PASSWORD WRONG   !! ");
		gotoxy(39,32);
		cputs("   * *   TRY AGAIN  * *");
      textcolor(15);
      gotoxy(30,36);
      cputs("     **  ( Press Escape To Go Back )  **");
      gotoxy(30,39);
		cputs(" ** ( Press Any Other Key To Try Again  ) **");

		char tmp=getch();
      if(tmp==27)
      	{
         clrscr();
          menu();
         }
		clrscr();
      pass();
		}
 }
   void main()
  {
    intro();
    menu();
}

void intro()
{
    textcolor(15);
    gotoxy(13,7);
	 for(i=0;i<79;i++) putch(177);
    gotoxy(13,19);
	 for(i=0;i<79;i++) putch(177);
    for(i=8;i<20;i++)
	{	gotoxy(13,i); putch(177); gotoxy(91,i); putch(177); }


    textcolor(12);
	 gotoxy(22,11);cputs("#     #    ####    #         ###      ##      #     #    #### ");
	 gotoxy(22,12);cputs("#     #    #       #       #        #    #    # # # #    #    ");
	 gotoxy(22,13);cputs("#  #  #    ####    #       #        #    #    #  #  #    #### ");
	 gotoxy(22,14);cputs("# # # #    #       #       #        #    #    #     #    #    ");
	 gotoxy(22,15);cputs("#     #    ####    #####     ###      ##      #     #    #### ");

     textcolor(15);
     gotoxy(12,23);
	  for(i=0;i<81;i++) putch(177);
     gotoxy(12,35);
	  for(i=0;i<81;i++) putch(177);
     for(i=23;i<35;i++)
	 { 	gotoxy(12,i); putch(177); gotoxy(92,i); putch(177); }

     textcolor(10);
	  gotoxy(37,28);cputs("THE STAR TRAVELS AND TOURISM  ");
	  gotoxy(41,30);cputs("MADE BY -  M. VIGNESH ");


    getch(); clrscr();

}

void menu()
{
clrscr();
	char op1,op2;
   output_box_date_n_time(0);

   textcolor(14);
   gotoxy(35,7);
	cputs(" !!  PLEASE SELECT YOUR ACCOUNT !!");
       textcolor(10);
		 gotoxy(42,19);
   	cputs("<>   ADMINISTRATOR");
		 gotoxy(42,24);
		cputs("<>   CUSTOMER");

      textcolor(15);
	gotoxy(26,40);
   cputs("(  USE UP AND DOWN ARROW TO SELECT AND PRESS ENTER  )");

   	textcolor(15);
      int opt1,opt2;
      gotoxy(31,19);
      cputs("======>");
      gotoxy(64,19);
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
         			gotoxy(31,19); cputs("======>");
         	      gotoxy(31,24); cputs("       ");
                  gotoxy(64,19); cputs("<======");
                  gotoxy(64,24); cputs("       ");

                 	op1=getch();
                  opt1=op1;
                  if(opt1==13)
                  	pass();
                else if(opt1==0)
                  	break;
                else if(!((opt1==0)||(opt1==13)))
                {
                textcolor(15);
                gotoxy(38,36);cputs("!!!  WRONG OPTION   !!!");
  				}

            }while(!((opt1==0)||(opt1==13)));
            		break;
         case 80 : do
         			{
         			gotoxy(31,19); cputs("       ");
                  gotoxy(31,24); cputs("======>");
                  gotoxy(64,19); cputs("       ");
                 	gotoxy(64,24); cputs("<======");

                   op1=getch();
                   opt1=op1;

                   if(opt1==13)
                  	customer();

                  else if(opt1==0)
								break;

                  else if(!((opt1==0)||(opt1==13)))
                {
                textcolor(15);
            	gotoxy(38,36);cputs("!!!  WRONG OPTION   !!!");
   }

            }while(!((opt1==0)||(opt1==13)));
            break;

  		default: textcolor(15);
      			gotoxy(38,36);cputs("!!!  WRONG OPTION   !!!");
      };

}while(1);

}
  else {
  textcolor(15);
  gotoxy(38,36);cputs("!!!  WRONG OPTION   !!!");
   menu();
      }
}
