#include <iostream>
#include "Temp.h"
using namespace std;

int main()
{
	const int aSize = 5; // Size of array a
	const int bSize = 7; // Size of array b
	const int cSize = 6; // Size of array c
	
	// Initialize and populate array
	int a[aSize] = {1, 2, 3, 4, 5};
	double b[bSize] = {1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 1.7};
	char c[cSize] = "HELLO"; // 6th position dor null.
	
	// Call integer function template function specialization
	cout << "Array a contains: " << endl;
	printArray(a, aSize);
	
	// Call doyble function template function specialization
	cout << "Array a=b contains: " << endl;
	printArray(b, bSize);
	
	// Call character function template function specialization
	cout << "Array c contains: " << endl;
	printArray(c, cSize);
} // End main