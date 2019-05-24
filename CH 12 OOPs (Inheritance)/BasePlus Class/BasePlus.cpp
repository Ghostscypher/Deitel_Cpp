#include <iostream>
#include <stdexcept>
#include "BasePlus.h"
using namespace std;

// Constructor
BasePlusCommissionEmployee::BasePlusCommissionEmployee(const string &first, const string &last, const string &ssn,
										double sales, double rate, double salary)
:firstName(first),
 lastName(last), // The program should validate all of these
 SSN(ssn)
{
	// Should also validate these
	try
	{
		setGrossSales(sales);
		setCommissionRate(rate);
		setBaseSalary(salary);
	}
	catch(invalid_argument &e)
	{
		cout << e.what() << endl;
	}
} // End constructor

// Set first name
void BasePlusCommissionEmployee::setFirstName(const string &first)
{
	firstName = first;
} // End setFirstName

// Get the first name
string BasePlusCommissionEmployee::getFirstName() const
{
	return firstName;
} // End getFirstName

// Set last name
void BasePlusCommissionEmployee::setLastName(const string &last)
{
	lastName = last;
} // End setLastName

// Get the last name
string BasePlusCommissionEmployee::getLastName() const
{
	return lastName;
} // End getLastName

// Set Social Security Number(SSN)
void BasePlusCommissionEmployee::setSSN(const string &ssn)
{
	SSN = ssn;
} // End setSSN

// Get the first name
string BasePlusCommissionEmployee::getSSN() const
{
	return SSN;
} // End getSSN

// Set gross sales ammount
void BasePlusCommissionEmployee::setGrossSales(double sales)
{
	if (sales >= 0.0)
		grossSales = sales;
	else
		throw invalid_argument("Gross Sales must be >= 0.0");
} // End setGrossSales

// Return gross sales ammount
double BasePlusCommissionEmployee::getGrossSales() const
{
	return grossSales;
} // End getGrossSales

// Set commission rate
void BasePlusCommissionEmployee::setCommissionRate(double rate)
{
	if (rate > 0.0 && rate < 1.0)
		commissionRate = rate;
	else
		throw invalid_argument("Commission rate must be > 0.0 and < 1.0");
} // End setCommissionRate

// Return commission rate
double BasePlusCommissionEmployee::getCommissionRate() const
{
	return commissionRate;
} // End getCommissionRate

// Set the base salary
void BasePlusCommissionEmployee::setBaseSalary(double salary)
{
	if (salary >= 0.0)
		baseSalary = salary;
	else
		throw invalid_argument("The base salary must be >= 0.0");
} // End setBaseSalary

// Return the base salary
double BasePlusCommissionEmployee::getBaseSalary() const
{
	return baseSalary;
} // End getBaseSalary

// Calculate earnings
double BasePlusCommissionEmployee::earnings() const
{
	return baseSalary + (commissionRate * grossSales);
} // End earnings

// Print CommissionEmployee object
void BasePlusCommissionEmployee::print() const
{	
	cout << "Commission Employee: " << firstName << ' ' << lastName
		 << "\nSocial Security Number(SSN): " << SSN
		 << "\nGross sales: " << grossSales
		 << "\nCommission rate: " << commissionRate
		 << "\nBase salary: " << baseSalary;
} // End print

// Destructor
BasePlusCommissionEmployee::~BasePlusCommissionEmployee()
{
	// Empty body
} // End destructor