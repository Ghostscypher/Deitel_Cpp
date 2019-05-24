#ifndef TEMP_H
#define TEMP_H

#include <iostream>
using namespace std;

// Function template print array definition
template <typename T> // N.b. 'T' can be any identifier

void printArray(const T * const array, int arraySize)
{
	for (int i = 0; i < arraySize; ++i)
		cout << array[i] << ' ';
	
	cout << endl;
} // End printArray

#endif