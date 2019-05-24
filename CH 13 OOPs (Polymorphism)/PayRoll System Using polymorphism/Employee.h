#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
using namespace std;

class Employee
{
public:
	Employee(const string &, const string &, const string &); // Constructor
	
	void setFirstName(const string &); // Set the first name
	string getFirstName() const; // Return the first name
	
	void setLastName(const string &); // Set the last name
	string getLastName() const; // Return last name
	
	void setSSN(const string &); // Set the Social Security Number(SSN)
	string getSSN() const; // Return SSN
	
	// Pure virtual functions makes employee an abstract base class
	virtual double earnings() const = 0; // Pure virtual
	virtual void print() const; // Virtual. Can't be pure virtual coz we'll use it to
private:						// print first name, last name, and SSN
	string firstName;
	string lastName;
	string SSN; // Social Security Number (SSN)
}; // End class Employee

#endif