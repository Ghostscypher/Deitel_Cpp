#include <iomanip>
#include <cmath>
#include <iostream>

using namespace std;

int main()
{
	double ammount;
	double principle = 2000.00;
	double rate = 1.05;
	
	//display headers
	cout << "Year" << setw(21) << "ammount on deposit" << endl;
	
	//set floating point number format
	cout << fixed << setprecision(2);
	
	//calculate new ammount on deposit for each of ten years
	for (int year = 1; year <= 10 ; ++year)
	{
		ammount = principle * pow(1.0 + rate, year);
		
		//display the year and the ammount
		cout << setw(4) << year << setw(10) << "KSh. " << ammount << endl;
	}//end for
}//end main