#include <iostream>
#include <fstream>
#include <cstdlib>
#include "ClientData.h"
using namespace std;

int main()
{
	fstream outCredit("Credit.dat", ios::out | ios::binary);
	
	// Exit program if ofStream did not open
	if (!outCredit)
	{
		cerr << "File could not be opened." << endl;
		exit(1);
	} // End if
	
	ClientData blankClient; // Default constructor
	
	// Output 100 blank records for file.
	for (int i = 0; i < 100; ++i)
		outCredit.write(reinterpret_cast<const char *>(&blankClient), sizeof(ClientData));
} // End main