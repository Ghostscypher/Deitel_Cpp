#include <iostream>
using namespace std;

const int rows = 2;
const int columns = 3;
	
void printArray(const int b[][columns])
{
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < columns; j++)
			cout << b[i][j] << " ";
		
		cout << endl;
	}
	cout << endl << endl;
}

int main()
{
	
	int myArr[rows][columns] = {{0, 1, 2}, {3, 4, 5}};
	int myArr1[rows][columns] = {{0, 1, 2,}, {3}};
	int myArr2[rows][columns] = {{0, 1}, {3}};
	
	printArray(myArr);
	printArray(myArr1);
	printArray(myArr2);
}