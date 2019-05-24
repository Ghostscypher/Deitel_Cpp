#include <iostream>

int main()
{
	int number1, number2; //numbers to add together
	
	std::cout << "Enter your first number: ";//prompt user to enter first number
	std::cin >> number1; //read first int
	
	std::cout << "Enter your second number: ";//prompt user to enter second number
	std::cin >> number2;//read second int
	
	std::cout << "The sum of the two numbers is: " << number1 + number2 << std::endl;//print sum; end line
}//end function