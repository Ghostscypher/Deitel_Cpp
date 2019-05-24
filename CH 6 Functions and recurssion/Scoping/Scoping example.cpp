#include <iostream>
using namespace std;

//function prototypes
void useLocal();
void useStaticLocal();
void useGlobal();
//end of prototypes

int x = 1;//global variables  

//begin main
int main()
{
	cout << "Global x in main is: " << x << endl;
	
	int x = 5;//local variable also called x
	
	cout << "Local x in main's inner scope is: " << x << endl;
	
	{//start new scope
		int x = 7;//local variable to this scope but not to main
		cout << "local x to main's inner scope is: " << x << endl;
	}//end of new scope
	
	cout << "Local x in main's inner scope is: " << x << endl;

	useLocal();//has local x
	useGlobal();//has static local x
	useStaticLocal();//uses global x
	useLocal();//reinitialises it's local x
	useGlobal();//retains it's prior value
	useStaticLocal();//retains it's prior value
	
	cout << "Local x in main is: " << x << endl;
}//end main

//functions from prototype functs
void useLocal()
{
	int x = 25;//value set to 25 each time the function is called
	cout << "Local x on enetering useLocal() is: " << x << endl;
	x++;
	cout << "After adding 1 the value now is: " << x << endl;
}//end useLocal

void useStaticLocal()
{
	static int x = 50;//set value to x for the first time fumction is called
	
	cout << "Local static x is: " << x << endl;
	x++;
	cout << "After adding one to the static value x now is: " << x << endl;
}//end useStaticLocal

void useGlobal()
{
	cout << "Global x is: " << x << endl;
	x *= 10;
	cout << "After multiplying by 10 our global now is: " << x << endl;
}//end useGlobal