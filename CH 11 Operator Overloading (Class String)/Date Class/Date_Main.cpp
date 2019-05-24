#include <iostream>
#include <cstdlib>
#include "Date.h"
using namespace std;

int main()
{
	Dates d1(12, 27, 2010); // December 27, 2010
	Dates d2; // Defaults to January 1, 1900
	
	cout << "d1 is " << d1 << "\nd2 is " << d2;
	cout << "\nd1 += 7 is: " << (d1 += 7);
	
	d2.setDate(2, 28, 2008);
	cout << "\n\nd2 is " << d2;
	cout << "\n++d2 is " << ++d2 << " (leap year allows 29th)";
	
	Dates d3 (7, 13, 2000);
	
	cout << "\n\nTesting the prefix increment operator:\n"
		 << "++d3 is " << ++d3 << endl;
    cout << "  d3 is " << d3;
    
    cout << "\n\nTesting the postfix increment operator:\n"
		 << "d3++ is " << d3++ << endl;
    cout << "  d3 is " << d3 << endl;
    
    try
	{
		system("\npause");
	}
	catch(...)
	{
		// Empty catch
	} // End try...catch
} // End main