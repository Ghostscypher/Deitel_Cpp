#include <iostream>
using namespace std;

int x = 10;//global variable x

int main()
{
	/*this is the unary scope operator ::
	it is used to access a global variable of the same name
	as a local variable in the same scope it used iff a global variable
	has the same name as the local variable*/	
	int x = 20;//local variable x
	
	//calling both variables in the same scope
	cout << "Local variable x is: " << x << endl;
	cout << "Global variable x is: " << ::x << endl;//accessing global variable
}//end main