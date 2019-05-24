#include <iostream>
#include <stdexcept>
#include "Commission.h"
using namespace std;

// Constructor
CommissionEmployee::CommissionEmployee(const string &first, const string &last, const string &ssn,
										double sales, double rate)
:firstName(first),
 lastName(last), // The program should validate all of these
 SSN(ssn)
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

// Set first name
void CommissionEmployee::setFirstName(const string &first)
{
	firstName = first;
} // End setFirstName

// Get the first name
string CommissionEmployee::getFirstName() const
{
	return firstName;
} // End getFirstName

// Set last name
void CommissionEmployee::setLastName(const string &last)
{
	lastName = last;
} // End setLastName

// Get the last name
string CommissionEmployee::getLastName() const
{
	return lastName;
} // End getLastName

// Set Social Security Number(SSN)
void CommissionEmployee::setSSN(const string &ssn)
{
	SSN = ssn;
} // End setSSN

// Get the first name
string CommissionEmployee::getSSN() const
{
	return SSN;
} // End getSSN

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
	cout << "Commission Employee: " << getFirstName() << ' ' << getLastName()
		 << "\nSocial Security Number(SSN): " << getSSN()
		 << "\nGross sales: " << getGrossSales()
		 << "\nCommission rate: " << getCommissionRate();
} // End print

// Destructor
CommissionEmployee::~CommissionEmployee()
{
	// Empty body
} // End destructor