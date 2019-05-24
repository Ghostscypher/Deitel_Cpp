#ifndef CLIENTDATA_H
#define CLIENTDATA_H

#include <string>
using namespace std;

class ClientData
{
public:
	ClientData(int = 0, string = "", string = "", double = 0.0); // Default class constructor
	
	// Accessor functions for accountNumber
	void setAccountNumber(int);
	int getAccountNumber() const;
	
	// Accessor functions for last name
	void setLastName(string);
	string getLastName() const;
	
	// Accessor functions for first name
	void setFirstName(string);
	string getFirstName() const;
	
	// Accessor functions for balance
	void setBalance(double);
	double getBalance() const;
private:
	int accountNumber;
	char lastName[15];
	char firstName[10];
	double balance;
}; // End class client data

#endif