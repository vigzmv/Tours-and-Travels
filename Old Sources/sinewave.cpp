#include<fstream.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<dos.h>
#include<windows.h>
#include<math.h>


void main()
{
 int x,x2=1,y;
 for(int j=0,k=0; j<46;j++)
 {
   if(j%6==0) k++;
	y=0;x=x2++;
 for(int i=0;i<40;i++)
 {

 	if(i<8)
   	y++;
   else if(i<16)
   	y--;
   else if(i<24)
   	y++;
   else if(i<32)
   	y--;
   else if(i<40)
   	y++;
  /*  else if(i<48)
   	y--;
   else if(i<56)
   	y++;
  else if(i<64)
   	y--;
   else if(i<72)
   	y++;
   else if(i<80)
		y--;
   else if(i<88)
   	y++;
   else if(i<96)
   	y--;
   else if(i<104)
   	y++;
   else if(i<112)
   	y--;         */

   Sleep(3);
   x=x+3;
   if(j%2==0)
   {
   gotoxy(x,y+15);
   cputs("* * *");
   }

   else
   {
   gotoxy(x,y+15);
   cputs("     ");
   }

   }
}
getch();

}
