#include <iostream>
#include "PN.h"
using namespace std;

int main()
{
	PhoneNumber p; // Create PhoneNumber class object
	char confirm; // Character to be used to confirm if phone number is correct
	 
L1:	cout << "Please input your phone number in the format +000 - 000 - 000000" << endl;
	cout << "Phone Number: ";
	cin >> p;
	
	cout << "Your Phone number is: " << p;
L2:	cout << "\nIs this correct (Y/N): ";
	cin >> confirm;
	
	// Await the user to confirm if Phone Number is correct
	if (confirm == 'N' || confirm == 'n') // Incorrect Phone Number
		goto L1;
	else if (confirm == 'Y' || confirm == 'y') // Correct Phoe Number
		return 0;
	else // Any other choice
	{
		cout << "Incorrect choice try again" << endl;
		goto L2;
	}
	// End if
} // End main