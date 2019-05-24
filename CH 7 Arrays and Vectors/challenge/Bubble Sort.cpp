#include <iostream>
using namespace std;

int main()
{
	int numSize = 0;
	double insert = 0;//holds the value of data temporarily
	
	cout << "How many numbers do you want to sort: ";
	cin >> numSize;
	
	const int arraySize = numSize;
	double dataArray[arraySize];//initialize our array
	
	//fill in data for x numof arrays
	cout << "\nPlease enter " << numSize << " numbers" << endl;
	
	for(int i = 0; i < arraySize; i++)
	{
		cout << "Number [" << i + 1 << "]: ";
		cin >> dataArray[i];
	}
	
	//print the unsorted rrays
	cout << "\nThis is the unsorted data" << endl; 
	
	for(int i = 0; i < arraySize; i++)
		cout << dataArray[i] << " ";
	
	//sort data using insertion
	for(int i = 1; i < arraySize; i++)
	{
		insert = dataArray[i];
		
		int moveNext = i;//initialize our variable
		while((moveNext > 0) && (dataArray[moveNext - 1] > insert))
		{
			dataArray[moveNext] = dataArray[moveNext - 1];
			moveNext--;
		}
		dataArray[moveNext] = insert;
	}
	
	//print sorted array
	cout << "\nThe sorted arrays are" << endl;
	
	for(int i = 0; i < arraySize; i++)
		cout << dataArray[i] << " ";
	
	//flush buffer
	cout << endl;
}