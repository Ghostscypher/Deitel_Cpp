#include <iostream>
#include <stdexcept>
#include "Date.h"
using namespace std;

Date::Date(int m, int d, int y)
{
	month = m;
	day = d;
	year = y;
}

// print date in the format mm/dd/yyyy
void Date::print() const
{
	cout << month << "/" << day << "/" << year << endl;
}

int Date::checkDay(int testDay) const
{
	static const int daysPerMonth[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	
	// determine if testday is valid for specified month
	if((testDay > 0) && (testDay <= daysPerMonth[month]))
		return testDay;
	
	// February 29 check for leap year
	if((month == 2 && testDay == 29) && ((year % 400 == 0 || year % 4 == 0) && year % 100 != 0))
		return testDay;
	
	throw invalid_argument("Invalid day for current month and year");
}// end function checkday

Date::~Date()
{
	cout << "Date object destructor for date ";
	print();
	cout << endl;
}