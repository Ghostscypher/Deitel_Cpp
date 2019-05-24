#include <iostream>
#include <iomanip>
using namespace std;

//start of prototypes
	void modifyArray(int [], int);
	void modifyElement(int);
//end of prototypes

int main()
{
	const int arraySize = 5;
	int a[arraySize] = {1, 2, 3, 4, 5};
	
	cout << "Effects of passing array by reference" << endl;
	cout << "\nOriginal values: " << endl;
	
	for(int i = 0; i < arraySize; i++)
		cout << setw(3) << a[i];
	
	//pass array to modifyArray() function byRef
	modifyArray(a, arraySize);
	
	//output modified array elements
	cout << "\nAfter modiying by ref" << endl; 
	for(int i = 0; i < arraySize; i++)
		cout << setw(3) << a[i];
	
	//pass modifyArray byval
	cout << "\nBefore modifying a[3]: " << a[3] << endl;
	modifyElement(a[3]);
	cout << "Effects of passing array by value" << endl;
	cout << "After modifying a[3]: " << a[3] << endl; 
}

void modifyArray(int b[], int sizeOfArray)
{
	//b points to array a in memory
	for(int i = 0; i < sizeOfArray; i++)
		b[i] *= 2;
}

void modifyElement(int e)
{
	//note the brackets when printing arithnetic ops directly
	cout << "Value of e in modifyElement function: " << (e *= 2) << endl;
}