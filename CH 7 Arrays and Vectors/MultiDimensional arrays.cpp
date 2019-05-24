#include <iostream>
using namespace std;

/*Multidimensional arrays can be initialized as a list
or use of nested loop e.g. as shown below*/

int main()
{
	const int arr_col_size = 2;
	const int arr_row_size = 2;
	int myArr[arr_row_size][arr_col_size] = {{0, 1}, {1, 2}};
	
	//print the above using nested loop
	for(int i = 0; i < arr_row_size; i++)
		for(int j = 0; j < arr_col_size; j++)
			cout << "Element [" << i << "][" << j<< "]:" << myArr[i][j] << endl;
}