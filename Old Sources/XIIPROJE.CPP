#include<fstream.h>
#include<process.h>
#include<iomanip.h>
#include<stdio.h>
#include<conio.h>
class student
{
	int roll;
	char name[50];
	int pm,cm,mm,em,csm;
	float percent;
	char grade;
	void calculate();
   public:
	void input();
	void output();
	void show_tabular();
	int retroll();
   int rettotal();
};

int student::rettotal()
{
	int rtn=(pm+cm+mm+em+csm);
 return rtn;
}
void student::calculate()
{
  percent=(pm+cm+mm+em+csm)/5.0;
  if(percent>=70)
	  grade='A';
  else if(percent>=50)
	  grade='B';
  else if(percent>=33)
	  grade='C';
  else
	  grade='D';
}
void student::input()
{
 cout<<"\nEnter the roll number of student  ";
 cin>>roll;
 cout<<"\nEnter the Name of the student  ";
 gets(name);
 cout<<"\nEnter marks(out of 100) in :- \n";
 cout<<setw(2)<<"\nPhysics : ";
 cin>>pm;
 cout<<setw(2)<<"\nChemistry : ";
 cin>>cm;
 cout<<setw(2)<<"\nMathematics : ";
 cin>>mm;
 cout<<setw(2)<<"\nEnglish : ";
 cin>>em;
 cout<<setw(2)<<"\nComputer Science : ";
 cin>>csm;
 calculate();
}
void student::output()
{
 cout<<"\n\n----**----";
 cout<<"\nRoll number of student          :     "<<roll;
 cout<<"\nName of student                 :     "<<name;
 cout<<"\nMarks in physics                :     "<<pm;
 cout<<"\nMarks in chemistry              :     ";
 cout<<cm<<"\nMarks in Mathematics            :     ";
 cout<<mm<<"\nMarks in english                :     ";
 cout<<em<<"\nMarks in Computer Science       :     "<<csm;
    cout<<"\nOverall percentage of student    :     "<<percent;
 cout<<"\nGrade of student is             :      "<<grade;
}
void student::show_tabular()
{
 cout<<"\t"<<roll<<"\t    "<<name<<setw(12)<<pm<<setw(5)<<cm<<setw(5)<<mm<<setw(5);
 cout<<" "<<em<<setw(5)<<csm<<setw(6)<<percent<<"%    "<<setw(6)<<grade<<endl;
}

int student::retroll()
{
 return roll;
}


void write_record();//write the record in binary file
void read_record();//read all record from binary file
void display(int);//accept roll no. and display that record
void modify_record(int);//modify specified record
void delete_record(int n);//delete a record
void class_result();
void result();
void welcome();//display welcome screen
void entry_menu();
void class_result_sorter();

void main()
{
  int choice;
  clrscr();
  welcome();
  do
  {
	 clrscr();
	 cout<<"\n\n\n\n\n\n\t\t\tMAIN MENU";
	 cout<<"\n\n\t\t01. RESULT MENU";
	 cout<<"\n\n\t\t02. ENTRY/EDIT MENU";
	 cout<<"\n\n\t\t03. EXIT";
	 cout<<"\n\n\n\n\tPlease Select Your Option(1/2/3)...";
	 cin>>choice;
	 clrscr();
	 switch(choice)
	  {
	  case 1: result();
		 break;
	  case 2: entry_menu();
		 break;
	  case 3: exit(0);
		 break;
	  default:cout<<"Wrong choice entered.Please try again...!!";
		  cout<<"\a";
	  }
	}while(choice!=3);
}

void write_record()
{
  student s;
  ofstream ofile;
  ofile.open("STUDENT.dat",ios::binary|ios::app);
  s.input();
  ofile.write((char*)&s,sizeof(student));
  ofile.close();
  cout<<"\nStudent record has been created.....";
  getch();
}
void read_record()
{
  student s;
  ifstream ifile;
  ifile.open("STUDENT.dat",ios::binary);
  if(!ifile)
	{
	cout<<"Error in Opening file !! Press any key...";
	getch();
	return;
	}
  cout<<"\n\n\n\t Display All Record \n\t*********";
  while(ifile.read((char *)&s,sizeof(student)))
	{
	s.output();
	}
  ifile.close();
  getch();
}

void display(int n)
{
 student st;
 ifstream f;
 f.open("STUDENT.dat",ios::binary);
 if(!f)
  {
	cout<<"\nFile could not open !! Press any key...";
	getch();
	return;
  }
 int flag=0;
 while(f.read((char *)&st,sizeof(student)))
  {
	 if(st.retroll()==n)
	 {
	  st.output();
	  flag=1;
	 }
  }
 f.close();
 if(flag==0)
  cout<<"\n\n!! No results found !!";
 getch();
}

void modify_record(int n1)
{
  int found=0;
  student st;
  fstream file("STUDENT.dat",ios::binary|ios::in|ios::out);
  if(!file)
	{
	cout<<"\nFile could not be open !! Press any key...";
	getch();
	return;
	}
  while(file.read((char *)&st,sizeof(student)))
	{
	 if(st.retroll()==n1)
	 {
		st.output();
		cout<<"\n\nPlease Enter the New Details of student"<<endl;
		st.input();
		int pos=(-1)*sizeof(st);
		file.seekp(pos,ios::cur);
		file.write((char*)&st,sizeof(student));
		cout<<"\n\n\n\t\t....Student record has been update.... ";
		found=1;
	 }
  }
	file.close();
	if(found==0)
		cout<<"\n\n\tRecord Not Found ";
	getch();
}

void delete_record(int n)
{
  student st;
  ifstream ifile;
  ifile.open("STUDENT.dat",ios::binary);
  if(!ifile)
  {
	 cout<<"\nError In Opening File !! Press any key...";
	 getch();
	 return;
  }
  ofstream ofile;
  ofile.open("COPY.dat",ios::out);
  ifile.seekg(0,ios::beg);
  while(ifile.read((char *)&st,sizeof(student)))
  {
	 if(st.retroll()!=n)
	 {
		ofile.write((char *)&st,sizeof(student));
	 }
  }
  ofile.close();
  ifile.close();
  remove("STUDENT.dat");
  rename("COPY.dat","STUDENT.dat");
  clrscr();
  cout<<"\n\n\n\t\tRECORD DELETED..... !!";
  getch();
}

void class_result_sorter()
{
  student stud;
  int studentcount=0;
  fstream f,f1,f2;
  int student_count=0;

  f2.open("SORTING.dat",ios::binary|ios::out);

  f.open("STUDENT.dat",ios::binary|ios::in);
  if(!f)
  {
	 cout<<"\nfile could not be open !! Press any key....";
	 getch();
	 return;
  }

  int i=0;
  while(f.read((char *)&stud,sizeof(student)))
  {
	  studentcount++;
  }
  f.close();

int x=studentcount;
while(x-->0)
   {

   	f.open("STUDENT.dat",ios::binary|ios::in);

      int max=0;
  	while(f.read((char *)&stud,sizeof(student)))
      {
  			if(max<stud.rettotal())
         	max=stud.rettotal();

   	}

   f.close();

   f.open("STUDENT.dat",ios::binary|ios::in);

   f1.open("TEMP.dat",ios::binary|ios::app);


   while(f.read((char *)&stud,sizeof(student)))
      {
  			if(max==stud.rettotal())
         {
         	f2.write((char *)&stud,sizeof(student));
         }

         else
         {
            f1.write((char *)&stud,sizeof(student));
         }

     }

     f.close();
     f1.close();

    remove("STUDENT.dat");
    rename("TEMP.dat","STUDENT.dat");

   }

 f1.close();
 f2.close();

   remove("STUDENT.dat");
   rename("SORTING.dat","STUDENT.dat");

  getch();


}


void class_result()
{
  class_result_sorter();  // SORTING OD RECORDS By MARKS OBTAINED
  student stud;
  ifstream f;
  f.open("STUDENT.dat",ios::binary);
  if(!f)
  {
	 cout<<"\nfile could not be open !! Press any key....";
	 getch();
	 return;
  }
  cout<<"\n\n\t\t\tCLASS   RESULT\n\n";
  cout<<"\n\t======================================================================\n";
  cout<<"\t R.No       Name              P    C    M    E    CS     %age     Grade"<<endl;
  cout<<"\t========================================================================\n";
  while(f.read((char *)&stud,sizeof(student)))
  {
	  stud.show_tabular();
  }

  getch();
  f.close();
}

void result()
{


  int choice;
  int rno;
  cout<<"\n\n\n\t\tRESULT MENU";
  cout<<"\n\n\t01.Class Result ";
  cout<<"\n\n\t02.Student Report Card";
  cout<<"\n\n\t03.RETURN TO MAIN MENU";
  cout<<"\n\n\nEnter choice(1/2/3)";
  cin>>choice;
  clrscr();
  switch(choice)
  {
	 case 1:class_result();break;
	 case 2:cout<<"\n\nEnter Roll No. of Student ";
		cin>>rno;
		display(rno);
		break;
	 case 3:break;
	 default:cout<<"\a";
  }
}

void welcome()
{
  cout<<"\n\n********************************************************************************";
  cout<<"\n\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
  cout<<"\n\n\n\n\t\t\t           STUDENT";
  cout<<"\n\n\t\t\t       PROGRESS REPORT";
  cout<<"\n\n\n\n\t\t\t    MADE BY : ASTHA MISHRA";
  cout<<"\n\t\t\t  KENDRIYA VIDYALAYA JANAKPURI";
  cout<<"\n\n\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
  cout<<"\n\n\n*****************************************************************************";
  getch();
}

void entry_menu()
{
  int ch,num;
  clrscr();
  cout<<"\n\n\n\t\tENTRY MENU";
  cout<<"\n\n\t1.CREATE STUDENT RECORD";
  cout<<"\n\n\t2.DISPLAY ALL STUDENTS RECORD";
  cout<<"\n\n\t3.SEARCH STUDENT RECORD";
  cout<<"\n\n\t4.MODIFY STUDENT RECORD ";
  cout<<"\n\n\t5.DELETE STUDENT RECORD ";
  cout<<"\n\n\t6.RETURN TO MAIN MENU";
  cout<<"\n\nPlease Enter Your Choice(1-6).......";
  cin>>ch;
  clrscr();
  switch(ch)
  {
	  case 1:write_record();break;
	  case 2:read_record();break;
	  case 3:cout<<"\n\n\tPlease enter the roll no. of student ";
		 cin>>num;
		 display(num);
		 break;
	  case 4:cout<<"\n\n\tPlease enter the roll no. of student ";
		 cin>>num;
		 modify_record(num);
		 break;
	  case 5:cout<<"\n\n\tPlease enter the roll no. of student ";
		 cin>>num;
	    delete_record(num);
		 break;
     case 6:break;
     default : cout<<"\a";entry_menu();
  }
}