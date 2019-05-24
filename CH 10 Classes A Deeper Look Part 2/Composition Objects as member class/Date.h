#ifndef DATE_H
#define DATE_H
class Date
{
public:
	Date(int = 1, int = 1, int = 1111);// Default constructor
	void print() const;
	~Date();
private:
	int month;
	int day;
	int year;
	
	// utility function
	int checkDay(int) const;
};// end class date
#endif