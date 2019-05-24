#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	char c;
	int i;
	double d;
	short s;
	long l;
	float f;
	long double ld;
	int array[20];
	int *arrayPtr = array;
	
	system("color b");
	cout << "Size of character: " << sizeof(c) << endl;
	cout << "Size of Integer: " << sizeof(i) << endl;
	cout << "Size of Short: " << sizeof(s) << endl;
	cout << "Size of long: " << sizeof(l) << endl;
	cout << "Size of long double: " << sizeof(ld) << endl;
	cout << "Size of float: " << sizeof(f) << endl;
	cout << "Size of array: " << sizeof(array) << endl;
	cout << "Size of arrayPtr: " << sizeof(arrayPtr) << endl;
	cout << "Size of double: " << sizeof(d) << endl;
	cout << "Number of elements in the array: " << (sizeof(array) / sizeof(arrayPtr)) << endl;
}