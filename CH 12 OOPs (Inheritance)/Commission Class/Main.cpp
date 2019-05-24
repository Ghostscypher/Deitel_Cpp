#include <iostream>
#include <iomanip>
#include <stdexcept>
#include "Commission.h"
using namespace std;

int main()
{
	// Instantiate a CommissionEmployee object
	CommissionEmployee employee(
	"Sue", "Jones", "222-22-2222", 1000, 1.06);
	
	// Set floating point fixed output
	cout << fixed << setprecision(2);
	
	// Get Commission Employee data
	cout << "Employee information obtained by get functions:"
		 << "\nFirst Name: " << employee.getFirstName()
		 << "\nLast Name: " << employee.getLastName()
		 << "\nSSN: " << employee.getSSN()
		 << "\nGross Sales: " << employee.getGrossSales();
		 
	// Use set functions
	employee.setGrossSales(800);
	employee.setCommissionRate(.1);
	
	// Print the updated details using print functions
	cout << "\nUpdated employee information output by print function: \n" << endl;
	employee.print();
	
	// Print the employee's earning
	cout << "\n\nEmployee's earning: $" << employee.earnings();
} // End main