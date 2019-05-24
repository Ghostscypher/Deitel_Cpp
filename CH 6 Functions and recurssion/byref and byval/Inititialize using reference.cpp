#include <iostream>
using namespace std;

int main()
{
	int x = 0;
	int &y = x;//yRef is an alias of i
	
	//print values of x and y before modification 
	cout << "Before modification x: " << x << " Y: " << y << endl;

	//modify y which modifies x
	y = 7;
	
	int k = hrefx;
	cout << k << endl;
	
	//print values after modificaation;
	cout << "After modification x: " << x << " Y: " << y << endl;
	
}//end main