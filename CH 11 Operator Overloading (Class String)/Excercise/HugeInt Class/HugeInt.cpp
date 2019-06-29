#include <cctype> // isdigit function prototype
#include "HugeInt.h"
using namespace std;

typedef HugeInt HI;

// Constructor/Default converter;
// Converts int to HugeInt data type
// Converts long data type to HugeInt data type
HugeInt::HugeInt(long value)
{
	position = digits - 1;
	size = 0;
		
	// Initialize array to 0
	for (int i = 0; i < digits; ++i)
		integer[i] = 0;
	
	// Place digits of argument into array
	for (int j = digits - 1; value != 0 && j >= 0; --j)
	{
		integer[j] = value % 10;
		value /= 10;
		position--;
		size++;
	} // End for
} // End constructor

// Conversion constructor
// Converts string to HugeInt
HugeInt::HugeInt(const string &number)
{
	position = digits - 1;
	size = 0;
	
	// Initialize array to 0
	for (int i = 0; i < digits; ++i)
		integer[i] = 0;
	
	// Place digits of argument into array
	int length = number.size();
	
	for (int j = digits - length, k = 0; j < digits; ++j, ++k)
		if (isdigit(number[k])) // Ensures that the number is a digit
		{
			integer[j] = number[k] - '0';
			position--;
			size++;
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
	if (position < secondValue.position)
		return true;
	else if (size == secondValue.size)
		for (int i = position; i < digits; i++)
			if (integer[i] < secondValue.integer[i])
				return true;
	
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
	if (position > secondValue.position)
		return true;
	else if (size == secondValue.size)
		for (int i = position; i < digits; i++)
			if (integer[i] > secondValue.integer[i])
				return true;
			
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
	
	int carry = 0;
	
	for (int i = digits - 1; i >= 0; i--)
	{
		temp.integer[i] = integer[i] + secondOperand.integer[i] + carry;
		
		// Determine whether to carry a 1
		if (temp.integer[i] > 9)
		{
			temp.integer[i] %= 10; // Reduce 0-9;
			carry = 1;
		}
		else
			carry = 0; // No carry; End if
	} // End for
	
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
	 */
	
	return temp; // Return copy if temporary object
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
	
	for (int i = digits - 1; i >= 0; i--)
		integer[i] = secondOperand.integer[i];
	
	getSize();
	getPosition();
	
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
// Used to get the size of the current object. Use this instead of .size
int HugeInt::getSize()
{
	size = 0;
	int j = 0;
	
	for (int i = 0; i < digits; i++)
	{
		if (integer[i] != 0)
			j++;
		
		if (j > 0)
			size++;
	} // End for
	
	return size;
} // End getSize

// USed to get the position
int HugeInt::getPosition()
{
	position = 0;
	
	int j = 0;
	
	for (int i = 0; i < digits; i++)
	{
		if (integer[i] != 0)
			j++;
			
		if (j == 0)
			position--;
	} // End for
	
	return position;
} // End getPosition

// Overloaded output operator
ostream& operator<<(ostream &output, const HugeInt &a)
{
	int i;
	
	for (i = 0; (a.integer[i] == 0) && (i < HugeInt::digits); ++i)
		; // Skip leading 0's
	
	if (i == HugeInt::digits)
		output << 0;
	else
		for (; i < HugeInt::digits; ++i)
			output << a.integer[i];
		
	return output; // Enables cout << x << y;
} // End operator<<

// Overloaded output operator
istream &operator>>(istream &input, HugeInt &a)
{
	string strIn;
	input >> strIn;
	
	// Convert from string to HUGEINT
	a = HugeInt(strIn);
	
	return input; // Enables cout << x << y;
} // End operator<<