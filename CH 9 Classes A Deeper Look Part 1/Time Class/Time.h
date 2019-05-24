//prevent Multiple Inclusions of a header
#ifndef TIME_H
#define TIME_H

class Time
{
private:
	   int hour;//0 - 23 (24Hr)
	   int minute;//0 - 59
	   int second;//0 - 59	
protected:
	
public:
	Time();//constructor
	void setTime(int, int, int);//set hour: minute: second
	void printUniversal();//print time in univerasl time format
	void printStandard();//print time in standars time format
};//end class Time
#endif