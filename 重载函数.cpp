#include <iostream>
#include <string>
using namespace std;
int main()
{
  long  c[5]={10100,-123567, 1198783,-165654, 3456};
  int a[5]={1,9,0,23,-45};
  float b[5]={2.4, 7.6, 5.5, 6.6, -2.3 };

  void sort(int []);
  void sort(float []);
  void sort(long []);
  //补充三个函数调用语句
  sort(a);cout<<"\n";
  sort(b);cout<<"\n";
  sort(c);cout<<"\n";
  return 0;
}

//补充三个重载的函数体
void sort(int a[])
{
int temp;
for(int i=0;i<5;i++)
	for(int j=i+1;j<5;j++)
	{
		if(a[i]>a[j])
		{
		temp=a[i];
		a[i]=a[j];
		a[j]=temp;
		}
	}
	cout<<"the sorted numbers :\n";
	for(int i=0;i<5;i++)
	{
	cout<<a[i]<<" ";
	}
}
void sort(float a[])
{
float temp;
for(int i=0;i<5;i++)
	for(int j=i+1;j<5;j++)
	{
		if(a[i]>a[j])
		{
		temp=a[i];
		a[i]=a[j];
		a[j]=temp;
		}
	}
	cout<<"the sorted numbers :\n";
	for(int i=0;i<5;i++)
	{
	cout<<a[i]<<" ";
	}
}
void sort(long a[])
{
long temp;
for(int i=0;i<5;i++)
	for(int j=i+1;j<5;j++)
	{
		if(a[i]>a[j])
		{
		temp=a[i];
		a[i]=a[j];
		a[j]=temp;
		}
	}
	cout<<"the sorted numbers :\n";
	for(int i=0;i<5;i++)
	{
	cout<<a[i]<<" ";
	}
}
