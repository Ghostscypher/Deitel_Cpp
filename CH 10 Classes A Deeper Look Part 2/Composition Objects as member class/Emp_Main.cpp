#include <iostream>
#include "Emp.h" // employee class definition
using namespace std;

int main()
{
	Date birth(7, 24, 1949); // initialize birth as date object
	Date hire(3, 12, 1998); // initialize hire as date object
	
	Employee manager("Bob", "Blue", birth, hire); //initialize manager as Employee object
	
	cout << endl;
	manager.print();
} // end main