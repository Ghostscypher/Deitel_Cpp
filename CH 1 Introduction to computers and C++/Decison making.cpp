#include <iostream>

using std::cout;//program uses cout
using std::cin;//pg uses cin
using std::endl;//pg uses endl

int main()//entering main function
{
	int number1, number2;//declaring two integers to use
	
	cout << "Enter two numbers to compare: ";//prompts user to enter both numbers
	cin >> number1 >> number2;//reads both numbers
	
	cout << "The numbers are: " << number1 << " and " << number2 << endl;//debugging purposes only
	//starting conditions
	if (number1 == number2)
		cout << "Both numbers are equal" << endl;
		
	if (number1 != number2)
		cout << "The numbers are not equal" << endl;
	
	if (number1 < number2)
		cout << "Number1 is lesser than number 2" << endl;
	
	if (number1 > number2)
		cout << "Number 1 is grater than number 2" << endl;
	
	if (number1 >= number2)
		cout << "Number 1 is greater than or equal to number 2" << endl;
	
	if (number1 <= number2)
		cout << "Number 1 is less than or equal to number 2" << endl;
	
	else
		cout << "MMMh! I could not compare the values, there must be an invalid value." << endl;
	// Finished the conditions
} // End program