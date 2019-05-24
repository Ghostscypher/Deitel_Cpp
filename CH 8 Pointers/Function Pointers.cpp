#include <iostream>
#include <iomanip>
using namespace std;

//start of prototypes
	void selectionSort(int [], const int, bool (*)(int, int));
	void Swap(int * const, int * const);
	bool ascending(int, int);
	bool descending(int, int);
//end of prototypes

int main()
{
	const int arraySize = 10;
	int order;//1 = ascending, 2 = descending
	int a[arraySize] = { 2, 4, 6, 8, 10, 12, 89, 68, 45, 37};
	
	cout << "Enter\n1 to sort in ascending order\n2 to sort in descending order" << endl;
	cout << "Order: ";
	cin >> order;
	cout << "\nThis is the original list: " << endl;
	
	//output original array
	for(int i = 0; i < arraySize; i++)
		cout << a[i] <<" ";
	
	cout << endl;
	
	/*sort array in ascending order. Pass function ascending 
       as an argument to specify ascending order*/
       
       if(order == 1)
	   {
		   selectionSort(a, arraySize, ascending);
		   cout << "\nData items in ascending order:" << endl;
	   }
	   else
	   {
		   selectionSort(a, arraySize, descending);
		   cout << "\nData items in descending order:" << endl;
	   }  
	   
	   //output sorted array
	   for(int i = 0; i < arraySize; i++)
	   		cout << a[i] <<" ";
}

void selectionSort(int b[], int arraySize, bool (*compare)(int , int))
{
	int s_Or_l;//index of smallest or largest element
	for(int i = 0; i < arraySize - 1; i++)
	{
		s_Or_l = i;
		for(int j = i + 1; j < arraySize; j++)
		{
			if(!(*compare)(b[s_Or_l], b[j]))
				s_Or_l = j;
			
		}
		Swap(&b[i], &b[s_Or_l]);
	}
}

void Swap(int * const aPtr, int * const bPtr)
{
	int hold = *aPtr;
	*aPtr = *bPtr;
	*bPtr = hold;
}

bool ascending(int a, int b)
{
	return a < b;//returns true if a < b or b > a
}

bool descending(int a, int b)
{
	return a > b;//returns true if b < a or a > b
}