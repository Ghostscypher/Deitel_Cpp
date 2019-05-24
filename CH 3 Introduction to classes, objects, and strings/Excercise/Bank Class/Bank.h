#include <iostream>
#include <string>

using namespace std;

class Bank
{
	private:
		double acc_balance;
		
	public:
		Bank(double);	
		void setAccountBalance(double);
		double getAccountBalance();
		void printBalance();
		void welcome(string);
		int checkPin(int);
		void deposit(double);
		void withdraw(double);
		void printMenu();
		void pause();
};