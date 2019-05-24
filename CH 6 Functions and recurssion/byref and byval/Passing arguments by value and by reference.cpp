#include <iostream>
using namespace std;

//function prototypes
	double squareByValue(double);
	void squareByReference(double &);
//end of protypes

int main()
{
	double x = 2.6;//value to square by value (visual studio name byval)
	double y = 4.4;//value to square by reference (visual studio name byref)

	//evaluate results based on our two functions and print results	
	cout << x << " squared by value is: " << squareByValue(x) << endl;
	cout << y << " squared by reference is: ";
	squareByReference(y);/*call the function here then the new value of y is
	automaticaly updated */
	cout << y << endl;//print new value of y
}//end main

/*squareByVal calculates the square and stores the result in x then returns
the new value of x*/
double squareByValue(double x)
{
	return x *= x;//caller argument not modified
}//end squareByValue 

/*it multiplies y reference by itself and and store the result in the variable 
to which yRef refers to the function main*/
void squareByReference(double &y)
{
	y *= y;//caller argument modified
}//end squareByReference