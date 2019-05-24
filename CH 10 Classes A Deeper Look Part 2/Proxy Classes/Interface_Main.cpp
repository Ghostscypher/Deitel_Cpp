#include <iostream>
#include "Interface.h"
using namespace std;

int main()
{
	Interface i(5); // Create interface object
	cout << "Interface contains: " << i.getValue() << " before setValue" << endl;
	
	i.setValue(10);
	cout << "\nInterface contains: " << i.getValue() << " after setValue" << endl; 
} // End main