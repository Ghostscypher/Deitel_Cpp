#include <iostream>
#include "overloaded.h"
using namespace std;

int main()
{
	Over o; // Intialize a class over object
	
	// Prompt user to eneter word with prefix
	cout << "Please enter the word in the form 'pre-word': ";
	cin >> o;
	
	// Print everything
	cout << o;
} // End main