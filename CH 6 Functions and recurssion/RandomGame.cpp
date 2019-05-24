#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

int main()
{
	//loop 20 times
	for(int i =1 ; i <= 20; i++)
	{
		//pick a random number between 1 and 6 and output it
		cout << setw(15) << (1 + rand() % 6);
		
		if (i % 5 == 0)
			cout << endl;
	}//end loop
}//end main