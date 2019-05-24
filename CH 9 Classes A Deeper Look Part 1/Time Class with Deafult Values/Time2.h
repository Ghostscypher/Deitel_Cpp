//prevent Multiple Inclusions of a header
#ifndef TIME_H
#define TIME_H

class Time
{	
public:
	Time(int = 0, int = 0, int = 0);//New constructor
	void setTime(int, int, int);//set hour: minute: second
	void printUniversal();//print time in univerasl time format
	void printStandard();//print time in standars time format
	
private:
	int hour;//0 - 23 (24Hr)
	int minute;//0 - 59
	int second;//0 - 59
	void setHour(int);//set hour
	void setMinute(int);//set minute
	void setSecond(int);//set Second
	int getHour();//gets the hour
	int getMinute();//gets the minutes
	int getSecond();//gets the second
};//end class Time
#endif