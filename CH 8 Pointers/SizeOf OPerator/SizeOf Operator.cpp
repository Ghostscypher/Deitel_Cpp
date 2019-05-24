#include <iostream>
using namespace std;

//Start of prototyes
	size_t getSize(double *);
//end of prototypes

int main()
{
	double array[20];
	cout << "The number of bytes in the array is: " << sizeof(array) << endl;
	cout << "\nThe number of bytes returned by getSize function is: " << getSize(array) << endl;
}

size_t getSize(double *Ptr)
{
	return sizeof(Ptr);
}