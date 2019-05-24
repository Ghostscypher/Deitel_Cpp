#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

int main()
{
	int f1 = 0;//frequency of the number 1
	int f2 = 0;//frequency of the number 2
	int f3 = 0;//frequency of the number 3
	int f4 = 0;//frequency of the number 4
	int f5 = 0;//frequency of the number 5
	int f6 = 0;//frequency of the number 6
	int face;//stores the face of the most recently rolled dice
	
	//start of loop
	for (int i = 1; i <= 6000000; i++)
	{
		face = 1 + rand() % 6;//set random
		
		//update our frequency counter
		switch(face)
		{
		case 1:
			f1++;
			break;
		
		case 2:
			f2++;
			break;
		
		case 3:
			f3++;
			break;
		
		case 4:
			f4++;
			break;
		
		case 5:
			f5++;
			break;
		
		case 6:
			f6++;
			break;
		
		default:
			break;
		}//end switch
	}//end for
	
	//print our reults
	cout << "Face" << setw(10) << "Frequency" << endl;
	cout << 1 << setw(10) << f1 << endl;
	cout << 2 << setw(10) << f2 << endl;
	cout << 3 << setw(10) << f3 << endl;
	cout << 4 << setw(10) << f4 << endl;
	cout << 5 << setw(10) << f5 << endl;
	cout << 6 << setw(10) << f6 << endl;
	cout << "Total: " << f1 + f2 + f3 + f4 + f5 + f6 << endl;
}//end main