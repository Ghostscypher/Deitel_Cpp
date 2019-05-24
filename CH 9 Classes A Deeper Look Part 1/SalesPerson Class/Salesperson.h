#ifndef SALESPERSON_H
#define SALESPERSON_H
class SalesPerson
{
public:
	static const int monthsPerYear = 12;
	SalesPerson();//constructor
	void getSalesFromUser();//input sales from keyboard
	void setSales(int, double);//set sales for a specific month
	void printAnnualSales();//Summarize and print the sales for the whole year

private:
	double totalAnnualSales();//prototype for utility function
	double sales[monthsPerYear];//12 monthly sales
};//end class salesperson
#endif