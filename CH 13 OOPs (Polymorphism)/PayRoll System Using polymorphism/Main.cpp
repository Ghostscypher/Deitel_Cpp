#include <iostream>
#include <iomanip>
#include <vector>
#include "Employee.h"
#include "Salaried.h"
#include "Commission.h"
#include "BasePlus.h"
using namespace std;

// Start of prototypes
void virtualViaPointer(const Employee *const);
void virtualViaReference(const Employee &);
// End of prototypes

int main()
{
	// Set floating-point output formatting
	cout << fixed << setprecision(2);
	
	// Create derived-class objects
	SalariedEmployee sEmployee("John", "Doe", "000-00-0000", 800);
	CommissionEmployee cEmployee("Jane", "Doe", "111-11-1111", 1000, .06);
	BasePlusCommissionEmployee bpEmployee("Susan", "Berkely", "222-22-2222", 5000, .04, 300);
	
	cout << "\nEmployees processed individually using static binding:\n\n";
	
	// Output each employee's information and earnings using static binding
	sEmployee.print();
	cout << "\nEarned: $" << sEmployee.earnings() << "\n\n";
	cEmployee.print();
	cout << "\nEarned: $" << cEmployee.earnings() << "\n\n";
	bpEmployee.print();
	cout << "\nEarned: $" << bpEmployee.earnings() << "\n\n";
	
	// Create vectors of three base-class pointers
	vector <Employee *> employees(3);
	
	// Initialize with employees
	employees[0] = &sEmployee;
	employees[1] = &cEmployee;
	employees[2] = &bpEmployee;
	
	cout << "\n\nEmployees processed polymorphically via dynamic/base binding:\n";
	
	// Call virtualViaPointer to print each employee's information and earnings
	// using dynamic binding
	for (size_t i = 0; i < employees.size(); ++i)
		virtualViaPointer(employees[i]);
	
	// Call virtualViaReference to print each employees information and earnings
	// using dynamic binding
	cout << "\n\nVirtual function calls made off base-class references:\n";
	
	for (size_t i = 0; i < employees.size(); ++i)
		virtualViaReference(*employees[i]); // Note dereferencing
} // End main

// Call Employee virtual functions print and earnings off a base-class reference
// pointer using dynamic binding
void virtualViaPointer(const Employee *const baseClassPtr)
{
	baseClassPtr->print();
	cout << "\nEarned: $" << baseClassPtr->earnings();
} // End virtualViaPointer

// Call Employee virtual functions print and earnings off a base-class reference
// pointer using dynamic binding
void virtualViaReference(const Employee &baseClassRef)
{
	baseClassRef.print();
	cout << "\nEarned: $" << baseClassRef.earnings();
} // End virtualViaReference