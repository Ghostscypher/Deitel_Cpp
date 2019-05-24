// BinarySearch.cpp
#include <iostream>
#include <cstdlib> // Prototype for fxs srand and rand
#include <ctime> // Prototype for function time
#include <algorithm> // Prototype for sort function
#include "BS.h" // Class binary search definition
using namespace std;

// Constructor initializes vector with random ints and sorts the vector
BinarySearch::BinarySearch(int vectorSize)
{
	size = (vectorSize > 0 ? vectorSize : 10); // Validate vector size, default 10
	srand(time(0)); // Seed rand using current system time
	
	// Fill vector with random ints within range 10 - 99
	for (int i = 0; i < size; ++i)
		data.push_back(10 + rand() % 99); // 10 -99
	
	sort(data.begin(), data.end()); // Sort the data
} //End constructor

// Perform binary search on the data
int BinarySearch::binarySearch(int searchElement) const
{
	int low = 0; // Low end of the search area
	int high = size - 1; // High end of the search area
	int middle = (low + high + 1) / 2; // Middle element
	int location = -1; // Return -1 if element is not found
	
	// Loop to searche element
	do	
	{
		// Print remaining elements of vectors to be searched
		displaySubElements(low, high);
		
		// Output spaces for alignment
		for (int i = 0; i < middle; ++i)
			cout << " ";
		
		cout << " * " << endl; // Indicate current middle
		
		// If element is found at the middle
		if (searchElement == data[middle])
			location = middle;
		else if (searchElement < data[middle])
			high = middle - 1;
		else // Middle element is too low
			low = middle + 1;
	
	  middle = (low + high + 1) / 2; // Recalculate middle	
	}while ((low <= high) && location == -1); // End do...while
	
	return location;
} // End Binary Search

// Display vaalue in vector
void BinarySearch::displayElements() const
{
	displaySubElements(0, size - 1);
} // End displayElements

// Display certain value in vector
void BinarySearch::displaySubElements(int low, int high) const
{
	for (int i = 0; i < low; ++i)
		cout << " "; // Output spaces for alignment
	
	for (int i = low; i <= high; ++i) // Output elements in vetor
		cout << data[i] << " ";
	
	cout << endl;
} // End displaySubElements