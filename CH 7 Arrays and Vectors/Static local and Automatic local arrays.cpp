#include <iostream>
#include <iomanip>
using namespace std;

//start of prototypes
	void staticArray();
	void autoArray();
//end of prototypes

/*static - preserved for the whole program
		 - initialized only once
		 - uses static and extern keywords
automatic 	- destroyed as soon as the scope is finished*
		    - initialized each time the scope is started
			- uses auto and register keywords
			- One can also ignore both keywords completely because 
			by default all initialized data types are auto*/

int main()
{
	//first call
	cout <<"First call*******************************************" << endl;
	staticArray();
	cout << endl;
	autoArray();
	
	//second call
	cout << "\nSecond call******************************************" << endl;
	staticArray();
	cout << endl;
	autoArray();	
}

void staticArray()
{
	static int sArray[2] = {};//initialize to zero
	sArray[0] += 1;
	sArray[1] +=2;
	
	cout << "Static Element [0] = " << sArray[0] << endl;
	cout << "Static Element [1] = " << sArray[1] << endl;
}

void autoArray()
{
	int aArray[2] = {};//initialize to zero
	aArray[0] += 1;
	aArray[1] +=2;
	
	cout << "Auto Element [0] = " << aArray[0] << endl;
	cout << "Auto Element [1] = " << aArray[1] << endl;
}