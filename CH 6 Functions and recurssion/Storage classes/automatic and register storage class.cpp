#include <iostream>

using namespace std;

int main()
{
	register int i;
	/*
		can be used with local variables only and used for 
		variables that require high speed processing such as counters. N.B. 
		This can be ignored completetely especially if the computer does not have enough
		registers
	*/
	
	for(i = 1 ; i <= 50; i++)
		cout << i << endl;
	
	auto int j;
	/*
		Used to declare local variables that are used just within
		the block of where they are declared i.e. between the curly brackets
		for example lets declare a variable inside a while loop. the variable will be destroyed
		as soon as we exit the loop
	*/
	
	//loop 50 times
	while (j <= 50)
	{
		auto int k = 1;
		k++;
		j++;//update counter
		cout << k << endl;//print current k
	}//end loop K is also destroyed here
	
	//expected error
	/*
		You should get the following errors
		1. 'auto' will change meaning in C++0x; please remove it
	    2. 'k' was not declared in this scope
		3. automatic and register storage class.cpp:30: error: 'k' was not declared in this scope
		N.B. error 3 is the original message if you are using mingg++ or g++ compiler
	*/
	cout << k << endl;
}