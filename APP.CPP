//program to print calendar of given date starting from 2001;
#include <iostream>
#include <stdio.h>
#include <conio.h>
using namespace std;
#include "gotoxyy.h"
void pressKey(int code, int *mon, int *year)
{
   if (code == 77)
   {
      *mon==12 ?(*mon = 1),(*year += 1) : *mon += 1;
   }
   else if (code == 75)
   {
      *mon == 1 ?(*mon = 12),(*year -= 1):*mon -= 1;
   }
   else if (code == 72)
   {
      *year += 1;
   }
   else if (code == 80)
   {
      *year -= 1;
   }
   else if(code==27)
     exit(1);
   else
      cout<<"INVALID KEY";
}
long int limitcount(int baseYear, int year, int mon)
{
   long int limcount = 0;
   int leap = 0, j, days = 0, toBeDay = 0;
   leap = year - baseYear;
   limcount = leap * 365;
   if (leap >= 4)
   {
      leap /= 4;
      limcount += leap;
   }
   for (j = 1; j < mon; j++)
   {
      if (j == 1 || j == 3 || j == 5 || j == 7 || j == 8 || j == 10 || j == 12)
         days += 31;
      else if (j == 2)
      {
         days += 28;
         if ((year % 4 == 0 && year % 100 != 0) || (year % 4 == 0 && year % 100 == 0 && year % 400 == 0))
            days++;
      }
      else if (j == 4 || j == 6 || j == 9 || j == 11)
         days += 30;
   }
   limcount = limcount + days;
   //cout << "\n lim" << limcount;
   toBeDay = limcount % 7;
   toBeDay += 1;
   if (toBeDay == 7)
      toBeDay = 0;
   cout << toBeDay;
   return (toBeDay);
}
void decideMonth(int Month, int year)
{
   gotoxy(44, 11);
   if (Month == 1)
      cout << "-----JANUARY-----" << year;
   else if (Month == 2)
      cout << "------FEBRUARY------" << year;
   else if (Month == 3)
      cout << "-----MARCH------" << year;
   else if (Month == 4)
      cout << "-----APRIL-----" << year;
   else if (Month == 5)
      cout << "-----MAY-----" << year;
   else if (Month == 6)
      cout << "-----JUNE-----" << year;
   else if (Month == 7)
      cout << "-----JULY-----" << year;
   else if (Month == 8)
      cout << "-----AUGUST-----" << year;
   else if (Month == 9)
      cout << "-----SEPTEMPBER-----" << year;
   else if (Month == 10)
      cout << "------OCTOBER-----" << year;
   else if (Month == 11)
      cout << "------NOVEMBER-----" << year;
   else if (Month == 12)
      cout << "-----DECEMBER-----" << year;
}
void printMonths(int mon, int year, int baseYear)
{
   int i, days, j = 0, inc = 0, move = 13, keyCode = 0, reserved = 0, toBeDay = 0;
   while (1)
   {
      toBeDay = limitcount(baseYear, year, mon);
      if (mon == 1 || mon == 3 || mon == 5 || mon == 7 || mon == 8 || mon == 10 || mon == 12)
         days = 31;
      else if (mon == 2)
      {
         days = 28;
         if ((year % 4 == 0 && year % 100 != 0) || (year % 4 == 0 && year % 100 == 0 && year % 400 == 0))
            days = 29;
      }
      else if (mon == 4 || mon == 6 || mon == 9 || mon == 11)
         days = 30;
      inc = toBeDay * 5;
      decideMonth(mon, year);
      gotoxy(40, 12);
      cout << "SUN  MON  TUE  WED  THU  FRI  SAT\n";
      for (i = 1; i <= days; i++)
      {
         gotoxy(40, move);
         for (j = 1; j <= 31; j++)
         {
            if (j == inc + 1)
            {
               cout << i;
               if (i >= 10)
                  j++;
               inc += 5;
               if ((i < days) && (inc < 31))
                  i++;
               else
                  break;
            }
            else
               cout << " ";
         }
         move++;
         inc = 0;
         cout << endl;
      }
      j == 7 ? reserved = 0 : reserved = j + 1;
      gotoxy(75, 19);
      cout << "PRESS ANOTHER KEY: ";
      keyCode = getche();
      move = 13;
      system("cls");
      gotoxy(1,1);
   cout << "\nPRESS RIGHT ARROW KEY FOR ONE MONTH BACk";
   cout << "\nPRESS LEFT ARROW KEY FOR ONE MONTH FORWARD";
   cout << "\nPRESS UP ARROW KEY FOR ONE  YEAR BACK";
   cout << "\nPRESS DOWN ARROW KEY FOR ONE YEAR FORWARD";
   cout<<  "\nPRESS ESCAPRE KEY FOR EXIT";
      pressKey(keyCode, &mon, &year);
   }
}
main()
{
   long int limcount;
   int date = 0, mon = 0, year = 0, baseYear = 2001, baseDay = 1, toBeDay = 0;
   cout << "ENTER DATE: ";
   cin >> date;
   cout << "\nENTER MONTH: ";
   cin >> mon;
   cout << "\nENTER YEAR STARTING FROM 2001: ";
   cin >> year;
   system("cls");
   cout << "\nU CAN CHANGE THIS CALENDAR ACCORDING TO UR CHOICE";
   cout << "\nPRESS RIGHT ARROW KEY FOR ONE MONTH BACk";
   cout << "\nPRESS LEFT ARROW KEY FOR ONE MONTH FORWARD";
   cout << "\nPRESS UP ARROW KEY FOR ONE  YEAR BACK";
   cout << "\nPRESS DOWN ARROW KEY FOR ONE YEAR FORWARD";
   cout<<  "\nPRESS ESCAPRE KEY FOR EXIT";
   printMonths(mon, year, baseYear);
}