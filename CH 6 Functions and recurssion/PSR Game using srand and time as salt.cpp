#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <ctime>

using namespace std;

/* NB. Random numbers are always in the form
number = shifting value/lowerbound + rand() % scaling factor/higherbound
for example
number = 1 + rand() % 10
will produce numbers between 1 and 10 1 being the lowerbound value */

int main()
{	
	srand(time(0));//seed PSRNG
	
	//loop 20 times
	for(int i =1 ; i <= 20; i++)
	{
		//pick a random number between 1 and 6 and output it
		cout << setw(15) << (1 + rand() % 6);
		
		if (i % 5 == 0)
			cout << endl;
	}//end loop
}//end main