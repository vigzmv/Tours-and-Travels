#include<fstream.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<dos.h>
#include<windows.h>
#include"Specials.cpp"

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
void empty_file_remove(char file[],int check);
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





void target_up_down(int keystroke, int &position)
{
     gotoxy(43,20);cout<<"       ";
     gotoxy(43,22);cout<<"       ";
     gotoxy(43,24);cout<<"       ";
	  gotoxy(43,26);cout<<"       ";
     gotoxy(43,28);cout<<"       ";
     gotoxy(43,30);cout<<"       ";

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
  show_error();
       }
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

textcolor(5);
gotoxy(42,4); cputs("---|        TOURS AND TRAVELS SYSTEM        |---");
gotoxy(61,7);  //title goes here...

textcolor(4);
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
            int give_id(TRAVELS trvl);

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

   gotoxy(55,7);cout<<"* * BOOK MY TRAVEL  ";

   gotoxy(45,16);cout<<"*  PLEASE ENTER THE FOLLOWING DETAILS  *\n";

   gotoxy(42,22);cout<<"PLEASE ENTER YOUR NAME              :     ";
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
   travel_id=give_id(trvl);

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
   			int tour_no,tariff;
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
          void view_tour();
   		 void view_tour(int chk);
				int give_id(admin_tour adm);
            void entry();
   			void remove_tour();
            void modify_tour();
};

		void admin_tour::entry()
   {
   clrscr();

	output_box_date_n_time();
   admin_tour adm;

   gotoxy(56,7);cout<<"* *  TOUR ENRTY  * *";
   gotoxy(45,16);cout<<"PLEASE ENTER TOUR PACKAGE DETAILS ";
   gotoxy(42,22);cout<<"ENTER TOUR NAME                 :        ";
   gets(tourname);
   gotoxy(42,24);cout<<"ENTER TOUR CITY                 :        ";
   gets(city);
   gotoxy(42,26);cout<<"ENTER TOUR PLACES               :        ";
   gets(place);
   gotoxy(42,28);cout<<"ENTER TOUR DETAILS              :        ";
   gets(details);
   gotoxy(42,30);cout<<"ENTER TOUR DAYS                 :        ";
   gets(day);
   gotoxy(42,32);cout<<"ENTER TOUR FARE PER PERSON      :        ";
	cin>>tariff;
   tour_no=give_id(adm);

   gotoxy(48,41);cout<<"!!   ENTRY  IS  SUCCESSFUL  !!";
   gotoxy(48,43);cout<<"        TOUR NO IS    :   "<<tour_no;
   getch();
}


    void admin_tour::view_tour()
  {
   clrscr();

   admin_tour adm;
   int j=0;
   fstream fin;

   output_box_date_n_time(1);

	gotoxy(54,7);cout<<"* * TOUR PACKAGES * *";
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
   while(1)
   {
    fin.read((char*)&adm,sizeof(admin_tour));

   if(fin.eof()) break;


   gotoxy(40,((j*20)+12));cout<<"TOUR No.                    :        ";cout<<adm.tour_no;
   gotoxy(40,((j*20)+15));cout<<"TOUR NAME                   :        ";puts(adm.tourname);
   gotoxy(40,((j*20)+16));cout<<"TOUR CITY                   :        ";puts(adm.city);
	gotoxy(40,((j*20)+18));cout<<"PLACES                      :        ";puts(adm.place);
   gotoxy(40,((j*20)+19));cout<<"DETAILS                     :        ";puts(adm.details);
   gotoxy(40,((j*20)+20));cout<<"TOUR DAYS                   :        ";puts(adm.day);
   gotoxy(40,((j*20)+21));cout<<"TOUR TICKET PER PERSON      :        Rs. "<<adm.tariff;

   gotoxy(39,((j*20)+23));cout<<" ONLY R.: """;
   No_coverter_caller(adm.tariff);cout<<" """;

   gotoxy(10,((j*20)+26));for(int i=0;i<112;i++) putch(205);

   j++;

   }

    getch();clrscr();
    fin.close();
  }

  void admin_tour::view_tour(int j)
  {

   gotoxy(40,((j*16)+25));cout<<"TOUR No.                    :        ";cout<<tour_no;
   gotoxy(40,((j*16)+28));cout<<"TOUR NAME                   :        ";puts(tourname);
   gotoxy(40,((j*16)+29));cout<<"TOUR CITY                   :        ";puts(city);
	gotoxy(40,((j*16)+30));cout<<"PLACES                      :        ";puts(place);
   gotoxy(40,((j*16)+33));cout<<"DETAILS                     :        ";puts(details);
   gotoxy(40,((j*16)+33));cout<<"TOUR DAYS                   :        ";puts(day);
   gotoxy(40,((j*16)+34));cout<<"TOUR TICKET PER PERSON      :        Rs. "<<tariff;

   gotoxy(39,((j*16)+36));cout<<" ONLY Rs :  ";
   No_coverter_caller(tariff);cout<<" ";

   gotoxy(10,((j*16)+38));for(int i=0;i<112;i++) putch(205);

   }

    void admin_tour::modify_tour()
	{
     clrscr();
    output_box_date_n_time(1);
    gotoxy(55,7);cout<<"* *  MODIFY TOUR  * *";

    admin_tour adm;
    int mod; char ans;
    fstream file;
    file.open("TOUR_PACKAGES.dat",ios::binary|ios::in);
    if(!file)
             {
             clrscr();
             output_box_date_n_time(0);
             gotoxy(55,28);
             cout<<"!!  NO TOUR PACKAGES !!";
             getch();
             admin();
             }
    file.close();

    file.open("TOUR_PACKAGES.dat",ios::binary|ios::in|ios::out);

    gotoxy(50,16);cout<<"PLEASE SELECT THE PACKAGE  : ";
    int j=0;
    gotoxy(10,19);for(int i=0;i<112;i++) putch(205);
    while(1)
            {
            file.read((char*)&adm,sizeof(admin_tour));
            if(file.eof()) break;

    			adm.view_tour(j);
            j++;
            }

    gotoxy(83,16);
    cin>>mod;

    file.clear();
    file.seekg(0,ios::beg);
    
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

       opt1=getch();
       op1=opt1;

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

                        do
                        {
                        show_blanks_in_modify_tour();

                        if(y==45)
                        	{
                           gotoxy(38,47);cout<<"====>";
                           }
                        else{
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
                           cin>>ans;
                           if((ans=='N')||(ans!='n'))
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
								break;
            case 80 :   if(y==45) y=27;
            				else y+=3;


                        do
                        {
                        show_blanks_in_modify_tour();

								if(y==45)
                        	{
                           gotoxy(38,47);cout<<"====>";
                           }
                        else{
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
                           cin>>ans;
                           if((ans=='n')||(ans=='n'))
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

                        break;
         };

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

   file.seekg(pos1);

   file.write((char*)&adm,sizeof(admin_tour));


  		if(!found)
  {

   show_error();
   getch();
   modify_tour();
  }

  }

   void admin_tour::remove_tour()
	{
    clrscr();

    output_box_date_n_time(1);
    gotoxy(56,7);cout<<"* *  REMOVE TOUR  * *";

    admin_tour adm;
    int rm;
    int datacount=0;
    fstream oldf,newf;

    gotoxy(50,17);cout<<"PLEASE SELECT THE PACKAGE  : ";
    oldf.open("TOUR_PACKAGES.dat",ios::binary|ios::in);
    if(!oldf)
             {
             clrscr();
             output_box_date_n_time(0);
             gotoxy(55,28);
             cout<<"!!  NO TOUR PACKAGES !!";
             getch();
             admin();
             }

    newf.open("temp.dat",ios::binary|ios::out);
            int j=0;

           while(1)
            {
            oldf.read((char*)&adm,sizeof(admin_tour));
            if(oldf.eof()) break;

    			adm.view_tour(j);
            j++;
            datacount++;
            }

    gotoxy(80,17);
    cin>>rm;

    char ans; oldf.close();

    clrscr();
    output_box_date_n_time(0);

	 oldf.open("TOUR_PACKAGES.dat",ios::binary|ios::in);
    oldf.read((char*)&adm,sizeof(admin_tour));
 int found=0;
 do
  {
  if(rm==adm.tour_no)
  {
   found++;
   gotoxy(40,20);cout<<"ARE YOU SURE YOU WANT TO REMOVE THIS PACKAGE (Y/N)? ";
    cin>>ans;

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

   if(!found)
  {

  	datacount=0;
   show_error();
   getch();
   remove_tour();
  }
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
gotoxy(30,17);cout<<"CUSTOMER NAME             :";gotoxy(65,17);puts(cust_name);
gotoxy(30,18);cout<<"CUSTOMER PHONE            :";gotoxy(65,18);cout<<cust_phone;
gotoxy(30,19);cout<<"CUSTOMER EMAIL            :";gotoxy(65,19);puts(cust_email);
gotoxy(17,21);for(i=0;i<71;i++) putch(220);
gotoxy(31,23);cout<<"TOUR NAME               :";gotoxy(63,23);puts(tourname);
gotoxy(31,24);cout<<"TOUR CITY               :";gotoxy(63,24);puts(city);
gotoxy(31,26);cout<<"DATE OF JOURNEY         :";gotoxy(63,26);cout<<cDay.dd<<" / "<<cDay.mm<<" / "<<"2013";
gotoxy(31,28);cout<<"No. OF PERSONS          :";gotoxy(63,28);cout<<no_seats;
gotoxy(17,30);for(i=0;i<71;i++) putch(220);
gotoxy(39,32);for(i=0;i<30;i++) putch(224);
gotoxy(39,33);putch(224);putch(224);cout<<"     TOTAL AMOUNT :       ";putch(224);putch(224);
gotoxy(39,35);putch(224);putch(224);cout<<"      Rs. "<<totamount; gotoxy(67,33); putch(224);putch(224);
gotoxy(39,36);for(i=0;i<30;i++) putch(224);
gotoxy(24,38);cout<<"Rs. : ";No_coverter_caller(totamount);cout<<" ONLY ";
gotoxy(17,39);for(i=0;i<71;i++) putch(220);

getch();

}

void cust_tour::view_book()
{
end end end
cout<<"\t     CUSTOMER NAME            :             ";puts(cust_name);end end
cout<<"\t     CUSTOMER EMAIL           :             ";puts(cust_email);end
cout<<"\t     CUSTOMER PHONE           :             "<<cust_phone;end end
cout<<"\t     TOUR NAME                :             ";puts(tourname);end
cout<<"\t     TOUR DATE                :             ";cout<<cDay.dd<<" / "<<cDay.mm<<" / "<<"2013";end
cout<<"\t     No. OF TICKESTS          :             ";cout<<no_seats;end end
cout<<"\t     TOTAL AMOUNT             :             Rs. "<<totamount; end
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
         gotoxy(40,14);cout<<" ENTER YOUR NAME     :     ";
         gets(cust.cust_name);
         gotoxy(40,16);cout<<" ENTER YOUR EMAIL    :     ";
         gets(cust.cust_email);
         gotoxy(40,18);cout<<" ENTER YOUR PHONE    :     ";
         cin>>cust_phone;
         gotoxy(40,21);cout<<" PLEASE SELCET TOUR PACKAGE  :  ";

         gotoxy(10,23);for(int i=0;i<112;i++) putch(205);
         int j=0;

         while(1)
         {
         temp.read((char*)&adm,sizeof(admin_tour));

         if(temp.eof()) break;

         adm.view_tour(j);
         j++;
			}

         int tm;
         gotoxy(74,21);cin>>tm;

         clrscr();
         output_box_date_n_time();

         gotoxy(45,7);cout<<"** BOOK TOUR **";

         gotoxy(37,14);cout<<"PLEASE ENTER DATE OF JOURNEY";
         gotoxy(35,17);cout<<"ENTER MONTH (In Digits.)   :     ";
         cin>>cust.cDay.mm;
         gotoxy(35,19);cout<<"ENTER DATE                 :     ";
         cin>>cust.cDay.dd;
         gotoxy(32,23);cout<<"PLEASE ENTER NO. OF TICKEST REQUIRED  :  ";
         cin>>cust.no_seats;

         temp.close();

         cust.tour_no=cust.give_id(c);
         fstream temp2;
         temp2.open("TOUR_BOOKINGS.dat",ios::binary|ios::app);
         fstream t;
         t.open("TOUR_PACKAGES.dat",ios::binary|ios::in);
            int found=0;
            while(1)
            {
            t.read((char*)&adm,sizeof(admin_tour));

             if(t.eof()) break;

        		if(tm==adm.tour_no)
          { found++;
            strcpy(cust.tourname,adm.tourname);
            strcpy(cust.place,adm.place);
            strcpy(cust.details,adm.details);
				strcpy(cust.day,adm.day);
            strcpy(cust.city,adm.city);
				cust.totamount=cust.no_seats*adm.tariff;

            temp2.write((char*)&cust,sizeof(cust_tour));
          }
			}
          if(!found)
		{

   		show_error();
   		getch();
   		book_tour();
      }

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

   gotoxy(48,7);cout<<"  * *   ADMINISTRATOR  MENU   * *";
   gotoxy(54,20);cout<<"<>  View Tour Bookings ";
   gotoxy(54,22);cout<<"<>  View Travels Bookings ";
   gotoxy(54,24);cout<<"<>  Create Tour Packages";
   gotoxy(54,26);cout<<"<>  View Tour Packages ";
   gotoxy(54,28);cout<<"<>  Delete Tour Packages ";
   gotoxy(54,30);cout<<"<>  Change Password ";

   gotoxy(48,45);cout<<"( * * PRESS Esc TO GO BACK * * )";
   gotoxy(39,48);cout<<"( USE UP AND DOWN ARROW TO SELECT AND PRESS ENTER )";

	fstream fout;
   fstream fin;

   char op1,op2;
   int opt1,opt2,pos=1;

   gotoxy(43,20);cout<<" =====>";
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
				gotoxy(43,20);cout<<" =====>";

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
             else if(opt1==27)
             menu();
             else if(opt1==0)
             break;
             else if (!((opt1==0)||(opt1==13)||(opt1==27)))
             {
             show_error();
   }
             }while(!((opt1==0)||(opt1==13)||(opt1==27)));
             break;

    case 2 :   do
    				{

               gotoxy(43,22);cout<<" =====>";

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
             show_error();
   }
             }while(!((opt1==0)||(opt1==13)||(opt1==27)));
             break;

    case 3:  do
           {
           gotoxy(43,24);cout<<" =====>";

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
             show_error();
   }
            }while(!((opt1==0)||(opt1==13)||(opt1==27)));
             break;

    case  4: do
    			{
            		gotoxy(43,26);cout<<" =====>";

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
             show_error();
             }
             }while(!((opt1==0)||(opt1==13)||(opt1==27)));

             break;
    case 5 : do
    			{
            	gotoxy(43,28);cout<<" =====>";

               op1=getch();
                  opt1=op1;
                  if(opt1==13)
            {
            adm.modify_tour();
            admin();
            }

             else if(opt1==27)
             menu();

             else if(opt1==0)
             break;

             else if (!((opt1==0)||(opt1==13)||(opt1==27)))
				 {
             show_error();
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
	show_error();
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

   output_box_date_n_time(0);

   char op1,op2;

   gotoxy(55,7);cout<<"* *   CUSTOMER  MENU   * *";
   gotoxy(54,20);cout<<"<>  BOOK MY TOUR";
   gotoxy(54,22);cout<<"<>  BOOK MY TRAVELS ";
   gotoxy(54,24);cout<<"<>  CANCEL TOUR BOOKINGS ";
   gotoxy(54,26);cout<<"<>  CANCEL TRAVEL BOOKINGS ";
   gotoxy(54,28);cout<<"<>  OFFER OF THE DAY !!";


   gotoxy(48,45);cout<<"( * * PRESS Esc TO GO BACK * * )";
   gotoxy(39,48);cout<<"( USE UP AND DOWN ARROW TO SELECT AND PRESS ENTER )";

   fstream f;
   int opt1,opt2,pos=1;

   gotoxy(43,20);cout<<" =====>";

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

   case 1:   gotoxy(43,20);cout<<" =====>";

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
             show_error();
             }
             }while(!((opt1==0)||(opt1==13)||(opt1==27)));

             break;

   case 2:  gotoxy(43,22);cout<<" =====>";

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
             show_error();
             }
             }while(!((opt1==0)||(opt1==13)||(opt1==27)));

             break;

   case 3:  gotoxy(43,24);cout<<" =====>";

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
				 show_error();
             }
             }while(!((opt1==0)||(opt1==13)||(opt1==27)));

             break;

   case 4:  gotoxy(43,26);cout<<" =====>";

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
             show_error();
             }
             }while(!((opt1==0)||(opt1==13)||(opt1==27)));

             break;

   case 5:   gotoxy(43,28);cout<<" =====>";

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
             show_error();
             }
             }while(!((opt1==0)||(opt1==13)||(opt1==27)));

             break;

   default : show_error();
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
	{
   file.read((char*)&trvl,sizeof(TRAVELS));
   }
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
	{
   file.read((char*)&adm,sizeof(admin_tour));
   }
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
	{
   file.read((char*)&cust,sizeof(cust_tour));
   }
   rtn=(cust.tour_no+1);
   file.close();
   return rtn;

}

 void empty_file_remove(char file[],int check)
 {
    if(check==1)
    	remove(file);
 }


  void pass()
{
clrscr();
   admin();
	int attempts=3;

   do{

   output_box_date_n_time();

	char tmp[4];
   textcolor(6);

   gotoxy(40,17);cout<"                                  ";
   gotoxy(50,20);
	cputs("  AUTHENTICATION REQUIRED   ");cputs("( ");cout<<attempts;cputs(" )");
   attempts-=1;;
   lock(0);
   textcolor(15);
   gotoxy(42,46);
   cputs("     **  ( Press Escape To Go Back )  **");
   textcolor(8);
   gotoxy(63,23);
	cout<<"         ";
	gotoxy(63,23);

	for(i=0;i<5;i++)
	{

	  tmp[i]=getch();
	  cputs("*");

     if(tmp[i]==27 )
      {
     	menu();
      }

	  if(tmp[i]==13 )
		{
		tmp[i]='\0';
		break;
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
    intro();
    menu();
  }

void intro()
{
    textcolor(15);
    gotoxy(23,7);
	 for(i=0;i<84;i++) putch(177);
    gotoxy(23,21);
	 for(i=0;i<84;i++) putch(177);
    for(i=8;i<22;i++)
	{	gotoxy(23,i); putch(177); gotoxy(106,i); putch(177); }


    textcolor(12);
	 gotoxy(34,12);cputs("#     #    ####    #         ###      ##      #     #    #### ");
	 gotoxy(34,13);cputs("#     #    #       #       #        #    #    # # # #    #    ");
	 gotoxy(34,14);cputs("#  #  #    ####    #       #        #    #    #  #  #    #### ");
	 gotoxy(34,15);cputs("# # # #    #       #       #        #    #    #     #    #    ");
	 gotoxy(34,16);cputs("#     #    ####    #####     ###      ##      #     #    #### ");

     textcolor(15);
     gotoxy(23,26);
	  for(i=0;i<84;i++) putch(177);
     gotoxy(23,38);
	  for(i=0;i<84;i++) putch(177);
     for(i=26;i<38;i++)
	 { 	gotoxy(23,i); putch(177); gotoxy(106,i); putch(177); }

     textcolor(10);
	  gotoxy(50,30);cputs("THE STAR TRAVELS AND TOURISM  ");
	  gotoxy(54,33);cputs("MADE BY -  M. VIGNESH ");


    getch(); clrscr();

}

void menu()
{
clrscr();
	char op1,op2;
   output_box_date_n_time(0);

   textcolor(2);
   gotoxy(48,7);
	cputs("!!    PLEASE SELECT YOUR ACCOUNT   !!");
       textcolor(6);
		 gotoxy(55,23);
   	cputs("<>   Administrator");
		 gotoxy(55,29);
		cputs("<>   Customer");

      textcolor(8);
	gotoxy(38,46);
   cputs("(  Use Up And Down Arrow To Select And Press Enter  )");

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
  else {
  textcolor(15);
  gotoxy(52,42);cputs("!!!  WRONG OPTION   !!!");
   menu();
      }

      }
