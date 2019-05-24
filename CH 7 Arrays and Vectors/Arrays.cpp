#include <iostream>
#include <iomanip>
using namespace std;

int main()
{	
	//this is an array that has not been initialized
	int indexes[10];
	//initialize the array using loop
	//loop ten times
	for(int i = 0; i < 10; i++)
		indexes[i] = i;	//assign value to the arrays
	
	//print the values which we had initialized
	cout << "Elements" << setw(18) << "Value" << endl;
	//use loop to print value of each elemtn in the array
	for(int j = 0; j < 10; j++)
	{
		cout << "Element ["<< j <<"]" << setw(12) << indexes[j] << endl;
	}
}//end main