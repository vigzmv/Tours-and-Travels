#include<iostream.h>
#include<conio.h>
#include<windows.h>

void S(int n)
{
HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_CURSOR_INFO cur;

GetConsoleCursorInfo(out,&cur);
cur.bVisible=n;
SetConsoleCursorInfo(out,&cur);
}



void main()
{
 cputs("NO CURSOR");
 S(0);
 getch();
}