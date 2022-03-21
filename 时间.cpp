#include<iostream> 
using namespace std; 
class Time; 
class Date 
{ 
public: 
 Date(int y,int m,int d){year=y;month=m;day=d;}; 
 friend void display(const Date &,const Time &); 
 int year; 
 int month; 
 int day; 
}; 
class Time 
{ 
public: 
 Time(int h,int m,int s){hour=h;minute=m;second=s;}; 
 friend void display(const Date &,const Time &); 
 int hour; 
 int minute; 
 int second; 
}; 
void display(const Date &d,const Time &t) 
{ 
 cout<<d.year<<"/"<<d.month<<"/"<<d.day<<" ";
 cout<<t.hour<<":"<<t.minute<<":"<<t.second; 
} 

 //主函数已给定如下，提交时不需要包含下述主函数
int main()
{
    void display(const Date &,const Time &);
    int year,month,day;
    cin>>year>>month>>day;
    Date d1(year,month,day);
    int hour,minute,second;
    cin>>hour>>minute>>second;
    Time t1(hour,minute,second);
    display(d1,t1);
    return 0;
}
