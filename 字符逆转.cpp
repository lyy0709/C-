#include <iostream>
#include <string>
using namespace std;
int main()
{
	string str;
	cout<<"please input a string:";
	cin>>str;
	int size=str.length();
	cout<<"the inverted string is:";
	for(int i=size-1;i>=0;i--)
	{
		cout<<str[i];
	}
	cout<<endl;
	return 0;
}
