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
	int m = 0, j;
	
	cout << "Enter upperbound limits of the prime loop i.e. upto: ";
	cin >> j;
	for (int i = 1; i <= j; i++)
	{
		if (cip(i) == true)
		{
			cout << i << endl;
			m++;
		}
	}
	cout << "M: " << m << endl;
}