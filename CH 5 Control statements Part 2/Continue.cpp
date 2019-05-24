#include <iostream>

using namespace std;

int main()
{
	int i;
	for (i = 1; i <= 10; i++)
	{
		if (i == 5)
			continue;//skip the remining code	
		
	cout << i << " ";
	}
	cout << "\nThis loop was used to stop printing: 5" << endl;
}