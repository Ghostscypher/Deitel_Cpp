#include <iostream>
#include "Employee.h"
using namespace std;

// Constructor
Employee::Employee(const string &first, const string &last, const string &ssn)
: firstName(first), lastName(last), SSN(ssn)
{
	// Empty body	
} // End constructor

// Set first name
void Employee::setFirstName(const string &first)
{
	firstName = first;
} // End setFirstName

// Return first name
string Employee::getFirstName() const
{
	return firstName;
} // End getFirstName

// Set last name
void Employee::setLastName(const string &last)
{
	lastName = last;
} // End setLastName

// Return last name
string Employee::getLastName() const
{
	return lastName;
} // End getLastName

// set Social Security Number
void Employee::setSSN(const string &ssn)
{
	SSN = ssn;
} // End setSSN

// Return SSN
string Employee::getSSN() const
{
	return SSN;
} // End getSSN

// Print function (virtual) N.B. NOT pure virtual
void Employee::print() const
{
	cout << getFirstName() << ' ' << getLastName()
		 << "\nSSN: " << getSSN();
} // End print