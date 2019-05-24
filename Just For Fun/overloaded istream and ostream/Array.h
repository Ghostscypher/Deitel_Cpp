#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
using namespace std;

class Array
{
// Operator non-member Overloading
friend ostream &operator<<(ostream &, const Array &);
friend istream &operator>>(istream &, Array &);
public:
	Array(int = 10); // Default constructor
	Array (const Array &); // Copy constructor
	
	int getSize() const; // Return size
 
	const Array &operator=(const Array &); // Assignment operator
	bool operator==(const Array &) const; // Equality operator
	
	// Inequality operator returns opposite of '==' operator
	bool operator!=(const Array &right)
	{
		return !(*this == right); // Invokes Arry::operator==
	} // End function operator !=
	
	// Subscript operator for non-constant objects returns modifiable lvalue.
	int &operator[](int);
	
	// Subscript operator for constant objects return rvalue
	int operator[](int) const;
	
	~Array(); // Destructor
// private:
	int size; // Pointer based array size
	int *Ptr; // Pointer to first element of pointer-based arrays
}; // End class array

#endif