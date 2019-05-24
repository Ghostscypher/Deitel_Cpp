#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdlib>
using namespace std;

// Global variables
enum RequestType
{
	ZERO_BALANCE = 1,
	CREDIT_BALANCE,
	DEBIT_BALANCE,
	END 
};

// Start of prototype
	int getRequest();
	bool shouldDisplay(int, double);
	void outputLine(int, const string, double);
// End of prototype

int main()
{
	// ifstream constructor opens the file
	ifstream inClientsFile("Clients.txt", ios::in);
	
	// Exit the program if ifstream was unable to open the file
	if (!inClientsFile)
	{
		cerr << "File could not be opened" << endl;
		exit(1);
	} // End if
	
	int request, account;
	string name;
	double balance;
	
	// Get user request (e.g. zero, credit or debit)
	request = getRequest();
	
	// Process user's request
	while (request != END)
	{
		switch (request)
		{
		case ZERO_BALANCE:
			cout << "\nAccount with zero balance: \n";
			break;
		case CREDIT_BALANCE:
			cout << "\nAccount with credit balances: \n";
			break;
		case DEBIT_BALANCE:
			cout << "\nAccount with debit balances: \n";
			break;
		default:
			break;
		} // End switch
	
		// Read account, name and balance
		inClientsFile >> account >> name >> balance;
		
		// Read file contents until eof
		while (!inClientsFile.eof())
		{
			if (shouldDisplay(request, balance))
				outputLine(account, name, balance);
			
			// Read account, name and balance
			inClientsFile >> account >> name >> balance;
		} // End inner while
		
		inClientsFile.clear(); // Reset eof for next input
		inClientsFile.seekg(0); // Reposition to beginning of file
		request = getRequest();
	} // End outer while
	
	cout << "End of run" << endl;
} // End main

// Obtain request from user
int getRequest()
{
	int request; // Request from user
	
	// Display request options
	cout << "\nEnter request" << endl
		 << "1 - List accounts with zero balances\n"
		 << "2 - List accounts with credit balance\n"
		 << "3 - List accounts with debit balance\n"
		 << "4 - End of run\n" << fixed << showpoint;
		 
	// Input user request
	do
	{
		cout << "\n? ";
		cin >> request;
	} while(request < ZERO_BALANCE && request > END);
	
	return request;
} // End getRequest

// Determine whether to display given record
bool shouldDisplay(int type, double balance)
{
	// Dertermine whether to display zero balances
	if (type == ZERO_BALANCE && balance == 0)
		return true;
	
	// Determine whether to display credit balance
	if (type == CREDIT_BALANCE && balance < 0)
		return true;
	
	// Determine whether to display debit balances
	if (type == DEBIT_BALANCE && balance > 0)
		return true;
	
	return false;
} // End shouldDisplay

// Display single record from file
void outputLine(int account, const string name, double balance)
{
	cout << left << setw(10) << account << setw(13) << name
		 << setw(7) << setprecision(2) << right << balance << endl;	
} // End outputLine