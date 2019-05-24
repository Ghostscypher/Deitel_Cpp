#include <iostream>
#include <iomanip>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{
	//salt PRNG
	srand(time(0));
	
	vector <int> myTestVector(50);
	
	//add data to our vector
	for(size_t i = 0; i < myTestVector.size(); i++)
		myTestVector[i] = (1 + rand() % 5);
	
	//print the results
	for(size_t i = 0; i < myTestVector.size(); i++)
	{
		if((i % 5) == 0)
			cout << endl;
		
		cout << setw(4) << myTestVector[i];	
	}
	cout << endl;
}