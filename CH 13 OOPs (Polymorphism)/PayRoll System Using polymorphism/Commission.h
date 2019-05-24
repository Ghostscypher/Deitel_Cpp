#ifndef COMMISSION_H
#define COMMISSION_H

#include <string>
#include "Employee.h"
using namespace std;

class CommissionEmployee : public Employee
{
public:
	CommissionEmployee(const string &, const string &, const string &,
						double = 0.0, double = 0.0); // Default onstructor
	
	void setGrossSales(double); // Set gross sales ammount
	double getGrossSales() const; // Return gross sales ammount
	
	void setCommissionRate(double); // Set commission rate as a percentage
	double getCommissionRate() const; // Return commission rate
	
	virtual double earnings() const; // Calculate earnings
	virtual void print() const; // Print CommissionEmployee object
protected:
	double grossSales; // Gross weekly sales
	double commissionRate; // Commission percentage
}; // End class CommissionEmployee

#endif