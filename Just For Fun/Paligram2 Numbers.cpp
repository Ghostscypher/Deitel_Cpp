#include <iostream>
using namespace std;

int main()
{
	long number = 1221;
	long digit;
	int reverse = 0;
	
	while(number != 0)
	{
		digit = number % 10;
		reverse = (reverse * 10) + digit;
		
		number /= 10;
	}
	
	cout << reverse << endl;
}