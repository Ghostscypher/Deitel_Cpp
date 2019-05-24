#include <iostream>
#include <iomanip>
using namespace std;

//start of prototypes
	int linearSearch(const int [], int, int);
//end of prototypes

/*Linear search works well with small arrays*/

int main()
{
	const int arraySize = 100;
	int someData [arraySize] = {};//initialize our arrays
	int element = 0;
	//create some data
	for(int i = 1; i <= arraySize; i++)
		someData[i] = i * 2;
	
	do
	{
	cout << "Enter the number you want to search (-99 to quit): ";
	cin >> element;
	
	if(element == -99)
		break;
	
	element = linearSearch(someData, arraySize, element);
	//use our function to search the results
	if (element != -1)
		cout << "Element found in key number " << element << endl;
	else
		cout << "Element not found!" << endl;
	}
	while(true);
}

int linearSearch(const int b[], int arraySize, int key)
{
	for(int i = 0; i < arraySize; i++)
	{
		if(b[i] == key)
			return i; 
	}
	return -1;//if element is not found
}