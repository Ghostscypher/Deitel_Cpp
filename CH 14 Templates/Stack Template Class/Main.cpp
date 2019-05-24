#include <iostream>
#include "Stack.h"
using namespace std;

int main()
{
	Stack<double> doubleStack(5); // Size 5
	double doubleValue = 1.1;
	
	cout << "Pushing elements onto doubleStack\n";
	
	// Push 5  doubles into stack
	while (doubleStack.push(doubleValue))
	{
		cout << doubleValue << ' ';
		doubleValue += 1.1;
	} // End while
	
	cout << "\nStack is full. Cannot push " << doubleValue
		 << "\n\nPopping elements from doubleStack\n";
		 
	// Pop elements from doubleStack
	while(doubleStack.pop(doubleValue))
		cout << doubleValue << ' ';
		
	cout << "\nStack is empty. Cannot pop\n";
	
	Stack<int> intStack; // Default size 10
	int intValue = 1;
	cout << "Pushing elements onto intStack\n";
	
	// Push 5  doubles into stack
	while (intStack.push(intValue))
	{
		cout << intValue << ' ';
		intValue += 1.1;
	} // End while
	
	cout << "\nStack is full. Cannot push " << intValue
		 << "\n\nPopping elements from intStack\n";
		 
	// Pop elements from doubleStack
	while(intStack.pop(intValue))
		cout << intValue << ' ';
		
	cout << "\nStack is empty. Cannot pop" << endl; 
} // End main