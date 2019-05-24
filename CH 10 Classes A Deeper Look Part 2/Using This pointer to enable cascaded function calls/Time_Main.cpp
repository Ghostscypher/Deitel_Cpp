#include <iostream>
#include <stdexcept>
#include "Time.h"
using namespace std;

int main()
{
	Time t; //Create time object
	
	// Cascaded function calls
	t.setHour(18).setMinute(30).setSecond(22);
	
	//Output time in universal and standard format
	cout << "Universal: ";
	t.printUniversal();
	
	cout << "\nStandard: ";
	t.printStandard();
	
	cout <<"\n\nNew Universal time: ";
	
	// Cascaded function calls
	t.setTime(20, 20, 20).printUniversal();
	cout << endl;
} // End main