#include <iostream>
#include <iomanip>
#include <cstdlib> // Exit function prototype
#include <stdexcept>
#include "Array.h"
using namespace std;

// Default constructor for Array class default size (10)
Array::Array(int arraySize)
{
	// Validate array size
	if (arraySize > 0)
		size = arraySize;
	else
		throw invalid_argument("Array size must be greater than 0");
	
	ptr = new int[size]; // Create space for pointer-based array
	
	for (int i = 0; i < size; ++i)
		ptr[i] = 0;
} // End constructor

// Copy constructor for class Array
// Must recieve a reference to prevent infinite recursion
Array::Array(const Array &arrayToCopy)
:size(arrayToCopy.size)
{
	ptr = new int[size];
	
	for (int i = 0; i < size; ++i)
		ptr[i] = arrayToCopy.ptr[i]; // Copy into object
} // End Array copy constructor

int Array::getSize() const
{
	return size; // Number of elements in an Array
} // End function getSize

// Destructor for class Array
Array::~Array()
{
	delete [] ptr; // Release pointer based Array space
} // End destructor

// Overloaded functions
// Overloaded assignment operator, const return avoids (a1 = a2) = a3
const Array &Array::operator=(const Array &rvalue)
{
	if (&rvalue != this) // Avoid self assignment
	{
		// For arrays of different sizes, deallocate original left-side array
		// then allocate new right side array
		if (size != rvalue.size)
		{
			delete [] ptr; // Release space
			size = rvalue.size; // Resize the object
			ptr = new int[size]; // Create space for array to copy
		} // End inner if
		
		for (int i = 0; i < size; ++i)
			ptr[i] = rvalue.ptr[i]; // Copy Array into object
	} // End outer if
	
	return *this; // Enables x = y = z
} //End operator=

// Determine if two Arrays are equal
bool Array::operator==(const Array &rvalue) const
{
	if (size != rvalue.size)
		return false; // Arrays of different number of elements
	
	for (int i = 0; i < size; ++i)
		if (ptr[i] != rvalue.ptr[i])
			return false; // Array size are not equal
		
	return true; // Arrays are equal
} // End operator==

// Overload subscript operator for non const Arrays, reference return
// creates a modifiable lvalue
int &Array::operator[](int subscript)
{
	// Check for subscript out_of_range error
	if (subscript < 0 || subscript >= size)
		throw out_of_range("Subscript out of range");
	
	return ptr[subscript]; // Reference return
} // End function operator[]

// Overloaded subscript operator for const arrays, const values returns rvalue
int Array::operator[](int subscript) const
{
		// Check for subscript out_of_range error
	if (subscript < 0 || subscript >= size)
		throw out_of_range("Subscript out of range");
	
	return ptr[subscript]; // Returns copy of this value. i.e. byvalue
} // End operator[]

// Overloaded input operator for class Array, inputs values for entire Array
istream &operator>>(istream &input, Array &a)
{
	for (int i = 0; i < a.size; ++i)
		input >> a.ptr[i];
	
	return input; // Enables cin >> x >> y
} // End operator>>

ostream &operator<<(ostream &output, const Array &a)
{
	int i;
	
	// Output private ptr-based array
	for (i = 0; i < a.size; ++i)
	{
		output << setw(12) << a.ptr[i];
		
		if ((i + 1) % 4 == 0) // 4 numbers per row of output
			output << endl;
	} // End for
	
	if (i % 4 != 0) // End last line of output
		output << endl;
	
	return output; // Enables cout << x << y;
} // End operator<<