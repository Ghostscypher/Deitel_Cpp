//prevent Multiple Inclusions of a header
#ifndef TIME_H
#define TIME_H

class Time
{	
public:
	Time(int = 0, int = 0, int = 0);//New constructor
	void setTime(int, int, int);//set hour: minute: second
	//print function normally declared const except for those that will modify time
	void printUniversal() const;//print time in univerasl time format
	void printStandard();//print time in standars time format
	
private:
	int hour;//0 - 23 (24Hr)
	int minute;//0 - 59
	int second;//0 - 59
	void setHour(int);//set hour
	void setMinute(int);//set minute
	void setSecond(int);//set Second
	//This is normally declared const
	int getHour() const;//gets the hour const
	int getMinute() const;//gets the minutes const
	int getSecond() const;//gets the second const
};//end class Time
#endif