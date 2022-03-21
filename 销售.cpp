#include <iostream>

using namespace std;

class Product
{
private:
	static int n;          
	static float sum;      
	static float discount;
	int num;              
	int quantity;          
	float price;        

public:
	Product(int n, int q, float p) :num(n), quantity(q), price(p) {};
	void total();           
	static float average(); 
	static void display(); 
};

void Product::total() 
{
	float rate = 1.0;
	if (quantity>10)
		rate = 0.98 * rate; 
	sum = sum + quantity * price * rate * (1 - discount);
	n = n + quantity;
}

float Product::average()
{
	return (sum / n);
}

void Product::display()
{
	cout <<average() << endl;
	cout <<sum << endl;
}
