#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
using namespace std;

class Complex
{
friend istream &operator>>(istream &, Complex &);
friend ostream &operator<<(ostream &, const Complex &);
public:
	Complex (double = 0.0, double = 0.0); // Constructor
	Complex operator+(const Complex &) const; // Addition
	Complex operator-(const Complex &) const; // Subtraction
	~Complex(); // Destructor
private:
	double real; // Real part
	double imaginary; // Imaginary part
}; // End class complex

#endif