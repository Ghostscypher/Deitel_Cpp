#include <iostream>
#include <stdexcept>
#include "Salaried.h"
using namespace std;

// Constructor
SalariedEmployee::SalariedEmployee(const string &first, const string &last,
									const string &ssn, double salary)
// Explicitly call Employee class constructor
: Employee(first, last, ssn)
{
	try
	{
		setWeeklySalary(salary); // Validate and set weekly salary
	}
	catch(invalid_argument &e)
	{
		cout << e.what() << endl;
	} // End try...catch
} // End constructor

// Set weekly salary
void SalariedEmployee::setWeeklySalary(double salary)
{
	if (salary >= 0.0)
		weeklySalary = salary;
	else
		throw invalid_argument("The weekly salary must be >= 0.0");
} // End getWeeklySalary

// Return weekly salary
double SalariedEmployee::getWeeklySalary() const
{
	return weeklySalary;
} // End getWeeklySalary

// Calculate earnings
double SalariedEmployee::earnings() const
{
	return getWeeklySalary();
} // End earnings

// Print SalariedEmployee object
void SalariedEmployee::print() const
{
	cout << "\n\nSalaried Employee: ";
	Employee::print();
	cout << "\nWeekly salary: " << earnings();
} // End print