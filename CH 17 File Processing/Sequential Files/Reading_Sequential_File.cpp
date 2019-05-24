// Reading and printing sequential file
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdlib>
using namespace std;

// Start of prototypes
	void outputLine(const int &, const string &, const double &);
// End of prototypes

int main()
{
	// ifstream opens the file for input
	ifstream inClientFile("Clients.txt", ios::in);
	
	// Exit program if ifstream could not open file
	if (!inClientFile)
	{
		cout << "File could not be opened" << endl;
		exit(1);
	} // End if
	
	// Declare variables
	int accountNumber = 0; // Account Number. Default number 0. Never Reached
	string name;
	double balance = 0;
	
	cout << left << setw(10) << "Account" << setw(13)
		 << "Name" << "Balance" << endl << fixed << showpoint;
		 
	// Display each record in file
	while (!inClientFile.eof())
	{
		inClientFile >> accountNumber >> name >> balance;
		outputLine(accountNumber, name, balance);
	} // End while
} // End main

// Display single record from file
void outputLine(const int &accountNumber, const string &name, const double &balance)
{
	cout << left << setw(10) << accountNumber << setw(13) << name
		 << setw(7) << setprecision(2) << right << balance << endl;	
} // End outputLine