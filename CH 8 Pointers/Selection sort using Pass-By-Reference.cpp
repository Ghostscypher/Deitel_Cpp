#include <iostream>
#include <iomanip>
using namespace std;

//start of prototypes
	void selectionSort(int * const, const int);
	void Swap(int * const, int * const);
//end of prototypes

int main()
{
		const int arraySize = 10;
		int a[arraySize] = { 2, 6, 4, 8, 10, 12, 89, 68, 45, 37};
		cout << "This is the data of the array before being sorted" << endl;
		
		for(int i = 0; i < 10; i++)
			cout << a[i] << " ";
		
		selectionSort(a, arraySize);//sort by reference
		
		cout << "\nData items after being sorted in ascending order" << endl;
		
		for(int i = 0; i < 10; i++)
			cout << a[i] << " ";
		
		cout << endl;
}

void selectionSort(int * const array, const int size)
{
	int smallest;//index of the smallest element in the array
	//loop size - 1 times
	for(int i = 0; i < size - 1; i++)
	{
		smallest = i;//first index of remaining array
		for(int j = i + 1; j < size; j++)
		{
			if (array[j] < array[smallest])
				smallest = j;
			
			Swap(&array[i], &array[smallest]);//swap values by reference
		}
	}
}
//swap elements at memory locations
void Swap(int * const element1Ptr, int * const element2Ptr)
{
	int hold = *element1Ptr;
	*element1Ptr = *element2Ptr;
	*element2Ptr = hold;
}//end of swap