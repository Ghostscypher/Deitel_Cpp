#include <iostream>
#include <iomanip>
using namespace std;

/*Constants must be initialized with const datatype name = value; otherwise
a compilation error occurs. For example const tau = 3.14159 * 2;
constants are uesd for initializing static arrays. i.e. they do not change
otherwise if array is dynamic then a compilation error ocuurs*/

int main()
{
	//using most common constant pi
	const double pi = 3.141592653589793;
	const double tau = pi * 2; 
	double radius = 0;//good practice to always initialize your variable
	//prompt user to enter radius of the circle
	cout << "Please enter the radius: ";
	cin >> radius;
	//calculate using pi then tau
	cout << "The area of the circle using pi is: " << pi * radius * radius << endl;
	cout << "The area of the circle using tau is: " << (tau * radius * radius) / 2 << endl;
}//end main	