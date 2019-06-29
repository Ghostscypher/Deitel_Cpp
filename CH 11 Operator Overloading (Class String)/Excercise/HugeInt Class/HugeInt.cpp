#include <cctype> // isdigit function prototype
#include "HugeInt.h"
using namespace std;

typedef HugeInt HI;

// Constructor/Default converter;
// Converts int to HugeInt data type
// Converts long data type to HugeInt data type
HugeInt::HugeInt(long value)
{
	bool isNegative = false;
	
	if(value < 0)
	{
		// Make the value positive
		value = value * -1;
		
		isNegative = true;
	}
	
	size = 0;
		
	// Initialize array to 0
	for (int i = 0; i < digits; ++i)
		integer[i] = 0;
	
	// Place digits of argument into array
	for (int j = digits - 1; value != 0 && j >= 0; --j)
	{
		integer[j] = value % 10;
		value /= 10;
		size++;
	} // End for
	
	position = digits - size;
	
	// Make the value -ve
	if (isNegative)
	{
		inverseSign_();
	}
} // End constructor

// Conversion constructor
// Converts string to HugeInt
HugeInt::HugeInt(const string &number)
{	
	bool isNegative = false;
	
	size = 0;
	
	// Initialize array to 0
	for (int i = 0; i < digits; ++i)
		integer[i] = 0;
	
	// Place digits of argument into array
	int length = number.size();
	
	if (number[0] == '-')
	{
		isNegative = true;
	}
	
	for (int j = digits - length, k = 0; j < digits; ++j, ++k)
	{
		if (isdigit(number[k])) // Ensures that the number is a digit
		{	
			integer[j] = number[k] - '0';
			size++;
		}
	}
		
	position = digits - size;
	
	// Make the value -ve
	if (isNegative)
	{
		inverseSign_();
	}
} // End conversion constructor

/* Overloaded operator functions */
// Logic operators
// Logical equivalence. ?HugeInt == Hugeint
bool HugeInt::operator==(const HugeInt &secondValue) const
{
	if (this == &secondValue) // Check if the objects are the same
		return true;
		
	for (int i = digits - 1; i >= 0; i--)
		if (integer[i] != secondValue.integer[i]) // Check if all the digits match
			return false;
		
		return true; // The control will reach here only if the digits matched
} // End operator ==

// ? HugeInt == string
bool HugeInt::operator==(const string &secondValue) const
{
	return (*this == HugeInt(secondValue));
} // End operator==

// ? HugeInt == long
bool HugeInt::operator==(const long secondValue) const
{
	return (*this == HugeInt(secondValue));
} // End operator==

// ? HugeInt == int
bool HugeInt::operator==(const int secondValue) const
{
	return (*this == HugeInt(secondValue));
} // End operator==

// Negation/compliment
// ? HugeInt != HugeInt
bool HugeInt::operator!=(const HugeInt &secondValue) const
{
	return !(*this == secondValue);
} // End operator!=

bool HugeInt::operator!=(const string &secondValue) const
{
	return !(*this == HugeInt(secondValue));
} // End operator!=

// ? HugeInt != long
bool HugeInt::operator!=(const long secondValue) const
{
	return !(*this == HugeInt(secondValue));
} // End operator!=

// ? HugeInt != int
bool HugeInt::operator!=(const int secondValue) const
{
	return !(*this == HugeInt(secondValue));
} // End operator!=

// Less than
// HugeInt < HugeInt
bool HugeInt::operator<(const HugeInt &secondValue) const
{
	if (size < secondValue.size)
		return true;
	else if (size == secondValue.size)
		for (int i = position; i < digits; i++)
			if (integer[i] < secondValue.integer[i])
				return true;
			else if(integer[i] > secondValue.integer[i])
				return false;
	
	return false;
} // End operator <

// HugeInt < string
bool HugeInt::operator<(const string &secondValue) const
{
	return (*this < HugeInt(secondValue));
} // End operator <

// HugeInt < long
bool HugeInt::operator<(const long secondValue) const
{
	return (*this < HugeInt(secondValue));
} // End operator <

// HugeInt < int
bool HugeInt::operator<(const int secondValue) const
{
	return (*this < HugeInt(secondValue));
} // End operator <

// Less than or equal to
// HugeInt <= string
bool HugeInt::operator<=(const HugeInt &secondValue) const
{
	return ((*this < secondValue) || (*this == secondValue));
} // End operator <=

bool HugeInt::operator<=(const string &secondValue) const
{
	return (*this <= HugeInt(secondValue));
} // End operator <=

// HugeInt < long
bool HugeInt::operator<=(const long secondValue) const
{
	return (*this <= HugeInt(secondValue));
} // End operator <=

// HugeInt < int
bool HugeInt::operator<=(const int secondValue) const
{
	return (*this <= HugeInt(secondValue));
} // End operator <=

// Greater than
// HugeInt > HugeInt
bool HugeInt::operator>(const HugeInt &secondValue) const
{
	if (size > secondValue.size)
		return true;
	else if (size == secondValue.size)
		for (int i = position; i < digits; i++)
			if (integer[i] > secondValue.integer[i])
				return true;
			else if(integer[i] < secondValue.integer[i])
				return false;
			
	return false;
} // End operator >

// HugeInt > string
bool HugeInt::operator>(const string &secondValue) const
{
	return (*this > HugeInt(secondValue));
} // End operator >

// HugeInt > long
bool HugeInt::operator>(const long secondValue) const
{
	return (*this > HugeInt(secondValue));
} // End operator >

// HugeInt > int
bool HugeInt::operator>(const int secondValue) const
{
	return (*this > HugeInt(secondValue));
} // End operator >

// Less than or equal to
// HugeInt >= string
bool HugeInt::operator>=(const HugeInt &secondValue) const
{
	return ((*this > secondValue) || (*this == secondValue));
} // End operator >=

bool HugeInt::operator>=(const string &secondValue) const
{
	return (*this >= HugeInt(secondValue));
} // End operator >=

// HugeInt >= long
bool HugeInt::operator>=(const long secondValue) const
{
	return (*this >= HugeInt(secondValue));
} // End operator >=

// HugeInt >= int
bool HugeInt::operator>=(const int secondValue) const
{
	return (*this >= HugeInt(secondValue));
} // End operator >=

/* Arithmetic operator */
// Addition operator; HugeInt + HugeInt
HugeInt HugeInt::operator+(const HugeInt &secondOperand) const
{	
	HugeInt temp; // Temporary result
	
	/*
	 * List of all possible situations represnted in a table
	 * 
	 * Situation RigthOp LeftOp Representation
	 * #1        +ve     +ve    10 + 4
	 * #2        +ve     -ve    10 + (-4) // Reduce to (10 - 4)
	 * #3		 -ve     +ve    -10 + 4 // Change to (4 - 10)
	 * #4        -ve     -ve    -10 + -4 // Change to (-10 - 4)
	 */
	
	// #4 : -10 - 4
	if(integer[position] < 0 && secondOperand.integer[secondOperand.position] < 0)
	{
		// Change the value to positive and add the two values then
		// convert the final value back to negative
		HugeInt temp2 = *this;
		temp = secondOperand;
		
		// Change to +ve
		inverseSign(temp2);
		inverseSign(temp);
		
		// Add the values and convert back to -ve 
		temp = temp + temp2;
		inverseSign(temp);
		
		// Return the final -ve value
		return temp;
	}
	
	// #3 : -10 + 4
	if (integer[position] < 0)
	{
		return secondOperand - *this;
	}
	
	// #2 : 10 + -4
	if (secondOperand.integer[secondOperand.position] < 0)
	{
		temp = secondOperand;
		
		inverseSign(temp);
		
		return *this - temp;
	}
	
	// #1 : 10 + 4 
	int carry = 0;
	
	// Get the maximum ammount of iteration
	int maxSize = size < secondOperand.size? secondOperand.size + 1: size + 1;
	
	for (int i = digits - 1; i >= digits - maxSize; i--)
	{
	   	temp.integer[i] = integer[i] + secondOperand.integer[i] + carry;
		temp.size++;
					
		// Determine whether to carry a 1
		if (temp.integer[i] > 9)
		{
			temp.integer[i] %= 10; // Reduce 0-9;
			carry = 1;
		}
		else
			carry = 0; // No carry; End if
	} // End for
	
	// Get the position for temp
	temp.position = temp.digits - temp.size;
	
	// Check if the last value is a leading 0
	if(temp.integer[temp.position] == 0)
	{
		temp.size--;
		temp.position++;
	}
	
	return temp; // Return copy if temporary object
} // End operator+

// Addition operator; HugeInt + string
HugeInt HugeInt::operator+(const string &secondOperand) const
{
	// Convert second operand into HugeInt and invoke operator+ for two HugeInt
	// types.
	return *this + HugeInt(secondOperand);
} // End operator+

// Addition operator; HugeInt + long
HugeInt HugeInt::operator+(const long secondOperand) const
{
	// Convert second operand into HugeInt and invoke operator+ for two HugeInt
	// types.
	return *this + HugeInt(secondOperand);
} // End operator+

// Addition operator; HugeInt + int
HugeInt HugeInt::operator+(const int secondOperand) const
{
	// Convert second operand into HugeInt and invoke operator+ for two HugeInt
	// types.
	return *this + HugeInt(secondOperand);
} // End operator+

// Complex addition operator HugeInt += Hugeint
// Complex addition
void HugeInt::operator+=(const HugeInt &secondValue)
{
	*this = (*this + secondValue);
} // End operator +=

// Complex addition operator HugeInt += string
void HugeInt::operator+=(const string &secondValue)
{
	*this = (*this + (HugeInt(secondValue)));
} // End operator +=

// Complex addition operator HugeInt += long
void HugeInt::operator+=(const long secondValue)
{
	*this = (*this + (HugeInt(secondValue)));
} // End operator +=

// Complex addition operator HugeInt += integer
void HugeInt::operator+=(const int secondValue)
{
	*this = (*this + (HugeInt(secondValue)));
} // End operator +=

// Subtraction operator; HugeInt - HugeInt
HugeInt HugeInt::operator-(const HugeInt &secondOperand) const
{	
	HugeInt temp; // Temporary result
	
	// Solve the problem by using two's complement
	/*
	 * List of all possible situations represnted in a table
	 * 
	 * Situation RigthOp LeftOp Representation
	 * #1        +ve     +ve    10 - 4
	 * #2        +ve     -ve    10 - (-4) // Change to 10 + 4
	 * #3		 -ve     +ve    -10 - 4
	 * #4        -ve     -ve    -10 - -4 // Change to 4 - 10
	 * #5 		 +ve	 +ve 	4 - 10	// But second operand is less than the first
	 */
	
	// #4 : -10 - (-4)
	if(integer[position] < 0 && secondOperand.integer[secondOperand.position] < 0)
	{
		// Remove the negative sign from the second operand
		HugeInt temp2 = *this;
		temp = secondOperand;
		
		// Change the values to +ve
	 	inverseSign(temp);
	 	inverseSign(temp2);
		
		temp = temp2 + temp;
		
		inverseSign(temp);
		
		return temp;
	}
	
	// #3 : -10 - 4
	if (integer[position] < 0)
	{
		// Change the first ops +ve then add and change the final result to -ve
		temp = *this;
		
		inverseSign(temp);
		
		temp = temp + secondOperand;
		
		inverseSign(temp);
		
		return temp;
	}
	
	// #2 : 10 - (-4)
	if (secondOperand.integer[secondOperand.position] < 0)
	{
		temp = secondOperand;
		
		inverseSign(temp);
		
		return *this + temp;
	}
	
	// #5 : 4 - 10
	if(secondOperand > *this)
	{	
		HugeInt temp2 = *this;
		temp = secondOperand;
		
		temp = temp - temp2;
		
		// Make the answer -ve
		inverseSign(temp);
		
		return temp;
	}
	
	// #1 : 10 - 4
	// Equate temp to the value of the current class
	temp = *this;
	
	// Holds a flipped version of the second operand
	HugeInt flipped = flip(temp, secondOperand);
	
	doTwosComplement(temp, flipped);
	
	return temp; // Return copy of temporary object
} // End operator-

// Subtraction operator; Hugeint - String
HugeInt HugeInt::operator-(const string &secondOperand) const
{
	// Convert second operand into HugeInt and invoke operator+ for two HugeInt
	// types.
	return *this - HugeInt(secondOperand);
} // End operator-

// Subtraction operator-; HugeInt - Int
HugeInt HugeInt::operator-(const int secondOperand) const
{
	// Convert second operand into HugeInt and invoke operator- for two HugeInt
	// types.
	return *this - HugeInt(secondOperand);	
} // End operator-

// Subtraction operator-; HugeInt - Int
HugeInt HugeInt::operator-(const long secondOperand) const
{
	// Convert second operand into HugeInt and invoke operator- for two HugeInt
	// types.
	return *this - HugeInt(secondOperand);	
} // End operator-

// Complex subtraction operator HugeInt -= Hugeint
// Complex subtraction
void HugeInt::operator-=(const HugeInt &secondValue)
{
	*this = (*this - secondValue);
} // End operator -=

// Complex subtraction operator HugeInt -= string
void HugeInt::operator-=(const string &secondValue)
{
	*this = (*this - (HugeInt(secondValue)));
} // End operator -=

// Complex subtraction operator HugeInt -= long
void HugeInt::operator-=(const long secondValue)
{
	*this = (*this - (HugeInt(secondValue)));
} // End operator -=

// Complex subtraction operator HugeInt -= integer
void HugeInt::operator-=(const int secondValue)
{
	*this = (*this - (HugeInt(secondValue)));
} // End operator -=

// Assignment operator
// HugeInt = HugeInt
HugeInt HugeInt::operator=(const HugeInt &secondOperand)
{
	// Prevent self assignment
	if (this == &secondOperand)
		return *this;
	
	for (int i = secondOperand.position; i < secondOperand.digits; i++)
		integer[i] = secondOperand.integer[i];
	
	// To allow for huge Int classes with different sizes
	size = secondOperand.size;
	position = secondOperand.position;
	
	return *this;
} // End operator= for HugeInt

// HugeInt = string
HugeInt HugeInt::operator=(const string &secondOperand)
{
	return *this = HugeInt(secondOperand);
} // End operator= for string

// HugeInt = long
HugeInt HugeInt::operator=(const long secondOperand)
{
	return *this = HugeInt(secondOperand);	
} // End operator= for long

// HugeInt = int
HugeInt HugeInt::operator=(const int secondOperand)
{
	return *this = HugeInt(secondOperand);	
} // End operator= for int

// Utility functions


// Overloaded output operator
ostream& operator<<(ostream &output, const HugeInt &a)
{
	if(a.size == 0)
		output << 0;
	else
	{
		for (int i = a.digits - a.size; i < a.digits; i++)
			output << a.integer[i];
	}
		
	return output; // Enables cout << x << y;
} // End operator<<

// Overloaded output operator
istream &operator>>(istream &input, HugeInt &a)
{
	string strIn;
	input >> strIn;
	
	// Convert from string to HUGEINT
	a = HugeInt(strIn);
	
	return input; // Enables cin >> x >> y;
} // End operator<<

// Used to make a specific value -ve
void makeNegative(HugeInt &a)
{
	if (a.integer[a.position] < 0)
		return;	
	
	a.integer[a.position] = a.integer[a.position] * -1;
}

// Used to make a specific value +ve
void makePositive(HugeInt &a)
{
	if (a.integer[a.position] >= 0)
		return;	
	
	a.integer[a.position] = a.integer[a.position] * -1;
}
	
// Inverse the sign of a given class
void inverseSign(HugeInt &a)
{
	a.integer[a.position] = a.integer[a.position] * -1;
}

// Drops any leading zeroes from a given HugeInt class
void dropLeadingZeroes(HugeInt &a)
{
	for (int i = a.position; i < a.digits; i++)
	{
		if (a.integer[i] == 0)
		{
			a.size--;
			a.position++;
		}
		else
			return;
	}
}