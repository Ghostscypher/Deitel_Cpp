#include <iostream>
#include <iomanip>

using namespace std;

//function prototypes
	double square(double);
//end of prototype

int main()
{
	double x = 10.225;
	//set format (Sticky)
	cout << fixed << setprecision(4);
	
	//print result using square function	
	cout << "The square of " << x << " is: " << square(x) << endl;
}//end main

double square(double x)
{
	return x * x;
}//end square function