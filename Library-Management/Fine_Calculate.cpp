#include <iostream>
#include "conio.h"
using namespace std;
struct date         // date for fine calculation , book issue date to submit date;
{
    int day;
    int month;
    int year;
};

bool Is_Leap_Year(int year)                 // that is check is leap year not and return true and false
{
    return(year%4==0 && year%100!=0) || (year%400==0);
}
int Days_In_Month(int month,int year)           // That return how many days given month
{
    int days[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    if (month==2 && Is_Leap_Year(year)) 
        return 29;
    return days[month];
}
int Calculate_Days(int day,int month,int year)      // That calculate how many days in given date
{
    int days=0;
    for (int i=1;i<year;i++) 
    {
        if(Is_Leap_Year(i))
            days +=366;
        else
            days +=365;
    }
    for (int i=1;i<month;i++) {
        days+=Days_In_Month(i,year);
    }
    days+=day;
    return days;
}
void input_Date()
{   int day1,day2,sub;
    date issue_date,submit_date;
    cout<<"\tEnter your book issue date--> "<<endl<<endl;
    cout<<"\tDate of day: ";
    cin>>issue_date.day;

    cout<<"\tDate of month: ";
    cin>>issue_date.month;

    cout<<"\tDate of year: ";
    cin>>issue_date.year;

    cout<<"\tEnter your book sumbit date--> "<<endl<<endl;
    cout<<"\tDate of day: ";
    cin>>submit_date.day;

    cout<<"\tDate of month: ";
    cin>>submit_date.month;

    cout<<"\tDate of year: ";
    cin>>submit_date.year;
    if((issue_date.day<=31 && issue_date.month<=12 && issue_date.year>=2000) && (submit_date.day<=31 && submit_date.month<=12 && submit_date.year>=2000))
    {
        day1=Calculate_Days(issue_date.day,issue_date.month,issue_date.year);
        day2=Calculate_Days(submit_date.day,submit_date.month,submit_date.year);
        sub=day2-day1;
        if(sub>=7)
        cout<<"Your extra days is "<<sub-7<<" and fine total is "<<(sub-7)*20<<" ruppies!"<<endl;
        else
            cout<<"You fine is 0 ruppies!"<<endl;
        cout<<"Press any key to continue!\n";
        getch();
        cin.ignore();
        return;
    }
    else
        cout<<"Your input is wrong please re-enter date-->\n";
    input_Date();
}