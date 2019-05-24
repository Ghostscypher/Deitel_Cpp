#ifndef SALARIED_H
#define SALARIED_H

#include "Employee.h"

class SalariedEmployee : public Employee
{	
public:
	SalariedEmployee(const string &, const string &, const string &,
					  double = 0.0); // Constructor
					  
	void setWeeklySalary(double); // Set the weekly Salary
	double getWeeklySalary() const; // Return the weekly salary
	
	// Keyword 'virtual' signals intent to overide
	virtual double earnings() const; // Calculate Earnings
	virtual void print() const; // Print SalariedEmployee Object
private:
	double weeklySalary; // Salary per week	
}; // End class SalariedEmployee

#endif