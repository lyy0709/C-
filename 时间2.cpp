#include <iostream>
//补充程序
using namespace std; 
class Date;
class Time 
{ 
public: 
 Time(int h,int m,int s){hour=h;minute=m;second=s;};
 void display(Date &);
 int hour; 
 int minute; 
 int second; 
}; 

class Date 
{ 
public: 
 friend Time;
 Date(int y,int m,int d){year=y;month=m;day=d;}; 
 int year; 
 int month; 
 int day; 
}; 
void Time::display(Date &d) 
{ 
 cout<<d.year<<"/"<<d.month<<"/"<<d.day<<" ";
 cout<<hour<<":"<<minute<<":"<<second; 
} 
int main()
{
    int year,month,day;
    cin>>year>>month>>day;
    Date d1(year,month,day);
    int hour,minute,second;
    cin>>hour>>minute>>second;
    Time t1(hour,minute,second);
    t1.display(d1);
    return 0;
}
