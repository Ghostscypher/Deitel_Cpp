#ifndef HUGEINT_H
#define HIGEINT_H

#include <iostream>
#include <string>
using namespace std;

class HugeInt
{
friend ostream &operator<<(ostream &, const HugeInt &); // cout <<
friend istream &operator>>(istream &, HugeInt &); // cin >>
friend void makePositive(HugeInt &);
friend void makeNegative(HugeInt &);
friend void inverseSign(HugeInt &);
friend void dropLeadingZeroes(HugeInt &);
public:
	static const int digits = 30; // Maximum number of digits in HugeInt
	
	// Constructors
	HugeInt(const string &); // Conversion/ constructor
	HugeInt(long = 0); // Conversion/default constructor

	// Logic operators
	// Logic equivalence
	bool operator==(const HugeInt &) const;
	bool operator==(const string &) const;
	bool operator==(const long) const;
	bool operator==(const int) const;
	
	// Negation operator
	bool operator!=(const HugeInt &) const;
	bool operator!=(const string &) const;
	bool operator!=(const long) const;
	bool operator!=(const int) const;
	
	// Less than
	bool operator<(const HugeInt &) const;
	bool operator<(const string &) const;
	bool operator<(const long) const;
	bool operator<(const int) const;
	
	// Greater than
	bool operator>(const HugeInt &) const;
	bool operator>(const string &) const;
	bool operator>(const long) const;
	bool operator>(const int) const;
	
	// Less than or equal to
	bool operator<=(const HugeInt &) const;
	bool operator<=(const string &) const;
	bool operator<=(const long) const;
	bool operator<=(const int) const;
	
	// Greater than or equal to
	bool operator>=(const HugeInt &) const;
	bool operator>=(const string &) const;
	bool operator>=(const long) const;
	bool operator>=(const int) const;
	
	// Arithmetic operators
	// Addition operator; HugeInt + HugeInt
	HugeInt operator+(const HugeInt &) const;
	HugeInt operator+(const string &) const;
	HugeInt operator+(const int) const;
	HugeInt operator+(const long) const;
	
	// Subtraction
	HugeInt operator-(const HugeInt &) const;
	HugeInt operator-(const string &) const;
	HugeInt operator-(const int) const;
	HugeInt operator-(const long) const;	
	
	// Multiplication
	HugeInt operator*(const HugeInt &) const;
	HugeInt operator*(const string &) const;
	HugeInt operator*(const int) const;
	HugeInt operator*(const long) const;
	
	// Division
	HugeInt operator/(const HugeInt &) const;
	HugeInt operator/(const string &) const;
	HugeInt operator/(const int) const;
	HugeInt operator/(const long) const;
	
	// Modular
	HugeInt operator%(const HugeInt &) const;
	HugeInt operator%(const string &) const;
	HugeInt operator%(const int) const;
	HugeInt operator%(const long) const;
	
	// Complex operators
	// Complex addition
	void operator+=(const HugeInt &);
	void operator+=(const string &);
	void operator+=(const long);
	void operator+=(const int);
	
	// Complex subtraction
	void operator-=(const HugeInt &);
	void operator-=(const string &);
	void operator-=(const long);
	void operator-=(const int);
	
	// Complex multiplication
	void operator*=(const HugeInt &);
	void operator*=(const string &);
	void operator*=(const long);
	void operator*=(const int);
	
	// Complex division
	void operator/=(const HugeInt &);
	void operator/=(const string &);
	void operator/=(const long);
	void operator/=(const int);
	
	// Complex modular
	void operator%=(const HugeInt &);
	void operator%=(const string &);
	void operator%=(const long);
	void operator%=(const int);
	
	// Postfix addition
	void operator++();
	
	// Prefix addition
	void operator++(int);
	
	// Postix subtraction
	void operator--();
	
	// Postfix subtraction
	void operator--(int);
	
	// Assignment operator
	HugeInt operator=(const HugeInt &);
	HugeInt operator=(const string &);
	HugeInt operator=(const long);
	HugeInt operator=(const int);
private:
	short integer[digits];
	int size; // Will be used to store the size of the numbers
	int position;
	
	/** Utility functions
	 * Used as helper functions for this class
	 */
	
	// Used to make this class +ve
	void makePositive_()
	{
		makePositive(*this);
	}
	
	// Used to make this class -ve
	void makeNegative_()
	{
		makeNegative(*this);
	}
		
	// Inverse sign is used to inverse the sign without caring
	// if the value is negative or positive
	// Inverse the sign of this class
	void inverseSign_()
	{
		inverseSign(*this);
	}
	
	// Used to flip this class
	HugeInt flip()
	{
		return flip(*this, *this);
	}
	
	// Used to flip the numbers ready for two's complement
	HugeInt flip(const HugeInt &firstOperand, const HugeInt &secondOperand) const
	{
		HugeInt temp(firstOperand); // Hold the value to be returned
		
		// Used to hold the operand that will be used during flipping
		// Priority large numbers
		HugeInt a;
		
		if (firstOperand.size == secondOperand.size)
			a = secondOperand;
		else if(firstOperand.size < secondOperand.size)
			a = secondOperand;
		else
			a = firstOperand;
		
		// Loop using the chosen value
		for (int i = a.position; i < a.digits; i++)
		{
			temp.integer[i] = 9 - secondOperand.integer[i];
		} // End for
		
		return temp;
	} // End flip
	
	// Perform two's complement on the given value
	void doTwosComplement(HugeInt &firstOperand, const HugeInt &secondOperand) const
	{
		// Perform two's complement here
		firstOperand = firstOperand + secondOperand + 1;
		
		// Drop the leading 1, if there is an overflow truncate
		if (firstOperand.position < 0)
		{
			firstOperand.size = firstOperand.digits;
			firstOperand.position = 0;
			
			if (firstOperand.integer[0] == 1)
			{
				firstOperand.integer[0] = 0;	
			}
		}
		else
			firstOperand.integer[firstOperand.position] = 0;

		// Find out if the remaining values are leading 0's, if true strip it
		dropLeadingZeroes(firstOperand);
		
	} // End doTwosComplement
}; // End class HugeInt

#endif