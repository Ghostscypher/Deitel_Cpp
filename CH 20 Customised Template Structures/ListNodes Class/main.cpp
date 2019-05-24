#include <iostream>
#include <cstdlib>
#include <string>
#include "List.h"
using namespace std;

// Display program option to the user
void displayInstructions()
{
	cout << "\nPlease choose one of the following:\n"
		 << " 1 To insert node at the beginning of list\n"
		 << " 2 To to insert node at the end of the list\n"
		 << " 3 To delete a value from top of list\n"
		 << " 4 To delete a value from bottom of list\n"
		 << " 5 To end list processing\n";
} // End displayInstructions

// Finction to test a list
template<typename T>
void testList(List<T> &listObject, const string &typeName)
{
	cout << "Testing a list of " << typeName << " values.\n";
	
	int choice; // Stores user's choice
	T value; // Store input data
	// List listObject;
	
	do
	{
		// Prompt user to enter choice
		cout << endl;
		displayInstructions();
		
		// Make sure the user enters correct value
		cout << "? ";
		cin >> choice;
		
		switch(choice)
		{
		case 1: // Insert at beginning
			cout << "Enter " << typeName << ": ";
			cin >> value;
			listObject.insertAtFront(value);
			listObject.print();
			break;
		case 2: // Insert at end
			cout << "Enter " << typeName << ": ";
			cin >> value;
			listObject.insertAtBack(value);
			listObject.print();
			break;
		case 3: // Remove from beginning
			if (listObject.removeFromFront(value))
				cout << value << " removed from top of list.";
			
			listObject.print();
			break;
		case 4:
			if (listObject.removeFromBack(value))
				cout << value << " removed from bottom of list.";
			
			listObject.print();
			break;
		case 5:
			cout << "End list test\n";
			return;
			break;
		default:
			cerr << "\nInvalid choice. Try again!...\n" << endl;
			break;
		} // End switch
	} while(1); // End do..while
} // End testList

int main()
{
	// Test list of integers
	List<int> intList;
	testList(intList, "Integer");
	
	// Test list of doubles
	List<double> dblList;
	testList(dblList, "Double");
} // End main