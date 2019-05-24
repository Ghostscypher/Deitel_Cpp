#include <iostream>
#include <stdexcept>
#include "Commission.h"
using namespace std;

// Constructor
CommissionEmployee::CommissionEmployee(const string &first, const string &last, const string &ssn,
										double sales, double rate)
// Explicitly call Employee constructor
: Employee(first, last, ssn)
{
	// Should also validate these
	try
	{
		setGrossSales(sales);
		setCommissionRate(rate);
	}
	catch(invalid_argument &e)
	{
		cout << e.what() << endl;
	}
} // End constructor

// Set gross sales ammount
void CommissionEmployee::setGrossSales(double sales)
{
	if (sales >= 0.0)
		grossSales = sales;
	else
		throw invalid_argument("Gross Sales must be >= 0.0");
} // End setGrossSales

// Return gross sales ammount
double CommissionEmployee::getGrossSales() const
{
	return grossSales;
} // End getGrossSales

// Set commission rate
void CommissionEmployee::setCommissionRate(double rate)
{
	if (rate > 0.0 && rate < 1.0)
		commissionRate = rate;
	else
		throw invalid_argument("Commission rate must be > 0.0 and < 1.0");
} // End setCommissionRate

// Return commission rate
double CommissionEmployee::getCommissionRate() const
{
	return commissionRate;
} // End getCommissionRate

// Calculate earnings
double CommissionEmployee::earnings() const
{
	return getCommissionRate() * getGrossSales();
} // End earnings

// Print CommissionEmployee object
void CommissionEmployee::print() const
{	
	cout << "\nCommission Employee: ";
	Employee::print();
	cout << "\nGross sales: " << getGrossSales()
		 << "\nCommission rate: " << getCommissionRate();
} // End print