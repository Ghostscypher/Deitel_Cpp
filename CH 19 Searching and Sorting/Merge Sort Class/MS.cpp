// MergeSort.cpp
#include <iostream>
#include <vector>
#include <cstdlib> // Prototypes for fxs srand() and rand()
#include <ctime> // Prototype for system time to seed rand()
#include "MS.h" // Class MergeSort definition
using namespace std;

// Constructor to fill vector with random ints
MergeSort::MergeSort(int vectorSize)
{
	size = (vectorSize > 0 ? vectorSize : 10); // Validate size
	srand(time(0)); // Seed random number generator using current system time
	
	// Fill vector with random ints in range 10 - 99
	for (int i = 0; i < size; ++i)
		data.push_back(10 + rand() % 99); // 10 - 99
} // End MergeSort constructor

// Split vectors into subvectors, sort subvectors, and merge subvectors into sorted vectors
void MergeSort::sort()
{
	sortSubVector(0, size - 1); // Recursively sort entire vector
} // End Sort

// Recursive function to sort subvectors
void MergeSort::sortSubVector(int low, int high)
{
	// Test base case i.e. size of vector = 1
	if ((high - low) >= 1) // If not base case
	{
		int middle = (low + high) / 2; // Calculates the middle of the vector
		int middle1 = middle + 1; // Calculate next element over
		
		// Output split step/process
		cout << "Split: ";
		displaySubVector(low, high);
		cout << endl << "    ";
		displaySubVector(low, middle);
		cout << "    ";
		displaySubVector(middle1, high);
		cout << endl << endl;
		
		// Split vector in two, sort each half (recursive calls)
		sortSubVector(low, middle); // First Half of vector
		sortSubVector(middle1 , high); // Second half of vector
		
		// Merge two sorted vectors after split calls return
		merge(low, middle, middle1, high);
	} // End if
} // End sortSubVector

// Merge two sorted subVectors into one
void MergeSort::merge(int left, int middle, int middle1, int right)
{
	int leftIndex = left;
	int rightIndex = middle1;	
	int combinedIndex = left;
	vector<int> combined(size); // Workong vector
	
	// Output two sub vectors before merging
	cout << "Merge: ";
	displaySubVector(left, middle);
	cout << endl << "  ";
	displaySubVector(middle1, right);
	cout << endl;
	
	// Merge vectors until reaching the end of either
	while (leftIndex <= middle && rightIndex <= right)
	{
		// Place smaller of two elements into result
		// and move to next space in vector
		if (data[leftIndex] <= data[rightIndex])
			combined[combinedIndex++] = data[leftIndex++];
		else
			combined[combinedIndex++] = data[rightIndex++];
	} // End while
	
	if (leftIndex == middle1) // If at end of left vector
	{
		while (rightIndex <= right) // Copy in rest of right vector
			combined[combinedIndex++] = data[rightIndex++];
	} // End if
	else // At the end of vector
	{
		while(leftIndex <= middle) // Copy in rest of left vector
			combined[combinedIndex++] = data[leftIndex++];
	} // End else
	
	// Copy values back into original vector
	for (int i = left; i <= right; ++i)
		data[i] = combined[i];
	
	// Output merged vector
	cout << "  ";
	displaySubVector(left, right);
	cout << endl << endl;
} // End merge

// Display elements in vector
void MergeSort::displayElements() const
{
	displaySubVector(0, size - 1);
} // End displayElements

// Display certain values in vector
void MergeSort::displaySubVector(int low, int high) const
{
	// Output spaces for alignment
	for (int i= 0; i < low; ++i)
		cout << "  ";
	
	for (int i = low; i <= high; ++i)
		cout << " " << data[i];
} // End displaySubVector