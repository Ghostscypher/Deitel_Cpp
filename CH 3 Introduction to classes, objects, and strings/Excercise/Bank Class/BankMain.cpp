#include <iostream>
#include "Bank.h" //include class Bank

using namespace std;

int main()//start of main function
{
	Bank Bank1(0.00);//create bank object called bank1
	string username;//create username string
	int pin;//pin that the user will input
	int menuselection;//variable used to choose and action
	double money;//flaot data type that will be used to update our class
	
	cout << "Please enter your username: ";
	cin >> username;
	Bank1.welcome(username);
	
	while (Bank1.checkPin(pin) == 1)
	{
		cout << "Please enter your pin to proceed\nPin: ";
		cin >> pin;
		
		if (Bank1.checkPin(pin) == 1)
			cout << "Incorrect pin. Try again" << endl;
	}
	
	//Bank1.printMenu();
	
	while (menuselection != 1 || menuselection != 2 || menuselection != 3 || menuselection != 4) 
	{
		Bank1.printMenu();
		cin >> menuselection;
		
		//decides what to do depending on what the user inputs
		if (menuselection == 1)
		{
			cout << "Please specify the ammount you want to withdraw. KSh: ";
			cin >> money;
			Bank1.withdraw(money);
		}
		else if (menuselection == 2)
		{
			cout << "Please specify the ammount you want to deposit. KSh: ";
			cin >> money;
			Bank1.deposit(money);
		}
		else if(menuselection == 3)
		{
			Bank1.printBalance();
		}
		else if(menuselection == 4)
		{
			cout << "Thank you for using YPA banking system" << endl;
			Bank1.pause();
			return 0;
		}
		else
		{
			cout << "Incorrect number, try again!" << endl;
		}
	}
}//end main function