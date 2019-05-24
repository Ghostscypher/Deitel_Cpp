#include <iostream>
#include "Increment.h"
using namespace std;

Increment::Increment(int c, int i)
	: count(c), //initializer for non-constant member
	increment(i)//required initializer for non const memeber
	{}//empty body

void Increment::print() const
{
	cout << "Count = " << count << "	Increment = " << increment << endl;
}//end function print