#include <iostream>
using namespace std;

/**
 * @brief Bit fields are used to declare the number of bits a variable can occupy
 * 		  in a class or struct dfeinition.
 * 
 * @description
 * This can be done by using the semicolon ':' as shown below
 * 	usigned b:2;
 * The above variable 'b' will occupy 2 bits.
 * This is used in classes and structs only.
 */

int main()
{
	struct T
	{
		unsigned b : 4;
		unsigned a : 2;
	}; // End struct T
	
	// Fill values for variables
	T var;
	var.b = 5;
	var.a = 1;
	
	// Print their sizes
	cout << var.b << endl;
	cout << var.a << endl;
} // End main