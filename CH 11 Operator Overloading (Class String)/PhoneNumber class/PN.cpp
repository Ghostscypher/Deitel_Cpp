#include <iomanip>
#include "PN.h"
using namespace std;

PhoneNumber::PhoneNumber(string n)
:areaCode(n),
exchange(n),
line(n)
{
	// Empty body
} // End condtructor function

PhoneNumber::~PhoneNumber()
{
	// Empty body
} // End destructor function

// Friend functions
ostream &operator<<(ostream &output, const PhoneNumber &a)
{
	output << "+" << a.areaCode << " - " << setw(1) <<" (0)" << setw(3) << a.exchange << " - " << setw(6) << a.line << endl;
	
	return output; // Enables cout << x << y;  
} // End operator<< overloading

istream &operator>>(istream &input, PhoneNumber &a)
{
	input >> setw(3) >> a.areaCode >> setw(3) >> a.exchange >> setw(6) >> a.line;
	
	return input; // Enables cin >> x >> y;
} // End operator>> overloading