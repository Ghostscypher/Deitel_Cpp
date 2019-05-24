#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include "ClientData.h"
using namespace std;

// Start of prototypes
	void outputLine(ostream &, const ClientData &);
// End of prototypes

int main()
{
	ifstream inCredit("Credit.dat", ios::in | ios::binary);
	
	// Exit program if ofStream did not open
	if (!inCredit)
	{
		cerr << "File could not be opened." << endl;
		exit(1);
	} // End if
	
	cout << setw(10) << "Account" << setw(16) << "Last Name" << setw(11)
		 << "First Name" << left << setw(10) << "Balance" << endl;
		 
	// Create record
	ClientData client;
	
	// Read first record from file
	inCredit.read(reinterpret_cast<char *>(&client), sizeof(ClientData));
	
	// Read all records from file
	while (inCredit && !inCredit.eof())
	{
		// Display record
		if (client.getAccountNumber() != 0)
			outputLine(cout, client);
		
		// Read next from file
		inCredit.read(reinterpret_cast<char *>(&client), sizeof(ClientData));\
	} // End while
} // End main

// Display single record
void outputLine(ostream &out, const ClientData &record)
{
	out << left << setw(10) << record.getAccountNumber()
		<< setw(16) << record.getLastName()
		<< setw(11) << record.getFirstName()
		<< setw(10) << setprecision(2) << right << fixed
		<< showpoint << record.getBalance() << endl;
} // End outputLine