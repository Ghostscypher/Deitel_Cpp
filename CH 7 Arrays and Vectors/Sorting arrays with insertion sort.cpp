#include <iostream>
#include <iomanip>
using namespace std;

/*I think I have understodd this*/

int main()
{
	const int arraySize = 10;
	int data[arraySize] = {12, 560, 45, 104, 747, 1511, 923, 320, 55, 1};
	int insert = 0;//temporary element to hold data to swap
	
	cout << "This is the unsorted array" << endl;
	
	for(int i = 0; i < arraySize; i++)
		cout << data[i] << " ";
	
	//insertion sort
	//loop over the elements of the arrays i.e. arraysize - 1
	for(int i = 1; i < arraySize; i++)
	{
		insert = data[i];
		int moveitem = i;//initialize location ti place element
		
		//search for location in which to put the current element
		while((moveitem > 0) && (data[moveitem - 1] > insert))
		{
			//shift element one slot to the right
			data[moveitem] = data[moveitem - 1];
			moveitem--;
		}
		data[moveitem] = insert;
	}//end of sort
	
	cout << "\nThis is the sorted array" << endl;
	
	for(int i = 0; i < arraySize; i++)
		cout << data[i] << " ";
}