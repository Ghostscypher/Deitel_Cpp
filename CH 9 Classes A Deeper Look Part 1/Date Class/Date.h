#ifndef DATE_H
#define DATE_H
class Date
{
public:
	Date(int = 1, int = 1, int = 1111);//Default constructor
	void print();
private:
	int month;
	int day;
	int year;
};//end class date
#endif