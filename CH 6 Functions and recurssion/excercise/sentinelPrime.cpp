#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

inline bool cip(int number)
{	
	//check whether numbers are prime using modulus
	//for numbers less than 10
	if (number < 10)
	{
		if (number == 1)
			return false;
		
		if (number == 2 || number == 3 || number == 5 || number == 7)
		return true;
	else
		return false;
	}
	//for numbers greater than 10
	if (((number % 2) == 0) || ((number % 3) == 0) || ((number % 5) == 0) || ((number % 7) == 0))
		return false;
	else
		return true;
}

int main()
{
	int n = 0;
	while (n != -1)
	{
		cout << "Enter number (-1 to quit 0 to cls): ";
		cin >> n;
		
		if (n == -1)
			break;
		
		if (n == 0)
		{
			system("cls");
			continue;
		}
		
		
		if (cip(n) == true)
			cout << "Is prime" << endl;
		else
			cout << "Not prime" << endl;
	}	
}