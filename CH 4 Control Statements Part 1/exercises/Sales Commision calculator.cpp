#include <iostream>
#include <iomanip>//stream manipulator

using namespace std;

int main()
{
	double sales; // sales as input by the user
	double salary; //total salary earned
	
	while (sales != -1)
	{
		cout << "\nEnter sales in dollars (-1 to end): ";
		cin >> sales;
		
		salary = 200 + (0.09 * sales);//calculates the total salary earned
		
		if (sales != -1)
		cout << "Salary is: $" << setprecision(2) << fixed << salary;
	}//end of loop
}// end of main function