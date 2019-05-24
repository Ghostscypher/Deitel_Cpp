//HBD.cpp
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

// Start of prototypes
	void print(string, int = 1); // Initialize the default value to 1
// End of prototypes

int main()
{
	// Change color of prompt to blue
	try
	{
		system("color b");
	}
	catch(...)
	{
		// Empty catch		
	} //End try ... catch
	
	int age = 0; // Initialize age
	
	// Time
	time_t now = time(0); // Get current date from system (Windows only)
	string today = ctime(&now);
	today = today.substr(4,6); // Format time to get only current month and date
							  // in the form mmm dd
	
	string birthday_boy = "Luiz Darwin"; // Self explanatory
	
	cout << "*********************************" << birthday_boy << "****************************" << endl;
	print("Happy birthday to you",2);
	print("How old are you now?");
	cout << "Age: ";
	cin >> age; // Read age
	
	if (age > 19)
	{
		age -= 20;
		cout << "Congractulations on " << age << " year(s) of NOT being a teen" << endl;
	}
	else
	{
		age = 20 - age;
		cout << "Hold on just " << age << " more year(s) of being a teen" << endl;
	}
	
	// Pause incase it is run directly
	// Start try
	try
	{
		system("pause");
	}
	catch(...)
	{
		// Empty catch		
	} //End try ... Catch
} // End main

void print(string what_to_print, int how_many_times_to_print_it)
{
	// Start loop to print string n times
	for (int i = 0; i < how_many_times_to_print_it; i++)
	{
		cout << what_to_print << endl;
	} // End loop
} // End print