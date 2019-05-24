#include <iostream>
#include "complex.h"
using namespace std;

int main()
{
	// Declare and initialize class Complex objects
	Complex x; 
	Complex y(4.3, 8.2);
	Complex z(3.3, 1.1);
	
	cout << "x: " << x
		 << "\ny: " << y
		 << "\nz: " << z;
		 
	// Testing operator+
	x = y + z;
	
	// Print the new value of x
	cout << "\n\nx = y + z:\n" << x << " = " << y << " + " << z << endl;
	
	// Testing operator-
	x = y - z;
	
	// Print the new value of x
	cout << "\n\nx = y - z:\n" << x << " = " << y << " - " << z << endl;
} // End main