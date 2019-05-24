#include <iostream>
using namespace std;

//start of prototypes
	int cubeByValue(int);
	void cubeByReference(int *);
//end of prototypes

int main()
{
	int x = 2;
	cout << "The original valjue of x is: " << x << endl;
	x = cubeByValue(x);//pass argument by value
	cout << "The new value of x after cubing is: " << x << endl; 
	cubeByReference(&x);//pass value by reference using pointers
	cout << "The new value of x after cubing by reference is: " << x << endl;
}

int cubeByValue(int y)
{
	return y *= y * y;
}

void cubeByReference(int *xPtr)
{
	*xPtr *= *xPtr * *xPtr;
}