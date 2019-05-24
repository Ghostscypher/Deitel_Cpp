#include <iostream>
#include "Date.h"
using namespace std;

int main()
{
	Date date1(10, 29, 1458);//set date1
	Date date2;//date defaults
	
	cout << "Date1: ";
	date1.print();
	
	cout << "Date2: ";
	date2.print();
	
	date2 = date1;//default memberwise assignment
	
	cout << "\n\nAfter default memberwise assignment date2: ";
	date2.print();
}