#ifndef HUGEINT_H
#define HIGEINT_H

#include <iostream>
#include <string>
using namespace std;

class HugeInt
{
friend ostream &operator<<(ostream &, const HugeInt &); // cout <<
friend istream &operator>>(istream &, HugeInt &); // cin >>
public:
	static const int digits = 5; // Maximum number of digits in HugeInt
	
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
	short *integer;
	int size; // Will be used to store the size of the numbers
	int position;
	
	// Utility functions
	HugeInt negativeAddition(const HugeInt &) const; // For -ve addition
	HugeInt negativeSubtraction(const HugeInt &) const; // For -ve subtraction
	int getSize(); // Will be used to get the size of objects
	int getPosition(); // USed to get the position where the current object starts at
}; // End class HugeInt

#endif