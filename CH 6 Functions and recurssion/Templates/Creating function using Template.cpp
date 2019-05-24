#include <iostream>
using namespace std;
//below is an aexample of a function template
template <typename T>
//end of template declaration

/*A template has many overloaded functions inside it. thus eliminating the need to 
write many overloaded function. N.B. In order to invoke the template all of the values
supplied to the function must be of the same data type*/

//start of template functiomn
T maximum(T value1, T value2, T value3)
{
	T maximumValue = value1;//assume that value 1 is the maximum
	
	//determine whether value 2 is greater than the current max value
	if (value2 > maximumValue)
		maximumValue = value2;
	
	//determine whether value 3 is greater than the current max value
	if (value3 > maximumValue)
		maximumValue = value3;
	
	return maximumValue;
}//end of template function