#include <iostream>
#include <fstream>
#include <cstdlib>
#include "ClientData.h"
using namespace std;

int main()
{
	int accountNumber;
	string lastName;
	string firstName;
	double balance;
	
	fstream outCredit("Credit.dat", ios::in | ios::out | ios::binary);
	
	// Exit program if ofStream did not open
	if (!outCredit)
	{
		cerr << "File could not be opened." << endl;
		exit(1);
	} // End if
	
	// Require user to specify account number
	ClientData client;
	cout << "Enter account number\n? ";
	cin >> accountNumber;
	
	// User enters information which is copied into file
	while (accountNumber > 0 && accountNumber <= 100)
	{
		cout << "\nEnter Last Name, First Name and balance\n?";
		cin >> lastName;
		cin >> firstName;
		cin >> balance;
		
		// Set record Account Number, Last Name, First Name, and balance
		client.setAccountNumber(accountNumber);
		client.setLastName(lastName);
		client.setFirstName(firstName);
		client.setBalance(balance);
		
		// Seek position in file of user-specified record
		outCredit.seekp((client.getAccountNumber() - 1) * sizeof(ClientData));
		
		// Write user specified information in file
		outCredit.write(reinterpret_cast<const char *>(&client), sizeof(ClientData));
		
		// Enable user to enter another account number
		cout << "Enter account number\n? ";
		cin >> accountNumber;
	} // End while
} // End main