#ifndef BASEPLUS_H
#define BASEPLUS_H

#include <string>
using namespace std;

class BasePlusCommissionEmployee
{
public:
	BasePlusCommissionEmployee(const string &, const string &, const string &,
						double = 0.0, double = 0.0, double = 0.0); // Default onstructor
	
	void setFirstName(const string &); // Set first name
	string getFirstName() const; // Return first name
	
	void setLastName(const string &); // Set Last name
	string getLastName() const; // Return Last name
	
	void setSSN(const string &); // Set Social Security Number
	string getSSN() const; // Return Social Security Number
	
	void setGrossSales(double); // Set gross sales ammount
	double getGrossSales() const; // Return gross sales ammount
	
	void setCommissionRate(double); // Set commission rate as a percentage
	double getCommissionRate() const; // Return commission rate
	
	void setBaseSalary(double); // Set base salary
	double getBaseSalary() const; // Get the base salary
	
	double earnings() const; // Calculate earnings
	void print() const; // Print CommissionEmployee object
	
	~BasePlusCommissionEmployee(); // Destructor	
private:
	string firstName;
	string lastName;
	string SSN; // Social Security Number
	double grossSales; // Gross weekly sales
	double commissionRate; // Commission percentage
	double baseSalary; // The base salary
}; // End class CommissionEmployee

#endif