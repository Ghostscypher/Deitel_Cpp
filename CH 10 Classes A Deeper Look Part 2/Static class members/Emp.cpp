#include <iostream>
#include "Emp.h"
using namespace std;

// Define and initialize static data member at global namespace scope
int Employee::count = 0; // Cannot include the keyword static

// Define static member function that returns number of employees objects
// instatiated (declared static in Emp.h)
int Employee::getCount()
{
	return count;
} // End static function getCount

Employee::Employee(const string &first, const string &last)
: firstName(first), lastName(last)
{
	count++; // Increment static count of Employees
	cout << "Employee constructor for " << firstName
	<< ' ' << lastName << " called." << endl;
} // End employee constructor

string Employee::getFirstName() const
{
	return firstName; // return copy of first name
} // End function getFirstName

string Employee::getLastName() const
{
	return lastName; // Return copy of last name
} // End function getLastName

// Destructor deallocates dynamically allocated memory
Employee::~Employee()
{
	cout << "\n~Employee() called for " << firstName
	<< ' ' << lastName << endl;
	
	count--; // decrement static count of employees
} // End ~Employee destructor 