#include <iostream>
#include <iomanip>
#include <stdexcept>
#include "BasePlus.h"
using namespace std;

int main()
{
	// Instantiate a CommissionEmployee object
	BasePlusCommissionEmployee employee(
	"Sue", "Jones", "222-22-2222", 1000, .06, 300);
	
	// Set floating point fixed output
	cout << fixed << setprecision(2);
	
	// Get Commission Employee data
	cout << "Employee information obtained by get functions:"
		 << "\nFirst Name: " << employee.getFirstName()
		 << "\nLast Name: " << employee.getLastName()
		 << "\nSSN: " << employee.getSSN()
		 << "\nGross Sales: " << employee.getGrossSales()
		 << "\nBase salary: " << employee.getBaseSalary();
		 
	// Use set functions
	employee.setBaseSalary(100);
	employee.setGrossSales(800);
	employee.setCommissionRate(.1);
	
	// Print the updated details using print functions
	cout << "\n\nUpdated employee information output by print function: \n" << endl;
	employee.print();
	
	// Print the employee's earning
	cout << "\n\nEmployee's earning: $" << employee.earnings();
} // End main