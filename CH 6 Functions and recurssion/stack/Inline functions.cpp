#include <iostream>
#include <iomanip>

using namespace std;

//no prototypes for inline function. They appear before main function

inline double cube(const double x)
{	
	return x * x * x;//calculate and return cube of x
}

int main()
{
	double x;
	//set format
	cout << fixed << setprecision(2);
	cout << "Please enter the side of the cube you want to find the value: ";
	cin >> x;
	
	//calculate and print results
	cout << "The volume of a cube of sides " << x << " is: " << cube(x) << " unit cube" << endl; 
}