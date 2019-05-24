#include <iostream>
#include <string>
#include "Stack.h"
using namespace std;

// Function template to manipulate T
template <typename T>
void testStack(
Stack<T> &theStack, // Reference to Stack<T>
T value, // Initial value to push
T increment, // Increment for subsequent values
const string stackName) // Name of stack<T> objects
{
	cout << "\nPushing elements onto " << stackName << "\n";
	
	// Push element onto stack
	while (theStack.push(value))
	{
		cout << value << ' ';
		value += increment;
	} // End while
	
	cout << "\nStack is full. Cannot push: " << value
		 << "\n\nPopping elements from " << stackName << "\n";
		 
	// Pop elements off the stack
	while (theStack.pop(value))
		cout << value << ' ';
	
	cout << "\nStack is empty. Cannot pop" << endl;
} // End function template testStack

int main()
{
	// Initialize class Stack objects
	Stack<double>doubleStack(5); // Size of stack = 5
	Stack<int>intStack; // Default size of stack = 10
	
	testStack(doubleStack, 1.1, 1.1, "doubleStack");
	testStack(intStack, 1, 1, "intStack");
} // End main