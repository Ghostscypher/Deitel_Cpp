#include <iostream>
#include <iomanip>
#include "Salesperson.h"//include salesperson definition
using namespace std;

//Access Functions to class SalesPerson
//constructor function
SalesPerson::SalesPerson()
{
	//initialize elements of the array to 0.0
	for(int i = 0; i < monthsPerYear; i++)
		sales[i] = 0.0;
}

//get 12 sales figure from the keyboard
void SalesPerson::getSalesFromUser()
{
	double salesFigure;
	
	for(int i = 1; i <= monthsPerYear; i++)
	{
		cout << "Enter Sales for month " << i << ": ";
		cin >> salesFigure;
		
		setSales(i, salesFigure);
	}//end for
}//end function getSalesFromUser

//set one of the 12 monthly sales
void SalesPerson::setSales(int month, double ammount)
{
	//test for invalid month value or sales figure
	if((month >= 1) && (ammount >= 0))
	{
		sales[month - 1] = ammount;//adjust for subscripts/ index 1 - 11	
	}
	else
	{
		cout << "Invalid month or sales figure!" << endl;
	}
}//end function setSales

//print total annual sales (with the help of utility function)
void SalesPerson::printAnnualSales()
{
	cout << setprecision(2) << fixed//set sticky keys for currency format
	<< "\nThe total ammount of sales are: $"
	<< totalAnnualSales() << endl;
}//end PrintAnnualSales

//Private utility function to class SalesPerson
double SalesPerson::totalAnnualSales()
{
	double total = 0.0;//initialize total
	
	for(int i = 0; i < monthsPerYear; i++)
		total += sales[i];
	
	return total;
}