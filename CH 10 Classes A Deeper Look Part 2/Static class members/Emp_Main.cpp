#include <iostream>
#include "Emp.h" // Employee class definition
using namespace std;

int main()
{
	// No object exist; use class name and binary scope resolution
	// operator to access static member function getCount
	cout << "Number of employees before instantiation of many object is "
	<< Employee::getCount() << endl; // Use class name
	
	// The following scope creates and destroys employees object before main
	// terminates
	{
		Employee e1("Susan", "Baker");
		Employee e2("Robert", "Jones");
		
		// Two objects exists; call static member function getCount again using
		// the class name and the scope resolution operator
		cout << "Number of employees after objects are instantiated is "
		<< Employee::getCount() << endl;
		
		cout << "\n\nEmployee 1: " << e1.getFirstName() << ' ' << e1.getLastName()
		<< "\nEmployee 2: " << e2.getFirstName() << ' ' << e2.getLastName();
	} // End nested scope in main
	
	// No objects exists, so call static member function getCount again using
	// the class name and the scope resolution operator
	cout << "\nNumber of employees after objects are deleted is "
	<< Employee::getCount() << endl;
} // End main