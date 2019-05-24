#ifndef BASEPLUS_H
#define BASEPLUS_H

#include <string>
#include "Commission.h"
using namespace std;

class BasePlusCommissionEmployee :public CommissionEmployee
{
public:
	BasePlusCommissionEmployee(const string &, const string &, const string &,
						double = 0.0, double = 0.0, double = 0.0); // Default onstructor
	
	void setBaseSalary(double); // Set base salary
	double getBaseSalary() const; // Get the base salary
	
	virtual double earnings() const; // Calculate earnings
	virtual void print() const; // Print CommissionEmployee object
	
	~BasePlusCommissionEmployee(); // Destructor	
private:
	double baseSalary; // The base salary
}; // End class CommissionEmployee

#endif