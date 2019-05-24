#include <iostream>

using namespace std;

int evaluateMaximum(int x, int y, int z)//start of function
{
	int maximumvalue = x;//set the max value to x
	
	if (y > maximumvalue)//if y is greater set max value to y
		maximumvalue = y;
	
	if (z > maximumvalue)//if z is greater tan the current max value set max value to z
		maximumvalue = z;
	
	return maximumvalue;//return max value back to caller
}//end function

int main()//start of main
{
	int x, y, z;//create variables
	
	cout << "Please enter three integers in the format x y z: ";
	cin >> x >> y >> z;
	
	//evaluate the value using evaluatenaximum function
	cout << "The maximum number is: " << evaluateMaximum(x, y, z) << endl;
}//end main