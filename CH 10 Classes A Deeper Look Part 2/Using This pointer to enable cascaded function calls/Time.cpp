#include <iostream>
#include <iomanip>
#include <stdexcept>
#include "Time.h"
using namespace std;

Time::Time(int hour, int minute, int second) // new constructor function
{
	setTime(hour, minute, second); // validate and set time
} // End constructor

int Time::getHour() const
{
	return hour;
} // End getHour

int Time::getMinute() const
{
	return minute;
} // End getMinute

int Time::getSecond() const
{
	return second;
} // End getSecond

Time &Time::setTime(int h, int m, int s)
{
	setHour(h);
	setMinute(m);
	setSecond(s);
	return *this; // Enables casacading
} // End set time

Time &Time::setHour(int h)
{
	if((h >= 0) && (h < 24))
		hour = h;
	else
		throw invalid_argument("Hour must be between 0 and 23 (0 - 23)");
	
	return *this; // Enables cascading
} // End setHour

Time &Time::setMinute(int m)
{
	if((m >= 0) && (m < 60))
		minute = m;
	else
		throw invalid_argument("Minute must be between 0 and 59 (0 - 59)");
	
	return *this; // Enables cascading
} // End setMinute

Time &Time::setSecond(int s)
{
	if((s >= 0) && (s < 60))
		second = s;
	else
		throw invalid_argument("Second must be between 0 and 59 (0 - 59)");
	
	return *this; // Enables cascading
} // End setSecond

void Time::printUniversal() const
{
	cout << setfill('0') << setw(2) << getHour() << ":" << setw(2) << getMinute() << ":"
	<< setw(2) << getSecond() << " HRs";
} // End print

void Time::printStandard()
{
	cout << ((getHour() == 0 || getHour() == 12)? 12: getHour() % 12) << ":" << setfill('0') <<
	setw(2) << getMinute() << ":" << setw(2) << getSecond() << ((getHour() < 12)? " AM": " PM");
} // End print standard

Time::~Time()
{
	// Empty body
} // End destructor