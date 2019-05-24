#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
using namespace std;

class Array
{
friend istream &operator>>(istream &, Array &);
friend ostream &operator<<(ostream &, const Array &);
public:
	Array(int = 10); // Default constructor
	Array(const Array &); // Copy constructor
	int getSize() const; // Return size
	const Array &operator=(const Array &); // Assignment operator
	bool operator==(const Array &) const; // Equality operator
	
	// Inequality operator returns opposite of == operator
	bool operator!=(const Array rvalue) const
	{
		return !(*this == rvalue); // Invokes Array::operator==
	} // End function operator!=
	
	// Subscript operator for non-constant objects returns modifiable lvalue
	int &operator[](int);
	
	// Subscript operator for constant object returns rvalue
	int operator[](int) const;
	
	~Array(); // Destructor
private:
	int size; // Pointer-based array size
	int *ptr; // Pointer to first element of pointer-based arrays
}; // End class Array

#endif