#include <iostream>
#include <iomanip>
#include <cstdlib> // Exit function prototype
#include <stdexcept>
#include "Array.h"
using namespace std;

// Overloaded input operator for class Array
// Inputs value for the entire array
istream &operator>>(istream &input, Array &a)
{
	for (int i = 0; i < a.size; ++i)
		input >> a.Ptr[i];
	
	return input; // Enables cin >> x >> y
} // End fumction

// Overloaded output array for class Array
ostream &operator<<(ostream &output, const Array &a)
{
	int i;
	
	// Output private Ptr based arrays
	for (i = 0; i < a.size; ++i)
	{
		output << setw(12) << a.Ptr[i];
		
		if ((i + 1) % 4 == 0) // Four numbers per row
			output << endl;	
	} // End for
	
	if (i % 4 != 0) // End last line of output
		output << endl;
	
	return output; // enables cout << x << y;
} // End function operator<<

// Default constructor
Array::Array(int arraySize)
{
	// Validate arraySize
	if (arraySize > 0)
		size = arraySize;
	else
		throw invalid_argument("Array size must be greater than 0");
	
	Ptr = new int[size]; // Create space for pointer based array
	
	// Start loop
	for(int i = 0; i < size; ++i)
		Ptr[i] = 0; // set pointer-based array elements
} // End constructor

// Copy constructor for class Array
// Must recieve a referfence to prevent infinite recussion
Array::Array(const Array &arrayToCopy)
: size(arrayToCopy.size)
{
	Ptr = new int[size]; // Create space for pointer based array
	
	// Start loop
	for(int i = 0; i < size; ++i)
		Ptr[i] = 0; // set pointer-based array elements	
}

int Array::getSize() const
{
	return size; // Number of elements in array	
} // End function getSize

// Overloaded assignment
// Const avoids (a1 = a2) = a3
const Array &Array::operator=(const Array &right)
{
	if (&right != this) // Avoid self-assignment
	{
		// For arrays of different sizes, deallocate original
		// left-side array, then allocate new left side array
		if (size != right.size)
		{
			delete [] Ptr;
			size = right.size;
			Ptr = new int[size]; // Create space for array copy
		} // End inner if
		for (int i = 0; i < size; ++i)
			Ptr[i] = right.Ptr[i]; // Copy array into object
	} // End outer if
	return *this; // Enable x = y = z i.e. cascading
} // end '=' overload

//Determine if two arrays are equal as boolean
bool Array::operator==(const Array &right) const
{
	if (size != right.size)
		return false; // Arrays of different number of elements
	
	for (int i = 0; i < size; ++i)
		if (Ptr[i] != right.Ptr[i])
			return false;
		
	return true; // Arrays are equal	
}

// Overloaded subscript operator for non-const Arrays,
// reference return creates a modifiable lvalue
int &Array::operator[](int subscript)
{
	// Check for subxript out_of_range error
	if (subscript < 0 || subscript >= size)
		throw out_of_range("Subscript out of range");
	
	return Ptr[subscript]; // Rteurns copy of this element
} // End function operator[]

// Overloaded subscript operator for const Array,
// const reference returns creates an rvalue

int Array::operator[](int subscript) const
{
	// Check for subscript out_of_range error
	if (subscript < 0 || subscript >= size)
		throw out_of_range("Subscript out of range");
	
	return Ptr[subscript];
} // end function operator[]

Array::~Array()
{
	delete [] Ptr; // Release pointer-based array space	
} // End destructor