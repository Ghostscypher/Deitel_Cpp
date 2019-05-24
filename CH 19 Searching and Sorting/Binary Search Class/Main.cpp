#include <iostream>
#include <cstdlib> // Prototype for funtion exit()
#include "BS.h"
using namespace std;

int main()
{
	int searchInt; // Search key
	int position; // Location of search key in vector
	
	// Create vector and output it
	BinarySearch searchVector(15);
	searchVector.displayElements();
	
	// Get search key from user
	cout << "\nPlease enter an integer value (-1 to quit): ";
	cin >> searchInt;
	
	// Exit if user enters an incorrect value
	if (!cin.good())
	{
		cerr << "\nIncorrect value entered quitting..." << endl;
		exit(1);
	} // End if
	
	// Infinite loop to serach for an integer value -1 to quit
	while (searchInt != - 1)
	{
		// Use binary search to try and find integer
		position = searchVector.binarySearch(searchInt);
		
		// Returns -1 if no index was found
		if (position == -1)
			cout << "The integer " << searchInt << " was not found";
		else
			cout << "The integer " << searchInt << " was found at " << position << endl;
		
		// Get search key from user
		cout << "\nPlease enter an integer value (-1 to quit): ";
		cin >> searchInt;
		
		// Exit if user enters an incorrect value
		if (!cin.good())
		{
			cerr << "\nIncorrect value entered quitting..." << endl;
			exit(1);
		} // End if
	} // End while
} // End main