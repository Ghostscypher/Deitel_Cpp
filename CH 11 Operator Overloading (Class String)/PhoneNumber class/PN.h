#ifndef PN_H
#define PN_H

#include <iostream>
#include <string>
using namespace std;

class PhoneNumber
{
// Overloaded iostream
friend ostream &operator<<(ostream &, const PhoneNumber &);
friend istream &operator>>(istream &, PhoneNumber &);
public:
	PhoneNumber(string = "0"); // Default constructor
	~PhoneNumber(); // Destructor
private:
	string areaCode;
	string exchange;
	string line;
};

#endif