#include <iostream>
#include <iterator>
using namespace std;

int main()
{
	cout << "Enter two integers: ";
	
	// Create istream_iterator for reading int values from cin
	istream_iterator<int> inputInt(cin);
	
	int number = *inputInt; // Read int from standard input
	++inputInt; // Move iterator to next input value
	int number1 = *inputInt; // Read int from standard input
	
	// Create ostream_operator for writing int values to cout
	ostream_iterator<int> outputInt(cout);
	
	// output results of cout
	cout << "The sum is: ";
	*outputInt = number + number1;
	cout << endl; 
} // End main