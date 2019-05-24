#include <iostream>
#include <stdexcept>
#include "Time.h"
using namespace std;

int main()
{
	//set a non - constant time
	Time wakeUp(6, 45, 00);//initialize a non-constant class object.
	const Time noon(12, 0, 0);//Initialize a const class object constant time noon	
	
	wakeUp.setTime(18);
	wakeUp.getTime
	noon.getTime
}