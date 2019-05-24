#include <iostream>
#include <stdexcept>
#include "BasePlus.h"
using namespace std;

// Constructor
BasePlusCommissionEmployee::BasePlusCommissionEmployee(const string &first, const string &last, const string &ssn,
										double sales, double rate, double salary)
 // Explicitly call CommissionEmployee class constructor
 : CommissionEmployee(first, last, ssn, sales, rate)
{
	// Should also validate these
	try
	{
		setBaseSalary(salary);
	}
	catch(invalid_argument &e)
	{
		cout << e.what() << endl;
	}
} // End constructor

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
	cout << "BasePlusCommission Employee: " << firstName << ' ' << lastName
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