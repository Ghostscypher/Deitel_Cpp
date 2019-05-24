#include <iostream>
#include <stdexcept>
#include "Array.h"
using namespace std;

int main()
{
	Array integer(7); // Create and initialize a 7-element Array class
	Array integer1; // Create and intialize a 10-element Array class by default
	
	// Print integer object size and contents
	cout << "Size of integer is: "
		 << integer.getSize()
		 << "\nArray after initialization:\n" << integer;
		 
		 	// Print integer1 object size and contents
	cout << "Size of integer1 is: "
		 << integer1.getSize()
		 << "\nArray after initialization:\n" << integer1;
		 
	// Input and print integer and integer1
	cout << "Enter integer" <<  endl;
	cin >> integer >> integer1;
	
	// Use overloaded inequality (!=) operator
	cout << "\nEvaluating: integer != integer1: ";
	
	if (integer != integer1)
		cout << "True. Not equal";
	else
		cout << "False. Equal";
	
	// Create Array integer2 using integer as an initializer. Print size and contents
	Array integer2(integer); // Invokes copy constructor
	
	cout << "\nSize of integer2 is: "
	 	 << integer2.getSize()
	 	 << "\nArray after initialization:\n" << integer2;
    
	// Use overloaded asignment (=) operator
	cout << "\nAssigning integer1 to integer:\n" << endl;
	integer = integer1; // N.B. Target array is smaller
	
	cout << "\nInteger is: \n"
		 << integer
		 << "\nInteger1 is: \n"
		 << integer1;
		 
	// Use overloaded equality (==) operator
	if (integer == integer1)
		cout << "Integer and integer1 are equal" << endl;
	else
		cout << "Integer and integer are not equal" << endl;
	
	// Use overloaded subscript operator to create rvalue
	cout << "\nInteger[5] is: " << integer[5];
	
	// Use overloaded subscript operator to create lvalue
	cout << "\n\nAssigning 1000 to integer[5]" << endl;
	integer[5] = 1000;
	cout << "Integer: \n" << integer;
	
	// Attempt to use out_of_range subscript
	try
	{
		cout << "\nAttempt to assign 1000 to integer[15]" << endl;
		integer[15] = 1000;
	} // End try
	catch(out_of_range &e)
	{
		cout << "An exception occured: " << e.what() << endl;
	} // End catch
} // End main