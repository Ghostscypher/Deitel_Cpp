#include <iostream>
using namespace std;

//start of prototypes
	int sqr(int);//square for integers
	double sqr(double);
//end of prototypes

//function overloading refers to using functions with the same name but different signatures

int main()
{
	cout << "Int version: 2 * 2 = " << sqr(2) << endl;//will use int version of sqr
	cout << "Double version: 2.5 * 2.5 = " << sqr(2.5) << endl;//will use double version of sqr
}//end main

int sqr(int x)
{
	return x * x;
}//end int version of sqr

double sqr(double x)
{
	return x * x;
}//end double version of sqr