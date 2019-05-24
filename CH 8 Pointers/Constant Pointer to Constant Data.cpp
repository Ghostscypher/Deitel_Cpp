#include <iostream>
using namespace std;

int main()
{
	int x = 5, y;
	
	const int * const Ptr = &x;
	cout << *Ptr << endl;
	
	//the following lines will give an error
	*Ptr = 7;
	Ptr = &y;
}