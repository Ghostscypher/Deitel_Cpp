#include <iostream>
using namespace std;

//start of prototypes
	unsigned long fibonacci(unsigned long);//recursive4
	unsigned long ifibonacci(unsigned long);//iterative
//end of prototypes

int main()
{	
	int x;
	
	cout << "Enter fib sequence you want to find: ";
	cin >> x;
	//to show sequence loop 20 times
	for (int i = 0; i <= x; i++)
	{
		//cout << "Fib(" << i << ") = " << fibonacci(i) << endl;
		cout << "iFib(" << i << ") = " << ifibonacci(i) << endl;
	}
}//end main

unsigned long fibonacci(unsigned long n)
{
	if ((n == 0) || (n == 1))//base case
		return n;
	else
		return fibonacci(n -1) + fibonacci(n - 2);
}//end recursiove fib

unsigned long ifibonacci(unsigned long n)
{
	unsigned long a = 0;
	unsigned long b = 1;
	unsigned long c;
	
	if ((n == 0) || (n == 1))
		return n;
	
	//you can use
/*	do
	{
		c = a + b;
		a = b;
		b = c;
		n --;
	}while (n > 1);*/
	
	//or
/*	for (unsigned long i = 1; i < n; i++)
	{
		c = a + b;
		a = b;
		b = c;
	}*/
	
	//or 
	
	for (unsigned long i = n; i > 1; i--)
	{
		c = a + b;
		a = b;
		b = c;
	}
	return c;
	
	/*N.B. Iterative method is fast compared to recussion. Recursion can be ued for small values*/
}//end iterative fib