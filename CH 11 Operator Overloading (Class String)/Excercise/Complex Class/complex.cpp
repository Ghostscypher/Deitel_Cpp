#include <iostream>
#include "complex.h"
using namespace std;

// Constructor
Complex::Complex(double realPart, double imaginaryPart)
:real(realPart),
 imaginary(imaginaryPart)
{
	// Empty body
} // End constructor

// Destructor
Complex::~Complex()
{
	// Empty body
} // End destructor

// Overloaded functions
// Addition operator
Complex Complex::operator+(const Complex &operand) const
{
	return Complex(real + operand.real, imaginary + operand.imaginary);
} // End operator+

// Substraction operator
Complex Complex::operator-(const Complex &operand) const
{
	return Complex(real - operand.real, imaginary - operand.imaginary);
} // End operator-

// Overloaded input operator
istream &operator>>(istream &input, Complex &a)
{
	input >> a.real >> a.imaginary; 
	
	return input; // Enables cin >> x >> y;
} // End operator>>

// Overloaded output operator
ostream &operator<<(ostream &output, const Complex &a)
{
	output << '(' << a.real << ", " << a.imaginary << ')';
	
	return output; // Enables cout << x << y;
} // End operator<<