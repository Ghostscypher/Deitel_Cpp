#include <iostream>
#include <iomanip>
using namespace std;

//start of prototypes
	double getMinimum(double [], int);
	double getMaximum(double [], int);
//end of protoypes

int main()
{
	const int arraySize = 5;
	double a[arraySize] = {};//initialize array to zero
	
	//set format
	cout << setprecision(4) << fixed;
	
	cout << "Enter five numbers to get the maximum and the minimum: " << endl;
	for(int i = 0; i < arraySize; i++)
	{
		cout << "Element [" << i + 1 << "]: "; 
		cin >> a[i];
	}
	cout << "Max: " << getMaximum(a, arraySize) << endl;
	cout << "Min: " << getMinimum(a, arraySize) << endl;
}

double getMinimum(double b[], int arraySize)
{
	double minimumSize = b[0]; //set minimum size to first element
	for(int i = 0; i < arraySize; i++)
	{
		if (b[i] < minimumSize)
			minimumSize = b[i];
	}
	return minimumSize;
}

double getMaximum(double b[], int arraySize)
{
	double maximumSize = b[0]; //set maximum size to first element
	for (int i = 0; i < arraySize; i++)
	{
		if (b[i] > maximumSize)
			maximumSize = b[i];
	}
	return maximumSize;
}