#include <iostream>
#include <iomanip>
#include <stdexcept>
#include "Commission.h"
#include "BasePlus.h"
using namespace std;

int main()
{
	// Create base-class object
	CommissionEmployee cEmployee(
	"Sue", "Jones", "222-22-2222", 1000, .06);
	
	// Create base-class pointer
	CommissionEmployee *cEmployeePtr = 0;
	
	// Create derived-class object
	BasePlusCommissionEmployee bpEmployee(
	"Bob", "Lewis", "333-33-3333", 500, 0.04, 300);
	
	// Create derived-class pointer
	BasePlusCommissionEmployee *bpEmployeePtr = 0;
	
	// Set floating point fixed output
	cout << fixed << setprecision(2);
	
	// Print CommissionEmployee and BasePlusCommissionEmployee objects
	cout << "Print base class and derived objects:\n";
	cEmployee.print(); // Invokes base-class print
	cout << "\n\n";
	bpEmployee.print(); // Invokes derived-class print
	
	//  Aim base-class pointer at base class object and print
	cEmployeePtr = &cEmployee;
	cout << "\n\nCalling print with base-class pointer to"
	"\nBase-class object invokes base class print function:\n";
	cEmployeePtr->print(); // Invokes base class print
	
	//  Aim derived-class pointer at derived-class object and print
	bpEmployeePtr = &bpEmployee;
	cout << "\n\nCalling print with derived-class pointer to"
	"\nDerived-class object invokes derived class print function:\n";
	bpEmployeePtr->print(); // Invokes derived class print
	
	// Aim base-class Pointer to derived class object and print
	cEmployeePtr = &bpEmployee;
	cout << "\n\nCalling print with base-class pointer to"
	"\nDerived-class object invokes derived class print function:\n";
	cEmployeePtr->print(); // Invokes base-class class print
	
	// Polymorphism invokes BasePlusCommissionEmployee's print
	// base-class pointer to derived class object
	cout << endl << endl;
	cEmployeePtr->print();
	cout << endl;
} // End main