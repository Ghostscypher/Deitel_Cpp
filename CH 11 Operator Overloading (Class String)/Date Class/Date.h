#ifndef DATE_H
#define DATE_H

#include <iostream>
using namespace std;

class Dates
{
friend ostream &operator<<(ostream &, const Dates &);
	
public:
	Dates(int = 1, int = 1, int = 1900); // Default constructor
	void setDate(int, int, int); // Set month, day, year respectively
	Dates &operator++(); // Prefix increment operator
	Dates operator++(int); // Postfix increment operator
	const Dates &operator+=(int); // Add days modify object
	static bool leapYear(int); // Is sdate in a leap year?
	bool endOfMonth(int) const; // Is date at end of month?
	
private:
	int month;
	int day;
	int year;
	
	static const int days[]; // Arrays of days per month
	void helpIncrement(); // Utility function for incrementing date
};
#endif