#include <iostream>
#include <iomanip>//stream manipulator

using namespace std;

int main()
{
	double hourly_rate, salary, hours_worked;
	
	//start of loop
	while (hours_worked != -1)
	{
		cout << "\nEnter hours worked (-1 to quit): ";
		cin >> hours_worked;
		
		//exit if the user has enetered sentinel value i.e. -1
		if (hours_worked == -1)
			return 0;
		
		cout << "Enter hourly rate of the employee ($00.00): ";
		cin >> hourly_rate;
		
		//calculate salary based on whether employee has worked more than 40 hrs
		if (hours_worked <= 40)
			salary = hourly_rate * hours_worked;
		else
			salary = ((40 * hourly_rate) + ((1.5 * hourly_rate) * (hours_worked - 40)));
			  
			//print the result		
			cout << "Salary is $" << setprecision(2) << fixed << salary; 
	}//end while
}//end main