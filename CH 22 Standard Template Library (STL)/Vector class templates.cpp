#include <iostream>
#include <vector>
using namespace std;

// Prototype for function template printVector
template<typename T> void printVector(const vector<T> &);

int main()
{
	const int SIZE = 6; // Define array size
	
	// Declare and initialize array
	int array[SIZE] = {1, 2, 3, 4, 5, 6};
	
	vector<int> integers; // Create vector of ints
	
	cout << "The initial size of integers is: " << integers.size()
		 << "\nThe initial capacity of integers is: " << integers.capacity();
		 
	// Function push_back is in every sequence container and is used to input
	// data at the back of a vector
	integers.push_back(2);
	integers.push_back(3);
	integers.push_back(4);
	
	cout << "\nThe new size of integers is: " << integers.size()
		 << "\nThe new capacity of integers is: " << integers.capacity();
		 
	// Output array using pointer notation
	cout << "\nOutput array using pointer notation: ";
	for (int *ptr = array; ptr != array + SIZE; ++ptr)
		cout << *ptr << ' ';
	
	cout << "\nOutput vector array using iterator notation: ";
	printVector(integers);
	
	// Two const revese_iterators
	cout << "\nReversed contents of vector integers: ";
	vector<int>::const_reverse_iterator reverseIterator;
	vector<int>::const_reverse_iterator tempIterator = integers.rend();
	
	// Display vectors in revese using revese_iterator
	for (reverseIterator = integers.rbegin(); reverseIterator != tempIterator; ++reverseIterator)
		cout << *reverseIterator << ' ';
	
	cout << endl;
} // End main

// Function template for outputting vector elements
template<typename T>
void printVector(const vector<T> &integer)
{
	typename vector<T>::const_iterator constIterator; // const_iterator
	
	// Display vector elements using const_iterator
	for (constIterator = integer.begin(); constIterator != integer.end(); ++constIterator)
		cout << *constIterator << ' ';
} // End printVector