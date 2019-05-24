#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include "ClientData.h"
using namespace std;

// Start of prototypes
int enterChoice();
void createTextFile(fstream &);
void updateRecord(fstream &);
void newRecord(fstream &);
void deleteRecord(fstream &);
void outputLine(ostream &, const ClientData &);
int getAccount(const char * const);
// End of prototypes

enum Choices {PRINT = 1, UPDATE, NEW, DELETE, END};

int main()
{
	// OPen file for reading and writing
	fstream ioCredit("credit.dat", ios::in | ios::out | ios::binary);
	
	// Exit program if fstream cannot open file
	if (!ioCredit)
	{
		cerr << "File could not be opened" << endl;
		exit(1);
	} // End if
	
	// Store user's choice
	int choice;
	
	// Enable user to specify action
	while ((choice = enterChoice()) != END)
	{
		switch(choice)
		{
		case PRINT: // Create text file from record file
			createTextFile(ioCredit);
			break;
		case UPDATE: // Update record
			updateRecord(ioCredit);
			break;
		case NEW: // Create new record
			newRecord(ioCredit);
			break;
		case DELETE: // Delete a record
			deleteRecord(ioCredit);
			break;
		default: // Display error message if user doesn't select the correct choice
			cerr << "Incorrect choice" << endl;
			break;
		} // End switch
	} // End while
} // End main

// Enable user to input menu choice
int enterChoice()
{
	// Display available options
	cout << "\nEnter your choice\n" << endl
		 << "1 - Store a formated text file of accounts. Called"
		 << " \"Print.txt\" for printing" << endl
		 << "2 - Update an account" << endl
		 << "3 - Add a new account" << endl
		 << "4 - Delete an account" << endl
		 << "5 - End the program\n?";
		 
	int menuChoice;
	cin >> menuChoice; // Input menu choice from user
	
	return menuChoice;
} // End enterChoice

// Create formatted text file for printing
void createTextFile(fstream &readFromFile)
{
	// Create text file
	ofstream outPrintFile("Print.txt", ios::out);
	
	// Exit program if ofstream cannot open file
	if (!outPrintFile)
	{
		cerr << "File could not be created." << endl;
		exit(1);
	} // End if
	
	outPrintFile << left << setw(10) << "Account" << setw(16)
				 << "Last Name" << setw(11) << "First Name" << right
				 << setw(10) << "Balance" << endl;

	// Set file- position pointer to beggining of readFromFile
	readFromFile.seekg(0);
	
	// Read first record from file
	ClientData client;
	readFromFile.read(reinterpret_cast<char *>(&client), sizeof(ClientData));
	
	// Copy all records from record file into text file
	while (!readFromFile.eof())
	{
		// Write single record to text file
		if (client.getAccountNumber() != 0) // Skip empty records
			outputLine(outPrintFile, client);
		
		// Read next record from record file
		readFromFile.read(reinterpret_cast<char *>(&client), sizeof(ClientData));
	} // End while
} // End createTextFile

// Update balance in record
void updateRecord(fstream &updateFile)
{
	// Obtain account number on which balance is to be updated
	int accountNumber = getAccount("Enter account to update");
	
	// Move file-position pointer to correct record in file
	updateFile.seekg((accountNumber - 1) * sizeof(ClientData));
	
	// Read first record from file
	ClientData client;
	updateFile.read(reinterpret_cast<char *>(&client), sizeof(ClientData));
	
	// Update record
	if (client.getAccountNumber() != 0)
	{
		// Display the record to be changed
		outputLine(cout, client);
		
		// Request user to specify transaction
		cout << "\nEnter (+)balance for charge or (-)balance for payment: ";
		double transaction;
		cin >> transaction;
		
		// Update record balance
		double oldBalance = client.getBalance();
		client.setBalance(oldBalance + transaction);
		outputLine(cout, client); // Print new balances for the account
		
		// Move file-position pointer to correct record in file
		updateFile.seekp((accountNumber - 1) * sizeof(ClientData));
		
		// Write updated record over old record in file
		updateFile.write(reinterpret_cast<char *>(&client), sizeof(ClientData));
	} // End if
	else // Display error if accont does not exist
		cerr << "Account #" << accountNumber
			 << " does not exist." << endl;
} // End updateRecord

// Create and insert record
void newRecord(fstream &insertInFile)
{
	// Obtain number of account to create
	int accountNumber = getAccount("Enter new account number");
	
	// Move file-possition pointer to correct record in file
	insertInFile.seekg((accountNumber - 1) * sizeof(ClientData));
	
	// Read record from file
	ClientData client;
	insertInFile.read(reinterpret_cast<char *>(&client), sizeof(ClientData));
	
	// Create record, if record does not previsously exist
	if (client.getAccountNumber() == 0)
	{
		string lastName, firstName;
		double balance = 0;
		
		// User enters first name, last name and balance
		cout << "Enter lastname, first name, balance\? ";
		cin >> setw(15) >> lastName;
		cin >> setw(10) >> firstName;
		cin >> balance;
		
		// Use values to populate account values
		client.setFirstName(firstName);
		client.setLastName(lastName);
		client.setBalance(balance);
		client.setAccountNumber(accountNumber);
		
		// Move file-position pointer to correct record in file
		insertInFile.seekp((accountNumber - 1) * sizeof(ClientData));
		
		// Insert record into file
		insertInFile.write(reinterpret_cast<const char *>(&client), sizeof(ClientData));
		
		// Show the user that the account was successfully added
		cout << "Account #" << accountNumber << " has been successfully added" << endl;
	} // End if
	else // Display error if account already exists
		cerr << "Account #" << accountNumber
 			 << " already exists." << endl;
} // End newRecord

// Delete an existing record
void deleteRecord(fstream &deleteFromFile)
{
	// Obtain number of account to delete
	int accountNumber = getAccount("Enter account number to delete");
	
	
	// Move file-position pointer to correct record in file
	deleteFromFile.seekg((accountNumber - 1) * sizeof(ClientData));
	
	// Read record from file
	ClientData client;
	deleteFromFile.read(reinterpret_cast<char *>(&client), sizeof(ClientData));
	
	// Delete record if record exists
	if (client.getAccountNumber() != 0)
	{
		// Create a blank client
		ClientData blankClient;
		
		// Move file-position pointer to correct record in file
		deleteFromFile.seekp((accountNumber - 1) * sizeof(ClientData));
		
		// Replace existing record with blank
		deleteFromFile.write(reinterpret_cast<const char *>(&blankClient), sizeof(ClientData));
		
		cout << "Account #" << accountNumber << " deleted.\n";
	} // End if
	else // Display error if record does not exist
		cerr << "Account #" << accountNumber << " does not exist"; 
} // End deleteRecord

// Display single record
void outputLine(ostream &out, const ClientData &record)
{
	out << left << setw(10) << record.getAccountNumber()
		<< setw(16) << record.getLastName()
		<< setw(11) << record.getFirstName()
		<< setw(10) << setprecision(2) << right << fixed
		<< showpoint << record.getBalance() << endl;
} // End outputLine

// Obtain account number value from user
int getAccount(const char * const prompt)
{
	int accountNumber;
	
	do
	{
		cout << "\n" << prompt << " (1- 100): ";
		cin >> accountNumber;
	} while (accountNumber < 1 || accountNumber > 100);
	
	return accountNumber;
} // End getAccount