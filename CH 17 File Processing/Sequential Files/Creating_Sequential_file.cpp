#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

int main()
{
	// ofsteream constructor opens files
	ofstream outClientFile("clients.txt", ios::out);
	
	// Exit program if unable to create client file
	if (!outClientFile) // Overloaded ! operator
	{
		cerr << "File could not be opened" << endl;
		exit(1);
	} // End if
	
	// If successfull continue. Prompt user to enter account number, name and balance
	cout << "Enter account name and balance." << endl
		 << "Enter End-Of-File to end input\n? ";
		 
	// Declare variables
	int accountNumber = 0; // Default account number. Never used
	string name;
	double balance = 0.0;
	
	// Read account number, name, and balance
	while (cin >> accountNumber >> name >> balance)
	{
		outClientFile << accountNumber << ' ' << name << ' ' << balance << endl;
		cout << "? ";
	} // End while
} // End main