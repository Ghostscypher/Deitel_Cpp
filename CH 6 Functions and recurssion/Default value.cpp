#include <iostream>
using namespace std;

//start of prototypes
	double defaultValueFunction(double, double pi = 3.14158);//we give our default value in our function prototype
//end of prototypes

int main()
{
	double radius;
	
	cout << "Please enter radius of circle: ";
	cin >> radius;
	
	//print results
	cout << "The area of the circle is: " << defaultValueFunction(radius) << " unit square" << endl;/*note that
	 pi is optional therefore we can write radius only without supplying the second argument i.e. pi*/
}//end main

//in this case pi is a default value
double defaultValueFunction(double radius, double pi)//don't supply default value here
{
	return pi * radius * radius;
}//end defaultValueFunction