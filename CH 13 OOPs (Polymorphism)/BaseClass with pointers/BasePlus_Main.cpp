#include <iostream>
#include <iomanip>
#include <stdexcept>
#include "Commission.h"
#include "BasePlus.h"
using namespace std;

int main()
{
	// Create base-class pointer
	CommissionEmployee *cEmployeePtr = 0;
	
	// Derived class object
	BasePlusCommissionEmployee bpEmployee(
	"Bob", "Lewis", "333-33-3333", 5000, .04, 300);
	
	// Aim base-class pointer at derived-class object
	cEmployeePtr = &bpEmployee;
	
	// Invoke base-class member member function on derived-class
	// object through base-class pointer
	string firstName = cEmployeePtr->getFirstName();
	string lastName = cEmployeePtr->getLastName();
	string SSN = cEmployeePtr->getSSN();
	double grossSales = cEmployeePtr->getGrossSales();
	double commissionRate = cEmployeePtr->getCommissionRate();
	
	// Attempt to invoke derived-class-only member functions
	// on derived-class object through base-class pointer (DisAllowed)
	double baseSalary = cEmployeePtr->getBaseSalary();
	cEmployeePtr->setBaseSalary(500);
} // End main