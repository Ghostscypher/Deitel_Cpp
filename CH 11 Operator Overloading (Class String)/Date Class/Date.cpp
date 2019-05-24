#include <iostream>
#include <string>
#include <stdexcept>
#include "Date.h"
using namespace std;

// Initialize static class, one classwide copy
const int Dates::days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// Dates constructor
Dates::Dates(int mm, int dd, int yy)
{
	Dates::setDate(mm, dd, yy); // Set default date
} // End Dates constructor

// Set month, Dates, year
void Dates::setDate(int mm, int dd, int yy)
{
	if (mm >= 1 && mm <= 12)
		month = mm;
	else
		throw invalid_argument("Month must be '1 - 12'");
	
	if (yy >= 1900 && yy <= 2100)
		year = yy;
	else
		throw invalid_argument("Year must be '1900 - 2100'");
		
	if ((month == 2 && leapYear(year) && dd >= 1 && dd <= 29) || dd >= 1 && dd <= days[month])
		day = dd;
	else
		throw invalid_argument("Day is out of range for the current month and year");
} // End function setDate

// Overloaded prefix increment operator
Dates &Dates::operator++()
{
	helpIncrement(); // Increment Dates
	
	return *this; // Reference return to create lvalue
} // End function operator++

// Overloaded postfix increment operator. N.B. the dummy integer operator does
// not have a parameter name
Dates Dates::operator++(int)
{
	Dates temp = *this; // Hold current state of object
	helpIncrement();
	
	// return unincremented, saved temporary object
	return temp; // Value return not a reference return
} // End function operator++

// Add a specific number of days to Dates
const Dates &Dates::operator+=(int additionalDays)
{
	for (int i = 0; i < additionalDays; ++i)
		helpIncrement();
	
	return *this;
} // End function operator+=

// If the year is a leap year, return true otherwise return false
bool Dates::leapYear(int testYear)
{
	if (testYear % 400 == 0 ||
	(testYear % 100 != 0 && testYear % 4 == 0))
		return true;
	else
		return false;
} // End function leapYear

// Determine whether day is last day of the month
bool Dates::endOfMonth(int testDay) const
{
	if (month == 2 && leapYear(year))
		return testDay == 29;
	else
		return testDay == days[month];
} // End function endOfMonth

// Function to help increment Dates
void Dates::helpIncrement()
{
	// Day is not end of month
	if (!endOfMonth(day))
		++day; // Increment day
	else
	{
		if (month < 12)
		{
			++month; // Increment month
			day = 1; // First day of new month
		}
		else // Last day of month
		{
			++year; // Increment year
			month = 1; // First month of new year
			day = 1; // First day of new month
		} // End if...else
	} // End if...else
} // End function helpIncrement

// Overloaded output operator
ostream &operator<<(ostream &output, const Dates &d)
{
	static string monthName[13] = {"", "January", "February", "March", "April", "May",
	"June", "July", "August", "Sepetember", "October", "Novemeber", "December"};
	
	output << monthName[d.month] << " " << d.day << ", " << d.year;
	
	return output; // Enables cascading
} // End operator<<