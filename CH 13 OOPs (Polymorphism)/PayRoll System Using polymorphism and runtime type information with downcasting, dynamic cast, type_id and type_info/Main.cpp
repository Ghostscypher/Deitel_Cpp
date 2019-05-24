#include <iostream>
#include <iomanip>
#include <vector>
#include <typeinfo>
#include "Employee.h"
#include "Salaried.h"
#include "Commission.h"
#include "BasePlus.h"
using namespace std;

int main()
{
	// Set floating-point output formatting
	cout << fixed << setprecision(2);
	
	// Create vector of three base-class pointers
	vector <Employee *> employees(3);
	
	// Initialize vector with various kind of employees
	employees[0] = new SalariedEmployee("John", "Smith", "000-00-0000", 800);
	employees[1] = new CommissionEmployee("Sue", "Jones", "111-11-1111", 1000, .06);	
	employees[2] = new BasePlusCommissionEmployee("Bob", "Lewis", "222-22-2222", 5000, .04, 300);
	
	// Polymorphically process each element in vector employees
	for (size_t i = 0; i < employees.size(); ++i)
	{
		employees[i]->print(); // Output employee information
		cout << endl;
		
		// Downcast pointer
		BasePlusCommissionEmployee *derivedPtr = dynamic_cast<BasePlusCommissionEmployee *>
		(employees[i]);
		
		// Determine if element points to base salaried commission employee
		if (derivedPtr != 0) // 0 if it is not BasePlusCommissionEmployee object
		{
			double oldBaseSalary = derivedPtr->getBaseSalary(); 
			cout << "Old base salary: $" << oldBaseSalary << endl;
			derivedPtr->setBaseSalary(1.10 * oldBaseSalary);
			cout << "New base salary with 10% increase is: $" << derivedPtr->getBaseSalary() << endl;
		} // End if
		
		cout << "\nEarned: $" << employees[i]->earnings() << "\n\n";
	} // End for
	
	// Release objects pointed to by vector's elements
	for (size_t i = 0; i < employees.size(); ++i)
	{
		 // Output class name
		 cout << "Deleting object of " << typeid(*employees[i]).name() << endl;
		 delete employees[i];
	} // End for
} // End main