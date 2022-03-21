#include <iostream>
#include <iomanip>
using namespace std;
//完成类模板的定义
using namespace std;
 
template<class numtype>
 
class Compare
{
public:
    Compare(numtype a,numtype b);
    numtype max();
    numtype min();
private:
    numtype x,y;
};
 
 
template<class numtype>
Compare<numtype>::Compare(numtype a,numtype b)
{
	x=a;
	y=b;
}
 
template<class numtype>
numtype Compare<numtype>::max()
{
	return (x>y)?x:y;
}
 
template<class numtype>
numtype Compare<numtype>::min()
{
	return (x<y)?x:y;
}

//main函数的定义
int main()
{
    int i1,i2;
    cin>>i1>>i2;
    Compare<int> cmp1(i1,i2);
    cout<<cmp1.max()<<" "<<cmp1.min()<<endl;
    float f1,f2;
    cin>>f1>>f2;
    Compare<float> cmp2(f1,f2);
    cout<<setiosflags(ios::fixed);
    cout<<setprecision(2);
    cout<<cmp2.max()<<" "<<cmp2.min()<<endl;
    char c1,c2;
    cin>>c1>>c2;
    Compare<char> cmp3(c1,c2);
    cout<<cmp3.max()<<" "<<cmp3.min()<<endl;
    return 0;
}

