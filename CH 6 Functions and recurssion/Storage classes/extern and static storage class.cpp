#include <iostream>

using namespace std;

int test(int);//test function prototype

int main()
{
	/*static variables exists in the computer memory through the whole time of program execution
	 the keywords static and extern are used to declare this variable types.
	 However, even though the variables and the function names exist from the start of program execution, this
	does not mean that these identifiers can be used throughout the program.*/
	
	/*the static integer below is preserved throughout this program unless modified
	it will be destroyed once the program exists. the static variables are not reinitialised
	even if stated so*/
	static int i = 1;
	extern int ii = 1;
	
	/*If we call the function test() then the previous value of our static 
	integer m is preserved.*/
}

int test(int j)
{
	static int m = j;
	return m;
}