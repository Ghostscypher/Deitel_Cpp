#include <iostream>
#include <iomanip>
using namespace std;

class Test
{
friend ostream &operator<<(ostream &num, const Test &numb)
{
	num << "(The number is: " << numb.Number << ")";
	
	return num;
}

friend istream &operator>>(istream &num, Test &numb)
{
	num >> numb.Number;
	
	return num;
}

public:
	Test(int n)// Default constructor
	:Number(n)
	{
		// Empty body
	} // End constructor
	
	int printf() const // Print the current value of number
	{
		return Number;
	} // End print
	
	~Test() // Detsructor
	{
		// Empty body
	} // End destructor
private:
	int Number;	
}; // Emd class test

int main()
{
	Test T(20); // Create Test object
	
	cout << T;
	
	cout << "Please enter an integer: ";
	cin >> T;
	
	cout << T;
} // Emd main