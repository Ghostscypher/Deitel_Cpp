#include <iostream>
#include "MS.h"
using namespace std;

int main()
{
	// Create object to do merge sort
	MergeSort sortVector(10);
	
	// Display unsorted vector
	cout << "Unsorted vector." << endl;
	sortVector.displayElements();
	cout << endl << endl;
	
	sortVector.sort(); // Sort vector
	
	// Display sorted vector
	cout << "Sorted vector." << endl;
	sortVector.displayElements();
} // End main