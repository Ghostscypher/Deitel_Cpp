#include <iostream>
#include "Date.h"
#include "Emp.h"
using namespace std;

Employee::Employee(const string &first, const string &second, const Date &dateOfBirth, const Date &dateOfHire)
:
firstName(first), // initialize First Name
lastName(second), // initialize Last Name
birthDate(dateOfBirth), // initialize birth date
hireDate(dateOfHire) // initialize hire date
{
	// output Employee object to show when the constructor is called
	cout << "Employee object constructor: "
	<< firstName << ", " << lastName << endl;
}// end of employee constructor

// Print Employee object
void Employee::print() const
{
	cout << lastName << ", " << firstName << " Hired: ";
	hireDate.print();
	cout << "Birthday: ";
	birthDate.print();
	cout << endl;
}// end function print

// output Employee to show when it's destructor is called
Employee::~Employee()
{
	cout << "Employee object destructor: "
	<< lastName << ", " <<	 firstName << endl;
}// end ~Employee destructor