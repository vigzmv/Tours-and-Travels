#include<stdio.h>
#include<conio.h>
#include<iostream.h>
void pw(long,char[]);
char *one[]={" "," one"," two"," three"," four"," five"," six"," seven",
" eight"," Nine"," ten"," eleven"," twelve"," thirteen"," fourteen"," fifteen"," sixteen"," seventeen"," eighteen"," nineteen"};
char *ten[]={" "," "," twenty"," thirty"," forty"," fifty"," sixty",
" seventy"," eighty"," ninety"};
void m()
{
 long n;
 clrscr();
 printf("Enter any 9 digit no.(or less) : ");
 scanf("%9ld",&n);
 if(n<=0)
                printf("Enter numbers greater than 0");
 else
 {
						pw((n/10000000)," Crore");
						pw(((n/100000)%100)," Lakh");
						pw(((n/1000)%100)," Thousand");
						pw(((n/100)%10)," Hundred");
						pw((n%100)," ");
 }
 getch();
}
void pw(long n,char ch[])
{
 (n>19)?cout<<ten[n/10]<<one[n%10]:cout<<one[n];
 if(n) cout<<ch;
}