#include <string>
#include "ClientData.h"
using namespace std;

// Default client class operator
ClientData::ClientData(int accountNumberValue, string lastName,
						string firstName, double balanceValue)
{
	setAccountNumber(accountNumberValue);
	setLastName(lastName);
	setFirstName(firstName);
	setBalance(balanceValue);
} // End constructor

// Set the account-number value
void ClientData::setAccountNumber(int accountNumberValue)
{
	accountNumber = accountNumberValue;
} // End setAccountNumber

// Get the account-number value
int ClientData::getAccountNumber() const
{
	return accountNumber;
} // End getAccountNumber

// Set last name
void ClientData::setLastName(string lastNameString)
{
	// Copy a maximum of 15 characters to last name
	int length = lastNameString.size();
	length = (length < 15 ? length: 14);
	
	lastNameString.copy(firstName, length);
	lastName[length] = '\0'; // Append null character to last name
} // End setLastName

// Get last name
string ClientData::getLastName() const
{
	return lastName;
} // End getLastName

// Set first name
void ClientData::setFirstName(string firstNameString)
{
	// Copy a maximum of 10 characters to first name
	int length = firstNameString.size();
	length = (length < 10 ? length: 9);
	
	firstNameString.copy(lastName, length);
	lastName[length] = '\0'; // Append null character to first name
} // End setFirstName

// Get first name
string ClientData::getFirstName() const
{
	return firstName;
} // End getFirstName

// Set balance for the account
void ClientData::setBalance(double balanceValue)
{
	balance = balanceValue;
} // End getBalance

// Get balance for the account
double ClientData::getBalance() const
{
	return balance;
} // End getBalance