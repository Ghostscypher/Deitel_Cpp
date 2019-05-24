//prevent Multiple Inclusions of a header
#ifndef TIME_H
#define TIME_H

class Time
{	
public:
	Time(int = 0, int = 0, int = 0); // New constructor
	
	// set functions (the time & return types enable cascading)
	Time &setTime(int, int, int); // set hour, minute, and second
	Time &setHour(int); // set hour
	Time &setMinute(int); // set minute
	Time &setSecond(int); // set second
	
	// print function normally declared const except for those that will modify time
	void printUniversal() const; // print time in univerasl time format
	void printStandard(); // print time in standars time format
	
	// This is normally declared const
	int getHour() const; // gets the hour
	int getMinute() const; // gets the minutes
	int getSecond() const; // gets the second
	
	~Time(); // Destructor
private:
	int hour; // 0 - 23 (24Hr)
	int minute; // 0 - 59
	int second; // 0 - 59
}; // End class Time
#endif