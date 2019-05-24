#include <iostream>
#include "Date.h"
using namespace std;

Date::Date(int m, int d, int y)
{
	month = m;
	day = d;
	year = y;
}

//print date in the format mm/dd/yyyy
void Date::print()
{
	cout << month << "/" << day << "/" << year << endl;
}