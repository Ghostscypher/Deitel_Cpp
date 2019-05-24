#include <iostream>
#include <stdexcept>
#include "Time.h"
using namespace std;

int main()
{
	Time t;//initialize an instance of the class Time
	
	cout << "The initial universal time is: ";
	t.printUniversal();
	cout << "\nThe initial standard time is: ";
	t.printStandard();
	
	//set time
	t.setTime(16, 45, 50);
	
	//print new time values
	cout << "\n\nAfter setting the time to (16, 45, 50), the new time is: " << endl;
	cout << "Universal: ";
	t.printUniversal();
	cout << "\nStandard: ";
	t.printStandard();
	
	//attempt to set time with invalid values
	
	cout << "\n\nTrying to set invalid value (99, 99, 99)" << endl;
	try
	{
		t.setTime(99, 99, 99);
	}
	catch(invalid_argument &e)
	{
		cout << "\nException: " << e.what() << endl;
	}
	//output values after specifying invalid values
	cout << "\nAfter attempting invalid values" << endl;
	cout << "Universal: ";
	 t.printUniversal();
	cout << "\nStandard: ";
	t.printStandard();
	
	
}