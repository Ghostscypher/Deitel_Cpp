#include <iostream>
#include "Increment.h"
using namespace std;

int main()
{
	Increment value(10, 5);
	
	cout << "Before Incrementing: " << endl;
	value.print();
	
	cout << "Start of incrementing" << endl;
	
	for(int i = 0; i <= 10; i++) //loop ten times
	{
		value.addIncrcement();
		value.print();
	} //end loop
} //end main