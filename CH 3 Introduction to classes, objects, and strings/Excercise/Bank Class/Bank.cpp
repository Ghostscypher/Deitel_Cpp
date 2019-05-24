#include <iostream>
#include "Bank.h"
#include <iomanip>

using namespace std;

//constructer function
Bank::Bank(double money)
{
	if (acc_balance < 0)
		setAccountBalance(0.00);
	else
		setAccountBalance(money);
}

//functtion to set account balance
void Bank::setAccountBalance(double money)
{
	acc_balance = money;
}

//function to return the current account balance
double Bank::getAccountBalance()
{
	return acc_balance;
}

//function to print the current account balance
void Bank::printBalance()
{
	cout << "Your account balance is: KSh " << setprecision(2) << fixed << getAccountBalance() << endl;
}

//function to welcome the user
void Bank::welcome(string username)
{
	cout << "welcome " << username << " to YPA banking system version 1.2" << endl;
}

//function that checks the if the pin enetered by the user is correct
int Bank::checkPin(int pin)
{
	if (pin != 1234)
	{
		return 1;
	}
}

//function to depopsit cash
void Bank::deposit(double money)
{
	if (money <= 0)//makes sure the user enters a valid ammount of cash to be deposited
	{
		cout << "Please enter an ammount greater than 0";
	}
	else
	{
		setAccountBalance(getAccountBalance() + money);
		cout << "KSh " << setprecision(2) << fixed << money << " has been deposited into your account. Your account balance is now KSh " << setprecision(2) << fixed << getAccountBalance(); 
	}
}

//function to withdraw cash
void Bank::withdraw(double money)
{
	if (getAccountBalance() - money < 0)//make sure that the current account balance does not fall below zero
	{
		cout << "Sorry your account balance is insufficient. Please deposit some cash and try again" << endl;
	}
	else
	{
		setAccountBalance(getAccountBalance() - money);
		cout << "You have withdrawn KSh " << setprecision(2) << fixed << money <<". Your account balance is now KSh " << setprecision(2) << fixed << getAccountBalance() << endl;
	}
}

//function that prints the main menu
void Bank::printMenu()
{
	cout << "\n---To proceed select----" << endl;
	cout << "1. To withdraw" << endl;
	cout << "2. To deposit" << endl;
	cout << "3. To check balance" << endl;
	cout << "4. To exit" << endl;
	cout << "Selection > "; 
}

void Bank::pause()
{
	string enterkey;
	cin >> enterkey;
}