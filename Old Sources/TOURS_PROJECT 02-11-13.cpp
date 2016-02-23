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
     gotoxy(32,16);cout<<"       ";
     gotoxy(32,18);cout<<"       ";
     gotoxy(32,20);cout<<"       ";
	  gotoxy(32,22);cout<<"       ";
     gotoxy(32,24);cout<<"       ";
     gotoxy(32,26);cout<<"       ";

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
  gotoxy(28,30);cout<<"!!!   WRONG OPTION   !!!";
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
gotoxy(41,4); cputs(" TOURS AND TRAVELS SYSTEM ");
gotoxy(51,5);  //title

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


	class travels
{
	public : char mode_travel[20];
   			char cust_name[20],from[20],dest[20];
            int amount,no_tickets;
				int cust_phone,travel_id;
            tdate cDay;

            struct time btime;
            struct date bdate;

            void view_travels();
            void view_city();
   			void book_travels();
            void view_book();
            void view_book(int check);
            void cancel_travel();
            int give_id(travels trvl);

				travels()
            {
					cDay.yy=2013;
            }

};

	  void travels::book_travels()
{
   travels trvl;
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


      void travels::view_book(int check)

   {	end for(i=1;i<29;i++){ gotoxy(7,i);putch(177); }
          for(i=1;i<29;i++){ gotoxy(75,i);putch(186); }

gotoxy(7,1);for(i=0;i<69;i++) putch(205);
gotoxy(35,2);cout<<"TRIP TICKET";
gotoxy(7,3);for(i=0;i<69;i++) putch(205);
gotoxy(18,5);cout<<"CUSTOMER NAME             -";gotoxy(52,5);puts(cust_name);
gotoxy(18,6);cout<<"CUSTOMER PHONE            -";gotoxy(52,6);cout<<(cust_phone);
gotoxy(18,7);cout<<"CUSTOMER EMAIL            -";gotoxy(52,7);puts(cust_name);
gotoxy(18,8);cout<<"DATE OF BOOKING           -";gotoxy(52,8);cout<<cDay.dd<<" / "<<cDay.mm<<" / "<<"2013";
gotoxy(7,10);for(i=0;i<69;i++) putch(205);
gotoxy(17,13);cout<<"BOARDING FROM           -";gotoxy(51,13);puts(from);
gotoxy(17,14);cout<<"DESTINATION             -";gotoxy(51,14);puts(dest);
gotoxy(17,16);cout<<"DATE OF JOURNEY         -";gotoxy(51,16);cout<<cDay.dd<<" / "<<cDay.mm<<" / "<<"2013";
gotoxy(17,17);cout<<"MODE OF TRAVEL          -";gotoxy(51,17);puts(mode_travel);
gotoxy(17,18);cout<<"No. OF PERSONS          -";gotoxy(51,18);cout<<no_tickets;
gotoxy(7,20);for(i=0;i<69;i++) putch(205);
gotoxy(29,22);for(i=0;i<28;i++) putch(224);
gotoxy(29,23);putch(224);putch(224);cout<<"     TOTAL AMOUNT :    ";putch(224);putch(224);
gotoxy(29,24);putch(224);putch(224);cout<<"      Rs. "<<amount;
gotoxy(29,25);for(i=0;i<28;i++) putch(224);end
gotoxy(14,27);cout<<"Rs. - ";No_coverter_caller(amount);cout<<" ONLY ";
gotoxy(7,29);for(i=0;i<69;i++) putch(205);
getch();
}


      void travels::view_book()
{
    travels trvl;

    gotoxy(7,1);for(i=0;i<69;i++) putch(205);
    gotoxy(33,2);cout<<"TRAVEL BOOKINGS ";
    gotoxy(7,3);for(i=0;i<69;i++) putch(205);

    fstream fin;
    fin.open("TRAVEL_BOOKINGS.dat",ios::binary|ios::in);
	 if(!fin)
             {
             clrscr();
             output_box_date_n_time(0);
             gotoxy(32,16);
             cout<<" NO BOOKINGS ";
             }

    fin.read((char*)&trvl,sizeof(travels));
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

    fin.read((char*)&trvl,sizeof(travels));

   }while(!fin.eof());

    getch();
}

    void travels::cancel_travel()
{
	clrscr();
	 travels trvl;
    int id;

    fstream oldf,newf;
    oldf.open("TRAVEL_BOOKINGS.dat",ios::binary|ios::in);
    if(!oldf)
    {
             clrscr();
             output_box_date_n_time(0);
             gotoxy(32,16);
             cout<<" NO BOOKINGS ";
    }

    gotoxy(22,2);cout<<"PLEASE ENTER YOU BOOKING ID ";
	 newf.open("temp.dat",ios::binary|ios::out);
    gotoxy(57,2);cin>>id;

    oldf.read((char*)&trvl,sizeof(travels));
    do
    {
     if(id==trvl.travel_id)
     	trvl.view_book(0);

    oldf.read((char*)&trvl,sizeof(travels));

    }while(!oldf.eof());

    oldf.close();

    line end end end

    char ans;

    oldf.open("TRAVEL_BOOKINGS.dat",ios::binary|ios::in);
    oldf.read((char*)&trvl,sizeof(travels));
 do
  {
   if(id==trvl.travel_id)
 {      cout<<"     ARE YOU SURE YOU WANT TO CANCEL THIS BOOKING ? (Y/N) \n";

    ans=getch();
    	if((ans=='Y')||(ans=='y'))
    	{ cout<<"\n\n\n\n\n                 ! !    BOOKING CANCELED    ! !";
      oldf.read((char*)&trvl,sizeof(travels)); continue; }

  		else cout<<"\n\n\n\n\n            !  !  BOOKING NOT CANCELLED  ! !\n";

  }
       	newf.write((char*)&trvl,sizeof(travels));
         oldf.read((char*)&trvl,sizeof(travels));

  }while(!oldf.eof());

   getch();
   newf.close();
   oldf.close();

   remove("TRAVEL_BOOKINGS.dat");
   rename("temp.dat","TRAVEL_BOOKINGS.dat");
 }




		void travels::view_city()
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

   gotoxy(29,4);cout<<"** TOUR ENRTY **";
   gotoxy(22,9);cout<<"PLEASE ENTER TOUR PACKAGE DETAILS ";
   gotoxy(15,13);cout<<"ENTER TOUR NAME                -      ";
   gets(tourname);
   gotoxy(15,15);cout<<"ENTER TOUR CITY                -      ";
   gets(city);
   gotoxy(15,17);cout<<"ENTER TOUR PLACES              -      ";
   gets(place);
   gotoxy(15,19);cout<<"ENTER TOUR DETAILS             -      ";
   gets(details);
   gotoxy(15,21);cout<<"ENTER TOUR DAYS                -      ";
   gets(day);
   gotoxy(15,23);cout<<"ENTER TOUR FARE PER PERSON     -      ";
	cin>>tariff;

   tour_no=give_id(adm);
}


    void admin_tour::view_tour()
  {
   clrscr();

   admin_tour adm;
   int j=0;
   fstream fin;

   output_box_date_n_time(1);

	gotoxy(26,4);cout<<"** TOUR PACKAGES **";
   fin.open("tour.dat",ios::binary|ios::in);
   if(!fin)
             {
             clrscr();
             output_box_date_n_time(0);
             gotoxy(30,16);
             cout<<" NO TOUR PACKAGES ";
             }
   fin.read((char*)&adm,sizeof(admin_tour));
   do
    {

   gotoxy(17,((j*15)+10));cout<<"TOUR No.                  -       ";cout<<adm.tour_no;
   gotoxy(17,((j*15)+12));cout<<"TOUR NAME                 -       ";puts(adm.tourname);
   gotoxy(17,((j*15)+13));cout<<"TOUR CITY                 -       ";puts(adm.city);
	gotoxy(17,((j*15)+15));cout<<"PLACES                    -       ";puts(adm.place);
   gotoxy(17,((j*15)+16));cout<<"DETAILS                   -       ";puts(adm.details);
   gotoxy(17,((j*15)+18));cout<<"TOUR DAYS                 -       ";puts(adm.day);
   gotoxy(17,((j*15)+19));cout<<"TOUR TICKET PER PERSON    -       Rs. "<<adm.tariff;
   gotoxy(4,((j*15)+22));for(int i=0;i<73;i++) putch(205);

   j++;

   fin.read((char*)&adm,sizeof(admin_tour));

   }while(!fin.eof());

    getch();clrscr();
    fin.close();
  }

  void admin_tour::view_tour(int chk)
  {

   end
   cout<<"\t     TOUR No.                   -       ";cout<<tour_no;end end
   cout<<"\t     TOUR NAME                  -       ";puts(tourname);end
   cout<<"\t     TOUR CITY                  -       ";puts(city);end
   cout<<"\t     PLACES                     -       ";puts(place);end
   cout<<"\t     DETAILS                    -       ";puts(details);end end
   cout<<"\t     TOUR DAYS                  -       ";puts(day);end
   cout<<"\t     TOUR TICKET PER PERSON     -       Rs. "<<tariff;end end
	cout<<"     "; for(int i=0;i<70;i++) putch(205);  end end

  }

   void admin_tour::remove_tour()
	{
    clrscr();

    output_box_date_n_time(1);
    gotoxy(34,4);cout<<" REMOVE TOUR ";

    admin_tour adm;
    int rm;
    fstream oldf,newf;

    gotoxy(28,7);cout<<"PLEASE SELECT THE PACKAGE ";
    oldf.open("tour.dat",ios::binary|ios::in);
    if(!oldf)
             {
             clrscr();
             output_box_date_n_time(0);
				 gotoxy(28,16);
             cout<<" NO TOUR PACKAGES ";
             }

    newf.open("temp.dat",ios::binary|ios::out);
    oldf.read((char*)&adm,sizeof(admin_tour));
            do
            {
    			adm.view_tour(0);
            oldf.read((char*)&adm,sizeof(admin_tour));
            }while(!oldf.eof());
    gotoxy(53,7);cin>>rm;

    clrscr(); end end end
    char ans; oldf.close();

	 oldf.open("tour.dat",ios::binary|ios::in);
    oldf.read((char*)&adm,sizeof(admin_tour));

    output_box_date_n_time(1);

 do
  {
  if(rm==adm.tour_no)
  {
   cout<<"\n\n\t      ARE YOU SURE YOU WANT TO REMOVE THIS PACKAGE (Y/N)? ";
    ans=getch();

    	if((ans=='Y')||(ans=='y'))
    	{
      cout<<"\n\n\n\n\n\\n\\t\t\t! !        DELETED        ! !";
      oldf.read((char*)&adm,sizeof(admin_tour));
		continue;
      }

  		else cout<<"\n\n\n\t\t\t!  !  PACKAGE NOT DELETED ! !\n";

  }
       	newf.write((char*)&adm,sizeof(admin_tour));
         oldf.read((char*)&adm,sizeof(admin_tour));

  }while(!oldf.eof());

   getch();

   newf.close();
   oldf.close();

	remove("tour.dat");
   rename("temp.dat","tour.dat");
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

end for(i=1;i<29;i++){ gotoxy(7,i);putch(177); }
          for(i=1;i<29;i++){ gotoxy(75,i);putch(186); }

gotoxy(7,1);for(i=0;i<69;i++) putch(205);
gotoxy(37,2);cout<<"TRIP TICKET";
gotoxy(7,3);for(i=0;i<69;i++) putch(205);
gotoxy(18,5);cout<<"CUSTOMER NAME             -";gotoxy(52,5);puts(cust_name);
gotoxy(18,6);cout<<"CUSTOMER PHONE            -";gotoxy(52,6);cout<<(cust_phone);
gotoxy(18,7);cout<<"CUSTOMER EMAIL            -";gotoxy(52,7);puts(cust_email);
gotoxy(18,8);cout<<"DATE OF BOOKING           -";gotoxy(52,8);cout<<cDay.dd<<" / "<<cDay.mm<<" / "<<"2013";
gotoxy(7,10);for(i=0;i<69;i++) putch(205);
gotoxy(17,13);cout<<"TOUR NAME               -";gotoxy(51,13);puts(tourname);
gotoxy(17,14);cout<<"TOUR CITY               -";gotoxy(51,14);puts(city);
gotoxy(17,16);cout<<"DATE OF JOURNEY         -";gotoxy(51,16);cout<<cDay.dd<<" / "<<cDay.mm<<" / "<<"2013";
gotoxy(17,18);cout<<"No. OF PERSONS          -";gotoxy(51,18);cout<<no_seats;
gotoxy(7,20);for(i=0;i<69;i++) putch(205);
gotoxy(29,22);for(i=0;i<28;i++) putch(224);
gotoxy(29,23);putch(224);putch(224);cout<<"     TOTAL AMOUNT :    ";putch(224);putch(224);
gotoxy(29,24);putch(224);putch(224);cout<<"      Rs. "<<totamount;
gotoxy(29,25);for(i=0;i<28;i++) putch(224);end
gotoxy(14,27);cout<<"Rs. - ";No_coverter_caller(totamount);cout<<" ONLY ";
gotoxy(7,29);for(i=0;i<69;i++) putch(205);

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
cout<<"\t     TOTAL AMOUNT             -             Rs. "<<totamount; end end end

cout<<"    ";for(int i=0;i<73;i++) putch(205);

}


void cust_tour::book_tour()
	{    clrscr();

         cust_tour cust,c;
         admin_tour adm;

         fstream temp;

         temp.open("tour.dat",ios::binary|ios::in);
         if(!temp)
             {
             clrscr();
             output_box_date_n_time(0);
             gotoxy(32,16);
             cout<<" NO BOOKINGS ";
             }
         output_box_date_n_time(1);
			gotoxy(35,4);;cout<<"** BOOK TOUR **";
         gotoxy(28,10);cout<<" ENTER YOUR NAME - ";
         gets(cust.cust_name);
         gotoxy(28,12);cout<<" ENTER YOUR EMAIL - ";
         gets(cust.cust_email);
         gotoxy(28,14);cout<<" ENTER YOUR PHONE - ";
         cin>>cust_phone;
         gotoxy(25,17);cout<<" PLEASE SELCET TOUR PACKAGE - ";


         temp.read((char*)&adm,sizeof(admin_tour));
         do
         {
         adm.view_tour(0);
         temp.read((char*)&adm,sizeof(admin_tour));

			}while(!temp.eof());

         int tm;
         gotoxy(58,17);cin>>tm;
         clrscr();
         output_box_date_n_time();

         gotoxy(32,4);cout<<"** BOOK TOUR **";

         gotoxy(27,9);cout<<"PLEASE ENTER DATE OF JOURNEY";
         gotoxy(25,13);cout<<"ENTER MONTH (In Digits.)   -     ";
         cin>>cust.cDay.mm;
         gotoxy(25,16);cout<<"ENTER DATE                 -     ";
         cin>>cust.cDay.dd;
         gotoxy(22,21);cout<<"PLEASE ENTER NO. OF TICKEST REQUIRED  -  ";
         cin>>cust.no_seats;

         temp.close();

         cust.tour_no=cust.give_id(c);
         fstream temp2;
         temp2.open("bookings.dat",ios::binary|ios::app);
         fstream t;
         t.open("tour.dat",ios::binary|ios::in);

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

        gotoxy(31,16);cout<<" ! !  BOOKING SUCCESS ! !";
		  getch();clrscr();

        cust.view_book(0);

        getch();

        t.close();temp2.close();
   }

    	void cust_tour::cancel_tour()
   {
    clrscr();

    output_box_date_n_time();
    gotoxy(32,4);cout<<"** CANCEL TRIP ";
    cust_tour cust;

    int id;
    fstream oldf,newf;

    oldf.open("bookings.dat",ios::binary|ios::in);
    if(!oldf)
    {
             clrscr();
             output_box_date_n_time(0);
             gotoxy(32,16);
             cout<<" NO BOOKINGS ";
    }

    gotoxy(22,8);cout<<"PLEASE ENTER YOU BOOKING ID - ";
    cin>>id;

	 newf.open("temp.dat",ios::binary|ios::out);

    oldf.read((char*)&cust,sizeof(cust_tour));
    do
    {
     if(id==cust.tour_no)
     	cust.view_book(0);
    oldf.read((char*)&cust,sizeof(cust_tour));

    }while(!oldf.eof());

    oldf.close();

    end end
    char ans;

	 oldf.open("bookings.dat",ios::binary|ios::in);
    oldf.read((char*)&cust,sizeof(cust_tour));
 do
  {
   if(id==cust.tour_no)
 {      cout<<"\t  ARE YOU SURE YOU WANT TO CANCEL THIS BOOKING ? (Y/N) \n";
    ans=getch();
    	if((ans=='Y')||(ans=='y'))
    	{ cout<<"\n\n\t\t    !  !    BOOKING CANCELED    !  !";
      oldf.read((char*)&cust,sizeof(cust_tour)); continue; }
   else cout<<"\n\n\t\t   !  !  BOOKING NOT CANCELLED   !  !\n";

  }
       	newf.write((char*)&cust,sizeof(cust_tour));
         oldf.read((char*)&cust,sizeof(cust_tour));
  }while(!oldf.eof());

   getch();
   newf.close();
   oldf.close();

   remove("bookings.dat");
   rename("temp.dat","bookings.dat");

 }
   /****************************************************************************************/


void admin()
{
clrscr();

admin_tour adm;
cust_tour cust;
travels trvl;

   output_box_date_n_time(0);

   gotoxy(39,5);cout<<"  * *   ADMINISTRATOR  MENU   * *";
   gotoxy(42,16);cout<<"<> VIEW TOUR BOOKINGS ";
   gotoxy(42,18);cout<<"<> VIEW TRAVEL BOOKINGS ";
   gotoxy(42,20);cout<<"<> CREATE NEW TOUR PACKAGES";
   gotoxy(42,22);cout<<"<> VIEW TOUR PACKAGES ";
   gotoxy(42,24);cout<<"<> DELETE TOUR PACKAGES ";
   gotoxy(42,26);cout<<"<> CHANGE PASSWORD ";
   gotoxy(32,34);cout<<"( USE UP AND DOWN ARROW TO SELECT AND PRESS ENTER )";
   gotoxy(35,37);cout<<"( * * PRESS Esc TO GO BACK * *)";

	fstream fout;
   fstream fin;

   char op1,op2;
   int opt1,opt2,pos=1;

   gotoxy(32,16);cout<<" =====>";
      gotoxy(35,29);
      op1=getch();
      opt1=op1;
      if(opt1==13)
   {
   fin.open("bookings.dat",ios::binary|ios::in);
             if(!fin)
             {
             clrscr();
				 output_box_date_n_time(0);
             gotoxy(32,16);
             cout<<" NO BOOKINGS ";
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
				gotoxy(32,16);cout<<" =====>";

             do{
                 	op1=getch();
                  opt1=op1;
                  if(opt1==13)
             {

             fin.open("bookings.dat",ios::binary|ios::in);

             if(!fin)
             {
             clrscr();
             output_box_date_n_time(0);
             gotoxy(32,16);
             cout<<" NO BOOKINGS ";
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
             gotoxy(38,37);cout<<"!!!   WRONG OPTION   !!!";
   }
             }while(!((opt1==0)||(opt1==13)||(opt1==27)));
             break;

    case 2 :   do
    				{

               gotoxy(32,18);cout<<" =====>";

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
             gotoxy(38,37);cout<<"!!!   WRONG OPTION   !!!";
   }
             }while(!((opt1==0)||(opt1==13)||(opt1==27)));
             break;

    case 3:  do
           {
           gotoxy(32,20);cout<<" =====>";

                 	op1=getch();
                  opt1=op1;
                  if(opt1==13)
            {
				fout.open("tour.dat",ios::binary|ios::app);
				adm.entry();clrscr();
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
             gotoxy(38,37);cout<<"!!!   WRONG OPTION   !!!";
   }
            }while(!((opt1==0)||(opt1==13)||(opt1==27)));
             break;

    case  4: do
    			{
            		gotoxy(32,22);cout<<" =====>";

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
             gotoxy(38,37);cout<<"!!!   WRONG OPTION   !!!";
   }
             }while(!((opt1==0)||(opt1==13)||(opt1==27)));

             break;
    case 5 : do
    			{
            	gotoxy(32,24);cout<<" =====>";

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
             gotoxy(38,37);cout<<"!!!   WRONG OPTION   !!!";
   }
             }while(!((opt1==0)||(opt1==13)||(opt1==27)));

             break;

      };
   }while(1);
 }

   else if(opt1==27)
   menu();

   else
   {
	gotoxy(38,37);cout<<"!!!   WRONG OPTION   !!!";
   admin();
   }
}

/****************************************************************************************/

void customer()
{
clrscr();

cust_tour cust;
travels trvl;
fstream file;

   output_box_date_n_time();

   char op1,op2;

   gotoxy(27,4);cout<<"* *   CUSTOMER  MENU   * *";
   gotoxy(27,11);cout<<"    <> BOOK MY TOUR";
   gotoxy(27,13);cout<<"    <> BOOK MY TRAVELS ";
   gotoxy(27,15);cout<<"    <> CANCEL TOUR BOOKINGS ";
   gotoxy(27,17);cout<<"    <> CANCEL TRAVEL BOOKINGS ";
   gotoxy(27,19);cout<<"    <> OFFER OF THE DAY !!";


   // need one more call for position good !!
   gotoxy(27,22);cout<<"(* * PRESS Esc TO GO BACK * *)";

   fstream f;
   int opt1,opt2,pos=1;

   gotoxy(21,11);cout<<" =====>";

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

   case 1:   gotoxy(21,11);cout<<" =====>";

             do{
                 	op1=getch();
                  opt1=op1;
                  if(opt1==13)
             {
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
             gotoxy(28,30);cout<<"!!!   WRONG OPTION   !!!";
             }
             }while(!((opt1==0)||(opt1==13)||(opt1==27)));

             break;

   case 2:  gotoxy(21,13);cout<<" =====>";

             do{
                 	op1=getch();
                  opt1=op1;
                  if(opt1==13)
             {
               file.open("TRAVEL_BOOKINGS.dat",ios::binary|ios::app);
    				trvl.book_travels();
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
             gotoxy(28,30);cout<<"!!!   WRONG OPTION   !!!";
             }
             }while(!((opt1==0)||(opt1==13)||(opt1==27)));

             break;

   case 3:  gotoxy(21,15);cout<<" =====>";

				 do{
                 	op1=getch();
                  opt1=op1;
                  if(opt1==13)
             {
               cust.cancel_tour();clrscr();
               customer();break;
             }
             else if(opt1==27)
             menu();

             else if(opt1==0)
             break;

             else if (!((opt1==0)||(opt1==13)||(opt1==27)))
             {
				 gotoxy(28,30);cout<<"!!!   WRONG OPTION   !!!";
             }
             }while(!((opt1==0)||(opt1==13)||(opt1==27)));

             break;

   case 4:  gotoxy(21,17);cout<<" =====>";

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
             gotoxy(28,30);cout<<"!!!   WRONG OPTION   !!!";
             }
             }while(!((opt1==0)||(opt1==13)||(opt1==27)));

             break;

   case 5:   gotoxy(21,19);cout<<" =====>";

   				do{
                 	op1=getch();
                  opt1=op1;
                  if(opt1==13)
             {
             }
             else if(opt1==27)
             menu();

             else if(opt1==0)
             break;

             else if (!((opt1==0)||(opt1==13)||(opt1==27)))
             {
             gotoxy(28,30);cout<<"!!!   WRONG OPTION   !!!";
				 }
             }while(!((opt1==0)||(opt1==13)||(opt1==27)));

             break;

   default : gotoxy(28,30);cout<<"!!!   WRONG OPTION   !!!";

      };

   }while(1);

 }

 else if(opt1==27)
   menu();

	else
   {

   gotoxy(28,30);cout<<"!!!   WRONG OPTION   !!!";
   customer();
   }
}

int travels::give_id(travels trvl)
{

int rtn;
fstream file;

file.open("TRAVEL_BOOKINGS.dat",ios::binary|ios::in);
if(!file) return 1;

while(!file.eof())
	{file.read((char*)&trvl,sizeof(travels));}
   rtn=(trvl.travel_id+1);
   file.close();

   return rtn;

}

int admin_tour::give_id(admin_tour adm)
{
int rtn;
fstream file;

file.open("tour.dat",ios::binary|ios::in);
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

file.open("bookings.dat",ios::binary|ios::in);
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

  void pass()
{
clrscr();

   output_box_date_n_time();

	char tmp[10];

	gotoxy(40,18);
	cputs("!!  ENTER THE PASSWORD  !!");

	gotoxy(48,24);
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
	gotoxy(42,29);
	if(!strcmp(tmp,passwrd))
		{
		cputs("!! PASSWORD CORRECT !! ");
		getch();

		clrscr();
		admin();
      }
	else
		{
		cout<<" !! PASSWORD WRONG !! ";
		gotoxy(41,32);
		cout<<"  * *   TRY AGAIN  * *";
      gotoxy(31,35);
      cout<<"     **  ( Press Escape To Go Back )  **";
      gotoxy(31,37);
		cout<<" ** ( Press Any Other Key To Try Again  ) **";

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
   gotoxy(36,6);
	cout<<" !!  PLEASE SELECT YOUR ACCOUNT !!\n\n";
		 gotoxy(42,19);
   	cputs("<>   ADMINISTRATOR");
		 gotoxy(42,24);
		cputs("<>   CUSTOMER");

      textcolor(7);
	gotoxy(27,40);
   cputs("(USE UP AND DOWN ARROW TO SELECT AND PRESS ENTER )");

   	textcolor(7);
      int opt1,opt2;
      gotoxy(32,19); cputs("======>");
      gotoxy(32,24);
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
         			gotoxy(32,19); cputs("======>");
         	      gotoxy(32,24); cputs("       ");

                 	op1=getch();
                  opt1=op1;
                  if(opt1==13)
                  	pass();
                else if(opt1==0)
                  	break;
                else if(!((opt1==0)||(opt1==13)))
                {
                textcolor(opt2+13);
                gotoxy(41,36);cputs("!!!  WRONG OPTION   !!!");
  				}

            }while(!((opt1==0)||(opt1==13)));
            		break;
         case 80 : do
         			{
         			gotoxy(32,19); cputs("       ");
                  gotoxy(32,24); cputs("======>");

                   op1=getch();
                   opt1=op1;

                   if(opt1==13)
                  	customer();

                  else if(opt1==0)
								break;

                  else if(!((opt1==0)||(opt1==13)))
                {
                textcolor(opt2+11);
            	gotoxy(41,36);cputs("!!!  WRONG OPTION   !!!");
   }

            }while(!((opt1==0)||(opt1==13)));

            break;
  		default: textcolor(opt2+9);
      			gotoxy(41,36);cputs("!!!  WRONG OPTION   !!!");
      };

}while(1);

}
  else {
  textcolor(opt2+7);
  gotoxy(41,36);cputs("!!!  WRONG OPTION   !!!");
   menu();
      }

}

