#include <iostream>
using namespace std;

void sort(int &,int &,int &);
int main()
{
 int a,b,c,a1,b1,c1;
 cout<<"Please enter 3 integers:";
//补充输入语句 
cin>>a>>b>>c;
 a1=a;b1=b;c1=c;
 sort(a1,b1,c1);
 cout<<a<<" "<<b<<" "<<c<<" in sorted order is ";
//补充输出语句 
cout<<a1<<" "<<b1<<" "<<c1<<" ";
 return 0;
}

//补充sort函数体
void sort(int &a1,int &b1,int &c1)
{
int temp;
if(a1>b1)
{temp=a1;a1=b1;b1=temp;};
if(a1>c1)
{temp=a1;a1=c1;c1=temp;};
if(b1>c1)
{temp=b1;b1=c1;c1=temp;};
}


