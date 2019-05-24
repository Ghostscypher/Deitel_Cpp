#include <iostream>
#include <iomanip>
using namespace std;

/*A recursive function is a function thnat calls itself, either directly
or indirectly through another function. We are going to write a recursive problem
i.e. Factorial of non negative numbers. We are ging to first of all solve this problem
using iterative method. then recursively*/

//start of prototypes
	unsigned long iterativeFactorize(long);
	unsigned long recursiveFactorize(long);
//end of prototypes

int main()//start of main
{
	int number;
	
	cout << "Please input the number you want to find the factorial of: ";
	cin >> number;
	
	cout << "The fatorial using iteration is: " <<  iterativeFactorize(number) << endl;
	cout << "The fatorial using recursion is: " <<  recursiveFactorize(number) << endl;
}//end main

unsigned long iterativeFactorize(long n)//iterative factorial
{
	unsigned long factorial = 1;
	
	if (n < 0)//make sure the number is greater than 0
		return 999;
	
	for (unsigned long i = n; i >= 1; i--)
		factorial *= i;
	
	return factorial;
}

unsigned long recursiveFactorize(long n)//recursive method
{
	if ((n == 1) || (n == 0))//test the base case ehich in this case is 1! = 0 and 0! = 1
		return 1;
	else if (n < 0)
		return 999;
	else
		return n * recursiveFactorize(n -1);
}