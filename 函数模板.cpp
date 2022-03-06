#include <iostream>
#include <string>
using namespace std;

//补充函数模板的定义
template <typename T>
void sort(T a[])
{
T temp;
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
	cout<<a[i]<<"  ";
	}
	cout<<"\n\n";
}

int main()
{ int a[5]={1,9,0,23,-45};
  float b[5]={2.4, 7.6, 5.5, 6.6, -2.3 };
  long c[5]={10100,-123567, 1198783,-165654, 3456};
  sort(a);
  sort(b);
  sort(c);
  return 0;
}
